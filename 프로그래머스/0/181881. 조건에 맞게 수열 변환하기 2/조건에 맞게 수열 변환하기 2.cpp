#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    vector<int> cntArr(arr.size());
    
    for(int i=0;i<arr.size();i++) {
        while(true) {
            if(arr[i] >= 50 && arr[i]%2 == 0) arr[i]/=2;
            else if(arr[i] < 50 && arr[i]%2 == 1) arr[i] = arr[i] * 2 + 1;
            else break;
            cntArr[i]++;
        }
    }
    
    return *max_element(cntArr.begin(), cntArr.end());
}