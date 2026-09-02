class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size();
        int mid = start + (end - start) / 2;
        int sum = numbers.at(mid);
        if(numbers.at(mid) > target){
            end = mid+1;
        }
        int i = 0;
        while(i < mid){
            if(numbers.at(i) + numbers.at(mid) == target){
                return {i+1, mid+1};
            }
            if(numbers.at(i) + numbers.at(mid) < target){
                i++;
            }
            else{
                mid--;
            }
        }

        return {};
    }
};
