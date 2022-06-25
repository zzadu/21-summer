#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string no = "~!@#$%^&*()=+[{]}:?,<>/";
    
    for (int i = 0; i < new_id.length(); i++) {
        if (isalpha(new_id[i]) && isupper(new_id[i])) {
            new_id[i] = tolower(new_id[i]); // 소문자 치환
        }
        if (no.find(new_id[i]) != string::npos) {
            new_id.replace(new_id.find(new_id[i]), sizeof(new_id[i]), ""); // 특수문자 제거
            i--;
        }
    }
    
    // 마침표 2개 이상 제거
    string dot = ".";
    for (int i = 0; i < new_id.length(); i++) {
        dot += ".";
    }
    
    while (dot != ".") {
        if (new_id.find(dot) != string::npos) {
            while (new_id.find(dot) != string::npos) {
                new_id.replace(new_id.find(dot), dot.length(), ".");
            }
        }
        dot = dot.substr(1);
    }
    
    // 맨 처음 마침표 제거
    if (new_id[0] == '.') {
        new_id = new_id.substr(1);
    }
    
    // 마지막 마침표 제거
    if (new_id[new_id.length() - 1] == '.') {
        new_id = new_id.substr(0, new_id.length() - 1);
    }
    
    // 공백 처리
    if (new_id.empty()) {
        new_id = "a";
    }
    
    // 길이 제한
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        
        // 마지막 마침표 제거
        if (new_id[new_id.length() - 1] == '.') {
        new_id = new_id.substr(0, new_id.length() - 1);
        }
    }
    
    // 길이 늘이기
    while (new_id.length() <= 2) {
        new_id += new_id[new_id.length() - 1];
    }
    
    return answer = new_id;
}