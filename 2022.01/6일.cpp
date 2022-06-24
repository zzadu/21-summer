#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (int x, int y) {
    return x > y;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), cmp);
    citations.push_back(0);
    
    for (int i = 0; i < citations.size() - 1; i++) {
        for (int j = citations[i]; j > citations[i + 1]; j--) {
            if (i + 1 == j) {
                return answer = j;
            }
            else if (i + 1 >= j)
                return answer = j;
        }
    }

    return answer;
}