#include <stdio.h>
#include <stdint.h>

typedef struct {
  int a;
  int b;
} edge_t;

void edge_array_scan(edge_t edges[], int32_t size) {
  int i = 0;
  int a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    edges[i].a = a;
    edges[i].b = b;
    i++;
  }
}

void edge_array_print(edge_t edges[], int32_t size) {
  printf("\033[22;34m[GRAPH PRINT]\n");

  for (int32_t i = 0; i < size; i++) {
    printf("%d -> %d\n", edges[i].a, edges[i].b);
  }

  printf("\033[0m");
}

void test_edge() {
  #define EDGE_AMOUNT 4
  edge_t edges[EDGE_AMOUNT];
  edge_array_scan(edges, EDGE_AMOUNT);
  edge_array_print(edges, EDGE_AMOUNT);
}

int main() {
  test_edge();
  return 0;
}

// boolean operation priority: NOT > AND > OR
// NOT a AND b OR c = ( (NOT a) AND b ) OR c

