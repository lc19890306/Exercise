#include <map>
//#include <set>
#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
#include <queue>
//#include <stack>
#include <string>
//#include <bitset>
//#include <cstdio>
//#include <limits>
//#include <utility>
#include <vector>
//#include <climits>
//#include <cstring>
//#include <cstdlib>
//#include <fstream>
//#include <numeric>
#include <sstream>
#include <iostream>
//#include <algorithm>
#include <unordered_map>
#include <memory>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
// #include <atomic>

namespace MatchingEngine {

    class Order {
    public:
        Order() : _price(0), _quantity(0) {}
        Order(std::string order_type,
              const size_t price,
              const size_t quantity,
              std::string order_id)
                : _order_type(std::move(order_type))
                , _price(price)
                , _quantity(quantity)
                , _order_id(std::move(order_id)) {}

        Order(const Order &other) : Order(other._order_type, other._price, other._quantity, other._order_id) {}

        Order(Order &&other) : Order(std::move(other._order_type), other._price, other._quantity,
                                     std::move(other._order_id)) {}

        Order &operator=(Order rhs) {
            std::swap(_order_type, rhs._order_type);
            std::swap(_price, rhs._price);
            std::swap(_quantity, rhs._quantity);
            std::swap(_order_id, rhs._order_id);
            return *this;
        }

        std::string getOrderType() const { return _order_type; }

        size_t getPrice() const { return _price; }

        void setPrice(const size_t price) { _price = price; }

        size_t getQuantity() const { return _quantity; }

        void setQuantity(const size_t quantity) { _quantity = quantity; }

        std::string getOrderId() const { return _order_id; }

    private:
        std::string _order_type;
        size_t _price;
        size_t _quantity;
        std::string _order_id;
    };

    struct Data {
        using OrderBook = std::unordered_map<std::string, Order>;
        OrderBook _order_book;
        struct OrderBucket {
            size_t _total_quantity;
            using OrderList = std::list<std::pair<size_t, std::string>>;
            OrderList _order_list;
            using OrderListIter = OrderList::iterator;
            using OrderTable = std::unordered_map<std::string, OrderListIter>;
            OrderTable _order_table;
            void addOrder(const Order &order) {
                _total_quantity += order.getQuantity();
                _order_table[order.getOrderId()] = _order_list.emplace(_order_list.end(), order.getQuantity(), order.getOrderId());
            }
            void deleteOrder(const Order &order) {
                _total_quantity -= order.getQuantity();
                _order_list.erase(_order_table[order.getOrderId()]);
                _order_table.erase(order.getOrderId());
            }
            bool empty() const {
                return _order_list.empty();
            }
        };
        std::map<size_t, OrderBucket> _sell_book;
        std::map<size_t, OrderBucket, std::greater<size_t>> _buy_book;
        void addOrder(const Order &order) {
            if (_order_book.find(order.getOrderId()) != _order_book.end()) return;
            _order_book[order.getOrderId()] = order;
            if (order.getOrderType() == "BUY") {
                _buy_book[order.getPrice()].addOrder(order);
            } else if (order.getOrderType() == "SELL") {
                _sell_book[order.getPrice()].addOrder(order);
            }
        }
        void deleteOrder(const std::string &order_id) {
            const auto it = _order_book.find(order_id);
            if (it == _order_book.end()) return;
            const auto &order = it->second;
            if (order.getOrderType() == "BUY") {
                _buy_book[order.getPrice()].deleteOrder(order);
                if (_buy_book[order.getPrice()].empty()) {
                    _buy_book.erase(order.getPrice());
                }
            } else if (order.getOrderType() == "SELL") {
                _sell_book[order.getPrice()].deleteOrder(order);
                if (_sell_book[order.getPrice()].empty()) {
                    _sell_book.erase(order.getPrice());
                }
            }
            _order_book.erase(it);
        }
    };

    class Operation {
    public:
        explicit Operation(std::string type) : _type(std::move(type)) {}

        virtual ~Operation() = default;

        virtual std::string getType() const {
            return _type;
        }

        virtual void executeOn(Data &data) = 0;

        static void printTrade(const std::string &order_id_1, const size_t price_1, const size_t quantity_1,
                               const std::string &order_id_2, const size_t price_2, const size_t quantity_2) {
            std::cout << "TRADE " << order_id_1 << " " << price_1 << " " << quantity_1 << " " << order_id_2 << " " << price_2 << " " << quantity_2 << std::endl;
        }

    private:
        std::string _type;
    };

