#include<stdio.h>
#include "list.h"

void display_menu() {
  printf("Main Menu\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");
  printf("Please enter the alphabet of the operation you would like to perform\n");
};

int main(void) {
  char ch;
  int value,position;
  List_ptr list = create_list();
  display_menu();
  ch = getchar();
  while(ch != 'm') {
    switch (ch){
    case 'a':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",add_to_end(list,value));
      break;
    case 'b':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",add_to_start(list,value));
      break;
    case 'c':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("Enter position\n");
    scanf("%d",&position);
    printf("%d\n",insert_at(list,value,position));
      break;
    case 'd':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",add_unique(list,value));
      break;
    case 'e':
    printf("%d\n",remove_from_start(list));
      break;
    case 'f':
    printf("%d\n",remove_from_end(list));
      break;
    case 'g':
    printf("Enter a position\n");
    scanf("%d",&position);
    printf("%d\n",remove_at(list,position));
      break;
    case 'h':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",remove_first_occurrence(list,value));
      break;
    case 'i':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",remove_all_occurrences(list,value));
      break;
    case 'j':
    printf("%d\n",clear_list(list));
      break;
    case 'k':
    printf("Enter a number\n");
    scanf("%d",&value);
    printf("%d\n",is_num_present(list,value));
      break;
    case 'l':
    display(list);
      break;  
    }
    display_menu();    
    while((getchar()) != '\n');
    ch = getchar();
  }
  destroy_list(list);
  return 0;
};