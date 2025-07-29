#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> containers;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

bool checkContainer(const int& i, const int& j) {
    return (containers[i][j - 1] == -1 || containers[i][j + 1] == -1 ||
        containers[i - 1][j] == -1 || containers[i + 1][j] == -1);
}

void forklift(const string& request) {
    int row = containers.size();
    int col = containers[0].size();
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> coordinate;
    queue<pair<int, int>> q;
    
    for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col ; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                q.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (int dir = 0 ; dir < 4 ; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= col || ny >= row || visited[ny][nx]) continue;
            if (containers[ny][nx] == -1) {
                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
            else if (containers[ny][nx] == request[0] - 'A') {
                visited[ny][nx] = true;
                coordinate.emplace_back(ny, nx);
            }
        }
    }
    
    for (const auto& [i, j] : coordinate) {
        containers[i][j] = -1;
    }
}

void crane(const string& request) {
    for (int i = 1 ; i < containers.size() ; i++) {
        for (int j = 1 ; j < containers[0].size() ; j++) {
            if (containers[i][j] == request[0] - 'A') {
                containers[i][j] = -1;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    containers.resize(storage.size() + 2, vector<int>(storage[0].size() + 2, -1));
    for (int i = 0 ; i < storage.size() ; i++) {
        for (int j = 0 ; j < storage[0].size() ; j++) {
            containers[i+1][j+1] = storage[i][j] - 'A';
        }
    }    
    
    for (const auto& request : requests) {
        request.size() == 1 ? forklift(request) : crane(request);
    }
    
    int answer = 0;
    for (const auto& vec : containers) {
        for (const auto& w : vec) {
            if (w >= 0) answer++;
        }
    }
    
    return answer;
}