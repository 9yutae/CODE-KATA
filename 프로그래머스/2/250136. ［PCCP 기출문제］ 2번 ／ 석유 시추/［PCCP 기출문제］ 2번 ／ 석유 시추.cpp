#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> oilRegionMap;
vector<vector<bool>> visited;
map<int, int> oilRegionSize;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfsMarkOilRegion(const int& regionId, const vector<vector<int>>& land, int yi, int xi) {
    queue<pair<int, int>> q;
    q.push({yi, xi});
    
    int currRegionSize = 1;
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for (int dir = 0 ; dir < 4 ; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < oilRegionMap[0].size() && ny >= 0 && ny < oilRegionMap.size()
                && !visited[ny][nx] && land[ny][nx] == 1) {
                q.push({ny, nx});
                oilRegionMap[ny][nx] = regionId;
                visited[ny][nx] = true;
                currRegionSize++;
            }
        }
    }
    
    oilRegionSize[regionId] = currRegionSize;
}

int solution(vector<vector<int>> land) {
    oilRegionMap.resize(land.size(), vector<int>(land[0].size(), 0));
    visited.resize(land.size(), vector<bool>(land[0].size(), false));
    
    int regionId = 1;
    for (int i = 0 ; i < land.size() ; i++) {
        for (int j = 0 ; j < land[0].size() ; j++) {
            if (land[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                bfsMarkOilRegion(regionId, land, i, j);
                oilRegionMap[i][j] = regionId++;
            }
        }
    }
    
    int maxOilAmount = 0;
    for (int j = 0 ; j < oilRegionMap[0].size() ; j++) {
        set<int> columnRegionSet;
        for (int i = 0 ; i < oilRegionMap.size() ; i++) {
            if (oilRegionMap[i][j] != 0) columnRegionSet.insert(oilRegionMap[i][j]);
        }
        
        int currOil = 0;
        for (const auto& w : columnRegionSet) {
            currOil += oilRegionSize[w];
        }
        
        maxOilAmount = max(maxOilAmount, currOil);
    }
    
    return maxOilAmount;
}