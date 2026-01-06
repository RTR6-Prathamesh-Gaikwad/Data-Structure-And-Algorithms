#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

typedef int status_t;
typedef int data_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
    int data;
    struct node* next;
};

list_t* create_list(void);

status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);

status_t pop_start(list_t* p_list, data_t* p_start);
status_t pop_end(list_t* p_list, data_t* p_end);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

status_t clear_data(list_t* p_list);

status_t is_list_empty(list_t* p_list);
status_t find_in_list(list_t* p_list, data_t f_data);
len_t get_list_length(list_t* p_list);

void show_list(list_t* p_list, const char* msg);
status_t destroy_list(list_t** pp_list);

static node_t* search_node(node_t* p_list, data_t new_data);
static node_t* get_node(data_t new_data);
status_t remove_all(list_t* p_list, data_t remove_data);

static void* xcalloc(size_t nr_elements, size_t size_per_element);

#endif
