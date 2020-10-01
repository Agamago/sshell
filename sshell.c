/*
 * Joey Sheridan
 * Assignment # 2
 * Operating Systems 
 * sshell.c
 */ 
 #include <sys/types.h>
 #include <string.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
 #include <sys/wait.h>

\
 #define MAX_LINE 80

 //Stores arguments in args[]
 int main() {

    char *args[MAX_LINE];
    char command[MAX_LINE];
    char delim[] = " ";
    int i = 0;
    *args[MAX_LINE/2 +1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit the program */
    pid_t pid;
    
    printf("osh> ");
    fgets(command, MAX_LINE, stdin);
    char *ptr = strtok(command, delim);

    while (ptr != NULL) {
	    args[i] = ptr;
	    ptr = strtok(NULL, delim);
	    ++i;
    }






    printf("Forking program . . . \n");
    pid = fork();

    while (should_run) {
       pid_t pid;
       printf ("osh>");
       fflush(stdout);

       //Fork error check
       if (pid < 0) {
	  printf("Fork error : %d (%s) \n", errno , strerror(errno));
	  should_run = -1;
       }
       
       //This is the child process
       else if (pid ==0) {
	   printf(" I am the child ");
	   execvp(args[0], args);
	   should_run = 0;
       }


       //This is the parent process
       else {
	   printf("I am the parent");
	   should_run = -0;
       }

       /*
       if (pid > 0) {
	   int stat_val;
	   pid_t child_pid;

	   child_pid = wait(&stat_val);

	   printf("child has finished: PID = %d \n", child_pid);
	   if (WIFEXITED(stat_val)) {
	       printf("Child exited with code %d \n", WEXITSTATUS(stat_val));
	   }

	   printf("Parent has finished \n");
	   should_run= -1;
       }
       */

	  
       /**
       * After reading user input, the steps are :
       * (1) fork a child process using fork()
       * (2) the child process will invoke execvp()
       * (3) if command included &, parent will invoke wait()
       */
      
    sleep(1);
    }
    printf("ending");
    should_run = 0;
    return 0;
 }
