#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int index = 0;
    while(k > 0) {
        if(index + k >= number.size()) {
            number.erase(index, k);
            break;
        }

        bool flag = false;    
        for(int i=1;i<=k;i++) {
            if(number[index] < number[index+i]) {
                flag = true;
                break;
            }
        }

        if(flag) {
            number.erase(index, 1);
            k--;
        }
        else index++;
    }
    
    if(number.size() == 0) return "0";
    return number;
}