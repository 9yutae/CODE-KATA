#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int y = arr.size();
    int x = arr[0].size();
    
    if(y > x) {
        for(auto& w:arr) {
            for(int i=0;i<y - x; i++)
                w.emplace_back(0);
        }
    }
    else if(x > y) {
        vector<int> tmp(x, 0);
        for(int i=0;i<x-y;i++)
            arr.emplace_back(tmp);
    }
    
    return arr;
}