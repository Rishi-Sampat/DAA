class Solution {
public:
    vector<int> diStringMatch(string s) {
         int n = s.size();
        vector<int>v;
        int i=0;
        int j=n;
        for(char ch:s){
            if(ch == 'I') v.push_back(i++);
            else v.push_back(j--);
        }
        v.push_back(i); // i == j at the end
        return v;
    }
};