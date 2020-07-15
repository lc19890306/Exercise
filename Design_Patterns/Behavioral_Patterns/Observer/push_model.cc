#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Subscriber;

class Publisher : public enable_shared_from_this<Publisher> {
public:
    void add(const std::shared_ptr<Subscriber> &subscriber);
    void subscribeEventForSubscriber(const std::shared_ptr<Subscriber> &subscriber, const std::string &event);
    void publish(const std::string &event);
    virtual ~Publisher() = default;

private:
    std::unordered_map<std::string, std::unordered_set<std::shared_ptr<Subscriber>>> _subscribers;
};

class Subscriber : public enable_shared_from_this<Subscriber> {
public:
    explicit Subscriber(std::string name) : _name(std::move(name)) {}

    void addPublisher(const std::shared_ptr<Publisher> &publisher) {
        _publisher = publisher;
    }

    void subscribe(const std::string &event) {
        _publisher->subscribeEventForSubscriber(shared_from_this(), event);
    }

    void get(const std::string &event) {
        cout << _name << " gets " << event << endl;
    }

    virtual ~Subscriber() = default;

private:
    std::string _name;
    std::shared_ptr<Publisher> _publisher;
};

void Publisher::add(const std::shared_ptr<Subscriber> &subscriber) {
    subscriber->addPublisher(shared_from_this());
}

void Publisher::subscribeEventForSubscriber(const shared_ptr<Subscriber> &subscriber, const string &event) {
    _subscribers[event].insert(subscriber);
}

void Publisher::publish(const string &event) {
    for (const auto &subscriber : _subscribers[event]) {
        subscriber->get(event);
    }
}

class Publisher1 : public Publisher {};
class Publisher2 : public Publisher {};

class Subscriber1 : public Subscriber {
public:
    explicit Subscriber1(const std::string &name) : Subscriber(name) {}
};
class Subscriber2 : public Subscriber {
public:
    explicit Subscriber2(const std::string &name) : Subscriber(name) {}
};

int main() {
    auto p1 = make_shared<Publisher1>();
    auto s1 = make_shared<Subscriber1>("s1");
    auto s2 = make_shared<Subscriber2>("s2");
    p1->add(s1);
    p1->add(s2);
    s1->subscribe("e1");
    s2->subscribe("e1");
    s2->subscribe("e2");
    p1->publish("e1");
    p1->publish("e2");
    return 0;
}