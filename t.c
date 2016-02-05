#include <stdio.h> 
void foo(int **p) { int j = 2; *p = &j; printf("%d ", **p); }
int main() 
{ int i = 97, *p = &i; foo(&p); printf("%d ", *p); return 0; } 
