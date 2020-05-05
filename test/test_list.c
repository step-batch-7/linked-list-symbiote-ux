#include <assert.h>
#include <stdio.h>
#include "../list.h"

void assert_remove_from_start(void) {
  printf("Remove_From_Start\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_from_start(list));
  assert(list->count == 0);
  printf("Passed\n");
  
  printf("should remove first num from the list\n");
  add_to_end(list,5);
  assert(remove_from_start(list));
  assert(list->count == 0);
  assert(list->last == NULL);
  assert(list->head == NULL);
  printf("Passed\n");
};

void assert_add_to_end(void) {
  printf("Add_To_End\n");
  List_ptr list = create_list();
  printf("should add num to end when list is empty\n");
  assert(add_to_end(list,1));
  assert(list->last->value == 1);
  assert(list->count == 1);
  printf("Passsed\n");
};

int main(void) {
  printf("Test Starts\n");
  assert_add_to_end();
  assert_remove_from_start();
  return 0;
}

