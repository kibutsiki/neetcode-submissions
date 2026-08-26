class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> temp_idx;
        std::vector<int> ans(temperatures.size(),0);

        for(int i{}; i < temperatures.size();i++){
            while(!temp_idx.empty() && temperatures.at(i) > temperatures.at(temp_idx.top())){
                 ans.at(temp_idx.top()) = i - temp_idx.top();
                 temp_idx.pop();
            }

            temp_idx.push(i);
        }

        return ans;
    }
};
