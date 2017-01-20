#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef struct time1 {
    int h, m, s;
    time1(int a, int b, int c) {
        h=a, m=b, s=c;
    }
    time1(){}
}time1;

typedef struct man {
    string name;
    time1 come;
    time1 go;
}man;


bool compare(time1 a, time1 b) {
    if(a.h != b.h)
        return a.h < b.h;
    if(a.m != b. m)
        return a.m < b.m;
    if(a.s != b.s)
        return a.s < b.s;
    return false;
}

bool compareCome(man a, man b) {
    return compare(a.come, b.come);
}

bool compareGo(man a, man b) {
    return compare(a.go, b.go);
}
vector<man> V;
int main() {
    int n;
    freopen("acm.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char na[1000];
        time1 c, g;
        scanf("%s %d:%d:%d %d:%d:%d", na, &c.h, &c.m, &c.s, &g.h, &g.m, &g.s);
        man tm;
        tm.come = c;
        tm.go = g;
        tm.name = string(na);
        V.push_back(tm);
    }
    sort(V.begin(), V.end(), compareCome);
    printf("%s ", V[0].name.c_str());
    sort(V.begin(), V.end(), compareGo);
    printf("%s", V[V.size() - 1].name.c_str());
    return 0;
}