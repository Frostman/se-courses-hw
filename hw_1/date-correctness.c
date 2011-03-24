#include <stdio.h>

int main() {
  int d, m, y;
  scanf("%d%d%d", &d, &m, &y);

  if(m < 1 || m > 12) {
    printf("No");
    return 0;
  }

  if(y < 1900 || y > 2100) {
    printf("No");
    return 0;
  }

  if(d < 1) {
    printf("No");
    return 0;
  }

  int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
    days[2]++;
  }

  if(d > days[m]) {
    printf("No");
    return 0;
  }

  printf("Yes");
  
  return 0;
}
