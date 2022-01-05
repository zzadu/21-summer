#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y) {
    int j = min(x.size(), y.size());

    for (int i = 0; i < j; i++) {
        if (x[i] != y[i])
            return x[i] > y[i];
    }

    return x + y > y + x;

}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringN;

    for (int i = 0; i < numbers.size(); i++) {
        stringN.push_back(to_string(numbers[i]));
    }

    sort(stringN.begin(), stringN.end(), cmp);

    for (int j = 0; j < stringN.size(); j++) {
        answer += stringN[j];
    }

    if (stringN[0] == "0")
        answer = "0";

    return answer;
}