// // Too clumsy!!
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         if (nums.size() == 1)
//             return nums[0];
//         sort(nums.begin(), nums.end());
//         auto first(nums.begin()), last(first);
//         auto half_size(nums.size() >> 1);
//         while (first < nums.end()) {
//             first = adjacent_find(first, nums.end());
//             last = adjacent_find(first, nums.end(), less<int>());
//             if (distance(first, last) + 1 > half_size)
//                 return *first;
//             else
//                 first = last + 1;
//         }
//     }
// };

// // The n/2-th element in the sorted array should be the majority element
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() >> 1];
//     }
// };

// // Just do partial sorting and find the n/2-th element
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
//         return nums[nums.size() >> 1];
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> hash_map;
//         auto half_size(nums.size() >> 1);
//         for (auto &&num : nums)
//             if (++hash_map[num] > half_size)
//                 return num;
//     }
// };

// // Randomization - since the probability of finding the majority element is always greater than 50%, randomly iterate different element to test whether it is the majority element
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_set<int> unique_nums;
//         auto half_size(nums.size() >> 1);
//         srand(unsigned(time(NULL)));
//         while (true) {
//             auto idx(rand() % nums.size());
//             if (unique_nums.find(nums[idx]) == unique_nums.end()) {
//                 unique_nums.insert(nums[idx]);
//                 if (count(nums.begin(), nums.end(), nums[idx]) > half_size)
//                     return nums[idx];
//             }
//         }
//     }
// };

// Divide-and-conquer - divide the nums into two halves and find the majority elements A and B in each half, respectively
// if A == B then this is the majority element
// otherwise count A and B in the nums and find out the majority element between them
template<typename RandomIt>
RandomIt findMajorityElement(RandomIt first, RandomIt last) {
    if (first == last)
        return last;
    auto size(distance(first, last));
    if (size == 1)
        return first;
    auto mid(first + (size >> 1));
    auto left(findMajorityElement(first, mid));
    auto right(findMajorityElement(mid, last));
    if (*left == *right)
        return left;
    return count(first, last, *left) > count(first, last, *right) ? left : right;
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return *findMajorityElement(nums.begin(), nums.end());
    }
};

// Boyer-Moore Voting Algorithm
// BEST solution for this kind of problems
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate(0), count(0);
        for (auto &&num : nums) {
            if (candidate == num)
                ++count;
            else if (0 == count) {
                candidate = num;
                count = 1;
            }
            else
                --count;
        }
	// in theory, here should add a double check if count(nums.begin(), nums.end(), candidate) >= nums.size() / 2;
	// in thie problem, we assume there must exist such a number, so we omit it
        return candidate;
    }
};

// Bit manipulation - since each number is a 32-bit integer, for each bit, count the appearance of 1 in all elements, if greater than n / 2, this bit should be 1 in the majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret(0);
        auto half_size(nums.size() >> 1);
        for (int i(0), mask(1); i < 32; ++i, mask <<= 1) {
            int bit_counter(0);
            for (auto &&num : nums) {
                if (num & mask)
                    ++bit_counter;
                if (bit_counter > half_size) {
                    ret |= mask;
                    break;
                }
            }
        }
        return ret;
    }
};
