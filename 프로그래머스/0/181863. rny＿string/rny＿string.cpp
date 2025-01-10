#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    while(rny_string.find("m") != string::npos) {
        int idx = rny_string.find("m");
        rny_string = rny_string.substr(0, idx) + "rn" + rny_string.substr(idx+1);
    }
    return rny_string;
}