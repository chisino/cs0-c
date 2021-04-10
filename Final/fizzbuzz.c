/**
 * Name: Artiom Dolghi
 *
 * CSCE 155E Final
 *
 * This program solves the Fizz Buzz Problem
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    int i = 0;


    for (i=1; i<=100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        }
        else if (i % 5 == 0) {
            printf("Buzz\n");
        }
        else if (i % 3 == 0) {
            printf("Fizz\n");
        }
        else {
            printf("%d\n", i);
        }
    }

    return 0;
}
