#include<stdlib.h>
#include<stdio.h>
#include "list.h"

void destroy_list(List_ptr list) {
  clear_list(list);
  free(list);
};

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    printf("%d \n",p_walk->value);
    p_walk = p_walk->next;
  }
};

Status clear_list(List_ptr list) {
  int count = list->count;
  Node_ptr p_walk = list->head;
  Node_ptr element_to_free = NULL;
  while(p_walk != NULL) {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
    list->count--;
  }
  list->head = NULL;
  list->last = NULL;
  Status code = list->count == 0 ? Success : Failure;
  return code;
};

Status remove_all_occurrences(List_ptr list, int value) {
  if(!is_num_present(list,value)) return Failure;
  int count = list->count;
  int times = 0;
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    remove_num(list,value);
    p_walk = p_walk->next;
    times++;
  }
  Status code = count - times == list->count ? Success : Failure;
  return code;
};

void remove_num(List_ptr list, int num) {
  Node_ptr p_walk = list->head;
  Node_ptr prev_pos = NULL;
  if(list->head->value == num ) list->head = list->head->next;
  else {
    while(p_walk->value != num ) {
    prev_pos = p_walk;
    p_walk = p_walk->next;
  }
  prev_pos->next = p_walk->next;
  }
  list->count--;
}

Status remove_first_occurrence(List_ptr list, int num) {
  if(!is_num_present(list,num)) return Failure;
  int count = list->count;
  remove_num(list,num);
  Status code = count - 1 == list->count ? Success : Failure;
  return code;
};

Node_ptr get_num(List_ptr list, int position) {
  Node_ptr p_walk = list->head;
  while(position > 1) {
    p_walk = p_walk->next;
    position--;
    }
    return p_walk;
};

Status remove_at(List_ptr list, int position){
  int count = list->count;
  if(position > count) return Failure;
  if(position == 1) list->head = list->head->next;
  else {
    Node_ptr p_walk = get_num(list,position-1);
    Node_ptr next_pos = p_walk->next->next;
    p_walk->next = next_pos;
  }
  list->count--;
  Status code = count - 1 == list->count ? Success : Failure;
  return code;
};

Status remove_from_end(List_ptr list) {
  return remove_at(list,list->count);
};

Status remove_from_start(List_ptr list) {
  int count = list->count;
  if(!count) return Failure;
  list->head = list->head->next;
  list->count--;
  Status code = count - 1 == list->count ? Success : Failure;
  return code;
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
  if(is_num_present(list,value)) return Failure;
  return insert_at(list,value,list->count+1);
};

Status insert_at(List_ptr list, int value, int position) {
  int count = list->count;
  position = position <= count ? position : count + 1;
  insert_value(list,value,position);
  Status code = count + 1 == list->count ? Success : Failure;
  return code;
};

Status add_to_start(List_ptr list, int value) {
  return insert_at(list,value,1);
};

Status add_to_end(List_ptr list, int value) {
  return insert_at(list,value,list->count+1);
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

    Node_ptr prev_head = list->head;
    list->head = new_node;
    new_node->next = prev_head;
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