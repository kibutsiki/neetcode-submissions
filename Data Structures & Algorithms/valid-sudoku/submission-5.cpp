class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> table1_3x3;
        unordered_map<char, int> table2_3x3;
        unordered_map<char, int> table3_3x3;
        unordered_map<char,int> row;
        unordered_map<char, int> col;
        for(int i=0; i < board.size();i++){
            if(i%3 == 0 && i > 0){
                for(auto& checker: table1_3x3){
                    if(checker.second > 1 && checker.first != '.'){
                        cout << checker.first << " " << checker.second << endl;
                        cout << "table1" << endl;
                        return false;
                    }
                }
                for(auto& checker: table2_3x3){
                    if(checker.second > 1 && checker.first != '.'){
                        cout << checker.first << " " << checker.second << endl;
                        cout << "table2" << endl;
                        return false;
                    }
                }for(auto& checker: table3_3x3){
                    if(checker.second > 1 && checker.first != '.'){
                        cout << "table3" << endl;
                        return false;
                    }
                }
                table1_3x3.clear();
                table2_3x3.clear();
                table3_3x3.clear();
            }
            for(int j = 0; j < board[i].size();j++){
                if(board[i][j] == '.'){
                    continue;
                }
                row[board[i][j]]++;
                col[board[j][i]]++;
                if(j/3 == 0){
                    table1_3x3[board[i][j]]++;
                }
                if(j/3 == 1){
                    table2_3x3[board[i][j]]++;
                }
                if(j/3 == 2){
                    table3_3x3[board[i][j]]++;
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
