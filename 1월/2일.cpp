#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string x, string y) {
    int i, j = min(x.size(), y.size());

    for (i = 0; i < j; i++) {
        if (x[i] == y[i]) {
            continue;
        }
        else
            return (x[i] < y[i]);
    }

    return (x[i] < y[i]);
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i].size() <= phone_book[i + 1].size()) {
            if (phone_book[i + 1].find(phone_book[i]) == 0)
                return false;
        }
    }
    
    return answer;
}