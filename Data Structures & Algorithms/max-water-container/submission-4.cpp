class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        vector<int> maxvolume{};
        size_t right{};
        size_t left{heights.size()-1};
        size_t max_area = 0;
        while(right < left){
            int value_curr = heights.at(right);            
            int value_curr2 = heights.at(left);
            size_t calculation = min(value_curr, value_curr2) * (left-right);
            max_area = max(max_area, calculation);
            if(value_curr < value_curr2){
                right++;
            }
            else{
                left--;
            }
        }

        return max_area;
    }
};
