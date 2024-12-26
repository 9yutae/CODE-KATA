#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(auto& w:arr) answer += w;
    
    return answer/arr.size();
}