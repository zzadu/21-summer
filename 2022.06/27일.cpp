#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> currentL(4, 1), currentR(4, 3), key;
    
    int num;
    for (int i = 0; i < numbers.size(); i++) {
        num = numbers[i];
        
        if (num % 3 == 1) {
            answer += 'L';
            currentL.first = (num - 1) / 3 + 1;
            currentL.second = 1;
        }
        else if (num % 3 == 0 && num != 0) {
            answer += 'R';
            currentR.first = (num - 1) / 3 + 1;
            currentR.second = 3;
        }
        else {
            if (num == 0) {
                key = make_pair(4, 2);
            }
            else {
                key = make_pair((num - 1) / 3 + 1, 2);
            }
            int distanceL = abs(currentL.first - key.first) + abs(currentL.second - key.second); // 왼손 거리
            int distanceR = abs(currentR.first - key.first) + abs(currentR.second - key.second); // 오른손 거리
            
            if (distanceL < distanceR) { // 왼손 사용
                answer += 'L';
                currentL = key;
            }
            else if (distanceR < distanceL) { // 오른손 사용
                answer += 'R';
                currentR = key;
            }
            else { // 거리 같을 때
                if (hand == "right") { // 오른손 사용
                    answer += 'R';
                    currentR = key;
                }
                else { // 왼손 사용
                    answer += 'L';
                    currentL = key;
                }
            }
        }
    }
    return answer;
}
