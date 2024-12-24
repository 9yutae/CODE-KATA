#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    while(n!=1) {
        answer.emplace_back(n);
        
        if(n%2 == 0) n/=2;
        else n = 3*n + 1;
    }
    
    answer.emplace_back(n);
    
    return answer;
}