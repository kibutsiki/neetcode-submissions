class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> ret{};
        std::unordered_map<int, int> occurance= {};
        int highest = 0;
        for(int i=0; i < nums.size();i++){
            occurance[nums.at(i)]++;
            if(occurance[nums.at(i)] > highest){
                highest = occurance[nums.at(i)];
                if(ret.empty()){
                    ret.push_back(nums.at(i));
                    continue;
                }
                if(ret.back() != nums.at(i)){
                    ret.push_back(nums.at(i));
                    if(ret.size() > k){
                        ret.erase(ret.begin());
                    }
                }
            }
        }

        return ret;
    }
};
