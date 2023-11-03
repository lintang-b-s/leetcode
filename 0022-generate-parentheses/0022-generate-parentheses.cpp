/*
ilusrasi: https://miro.medium.com/v2/resize:fit:1400/1*a932yah98FuImJH_-JCsvA.png
output = variabel res
base case: jika length string == n atau jumlah parentheses == n , add string ke res dan backtrack ke kondisi sebelumnya.
- unutk menambahkna (: jumlah opening bracket < n
- untuk menambahkan ): jumlah closing bracket < opening bracket.


*/


class Solution {
    vector<string> res ;
private: 
    void solve (int openBracket, int closeBracket, int n, string curr ) {
        if (curr.length() == n*2) {
            res.push_back(curr);
            return;
        }
        if (openBracket < n ) {
            solve(openBracket+1, closeBracket, n, curr + "(");
        }
        if (closeBracket < openBracket) {
            solve(openBracket, closeBracket+1, n, curr + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
            solve(0,0,n,"");
            return res;
    }
};