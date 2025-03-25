#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [&](vector<int>& lhs, vector<int>& rhs) {
        if (lhs[col-1] == rhs[col-1]) return lhs[0] > rhs[0];
        return lhs[col-1] < rhs[col-1];
    });
    
    int answer = 0;
    for (int i=row_begin; i <= row_end; i++) {
        int modSum = 0;
        for (const auto& w : data[i-1]) {
            modSum += (w % i);
        }
        answer ^= modSum;
    }

    return answer;
}