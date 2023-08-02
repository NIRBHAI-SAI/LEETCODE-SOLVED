class Solution {
    private:
    void bfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>> &vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int x_[] = {0,1,-1,0};
            int y_[] = {-1,0,0,1};
            
            for(int i = 0;i<=3;i++){
                   int nr = r + x_[i];
                    int nc = c + y_[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == '1'){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }            
                }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    c++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return c;   
    }
};