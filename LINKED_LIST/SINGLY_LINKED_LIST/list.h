#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);

// data addition functions
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

// get functions
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

// pop functions
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

// remove functions
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

// miscallaneous function
int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);
void show_list(struct node* p_list, const char* msg);

// list destruction function
int destroy_list(struct node* p_list);


