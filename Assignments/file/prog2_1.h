#include <iostream>
#include <istream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <string.h>
#define vector_Size 2000

// Namespace to declare scope for the class and functions
using namespace std;


// Class for a tokenizer object
class Tokenizer{
	std::vector<std::string> token[vector_Size];
	int cur_size_string_vector;
	int count_itr;
	bool contains_number(const std::string &c);
	size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
public:
	vector<string>  GetTokens();
	Tokenizer();
	~Tokenizer(){


	}
	void Tokenize(string str);
	int  getsize();
};
