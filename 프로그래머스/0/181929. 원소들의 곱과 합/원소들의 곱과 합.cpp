#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int tot = 0, mul = 1;
    
    for(const auto &w:num_list) {
        tot += w;
        mul *= w;
    }

    return mul < tot*tot ? 1 : 0;
}