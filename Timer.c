/*
 * This is just a program to practice fork(), exec(), wait()
 *
 * This works fine I just forgot that execv() has to take a path
 * to a program, not a raw C file.  Things have to be complied 
 * before they are run.
 */

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){

        time_t start = time(NULL);


        if (fork() == 0){
                execv(argv[1], NULL);
        } else{
                wait(NULL);
        }

        time_t end = time(NULL);

        printf("Execution time: %ld\n", end - start);
        
}
