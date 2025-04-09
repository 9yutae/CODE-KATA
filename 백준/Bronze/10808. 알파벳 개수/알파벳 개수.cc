#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string input;
    cin >> input;

    map<char, int> alphabet;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        alphabet[ch] = 0;
    }

    for (const char& ch : input) {
        alphabet[ch]++;
    }

    for (const auto& w : alphabet) {
        cout << w.second << " ";
    }
}
