#include <iostream>
#include <vector>

using namespace std;

const int MAX = 0xffffff;

vector<int> dijkstra(int start, vector<vector<int>> graph, int n) {
    vector<int> distance(graph[start]);
    vector<bool> visited(n, false);
    visited[start] = true;
    
    for(int i=0; i < n; i++) {
        int min = MAX;
        int current = 0;
        for(int j=0; j < n; j++) {
            if(distance[j] < min && !visited[j]) {
                min = distance[j];
                current = j;
            }
        }
        visited[current] = true;
        
        for(int j=0; j < n; j++) {
            if(!visited[j] && distance[current] + graph[current][j] < distance[j]) {
                distance[j] = distance[current] + graph[current][j];
            }
        }
    }
    
    return distance;
}

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<int>> graph(N, vector<int>(N, MAX));
    for(int i = 0; i < N; i++)
        graph[i][i] = 0;
    
    for(const auto& w : road) {
        int u = w[0] - 1, v = w[1] - 1;
        graph[u][v] = min(graph[u][v], w[2]);
        graph[v][u] = min(graph[v][u], w[2]);
    }
    
    vector<int> distance = dijkstra(0, graph, N);
    int answer = 0;
    for(const auto& dist : distance) {
        if(dist <= K) answer++;
    }

    return answer;
}