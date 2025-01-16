#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int width = park[0].size();
    int heigth = park.size();
    
    int x, y;
    for(int i=0;i<heigth;i++) {
        for(int j=0;j<width;j++) {
            if (park[i][j] == 'S') { 
                x = j;
                y = i;
                break;
            }
        }
    }

    for(const auto& w:routes) {
        bool canMove = true;
        int n = w[2] - '0';
        switch(w[0]){
            case 'E':
                for(int i=1;i <= n;i++) {
                    if(x+i > width - 1 || park[y][x+i] == 'X') canMove = false;
                }
                if(canMove) x += n;
                break;
            case 'W':
                for(int i=1;i <= n;i++) {
                    if(x-i < 0 || park[y][x-i] == 'X') canMove = false;
                }
                if(canMove) x -= n;
                break;
            case 'N':
                for(int i=1;i <= n;i++) {
                    if(y-i < 0 || park[y-i][x] == 'X') canMove = false;
                }
                if(canMove) y -= n;
                break;
            case 'S':
                for(int i=1;i <= n;i++) {
                    if(y+i > heigth - 1 || park[y+i][x] == 'X') canMove = false;
                }
                if(canMove) y += n;
                break;
        }
    }
    
    vector<int> answer = { y, x };
    return answer;
}