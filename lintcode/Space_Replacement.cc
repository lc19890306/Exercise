class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        for (int i(0); i < length;) {
            if (string[i] == ' ') {
                string[i] = '%';
                reverse(string + i + 1, string + length);
                string[length] = '0';
                string[length + 1] = '2';
                reverse(string + i + 1, string + length + 2);
                length += 2;
                string[length] = 0;
                i += 3;
            }
            else
                ++i;
        }
        return length;
    }
};  
