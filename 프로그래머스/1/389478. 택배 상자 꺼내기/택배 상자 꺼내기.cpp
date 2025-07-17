#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    vector<vector<int>> packages(w, vector<int>());
    
    int row = -1;
    for (int i = 0 ; i < n ; i++) {
        int column = i%w;
        if (column == 0) row++;

        if (row % 2) {
            packages[w - column - 1].push_back(i+1);
        }
        else {
            packages[column].push_back(i+1);
        }
    }
    
    int rowIdx = (num - 1) / w;
    int colIdx = rowIdx % 2 == 0 ? (num-1) % w : w - (num-1) % w - 1;
    return packages[colIdx].size() - rowIdx;
}