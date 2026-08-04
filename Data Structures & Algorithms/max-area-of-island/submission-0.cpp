class Solution {
public:
    int horizontal[4] = {0, 1, 0, -1};
    int vertical[4] = {-1, 0, 1, 0};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        int currMax = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j]) {
                    dfs(grid, visited, i, j, currMax);
                    maxArea = max(maxArea, currMax);
                    currMax = 0;
                }
            }
        }

        return maxArea;
    }

    void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited,
             int row, int col, int& currMax) 
    {
        visited[row][col] = true;
        currMax += 1;

        for(int i = 0; i < 4; i++) {
            int newRow = row + vertical[i];
            int newCol = col + horizontal[i];

            if((newRow >= 0 && newRow < grid.size()) && 
               (newCol >= 0 && newCol < grid[0].size()) && 
               (!visited[newRow][newCol]) && 
               (grid[newRow][newCol])
               ) 
            {
                dfs(grid, visited, newRow, newCol, currMax);
            }
        }
    }
};










