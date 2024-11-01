#include <iostream>
#include <map>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    map<int, int> cards;

    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        auto it = cards.find(tmp);
        if (it != cards.end()) {
            it->second++;
        }
        else {
            cards.insert({tmp, 1});
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        auto it = cards.find(tmp);
        if (it != cards.end()) {
            cout << it->second << " ";
        }
        else {
            cout << "0 ";
        }
    }

    return 0;
}