#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), cmp);

    int i = 0;
    while (i < people.size()) {
        if (limit - people[i] < 40) { // 한명만 탈 수 있는 상황
        }
        else {
            if (people.size() > 1 && people[i] + people.back() <= limit)
                people.pop_back();
        }
        i++;
        answer++;
        
    }

    return answer;
}