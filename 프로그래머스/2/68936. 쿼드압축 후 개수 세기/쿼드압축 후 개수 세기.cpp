#include <string>
#include <vector>

using namespace std;

vector<vector<int>> vec;

void QuadTree(vector<int>& answer, int n, int x, int y) {
    if (n == 1) {
        answer[vec[y][x]]++;
        return;
    }
    
    bool flag = true;
    for (int i = y; i < n + y ; i++) {
        for (int j = x; j < n + x ; j++) {
            if (vec[i][j] != vec[y][x]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    
    if (flag) {
        answer[vec[y][x]]++;
    }
    else {
        QuadTree(answer, n/2, x, y);
        QuadTree(answer, n/2, x, y + n/2);
        QuadTree(answer, n/2, x + n/2, y);
        QuadTree(answer, n/2, x + n/2, y + n/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0, 0 };
    vec = arr;
    QuadTree(answer, arr.size(), 0, 0);
    
    return answer;
}