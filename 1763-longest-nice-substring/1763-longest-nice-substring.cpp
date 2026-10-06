class Solution {
public:
    string longestNiceSubstring(string s) {
         vector<int> sub = longestNiceSubstring(s, 0, s.size());
        return s.substr(sub[0], sub[1] - sub[0]);
    }

private:
    vector<int> longestNiceSubstring(string &s, int left, int right) {
        unordered_set<char> charSet = getCharSet(s, left, right);

        for (int i = left; i < right; i++) {
            if (!charSet.count(tolower(s[i])) || !charSet.count(toupper(s[i]))) {

                vector<int> prefix = longestNiceSubstring(s, left, i);
                vector<int> suffix = longestNiceSubstring(s, i + 1, right);

                if (prefix[1] - prefix[0] >= suffix[1] - suffix[0])
                    return prefix;
                else
                    return suffix;
            }
        }

        return {left, right};
    }

    unordered_set<char> getCharSet(string &s, int left, int right) {
        unordered_set<char> charSet;

        for (int i = left; i < right; i++)
            charSet.insert(s[i]);

        return charSet;
    }
};