#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> numbers, queue<int>* result, int i) {

    int size = (*result).size();

    for (int j = 0; j < size; j++) {
        (*result).push((*result).front() + numbers[i]);
        (*result).push((*result).front() - numbers[i]);
        (*result).pop();
    }

    if (i == numbers.size() - 1)
        return;

    bfs(numbers, result, ++i);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    queue<int> result;
    result.push(0);

    bfs(numbers, &result, 0);

    while (result.size()) {
        if (result.front() == target)
            answer++;
        result.pop();
    }

    return answer;
}