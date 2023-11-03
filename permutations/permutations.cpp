/*
ILUSTRASI: https://media.geeksforgeeks.org/wp-content/uploads/20230607112555/file.png
A b c
L     R
I
A B C 
    L  R
    I
A B C 
       LR  RETURN
       I
A B C
    L   R
    I
A  B  C
     L  R  
         I
A  C  B
    L   R
          I
A C  B
        LR  RETURN 
A B C
L     R
    I
B  A C
L   I  R
B A C
   L R
   I
B A  C
       L R RETURN 
B A C
    L  R
        I
B  C  A
       LR  RETURN 
        I
A  B  C
L      R
        I
C  B  A
L       R
         I
C  B A 
    L  R
    I
C B A
      LR RETURN
      I
C  B A
     L R
        I
C  A B
        L R RETURN
         I


*/
class Solution {
    vector<vector<int>> res;
private:
    void solve(vector<int>& nums, int l, int r) {
        if (l == r) {
            res.push_back(nums);
            return;
        }
        
        for (int i=l; i <= r; i++ ) {
            swap(nums[l], nums[i]);
            solve(nums, l+1, r);
            swap(nums[l], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(nums, 0, n-1 );
        return res;
    }
};