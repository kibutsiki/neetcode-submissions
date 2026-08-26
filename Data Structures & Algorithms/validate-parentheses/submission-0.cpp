class Solution {
public:
    bool isValid(string s) {
        std::stack<char> valid;
        std::unordered_map<char, char> valid_parentheses = {
            {']', '['},
            {')', '('},
            {'}' , '{'}
        };

        for(char c : s){
            if(valid_parentheses.count(c)){
                if(!valid.empty() && valid.top() == valid_parentheses[c]){
                    valid.pop();
                }
                else{
                    return false;
                }
            }
            else{
                valid.push(c);
            }
        }

        return valid.empty();
    }
};
