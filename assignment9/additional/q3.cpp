#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;

/*
PSEUDO-CODE:
1. Read grid dimensions M, N and the grid costs.
2. Create a `dist` 2D array initialized to Infinity, except `dist[0][0] = grid[0][0]`.
3. Create a Min-Priority Queue `pq` storing tuples `{cost, row, col}`.
4. Push start node `{grid[0][0], 0, 0}` to `pq`.
5. While `pq` is not empty:
    a. Pop the element with smallest cost: `{d, r, c}`.
    b. If `d > dist[r][c]`, continue (skip outdated path).
    c. If `(r, c)` is the bottom-right cell `(M-1, N-1)`, return `d`.
    d. For each valid neighbor `(nr, nc)` (up, down, left, right):
        i. Calculate `new_cost = d + grid[nr][nc]`.
        ii. If `new_cost < dist[nr][nc]` (found a cheaper path):
            - Update `dist[nr][nc] = new_cost`.
            - Push `{new_cost, nr, nc}` to `pq`.
*/

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dist(m, vector<int>(n, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();

        if (d > dist[r][c]) continue;

        if (r == m - 1 && c == n - 1) {
            cout << d << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (dist[r][c] + grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + grid[nr][nc];
                    pq.push({dist[nr][nc], nr, nc});
                }
            }
        }
    }

    return 0;
}