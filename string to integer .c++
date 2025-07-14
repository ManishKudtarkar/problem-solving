class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int digit;
        int len = s.size();
        int i = 0;
        int sign =1;

        while (i < len && s[i] == ' ') ++i;

        if (i < len && (s[i] == '+' || s[i] == '-')){
            if (s[i]== '-') sign = -1;
            ++i;
        }

        while (i < len && s[i]>= '0' && s[i] <= '9') {
            int digit = s[i]- '0';

            if (result > (INT_MAX - digit) / 10)
                return sign == 1? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            ++i;
        }

        return result * sign;        
    }
};
