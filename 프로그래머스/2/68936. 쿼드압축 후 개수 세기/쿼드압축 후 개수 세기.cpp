#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> vec;

void QuadTree(vector<int>& answer, int n, int y, int x) {
    bool flag = true;
    int prv = vec[y][x];
    for(int i=y;i<y+n;i++) {
        for(int j=x;j<x+n;j++) {
            if(vec[i][j] != prv) flag = false;
        }
    }
    if(flag) answer[prv]++;
    else {
        QuadTree(answer, n/2, y, x);
        QuadTree(answer, n/2, y, x+n/2);
        QuadTree(answer, n/2, y+n/2, x);
        QuadTree(answer, n/2, y+n/2, x+n/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    vec = arr;
    QuadTree(answer, arr.size(), 0, 0);
    
    
    return answer;
}