    class BuyOperation : public Operation {
    public:
        BuyOperation(std::string order_type,
                     const size_t price,
                     const size_t quantity,
                     std::string order_id)
                : Operation("BUY")
                , _order_type(std::move(order_type))
                , _price(price)
                , _quantity(quantity)
                , _order_id(std::move(order_id)) {}

        void executeOn(Data &data) override;

    private:
        std::string _order_type;
        size_t _price;
        size_t _quantity;
        std::string _order_id;
    };

    void BuyOperation::executeOn(Data &data) {
        auto &order_book = data._order_book;
        auto &sell_book = data._sell_book;
        if (order_book.find(_order_id) != order_book.end()) return;
        const auto &end_it = sell_book.upper_bound(_price);
        for (auto it = sell_book.begin(); it != end_it && _quantity;) {
            auto &order_bucket = it->second;
            auto &total_quantity = order_bucket._total_quantity;
            auto &order_list = order_bucket._order_list;
            auto &order_table = order_bucket._order_table;
            for (auto it = order_list.begin(); it != order_list.end() && _quantity;) {
                auto &available_quantity = it->first;
                const auto &sell_order_id = it->second;
                const size_t trade_quantity = std::min(_quantity, available_quantity);
                const auto &sell_order = order_book[sell_order_id];
                printTrade(sell_order.getOrderId(), sell_order.getPrice(), trade_quantity,
                           _order_id, _price, trade_quantity);
                _quantity -= trade_quantity;
                available_quantity -= trade_quantity;
                total_quantity -= trade_quantity;
                if (available_quantity == 0) {
                    order_book.erase(sell_order_id);
                    order_table.erase(sell_order_id);
                    it = order_list.erase(it);
                }
            }
            if (order_list.empty()) {
                it = sell_book.erase(it);
            }
        }
        if (_quantity == 0) return;
        if (_order_type == "GFD") {
            data.addOrder(Order("BUY", _price, _quantity, _order_id));
        }
    }

    class SellOperation : public Operation {
    public:
        SellOperation(std::string order_type,
                      const size_t price,
                      const size_t quantity,
                      std::string order_id)
                : Operation("SELL")
                , _order_type(std::move(order_type))
                , _price(price)
                , _quantity(quantity)
                , _order_id(std::move(order_id)) {}

        void executeOn(Data &data) override;

    private:
        std::string _order_type;
        size_t _price;
        size_t _quantity;
        std::string _order_id;
    };

    void SellOperation::executeOn(Data &data) {
        auto &order_book = data._order_book;
        auto &buy_book = data._buy_book;
        if (order_book.find(_order_id) != order_book.end()) return;
        const auto &end_it = buy_book.upper_bound(_price);
        for (auto it = buy_book.begin(); it != end_it && _quantity;) {
            auto &order_bucket = it->second;
            auto &total_quantity = order_bucket._total_quantity;
            auto &order_list = order_bucket._order_list;
            auto &order_table = order_bucket._order_table;
            for (auto it = order_list.begin(); it != order_list.end() && _quantity;) {
                auto &available_quantity = it->first;
                const auto &buy_order_id = it->second;
                const size_t trade_quantity = std::min(_quantity, available_quantity);
                const auto &buy_order = order_book[buy_order_id];
                printTrade(buy_order.getOrderId(), buy_order.getPrice(), trade_quantity,
                           _order_id, _price, trade_quantity);
                _quantity -= trade_quantity;
                available_quantity -= trade_quantity;
                total_quantity -= trade_quantity;
                if (available_quantity == 0) {
                    order_book.erase(buy_order_id);
                    order_table.erase(buy_order_id);
                    it = order_list.erase(it);
                }
            }
            if (order_list.empty()) {
                it = buy_book.erase(it);
            }
        }
        if (_quantity == 0) return;
        if (_order_type == "GFD") {
            data.addOrder(Order("SELL", _price, _quantity, _order_id));
        }
    }

    class CancelOperation : public Operation {
    public:
        explicit CancelOperation(std::string order_id)
                : Operation("CANCEL")
                , _order_id(std::move(order_id)) {}

        void executeOn(Data &data) override;

    private:
        std::string _order_id;
    };

    void CancelOperation::executeOn(Data &data) {
        data.deleteOrder(_order_id);
    }

