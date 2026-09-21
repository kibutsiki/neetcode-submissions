class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start{}, last = nums.size() - 1;

        while(start <= last){
            int mid = (last + start)/2;
            if(target == nums.at(mid)){
                return mid;
            }
            else if(target > nums.at(mid)){
                start = mid+1;
            }
            else{
                last = mid-1;
            }
        }

        return -1;
    }
};
