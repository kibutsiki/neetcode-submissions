class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};

        int l{};
        int max_num_index{};
        for(int r = k-1; r < nums.size(); r++){
            int copy = {l};
            int max_num = INT_MIN;
            if(max_num_index > l && nums.at(r) > nums.at(max_num_index)){
                max_num_index = r;
                res.push_back(nums.at(r));
                continue;
            }
            while(copy <= r){
                if(max_num < nums.at(copy)){
                    max_num_index = copy;
                    max_num = nums.at(copy);
                }
                
                copy++;
            }
            res.push_back(max_num);
            l++;
        }

        return res;
    }
};
