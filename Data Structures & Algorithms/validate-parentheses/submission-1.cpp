class Solution {
public:
    bool isValid(string s) {
        std::stack<char> valid;
        valid.push(s.at(0));

        for(int i{1}; i < s.size();i++){
            char temp;
            if(valid.empty()){
                temp = '.';
            }else{
                temp = valid.top();
            }

            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                valid.push(s[i]);
            }
            else if(
                (temp == '[' && s[i] == ']') || 
                (temp == '{' && s[i] == '}') || 
                (temp == '(' && s[i] == ')')){
                    valid.pop();
                }
            else{
                return false;
            }
        }
        return valid.empty();
    }
};