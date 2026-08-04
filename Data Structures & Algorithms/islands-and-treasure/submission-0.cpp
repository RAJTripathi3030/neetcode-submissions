class Solution {
public:
    int ROWS, COLS;
    int horizontal[4] = {0, 1, 0, -1};
    int vertical[4] = {-1, 0, 1, 0};

    int INF = INT_MAX;

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        visited[r][c] = true;
        int steps = 0;

        while(!q.empty()) {
            int Qsize = q.size();
            for(int i = 0; i < Qsize; i++) {
                auto [row, col] = q.front();
                q.pop();
                if(grid[row][col] == 0) return steps;

                for(int j = 0; j < 4; j++) {
                    int newRow = row + vertical[j];
                    int newCol = col + horizontal[j];

                    if(newRow >= 0 && newRow < ROWS && 
                       newCol >= 0 && newCol < COLS && 
                       !visited[newRow][newCol] && 
                       grid[newRow][newCol] != -1) 
                    {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }

        return INF;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == INF) {
                    grid[i][j] = bfs(grid, i, j);
                }
            }
        }
    }
};
