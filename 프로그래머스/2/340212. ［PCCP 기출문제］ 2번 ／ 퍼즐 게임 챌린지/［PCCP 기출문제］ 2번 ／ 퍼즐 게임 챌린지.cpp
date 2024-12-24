#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {    
    int minLevel = 1, N = diffs.size();
    int MaxLevel = *max_element(diffs.begin(), diffs.end());
    
    int answer = MaxLevel;

    while(minLevel <= MaxLevel) {
        int curLevel = (minLevel + MaxLevel) / 2;
        long long total = times[0];
        
        for(int i=1;i<N;i++) {
            if(diffs[i] > curLevel) total += ((diffs[i] - curLevel) * (times[i-1] + times[i]));
            total += times[i];
            
            if(total > limit) break;
        }
        
        if(total <= limit) {
            MaxLevel = curLevel - 1;
            answer = min(answer, curLevel);
        }
        else
            minLevel = curLevel + 1;
        }

/**
    for(int i=1;i<N;i++) {
        if(diffs[i] > answer) total += ((diffs[i] - answer) * (times[i-1] + times[i]));
        total += times[i];
    }
    
    while(total > limit) {
        answer++;
        for(int i=1;i<N;i++) {
            if(diffs[i] >= answer) total -= (times[i-1] + times[i]);
        }
    }
**/
    return answer;
}