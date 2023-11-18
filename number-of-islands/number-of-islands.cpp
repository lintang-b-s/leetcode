/*
intuisi:
- setiap island bisa dicek pakai dfs
1. buat set<pair<int, int>> visited, buat cek apakah di cell i,j udah divisit
2. iterate array dari kiri kenan dari atas ke bawah, jika di cell i,j nilainya '1' dan belum divisit -> increment islands &   dfs dari cell itu utk untuk menandai island
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
*/

class Solution {
    set<pair<int, int>> visited;
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0; i < grid.size(); i++){
            for (int j =0 ; j < grid[0].size(); j++){
                  
                if (  grid[i][j] == '1' &&  visited.find(make_pair(i, j )) == visited.end() ){
                  cout << "i: "  << i << " J : " << j  << endl;
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }

private:
    void dfs( vector<vector<char>>& graph, int i , int j){
      int m = graph.size(), n = graph[0].size();
      
      if (i < 0 || j < 0 || i ==m || j == n || graph[i][j] == '0' ||
         visited.find(make_pair(i, j )) != visited.end() ){
          return ;
      }
      visited.insert(make_pair(i, j));
      dfs(graph, i-1, j);
      dfs(graph, i+1, j);
      dfs(graph, i, j-1);
      dfs(graph,i ,j+1);
    
    }
};