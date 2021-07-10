class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int column, int maxR, int maxC) {
        if(row < 0 || row >= maxR || column < 0 || column >=maxC || grid[row][column] != '1') {
            return;
        }
        
        grid[row][column] = '2';
        int x[] = {0, -1, 0, 1};
        int y[] = {-1, 0, 1, 0};
        for(int k=0; k<4; k++) {
            dfs(grid, row+x[k], column+y[k], maxR, maxC);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, rows, columns);
                    count++;
                }
            }
        }
        return count;
    }
};