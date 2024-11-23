class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        
        for(auto& r : matrix){
            string s(r.size(), 'T');
            for(int i=1; i<r.size(); i++){
                if(r[i] != r[0]) s[i] = 'F';
            }
            mp[s]++;
        }
        
        int ans = 0;
        for(auto p: mp){
            ans = max(ans, p.second);
        }
        return ans;
    }
};
/*
Iteration 1 (Row = {1, 1, 0, 1}):
Step 1: Create the string s
Step 2: Compare each element of the row with the first element (row[0] = 1):
For i = 1: row[1] = 1, which equals row[0]. So, s remains "TTTT".
For i = 2: row[2] = 0, which does not equal row[0]. So, s[2] = 'F'. Now, s = "TTFT".
For i = 3: row[3] = 1, which equals row[0]. So, s remains "TTFT".
*/

//basically pattern banana hai, jitne pattern same honge wahi answer hoga
