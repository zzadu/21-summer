#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int i = 0;
    while (k) {
        if (i == number.size() - 1 && k > 0) {
            number.erase(number.end() - 1);
            k--;
        }
        else if (number[i] < number[i + 1]) {
            number.erase(number.begin() + i);
            k--;
            i = 0;
        }
        else
            i++;
    }
    
    
    return answer = number;
}