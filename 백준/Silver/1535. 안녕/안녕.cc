#include <iostream>
#include <vector>
using namespace std;

vector<int> Damage, GetJoy;
int N;

void backtrack(int idx, int Health, int Joy, int& MaxJoy) {
    if (Health <= 0) return;
    if (idx == N) {
        MaxJoy = max(MaxJoy, Joy);
        return;
    }

    backtrack(idx + 1, Health, Joy, MaxJoy);
    backtrack(idx + 1, Health - Damage[idx], Joy + GetJoy[idx], MaxJoy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Damage.resize(N);
    for (int& w : Damage)
        cin >> w;
    GetJoy.resize(N);
    for (int& w : GetJoy)
        cin >> w;

    int Health = 100, Joy = 0;
    int MaxJoy = 0;
    backtrack(0, Health, Joy, MaxJoy);

    cout << MaxJoy;
}
