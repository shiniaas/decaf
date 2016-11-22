bison -d -t decaf.y
flex decaf.l
gcc tree.c decaf.tab.c  -ll -o result
./result my.decaf