#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int num[9];
const char* board[9];
int len[9] = {4, 3, 4, 3 ,5 ,3 ,4 ,3 ,4};

int main() {
  freopen("acm.in", "r", stdin);  
  for(int i = 0; i < 9; i++)
    scanf("%d", &num[i]);
  board[0] = "ABDE\0";
  board[1] = "ABC\0";
  board[2] = "BCEF\0";
  board[3] = "ADG\0";
  board[4] = "BDEFH\0";
  board[5] = "CFI\0";
  board[6] = "DEGH\0";
  board[7] = "GHI\0";
  board[8] = "EFHI\0";
  int res = 0x3f3f3f3f; 
  int result[9];
  for(int i = 0; i < (1 << 18); i++) {
    int temRes[9];
    int count[9];
    int tot = 0;
    for(int j = 0; j < 9; j++) {
      count[j] = 0;
      temRes[j] = 0;
    }
    for(int j = 0; j < 9; j++) { // 每一种
      int tc = 3 & (i >> (j * 2)); // 移动步数
      temRes[j] = tc;
      tot += tc;
      for(int k = 0 ; k < len[j]; k++) {
        count[board[j][k] - 'A'] += tc; // 每个种顺时针移动次数
      }
    }
    int flag = true;
    for(int j = 0; j < 9; j++) { // 每个钟显示
      if((num[j] + count[j]) % 4 != 0) {
        flag = false;
        break;
      }
    }
    if(flag) {
      if(tot < res) {
        for(int j = 0; j < 9 ; j++)
          result[j] = temRes[j];
        res = tot < res ? tot: res; 
      }
    }
  }
  for(int i = 0 ; i < 9; i++) {
    for(int j = 0; j < result[i]; j++)
      printf("%d ", i + 1);
  }
  return 0;
}
