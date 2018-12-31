gcc RB.lab5.c -o RB.lab5.o -c
gcc lab5driver.c -o lab5driver.o -c
gcc -o tree lab5driver.o RB.lab5.o
