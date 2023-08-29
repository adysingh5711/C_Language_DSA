#include <stdio.h>
#include <stdlib.h>
struct node
{

	int data;
	struct node *next;
};
struct node *create();
struct node *sort(struct node *start)
{
	struct node *ptr1 = start, *ptr2 = start;
	for (ptr1 = start; ptr1 != NULL; ptr1 = ptr1->next)
	{
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
		{
			if (ptr2->data < ptr1->data)
			{
				int temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
		}
	}
	return start;
}
struct node *insert_f(struct node *start, int num)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	struct node *ptr;
	ptr = start;
	start = new_node;
	new_node->next = ptr;
	return start;
}
struct node *insert_e(struct node *start, int num)
{
	struct node *ptr = start;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new_node;
	new_node->next = NULL;
	return start;
}
struct node *delete_b(struct node *start)
{
	struct node *ptr = start;
	start = ptr->next;
	free(ptr);
	return start;
}
struct node *delete_e(struct node *start)
{
	struct node *ptr = start;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	ptr->next = NULL;
	return start;
}
struct node *insert_after(struct node *start, int num, int n)
{

	struct node *ptr = start;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while (ptr->data != n)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;
	return start;
}
struct node *insert_before(struct node *start, int num, int n)
{
	struct node *ptr = start, *prev = NULL;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while (ptr->next->data != n)
	{

		ptr = ptr->next;
	}
	struct node *temp = ptr->next;
	ptr->next = new_node;
	new_node->next = temp;

	return start;
}

struct node *delete_num(struct node *start, int n)
{
	struct node *ptr = start;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	while (ptr->next->data != n)
		ptr = ptr->next;
	ptr->next = ptr->next->next;
	return start;
}
struct node *delete_all(struct node *start)
{
	struct node *ptr = start, *prev;
	while (ptr->next != NULL)
	{
		prev = ptr;

		ptr = ptr->next;
		free(prev);
	}
	start = NULL;
	free(ptr);
	return start;
}
int main()
{
	struct node *start, *ptr;
	int n;
	start = (struct node *)create();

	printf("Enter 1 to insert a value at the beginning of the list.\nEnter 2 to insert a value at the end of the list.\nEnter 3 to insert num before a number.\nEnter 4 to insert num after a number.\nEnter 5 to delete a value at the beginning of the node.\nEnter 6 to delete a value at the end of the list.\nEnter 7 to delete a specific number.\nEnter 8 to delete all linked list all at once.\nEnter 9 to sort the list.\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		printf("Enter the value that you wish to enter.\n");
		int n, num;
		scanf("%d", &n);
		start = insert_f(start, n);
		break;
	}
	case 2:
	{
		printf("Enter the value that you wish to enter.\n");
		int n;
		scanf("%d", &n);
		start = insert_e(start, n);
		break;
	}

	case 3:
	{
		int num, n;
		printf("Enter the data, and the number before which it is to be added.\n");
		scanf("%d%d", &num, &n);
		start = insert_before(start, num, n);
		break;
	}
	case 4:
	{
		int num, n;
		printf("Enter the data, and the number after which it is to be added.\n");
		scanf("%d%d", &num, &n);
		start = insert_after(start, num, n);
		break;
	}
	case 5:
	{
		start = delete_b(start);
		break;
	}
	case 6:
	{
		start = delete_e(start);
		break;
	}
	case 7:
	{
		int n;
		printf("Enter the data of the node that you wish to delete.\n");
		scanf("%d", &n);
		start = delete_num(start, n);
		break;
	}
	case 8:
	{
		start = delete_all(start);
		break;
	}
	case 9:
	{
		start = sort(start);
		break;
	}

	default:
		printf("Invalid choice");
	}
	if (start == NULL)
	{
		printf("The list is empty.\n");
		return 0;
	}
	else
		printf("The elements of the list are:\n");
	ptr = start;

	while (ptr->next != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("%d", ptr->data);

	return 0;
}

struct node *create()
{

	struct node *start = NULL;
	struct node *ptr;
	int num;
	printf("Enter the data elements. Enter -1 to terminate the the entry process.\n");
	scanf("%d", &num);
	while (num != -1)
	{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		if (start == NULL)
		{
			start = new_node;
			new_node->next = NULL;
		}
		else
		{
			struct node *ptr = start;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->next = NULL;
		}
		scanf("%d", &num);
	}
	return start;
}
