#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr) {
    int size = arr.size();
    if(size == 1) return arr;
    
    int cnt = 1;    
    for(int i=1;i<11;i++) {
        if(size <= pow(2,i)) break;
        else cnt++;
    }
    
    vector<int> answer = arr;
    for(int i=arr.size();i<pow(2, cnt);i++) answer.push_back(0);
    
    return answer;
}