#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n = 5;
    register unsigned short i;

    char **splited = (char **)malloc(sizeof(char *) * n);
    
    for (i = 0; i < n; i ++) {
        *(splited + i) = (char *)malloc(0);
    }
    
    *(splited + 0) = "yo";
    *(splited + 1) = "check";
    *(splited + 2) = "this";

    strcpy(*(splited + 3), "test!!");

    splited[4] = "another test!";
    
    
    for (i = 0; i < n; i ++) {
        printf("%s\n", *(splited + i));
    }
    
    // yo
    printf("*(splited + 0): %p, %s\n", *(splited + 0), *(splited + 0));
    printf("splited[0]: %p, %s\n\n", splited[0], splited[0]);

    // check
    printf("*(splited + 1): %p, %s\n", *(splited + 1), *(splited + 1));
    printf("splited[1]: %p, %s\n\n", splited[1], splited[1]);

    // this
    printf("*(splited + 2): %p, %s\n", *(splited + 2), *(splited + 2));
    printf("splited[2]: %p, %s\n\n\n", splited[2], splited[2]);

    // y
    printf("*(*(splited + 0) + 0): %d, %c\n", *(*(splited + 0) + 0), *(*(splited + 0) + 0));
    printf("*(*splited + 0): %d, %c\n", *(*splited + 0), *(*splited + 0));
    printf("**(splited + 0): %d, %c\n", **(splited + 0), **(splited + 0));
    printf("**splited + 0: %d, %c\n", **splited + 0, **splited + 0);
    printf("splited[0][0]: %d, %c\n", splited[0][0], splited[0][0]);
    printf("*splited[0]: %d, %c\n\n\n", *splited[0], *splited[0]);
    

    // o
    printf("*(*(splited + 0) + 1): %d, %c\n", *(*(splited + 0) + 1), *(*(splited + 0) + 1));
    printf("*(*splited + 1): %d, %c\n", *(*splited + 1), *(*splited + 1));
    printf("splited[0][1]: %d, %c\n\n\n", splited[0][1], splited[0][1]);

    // c
    printf("*(*(splited + 1) + 0): %d, %c\n", *(*(splited + 1) + 0), *(*(splited + 1) + 0));
    printf("**(splited + 1): %d, %c\n", **(splited + 1), **(splited + 1));
    printf("splited[1][0]: %d, %c\n", splited[1][0], splited[1][0]);
    printf("*splited[1]: %d, %c\n\n", *splited[1], *splited[1]);


//    for (i = 0; i < 1000; i ++) {
//        printf("%s ", splited[0] + i);
//    }
    //    same
    //    for (i = 0; i < 100; i ++) {
    //        printf("%s ", *splited + i);
    //    }
    

//    for (i = 0; i < 10000; i ++) {
//        printf("%c", splited[0][i]);
//    }
    //    same
    //    for (i = 0; i < 10000; i ++) {
    //        printf("%c ", *(*splited + i));
    //    }


}
