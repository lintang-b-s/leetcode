/*
- pakai bfs, tiap menit =  visit node di next level


Input: grid = [[2,1,1]
                ,[0,1,1]
                ,[1,0,1]]


queue=[{0,0}]
- minute 1  queue=[{0,1}]
[[2,2,1]
,[0,1,1]
,[1,0,1]]
-munte 2 = queue[{0,2}, {1,1}]
[[2,2,2]
,[0,2,1]
,[1,0,1]]
- minute 2 queue=[{1,1}, {1,2}]
[[2,2,2]
,[0,2,2]
,[1,0,1]]

- minute 3 queue=[{}]
[[2,2,2]
,[0,2,2]
,[1,0,2]]



*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size(), freshOrange=0;
        // vector<vector<int>> visited= grid;

        queue<pair<int, int >> q;

        for( int i=0; i<m; i++){
            for (int j=0; j< n; j++){
                if (grid[i][j] ==2) {
                    q.push({i,j});
                }
                if (grid[i][j]==1){
                    freshOrange++;
                }
            }
        }

        if (freshOrange==0){
            return 0;
        }
        if (q.empty()){
            return -1;
        }

        int minutes= -1;

        vector<pair<int,int>> dirs= {{1,0}, {-1,0}, {0,-1}, {0,1}};
        while (!q.empty()){
            int size = q.size();
            while (size--){
                // cek orange di 4 direction dari  cell 
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy]: dirs){
                    int i = x + dx;
                    int j = y+dy;
                    if (i >=0 && j >= 0 && 
                    i < m && j < n && grid[i][j] == 1){
                        freshOrange--;
                        grid[i][j]=2;
                        q.push({i,j});
                    }
                }
            }
            minutes ++;

        }

        return (freshOrange ==0 )? minutes: -1;
    }
};