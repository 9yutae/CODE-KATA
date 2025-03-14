#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

int solution(vector<vector<string>> book_time) {
    vector<pii> times;
    for(const auto& w : book_time) {
        int start = (w[0][0] - '0') * 600 + (w[0][1] - '0') * 60 + (w[0][3] - '0') * 10 + (w[0][4] - '0');
        int end = (w[1][0] - '0') * 600 + (w[1][1] - '0') * 60 + (w[1][3] - '0') * 10 + (w[1][4] - '0');
        times.push_back({ start, end + 10});
    }
    
    sort(times.begin(), times.end());
    
    priority_queue<int> pq;
    for(const auto& w:times){
        if(!pq.empty() && -pq.top() <= w.first)
            pq.pop();
        pq.push(-w.second);
    }

    return pq.size();
}