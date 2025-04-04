#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define N 51

int parents[N * N];
string values[N * N];

int getParents(int x) {
    if (parents[x] == x) return x;
    else return parents[x] = getParents(parents[x]);
}

void update1(int r, int c, string value) {
    int k = r * 50 + c;
    
    values[getParents(k)] = value;
}

void update2(string value1, string value2) {
    for (int i = 1; i < N * N; i++) {
        if (values[i] == value1) values[i] = value2;
    }
}

void merge(int r1, int c1, int r2, int c2) {
    int a = getParents(r1 * 50 + c1);
    int b = getParents(r2 * 50 + c2);
    
    if (a == b) return;
    if (values[a] == "" && values[b] != "") parents[a] = b;
    else parents[b] = a;
}

void unmerge(int r, int c) {
    int k = r * 50 + c;
    int chk = getParents(k);
    string value = values[chk];
    vector<int> v;
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int k = i * 50 + j;
            if (getParents(k) == chk) v.push_back(k);
        }
    }
    for (int cur : v) {
        parents[cur] = cur;
        values[cur] = "";
    }
    values[k] = value;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i < N * N; i++) parents[i] = i;
    
    for (string command: commands) {
        istringstream iss(command);
        vector<string> tokens;
        string token;
        
        while (iss >> token) tokens.push_back(token);
        
        if (tokens[0] == "UPDATE") {
            if (tokens.size() == 4) update1(stoi(tokens[1]), stoi(tokens[2]), tokens[3]);
            else update2(tokens[1], tokens[2]);
        }
        else if (tokens[0] == "MERGE") {
            merge(stoi(tokens[1]), stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]));
        }
        else if (tokens[0] == "UNMERGE") {
            unmerge(stoi(tokens[1]), stoi(tokens[2]));
        }
        else {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            int k = r * 50 + c;
            
            if (values[getParents(k)] == "") answer.push_back("EMPTY");
            else answer.push_back(values[getParents(k)]);
        }
/*
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5 ; j++) {
                printf("%s ", values[getParents(i * 50 + j)].c_str());
            }
            printf("\n");
        }
        printf("\n");*/
    }
    
    return answer;
}