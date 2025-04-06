#include <string>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i=0; i < row; i++) {
        if (board[i][col]) return false;
        if (col - row + i >= 0 && board[i][col - row + i]) return false;
        if (col + row - i < n && board[i][col + row - i]) return false;
    }
    return true;
}

void backtrack(int& answer, vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        answer++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            backtrack(answer, board, row + 1, n);
            board[row][col] = 0;
        }
    }
}

int solution(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    int answer = 0;
    backtrack(answer, board, 0, n);
    return answer;
}