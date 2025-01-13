#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    bool isExist[100001] = { false };
    
    for(int i=0;i<arr.size();i++) {
        if(answer.size() == k) break;
        if(isExist[arr[i]] == false) {
            answer.push_back(arr[i]);
            isExist[arr[i]] = true;
        }
    }
    
    for(int i=answer.size();i<k;i++) answer.push_back(-1);
    
    return answer;
}