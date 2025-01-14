#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() != arr2.size()) return arr1.size() > arr2.size() ? 1 : -1;
    int sum1 = 0, sum2 = 0;
    for(const auto& w:arr1) sum1 += w;
    for(const auto& w:arr2) sum2 += w;
    
    if(sum1 != sum2) return sum1 > sum2 ? 1 : -1;
    return 0;
}