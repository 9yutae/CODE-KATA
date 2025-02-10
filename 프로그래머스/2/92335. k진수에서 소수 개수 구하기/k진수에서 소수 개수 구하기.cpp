#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    string num;
    while(n>0) {
        num += to_string(n%k);
        n/=k;
    }
    reverse(num.begin(), num.end());
    
    vector<long long> num_list;
    stringstream ss(num);
    string buffer;
    while(getline(ss, buffer, '0')) {
        if(!buffer.empty()) {
            num_list.push_back(stoll(buffer));
        }
    }
    
    int answer = 0;
    for(const auto& w:num_list) {        
        bool flag = true;
        for(long long i=2;i<=sqrt(w);i++) {
            if(w%i == 0) flag = false;
            if(!flag) break;
        }
        
        if(w == 1) flag = false;
        if(flag) answer++;

    }
    
    return answer;
}