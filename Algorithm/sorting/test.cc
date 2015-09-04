#include "functions.hh"

#include <iostream>
#include <vector>

#include <algorithm>

#include "heap_sort.hh"
// using namespace std;

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
 
    Algo::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
 
    Algo::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';
    return 0;
}
