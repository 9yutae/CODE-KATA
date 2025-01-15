#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    sort(num_list.begin(), num_list.end());
    copy(num_list.begin() + 5, num_list.end(), back_inserter(answer));
    
    return answer;
}