#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int SelectCriteria(string ext) {
    if (ext == "code") return 0;
    else if (ext == "date") return 1;
    else if (ext == "maximum") return 2;
    else if (ext == "remain") return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int extIdx = SelectCriteria(ext);
    vector<vector<int>> answer;
    for(const auto& vec : data) {
        if (vec[extIdx] < val_ext) answer.push_back(vec);
    }
    
    extIdx = SelectCriteria(sort_by);
    sort(answer.begin(), answer.end(), 
         [extIdx] (const vector<int>& lhs, const vector<int>& rhs) {
             return lhs[extIdx] < rhs[extIdx];
         });
    
    return answer;
}