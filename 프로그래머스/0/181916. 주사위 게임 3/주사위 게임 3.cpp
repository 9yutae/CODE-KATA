#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    if(a==b && b==c && c==d) return 1111*a;
    
    vector<int> dice(7);
    
    dice.at(a)++;
    dice.at(b)++;
    dice.at(c)++;
    dice.at(d)++;
    
    int p=0;
    for(const auto& w:dice) {
        if(w==3) {
            auto p = find(dice.begin(), dice.end(), 3) - dice.begin();
            auto q = find(dice.begin(), dice.end(), 1) - dice.begin();
            return (10*p+q) * (10*p+q);
        }
        else if(w==2) {
            auto iter = find(dice.begin(), dice.end(), 2);
            auto iter2 = find(iter+1, dice.end(), 2);
            if(iter2 != dice.end()) {
                auto p = iter - dice.begin();
                auto q = iter2 - dice.begin();
                
                return (p+q) * (q-p);
            }
            else {
                auto iter = find(dice.begin(), dice.end(), 1);
                auto iter2 = find(iter+1, dice.end(), 1);
                
                auto q = iter - dice.begin();
                auto r = iter2 - dice.begin();
                return q*r;
            }
        }
    }
    
    return find(dice.begin(), dice.end(), 1) - dice.begin();
}