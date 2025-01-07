#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int answer1[5] =  { 1, 2, 3, 4, 5 };
    int answer2[8] =  { 2, 1, 2, 3, 2, 4, 2, 5 };
    int answer3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> ansCnt(3);
    
    int idx = 0;
    for(const auto& w:answers) {
        if(w==answer1[idx%5]) ansCnt[0]++;
        if(w==answer2[idx%8]) ansCnt[1]++;
        if(w==answer3[idx%10]) ansCnt[2]++;
        idx++;
    }
    
    int maxVal = *max_element(ansCnt.begin(), ansCnt.end());
    vector<int> answer;
    for(int i=0;i<3;i++) {
        if(ansCnt[i] == maxVal) answer.emplace_back(i+1);
    }    
    
    return answer;
}