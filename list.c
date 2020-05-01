#include<stdlib.h>
#include<stdio.h>
#include "list.h"

Status remove_from_start(List_ptr list) {
  int count = list->count;
  Node_ptr next_pos = list->head->next;
  list->head = next_pos;
  if(count - 1 == list->count) return Success;
  return Failure;
};

int is_num_present(List_ptr list, int num) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    if(p_walk->value == num) return 1;
    p_walk = p_walk->next;
  }
  return 0;
};

Status add_unique(List_ptr list, int value) {
  int count = list->count;
  if(!is_num_present(list,value)) {
  insert_value(list,value,count + 1);
  if(count + 1 == list->count) return Success;
  return Failure;
  }
  if(count == list->count) return Success;
  return Failure;
};

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
  insert_value(list,value,count + 1);
  if(count + 1 == list->count) return Success;
  return Failure;
};

Node_ptr create_node(int value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node; 
};

void update_linked_list(Node_ptr p_walk,Node_ptr node,List_ptr list,int position) {
  Node_ptr next_pos = p_walk->next;
  p_walk->next = node;
  node->next = next_pos;
  list->count++;
  if(list->count == position) list->last = node;
};

Node_ptr get_position_to_insert(List_ptr list, int position) {
  Node_ptr p_walk = list->head;
  int curr_pos = 1;
  while(curr_pos != position-1) {
    p_walk = p_walk->next;
    curr_pos++;
  }
  return p_walk;
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
  } 
  else {
    Node_ptr p_walk = get_position_to_insert(list,position);
    update_linked_list(p_walk,new_node,list,position);
  }
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};