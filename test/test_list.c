#include <assert.h>
#include <stdio.h>
#include "../list.h"

void assert_remove_at(void) {
  printf("Remove_At\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_at(list,1));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("Passed\n");

  printf("should remove the num from valid position\n");
  add_to_end(list,5);
  add_to_end(list,10);
  add_to_end(list,15);
  assert(remove_at(list,1));
  assert(list->count == 2);
  assert(list->head->value == 5);
  printf("Passed\n");

  printf("should fail if invalid position is given\n");
  assert(!remove_at(list,5));
  assert(list->count == 2);
  printf("Passed\n");
};

void assert_remove_from_end(void) {
  printf("Remove_from_end\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_from_end(list));
  assert(list->count == 0);
  printf("Passed\n");

  printf("should remove num from last in the list\n");
  add_to_end(list,5);
  add_to_end(list,10);
  assert(remove_from_end(list));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);
  printf("Passed\n");
};

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


  printf("should remove first num from the list when more than one is present\n");
  add_to_end(list,5);
  add_to_end(list,10);
  assert(remove_from_start(list));
  assert(list->count == 1);
  assert(list->last->value == 10);
  assert(list->head->value == 10);
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
  assert_remove_from_end();
  assert_remove_at();
  return 0;
}

