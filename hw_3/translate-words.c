#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>

int main() {
  iconv_t cd = iconv_open("UTF-8", "KOI8-R");
  char in_buf[256], out_buf[1024];

  while(1 == scanf("%s ", &in_buf)){
    size_t in_size = strlen(in_buf);
    size_t out_size = sizeof(out_buf) - 1;
    const char * in = in_buf;
    char * out = out_buf;
    iconv(cd, &in, &in_size, &out, &out_size);
    *out = 0;
    printf("%s ", out_buf);
  }

  iconv_close(cd);
  
  return EXIT_SUCCESS;
}

