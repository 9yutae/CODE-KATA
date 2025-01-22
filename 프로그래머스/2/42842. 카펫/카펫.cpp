#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    double width = 1 + brown / 4 + sqrt(pow(brown/2 - 2, 2) - 4 * yellow) / 2;
    double height = 1 + brown / 4 - sqrt(pow(brown/2 - 2, 2) - 4 * yellow) / 2;
    
    answer[0] = round(width);
    answer[1] = round(height);
    
    return answer;
}