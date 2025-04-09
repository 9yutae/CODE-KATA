#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    // 좌우 이동 최소값 (기본은 오른쪽으로 끝까지 가는 경우)
    int minHorizontalMovements = name.size() - 1;
    int verticalMovements = 0;

    for (int i = 0; i < name.size(); i++) {
        // 위/아래 이동 횟수 (알파벳 변경)
        verticalMovements += min(name[i] - 'A', 'Z' + 1 - name[i]);

        // 좌우 이동 최소 거리 그리디 계산
        int nextIdx = i + 1;
        while (nextIdx < name.size() && name[nextIdx] == 'A')
            nextIdx++;

        int distanceLeftRound = i * 2 + name.size() - nextIdx;
        int distanceRightRound = i + (name.size() - nextIdx) * 2;
        minHorizontalMovements = min(minHorizontalMovements, min(distanceLeftRound, distanceRightRound));
    }

    return verticalMovements + minHorizontalMovements;
}