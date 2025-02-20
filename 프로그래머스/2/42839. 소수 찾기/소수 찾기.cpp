#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false; 
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int n = numbers.size();
    set<int> visited;
    int answer = 0;
    for (int i = 0; i < (1 << n); ++i) {
        string CurrentPermutation = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                CurrentPermutation += numbers[j];
        }
        
        if(CurrentPermutation.empty()) continue;
        sort(CurrentPermutation.begin(), CurrentPermutation.end());
        
        do {
            int tmp = stoi(CurrentPermutation);
            if(visited.find(tmp) != visited.end()) continue;
            visited.insert(tmp);
            
            if(isPrime(tmp)) answer++;
        } while (next_permutation(CurrentPermutation.begin(), CurrentPermutation.end()));
    }
    
    return answer;
}