#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> map;
bool visited[501][501][4];
int N, M;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int GetLengthOfCycle(int y, int x, int dir) {
    int Len = 0;
    while (!visited[y][x][dir]) {
        Len++;
        visited[y][x][dir] = true;
        
        if (map[y][x] == 'L') {
            dir = (dir + 1) % 4;
        }
        else if (map[y][x] == 'R') {
            dir = (dir + 3) % 4;
        }
        
        x = (x + dx[dir] + M) % M;
        y = (y + dy[dir] + N) % N;
    }
    
    return Len;
}


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    N = grid.size();
    M = grid[0].size();
    map = grid;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<4; k++) {
                if (!visited[i][j][k]) {
                    answer.push_back(GetLengthOfCycle(i, j, k));
                } 
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}