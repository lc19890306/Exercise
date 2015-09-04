#include "priority_queue.hh"

#include <queue>
#include <vector>
#include <iostream>
 
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
 
int main() {
    Algo::priority_queue<int> q;
 
    for(int n : {1,8,5,6,3,4,0,9,3,2})
        q.push(n);
 
    print_queue(q);
 
    Algo::priority_queue<int, std::vector<int> > q2;
 
    for(int n : {1,8,5,6,3,4,0,9,3,2})
        q2.push(n);
 
    print_queue(q2);
}
