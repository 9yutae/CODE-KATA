#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1 ; i < land.size() ; i++) {
        int idexPrevMax = max_element(land[i-1].begin(), land[i-1].end()) - land[i-1].begin();
        int prevMax = land[i-1][idexPrevMax];
        
        vector<int> tmp(land[i-1]);
        tmp.erase(tmp.begin() + idexPrevMax);
        int secondMax = *max_element(tmp.begin(), tmp.end());
        
        for (int j = 0 ; j < land[i].size() ; j++) {
            if (j == idexPrevMax) land[i][j] += secondMax;
            else land[i][j] += prevMax;
        }
    }
    
    return *max_element(land.back().begin(), land.back().end());
}