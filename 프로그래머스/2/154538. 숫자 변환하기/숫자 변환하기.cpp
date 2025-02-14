#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int,int>> que;
    que.push({x, 0});
    
    bool visited[1000001] = { false, };
    
    while(!que.empty()) {
        if(que.front().first == y) return que.front().second;
        
        int tmp = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        if(visited[tmp]) continue;
        visited[tmp] = true;
        
        if(tmp + n <= y) que.push({tmp + n, cnt + 1});
        if(tmp * 2 <= y) que.push({tmp * 2, cnt + 1});
        if(tmp * 3 <= y) que.push({tmp * 3, cnt + 1});
    }
    
    return -1;
}