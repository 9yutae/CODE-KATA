#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const auto &w:queries) {
        int tmp = arr.at(w[0]);
        arr.at(w[0]) = arr.at(w[1]);
        arr.at(w[1]) = tmp;
    }
    
    return arr;
}