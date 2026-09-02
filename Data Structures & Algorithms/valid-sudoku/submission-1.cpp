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
                if(j/3 == i/3 && j%3 < 3 && i%3 < 3){
                    table3x3[board[i][j]]++;
                }
                if(i%3 == 0 && j%3 == 0 && i > 0 && j > 0){
                    for(auto& checker: table3x3){
                        cout << checker.first << " " << checker.second << endl;
                        if(checker.second > 1 && checker.first != '.'){
                            cout << "3x3" << endl;
                            return false;
                        }
                    }
                    table3x3.clear();
                }
            }
            for(auto& checker: row){
                if(checker.second > 1 && checker.first != '.'){
                    cout << "row" << endl;
                    return false;
                }
            }
            for(auto& checker: col){
                if(checker.second > 1 && checker.first != '.'){
                    cout << "col" << endl;
                    return false;
                }
            }
            row.clear();
            col.clear();
        }
        return true;
    }
};
