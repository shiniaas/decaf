bison -d decaf.y
flex decaf.l
gcc main.c decaf.tab.c -ll -o result