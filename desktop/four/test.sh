bison -d -t decaf.y
flex decaf.l
cp decaf.tab.c decaf.tab.cpp
g++ decaf.tab.cpp -w -ll -o result 
./result my.decaf