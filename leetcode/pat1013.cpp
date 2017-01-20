#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;




bool isPrime(int n) {
    if(n == 1 || n == 0)
        return false;
    int sq = sqrt(n);
    for(int i = 2; i <= sq; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
string myreverse(string s) {
    string res = "";
    for(int i = s.size() - 1; i >= 0; i--) {
        res = res + s[i];
    }
    return res;
}
int to10(string s, int r) {
    int res = 0;
    int pw = 1;
    for(int i = 0; i < s.size(); i++) {
        res = res + (s[i] - '0') * pw;
        pw = pw * r;
    }
    return res;
}
string toRadix(int n, int r) {
    string s = "";
    while(n) {
        s = s + (char)(n % r + '0');
        n/=r;
    }
    return s;
}


int main() {
    int n, radix;
    freopen("acm.in", "r", stdin);
    while(scanf("%d", &n)) {
        if(n < 0)
            break;
        scanf("%d", &radix);
        if(!isPrime(n) || n == 1) {
            printf("No\n");
            continue;
        }
        string s = toRadix(n, radix);
        int num = to10(myreverse(s), radix);
        printf("%d xxx radix %d\n", num, radix);
        if(isPrime(num)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}