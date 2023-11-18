/*
sama kaya https://leetcode.com/problems/number-of-islands/ beadanya kita track luas setiap island berapa dan return luas max
*/
class Solution {
    set<pair<int, int>> visited;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea= 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j <grid[0].size(); j++){
                if (grid[i][j] == 1 || visited.find(make_pair(i,j)) == visited.end() ) {
                    // jikka grid ke i,j == '1' dan belum divisit
                    int islandArea = 0;
                    cout << " dfs: " << i << " j: " << j <<endl;
                     dfs(grid, i, j ,islandArea);
                     maxArea = max(maxArea, islandArea);
                }
            }
        }
        return maxArea;
    }

private:
    void dfs(vector<vector<int>>& graph, int i , int j , int& area) {
        int m = graph.size(), n = graph[0].size();
        if (i < 0 || j < 0 || i ==m || j == n || graph[i][j] == 0 || 
            visited.find(make_pair(i,j)) != visited.end()) {
                // cek apakah cell diluar graph, isi cell == '0', cell sudah divisit
                return;
        }

        area++;
        visited.insert(make_pair(i,j));
        cout << i << " j: " << j << " area: " << area << endl;
        dfs(graph, i-1, j, area); // dfs ke kiri  cell
        dfs(graph, i+1, j, area); // dfs ke kanan  cell
        dfs(graph, i, j-1, area); // dfs ke atas  cell
        dfs(graph, i, j + 1,area);  // dfs ke bawah  cell 

    }
};