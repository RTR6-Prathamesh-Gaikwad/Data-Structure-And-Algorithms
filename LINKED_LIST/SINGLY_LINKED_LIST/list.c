#include"list.h"

struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    head_node->data = 0;
    head_node->next = NULL;
    
    return head_node;
}
// data addition functions
int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->next = p_list->next;
    p_list->next = new_node;

    return SUCCESS;
}

int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    run = p_list;
    while(run->next != NULL)
    {
        run = run->next;
    }

    run->next = new_node;

    return SUCCESS;
}
int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    run = p_list->next;
    while(run != NULL)
    {
        if(run->data == existing_data)
            break;
        run = run->next;
    }

    if(NULL == run)
        return LIST_DATA_NOT_FOUND;
    
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->next = existing_node->next;
    existing_node->next = new_node;

    return SUCCESS;
}
int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;
    struct node* new_node = NULL;

    run_previous = p_list;
    run = p_list->next;
    while(run != NULL)
    {
        if(run->data == existing_data)
            break;
        run_previous = run;
        run = run->next;
    }

    if(run == NULL)
        return LIST_DATA_NOT_FOUND;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    
    new_node->next = run;
    run_previous->next = new_node;

    return SUCCESS;

}

// get functions
int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == NULL)
        return LIST_EMPTY;
    *p_start_data = p_list->next->data;
    return SUCCESS;
}

int get_end(struct node* p_list, int* p_end_data)
{
    if(p_list->next == NULL)
        return LIST_EMPTY;
    struct node* run = NULL;

    run = p_list;
    while(run->next != NULL)
        run = run->next;
    
    *p_end_data = run->data;
    return SUCCESS;
}

// pop functions
int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list->next == NULL)
        return LIST_EMPTY;
    *p_start_data = p_list->next->data;

    delete_previous = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_previous->next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return SUCCESS;
}
int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list->next == NULL)
        return LIST_EMPTY;
    run_previous = p_list;
    run = p_list->next;

    while(run->next != NULL)
    {
        run_previous = run;
        run = run->next;
    }

    *p_end_data = run->data;

    free(run);
    run = NULL;
    run_previous->next = NULL;

    return SUCCESS;
}

// remove functions
int remove_start(struct node* p_list)
{
    if(p_list->next == NULL)
        return LIST_EMPTY;
    
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    delete_previous = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_previous->next = delete_next;
    free(delete_node);
    delete_node = NULL;

    return SUCCESS;
}
int remove_end(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list->next == NULL)
        return LIST_EMPTY;
    run_previous = p_list;
    run = p_list->next;
    while(run->next != NULL)
    {
        run_previous = run;
        run = run->next;
    }

    free(run);
    run = NULL;
    run_previous->next =NULL;

    return SUCCESS;
}
int remove_data(struct node* p_list, int r_data)
{
    struct node* run =NULL;
    struct node* run_previous = NULL;

    run_previous = p_list;
    run = p_list->next;
    while(run != NULL)
    {
        if(run->data == r_data)
            break;
        run_previous = run;
        run = run->next;
    }
    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    run_previous->next = run->next;
    free(run);
    run = NULL;
    return SUCCESS;
}

// miscallaneous function
int find(struct node* p_list, int f_data)
{
    struct node* run = NULL;

    run = p_list->next;
    while(run != NULL)
    {
        if(run->data == f_data)
            return TRUE;
        run = run->next;
    }
    return FALSE;
}
int get_list_length(struct node* p_list)
{
    int len = 0;
    struct node* run = NULL;
    run = p_list->next;
    while(run != NULL)
    {
        len = len + 1;
        run = run->next;
    }
    return len;
}
int is_list_empty(struct node* p_list)
{
    return (p_list->next == NULL);
}
void show_list(struct node* p_list, const char* msg)
{
    struct node* run = NULL;

    if(msg != NULL)
        puts(msg);
    
    printf("[START]-");
    run = p_list->next;
    while(run != NULL)
    {
        printf(">[%d]-", run->data);
        run = run->next;
    }
    printf(">[END]\n");
}

// list destruction function
int destroy_list(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;

    run = p_list;
    while(run != NULL)
    {
        run_next = run->next;
        free(run);
        run = NULL;
        run = run_next;
    }

    return SUCCESS;
}
