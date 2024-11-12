class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int p = m.size();
        int q = m[0].size();
        
        int row = 0, col = q-1;
        while(row<p && col>=0){
            if(m[row][col] == target){
                return 1;
            }
            else if(m[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return 0;
    }
};