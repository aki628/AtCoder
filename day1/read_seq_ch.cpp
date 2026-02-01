// Reads an input English-letter string and prints each character on a separate line.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0; // read a whitespace-delimited string

    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c))) {
            cout << c << '\n';
        }
    }

    return 0;
}