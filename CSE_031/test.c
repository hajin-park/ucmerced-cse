#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    char charlist[] = "ABCDEFGH";
    int* a;
    a = charlist;
    a[0] = 512;
    printf("%x\n", charlist[1]);
}
