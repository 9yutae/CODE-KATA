#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    queue<int> que;
    for(int i=0;i<order.size();i++)
        que.push(i+1);
    
    int idx = 0;
    int answer = 0;
    stack<int> st;
    
    while(!que.empty()) {
        if(order[idx] == que.front()) {
            answer++;
            idx++;
            que.pop();
        }
        else if(!st.empty() && order[idx] == st.top()) {
            answer++;
            idx++;
            st.pop();
        }
        else {
            st.push(que.front());
            que.pop();
        }
    }
    
    while(!st.empty()) {
        if(order[idx] == st.top()) {
            answer++;
            idx++;
            st.pop();
        }
        else break;
    }

    return answer;
}