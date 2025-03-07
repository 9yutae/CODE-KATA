#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVisited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int xlen, ylen;

void dfs(vector<vector<int>>& map, int& days, int y, int x) {
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < xlen && ny >=0 && ny < ylen && !isVisited[ny][nx] && map[ny][nx]) {
            days += map[ny][nx];
            isVisited[ny][nx] = true;
            dfs(map, days, ny, nx);
        }
    }
}

vector<int> solution(vector<string> maps) {
    xlen = maps[0].size();
    ylen = maps.size();
    
    vector<vector<int>> map(ylen);
    for(int i=0;i<ylen;i++) {
        for(const auto& w:maps[i]) {
            if(w == 'X') map[i].push_back(0);
            else map[i].push_back(w - '0');
        }
    }
    
    vector<int> answer;
    for(int i=0;i<ylen;i++) {
        for(int j=0;j<xlen;j++) {
            if(map[i][j] && !isVisited[i][j]) {
                int days = map[i][j];
                isVisited[i][j] = true;
                dfs(map, days, i, j);
                answer.push_back(days);
            }
            else isVisited[i][j] = true;
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}