#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    
    vector<int> answer;
    copy(num_list.begin(), num_list.begin() + 5, back_inserter(answer));
    
    return answer;
}