#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(int n) {
    vector<int> DP(60001, 0);
    DP[1] = 1;
    DP[2] = 2;
    
    for (int i = 3 ; i <= n ; i++) {
        DP[i] = (DP[i-2] + DP[i-1]) % 1000000007;
    }
    
    return DP[n];
}