/*
 While we are iterating and inserting elements into the hash table, we also look back to check if current element's complement already exists in the hash table. If it exists, we have found a solution and return the indices immediately.


*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i = 0;
        for(int num: nums){
            int complement = target -num;
            if (m.find(complement) != m.end()){
                return {m[complement], i};
            }
            m[num] =  i;
            i++;
        }
        throw;
    }
};