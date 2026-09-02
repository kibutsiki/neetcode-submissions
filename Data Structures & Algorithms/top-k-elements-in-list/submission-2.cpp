class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == k){
            return nums;
        }
        std::vector<int> ret{};
        std::unordered_map<int, int> occurance= {};
        int highest = 1;
        ret.push_back(nums.at(0));
        for(int i=0; i < nums.size();i++){
            occurance[nums.at(i)]++;
            if(occurance[nums.at(i)] > highest){
                highest = occurance[nums.at(i)];
                if(ret.back() != nums.at(i)){
                    ret.push_back(nums.at(i));
                    int index = 0;
                    int smallest = occurance[ret.at(0)];
                    for(int j =1; j < ret.size();j++){
                        if(occurance[ret.at(j)] < smallest){
                            index = j;
                            smallest = occurance[ret.at(j)];
                        }
                    }
                    cout << index;
                    if(ret.size() > k){
                        ret.erase(ret.begin() + index);
                    }
                }
                highest = 0;
            }
        }

        return ret;
    }
};
