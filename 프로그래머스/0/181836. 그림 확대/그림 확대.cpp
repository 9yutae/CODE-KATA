#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(auto& w:picture) {
        string tmp;
        for(int i=0;i<w.size();i++) {
            for(int j=0;j<k;j++)
                tmp += w[i];
        }
        w = tmp;
    }
    
    for(const auto& w:picture) {
        for(int i=0;i<k;i++) {
            answer.emplace_back(w);
        }
    }
    
    return answer;
}