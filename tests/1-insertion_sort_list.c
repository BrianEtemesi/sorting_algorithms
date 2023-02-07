#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a list of doubly linked lists in ascenidng order
 * @list: Doubly linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
    int flag, i = 0, n = 0, comparator, to_be_compared;
    listint_t *x, *y, *z, *temp = *list;

    /* Determine number of nodes or n */
    while (temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }
	temp = *list;

    /* Looping through the whole list of size (n) */
    for (i = 0; i < n; i ++)
    {
        printf("======= FOR LOOP [%d] ====\n \n", i);
		comparator = temp->n;
		printf("Compartor [%d]\n", comparator);
		
		if (temp->next == NULL)
		{
			printf("Cant assign");
			exit(1);
		}
        to_be_compared = temp->next->n;
        printf("To be compared [%d]\n", to_be_compared);

        printf("Comparing [%d] with [%d]\n", comparator, to_be_compared);

        /* Actual Comparison */
		while(temp)
        {
            printf("If [%d] < [%d]\n", to_be_compared, comparator);
            printf(" \n ===== Entering while =====\n \n");
            flag = 0;
            if (to_be_compared < comparator)
            {
                printf("[%d] is less than [%d]\n", to_be_compared, comparator);
                /* Storing Copies of the node addresses */
                x = temp->next;
                y = temp->next->next;
                z = temp->prev;

                /* Actual swapping */
                printf("\nInitial list ==== \n");
                print_list(*list);
                printf("==== \n");
				if (temp->next)
				{
					temp->next = y;
					if (y != NULL)
						y->prev = temp;
				}
                x->next = temp;
                x->prev = z;
				if (z != NULL)
					z->next = x;
                flag = 1;
                print_list(*list);
                printf("\n==== Completed Swapping ====\n");
                /* This logic allows temp to be automatically moved */
            }
            else
            {
                printf("[%d] is not less than [%d]\n", to_be_compared, comparator);
				temp = temp->next;
				break;
            }
			printf("Broken from loop with flag [%d]\n", flag);
        }
    }
    printf("\n ==== End of For Loop \n \n");

    /**
     Problem statement 
     Date: 05th February, 2023

    --> Segmentation Fault received at 6th Loop
    --> Not sure how many times the inner is supposed to run
    --> using while(temp) has proved innefective
    */
}