#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for(auto& w:num_list) {
        while(w!=1) {
            w = w%2 ? (w-1)/2 : w/2;
            answer++;
        }
    }
    return answer;
}