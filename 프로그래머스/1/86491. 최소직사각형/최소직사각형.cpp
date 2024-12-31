#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> longer, shorter;
    for(auto& w:sizes) {
        if(w[0] > w[1]) { longer.emplace_back(w[0]); shorter.emplace_back(w[1]); }
        else { longer.emplace_back(w[1]); shorter.emplace_back(w[0]);}
    }
    
    int lMax = *max_element(longer.begin(), longer.end());
    int sMax = *max_element(shorter.begin(), shorter.end());
        
    return lMax * sMax;
}