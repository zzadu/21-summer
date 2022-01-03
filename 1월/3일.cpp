#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<string> x, vector<string> y) {
    return x[1] < y[1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int kind = 1;
    sort(clothes.begin(), clothes.end(), compare);

    int cnt[30] = { 1, 0 };
    for (int i = 0,  j = 0; i < clothes.size() - 1; i++) {
        if (clothes[i][1] != clothes[i + 1][1]) {
            kind++;
            cnt[++j]++;
        }
        else
            cnt[j]++;
    }

    if (kind == 1) {
        answer = clothes.size();
    }
    else {
        for (int k = 0; k < kind; k++) {
            answer *= (cnt[k] + 1);
        }
        answer--;
    }

    return answer;
}