
/*

dfs dari cell yg di borders ,  bisa flow jika height next cell  <  height current cell.


cell yg bisa flow ke kedua oceans , 


Input: heights = [[1,2,2,3,5]
                    ,[3,2,3,4,4]
                    ,[2,4,5,3,1]
                    ,[6,7,1,4,5]
                    ,[5,1,1,2,4]]
border top: 
- [0,4] : atlantic  & pacific
- [0,2] - [1,2]- [2,2]: pacific
border left:
- [3,0] : pacific
- [3,0]- [4,0] : atlantic
- [3,0]- [3,1]: pacific 
border right: 
- [1,4]- [1,3]- [0,3]: pacific 
- [1,4]: atlantic
- [ 2,4] - [2,3] - [2,2]: atlanctic
border bottom: atlantic
- [4,0]- [3,0]- [3,1]: atlantic

*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         vector<vector<int>>ans;
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);

        }
        
        for (int j = 0; j < n; j++) {
            
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m-1, j);
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (pacific[i][j] && atlantic[i][j]) 
                    ans.push_back({i,j});           
            }
        }
        return ans;
    }

      void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;
       
        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
     
        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
   
        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
       
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);

    }
};