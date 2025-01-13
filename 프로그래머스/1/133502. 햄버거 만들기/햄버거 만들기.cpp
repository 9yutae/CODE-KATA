#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> burger = { -1 };
    int answer = 0;
    for(auto& w:ingredient) {
        if(burger.back() == 1 && w == 2) burger.back() = 12;
        else if(burger.back() == 12 && w == 3) burger.back() = 123;
        else if(burger.back() == 123 && w == 1) {
            answer++;
            burger.pop_back();
        }
        else burger.push_back(w);
    }
    
    return answer;
}