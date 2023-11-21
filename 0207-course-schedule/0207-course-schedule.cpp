/*
- resource topological sort dfs: https://www.geeksforgeeks.org/topological-sorting/
-  topological sort kahn :https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

- intuisi: utk tau semua course dapaat diselesaikan ,kita harus cek jika 
graph tidak ada cycle.
- pakai topological sort utk cek ada cycle atau tidak. res.size() != n jika ada cycle

- adj[i] = menyimpan elemen yg adjacent dg elemen ke-i



- indegree: array yg menyimpna jumlah dependency yang harus diselesaikan .
misal  a-> b 
maka indegree[b] = 1. (a harus diselesaikan sebelum b)

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> res;


        for (auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        
        }

        queue<int> q;
        for (int i =0 ; i< numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int top = q.front();
            q.pop();
            res.push_back(top);

            for (auto x: adj[top]){
                indegree[x]--;
                if (indegree[x] == 0){
                    q.push(x);
                }
            }

        }

        return res.size() == numCourses;
    }
};