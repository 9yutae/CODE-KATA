#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(const auto& w:numbers) {
        if(w%2 == 0) answer.push_back(w+1);
        else {
            long long bit = 1;
            while(true) {
                if((w&bit) == 0) break;
                bit <<= 1;   
            }
            
            answer.push_back(w + (bit / 2));
        }
    }
    
    return answer;
}