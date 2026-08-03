class Solution {
public:
    int horizontal[4] = {0, 1, 0, -1};
    int vertical[4] = {-1, 0, 1, 0};

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visitedEle(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visitedEle[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, visitedEle, grid);
                }
            }
        }
        return count;
    }

    void dfs(int row, int col, vector<vector<bool>>& visitedEle, const vector<vector<char>>& grid) {
        visitedEle[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int newRow = row + vertical[i];
            int newCol = col + horizontal[i];

            if((newRow >= 0 && newRow < grid.size()) && 
                (newCol >= 0 && newCol < grid[0].size()) &&
                grid[newRow][newCol] == '1' &&
                !visitedEle[newRow][newCol]
            ) {
                dfs(newRow, newCol, visitedEle, grid);
            }
        }
    }
};
