#include "include/types.h"
#define BUFFSIZE 256

FILE *fp;
atom * l_read(FILE *input) {
	fp=input;
	return l_parse(l_next());
}

static char l_readchar(void) {
	int c = getc(i);
	if (c != EOF)
		return c;
	printf("Error: unexpected EOF (check parents)\n");
	exit(1);
}

static void l_putback(char c) {
	ungetc(c,fp);
}
static char *l_next(void) {
	static char buff[BUFFSIZE];
	char *c = buff;
	while ( isspace(*c = l_readchar())) ;
	
	if (*c != ')' && *c != '(' && *c != '"') {
		while ( !isspace(*(c+1) = l_readchar()) && *(c+1) != '(' && *(c+1) != ')')
			c++;
		l_putback(*(c+1));
	}
	else if (*c == '"') {
		while ((*(++c) = l_readchar()) != '"')
			if (*c == '\\')
				*(++c) = l_readchar();
	}
	*(c+1) = '\0';
	return buff;
}
static atom *l_parselist(void) {
	char *p = l_next();
	atom *ret,*car,*cdr;
	switch (*p) {
		case ')':
			return NULL;
		case '.':
			ret = l_parse(l_next());
			if (*l_next() == ')')
				return ret;
			else {
				printf("Error:invalid dotted list\n");
				exit(1);
			}
			break;
		default:
			car = l_parse(p);
			cdr = l_parselist();
			return l_newcons(car,cdr);
	}
}
static atom *l_parse(char *p) {
	char *t = p;
	if (!*p)
		return NULL;/*we've reached the end*/
	switch(*p) {
		case '(':
			return l_parselist();
		case '"':
			while (*(++t));
			*(t-1) = '\0';
			return l_newstring(p+1);
		case '#':
			switch(*(p+1)) {
				case '\\':
					return l_newchar(*(p+2));
				case 't':
					return l_newbool(1);
				case 'f':
					return l_newbool(0);
				default:
					printf("Error:invalid # syntax\n");
					exit(1);
			}
			break;
		case '\'':
			return l_newcons(l_newsym("quote"),l_newcons(*(p+1)?l_parse(p+1):l_parse(l_next()),NULL));
		case '`':
			return l_newcons(l_newsym("quote"),l_newcons(*(p+1)?l_parse(p+1):l_parse(l_next()),NULL));
		case ',':
			return l_newcons(l_newsym("quote"),l_newcons(*(p+1)?l_parse(p+1):l_parse(l_next()),NULL));
		case ')':
		default:
			if (isdigit(*p))
				return l_newint(atoi(p));
			else
				return l_newsym(p);
	}
}
			