/*
ilustrasi: https://static.javatpoint.com/tutorial/daa/images/n-queens-problems3.png
board[i][j] = cell di papan row i kolom j. 
'Q' = ditempati queen
'.' = tidak ditempati queen

intusisi: coba letakkan queen tiap baris dengan mencoba setiap kolom, jika kolom tsb memenuhi kondisi lanjut baris selanjutnya, jika tidak memenuhi backtrack ke kondisi sebelumnya. 

*/


class Solution {
private:
    bool isSafePlace(int n, vector<string>& board, int row, int col) {
        // cek di row row sebelumnya apakah ada yang queen yg satu kolom
        for (int i=0; i < row; i++){
            if (board[i][col] == 'Q') {
                return false;
            }
        } 

        // cek apakah di row row sebelumnya ada queen yg diagonal ke kiri
        for (int i=col -1, j =row-1; i >=0 && j>=0; i--,j--){
            if (board[j][i] == 'Q') {
                return false;
            }
        }

        // cek apakahd i row row sebelumnya ada queen yang diagonal ke kekanan
           for (int i=col+1 , j =row-1; i >=0 && j>=0; i++,j--){
            if (board[j][i] == 'Q') {
                return false;
            }
        }
        // kalau semua kondisi memenuhi reuturn true
        return true;
    }

    void solve(int n, vector<vector<string>>& output, vector<string>& board, int row) {
        // jika row yg dicoba melebihi ukuran n papan, berarti solusi ditemukan
        if (row == n) {
            output.push_back(board);
            return ;
        }
         
        // di row saat ni coba setiap kolom, apakah posisinya memenuhi kondisi
        for (int col=0 ; col < n; col++){
         
            if (isSafePlace(n, board, row, col)) {
                // jika posisi memenuhi kondisi, set cell dg 'Q'
                board[row][col] = 'Q';
                solve(n, output, board, row+1);
                // jika posisi tidak memenuhi kondisi, set cell dg '.' dan backtrack ke kedaaan papan sebelumnya.
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;  
        vector<string> board(n, string(n, '.'));
        solve(n, output, board, 0);
        return output;
    }
};