#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& grid, int m, int n)
{
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
        return;

    grid[r][c] = 0; // mark as visited

    dfs(r-1, c, grid, m, n); // up
    dfs(r+1, c, grid, m, n); // down
    dfs(r, c-1, grid, m, n); // left
    dfs(r, c+1, grid, m, n); // right
}

int main() {
    vector<vector<int>> grid = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    int m = grid.size();
    int n = grid[0].size();

    int islands = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                islands++;
                dfs(i, j, grid, m, n);
            }
        }
    }

    cout << islands << endl;
}
