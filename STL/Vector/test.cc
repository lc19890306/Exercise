#include <iostream>
#include "Vector.hh"

using namespace std;

template<typename T>
using V = Vector<T>;

template<typename T>
void print(const V<T> &v, const std::string &s) {
    cout << s << " : ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

struct A {
    A(){
        cout<<"A::A\n";
    }
    A(const A &other){
        cout<<"A::copy\n";
    }
    A(A &&other){
        cout<<"A::move\n";
    }
    ~A(){
        cout<<"A::~A\n";
    }
    int x = 1;
};

int main() {
    V<int> v1(5), v2(3, 5);
    print(v1, "v1");
    print(v2, "v2");
    try {
        v2.at(2) = 4;
    } catch (exception &e) {
        std::cout << e.what() << std::endl;
    }
    print(v1, "v1");
    print(v2, "v2");
    V<int> v3(std::move(v2));
//    print(v2, "v2"); // should not use v2 after moving
    print(v3, "v3");
    V<int> v;
    cout << "capacity is " << v.capacity() << endl; // 0
    v.push_back(1);
    cout << "capacity is " << v.capacity() << endl; // 1
    v.push_back(2);
    cout << "capacity is " << v.capacity() << endl; // 2
    v.push_back(3);
    cout << "capacity is " << v.capacity() << endl; // 4
    v.push_back(4);
    cout << "capacity is " << v.capacity() << endl; // 4
    V<A> vv(3);
    cout << "popping back..." << endl;
    vv.pop_back(); // pop_back calls A's destructor
    cout << "done" << endl;
    vv.capacity(); // nodiscard issues a warning during compilation
    V<pair<int, int>> vp;
    vp.emplace_back(1, 3);
    cout << vp[0].first << ", " << vp[0].second << endl; // 1, 3
    return 0;
}
