#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string a, string b) {
    if(a.size() < b.size()) 
        swap(a, b);
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());    
    
    string answer(a.size()+1, '0');
    int i = 0;
    for(;i<a.size();i++) {
        int sum = (a[i] - '0') + (answer[i] - '0');
        if(i<b.size()) sum += (b[i] - '0');
        
        if(sum > 9) answer[i+1] = '1';
        answer[i] = (sum % 10) + '0';
    }
    
    if(answer[a.size()] == '0') answer.pop_back();
    reverse(answer.begin(), answer.end());
    
    return answer;
}