class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};

        int l{};
        for(int r = k-1; r < nums.size(); r++){
            int copy = {l};
            int max_num = {};
            while(copy <= r){
                max_num = max(max_num, nums.at(copy));
                copy++;
            }
            res.push_back(max_num);
            l++;
        }

        return res;
    }
};
