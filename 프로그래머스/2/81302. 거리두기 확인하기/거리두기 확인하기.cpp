#include <string>
#include <vector>

using namespace std;

bool checkDistance(vector<string> place, int y, int x) {
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    vector<vector<bool>> isVisited(5, vector<bool>(5, false));
    isVisited[y][x] = true;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !isVisited[ny][nx]) {
            if(place[ny][nx] == 'P') return false;
            else if(place[ny][nx] == 'X') continue;
            for(int j=0; j<4; j++) {
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                if(nnx >= 0 && nnx < 5 && nny >= 0 && nny < 5 && !isVisited[nny][nnx]) {
                    if(place[nny][nnx] == 'P') return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(const auto& place : places) {
        bool flag = true;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(place[i][j] == 'P') {
                    flag = checkDistance(place, i, j);
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        flag ? answer.push_back(1) : answer.push_back(0);
    }
    return answer;
}