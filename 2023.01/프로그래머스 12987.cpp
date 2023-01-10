#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end()); sort(B.begin(), B.end());
     
    int indexB = 0;
    for (int indexA = 0; indexA < A.size() && indexB < B.size();) {
        if (A[indexA] < B[indexB]) { // B가 클 때
            answer++;
            indexA++; indexB++;
        }
        else if (A[indexA] > B[indexB]) { // A가 클 때
            indexB++;
        }
        else { // 무승부
            indexB++;
        }
    }
    
    return answer;
}