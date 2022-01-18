#include <iostream>
#include <istream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <string.h>


// Namespace to declare scope for the class and functions
using namespace std;

 class Parser{
	 bool contains_numbercheck(const std::string &c);
public:
	
	Parser(){

	}
	~Parser(){

		
		
	}
	bool parse(vector<string> str);
	
};