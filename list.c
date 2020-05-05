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
  Node_ptr p_walk = list->head;
  Node_ptr element_to_free = NULL;
  while(p_walk != NULL) {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
};

Status remove_all_occurrences(List_ptr list, int value) {
  int is_present = 1;
  while(is_present == 1) {
    is_present = remove_first_occurrence(list,value);   
  }
  return Success;
};

Status remove_first_occurrence(List_ptr list, int num) {
  if(!is_num_present(list,num)) return Failure;
  Node_ptr p_walk = list->head;
  int position = 1;
  while(p_walk != NULL) {
    if(p_walk->value == num) return remove_at(list,position);
    p_walk = p_walk->next;
    position++; 
  }
  return Failure;
};

Status remove_at(List_ptr list, int position){
  if(position > list->count || position < 0 ) return Failure;
  if(position == 0 ) return remove_from_start(list);
  Node_ptr p_walk = get_position(list,position);
  if(position + 1 == list->count) {
    list->last = p_walk;
    list->last->next = NULL;
  } else {
     Node_ptr next_pos = p_walk->next->next;
     p_walk->next = next_pos;
  }
  list->count--;
  return Success;
};

Status remove_from_end(List_ptr list) {
  return remove_at(list,list->count-1);
};

Status remove_from_start(List_ptr list) {
  if(list->count == 0) return Failure;
  if(list->count == 1) list->last = NULL;
  Node_ptr  new_head = list->head->next;
  free(list->head);
  list->head = new_head;
  list->count--;
  return Success;
};

int is_num_present(List_ptr list, int num) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    if(p_walk->value == num) return Success;
    p_walk = p_walk->next;
  }
  return Failure;
};

Status add_unique(List_ptr list, int value) {
  if(is_num_present(list,value)) return Failure;
  return insert_at(list,value,list->count);
};

Status add_to_start(List_ptr list, int value) {
  return insert_at(list,value,0);
};

Status add_to_end(List_ptr list, int value) { 
  return insert_at(list,value,list->count);
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
  if(list->count == position + 1) list->last = node;
};

Node_ptr get_position(List_ptr list, int position) {
  Node_ptr p_walk = list->head;
  int curr_pos = 1;
  while(curr_pos != position) {
    p_walk = p_walk->next;
    curr_pos++;
  }
  return p_walk;
};

Status insert_at(List_ptr list, int value, int position) {
  if(position > list->count || position < 0) return Failure;
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) {
    list->head = new_node;
    list->last = new_node;
    list->count++;
    return Success;
  }
  if(position == 0) {
    Node_ptr prev_head = list->head;
    list->head = new_node;
    new_node->next = prev_head;
    list->count++;
    return Success;
  }      
    Node_ptr p_walk = get_position(list,position);
    update_linked_list(p_walk,new_node,list,position);
    return Success;
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};