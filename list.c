#include<stdlib.h>
#include<stdio.h>
#include "list.h"

Status clear_list(List_ptr list) {
  int count = list->count;
  Node_ptr p_walk = list->head;
  Node_ptr element_to_free = NULL;
  while(p_walk != NULL) {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
  }
  list->count = 0;
  if(list->count == 0) return Success;
  return Failure;
};

Status remove_all_occurrences(List_ptr list, int value) {
  int count = list->count;
  int times = 0;
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    remove_num(list,value);
    p_walk = p_walk->next;
    times++;
  }
  if(count - times == list->count) return Success;
  return Failure;
};

void remove_num(List_ptr list, int num) {
  if(!is_num_present(list,num)) return;
  Node_ptr p_walk = list->head;
  Node_ptr prev_pos = NULL;
  if(list->head->value == num ) {
    list->head = list->head->next;
  } else {
    while(p_walk->value != num ) {
    prev_pos = p_walk;
    p_walk = p_walk->next;
  }
  prev_pos->next = p_walk->next;
  }
  list->count--;
}

Status remove_first_occurrence(List_ptr list, int num) {
  int count = list->count;
  remove_num(list,num);
  if(count - 1 == list->count) return Success;
  return Failure;
};

Status remove_at(List_ptr list, int position){
  int count = list->count;
  if(position > count) return Failure;
  Node_ptr p_walk = list->head;
  while(position != 2) {
    p_walk = p_walk->next;
    position--;
  }
  Node_ptr node_to_delete = p_walk->next;
  Node_ptr next_pos = node_to_delete->next;
  p_walk->next = next_pos;
  list->count--;
  if(count - 1 == list->count) return Success;
  return Failure;
};

Status remove_from_end(List_ptr list) {
  int count = list->count;
  Node_ptr p_walk = list->head;
  while(count != 2) {
    p_walk = p_walk->next;
    count--;
  }
  list->last = p_walk;
  list->last->next = NULL;
  list->count--;
  if(count - 1 == list->count) return Success;
  return Failure;
};

Status remove_from_start(List_ptr list) {
  int count = list->count;
  Node_ptr next_pos = list->head->next;
  list->head = next_pos;
  list->count--;
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