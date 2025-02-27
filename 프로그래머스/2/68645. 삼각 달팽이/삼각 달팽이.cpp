#include <string>
#include <vector>

using namespace std;

int dx[3] = { 0, 1, -1 };
int dy[3] = { 1, 0, -1 };

vector<int> solution(int n) {
    vector<vector<int>> Snail(n+1, vector<int>(n));
    
    int number = 1;
    int x = 0, y = -1, direction = 0;
    
    for(int i=n;i>0;i--) {
        int tmp = i;
        while(tmp--) {
            y += dy[direction];
            x += dx[direction];
            Snail[y][x] = number++;
        }
        direction = (direction + 1) % 3;
    }
    
    vector<int> answer;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            answer.push_back(Snail[i][j]);
        }
    }
    
    return answer;
}