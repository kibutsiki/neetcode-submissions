class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }

        std::unordered_map<char,int> s_map {};
        std::unordered_map<char,int> t_map {};

        for(char c : t){
            t_map[c]++;
        }

        int have{}, l{}, start{}, need = t_map.size();
        int resLen = INT_MAX;

        for(int i{}; i < s.size();i++){
            char character = s.at(i);
            s_map[character]++;

            if(t_map.count(character) && s_map[character] == t_map[character]){
                have++;
            }
            while(have == need){
                if(i - l + 1 <  resLen){
                    resLen = i - l + 1;
                    start = l;
                }
                
                s_map[s[l]]--;

                if(t_map.count(s[l]) && s_map[s[l]] < t_map[s[l]]){
                    have--;
                }
                l++;
            }

        }
        return resLen == INT_MAX ? "" : s.substr(start, resLen);
    }
};
