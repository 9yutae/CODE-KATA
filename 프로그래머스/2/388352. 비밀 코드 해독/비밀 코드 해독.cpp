#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> queries(n, 1);
    for (int i = 0 ; i < n - 5 ; i++) {
        queries[i] = 0;
    }
    
    int answer = 0;
    do {
        bool isValid = true;
        
        for (int i = 0 ; i < q.size() ; i++) {
            int cnt = 0;
            for (const auto& w : q[i]) {
                if (queries[w - 1] == 1) cnt++;
                if (cnt > ans[i]) break;
            }
            
            if (cnt != ans[i]) {
                isValid = false;
                break;
            }
        }
        
        if (isValid) answer++;
        
    } while (next_permutation(queries.begin(), queries.end()));

    return answer;
}