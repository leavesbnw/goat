#include <stdio.h>
#include <stdlib.h>
#include "include/types.h"

int main (int argc,const char *argv[]) {
	char *p;
	nspace *n = NULL;
	atom *fn = l_newfun(l_newcons(l_newsym("x"),NULL),l_ccons(l_newcons(l_newsym("x"),NULL)),n);
	n = l_bind(n,(lsym *)l_newsym("identity"),fn);
	n = l_bind(n,l_csym(l_newsym("+")),l_newax(l_add));
	n = l_bind(n,l_csym(l_newsym("-")),l_newax(l_sub));
	n = l_bind(n,l_csym(l_newsym("*")),l_newax(l_mult));
	n = l_bind(n,l_csym(l_newsym("/")),l_newax(l_div));
	n = l_bind(n,l_csym(l_newsym("=")),l_newax(l_numeq));
	n = l_bind(n,l_csym(l_newsym("<")),l_newax(l_lt));
	n = l_bind(n,l_csym(l_newsym("exit")),l_newax(l_quit));
	n = l_bind(n,l_csym(l_newsym("lambda")),l_newax(l_lambda));
	n = l_bind(n,l_csym(l_newsym("define")),l_newax(l_define));
	n = l_bind(n,l_csym(l_newsym("quote")),l_newax(l_quote));
	n = l_bind(n,l_csym(l_newsym("list?")),l_newax(l_list));
	n = l_bind(n,l_csym(l_newsym("car")),l_newax(l_car));
	n = l_bind(n,l_csym(l_newsym("cdr")),l_newax(l_cdr));
	n = l_bind(n,l_csym(l_newsym("cons")),l_newax(l_cons));
	n = l_bind(n,l_csym(l_newsym("if")),l_newax(l_if));
	n = l_bind(n,l_csym(l_newsym("null?")),l_newax(l_null));
	n = l_bind(n,l_csym(l_newsym("let")),l_newax(l_let));
	n = l_bind(n,l_csym(l_newsym("let*")),l_newax(l_lets));
	n = l_bind(n,l_csym(l_newsym("set!")),l_newax(l_set));
	n = l_bind(n,l_csym(l_newsym("letrec")),l_newax(l_letrec));
	n = l_bind(n,l_csym(l_newsym("apply")),l_newax(l_apply));
	n = l_bind(n,l_csym(l_newsym("or")),l_newax(l_or));
	n = l_bind(n,l_csym(l_newsym("and")),l_newax(l_and));
	n = l_bind(n,l_csym(l_newsym("not")),l_newax(l_not));
	n = l_bind(n,l_csym(l_newsym("begin")),l_newax(l_begin));
	n = l_bind(n,l_csym(l_newsym("equal?")),l_newax(l_equal));
	n = l_bind(n,l_csym(l_newsym("defmacro")),l_newax(l_defmacro));
	n = l_bind(n,l_csym(l_newsym("call/cc")),l_newax(l_callcc));
	n = l_bind(n,l_csym(l_newsym("eq?")),l_newax(l_eq));

	for (;;) {
		printf("> ");
		print(eval(read(stdin),n));
		printf("\n");
	}
	return 0;
}
