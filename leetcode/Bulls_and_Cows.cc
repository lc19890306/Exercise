// Two-pass solution - O(n) time and O(1) space complexity
class Solution {
public:
    string getHint(string secret, string guess) {
        int count_a(0), count_b(0);
	// count is used to record the need for each digit
        vector<int> count(10);
        for (int i(0); i < secret.length(); ++i) {
	  // if s[i] == g[i], need is satisfied
            if (secret[i] == guess[i]) {
                ++count_a;
            }
	    // if s[i] != g[i], need is not satisfied, need for according digit increments
            else
                ++count[secret[i] - '0'];
        }
	// check the need for each digit
        for (int i(0); i < guess.length(); ++i) {
            if (secret[i] != guess[i]) {
                if (count[guess[i] - '0'] > 0) {
                    --count[guess[i] - '0'];
                    ++count_b;
                }
            }
            
        }
        return to_string(count_a) + "A" + to_string(count_b) + "B";
    }
};

// One-pass solution
// if s[i] == g[i], s[i] and g[i] are paired
// if s[i] != g[i], we need to check 
// 1. whether s[i] can pair with g[j] where j < i, if so, count_b increments
// 2. whether g[i] can pair with s[j] where j < i, if so, count_b increments
class Solution {
public:
    string getHint(string secret, string guess) {
        int count_a(0), count_b(0);
        vector<int> count(10);
        for (int i(0); i < secret.length(); ++i) {
            if (secret[i] == guess[i])
                ++count_a;
            else {
	      // use count[s[i]]++ to record an s[i] that need to be paired with g later
	      // if count[s[i]] < 0, there must exist a number of g[j] that can be paired with s[i]
	      // use count[g[i]]-- to record an g[i] that need to be paired with s later
	      // if count[g[i]] > 0, there must exist a number of s[j] that can be paired with g[i]
                if (count[secret[i] - '0']++ < 0)
                    ++count_b;
                if (count[guess[i] - '0']-- > 0)
                    ++count_b;
            }
        }
        return to_string(count_a) + "A" + to_string(count_b) + "B";
    }
};

// same as the above solution
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.length() != guess.length())
            return "0A0B";
        int count_A(0), count_B(0), count[10] = {0};
        for (int i(0); i < secret.length(); ++i) {
            if (secret[i] == guess[i])
                ++count_A;
            else {
                if (++count[secret[i] - '0'] <= 0)
                    ++count_B;
                if (--count[guess[i] - '0'] >= 0)
                    ++count_B;
            }
        }
        return to_string(count_A) + "A" + to_string(count_B) + "B";
    }
};
