#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> collatzSeq;
    vector<double> avgSum;
    
    collatzSeq.push_back(k);
    avgSum.push_back(0);
    
    while (k > 1) {
        int prev = collatzSeq.back();
        if (k % 2) {
            k = 3 * k + 1;
        }
        else {
            k /= 2;
        }
        
        collatzSeq.push_back(k);
        avgSum.push_back(avgSum.back() + (double)(k + prev) / 2.0);
    }
    
    int n = collatzSeq.size();
    vector<double> answer;
    for (const auto& range : ranges) {
        int leftBound = range[0];
        int rightBound = n - 1 + range[1];
        
        if (leftBound > rightBound) answer.push_back(-1);
        else answer.push_back(avgSum[rightBound] - avgSum[leftBound]);
    }
    
    return answer;
}