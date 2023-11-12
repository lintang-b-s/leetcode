/*
resource priority queue: https://www.geeksforgeeks.org/priority_queuepush-priority_queuepop-c-stl/
resource remove duplicate: https://www.geeksforgeeks.org/remove-duplicates-sorted-array/


intuisi: 
- bisa pakai max-heap/priorityQueue, 
 - buat priority queue max-heap dari array nums
 - pop k kali untuk mendapatkan k th largest
 - 
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 0 ; i < k ; i++) {
            res = maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};