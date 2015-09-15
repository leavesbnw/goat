#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#define catom(x) ((atom *) x)
typedef enum {
	TCONS,TINT,TCHAR,TFUN,TSTRING,TSYM,TBOOL,TAX,TMAC,TCONT
} atom;

typedef struct lcons {
	atom t,*car,*cdr;
} lcons;

typedef struct lint {
	atom t;
	int i;
} lint;

typedef struct lchar {
	atom t;
	char c;
} lchar;

typedef struct lstring {
	atom t;
	char *s;
} lstring;

typedef struct lsym {
	atom t;
	char *s;
} lsym;

typedef struct lnspace {
	struct nspace *head;
	asym *name;
	atom *link;
} lnspace;

typedef struct lax {
	atom t;
	atom *(*a)(acons*,nspace*);
} lax;

typedef struct lfun {
	atom t;
	nspace *n;
	atom *args;
	acons *body;
} lfun;

atom *l_newcons(atom *car,atom *cdr);
lcons *l_ccons(atom *x);
atom *l_newint(int i);
lint *l_cint(atom *x);
atom *l_newchar(char c);
lchar *l_cchar(atom *x);
atom *l_newstring(char *s);
lstring *l_cstring(atom *x);
atom *l_newsym(char *s);
lsym *l_csym(atom *x);
nspace *l_bind(nspace *head,lsym *name,atom *link);
atom *l_newax(atom *(*a)(lcons*,nspace*));
lax *l_cax(atom *x);
atom *l_newfun(atom *args,lcons *body,nspace *n);
lfun *l_cfun(atom *x);