#include "foundation.h"

//Делает из строки число, и возвращает его
unsigned StrToDigit(string Str)
{
	unsigned f = 0;
	unsigned Result = 0;
	unsigned LenStr = Str.size() - 1;
	int i = LenStr;
	while (i >= 0)
	{
		unsigned ten = 1;
		for (unsigned j = LenStr - i; j > 0; j--)
			ten *= 10;
		Result += (Str[i] - '0') * ten;
		i--;
	}
	return Result;
}