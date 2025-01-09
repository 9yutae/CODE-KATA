#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<bool> hasExtra(n+2, false);
    for(const auto& w:reserve) hasExtra[w] = true;
    
    for(auto iter=lost.begin();iter<lost.end();) {
        if(hasExtra[*iter]) {
            hasExtra[*iter] = false;
            lost.erase(iter);
        }
        else iter++;
    }
    
    sort(lost.begin(), lost.end());
    int cnt = 0;
    for(const auto& w:lost) {
        if(hasExtra[w-1]) hasExtra[w-1] = false;
        else if(hasExtra[w+1]) hasExtra[w+1] = false;
        else cnt++;
    }
    
    return n - cnt;
}