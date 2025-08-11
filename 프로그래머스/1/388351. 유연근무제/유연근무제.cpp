#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int index = 0;
    for (const auto& vec : timelogs) {
        int day = startday - 1;
        int hourLimit = schedules[index] / 100;
        int minuteLimit = schedules[index] % 100 + 10;
        if (minuteLimit >= 60) {
            minuteLimit -= 60;
            hourLimit++;
        }
        
        bool flag = true;
        for (const auto& time : vec) {
            if (day > 4) {
                day = (day + 1) % 7;
                continue;
            }
            if (time / 100 > hourLimit) {
                flag = false;
                break;
            }
            if (time / 100 == hourLimit && time % 100 > minuteLimit) {
                flag = false;
                break;
            }
            
            day++;
        }
        
        if (flag) answer++;
        index++;
    }
    
    return answer;
}