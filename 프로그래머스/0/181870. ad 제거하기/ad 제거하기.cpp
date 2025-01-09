#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for(auto iter=strArr.begin();iter!=strArr.end();){
        if(iter->find("ad") != string::npos) {
            strArr.erase(iter);
        }
        else 
            iter++;
    }
    return strArr;
}