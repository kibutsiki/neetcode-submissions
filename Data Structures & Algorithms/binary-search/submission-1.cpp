class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start{}, last = nums.size() - 1;
        int mid = 0;
        while(start <= last){
            mid = (last + start)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                last = mid-1;
            }
        }

        return -1;
    }
};
