#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> v[24];

int getIndex(int a, int b, int c, int d) {
    return a * 8 + b * 4 + c * 2 + d;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (string i : info) {
        int a, b, c, d, score;
        istringstream iss(i);
        string str;
        
        iss >> str;
        if (str == "cpp") a = 0;
        else if (str == "java") a = 1;
        else a = 2;
        
        iss >> str;
        if (str == "backend") b = 0;
        else b = 1;
        
        iss >> str;
        if (str == "junior") c = 0;
        else c = 1;
        
        iss >> str;
        if (str == "chicken") d = 0;
        else d = 1;
        
        iss >> str;
        score = stoi(str);
        
        v[getIndex(a, b, c, d)].push_back(score);
    }
    
    for (int i = 0; i < 24; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    for (string q : query) {
        int score;
        vector<int> a, b, c, d;
        istringstream iss(q);
        string str;
        
        iss >> str;
        if (str == "cpp") a.push_back(0);
        else if (str == "java") a.push_back(1);
        else if (str == "python") a.push_back(2);
        else a = { 0, 1, 2 };
        iss >> str;

        iss >> str;
        if (str == "backend") b.push_back(0);
        else if (str == "frontend") b.push_back(1);
        else b = { 0, 1 };
        iss >> str;

        iss >> str;
        if (str == "junior") c.push_back(0);
        else if (str == "senior") c.push_back(1);
        else c = { 0, 1 };
        iss >> str;

        iss >> str;
        if (str == "chicken") d.push_back(0);
        else if (str == "pizza") d.push_back(1);
        else d = { 0, 1 };

        iss >> str;
        score = stoi(str);
        
        int cnt = 0;
        for (int aa : a) {
            for (int bb : b) {
                for (int cc : c) {
                    for (int dd : d) {
                        int i = getIndex(aa, bb, cc, dd);
                        auto it = lower_bound(v[i].begin(), v[i].end(), score);
                        cnt += v[i].end() - it;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}