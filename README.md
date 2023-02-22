
**README.md**

**PROJECT:** 0x16. C - Simple Shell

**AUTHORS:** Mogbo Chimmuanya  

`          `Ochiogu Chisom

***Much thanks to Ali Abdela and Sami Birhanu, and* Dr. Ehoneah Obed *for making their code available to us.*** 



**About Project:** 

This project is a simple version of the linux shell made for [Holberton School](https://www.holbertonschool.com/) taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.
It is created using the **C programming Language** and it can do many functionalities that a real shell does.

**What is the Shell?**

The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.
## **List of allowed functions and system calls for this project:**
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- \_exit (man 2 \_exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (\_\_xstat) (man 2 stat)
- lstat (\_\_lxstat) (man 2 lstat)
- fstat (\_\_fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

**TASKS:**

0. Betty would be proud

Write a beautiful code that passes the Betty checks

0. Simple shell 0.1

Write a UNIX command line interpreter.

- Usage: simple\_shell

Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, \*, &, #
- be able to move the cursor
- handle commands with arguments

*execve will be the core part of your Shell, don’t forget to pass the environ to it…*

0. Simple shell 0.2

Simple shell 0.1 +

- Handle command lines with arguments.
###
0. ### Simple shell 0.3
Simple shell 0.2 +

- Handle the PATH
- fork must not be called if the command doesn’t exist
0. ### Simple shell 0.4
Simple shell 0.3 +

- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

0. ### Simple shell 1.0
Simple shell 0.4 +

- Implement the env **built-in**, that prints the current environment

0. ### Simple shell 0.1.1
Simple shell 0.1 +

- Write your own getline function
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use static variables
- You are not allowed to use getline

You don’t have to:

- be able to move the cursor

0. ### Simple shell 0.2.1
Simple shell 0.2 +

- You are not allowed to use strtok

0. ### Simple shell 0.4.1
Simple shell 0.4 +

- handle arguments for the built-in exit
- Usage: exit status, where status is an integer used to exit the shell

0. ### setenv, unsetenv
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

- setenv
  - Initialize a new environment variable, or modify an existing one
  - Command syntax: setenv VARIABLE VALUE
  - Should print something on stderr on failure
- unsetenv
  - Remove an environment variable
  - Command syntax: unsetenv VARIABLE
  - Should print something on stderr on failure

0. ### cd
Simple shell 1.0 +

Implement the builtin command cd:

- Changes the current directory of the process.
- Command syntax: cd [DIRECTORY]
- If no argument is given to cd the command must be interpreted like cd $HOME
- You have to handle the command cd -
- You have to update the environment variable PWD when you change directory

man chdir, man getcwd

0. ### ;
Simple shell 1.0 +

- Handle the commands separator ;

0. ### && and ||
Simple shell 1.0 +

- Handle the && and || shell logical operators

0. ### Alias
Simple shell 1.0 +

- Implement the alias builtin command
- Usage: alias [name[='value'] ...]
  - alias: Prints a list of all aliases, one per line, in the form name='value'
  - alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
  - alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

0. ### Variables
Simple shell 1.0 +

- Handle variables replacement
- Handle the $? variable
- Handle the $$ variable

0. ### Comments
Simple shell 1.0 +

- Handle comments (#)

0. ### File as input
Simple shell 1.0 +

- Usage: simple\_shell [filename]
- Your shell can take a file as a command line argument
- The file contains all the commands that your shell should run before exiting
- The file should contain one command per line
- In this mode, the shell should not print a prompt and should not read from stdin