    class ModifyOperation : public Operation {
    public:
        ModifyOperation(std::string order_id,
                        std::string operation_type,
                        const size_t new_price,
                        const size_t new_quantity)
                : Operation("MODIFY")
                , _order_id(std::move(order_id))
                , _operation_type(std::move(operation_type))
                , _new_price(new_price)
                , _new_quantity(new_quantity) {
            _operations.push_back(std::make_unique<CancelOperation>(_order_id));
            if (_operation_type == "BUY") {
                _operations.push_back(std::make_unique<BuyOperation>("GFD", _new_price, _new_quantity, _order_id));
            } else if (_operation_type == "SELL") {
                _operations.push_back(std::make_unique<SellOperation>("GFD", _new_price, _new_quantity, _order_id));
            }
        }

        void executeOn(Data &data) override;

    private:
        std::string _order_id;
        std::string _operation_type;
        size_t _new_price;
        size_t _new_quantity;
        std::vector<std::unique_ptr<Operation>> _operations;
    };

    void ModifyOperation::executeOn(Data &data) {
        const auto &order_book = data._order_book;
        if (order_book.find(_order_id) == order_book.end()) return;
        for (auto &&operation : _operations) {
            operation->executeOn(data);
        }
    }

    class PrintOperation : public Operation {
    public:
        PrintOperation() : Operation("PRINT") {}

        void executeOn(Data &data) override;
    };

    void PrintOperation::executeOn(Data &data) {
        std::cout << "SELL:" << std::endl;
        for (auto rit = data._sell_book.rbegin(); rit != data._sell_book.rend(); ++rit) {
            std::cout << rit->first << " " << rit->second._total_quantity << std::endl;
        }
        std::cout << "BUY:" << std::endl;
        for (const auto &entry : data._buy_book) {
            std::cout << entry.first << " " << entry.second._total_quantity << std::endl;
        }
    }

    class OperationFactory {
    public:
        explicit OperationFactory(std::string type) : _type(std::move(type)) {}

        virtual ~OperationFactory() = default;

        virtual std::string getType() const {
            return _type;
        }

        virtual std::unique_ptr<Operation> create(const std::vector<std::string> &columns) = 0;

    private:
        std::string _type;
    };

