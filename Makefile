CXX = g++
CXXFLAGS = -std=c++11 -ggdb -Wall
LDFLAGS = -ggdb
O = parse.tab.o Expr.o SymTab.o SymUtils.o Stmt.o Symbol.o

parser: $O
	$(CXX) $(LDFLAGS) $O -o parser

all.h: List.h error.h Expr.h Stmt.h Symbol.h SymTab.h SymUtils.h TypeUtils.h
	touch all.h

parse.tab.cpp: parse.y
	bison -v parse.y; /bin/mv parse.tab.c parse.tab.cpp

scan.cpp: scan.l
	flex -t scan.l > scan.cpp

parse.tab.o: parse.tab.cpp scan.cpp main.cpp all.h
Expr.o: all.h
Stmt.o: all.h
SymTab.o: all.h
SymUtils.o: all.h
Symbol.o: all.h

clean:
	/bin/rm -f parser scan.cpp parse.tab.cpp parse.output core.* $O test.out

T = samples/arith.py samples/assign.py samples/class.py samples/comments.py samples/decl.py samples/def.out samples/def.py samples/empty.py samples/for.py samples/if.py samples/ifs.py samples/searchlist.py samples/test1.py samples/while.py

test: parser
	./parser -4 < samples/ifs.py > test.out
