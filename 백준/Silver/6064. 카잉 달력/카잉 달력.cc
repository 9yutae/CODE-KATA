#include <iostream>
#define endl "\n"

using namespace std;

int gcd(int a, int b){ // 최대 공약수
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){ // 최소 공배수
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int ans = -1;
        int maxi = lcm(M, N);
        while(x <= maxi) {
            int ny = x % N;
            if(ny == 0) ny = N;
            if(ny == y) {
                ans = x;
                break;
            }

            x += M;
        }
        cout << ans << endl;
    }

    return 0;
}
