class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                sum += abs(matrix[i][j]);


                if (matrix[i][j] < 0) {
                    negativeCount++;
                }


                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            }
        }

        // Adjust the sum if there are an odd number of negative elements
        if (negativeCount % 2 != 0) {
            sum -= 2 * minAbsVal;
        }

        return sum;
        
    }
};