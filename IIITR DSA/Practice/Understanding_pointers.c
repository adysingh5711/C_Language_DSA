#include <stdio.h>
int main()
{
int x=10;
char ch = 'A';

void *gp;
int *pg;

gp = &x;
printf("\n Generic pointer points to the integer value = %d", *(int*)gp);
pg = &x;
printf("\n Generic pointer points to the integer value = %d", *pg);
gp = &ch;
printf("\n Generic pointer now points to the character= %c", *(char*)gp);
return 0;
}

/*
Let's break down the differences between *(int*)gp and *gp in detail:

*(int*)gp:

(int*)gp: This part of the expression is a type cast. It treats the generic pointer gp as a pointer to an integer (int*). It informs the compiler to interpret gp as a pointer to an integer data type.
*(int*)gp: After the type cast, the * operator is used to dereference the resulting integer pointer. It accesses the value stored at the memory location pointed to by the generic pointer gp. This assumes that gp indeed points to an integer value.
*gp:

*gp: In this case, there is no type cast involved. It assumes that gp is already a pointer to a specific data type (such as int*, float*, etc.).
*gp: The * operator is used to dereference the pointer gp directly. It accesses the value stored at the memory location pointed to by gp. The type of gp determines the type of the value being accessed. If gp is an int* pointer, *gp would retrieve an integer value.
To summarize:

*(int*)gp first casts gp to an integer pointer type (int*), and then dereferences it to obtain the integer value being pointed to.
*gp directly dereferences the pointer gp to obtain the value stored at the memory location pointed to by gp, without any type casting involved.
The choice between *(int*)gp and *gp depends on the type of data that gp is expected to point to. If gp is known to be a pointer to an integer, then *gp would be sufficient. However, if gp is a generic pointer (void*) and the specific data type needs to be inferred, then a type cast like *(int*)gp would be necessary to correctly interpret the pointer and access the value.
*/