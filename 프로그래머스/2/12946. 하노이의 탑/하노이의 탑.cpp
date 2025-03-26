#include <string>
#include <vector>

using namespace std;

void HanoiTower(int n, vector<vector<int>>& answer, int departure, int destination, int transfer) {
    if (n == 1) {
        answer.push_back({departure, destination});
        return;
    }
    
    HanoiTower(n-1, answer, departure, transfer, destination);
    answer.push_back({departure, destination});
    HanoiTower(n-1, answer, transfer, destination, departure);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    HanoiTower(n, answer, 1, 3, 2);
    return answer;
}