#include "prog2_1.h"
#include <iostream>
#include <istream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <string.h>
#include <cstdlib>
#include <cstdlib>



using namespace std;

int min(int a,int  b){

	return a < b ? a : b;

}

//this function takes string and spilt based on given character ' '
size_t Tokenizer::split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	
	strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos-1));
	

	return strs.size();
}


Tokenizer::Tokenizer()
{
	cur_size_string_vector = 0;
	 count_itr = 0;
	//token = new std::vector<std::string>();
}

//this fucnction takes a string check whether given string contains integer or not
bool Tokenizer:: contains_number(const std::string &c)
{
	for(int i=0;c[i]!='\0';i++)
	{
	
	if(c[i]-'0'<0 || c[i]-'0'>9)
		 return false;
	}

	
	return true;
}


//Tokenize() fn define which take a string if string have valid token the store these token in Tokenizer class
void  Tokenizer:: Tokenize(string str)
{

	std::vector<std::string> v;
	split(str, v, ' ');
	for (int i = 0; i < v.size(); i++)
	{
	  
		try {
			if (v[i] == "push" || v[i] == "pop" || v[i] == "add" || v[i] == "sub" || v[i] == "mul" || v[i] == "div" || v[i] == "mod" || v[i] == "skip" || v[i] == "save" || v[i] == "get" || contains_number(v[i]))
			{

				token[cur_size_string_vector].push_back(v[i]);

			}
			else
			{

				throw "Unexpected token : ";
			}
		}
		catch (const char* msg) {
			cerr << "Error on line " << cur_size_string_vector+1<<" : "<< msg << v[i] << endl;
			exit(0);
		}

	}
	cur_size_string_vector++;
}

// define pop_front() which pop front element of given vector
template<typename T>
void pop_front(std::vector<T>& vec)
{
	
	vec.erase(vec.begin());
}

//GetTokens fn return string of tokens in which order token entered
vector<string> Tokenizer:: GetTokens()
{
	vector<string> tOutput;
	try{
		if (cur_size_string_vector-1<0)
			throw "No tokens";
		int sizeofvector = token[count_itr].size();
		for (int i = 0; i < sizeofvector; i++)
		{

			tOutput.push_back(token[count_itr][0]);
			pop_front(token[count_itr]);
		}
		

		}
		catch (const char* msg) {
			cerr << msg <<  endl;
			exit(0);
		}

	cur_size_string_vector--;

	count_itr++;
	return tOutput;
}

//it return current size of vector in Tokenizer class
int Tokenizer::getsize(){

	return cur_size_string_vector;
}


