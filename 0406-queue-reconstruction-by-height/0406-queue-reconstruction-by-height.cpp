/*
- sort people dg height tertinggi di depan , lalu setelahnya insert people dg height lebih rendah atau sama dg height tertinggi.
-  jika ada 2 people dg tinggi sama, maka insert people dg  ki terendah ke depan disusul people dg ki lebih tinggi.
 [hi,ki]
 People = [[7,0], [4,4], [7,2], [5,0], [6,1], [5,4], [8,0]]
 Sorted People: [[8,0], [7,0], [7,2], [6,1], [5,0], [5,4], [4,4]]]
 ans = []
 - insert sorted people ke ans dg index sesuai dg ki.

  man = [8,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[8,0]"]
 man = [7,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[7,0]", [8,0]]
 man = [7,'2'] -> ans.insert(ans.begin()+'2', man) -> ans  = [[7,0], [8,0], "[7,2]"]
 man = [6,'1'] -> ans.insert(ans.begin()+'1', man) -> ans  = [[7,0], "[6,1]", [8,0], [7,2]]
 man = [5,'0'] -> ans.insert(ans.begin()+'0', man) -> ans  = ["[5,0]", [7,0], [6,1], [8,0], [7,2]]
 man = [5,'4'] -> ans.insert(ans.begin()+'4', man) -> ans  = [[5,0], [7,0], [6,1], [8,0], "[5,4]", [7,2]]
 man = [4,'4'] -> ans.insert(ans.begin()+'4', man) -> ans  = [[5,0], [7,0], [6,1], [8,0], "[4,4]", [5,4], [7,2]]
*/

class Solution {
public:
    static bool comp(vector<int> & a , vector<int>& b){
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (auto& m: people) {
            res.insert(res.begin() + m[1], m);
        }
        return res;
    }
};