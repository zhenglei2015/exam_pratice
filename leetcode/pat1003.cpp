#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


typedef struct edge{
    int from;
    int to;
    int cost;
    edge() {}
    edge(int a, int b, int c) {
        from = a;
        to = b;
        cost = c;
    }
}edge;

vector<edge> G;

int n, m;
int start1, end1;
int people[1000];
int len[1000];
int totPeople[1000];
int totPath[1000];

void dfs(int e) {
    if(totPath[e] != 0) {
        return ;
    }
    int tpath = 0;
    int tpeople = 0;
    for(int i = 0; i < G.size(); i++) {
        if(G[i].to == e) {
            if(len[G[i].from] + G[i].cost == len[e]) {
                dfs(G[i].from);
                tpath += totPath[G[i].from];
                tpeople = tpeople > totPeople[G[i].from] + people[G[i].to] ? tpeople : totPeople[G[i].from] + people[G[i].to];
            }
        }
    }
    totPath[e] = tpath;
    totPeople[e] = tpeople;
}

int main() {
    freopen("acm.in", "r", stdin);
    scanf("%d%d", &n,&m);
    scanf("%d%d", &start1, &end1);
    for(int i = 0; i < n; i++) {
        len[i] = 0x3f3f3f3f;
        totPeople[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &people[i]);
    }
    for(int i = 0; i < m; i++) {
        int f, t, c;
        scanf("%d%d%d", &f, &t, &c);
        G.push_back(edge(f, t, c));
        G.push_back(edge(t, f, c));
    }
    len[start1] = 0;
    totPeople[start1] = people[start1];
    totPath[start1] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < G.size(); j++) {
            edge e = G[j];
            if(len[e.from] + e.cost < len[e.to]) {
                len[e.to] = len[e.from] + e.cost;
            }
        }
    }
    dfs(end1);
    printf("%d %d", totPath[end1], totPeople[end1]);
    return 0;
}