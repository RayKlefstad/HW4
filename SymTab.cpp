#include "all.h"

SymTab ST;

void SymTab :: enterSymbol(Symbol sy)
{
    head->info = new SymbolPair(sy, head->info);
}

Symbol SymTab :: findSymbolInList(string name, SymbolList sl)
{
    for (; sl; sl = sl->next)
        if (name == sl->info->name)
            return sl->info;
    return 0;
}

Symbol SymTab :: findSymbolInTopScope(string name)
{
    return findSymbolInList(name, head->info);
}

void SymTab :: enterScope(SymbolList syli)
{
    head = new SymbolListPair(syli, head);
}

SymbolList SymTab :: exitScope()
{
    SymbolList t = head->info;
    head = head->next;
    if (HW == 4)
    {
        cout << "*** Exit Scope ***" << endl;
        putSymbolList(cout, t);
        cout << endl;
    }
    return t;
}

Symbol SymTab :: findSymbol(string name)
{
    for (SymbolListList sll = head; sll; sll = sll->next)
        for (SymbolList sl = sll->info; sl; sl = sl->next)
            if (name == sl->info->name)
                return sl->info;
    return 0;
}

void SymTab :: declare(Symbol sy)
{
    Symbol oldSy = findSymbolInTopScope(sy->name);
    if (oldSy)
        semantic_error("multiple definitions in scope");
    else
        enterSymbol(sy);
    debug("declaring symbol " + sy->name);
}

void SymTab :: putSymbolList(ostream & out, SymbolList L)
{
        for (SymbolList sl = L; sl; sl = sl->next)
        {
            sl->info->put(out);
            out << endl;
        }
}

void SymTab :: put(ostream & out)
{
    for (SymbolListList sll = head; sll; sll = sll->next)
        putSymbolList(out, sll->info);
}
