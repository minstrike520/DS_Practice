#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct {
  int32_t value;
  void *next;
} int32_node_t;

void array_list_alloc(int32_node_t ***nodes, int32_t size) {
  *nodes = (int32_node_t **)malloc(size * sizeof(int32_node_t *));
  for (int32_t i = 0; i < size; i++) {
    (*nodes)[i] = NULL;
  }
}

void array_list_free(int32_node_t **nodes, int32_t size) {
  for (int32_t i = 0; i < size; i++) {
    free(nodes[i]);
  }
  free(nodes);
}

void adjacency_list_scan(int32_node_t **nodes) {
  int32_t a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    int32_node_t *new_node = malloc(sizeof(int32_node_t));
    new_node->value = b;
    new_node->next = nodes[a];
    nodes[a] = new_node;
  }
}

void adjacency_list_print(int32_node_t **nodes, int32_t size) {
  printf("\033[22;34m[GRAPH PRINT]\n");

  for (int32_t i = 0; i < size; i++) {
    for (int32_node_t *node = nodes[i]; node != NULL; node = node->next) {
      printf("%d -> %d\n", i, node->value);
    }
  }

  printf("\033[0m");
}

void matrix_alloc(int32_t ***matrix, int32_t size) {
  *matrix = (int32_t **)malloc(size * sizeof(int32_t *));
  for (int32_t i = 0; i < size; i++) {
    (*matrix)[i] = (int32_t *)calloc(size, sizeof(int32_t));
  }
}

void matrix_free(int32_t **matrix, int32_t size) {
  for (int32_t i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void weighted_adjacency_matrix_scan(int32_t **matrix) {
  int32_t a, b, w;
  while (scanf("%d %d %d", &a, &b, &w) != EOF) {
    matrix[a][b] = w;
  }
}

void weighted_adjacency_matrix_print(int32_t **matrix, int32_t size) {
  printf("\033[22;34m[GRAPH PRINT]\n");

  for (int32_t i = 0; i < size; i++) {
    for (int32_t j = 0; j < size; j++) {
      if (matrix[i][j] != 0) {
        printf("%d ->%d-> %d\n", i, matrix[i][j], j);
      }
    }
  }

  printf("\033[0m");
}

void test_array_list() {
  int32_t NODE_AMOUNT = 4;
  int32_node_t **nodes;
  array_list_alloc(&nodes, NODE_AMOUNT);

  adjacency_list_scan(nodes);
  adjacency_list_print(nodes, NODE_AMOUNT);

  array_list_free(nodes, NODE_AMOUNT);
  nodes = NULL;
}

void test_matrix() {
  int32_t NODE_AMOUNT = 5;
  int32_t **matrix;
  matrix_alloc(&matrix, NODE_AMOUNT);

  weighted_adjacency_matrix_scan(matrix);
  weighted_adjacency_matrix_print(matrix, NODE_AMOUNT);

  matrix_free(matrix, NODE_AMOUNT);
  matrix = NULL;
}

int main() {
  test_array_list();
  return 0;
}
