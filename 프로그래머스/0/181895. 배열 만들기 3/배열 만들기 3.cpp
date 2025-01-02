#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for(const auto& w:intervals) {
        copy(arr.begin() + w[0], arr.begin() + w[1] + 1, std::back_inserter(answer));
    }
    
    return answer;
}