#include "wait.h"

Wait::Wait(void) : expr(NULL)
{
	this->type = S_TYPE_STATEMENT_WAIT;
}

Wait::Wait(Expression* expr, YYLTYPE loc) : expr(expr)
{
	this->type = S_TYPE_STATEMENT_WAIT;
	this->location = loc;
	this->children = (expr) ? expr : NULL;

	this->UpdateChildren();
}

Wait::~Wait()
{
}

void Wait::PrintInfo(FILE* os) const
{
	fprintf(os, "%s with %d children at %d(%d) - %d(%d)\n",
		SYMBOL_TYPE_STRING(type),
		this->children ? this->children->Size() + 1 : 0,
		location.start.line,
		location.start.character,
		location.end.line,
		location.end.character);
}