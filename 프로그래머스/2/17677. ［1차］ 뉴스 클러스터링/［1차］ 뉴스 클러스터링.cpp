#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

set<string> keywords;

map<string, int> makeValidPair(const string& str) {
    map<string, int> validStr;
    for (int i = 0 ; i < str.size() - 1 ; i++) {
        char ch1 = str[i], ch2 = str[i + 1];
        string tmp = "";
        if (isupper(ch1)) tmp += ch1;
        else if (islower(ch1)) tmp += (ch1 - 32);
        else continue;
        
        if (isupper(ch2)) tmp += ch2;
        else if (islower(ch2)) tmp += (ch2 - 32);
        else continue;
        
        validStr[tmp]++;
        keywords.insert(tmp);
    }
    
    return validStr;
}

int solution(string str1, string str2) {
    map<string, int> validStr1 = makeValidPair(str1);
    map<string, int> validStr2 = makeValidPair(str2);
    
    float intersectionSet = 0, unionSet = 0;
    for(const string& str : keywords) {
        if (validStr1.find(str) != validStr1.end() && validStr2.find(str) != validStr2.end()) {
            intersectionSet += min(validStr1[str], validStr2[str]);
            unionSet += max(validStr1[str], validStr2[str]);
        }
        else if (validStr1.find(str) != validStr1.end()) {
            unionSet += validStr1[str];
        }
        else if (validStr2.find(str) != validStr2.end()) {
            unionSet += validStr2[str];
        }
    }
    
    return unionSet != 0 ? intersectionSet / unionSet * 65536 : 65536;
}