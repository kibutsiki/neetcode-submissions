class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int> maxvolume{};
        size_t right{};
        size_t left{heights.size()-1};
        size_t max = 0;
        while(right < left){
            int value_curr = heights.at(right);            
            int value_curr2 = heights.at(left);
            size_t calculation = min(value_curr, value_curr2) * (left-right);
            if(max < calculation){
                max = calculation;
            }else{
                if(right < left){
                    right+= 1;
                }
                else{
                    left += 1;
                }
            }
        }

        return max;
    }
};
