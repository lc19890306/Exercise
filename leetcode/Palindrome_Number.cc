class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div(1);
        while (x / div >= 10)
            div *= 10;
        while (x) {
            if (x / div != x % 10)
                return false;
            else {
                x %= div;
                x /= 10;
                div /= 100;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
      // Typically, negatives and numbers ending with zero are not palindrome (except 0)
      // test case: 10, 0, -1, 121, 1331
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int sum(0);
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return x == sum || x == sum / 10;
    }
};
