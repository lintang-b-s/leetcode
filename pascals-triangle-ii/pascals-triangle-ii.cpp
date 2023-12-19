
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        helper(0, rowIndex, pascal);

        vector<int> idxRow;
        cout << "size: "<< pascal[rowIndex].size();
        for (int i=0; i < pascal[rowIndex].size(); i++){
            idxRow.push_back(pascal[rowIndex][i]);
        }
        return idxRow;
    }
    
    void helper(int row, int totRows, vector<vector<int>>& pascal){
        if (row == totRows+1) return;

        vector<int> currRow(row+1, 1);

        //row 4 (row=3), f(i,j) = f(i-1,j-1) + f(i-1,j) . j = 2,3
        for (int col=1; col<row; col++){
            currRow[col] = pascal[row-1][col-1] + pascal[row-1][col];
        }
        pascal.push_back(currRow);

        helper(row+1, totRows, pascal);
    }
    
};

/*

f(i,j) = f(i-1,j-1) + f(i-1,j);
basecase:
j==1 -> f(i,j) =1
j=i -> f(i,j) =1

*/

/*
Time Complexity: 

*/