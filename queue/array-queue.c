#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_LENGTH 10000

typedef struct {
  int32_t array[STACK_MAX_LENGTH];
  int32_t tail;
} queue_t;

int32_t queue_init(queue_t* self) {
  self->tail = -1;
  return 0;
}

int32_t queue_enqueue(queue_t* self, int32_t value) {
  self->tail++;
  self->array[self->tail] = value;
  return 0;
}

int32_t queue_dequeue(queue_t* self, int32_t* returns) {
  if (self->tail == -1) {
    return -1;
  }
  *returns = self->array[0];

  for (int32_t i = 0; i < self->tail; i++) {
    self->array[i] = self->array[i + 1];
  }
  self->tail--;
  return 0;
}

int32_t queue_debug(queue_t* self) {
  printf("[DEBUG: queue]\n");

  //for (int32_t i = self->tail; i > -1; i--) {
  for (int32_t i = 0; i < self->tail + 1; i++) {
    printf("[%d]: %d\n", i, self->array[i]);
  }
  return 0;
}

int main() {
  queue_t* a = malloc(sizeof(queue_t));
  queue_init(a);
  queue_enqueue(a, 10);
  queue_enqueue(a, 4);
  queue_enqueue(a, 2);
  queue_enqueue(a, 3);
  queue_enqueue(a, 5);
  queue_enqueue(a, 7);
  queue_debug(a);

  int32_t b;
  queue_dequeue(a, &b);
  printf("%d\n", b);
  queue_debug(a);
}
