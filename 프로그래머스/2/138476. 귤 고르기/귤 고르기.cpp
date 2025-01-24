#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int,int> &lhs, pair<int,int> &rhs) {
    if(lhs.second == rhs.second) return lhs.first < rhs.first;
    return lhs.second > rhs.second;
}

int solution(int k, vector<int> tangerine) {
    map<int, int> sizes;
    for(const auto& w:tangerine)
        sizes[w]++;
    
    vector<pair<int, int>> vec(sizes.begin(), sizes.end());
    sort(vec.begin(), vec.end(), compare);
    
    int cnt = 0;
    int answer = 0;
    
    for(const auto& w:vec) {
        cnt += w.second;
        answer++;
        if(cnt >= k) break;
    }
    
    return answer;
}