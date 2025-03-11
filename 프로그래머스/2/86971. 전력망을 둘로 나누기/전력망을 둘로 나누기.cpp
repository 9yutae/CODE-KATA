#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

int DFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    
    int cnt = 1;
    while(!st.empty()) { 
        int node = st.top();
        st.pop();
        
        for (int w : graph[node]) {
            if(!visited[w]) {
                visited[w] = true;
                st.push(w);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    for(const auto& wire : wires) {
        int u = wire[0], v = wire[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int answer = n;
    for(auto& wire : wires) {
        int u = wire[0], v = wire[1];
        
        graph[u].erase(remove(graph[u].begin(), graph[u].end(), v), graph[u].end());
        graph[v].erase(remove(graph[v].begin(), graph[v].end(), u), graph[v].end());
        
        vector<bool> visited(n+1, false);
        int subtreeSize = DFS(u, graph, visited);
        int gap = abs(n - 2 * subtreeSize);
        answer = min(answer, gap);
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    return answer;
}