#include <string>
#include <vector>

using namespace std;

string convertNotes(const string& str) {
    string result = "";
    for (const char& ch : str) {
        if (ch == '#') {
            result.back() += 32;
        }
        else {
            result += ch;
        }
    }
    
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string search = convertNotes(m);
    int maxTime = -1;
    
    for (const auto& str : musicinfos) {
        int start = stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
        int finish = stoi(str.substr(6, 2)) * 60 + stoi(str.substr(9, 2));
        int time = finish - start;
        
        string music = convertNotes(str.substr(12));
        int pos = music.find(",");
        
        string title = music.substr(0, pos);
        string info = music.substr(pos + 1);
        
        int repeats = time / info.size();
        int mod = time % info.size();       
        
        string compare = "";
        while (repeats--) compare += info;
        if (mod) compare += info.substr(0, mod);
        
        if (compare.find(search) != string::npos && time > maxTime) {
            answer = title;
            maxTime = time;
        }
    }
    
    return answer;
}