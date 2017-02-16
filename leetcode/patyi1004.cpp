#include <stdio.h>
#include <stdlib.h>

typedef struct man{
    char name[1000];
    char cls[1000];
    int score;
}man;

man student[10000];

int cmp(const void *a, const void *b) {
    int s1 = (*(man *)a).score;
    int s2 = (*(man *)b).score;
    return s1 > s2;
}

int main() {
    freopen("acm.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s%s%d", &student[i].name, &student[i].cls, &student[i].score);
    }
    qsort(student, n, sizeof(man), cmp);
    printf("%s %s\n%s %s", student[n - 1].name, student[n - 1].cls, student[0].name, student[0].cls);
    return 0;
}
