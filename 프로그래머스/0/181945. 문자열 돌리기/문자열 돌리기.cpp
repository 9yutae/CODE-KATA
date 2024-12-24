#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto &w:str) cout << w << endl;
    
    return 0;
}