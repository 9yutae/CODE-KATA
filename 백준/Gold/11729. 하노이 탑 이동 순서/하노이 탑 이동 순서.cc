#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> answer;

void hanoi(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        answer.push_back(make_pair(source, target));
        return;
    }

    hanoi(n-1, source, auxiliary, target);
    answer.push_back(make_pair(source, target));
    hanoi(n-1, auxiliary, target, source);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);

    cout << answer.size() << endl;
    for (const auto& p : answer) {
        cout << p.first << " " << p.second << "\n";
    }
}
