#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    vector<int> on_bridge;

    int i, start = 0;

    for (i = 0; i < truck_weights.size(); i++) {
        
        int sum = 0;

        for (int j = i - 1; j >= start && start > 0; j--) {
            if (answer - on_bridge[j] >= bridge_length) {
                start = j + 1;
                break;
            }
        }

        for (int j = start; j <= i; j++) {
            sum += truck_weights[j];
        }

        if (sum <= weight && on_bridge.size() - start < bridge_length) {
            on_bridge.push_back(answer);
            answer++;
        }
        else {
            answer += bridge_length - (answer - on_bridge[start]);
            start++;
            i--;
        }
    }

    answer += bridge_length - 1;
    return answer;
} 