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
