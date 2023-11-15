/*


Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

intuisi:
- iterate setiap interval di dalam interval
-  jika newInterval < interval ke -i , bisa insert newInterval & semua interval setelah  i ke res.
- jka newInteval > interfval ke-i , hanya bisa insert interval ke-i.
- jika neWInrterval overlapping dg interval ke-i, merge interval ke-i dan newInterval jd newInterval baru. & tidak bisa langsung insert newINterval karena bisa aja di interval berikutnya masih overlapping & kita harus merge banyak intervals yang saling overlapping


intervals 1-2 3-5. 6-7 8-10 12-16
 newInterval    4 -    8

1. i = 0 -> 4 > 2 (tidak overlaping)
res= [1-2]
newInterval = [4-8]

2. i =1 -> overlapping
newInterval = [3-8]

3. i =2 -> overlapping
newInterval = [3-8]

4. i =3 -> overlapping 
newInterval = [3-10]

5. i =4 -> tidak overlaping ( 10 < 12)
res = [1-2, 3-10, 12,16]

time complexity: O(n)

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i=0; i < intervals.size(); i++){
            if (newInterval[1] < intervals[i][0]){
            // newInterval < iterval ke-i
                res.push_back(newInterval);
                for(int j=i ; j < intervals.size() ; j++) {
                    res.push_back(intervals[j]);
                }
                return res;
            }else if (newInterval[0] > intervals[i][1]) {
                // jika newInterval > interval ke-i
                res.push_back(intervals[i]);

            }else {
                int minStart = min(intervals[i][0], newInterval[0]);
                int maxEnd = max(intervals[i][1], newInterval[1]);
                vector<int> newV{minStart, maxEnd};
                newInterval = newV;
                std::cout << i << " " << minStart << " "  <<   newInterval[0] << newInterval[1] << endl;
            }

        }

        res.push_back(newInterval);

        return res;
    }
};