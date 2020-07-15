#include <iostream>
#include "hash_map.hh"

using namespace std;

int main() {
    hash_map<int, std::string> dict;
    dict.insert(std::make_pair(1, "one"));
    dict.emplace(2, "two");
    cout << dict.at(1) << endl;
    cout << dict[2] << endl;
    cout << dict[3] << endl;
    dict[3] = "three";
    cout << dict[3] << endl;
    return 0;
}
