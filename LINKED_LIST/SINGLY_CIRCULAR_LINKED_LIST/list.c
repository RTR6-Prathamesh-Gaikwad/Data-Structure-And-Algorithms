#include"list.h"

list_t* create_list(void)
{
    list_t* new_list = NULL;

    new_list = get_node(0);
    new_list->next = new_list;

    return new_list;
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    node_t* new_node = get_node(new_data);
    new_node->next = p_list->next;
    p_list->next = new_node;

    return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    node_t* new_node = get_node(new_data);
    node_t* run = NULL;
    new_node->next = p_list->next;
    
    run = p_list;
    while(run->next != p_list)
    {
        run = run->next;
    }

    new_node->next = p_list;
    run->next = new_node;

    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* new_node = NULL;
    node_t* run = NULL;

    new_node = get_node(new_data);
    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == e_data)
            break;
        run = run->next;
    }

    if(run == p_list)
        return LIST_DATA_NOT_FOUND;
    
    new_node->next = run->next;
    run->next = new_node;

    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* new_node = NULL;
    node_t* run_prev = NULL;
    node_t* run = NULL;

    new_node = get_node(new_data);
    
    run_prev = p_list;
    run = p_list->next;

    while(run != p_list)
    {
        if(run->data == e_data)
            break;
        run_prev = run;
        run = run->next;
    }
    if(run  == p_list)
    {
        return LIST_DATA_NOT_FOUND;
    }

    new_node->next = run;
    run_prev->next = new_node;

    return SUCCESS;
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    
    *p_start_data = p_list->next->data;
    return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    
    node_t* run = NULL;
    run = p_list->next;
    while(run->next != p_list)
        run = run->next;
    
    *p_end_data = run->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    node_t* pop_node;
    
    *p_start = p_list->next->data;
    pop_node = p_list->next;
    p_list->next = p_list->next->next;

    free(pop_node);
    pop_node = NULL;

    return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* p_end)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    node_t* run = NULL;
    node_t* run_prev = NULL;

    run_prev = p_list;
    run = p_list->next;
    while(run->next != p_list){
        run_prev = run;
        run = run->next;
    }
    
    *p_end = run->data;
    run_prev->next = p_list;
    free(run);
    run = NULL;

    return SUCCESS;
}

status_t remove_start(list_t* p_list)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    node_t* remove_node;
    
    remove_node = p_list->next;
    p_list->next = p_list->next->next;

    free(remove_node);
    remove_node = NULL;

    return SUCCESS;
}

status_t remove_end(list_t* p_list)
{
    if(p_list->next == p_list)
        return LIST_EMPTY;
    node_t* run = NULL;
    node_t* run_prev = NULL;

    run_prev = p_list;
    run = p_list->next;
    while(run->next != p_list){
        run_prev = run;
        run = run->next;
    }
    
    run_prev->next = p_list;
    free(run);
    run = NULL;

    return SUCCESS;
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* run = NULL;
    node_t* run_prev = NULL;

    run_prev = p_list;
    run = p_list->next;

    while(run != p_list)
    {
        if(run->data == r_data)
            break;
        run_prev = run;
        run = run->next;
    }

    if(run == p_list)
        return LIST_DATA_NOT_FOUND;
    
    run_prev->next = run->next;
    free(run);
    run = NULL;

    return SUCCESS;
}

status_t clear_data(list_t* p_list)
{
    while(p_list->next != p_list)
    {
        remove_start(p_list);
    }

    return SUCCESS;
}

status_t is_list_empty(list_t* p_list)
{
    if(p_list->next == p_list)
        return TRUE;
    return FALSE;
}

status_t find_in_list(list_t* p_list, data_t f_data)
{
    node_t* run = NULL;
    run = p_list->next;
    while(run != p_list)
    {
        if(run->data == f_data)
            return TRUE;
        run = run->next;
    }

    return FALSE;
}

len_t get_list_length(list_t* p_list)
{
    int len = 0;
    node_t* run = p_list->next;
    while(run != p_list)
    {
        len++;
        run = run->next;
    }

    return len;
}

void show_list(list_t* p_list, const char* msg)
{
    node_t* run = p_list->next;

    puts(msg);
    printf("[START]->");
    
    while(run != p_list)
    {
        printf("[%d]->", run->data);
        run = run->next;
    }
    printf("[END]\n");
}

status_t destroy_list(list_t** pp_list)
{
    node_t* p_list = *pp_list;
    node_t* run = p_list->next;
    node_t* run_next = NULL;
    while(run != p_list)
    {
        run_next = run->next;
        free(run);
        run = run_next;
    }

    free(p_list);
    p_list = NULL;
    *pp_list = NULL;

    return SUCCESS;
}

static node_t* search_node(node_t* p_list, data_t new_data)
{
    node_t* run = p_list->next;
    while(run != p_list)
    {
        if(run->data == new_data)
            return run;
        run = run->next;
    }

    return NULL;
}

static node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL;
    new_node = (node_t*)xcalloc(1, sizeof(node_t));
    new_node->data = new_data;
    new_node->next;

    return new_node;
}

status_t remove_all(list_t* p_list, data_t remove_data)
{
    node_t* run = p_list->next;
    node_t* run_prev = p_list;
    while(run != p_list)
    {
        if(run->data == remove_data)
        {   
            run_prev->next = run->next;
            free(run);
            run = run_prev->next;
            continue;
        }
        run_prev = run;
        run = run->next;
    }

    return SUCCESS;
}

static void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void * p = NULL;
    p = calloc(nr_elements, size_per_element);
    if(NULL == p)
    {
        fprintf(stderr, "Faatal error: memory not allocated\n");
        exit(EXIT_FAILURE);
    }

    return p;
}