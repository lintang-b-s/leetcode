/*
https://leetcode.com/problems/3sum/description/

mirip dg two sum II: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

[-1,0,1,2,-1,-4]
sorting:
[-4,-1,-1,0,1,2]
  i
ide: iterate array dg i mulai dari 0, tiap kali iterate iterate lagi dg 2 pointer untuk mencari jumlah ketiga elemen =0 (caranya mirip dg two sum II).
untuk handle duplicate , setelahh sum == 0 ,geser 2 pointer, dan cek apakah 
elemen 2 pointer sama dg elemen sebelum pointer digeser , jika ya  maka geser lagi 2 pointernya. pas sum != 0 geser pointer && handle duplicate .untuk handle duplicate pointer ke 0, pas setelah iterate 2pointer, cek apakah elemen pointer ke 0 sama dg elemen pointer 0 sebelum di geser.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size();){
            int left = i +1, right = nums.size() -1;
            
            while (left < right){
                int sum = nums[i]+nums[left]+nums[right]; // jumlah ketiga elemn
                if (sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while ((left < right) && nums[left] == nums[left-1]) {left++;}
                    while ((left<right) && nums[right] == nums[right+1]) {right--;}
                }else if (sum >0){
                    right --;
                    while ((left < right) && nums[right] == nums[right+1]){right--;}
                }else {
                    left ++ ;
                    while ((left <right) && nums[left] == nums[left-1]) {left++;}
                }
            }
            i++;
            while ((i<nums.size() && nums[i] ==nums[i-1])){
                i++;
            }

        }
        return res;

    }
};