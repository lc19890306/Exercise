#pragma once

template<typename Key, typename Value, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
class hash_map {
public:
    using key_type = Key;
    using mapped_type = Value;
    using hash_type = Hash;

    explicit hash_map(const size_t n = 31, const hash_type &hasher = hash_type()) : buckets(n), hasher(hasher) {}
    hash_map(const hash_map &other) : buckets(other.buckets), hasher(other.hasher) {}
    hash_map(hash_map &&other) noexcept : buckets(std::move(other.buckets)), hasher(std::move(other.hasher)) {}
    hash_map &operator=(hash_map rhs) {
        swap(rhs);
        return *this;
    }
    ~hash_map() = default;

public:
    void swap(hash_map &other) {
        std::swap(buckets, other.buckets);
        std::swap(hasher, other.hasher);
    }

    mapped_type &operator[](const key_type &key) {
        auto &&bucket = get_bucket(key);
        const auto &it = bucket.find(key);
        if (it->first == key) return it->second;
        return bucket.emplace(it, key, mapped_type())->second;
    }

    mapped_type &at(const key_type &key) {
        try {
            auto &&bucket = get_bucket(key);
            return bucket.find(key)->second;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    bool insert(const std::pair<key_type, mapped_type> &p) {
        auto &&bucket = get_bucket(p.first);
        const auto &it = bucket.find(p.first);
        if (it->first == p.first) return false;
        bucket.insert(it, p);
        return true;
    }

    bool emplace(const key_type &key, const mapped_type &value) {
        auto &&bucket = get_bucket(key);
        const auto &it = bucket.find(key);
        if (it->first == key) return false;
        bucket.emplace(it, key, value);
        return true;
    }

private:
    struct bucket_type {
        using bucket_value = std::pair<key_type, mapped_type>;
        using bucket_data = std::list<bucket_value>;
        using bucket_iterator = typename bucket_data::iterator;
        bucket_data data;
        auto find(const Key &key) {
            return find_if(begin(data), end(data), [&key](const auto &p){ return p.first == key; });
        }
        void insert(bucket_iterator it, const bucket_value &p) {
            data.insert(it, p);
        }
        auto emplace(bucket_iterator it, const key_type &key, const mapped_type &value) {
            return data.emplace(it, key, value);
        }
    };

    bucket_type &get_bucket(const key_type &key) {
        return buckets[hasher(key) % buckets.size()];
    }

    std::vector<bucket_type> buckets;
    hash_type hasher;
};
