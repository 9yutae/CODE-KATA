#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {    
    map<string, set<string>> report_list;
    for(const auto w:report) {
        stringstream ss;
        ss.str(w);
            
        string reporter, reported;
        ss >> reporter >> reported;

        report_list[reported].insert(reporter);
    }
    
    map<string, int> answered;
    for(const auto& w:report_list) {
        if(w.second.size() >= k) {
            for(const auto& id:w.second)
                answered[id]++;
        }
    }
    
    vector<int> answer;
    for(const auto& w:id_list) {
        answer.push_back(answered[w]);
    }
    
    return answer;
}