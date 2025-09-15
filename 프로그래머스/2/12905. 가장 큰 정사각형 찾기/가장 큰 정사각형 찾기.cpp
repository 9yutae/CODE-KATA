#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int MaxLength = 0;
    for (int i = 0 ; i < board.size() ; i++) {
        for (int j = 0 ; j < board[0].size() ; j++) {
            if (i != 0 && j != 0 && board[i][j] == 1) {
                board[i][j] = min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
            }
            
            MaxLength = max(MaxLength, board[i][j]);
        }
    }
    
    return MaxLength * MaxLength;
}