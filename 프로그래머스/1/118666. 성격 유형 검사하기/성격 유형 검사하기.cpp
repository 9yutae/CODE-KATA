#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> mbti(26, 0);
    for(int i=0;i<survey.size();i++) {
        int first = survey[i][0] - 'A';
        int last = survey[i][1] - 'A';
        
        switch(choices[i]) {
            case 1:
                mbti[first] += 3;
                break;
            case 2:
                mbti[first] += 2;
                break;
            case 3:
                mbti[first] += 1;
                break;
            case 5:
                mbti[last] += 1;
                break;
            case 6:
                mbti[last] += 2;
                break;
            case 7:
                mbti[last] += 3;
                break;
        }
    }
    
    answer += mbti['R'-'A'] >= mbti['T'-'A'] ? "R" : "T";
    answer += mbti['C'-'A'] >= mbti['F'-'A'] ? "C" : "F";
    answer += mbti['J'-'A'] >= mbti['M'-'A'] ? "J" : "M";
    answer += mbti['A'-'A'] >= mbti['N'-'A'] ? "A" : "N";
    
    return answer;
}