#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isValid(int x, int y, int maxX, int maxY) {
    return x >= 0 && x < maxX && y >= 0 && y < maxY;
}

int bfs(const int& n, const int& m, const vector<vector<int>>& maps, vector<vector<bool>>& visited) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int counts = q.front().second;
        q.pop();
        
        if (x == m - 1 && y == n - 1) {
            return counts;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (isValid(nx, ny, m, n) && maps[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({{nx, ny}, counts + 1});
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return bfs(n, m, maps, visited);
}