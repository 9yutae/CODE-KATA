#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<int> rankIdx(rank.size());
    for(int i=0;i<rank.size();i++)
        rankIdx[rank[i] - 1] = i;
    
    vector<int> top3;
    for(int i=0, cnt=0; cnt < 3 ;i++) {
        if(attendance[rankIdx[i]] == true) {
            top3.emplace_back(rankIdx[i]);
            cnt++;
        }
    }
    
    int answer = 10000*top3[0] + 100*top3[1] + top3[2];
    
    return answer;
}