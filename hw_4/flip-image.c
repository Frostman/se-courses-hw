#include <stdio.h>
#include <stdlib.h>

typedef struct pixel_s {
  int r;
  int g;
  int b;
} pixel_t;

int main() {

  scanf("P3\n");

  int width, height, max_val, r, g, b;
  scanf("%d %d %d", &width, &height, &max_val);

  pixel_t ** array = (pixel_t **) malloc(height * sizeof(pixel_t *));
  pixel_t * p;
  for(int i = 0; i < height; i++) {
    array[i] = (pixel_t *) malloc(width * sizeof(pixel_t));
    
    for(int j = 0; j < width; j++) {
      p = &array[i][j];
      scanf("%d %d %d", &r, &g, &b);
      p->r = r;
      p->g = g;
      p->b = b;
    }
  }

  printf("P3\n%d %d\n%d\n", width, height, max_val);
  
  for(int i = height - 1; i >= 0; i--) {
    for(int j = 0; j < width; j++) {
      p = &array[i][j];
      printf("%d %d %d ", p->r, p->g, p->b); 
    }
    printf("\n");

    free(array[i]);
  }
  free(array);
  
  return EXIT_SUCCESS;
}

