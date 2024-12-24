#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int idx = num_list.size();
    int prev = num_list[idx-2], last = num_list[idx-1];
    
    if(last > prev) num_list.emplace_back(last - prev);
    else num_list.emplace_back(2*last);
    
    return num_list;
}