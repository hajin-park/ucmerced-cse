#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert code here
    printf("%d\n", head->iValue);
    printf("%f\n", head->fValue);
    printf("%p\n", head);
    printf("%p\n", &head->iValue);
    printf("%p\n", &head->fValue);
    printf("%p\n", head->next);
	
	
	return 0;
}