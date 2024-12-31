#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int idx) {
    auto iter = find(arr.begin() + idx, arr.end(), 1);
    return iter != arr.end() ? iter - arr.begin() : -1;
}