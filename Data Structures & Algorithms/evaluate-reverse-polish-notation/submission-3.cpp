class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> numbers;
        for(string c : tokens){
            if(c == "+" || c == "*" || c == "/" || c == "-"){
                int num1 = stoi(numbers.top());
                numbers.pop();
                int num2 = stoi(numbers.top());
                numbers.pop();
                if(c == "+"){
                    numbers.push(to_string(num1+num2));
                }
                else if(c == "*"){
                    numbers.push(to_string(num2*num1));
                }
                else if(c == "/"){
                    numbers.push(to_string(num2/num1));
                }
                else if(c == "-"){
                    numbers.push(to_string(num2-num1));
                }
            }
            else{
                numbers.push(c);
            }
        }
        return stoi(numbers.top());
    }
};
