#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    for(const auto w:queue1) sum1 += w;
    for(const auto w:queue2) sum2 += w;
    
    if((sum1 + sum2) % 2 != 0) return -1;
    
    int answer = 0;
    int idx1 = 0, idx2 = 0;
    int size1 = queue1.size(), size2 = queue2.size();
    while(idx1 < queue1.size() && idx2 < queue2.size()) {
        if(sum1 == sum2) break;
        if(idx1 + idx2 > (size1 + size2) * 2) break;
        if(sum1 > sum2) {
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            queue2.push_back(queue1[idx1++]);
        }
        else {
            sum1 += queue2[idx2];
            sum2 -= queue2[idx2];
            queue1.push_back(queue2[idx2++]);
        }
        
        answer++;
    }
    
    if(sum1 != sum2) return -1;
    return answer;
}