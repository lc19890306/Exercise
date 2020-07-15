#pragma once

template<typename Key, typename Value, typename Hash=std::hash<Key>>
class hash_map {
public:
    using key_type = Key;
    using mapped_type = Value;
    using hash_type = Hash;

    explicit hash_map(const size_t num_buckets = 19, const hash_type &hasher = hash_type())
            : buckets(num_buckets), hasher(hasher) {
    }
    hash_map(const hash_map &other) = delete;
    hash_map &operator=(const hash_map &rhs) = delete;

    [[nodiscard]] mapped_type value_for(const key_type &key, const mapped_type &default_value = mapped_type()) {
        return get_bucket(key).value_for(key, default_value);
    }

    void add_or_update_mapping(const key_type &key, const mapped_type &value) {
        get_bucket(key).add_or_update_mapping(key, value);
    }

    void remove_mapping(const key_type &key) {
        get_bucket(key).remove_mapping(key);
    }

private:
    class bucket_type {
    public:
        mapped_type value_for(const key_type &key, const mapped_type &default_value) {
            std::shared_lock<std::shared_mutex> lk(mutex);
            const auto it = find_entry_for(key);
            return (it == std::end(data)) ? default_value : it->second;
        }

        void add_or_update_mapping(const key_type &key, const mapped_type &value) {
            std::lock_guard<std::shared_mutex> lk(mutex);
            const auto it = find_entry_for(key);
            if (it == std::end(data)) {
                data.emplace_back(key, value);
            } else {
                it->second = value;
            }
        }

        void remove_mapping(const key_type &key) {
            std::lock_guard<std::shared_mutex> lk(mutex);
            const auto it = find_entry_for(key);
            if (it != std::end(data)) {
                data.erase(it);
            }
        }
    private:
        using bucket_value = std::pair<key_type, mapped_type>;
        using bucket_data = std::list<bucket_value>;
        using bucket_iterator = typename bucket_data::iterator;

        bucket_iterator find_entry_for(const key_type &key) {
            return std::find_if(std::begin(data), std::end(data), [&key](const auto &item){ return item.first == key; });
        }

        bucket_data data;
        std::shared_mutex mutex; // rw_lock
    };

//    std::vector<std::unique_ptr<bucket_type>> buckets;
    std::vector<bucket_type> buckets;
    hash_type hasher;

    [[nodiscard]] bucket_type &get_bucket(const key_type &key) {
        return buckets[hasher(key) % buckets.size()];
    }
};
