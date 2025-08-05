#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<int>> DB;

void insertAllCombinations(const vector<string>& infoTokens) {
    vector<string> fields(infoTokens.begin(), infoTokens.begin() + 4);
    int score = stoi(infoTokens[4]);
    
    int n = fields.size();
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        string key = "";
        for (int i = 0 ; i < n ; i++) {
            if (mask & (1 << i)) {
                key += fields[i];
            }
            else {
                key += "-";
            }
            
        }
        
        DB[key].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    for (const string& str : info) {
        vector<string> infoTokens;
        stringstream infoStream(str);
        string token;
        
        while(infoStream >> token) {
            infoTokens.push_back(token);
        }
        
        insertAllCombinations(infoTokens);
    }
    
    for (auto& [_, scores] : DB) {
	    sort(scores.begin(), scores.end());
	}
    
    vector<int> responses;
    for (const string& request : query) {
        stringstream queryStream(request);
        string token, queryTokens = "";
        int flag = 0;
        
        while (queryStream >> token) {
            if (token == "and") continue;
            if (!isdigit(token[0])) queryTokens += token;
            else flag = stoi(token);
        }
        
        const vector<int>& scores = DB[queryTokens];
        int count = scores.end() - lower_bound(scores.begin(), scores.end(), flag);
        responses.push_back(count);
    }
    
    return responses;
}