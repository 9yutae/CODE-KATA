#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    for(int i=0;i<numbers.size();i++) {
        for(int j=i+1;j<numbers.size();j++) {
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer;
    for(const auto& w:s) answer.emplace_back(w); 
    
    return answer;
}