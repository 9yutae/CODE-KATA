#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> que;
    for(int i=0;i<priorities.size();i++) {
        que.push(i);
    }
    
    vector<int> process;
    while(!que.empty()) {
        int index = que.front();
        que.pop();
        
        int MaxNum = *max_element(priorities.begin(), priorities.end());
        
        if(MaxNum == priorities[index]) {
            process.push_back(index);
            priorities[index] = -1;
        }
        else {
            que.push(index);
        }
    }
    
    for(int i=0;i<process.size();i++) {
        if(process[i] == location)
            return i+1;
    }
}