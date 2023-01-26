#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, start = 0;
    
    if (cacheSize == 0)
        return 5 * cities.size();
    
    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    vector<string> c;
    
    for (int j = 0; j < cities.size(); j++) {
        if (find(c.begin(), c.begin() + j, cities[j]) == c.begin() + j) {
            answer += 5;
            c.push_back(cities[j]);
        }
        else {
            answer++;
            c.erase(find(c.begin(), c.begin() + j - 1, cities[j]));
            c.push_back(cities[j]);
        }
        
        if (c.size() > cacheSize)
            c.erase(c.begin());
    }
    
    return answer;
}