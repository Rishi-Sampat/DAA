class Solution {
public:
    string convertToBase7(int num) {
         if (num == 0) return "0";
    
    bool negative = num < 0;
    long n = abs((long)num);  
    string result = "";
    
    while (n > 0) {
        int digit = n % 7;
        result += to_string(digit);
        n /= 7;
    }
    
    if (negative) result += "-";
    reverse(result.begin(), result.end());
    
    return result;
    }
};