class Solution {
public:
    string intToRoman(int num) {
        string ret;
        while (num > 0) {
            if (num > 999) {
                ret += "M";
                num -= 1000;
                continue;
            }
            if (num > 899) {
                ret += "CM";
                num -= 900;
                continue;
            }
            if (num > 499) {
                ret += "D";
                num -= 500;
                continue;
            }
            if (num > 399) {
                ret += "CD";
                num -= 400;
                continue;
            }
            if (num > 99) {
                ret += "C";
                num -= 100;
                continue;
            }
            if (num > 89) {
                ret += "XC";
                num -= 90;
                continue;
            }
            if (num > 49) {
                ret += "L";
                num -= 50;
                continue;
            }
            if (num > 39) {
                ret += "XL";
                num -= 40;
                continue;
            }
            if (num > 9) {
                ret += "X";
                num -= 10;
                continue;
            }
            if (num > 8) {
                ret += "IX";
                num -= 9;
                continue;
            }
            if (num > 4) {
                ret += "V";
                num -= 5;
                continue;
            }
            if (num > 3) {
                ret += "IV";
                num -= 4;
                continue;
            }
            if (num > 0) {
                ret += "I";
                num -= 1;
                continue;
            }
        }
        return ret;
    }
};

// Optimized version - avoid a couple of if condtions
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        while (num > 999) {
            ret += "M";
            num -= 1000;
        }
        if (num > 899) {
            ret += "CM";
            num -= 900;
        }
        if (num > 499) {
            ret += "D";
            num -= 500;
        }
        if (num > 399) {
            ret += "CD";
            num -= 400;
        }
        while (num > 99) {
            ret += "C";
            num -= 100;
        }
        if (num > 89) {
            ret += "XC";
            num -= 90;
        }
        if (num > 49) {
            ret += "L";
            num -= 50;
        }
        if (num > 39) {
            ret += "XL";
            num -= 40;
        }
        while (num > 9) {
            ret += "X";
            num -= 10;
        }
        if (num > 8) {
            ret += "IX";
            num -= 9;
        }
        if (num > 4) {
            ret += "V";
            num -= 5;
        }
        if (num > 3) {
            ret += "IV";
            num -= 4;
        }
        while (num > 0) {
            ret += "I";
            num -= 1;
        }
        return ret;
    }
};

// Use this solution
string M[] = {"", "M", "MM", "MMM"};
string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
class Solution {
public:
    string intToRoman(int num) {
        return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
    }
};
