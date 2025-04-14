#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int n, m, top, bottom;
    vector<vector<int>> answer;
    deque<int> left, right;
    deque<deque<int>> mid;
    
    n = rc.size();
    m = rc[0].size();
    mid = deque<deque<int>>(n , deque<int>());
    for (int i = 0; i < n; i++) {
        left.push_back(rc[i][0]);
        for (int j = 1; j < m - 1; j++) mid[i].push_back(rc[i][j]);
        right.push_back(rc[i][m - 1]);
    }
    
    m = mid[0].size();
    top = 0;
    bottom = n - 1;
    for (string operation : operations) {
        if (operation == "ShiftRow") {
            top = (top + n - 1) % n;
            bottom = (bottom + n - 1) % n;
        }
        else {
            mid[top].push_front(left[top]);
            mid[bottom].push_back(right[bottom]);
            
            left[top] = mid[bottom].front();
            mid[bottom].pop_front();
            
            left.push_back(left.front());
            left.pop_front();
            
            right[bottom] = mid[top].back();
            mid[top].pop_back();
            
            right.push_front(right.back());
            right.pop_back();
        }
    }
    
    answer = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int ni = (top + i) % n;
        answer[i].push_back(left[ni]);
        for (int j = 0; j < m; j++) answer[i].push_back(mid[ni][j]);
        answer[i].push_back(right[ni]);
    }
    
    return answer;
}