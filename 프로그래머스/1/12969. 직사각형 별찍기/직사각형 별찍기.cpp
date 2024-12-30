#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    string s;
    s.append(a, '*');
    
    while(b--) cout << s << endl;
    
    return 0;
}