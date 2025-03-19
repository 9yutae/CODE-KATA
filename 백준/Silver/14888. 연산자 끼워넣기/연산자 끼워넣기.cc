#include <iostream>
#include <vector>
using namespace std;

int minVal = 1000000001;
int MaxVal = -1000000001;

void backtrack(int num, int idx, vector<int>& operands, vector<int>& operators) {
    if(idx == operands.size()) {
        MaxVal = max(num, MaxVal);
        minVal = min(num, minVal);
        return;
    }

    for(int i=0; i<4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            if(i == 0)
                backtrack(num + operands[idx], idx+1, operands, operators);
            else if(i == 1)
                backtrack(num - operands[idx], idx+1, operands, operators);
            else if(i == 2)
                backtrack(num * operands[idx], idx+1, operands, operators);
            else if(i == 3)
                backtrack(num / operands[idx], idx+1, operands, operators);
            operators[i]++;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> operands(N);
    for (int& oper : operands) {
        cin >> oper;
    }

    vector<int> operators(4);
    for (int& oper : operators) {
        cin >> oper;
    }

    backtrack(operands[0], 1, operands, operators);

    cout << MaxVal << "\n" << minVal;

    return 0;
}
