#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for(int i=0;i<arr.size();i++) {
        int rept = arr[i];
        if(flag[i]) rept *= 2;
        while(rept--) {
            if(flag[i]) answer.push_back(arr[i]);
            else answer.pop_back();
        }
    }
    return answer;
}