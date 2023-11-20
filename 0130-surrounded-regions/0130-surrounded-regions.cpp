/*

Input: board = [["X","X","X","X"]
                ,["X","O","O","X"]
                ,["X","X","O","X"]
                ,["X","O","X","X"]]

dfs: 
- [1,1] - [1,2] - [2,2]
-> board = [["X","X","X","X"]
            ,["X","X","X","X"]
            ,["X","X","X","X"]
            ,["X","O","X","X"]]

intuisi: dfs ke setiap cell di setiap border, jika cell == '0' ubah ke '1' , cek neighbor dari cell jg jika cell == '0' ubah ke '1'



board =
[["O","O","O"]
,["O","O","O"]
,["O","O","O"]]

board =
[["X","O","X"]
,["X","O","X"]
,["X","O","X"]]

[["O","X","X","O","X"]
,["X","O","O","X","O"]
,["X","O","X","O","X"]
,["O","X","O","O","O"]
,["X","X","O","X","O"]]

[["O","X","X","O","X"]
,["X","O","O","X","O"]
,["X","O","X","O","X"]
,["O","X","O","O","O"]
,["X","X","O","X","O"]]

[["O","X","X","O","X"]
,["X","X","X","X","O"]
,["X","X","X","X","X"]
,["O","X","X","O","O"]
,["X","X","O","X","O"]]

- It is adjacent to an 'O' that should not be flipped.  ???

*/
class Solution {
    set<pair<int, int>> visited;

public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int m=board.size();
        if(!m)
        	return;
        int n=board[0].size();

		for(i=0;i<m;i++){
            // dfs di  setiap cell di border paling kiri
			dfs(board,i,0,m,n);
			if(n>1)
                // dfs di  setiap cell di  border paling kanan
				dfs(board,i,n-1,m,n);
		}
		for(j=1;j+1<n;j++){
            // (0,0 ) dan (m-1,n-1 )tidak dicek karena udah dicek di loop sebelunya
			dfs(board,0,j,m,n);
            // dfs di  setiap cell di  border paling atas
			if(m>1)
             // dfs di  setiap cell di  border paling bawah
				dfs(board,m-1,j,m,n);
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }
	void dfs(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			vec[i][j]='1';
			if(i>1)
				dfs(vec,i-1,j,row,col);
			if(j>1)
				dfs(vec,i,j-1,row,col);
			if(i+1<row)
				dfs(vec,i+1,j,row,col);
			if(j+1<col)
				dfs(vec,i,j+1,row,col);
		}
	}

};
