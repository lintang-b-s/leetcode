/*
https://leetcode.com/problems/3sum-closest/
mirip dg 3sum https://leetcode.com/problems/3sum/ 
mirip dg two sum II https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

ide: sorting array, lalu asumsikan jawabannya (ans) sama dg jumlahan tiga elemen pertama di array. iterate array dg pointer i , lalu cari triplet dg mengiterate i+1 sampai arraySize-2 (mirip dg two SUM II), jumlahan triplet disimpan di varb sum. 
jika selisih antara target dg sum dg target < slesiih antara ans dg target berarti sum triplet saat ini lebih dekat dg targetm maka update ans =sum.


1.  sort array ascending. lalu, buat variable ans = jumlahan 3 triplet pertama.
2..iterate array dg index i & i mulai dari 0. 
3. jika selisih antara target dg sum dg target < slesiih antara ans dg target berarti sum triplet saat ini lebih dekat dg targetm maka update ans =sum.
4.. iterate array index i+1 hgg terkahir pakai 2 pointer , lalu cari triplet yang jumlahan
nya sama dg target (mirip dg two sum II).


*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());// sort array ascending
        int n = nums.size();
        
        int ans = nums[0] + nums[1] + nums[2]; // asumsi jawaban
        for (int i =0; i< n -2; i++){
            int left= i+1;
            int right = n-1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int ansDiff = abs(ans - target), sumDiff = abs(sum - target);
                if (sumDiff < ansDiff ){
//                     sum lebih dekat dg target
                    ans = sum;
                }
                if (sum == target){
                    return sum;
                }else if (sum >target){
                    right --;
                }else {
                    left++;
                }
            }
        }
        
        return ans;
        
    }
};