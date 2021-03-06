#include <assert.h>
#include <stdio.h>
#include "../list.h"

void assert_remove_all_occurrence(void) {
  printf("Remove_All_Occurrence\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_all_occurrences(list,2));
  assert(list->head == NULL);
  printf("Passed\n");

  printf("should fail if num is not present in the list\n");
  add_to_end(list,1);
  add_to_end(list,2);
  assert(!remove_all_occurrences(list,4));
  assert(list->count == 2);
  printf("Passed\n");

   printf("should remove all occurrences of a num from the list\n");
  add_to_end(list,1);
  add_to_end(list,3);
  add_to_end(list,1);
  assert(remove_all_occurrences(list,1));
  assert(list->count == 2);
  assert(list->head->value == 2);
  assert(list->last->value == 3);
  printf("Passed\n");
};

void assert_remove_first_occurrence(void) {
  printf("Remove_First_Occurrence\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_all_occurrences(list,1));
  assert(list->count == 0);
  printf("Passed\n");

  printf("should fail if num is not present in the list\n");
  add_to_end(list,5);
  add_to_end(list,6);
  assert(!remove_all_occurrences(list,1));
  assert(list->count == 2);
  printf("Passed\n");

  printf("should remove the first occurrence of the num from the list\n");
  assert(remove_first_occurrence(list,6));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);
  printf("Passed\n");
};

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

void assert_is_num_present(void){
  printf("Is_num_Present \n");
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 6);
  add_to_end(list, 7);

  printf("Should give true if num is present\n");
  assert(is_num_present( list ,5));

  printf("Should give false if num is not present\n");
  assert(!is_num_present(list, 10 ));
  printf("Passed\n");
};

void assert_add_unique(void) {
  printf("Add_Unique\n");
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 6);
  add_to_end(list, 7);
  printf("Should add num at last if num is not present\n");
  assert(add_unique(list, 8));
  assert(list->count == 4);
  assert(list->last->value == 8);

  printf("Should not add num at last if num is not present\n");
  assert(!add_unique(list, 5));
  assert(list->count == 4);
  assert(list->last->value == 8);
  printf("Passed\n");
}

void assert_insert_at(void) {
  printf("Insert_At\n");
  List_ptr list = create_list();
  printf("Should insert at zero position of list when list  is empty\n");
  assert(insert_at(list, 5 , 0));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);

  printf("Should insert at middle of the list \n");
  add_to_end(list, 6);
  add_to_end(list, 7);
  assert(insert_at(list, 4, 1)); 
  assert(list->count == 4);
  assert(list->head->next->value == 4);

  printf("Should insert at last of the list \n");
  assert(insert_at(list, 5 , 4));
  assert(list->count == 5);
  assert(list->last->value == 5);
   
  printf("Should not insert at invalid position\n");
  assert(!insert_at(list, 5 , 10));
  assert(list->count == 5);
  printf("Passed\n");
};

void assert_add_to_start(void) {
  printf("Add_To_Start \n");
  List_ptr list = create_list();
  
  printf("Should add number to start when list is empty\n");
  assert(add_to_start(list , 5));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);

  printf("Should add the number when list is not empty\n");
  add_to_start(list, 5);
  add_to_start(list, 6);
  assert(add_to_start(list, 4));
  assert(list->head->value == 4);
  assert(list->count == 4);
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
  assert_add_to_start();
  assert_insert_at();
  assert_add_unique();
  assert_is_num_present();
  assert_remove_from_end();
  assert_remove_from_start();
  assert_remove_at();
  assert_remove_first_occurrence();
  assert_remove_all_occurrence();
  return 0;
}

