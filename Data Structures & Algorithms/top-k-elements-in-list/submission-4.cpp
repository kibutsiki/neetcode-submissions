class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tracking;
        for(int num : nums){
            tracking[num]++;
        }
        vector<pair<int,int>> pairs;
        for(auto& ci : tracking){
            pairs.push_back({ci.first, ci.second});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ret;
        int n = (int)pairs.size();
        for(int i=n-1; i >= n-k;i--){
            ret.push_back(pairs.at(i).first);
        }
        return ret;
    }
};
