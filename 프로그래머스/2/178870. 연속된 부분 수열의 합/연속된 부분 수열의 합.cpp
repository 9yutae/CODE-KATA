#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);
    int current_sum = sequence[0];
    int left = 0, right = 0;
    int min_length = sequence.size() + 1;
    
    while(right < sequence.size()) {
        if (current_sum == k) {
            if ((right - left) < min_length) {
                min_length = right - left;
                answer = {left, right};
            }
        }
        if (current_sum >= k) {
            current_sum -= sequence[left];
            left++;
        } else {
            right++;
            if (right < sequence.size()) {
                current_sum += sequence[right];
            }
        }
    }
    
    return answer;
}