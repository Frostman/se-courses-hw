#include <stdio.h>

int main() {
  int t, s, v;
  scanf("%d%d%d", &t, &s, &v);

  int d = s / v;

  if(d < t) {
    printf("download");
  } else if(d == t) {
    printf("equal");
  } else {
    printf("watch");
  }
  
  return 0;
}
