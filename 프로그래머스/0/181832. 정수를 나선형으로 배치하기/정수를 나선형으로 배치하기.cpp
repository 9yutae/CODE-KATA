#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    int x = 0, y= 0, direction = 0;
    for(int i=1;i<=n*n;i++) {
        answer[y][x] = i;
        
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || answer[ny][nx] != 0) {
            direction = (direction+1) % 4;
            nx = x + dx[direction];
            ny = y + dy[direction];
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}