    class BuyOperationFactory : public OperationFactory {
    public:
        BuyOperationFactory() : OperationFactory("BUY") {}

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns) override;
    };

    std::unique_ptr<Operation> BuyOperationFactory::create(const std::vector<std::string> &columns) {
        if (columns.size() != 5) return nullptr;
        assert(columns[0] == getType());
        const auto &order_type = columns[1];
        if (order_type != "IOC" && order_type != "GFD") return nullptr;
        const auto price = std::stoi(columns[2]);
        if (price <= 0) return nullptr;
        const auto quantity = std::stoi(columns[3]);
        if (quantity <= 0) return nullptr;
        const auto &order_id = columns[4];
        return std::make_unique<BuyOperation>(order_type, price, quantity, order_id);
    }

    class SellOperationFactory : public OperationFactory {
    public:
        SellOperationFactory() : OperationFactory("SELL") {}

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns) override;
    };

    std::unique_ptr<Operation> SellOperationFactory::create(const std::vector<std::string> &columns) {
        if (columns.size() != 5) return nullptr;
        assert(columns[0] == getType());
        const auto &order_type = columns[1];
        if (order_type != "IOC" && order_type != "GFD") return nullptr;
        const auto price = std::stoi(columns[2]);
        if (price <= 0) return nullptr;
        const auto quantity = std::stoi(columns[3]);
        if (quantity <= 0) return nullptr;
        const auto &order_id = columns[4];
        return std::make_unique<SellOperation>(order_type, price, quantity, order_id);
    }

    class CancelOperationFactory : public OperationFactory {
    public:
        CancelOperationFactory() : OperationFactory("CANCEL") {}

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns) override;
    };

    std::unique_ptr<Operation> CancelOperationFactory::create(const std::vector<std::string> &columns) {
        if (columns.size() != 2) return nullptr;
        assert(columns[0] == getType());
        const auto &order_id = columns[1];
        return std::make_unique<CancelOperation>(order_id);
    }

    class ModifyOperationFactory : public OperationFactory {
    public:
        ModifyOperationFactory() : OperationFactory("MODIFY") {}

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns) override;
    };

    std::unique_ptr<Operation> ModifyOperationFactory::create(const std::vector<std::string> &columns) {
        if (columns.size() != 5) return nullptr;
        assert(columns[0] == getType());
        const auto &order_id = columns[1];
        const auto &operation_type = columns[2];
        const auto new_price = std::stoi(columns[3]);
        if (new_price <= 0) return nullptr;
        const auto new_quantity = std::stoi(columns[4]);
        if (new_quantity <= 0) return nullptr;
        return std::make_unique<ModifyOperation>(order_id, operation_type, new_price, new_quantity);
    }

    class PrintOperationFactory : public OperationFactory {
    public:
        PrintOperationFactory() : OperationFactory("PRINT") {}

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns) override {
            if (columns.size() != 1) return nullptr;
            assert(columns[0] == getType());
            return std::make_unique<PrintOperation>();
        }
    };

    class OperationCreator {
    public:
        OperationCreator();

        void addOperationFactory(std::unique_ptr<OperationFactory> factory) {
            _factory_table.emplace(factory->getType(), std::move(factory));
        }

        std::unique_ptr<Operation> create(const std::vector<std::string> &columns);

    private:
        std::unordered_map<std::string, std::unique_ptr<OperationFactory>> _factory_table;
    };

    OperationCreator::OperationCreator() {
        addOperationFactory(std::make_unique<BuyOperationFactory>());
        addOperationFactory(std::make_unique<SellOperationFactory>());
        addOperationFactory(std::make_unique<CancelOperationFactory>());
        addOperationFactory(std::make_unique<ModifyOperationFactory>());
        addOperationFactory(std::make_unique<PrintOperationFactory>());
    }

    std::unique_ptr<Operation> OperationCreator::create(const std::vector<std::string> &columns) {
        if (columns.empty()) return nullptr;
        auto it = _factory_table.find(columns[0]);
        if (it == _factory_table.end()) return nullptr;
        return it->second->create(columns);
    }

    class Engine {
    public:
        Engine() = default;
        Engine(const Engine &) = delete;
        Engine &operator=(const Engine &) = delete;

        bool executeOn(const std::string &line);

        void addOperationFactory(std::unique_ptr<OperationFactory> factory) {
            _operation_creator.addOperationFactory(std::move(factory));
        }

    private:

        std::vector<std::string> interpret(const std::string &line);

        OperationCreator _operation_creator;
        using OperationList = std::list<std::unique_ptr<Operation>>;
        OperationList _operations;
        std::unordered_map<std::string, OperationList::iterator> _order_table;
        std::mutex _mtx;
        Data _data;
    };

    std::vector<std::string> Engine::interpret(const std::string &line) {
        std::istringstream input(line);
        std::vector<std::string> columns;
        std::string column;
        while (input >> column) {
            columns.push_back(column);
        }
        return columns;
    }

    bool Engine::executeOn(const std::string &line) {
        if (line == "EOF") return false;
        const auto &columns = interpret(line);
        if (auto operation = _operation_creator.create(columns)) {
            operation->executeOn(_data);
        }
        return true;
    }
    
    template <typename T>
    class thread_safe_queue {
    public:
        thread_safe_queue() = default;
        thread_safe_queue(const thread_safe_queue &other) {
            std::lock_guard<std::mutex> lk(other.mtx);
            q = other.q;
        }
        thread_safe_queue(thread_safe_queue &&other) {
            std::lock_guard<std::mutex> lk(other.mtx);
            q = std::move(other.q);
        }
        void push(T x) {
            std::lock_guard<std::mutex> lk(mtx);
            q.push(std::move(x));
            cond.notify_one();
        }
        T pop() {
            std::unique_lock<std::mutex> lk(mtx);
            cond.wait(lk, [this]{ return !q.empty(); });
            const T res = std::move(q.front());
            q.pop();
            return res;
        }

    private:
        std::mutex mtx;
        std::queue<T> q;
        std::condition_variable cond;
    };
    
    void reader(thread_safe_queue<std::string> &q) {
        std::string line;
        while (std::getline(std::cin, line)){
            q.push(line);
        }
        q.push("EOF");        
    }
    
    void worker(thread_safe_queue<std::string> &q, const std::unique_ptr<Engine> &engine) {
        while (engine->executeOn(q.pop()));        
    }
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    using namespace MatchingEngine;
    thread_safe_queue<std::string> q;
    auto engine = std::make_unique<Engine>();
    std::thread reader_thread(reader, std::ref(q));
    std::thread worker_thread(worker, std::ref(q), std::ref(engine));
    if (reader_thread.joinable()) {
        reader_thread.join();
    }
    if (worker_thread.joinable()) {
        worker_thread.join();
    }
    // std::string line;
    // while (std::getline(std::cin, line)) {
    //     engine->executeOn(line);
    // }
    return 0;
}
