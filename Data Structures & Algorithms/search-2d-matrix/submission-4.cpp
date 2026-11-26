class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low{}, high{static_cast<int>(matrix.size()-1)};
        while(low <= high){
            int middle = low+(high - low)/2;
            if(matrix[middle][0] > target){
                high = middle - 1;
            }else if(matrix[middle][matrix[0].size()-1] < target){
                low = middle + 1;
            }
            else{
                int lowInner{}, highInner{static_cast<int>(matrix[0].size()-1)};
                while(lowInner <= highInner){
                    int middleInner = lowInner+(highInner - lowInner)/2;
                    if(matrix[middle][middleInner] == target){
                        return true;
                    }else if(matrix[middle][middleInner] > target){
                        highInner = middleInner - 1;
                    }else{
                        lowInner = middleInner + 1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
