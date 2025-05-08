#include <string>
#include <vector>
using namespace std;

bool visited[200];

void dfs(int idx, int n, const vector<vector<int>>& computers) {
    for (int i=0; i<n; i++) {
        if (i != idx && computers[idx][i] && !visited[i]) {
            visited[i] = true;
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0; i<n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}