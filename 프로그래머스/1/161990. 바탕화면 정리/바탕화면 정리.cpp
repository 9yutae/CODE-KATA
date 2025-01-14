#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux = 0xfffff, luy = 0xfffff;
    int rdx = -1, rdy = -1;
    for(int i=0;i<wallpaper.size();i++) {
        for(int j=0;j<wallpaper[i].size();j++) {
            if(wallpaper[i][j] == '#') {
                if(lux > i) lux = i;
                if(luy > j) luy = j;
                if(rdx < i+1) rdx = i+1;
                if(rdy < j+1) rdy = j+1;
            }
        }
    }
    
    vector<int> answer = {lux, luy, rdx, rdy};
    return answer;
}