class Solution {
public:
    int palin(int i, int j, string &s){
        int cnt=0;
        while(i>=0 && j<s.length() && s[i--]==s[j++])
        cnt++;
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++)
            cnt+=palin(i,i,s)+palin(i,i+1,s);
            return cnt;
    }
};