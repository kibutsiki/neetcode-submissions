class Solution {
public:
    bool isPalindrome(string s) {
        int count = 0;
        if(!isalpha(s.at(s.size()-1))){
            s = s.substr(0, s.size()-1);
        }
        for(int i=0; i < s.size();i++){
            if(isalpha(s.at(i))){
                s.at(count) = s.at(i);
                count++;
            }
        }
        s.resize(count);
        
        for(int i = 0; i < s.size();i++){
            if(s.at(i) > 'A' && s.at(i) < 'Z'){
                s.at(i) = s.at(i) - 'A' + 'a';
            }
        }
        cout << s;
        int first = 0, second = s.size()-1;
        while(first <= second){
            if(s.at(first) != s.at(second)){
                return false;
            }
            first++;
            second--;
        }
        
        
        
        return true;
    }
};
