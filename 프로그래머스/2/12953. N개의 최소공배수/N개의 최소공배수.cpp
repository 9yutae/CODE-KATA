#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if(a < b) swap(a, b);
    
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i=1;i<arr.size();i++) {
        answer = answer * arr[i] / GCD(answer, arr[i]);
    }
    
    return answer;
}