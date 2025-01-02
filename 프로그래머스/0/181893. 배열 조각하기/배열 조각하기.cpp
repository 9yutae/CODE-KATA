#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    int from = 0, to = arr.size();
    for(int i=0;i<query.size();i++) {
        if(i%2==0) to = from + query[i] + 1;
        else from += query[i];
    }
    vector<int> answer(arr.begin() + from, arr.begin() + to);
    
    return answer;
}