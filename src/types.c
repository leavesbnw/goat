#include "include/types.h"
#include <glib.h>

atom *l_newcons(atom *car,atom *cdr) {
	lcons *ret = g_new(lcons,1);
	ret->t = TCONS;
	ret->car = car;
	ret->cdr = cdr;
	return (atom *)ret;
}
  /*
   * convert atom to lcons
   */
lcons *l_ccons(atom *x) {
	if (x && *x == TCONS)
		return (lcons *)x;
	printf("Error: bad cons cast\n");
	return NULL;
}

atom *l_newint(int i) {
	lint *ret = g_new(lint,1);
	ret->t = TINT;
	ret->i = i;
	return (atom *)ret;
}
lint *l_cint(atom *x) {
	if (x && *x == TINT)
		return (lint *)x;
	printf("Error: Bad int cast\n");
	return NULL;
}

atom *l_newchar(char c) {
	lchar *ret = g_new(lchar,1);
	ret->t = TCHAR;
	ret->c = c;
	return (atom *)ret;
}
lchar *l_cchar(atom *x) {
	if (x && *x == TCHAR)
		return (lchar *)x;
	printf("Error:bad char cast\n");
	return NULL;
}

atom *l_newstring(char *s) {
	char *str = g_malloc(strlen(s));
	lstring *ret = g_new(lstring,1);
	ret->t = TSTRING;
	ret->s = strcpy(str,s);
	return (atom *)ret;
}
lstring *l_cstring(atom *x) {
	if (x && *x == TSTRING)
		return (lstring *)x;
	printf("Error:bad string cast\n");
	return NULL;
}

atom *l_newsym(char *s) {
	char *str = g_malloc(strlen(s));
	lsym *ret = g_new(lsym,1);
	ret->t = TSYM;
	ret->s = strcpy(str,s);
	return (atom *)ret;
}
lsym *l_csym(atom *x) {
	if (x && *x == TSYM)
		return (lsym *)x;
	printf("Error:bad sym cast\n");
	return NULL;
}

nspace *l_bind(nspace *head,lsym *name,atom *link) {
	nspace *ret = g_new(nspace,1);
	ret->head = head;
	ret->name = name;
	ret->link = link;
	return ret;
}

atom *l_newax(atom *(*a)(lcons*,nspace*)) {
	lax *ret = g_new(lax,1);
	ret->t = TAX;
	ret->a = a;
	return (atom *)ret;
}
lax *l_cax(atom *x) {
	if (x && *x == TAX)
		return (lax *)x;
	printf("Error:bad lax cast\n");
	return NULL;
}

atom *l_newfun(atom *args,lcons *body,nspace *n) {
	lfun *ret = g_new(lfun,1);
	ret->t = TFUN;
	ret->args = args;
	ret->body = body;
	ret->n = n;
	return (atom *)ret;
}
lfun *l_cfun(atom *x) {
	if (x && *x == TFUN)
		return (lfun *)x;
	printf("Error:bad fun cast\n");
	return NULL;
}
