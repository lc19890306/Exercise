#include <string>

using std::string;

bool cmp(const string &lhs, const string &rhs) {
    if (lhs.size() == rhs.size())
        return lhs > rhs;
    auto shorter(lhs.size() < rhs.size() ? lhs : rhs);
    auto longer(shorter == lhs ? rhs : lhs);
    while (shorter.size() < longer.size())
        shorter += shorter.back();
    return shorter == lhs ? shorter > longer : longer > shorter;
}

int main() {
  auto ret(cmp("9", "34"));
  return 0;
}
