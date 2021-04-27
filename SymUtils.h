void enterScope(SymbolList L);
SymbolList exitScope();
void declare(Symbol sy);

void enterClass(string name, TypeList parents, Symbol sym);
void exitClass(string name, Type ty, Symbol sy);

void enterFunc(Symbol fn, SymbolList params);
void declareFuncReturnType(Type ty);
Type lookupFuncReturnType();
void declareFuncParam(Symbol param);
void declareFuncVar(Symbol sy);
void requireSameTypeForReturnStatement(Type ty, Type rt);
void exitFunc();

void declareLoopVar(string name, Expr ex);

Symbol findIdentExpr(string name);
Symbol findIdentInClassType(string name, Type cs);
Type findIdentType(string name);
Type findListElementType(Type ty);
Type findFuncReturnTypeInType(Type ty);
Type findExprTypeOfFirstInList(ExprList L);
