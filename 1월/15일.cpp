#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, size = jobs.size();

    sort(jobs.begin(), jobs.end(), cmp);
    int time = 0;
    time += jobs[0][0];

    int i = 0;
    while (jobs.size() != 0) {
        int min = 0, j;
        answer += time + jobs[i][1] - jobs[i][0];
        time += jobs[i][1];

        jobs.erase(jobs.begin() + i);
        if (jobs.size() == 0)
            break;

        for (j = 0; j < jobs.size(); j++) {
            if (jobs[j][1] < jobs[min][1] && jobs[j][0] < time)
                min = j;
        }
        i = min;
    }

    return answer / size;
}