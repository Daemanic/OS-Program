#include <stdio.h>
#include <stdlib.h>

int bss_global_var;

int main() {
  int stack_local_var = 42;
  int *heap_ptr = (int *)malloc(sizeof(int));
  if (heap_ptr == NULL) {
    return 1;
  }
  *heap_ptr = 99;
  printf("~ mapping addresses ~\n");
  printf("bss (global): %p\n", (void*)&bss_global_var);
  printf("stack (local): %p\n", (void*)&stack_local_var);
  printf("heap (dynamic): %p\n", (void*)heap_ptr);
  // break-point
  printf("~ ready for GDB inspection ~\n");
  free(heap_ptr);
  
  return 0;
}
