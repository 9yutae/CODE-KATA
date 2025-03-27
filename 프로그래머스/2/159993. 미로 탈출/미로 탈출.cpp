#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> isVisited;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(vector<string> maps, int x, int y, char target) {
    queue<pair<int, int>> q;
    q.push({x, y});
    isVisited[y][x] = true;
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (maps[y][x] == target) {
            return grid[y][x];
        }
    
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < maps[0].size() && ny >= 0 && ny < maps.size() && !isVisited[ny][nx]) {
                if(maps[ny][nx] != 'X') {
                    grid[ny][nx] = grid[y][x] + 1;
                    isVisited[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {    
    int startX, startY, leverX, leverY;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                startY = i, startX = j;
            }
            if (maps[i][j] == 'L') {
                leverY = i, leverX = j;
            }
        }
    }
    
    grid.resize(maps.size(), vector<int>(maps[0].size(), 0));
    isVisited.resize(maps.size(), vector<bool>(maps[0].size(), false));
    int toLever = bfs(maps, startX, startY, 'L');
    if (toLever == -1) return -1;

    grid.clear();
    isVisited.clear();
    grid.resize(maps.size(), vector<int>(maps[0].size(), 0));
    isVisited.resize(maps.size(), vector<bool>(maps[0].size(), false));
    int toExit = bfs(maps, leverX, leverY, 'E');
    if (toExit == -1) return -1;

    return toLever + toExit;
}