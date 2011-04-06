#include <stdio.h>
#include <stdlib.h>
#include <spelling.h>
#include <string.h>

int main() {
  char buf[1024];
  char prefix[1024];
  char suffix[1024];
  char replace[1024];

  while(1 == scanf("%1023s", &buf)) {
    int len = strlen(buf);
    printf("read: %s (%d)\n", buf, len);
  }

  return EXIT_SUCCESS;
}

