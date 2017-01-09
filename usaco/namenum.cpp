/*
ID:z3635362
LANG:C++
TASK:namenum
*/

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

map<string, string> mp;
char tname[100];
int len;
vector<string> res;
string board[] = {"0", "0", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
int used[500];
vector<string> valid;

string getNum(string s) {
    string num = "";
    for(int i = 0; i < s.length(); i++) {
        for(int j = 2; j <= 9; j++) {
            for(int k = 0; k < 3; k++) {
                if(board[j][k] == s[i])
                    num += j + '0';
            }
        }
    }
    return num;
}

int main() {
    freopen("dict.txt", "r", stdin);
    while(scanf("%s", tname) != EOF) {
        string s = tname;
        mp[s] = getNum(s);
    }
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    scanf("%s", tname);
    string target = tname;
    map<string,string>::iterator  it;
    for(it = mp.begin(); it != mp.end(); it++) {
        if(it->second == target)
            res.push_back(it->first);
    }
    if(res.size() != 0) {
        for (int i = 0; i < res.size(); i++) {
            printf("%s\n", res[i].c_str());
        }
    } else {
        printf("NONE\n");
    }
    return 0;
}
