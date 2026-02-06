This project has been created has part of the 42 curriculum by nmayela

Description:
ft_printf is a project which consist to output the params given to the the function ft_printf , like the real function printf.

Instructions:
To compile the project , first you have to use the Makefile, 
make all to build 
make clean to remove all *.o files 
make fclean to remove all *.o and *.a files
make re to rebuild , executing at the same time fclean then all.

Once the project is build you have to compile with those flags :
'gcc -Wall -Wextra -Werror -L. -lftprintf'

Ressource:
To accomplish my project , I used this site to understand how va_arg work. 
https://koor.fr/C/cstdarg/va_arg.wp

About my algorithm , I only use a lot of conditions to know which function will be called according to the params given to ft_printf
for example if I have '%d' I will convert a int into a string to be able to display the result in the output.
