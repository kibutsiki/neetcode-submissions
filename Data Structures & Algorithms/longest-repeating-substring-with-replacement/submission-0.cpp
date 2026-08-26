class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> occurance;

        int longest {};

        int left {}, frequency {};

        for(int right{}; right < s.size();right++){
            occurance[s.at(right)]++;
            frequency = max(frequency, occurance[s.at(right)]);

            while((right - left + 1) - frequency > k){
                occurance[s.at(left)]--;
                left++;
            }

            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};

