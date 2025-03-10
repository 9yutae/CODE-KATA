#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> arrays(rows*columns);
    iota(arrays.begin(), arrays.end(), 1);
    
    vector<int> answer;
    int direction[4] = { 1, columns, -1, -columns };
    for(const auto& q : queries) {
        int idx = (q[0] - 1) * columns + (q[1] - 1);
        int curr = arrays[idx];
        int minValue = curr;
        
        for(int i=1;i<=4;i++) {
            int n = q[i%2 + 2] - q[i%2];
            while(n--) {
                idx += direction[i-1];
                int next = arrays[idx];
                arrays[idx] = curr;
                minValue = min(minValue, curr);
                curr = next;
            }
        }
        
        answer.push_back(minValue);
    }

    return answer;
}