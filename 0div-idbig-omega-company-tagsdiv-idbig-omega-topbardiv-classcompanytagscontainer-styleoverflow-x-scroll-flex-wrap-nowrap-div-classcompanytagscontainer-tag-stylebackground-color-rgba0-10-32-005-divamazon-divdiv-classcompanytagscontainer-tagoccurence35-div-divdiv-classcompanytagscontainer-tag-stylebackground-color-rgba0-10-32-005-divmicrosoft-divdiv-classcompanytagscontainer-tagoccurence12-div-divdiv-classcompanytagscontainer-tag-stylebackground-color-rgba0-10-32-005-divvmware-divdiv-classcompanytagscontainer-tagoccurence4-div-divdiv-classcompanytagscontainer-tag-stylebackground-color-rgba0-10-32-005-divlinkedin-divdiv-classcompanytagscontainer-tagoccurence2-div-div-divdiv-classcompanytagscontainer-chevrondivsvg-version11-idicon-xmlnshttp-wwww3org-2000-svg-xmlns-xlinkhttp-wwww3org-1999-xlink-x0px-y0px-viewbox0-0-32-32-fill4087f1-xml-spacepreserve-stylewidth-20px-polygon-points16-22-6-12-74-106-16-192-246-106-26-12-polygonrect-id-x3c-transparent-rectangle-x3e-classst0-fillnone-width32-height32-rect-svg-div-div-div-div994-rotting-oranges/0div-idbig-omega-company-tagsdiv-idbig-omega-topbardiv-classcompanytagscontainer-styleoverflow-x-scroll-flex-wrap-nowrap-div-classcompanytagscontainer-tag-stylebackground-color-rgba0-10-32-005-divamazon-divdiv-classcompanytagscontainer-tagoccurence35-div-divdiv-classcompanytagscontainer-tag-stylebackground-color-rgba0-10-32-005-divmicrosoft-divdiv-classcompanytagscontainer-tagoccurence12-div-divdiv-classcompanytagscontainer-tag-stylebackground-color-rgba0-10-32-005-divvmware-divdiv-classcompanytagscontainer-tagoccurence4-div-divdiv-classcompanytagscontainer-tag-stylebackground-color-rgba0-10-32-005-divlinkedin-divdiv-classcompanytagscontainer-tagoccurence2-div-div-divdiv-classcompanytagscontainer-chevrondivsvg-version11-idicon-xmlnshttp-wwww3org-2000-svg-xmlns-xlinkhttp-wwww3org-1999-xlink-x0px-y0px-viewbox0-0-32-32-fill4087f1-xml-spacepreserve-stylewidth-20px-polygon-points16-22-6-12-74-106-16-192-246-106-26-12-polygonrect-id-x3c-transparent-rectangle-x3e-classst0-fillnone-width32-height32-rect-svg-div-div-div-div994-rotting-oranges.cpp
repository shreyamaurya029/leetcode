class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},t}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); 
                    vis[i][j] = 2; //mark them as visited 
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int time=0; 
        while(!q.empty()){
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();

            //pushing into the queue
            //applying bfs
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!= 2 && grid[i][j]!= 0){
                    return -1;
                }
            }
        }
        return time;

        
    }
};