#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(const auto& w:queries) {
        int min = 1234567;
        for(int i=w[0];i<=w[1];i++) {
            if(arr[i] > w[2] && arr[i] < min) min = arr[i];
        }
        
        if(min!=1234567) answer.push_back(min);
        else answer.push_back(-1);
    }
    
    return answer;
}