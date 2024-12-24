#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const auto& w:queries) {
        for(int i=w[0];i<=w[1];i++) {
            if(i%w[2] == 0) arr[i]++;
        }
    }
    
    return arr;
}