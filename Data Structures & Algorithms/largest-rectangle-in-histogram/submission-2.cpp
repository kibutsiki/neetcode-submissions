class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area{};

        
        int right = heights.size()-1;
        for(int i{}; i < heights.size();i++){
            int min_height = heights[i];
            int j{i};
            while(j < heights.size()){
                min_height = min(min_height, heights[j]);
                j++;
                max_area = max(max_area, (min_height * (j - i)));
            }
        }
        return max_area;
    }
};
