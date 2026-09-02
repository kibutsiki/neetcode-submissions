class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int index = 0, streak = 0, curr = nums[0], highest = 0;

        while(i < nums.size()){
            if(nums[i] != curr){
                curr = nums[i];
                streak = 0;
            }

            while(i < nums.size() && nums[i] == curr){
                i++;
            }
            streak++;
            curr++;
            highest = max(highest, streak);
        } 
        
        return highest;
    }
};
