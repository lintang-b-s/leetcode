/*
cari pivot index, pivot adalah nilai paling minimum di array
setelah pivot ditemukan maka pecah array mjd A1[0,pivot-1] dan A2[pivot, n-1]
lalu lakukan binary search di A1 untuk mencari target jika tidak ada maka binary search di A2

untuk cari pivot , bandingkan mid dengan nums[-1] jika mid lebih besar maka pivot ada di kanan, set left ke mid+1, karena pasti di sebelah kanan adalah array menaik yang rerata elemennya lebih kecil dibandingkan di kirinnya mid


*/

class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left= 0, right=n-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[n-1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        int pivot = left;
        int answer = binarySearch(nums, 0, pivot-1, target);
        if (answer != -1){
            return answer;
        }
        return binarySearch(nums, pivot, n-1, target);
    }

    public int binarySearch(int[] nums, int left, int right, int target){
        while (left <= right){
            int mid = left + (right-left)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
          
        }
          return -1;
    }

}