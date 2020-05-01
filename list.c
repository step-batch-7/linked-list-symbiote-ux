#include<stdlib.h>
#include<stdio.h>
#include "list.h"

Status insert_at(List_ptr list, int value, int position) {
  int count = list->count;
  position = position <= count ? position : count + 1;
  insert_value(list,value,position);
  if(count + 1 == list->count) return Success;
  return Failure;
};

Status add_to_start(List_ptr list, int value) {
  int count = list->count;
  insert_value(list,value,1);
  if(count + 1 == list->count) return Success;
  return Failure;
};

Status add_to_end(List_ptr list, int value) {
  int count = list->count;
  insert_value(list,value,count+1);
  if(count + 1 == list->count) return Success;
  return Failure;
};

Node_ptr create_node(int value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node; 
};

void insert_value(List_ptr list, int value, int position) {
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) {
    list->head = new_node;
    list->last = new_node;
    list->count++;
    return;
  }
  if(list->head != NULL && position == 1) {
    Node_ptr new_head = list->head;
    list->head = new_node;
    new_node->next = new_head;
    list->count++;
    return;
  }
  Node_ptr p_walk = list->head;
  int curr_pos = 1;
  while(curr_pos != position-1) {
    p_walk = p_walk->next;
    curr_pos++;
  }
  Node_ptr new_pos = p_walk->next;
  p_walk->next = new_node;
  new_node->next = new_pos;
  list->count++;
  if(list->count == position) list->last = new_node;
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};