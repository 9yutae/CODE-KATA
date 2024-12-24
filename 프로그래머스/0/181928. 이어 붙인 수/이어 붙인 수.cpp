#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    for(const auto &w:num_list) {
        if(w%2) odd = odd * 10 + w;
        else even = even * 10 + w;
    }
    
    return odd + even;
}