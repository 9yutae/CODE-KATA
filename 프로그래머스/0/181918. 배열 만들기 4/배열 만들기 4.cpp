#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    for(int i=0;i<arr.size();i++) {
        if(stk.empty()) stk.emplace_back(arr[i]);
        else if(stk.back() < arr[i]) stk.emplace_back(arr[i]);
        else {
            stk.pop_back();
            i--;
        }
    }
    
    return stk;
}