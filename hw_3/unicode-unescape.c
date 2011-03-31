#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>

int main() {
  int slash = 0;
  char c, buf[32];
   
  iconv_t cd = iconv_open("UTF-8", "UTF-32LE");
  while(1) {
    if(1 != scanf("%c", &c)) {
      break;
    }

    if(c != '\\') {
      if(slash == 1 && (c == 'u' || c == 'U')) {
        slash = 0;
        
        scanf("%6c", &buf);
        unsigned long int t = strtoul(buf, NULL, 16);
        const char * in = (char *)&t;
        char * out = buf;
        size_t in_size = 4;
        size_t out_size = sizeof (buf) - 1;
        iconv(cd, &in, &in_size, &out, &out_size);
        *out = 0;
        printf("%s", buf);
      } else {    
        printf("%c", c);
        slash = 0;
      }
    } else {
      slash++;
    }
  }

  iconv_close(cd);

  return EXIT_SUCCESS;
}

