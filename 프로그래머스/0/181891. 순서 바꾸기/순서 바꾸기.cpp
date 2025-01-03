#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    copy(num_list.begin() + n, num_list.end(), back_inserter(answer));
    copy(num_list.begin(), num_list.begin() + n, back_inserter(answer));
    
    return answer;
}