class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int longest_sub{};
        int starting{};
        for(int i{0};i < s.size();i++){
            while(charSet.find(s.at(i)) != charSet.end()){
                charSet.erase(s.at(starting));
                starting++;
            }

            charSet.insert(s.at(i));
            longest_sub = max(longest_sub, i - starting + 1);
        }
        return longest_sub;
    }
};
