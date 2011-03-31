#include <stdio.h>
#include <stdlib.h>
#include <spelling.h>

int main() {
  char buf[1024];

  while(1 == scanf("%1023s", &buf)) {
    printf(">> %s\n", buf);
  }

  return EXIT_SUCCESS;
}

