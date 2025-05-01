#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> pq;
    for (const auto& str : operations) {
        int tmp = stoi(str.substr(2));
        if (str[0] == 'I') {
            pq.insert(tmp);
        }
        else if (tmp > 0 && !pq.empty()) {
            pq.erase(prev(pq.end()));
        }
        else if (tmp < 0 && !pq.empty()) {
            pq.erase(pq.begin());
        }
    }
    
    if (pq.empty()) return { 0, 0 };
    return { *prev(pq.end()), *pq.begin() };
}