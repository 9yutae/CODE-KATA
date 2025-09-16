#include <string>
#include <algorithm>

using namespace std;

int solution(int n) {
    string binary = "";
    while (n) {
        binary += (n%2 ? '1' : '0');
        n /= 2;
    }

    int indexLastOnes = binary.find('1');
    int countLastOnes = 0;
    for(;indexLastOnes < binary.size() ; indexLastOnes++) {
        if (binary[indexLastOnes] == '1') countLastOnes++;
        else break;
    }
    
    if (indexLastOnes == binary.size()) binary += '1'; 
    else binary[indexLastOnes] = '1';
    
    for(int i = 0 ; i < indexLastOnes ; i++) {
        if ((countLastOnes--) > 1) binary[i] = '1';
        else binary[i] = '0';
    }
    
    int answer = 0;
    for (int i = 0, radix = 1 ; i < binary.size() ; i++) {
        answer += radix * (binary[i] - '0');
        radix *= 2;
    }
    
    return answer;
}