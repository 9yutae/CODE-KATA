#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left;i<=right;i++) {
        bool flag = true;
        int j = 1;
        while(j*j <= i) {
            if(j*j == i) flag = false;
            j++;
        }
        
        answer += flag ? i : -i;
    }
    
    return answer;
}