#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> answer;
    vector<int> sum = { 0 };
    
    for(const auto& w:elements) {
        sum.push_back(w + sum.back());
    }
    
    for(const auto& w:elements) {
        sum.push_back(w + sum.back());
    }
 
    for (int i = 0; i < elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
            answer.insert(sum[i + 1 + j] - sum[j]);
    }
    
    return answer.size();
}