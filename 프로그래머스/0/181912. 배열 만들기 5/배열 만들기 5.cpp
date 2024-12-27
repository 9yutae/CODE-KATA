#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(const auto& w:intStrs) {
        int num = 0;
        for(int i=s;i<s+l;i++) {
            num = num * 10 + (w[i] - '0');
        }
        
        if(num > k) answer.emplace_back(num);
    }
    
    return answer;
}