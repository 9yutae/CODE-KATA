#include <string>
#include <vector>

using namespace std;
const int MAX = 0xffffff;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> nchar(26, MAX);
    for(const auto& w:keymap) {
        for(int i=0;i<w.size();i++) {
            int tmp = w[i] - 'A';
            if(nchar[tmp] > i) nchar[tmp] = i;
        }
    }
    
    vector<int> answer;
    for(const auto& t:targets) {
        int cnt = 0;
        for(const auto& w:t) {
            if(nchar[w-'A'] == MAX) {
                cnt = -1;
                break;
            }
            cnt += nchar[w-'A'] + 1;            
        }
        answer.push_back(cnt);
    }
    
    return answer;
}