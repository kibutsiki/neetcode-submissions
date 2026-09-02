class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> s1_map{};
        std::unordered_map<char, int> s2_map{};

        int l{};
        for(int i{}; i < s2.size();i++){
            if(i < s1.size()){
                s1_map[s1.at(i)]++;
            }
            s2_map[s2.at(i)]++;

            while(i - l + 1 > s1.size()){
                if(--s2_map[s2.at(l)] <= 0){
                    s2_map.erase(s2.at(l));
                }
                
                l++;
            }

            if(s1_map == s2_map && s1_map.size() == s1.size()){
                return true;
            }
        }

        return false;
    }
};
