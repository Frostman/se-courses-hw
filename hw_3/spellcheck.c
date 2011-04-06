#include <stdio.h>
#include <stdlib.h>
#include <spelling.h>
#include <string.h>

int main() {
  char buf[1024];
  char word[1024];
  char prefix[1024];
  char suffix[1024];
  char insert[1024];
  char correct[1024];
  char rem_chars[1024];

  prefix[0] = 0;
  suffix[0] = 0;
  insert[0] = 0;
  correct[0] = 0;
  rem_chars[0] = 0;

  while(1 == scanf("%1023s", &buf)) {
    int len = strlen(buf);

    if(buf[0] == '$') {
      strcpy(suffix, buf + 1);
      //printf("suffix: %s\n", suffix);
    } else if(buf[0] == '&') {
      strcpy(prefix, buf + 1);
      //printf("prefix: %s\n", prefix);
    } else if(buf[0] == '.') {
      strcpy(insert, buf + 1);
      //printf("insert: %s\n", insert);
    } else if(buf[0] == '-') {
      strcpy(correct, buf + 1);
      //printf("correct: %s\n", correct);
    } else if(buf[0] == '!') {
      strcpy(rem_chars, buf + 1);
      //printf("rem_chars: %s\n", rem_chars);
    } else {
      //printf("read: %s ; ", buf);
      
      word[0] = 0;
      int shift = 0, add_suffix = 0;
      if(buf[0] == '^') {
        strcat(word, prefix);
        shift = 1;
      }
      if(buf[len - 1] == '$') {
        buf[len - 1] = 0;
        add_suffix = 1;
      }
      strcat(word, buf + shift);

      if(1 == add_suffix) {
        strcat(word, suffix);
      }

      char * dot_idx = strchr(word, '.');

      if (NULL != dot_idx) {
        shift = dot_idx - word + 1;
        strcpy(buf, word);
        *(buf + shift - 1) = 0;
        word[0] = 0;
        strcat(word, buf);
        strcat(word, insert);
        strcat(word, buf + shift);
      }

      for(;;) {
        char * bad_idx = strpbrk(word, rem_chars);
        if(NULL == bad_idx) {
          break;
        }
        shift = bad_idx - word + 1;
        strcpy(buf, word);
        *(buf + shift - 1) = 0;
        word[0] = 0;
        strcat(word, buf);
        strcat(word, buf + shift);
      }
      
      //printf("check: %s\n", word);

      if(0 == strcmp(correct, word) || is_spelled_correctly(word)){
        printf("%s: correct\n", word);
      } else {
        printf("%s: incorrect\n", word);
      }
    }
  }

  return EXIT_SUCCESS;
}

