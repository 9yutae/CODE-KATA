#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> list;
    for(int i=0;i<want.size();i++) {
        list.insert({want[i], number[i]});
    }
    
    map<string,int> compare;
    for(int i=0;i<10;i++) {
        compare[discount[i]]++;
    }
    
    int answer = 0;
    if(list == compare) answer++;    
    
    for(int i=10;i<discount.size();i++) {
        if(compare[discount[i-10]] == 1) compare.erase(discount[i-10]);
        else compare[discount[i-10]]--;
        
        compare[discount[i]]++;
        if(list == compare) answer++;
    }
    
    return answer;
}