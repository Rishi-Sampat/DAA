class Solution {
public:
    int findComplement(int num) {
        int ret = 0; 
        int power = 1;

        while (num > 0) {
            int bit = num & 1; 
            int flipped = bit ^ 1;

            ret += flipped * power;
            power <<= 1;
            num >>= 1;
        }
        return ret;
    }
};