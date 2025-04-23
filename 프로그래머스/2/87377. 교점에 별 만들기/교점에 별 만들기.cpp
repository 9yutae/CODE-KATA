#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    long long minX = LLONG_MAX, minY = LLONG_MAX;
    long long maxX = LLONG_MIN, maxY = LLONG_MIN;
    vector<pair<long long, long long>> points;

    for (int i=0; i<line.size(); i++) {
        for (int j=i+1; j<line.size(); j++) {
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];

            long long denom = A*D - B*C;
            if (denom == 0) continue;

            long long x_num = B*F - E*D;
            long long y_num = E*C - A*F;

            if (x_num % denom == 0 && y_num % denom == 0) {
                long long x = x_num / denom;
                long long y = y_num / denom;
                points.push_back({x, y});

                minX = min(minX, x); maxX = max(maxX, x);
                minY = min(minY, y); maxY = max(maxY, y);
            }
        }
    }

    string str(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, str);

    for (auto& point : points) {
        answer[maxY - point.second][point.first - minX] = '*';
    }

    
    return answer;
}