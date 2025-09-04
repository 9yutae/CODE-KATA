#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> digits = { 4, 1, 2 };

    while(n > 0) {
        answer += digits[n%3] + '0';
        if (n % 3 == 0) n = n / 3 - 1;
        else n /= 3;
    }

    reverse(answer.begin(), answer.end());  

    return answer;
}