/*
ID:z3635362
LANG:C++
TASK:transform
*/

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int n;
char origin[100][100];
char temp[100][100];
char target[100][100];

void rotate(char origin1[][100], char target1[][100]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0;j < n; j++) {
            target1[j][i] = origin1[i][j];
        }
    }
}
void reflectV(char origin1[][100], char target1[][100]) {
    int temp2[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp2[i][n - 1 - j] = origin1[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            target1[i][j] = temp2[i][j];
}


void reflectH(char origin1[][100], char target1[][100]) {
    int temp2[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp2[n - 1 - i][j] = origin1[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            target1[i][j] = temp2[i][j];
}


void r90(char origin[][100]) {
    char temp2[100][100];
    rotate(origin, temp2);
    reflectV(temp2, temp);
}

void r180(char origin[][100]) {
    char temp2[100][100];
    reflectH(origin, temp2);
    reflectV(temp2, temp);
}

void r270(char origin[][100]) {
    char temp2[100][100];
    rotate(origin, temp2);
    reflectH(temp2, temp);
}

bool isSame(char origin1[][100], char target1[][100]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(origin1[i][j] != target1[i][j])
                return false;
        }
    }
    return true;
}

void printfBoard(char b[][100]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        for(int j = 0; j < n; j++) {
            origin[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        for(int j = 0; j < n; j++) {
            target[i][j] = s[j];
        }
    }
    r90(origin);
    if(isSame(temp, target)) {
        printf("1\n");
        return 0;
    }
    r180(origin);
    //printfBoard(temp);
    if(isSame(temp, target)) {
        printf("2\n");
        return 0;
    }
    r270(origin);
    if(isSame(temp, target)) {
        printf("3\n");
        return 0;
    }
    reflectV(origin, temp);
    if(isSame(target, temp)) {
        printf("4\n");
        return 0;
    }
    char reflect[100][100];
    reflectV(origin, reflect);
    r90(reflect);
    if(isSame(target, temp)) {
        printf("5\n");
        return 0;
    }
    r180(reflect);
    if(isSame(target, temp)) {
        printf("5\n");
        return 0;
    }
    r270(reflect);
    if(isSame(target, temp)) {
        printf("5\n");
        return 0;
    }
    if(isSame(origin, target)) {
        printf("6\n");
        return 0;
    }
    printf("7\n");
    return 0;
}

