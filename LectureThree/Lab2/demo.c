#include <stdio.h>

int data_global_var = 0x12345678;
const char *text_string_literal = " Text_Segment";

void check_execution() {
  printf("~ executing text segment block ~\n");
}

int main() {
  printf("~ addresses: ~\n");
  printf("data (global initialized): %p\n", (void*)&data_global_var);
  printf("text string (rodata): %p\n", (void*)text_string_literal);
  printf("text code (function): %p\n", (void*)&check_execution);

  check_execution();
  // break-point
  printf("~ ready for segment inspection ~\n");

  return 0;
}
