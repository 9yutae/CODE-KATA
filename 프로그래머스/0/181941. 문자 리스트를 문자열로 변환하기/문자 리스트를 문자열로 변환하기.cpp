#include <string>
#include <vector>
#include <sstream>
// #include <numeric>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    // for(auto &w:arr) answer += w;    
    //return accumulate(arr.begin(), arr.end(), string(""));
    
    ostringstream oss;
    for (const auto& w : arr) {
        oss << w;
    }
    
    return oss.str();
    
   //  return answer;
}