#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<int> skillTree(26, 0);
    int idx = 1;
    for (const auto& ch : skill) {
        skillTree[ch - 'A'] = idx++;
    }
    
    int availableTrees = 0;
    for (const auto& str : skill_trees) {
        bool flag = true;
        idx = 1;
        for (const auto& ch : str) {
            if (skillTree[ch - 'A'] == 0) continue;
            if (skillTree[ch - 'A'] == idx) idx++;
            else {
                flag = false;
                break;
            }
        }
        
        if (flag) availableTrees++;
    }
    
    return availableTrees;
}