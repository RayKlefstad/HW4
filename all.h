using namespace std;
#include <iostream>

#include "List.h"

extern int HW;

typedef struct SymbolBlock * Symbol;

typedef ListPair<Symbol> SymbolPair;
typedef SymbolPair * SymbolList;

typedef struct TypeBlock * Type;

typedef ListPair<Type> TypePair;
typedef TypePair * TypeList;

#include "error.h"
#include "Symbol.h"
#include "SymTab.h"
#include "Expr.h"
#include "Stmt.h"
#include "SymUtils.h"
#include "TypeUtils.h"

void check(StmtList L);
void do_homework(StmtList L);
