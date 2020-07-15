#include <iostream>
#include "hash_map.hh"

using namespace std;

int main() {
    hash_map<int, std::string> dict;
    dict.add_or_update_mapping(1, "one");
    dict.add_or_update_mapping(2, "two");
    dict.add_or_update_mapping(3, "three");
    std::cout << dict.value_for(1) << std::endl;
    std::cout << dict.value_for(2) << std::endl;
    std::cout << dict.value_for(3) << std::endl;
    return 0;
}
