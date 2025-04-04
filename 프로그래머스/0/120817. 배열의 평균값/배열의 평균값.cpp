#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for(auto& w:numbers) answer += w;
    
    answer /= numbers.size();
    
    return answer;
}