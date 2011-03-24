#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, x = 0, y = 0, tx, ty, ans = 0;
  scanf("%d", &n);
  
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &tx, &ty);
    ans += abs(x - tx);
    ans += abs(y - ty);
    x = tx;
    y = ty;
  }

  printf("%d", ans);
  
  return 0;
}
