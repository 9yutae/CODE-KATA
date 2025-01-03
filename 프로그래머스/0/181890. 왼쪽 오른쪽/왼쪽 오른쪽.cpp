#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> str_list) {
    int lidx = find(str_list.begin(), str_list.end(), "l") - str_list.begin();
    int ridx = find(str_list.begin(), str_list.end(), "r") - str_list.begin();
    
    vector<string> answer;
    if(lidx < ridx) copy(str_list.begin(), str_list.begin() + lidx, back_inserter(answer));
    else if(lidx > ridx) copy(str_list.begin() + ridx + 1, str_list.end(), back_inserter(answer));
    
    return answer;
}