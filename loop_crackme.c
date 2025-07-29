#include <stdio.h>

int main(){
    int i;
    int sum = 0;
    printf("starting loop..\n");
    for(i = 0; i < 5; i++){
        sum += i;
        printf("current sum: %d\n", sum);
    }
    printf("loop finished. Finale sum: %d\n", sum);
    return 0;
}
