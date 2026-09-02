class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> table3x3;
        unordered_map<char,int> row;
        unordered_map<char, int> col;
        for(int i=0; i < board.size();i++){
            for(int j = 0; j < board[i].size();j++){
                row[board[i][j]]++;
                col[board[j][i]]++;
                if(i%3 == 0 && j%3 == 0){
                    for(auto& checker: table3x3){
                        if(checker.second > 1 && checker.first != '.'){
                            return false;
                        }
                    }
                    table3x3.clear();
                }
                for(auto& checker: row){
                    if(checker.second > 1 && checker.first != '.'){
                        return false;
                    }
                }
                for(auto& checker: col){
                    if(checker.second > 1 && checker.first != '.'){
                        return false;
                    }
                }
                row.clear();
                col.clear();
            }
        }
        return true;
    }
};
