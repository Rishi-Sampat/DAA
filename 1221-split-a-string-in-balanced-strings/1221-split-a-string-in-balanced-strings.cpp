class Solution {
public:
    int balancedStringSplit(string s) {
        int bal = 0, ans = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                bal++;
            } else {
                bal--;
            }
            if (bal == 0) {
                ans++;
            }
        }
        return ans;
    }
};