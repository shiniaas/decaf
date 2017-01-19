bison -d -t decaf.y
flex decaf.l
cp tree.c tree.cpp
cp decaf.tab.c decaf.tab.cpp
g++ decaf.tab.cpp -w -ll -o result 
./result my.decaf