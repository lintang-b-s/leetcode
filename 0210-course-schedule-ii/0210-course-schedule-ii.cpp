/*
- resource topological sort dfs: https://www.geeksforgeeks.org/topological-sorting/
-  topological sort kahn :https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

sama kaya: https://leetcode.com/problems/course-schedule/

- pakai topological sort.

Input: numCourses = 2, prerequisites = [[1,0]]

0 -> 1
0 harus diselesaikan sebelum 1


Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]

ilustrasi: https://docs.google.com/document/d/1LMeWgGEMK4YdfMUIKWqMIRMUK7XfC67xO4eBHkr3t5U/edit?usp=sharing

adj= [[1,2], [3], [3], []]
indegree= [ 0, 1, 1, 2]


q=[3]

 - q= [ ]
 adj[3] = 

*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> res;

        for (auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;
        for (int i= 0; i <numCourses; i++){
            if (indegree[i] == 0 ){
                q.push(i);
            }
        }
        

        while (!q.empty()){
            int top = q.front();
            q.pop();
            res.push_back(top);

            for (auto x :adj[top]){
                indegree[x]--;
                if (indegree[x] == 0){
                    q.push(x);
                }
            }
             
        }

        vector<int> nul;
        return (res.size() ==  numCourses ) ? res : nul;

    }
};