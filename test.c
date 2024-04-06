#include <stdio.h>
#include <unistd.h>

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("a + b is %d\n", a + b);

    /*
    int pid = fork();
    int i;
    scanf("%d", &i);
    if(pid == 0) printf("pid is Zero %d\n", pid);
    else printf("pid is not Zero %d\n", pid);
    printf("i is %d\n", i);
    */

}