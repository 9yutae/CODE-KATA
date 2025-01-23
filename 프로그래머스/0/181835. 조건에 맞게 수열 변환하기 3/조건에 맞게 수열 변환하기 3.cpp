#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if(k%2) {
        for(auto& w:arr) w *= k;
    }
    else {
        for(auto& w:arr) w += k;
    }
    return arr;
}