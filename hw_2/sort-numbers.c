#include <stdio.h>
#include <stdlib.h>
  
int compare(const void * va, const void * vb) {
  int a = *(int *) va;
  int b = *(int *) vb;

  if (a > b) {
    return 1;
  } else if(a == b) {
    return 0;
  }
  
  return -1;
}

int main() {
  int arr[1024];
  int t, i, n = 0;

  while(n < 1024 && 1 == scanf("%d", &t)) {
    arr[n++] = t;
  }

  //printf("%d\n", n);
  //for(i = 0; i < n; i++) {
  //  printf("%d ", arr[i]);
  //}
  //printf("\n");
  
  qsort(arr, n, sizeof(int), compare);

  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return EXIT_SUCCESS;
}

