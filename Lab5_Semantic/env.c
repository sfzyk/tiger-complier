//
// Created by lenovo on 2018/9/13.
//

#include <stdlib.h>
#include "util.h"
#include "symbol.h"
#include "types.h"
#include "env.h"


E_enventry E_VarEntry(Ty_ty ty){
    E_enventry e= checked_malloc(sizeof(struct E_enventry_));
    e->kind=E_varEntry;
    e->u.var.ty=ty;
    return e;
}
E_enventry E_FunEntry(Ty_tyList formals, Ty_ty ty){
    E_enventry e=checked_malloc(sizeof(struct E_enventry_));
    e->kind=E_funEntry;
    e->u.func.formals=formals;
    e->u.func.ty=ty;
    return e;
}

S_table E_base_tenv(void){
    S_table st=S_empty();
    S_enter(st,S_Symbol(String("int")),Ty_Int());
    S_enter(st,S_Symbol(String("string")),Ty_String());


    return st;
}

S_table E_base_venv(void){
    S_table st=S_empty();
    return st;
}


