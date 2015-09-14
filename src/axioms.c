#include "include/types.h"
atom *l_add(lcons *args,nspace *n) {
	if (!args)
		return l_newint(0);
	lint *car = l_cint(eval(args->car,n));
	lint *cdr = l_cint(l_add(l_ccons(args->cdr),n));
	if (car && cdr)
		return l_newint(car->i + cdr->i);
	else {
		printf("Error: \"+\" bad int \n");
		return NULL;
	}
}