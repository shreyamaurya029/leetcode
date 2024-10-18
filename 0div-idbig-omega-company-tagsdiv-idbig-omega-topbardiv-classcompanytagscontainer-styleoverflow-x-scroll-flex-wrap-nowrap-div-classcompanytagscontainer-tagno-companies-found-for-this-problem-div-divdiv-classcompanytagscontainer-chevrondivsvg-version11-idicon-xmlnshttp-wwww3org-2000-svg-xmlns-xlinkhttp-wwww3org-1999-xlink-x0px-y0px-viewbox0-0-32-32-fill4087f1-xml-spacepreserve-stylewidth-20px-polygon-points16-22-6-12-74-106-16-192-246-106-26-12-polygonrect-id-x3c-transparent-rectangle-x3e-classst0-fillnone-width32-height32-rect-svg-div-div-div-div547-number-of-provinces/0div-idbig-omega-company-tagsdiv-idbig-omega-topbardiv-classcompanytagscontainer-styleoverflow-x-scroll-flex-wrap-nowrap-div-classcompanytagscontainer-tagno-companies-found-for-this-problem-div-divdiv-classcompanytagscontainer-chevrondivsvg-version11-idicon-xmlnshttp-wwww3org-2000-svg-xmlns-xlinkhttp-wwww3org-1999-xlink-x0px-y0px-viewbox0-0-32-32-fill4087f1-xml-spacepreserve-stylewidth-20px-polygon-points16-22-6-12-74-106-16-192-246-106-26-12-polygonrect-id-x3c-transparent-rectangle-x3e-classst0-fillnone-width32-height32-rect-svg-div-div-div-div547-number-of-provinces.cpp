class Solution {
    //dfs jismein stack lenge

    void dfs(int index,vector<int>&vis,vector<vector<int>>&adjList){
        vis[index] = {1};
        for(auto it: adjList[index]){ //we here traverse in the adjancency list of that index
            if(vis[it] == 0){
                dfs(it,vis,adjList);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& m) {
        int n = m.size();
        vector<vector<int>>adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(m[i][j] == 1 and i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,0);
        int cnt = 0;//to count the number of components

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i,vis,adjList);
            }
        }

        return cnt;



        
    }
};