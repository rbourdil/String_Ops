#ifndef STROPS_H
#define STROPS_H

#include <string.h>
#include <stdlib.h>

void	add(char *res, const char *op);
void	diff(char *res, const char *op);

void	plus(char *res, const char *op);
void	minus(char *res, const char *op);
int		comp(const char *op1, const char *op2);

void	pop(char *s, char c);
void	depop(char *s);
void	reverse(char *s);

#endif
