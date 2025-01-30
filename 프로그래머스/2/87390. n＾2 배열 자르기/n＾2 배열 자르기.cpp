#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> arr;
    
    long long row = left / n + 1;
    long long col = left % n + 1;
    
    for(long long i=left; i<=right; i++, col++) {
        
        if(col <= row) arr.push_back(row);
        else arr.push_back(col);
        
        if(col == n) {
            row++;
            col = 0;
        }
    }
    
    return arr;
}