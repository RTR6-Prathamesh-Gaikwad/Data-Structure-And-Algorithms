#include"list.h"

int main(void)
{
    struct node* p_list = NULL;

    int status;
    int data, start_data, end_data;
    int length;

    static const char* line = "====================================================================";

    p_list = create_list();
    assert(p_list != NULL);
    printf("List created successfully\n");
    puts(line);

    printf("Testing assertions on the empty list\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are suuccessful\n");
    puts(line);

    show_list(p_list, "Showing empty list immediately after creation :");
    puts(line);

    for(data = 0; data < 5; data++)
    {
        status = insert_start(p_list, data* 10);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the start of the list\n", data* 10);
    }    

    show_list(p_list, "Showing list after inserting 5 data elemensts at the start:\n");
    puts(line);

    for(data = 1; data <= 5; data++)
    {
        status = insert_end(p_list, data* 5);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the end of the list\n", data* 5);
    }    

    show_list(p_list, "Showing list after inserting 5 data elemensts at the end:\n");
    puts(line);

    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non existent data -5\n");
    puts(line);

    status = insert_after(p_list, 0, 100);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting 100 after 0 :");

    status = insert_before(p_list, 43, 200);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 200 after non existent data 43\n");
    puts(line);
    
    status = insert_before(p_list, 0, 200);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting 200 after 0 :");
    puts(line);

    status = get_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("data at the start : %d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it");
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("data at the end : %d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that get_end() returns end data without removing it");
    puts(line);

    status = pop_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("data at the start : %d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns start data");
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("data at the end : %d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that pop_end() removes and returns end data ");
    puts(line);

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_start()");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_end()");
    puts(line);

    status = remove_data(p_list, 78);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected error in removing non existent data 78\n");
    puts(line);

    status = remove_data(p_list, 0);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after removeing existing data 0");

    status = find(p_list, 91);
    assert(status == FALSE);
    printf("Expected return FALSE from find() for on existent data 91\n");
    puts(line);

    status = find(p_list, 100);
    assert(status == TRUE);
    printf("expected return value TRUE from find() for existing data 100\n");
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Expected return value FALSE from is_list_empty()\n");
    puts(line);

    length = get_list_length(p_list);
    printf("Length of the list = %d\n", length);
    puts(line);

    status = destroy_list(p_list);
    assert(status == SUCCESS);
    p_list = NULL;
    printf("List is destroyed successfully\n");
    puts(line);

    return 0;
    
}