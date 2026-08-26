class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> s1_vec(26,0);
        vector<int> s2_vec(26,0);

        for(int i{}; i < s1.size();i++){
            s1_vec[s1.at(i) - 'a']++;
            s2_vec[s2.at(i) - 'a']++;
        }

        int matches{};


        for(int i{}; i < 26;i++){
            if(s1_vec[i] == s2_vec[i]){
                matches++;
            }
        }
        int l{};
        for(int i = s1.size(); i < s2.size();i++){
            if(matches == 26){
                return true;
            }
            int index = s2.at(i) - 'a';
            s2_vec.at(index)++;
            if(s1_vec.at(index) == s2_vec.at(index)){
                matches++;
            }
            else if(s1_vec.at(index) + 1 == s2_vec.at(index)){
                matches--;
            }

            index = s2.at(l) - 'a';
            s2_vec.at(index)--;
            if(s1_vec.at(index) == s2_vec.at(index)){
                matches++;
            }
            else if(s1_vec.at(index)-1 == s2_vec.at(index)){
                matches--;
            }
            l++;
        }
        return matches == 26;

    }
};
