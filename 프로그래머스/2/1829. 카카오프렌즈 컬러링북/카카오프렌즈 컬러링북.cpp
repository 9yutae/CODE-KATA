#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> isVisited;
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int i, int j, const vector<vector<int>>& picture) {
    queue<pair<int, int>> q;
    q.push({i, j});
    isVisited[i][j] = true;
    int flag = picture[i][j];

    int current_size = 1;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int dir = 0 ; dir < 4 ; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[ny][nx]) {
                if (picture[ny][nx] == flag) {
                    q.push({ny, nx});
                    isVisited[ny][nx] = true;
                    current_size++;
                }
            }
        }
    }
    
    return current_size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m; N = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    isVisited.assign(m, vector<bool>(n, false));
    
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (picture[i][j] && !isVisited[i][j]) {
                int current_size_of_area = BFS(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, current_size_of_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}