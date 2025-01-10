#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    for(auto& w:s) {
        for(int i=0;i<index;i++) {
            w = (w != 'z') ? w + 1 : 'a';
            while(find(skip.begin(), skip.end(), w) != skip.end()) {
                w = (w != 'z') ? w + 1 : 'a';
            }
        }
    }
    return s;
}