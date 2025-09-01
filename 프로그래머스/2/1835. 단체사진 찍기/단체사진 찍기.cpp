#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkAllConditions(const string& names, const vector<string>& data) {
    int pos[26];
    fill(begin(pos), end(pos), -1);
    for (int i = 0 ; i < names.size() ; i++) {
        pos[names[i] - 'A'] = i;
    }
    
    for (const string& request : data) {
        int A = request[0] - 'A';
        int B = request[2] - 'A';
        char oper = request[3];
        int k = request[4] - '0';
        
        int dist = abs(pos[A] - pos[B]) - 1;
        if (oper == '=' && dist != k) return false;
        if (oper == '<' && dist >= k) return false;
        if (oper == '>' && dist <= k) return false;
    }
    
    return true;
}

int solution(int n, vector<string> data) {
    string names = "ACFJMNRT";
    int answer = 0;
    
    sort(names.begin(), names.end());
    do {
        if (checkAllConditions(names, data)) answer++;
    } while (next_permutation(names.begin(), names.end()));
        
    return answer;
}