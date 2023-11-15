/*

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
vector<res>
1. i = 0
[1,3] & [2,6] overlapping -> [1,6]
[1,6] < [8.10] insert [1,6],[8,10], [15,18] ke res


----
Input: intervals = [[1,3],[2,6],[6,10],[15,18]]
1. i = 0
[1,3] & [2,6] overlapping -> [1,6]
[1,6] overlapping [6.10] -> [1,10]
[1,10] < [15,18] -> insert [1,10],[15,18] ke res

----
Input: intervals = [[1,3],[2,6],[6,10],[10,18]]
1. i = 0
[1,3] & [2,6] overlapping -> [1,6]
[1,6] overlapping [6.10] -> [1,10]
[1,10] overlapping [10,18] -> [10,18]
insert [10,18] ke res


----
Input: intervals = [[1,3],[4,6],[7,10],[11,18]]
[1,3] < [4,6] -> insert [1,3] to res
[4,6] < [7,10] -> insert [7,10] to res
[7,10] < [11,18] -> insert [7,10] to res
insert [11,18] to res


*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> overlappingIntv;
        vector<vector<int>> res;
        for (int i=0 ; i < intervals.size() ; i++ ) {
           if (res.empty() || res.back()[1] < intervals[i][0]){
               // jika res kosong atau interval terakhir dari res <. interval ke-i
                cout << "intervals[i]: "  << intervals[i][0] <<   intervals[i][1] << endl;
                    res.push_back(intervals[i]); 
            }else {
               res.back()[1] = max(res.back()[1], intervals[i][1]);
               cout << "res: " << res.back()[0] <<  res.back()[1] << endl;
           }
            
        }
        return res;
    }
};