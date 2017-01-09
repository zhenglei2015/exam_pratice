/*
ID:z3635362
LANG:C++
TASK:dualpal
*/

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

string converBase(int n, int base) {
    string num = "";
    for(int i = 0; n != 0; i++) {
        int k = n % base;
        n/=base;
        if(k < 10)
            num += (k + '0');
        else
            num += (k - 10 + 'A');
    }
    string res = "";
    for(int i = num.length() - 1; i >= 0; i--) {
        res += num[i];
    }
    return res;
}

bool isPar(string s) {
    for(int j = 0; j < s.length()/2; j++) {
        if(s[j] != s[s.length() - 1 - j]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s;
    scanf("%d%d", &n,&s);
    s++;
    int cnt = 0;
    while(cnt < n) {
        int parcnt = 0;
        for(int i = 2; i <= 10; i++) {
            string ss = converBase(s, i);
            if(isPar(ss)) {
                parcnt++;
                if(parcnt == 2)
                    break;
            }
        }
        if(parcnt >= 2) {
            cnt++;
            printf("%d\n", s);
        }
        s++;
    }
    return 0;
}
