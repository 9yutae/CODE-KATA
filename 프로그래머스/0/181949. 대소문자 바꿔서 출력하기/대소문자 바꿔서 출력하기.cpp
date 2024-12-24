#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(auto &w:str) {
        if(isupper(w)) w += 32;
        else if(islower(w)) w-= 32;
    }
    
    cout << str;
    
    return 0;
}