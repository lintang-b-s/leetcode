/*

intiuisi:
- coba isi cell dari kiri kanan &  atas ke bawah, coba angka 1 sampai 9,
    - jika salah satu memenuhi 3 kondisi, set angka ke cell tsb, lalu rekursi ke fungsi solve lagi.
    - jika sampai angka 9 masih belum memenuhi 3 kondisi, return false , backtrack ke parent, parent mencoba angka yg lain dari yg sebelumnya di set.
    

ilustrrasi: https://lh6.googleusercontent.com/K6GqbUp1oiY3S01bZtxY6S7N8GCiLBke55d46BJ0fm2Eia8EDU284lyfWHoJ4kE_T0xpPh-ZU-GwNiCZ6Z9RtPDWqUJSBSHYp3PQFLulvIufpuI5dQnoz3Mr1TWZ4nF9S0idTtwM

ilustraasi: https://upload.wikimedia.org/wikipedia/commons/8/8c/Sudoku_solved_by_bactracking.gif

- isValid(board, c, row, col) function untuk cek apakah penempatan angka memenuhi 3 kondisi: 
    - loop i =0 sampai 9 ->
    - board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c, untuk cek apakah di 3x3 grid ada angka yang sama dg angka yg ingin ditempatkan.
    - board[i][col] == c ->. untuk cek apakah dalam colom = col ada angka yg sama
    - board[col][i] == c -> untuk cek apakah ada dalam row =row ada angka yang sama.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i=0; i < board.size(); i++){
            for (int j =0; j < board[0].size(); j++){
                if (board[i][j] == '.'){
                    for (char coba = '1'; coba <= '9'; coba++){
                        if (isValid(board, i, j , coba)) {
                            board[i][j] = coba;
                            if (solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
 
};