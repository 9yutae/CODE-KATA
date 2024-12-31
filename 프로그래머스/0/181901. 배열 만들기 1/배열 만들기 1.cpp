#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer(n/k);
    iota(answer.begin(), answer.end(), 1);
    for(auto& w:answer) w *= k;
    
    return answer;
}