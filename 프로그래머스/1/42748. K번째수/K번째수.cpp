#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(const auto& w:commands) {
        vector<int> tmp;
        copy(array.begin() + w[0] - 1, array.begin() + w[1], back_insert_iterator<std::vector<int>> (tmp));
        sort(tmp.begin(), tmp.end());
        answer.emplace_back(tmp[w[2]-1]);
    }
    
    return answer;
}