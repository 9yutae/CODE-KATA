#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<vector<pair<int, int>>> robots(routes.size(), vector<pair<int, int>>());
    int MaxDist = 0;
    for (int i = 0 ; i < routes.size() ; i++) {
        int start = routes[i][0] - 1;
        int currRow = points[start][0], currCol = points[start][1];
        robots[i].emplace_back(currRow, currCol);
        
        int distance = 0;        
        for (int j = 1 ; j < routes[i].size() ; j++) {
            int dest = routes[i][j] - 1;
            int destRow = points[dest][0], destCol = points[dest][1];
            
            while (currRow != destRow) {
                currRow > destRow ? currRow-- : currRow++;
                robots[i].emplace_back(currRow, currCol);
                distance++;
            }
            
            while (currCol != destCol) {
                currCol > destCol ? currCol-- : currCol++;
                robots[i].emplace_back(currRow, currCol);
                distance++;
            }
        }
        
        MaxDist = max(MaxDist, distance);
    }
    
    int answer = 0;
    for (int i = 0 ; i <= MaxDist ; i++) {
        map<pair<int, int>, int> check;
        for(const auto& robot : robots) {
            if (robot.size() <= i) continue;
            check[robot[i]]++;
        }
        
        for (const auto& w : check) {
            if (w.second > 1) answer++;
        }
    }
    
    return answer;
}