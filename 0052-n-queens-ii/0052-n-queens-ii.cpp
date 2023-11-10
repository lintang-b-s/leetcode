/*
ilustrasi: https://static.javatpoint.com/tutorial/daa/images/n-queens-problems3.png


intusisi: coba letakkan queen tiap baris dengan mencoba setiap kolom, jika kolom tsb memenuhi kondisi lanjut baris selanjutnya, jika tidak memenuhi backtrack ke kondisi sebelumnya. Jika row == n , tambahkan count solusi


[Q,X,X,X]
[X,X,Q,X]
[X,X,X,X]
[X,X,X,Q]

[Q,X,X,X]
[X,X,X,Q]
[X,Q,X,X]
[X,X,X,X]




*/


class Solution {
public:
    int totalNQueens(int n) {
         std::set<int> col;
         std::set<int> diag;
         std::set<int> aDiag;
         int res = 0;
         backtrack(0, n, col, diag, aDiag, res);
        return res;
    }

    void backtrack(int row, int n,  std::set<int>& col,
     std::set<int>& diag,  std::set<int>& aDiag, int& res){
         if (row ==n) {
             res +=1;
             return ;
         }
         
         for (int c = 0 ; c < n; c++){
             int d = row + c;
             int ad = row - c;
             if (col.contains(c) || aDiag.contains(ad) || diag.contains(d)) {
                 continue;
             }
             col.insert(c);aDiag.insert(ad);diag.insert(d);
             backtrack(row+1, n, col, diag, aDiag, res);
             col.erase(c);aDiag.erase(ad);diag.erase(d);
         }
     }
};