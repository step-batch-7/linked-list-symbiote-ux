#include<stdlib.h>
#include<stdio.h>
#include "list.h"

Status add_to_end(List_ptr list, int value) {
  int count = list->count;
  insert_value(list,value);
  if(count + 1 == list->count) return Success;
  return Failure;
};

Node_ptr create_node(int value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node; 
} 

void insert_value(List_ptr list, int value) {
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) list->head = new_node;
  else list->last->next = new_node;
  list->last = new_node;
  list->count++;
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};