#include <string>
#include <vector>
#include <map>
using namespace std;

bool isBingo(char c, const vector<string>& board) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

    return false;
}

int solution(vector<string> board) {
    map<char, int> counts;
    for (const string& str : board) {
        for (const char& ch : str) {
            counts[ch]++;
        }
    }
    
    if (counts['O'] < counts['X'] || counts['O'] - 1 > counts['X']) return 0;
    
    if (counts['O'] == counts['X']) {
        if (isBingo('O', board)) return 0;
    }
    if (counts['O'] == counts['X'] + 1) {
        if (isBingo('X', board)) return 0;
    }
    
    return 1;
}