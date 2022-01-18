#include"prog2_3.h"

bool Parser::contains_numbercheck(const std::string &c)
{
	for (int i = 0; i < c[i] != '\0'; i++)
	if (c[i] - '0'<0 || c[i] - '0'>9)
		return false;
	return true;
}

bool Parser::parse(vector<string> vStr)
{

	if (vStr.size() == 1)
	{
		if (vStr[0] == "pop" || vStr[0] == "add" || vStr[0] == "sub" || vStr[0] == "mul" || vStr[0] == "div" 
			|| vStr[0] == "mod" || vStr[0] == "skip")
			return true;
		return false;

	}
	else if (vStr.size() == 2)
	{
		if (vStr[0] == "push" || vStr[0] == "save" || vStr[0] == "get")
		{

			if (contains_numbercheck(vStr[1]))
				return true;

			return false;
		}

		return false;
	}
	return false;
}
