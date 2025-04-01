#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isValid(int x, int y, int maxX, int maxY) {
    return x >= 0 && x < maxX && y >= 0 && y < maxY;
}

int bfs(int x, int y, const vector<string>& board) {
    int n = board.size();
    int m = board[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({{x, y}, 0});
    visited[y][x] = true;
    
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        if(board[y][x] == 'G') {
            return depth;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x;
            int ny = y;
            
            while (true) {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];
                
                if (!isValid(tx, ty, m, n) || board[ty][tx] == 'D')
                    break;
                
                nx = tx;
                ny = ty;
            }
            
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({{nx, ny}, depth + 1});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int x, y;
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == 'R') {
                x = j;
                y = i;
                break;
            }
        }
    }

    return bfs(x, y, board);
}