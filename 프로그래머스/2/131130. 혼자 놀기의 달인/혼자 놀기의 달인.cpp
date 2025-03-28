#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    vector<int> groups;
    vector<bool> isUsed(cards.size(), false);
    
    for (int i=0; i<cards.size(); i++) {
        if (!isUsed[i]) {
            vector<int> box;
            box.push_back(cards[i]);
            isUsed[i] = true;
            
            while(true) {
                int idx = box.back() - 1;
                if (isUsed[idx]) {
                    break;
                }
                
                box.push_back(cards[idx]);
                isUsed[idx] = true;
            }
            
            groups.push_back(box.size());
        }
    }
    
    sort(groups.begin(), groups.end(), greater<int>());
    
    int answer = 0;
    if (groups.size() > 1) {
        answer = groups[0] * groups[1];
    }
    return answer;
}