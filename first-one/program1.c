#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[] = "Szymon";
    for (int i = 31; i < 38; i++) {
        // reset color
        printf("\033[0m");
        printf("Cześć ");
        printf("\033[0;%dm", i);
        printf("Nutek");
        // reset color
        printf("\033[0m");
        printf(", mówi ");
        printf("\033[1;%dm", i);
        printf("%s", name);
        // reset color
        printf("\033[0m");
        printf("! \n");
    }
    
    return 0;
}
