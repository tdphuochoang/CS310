#include"prog2_3.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include"prog2_1.h"
using namespace std;


int main(int nargs,char*args[] ){
	ifstream myfile;

	Tokenizer t;
	Parser p;
	ofstream out;
	string line;
	vector<string >OutputToken;
	std::vector<std::string> OutputTokenStore[1000];
	myfile.open(args[1]);
	cout<<"Assignment #2-4, Scott Lindeneau, slindeneau@sdsu.edu"<<endl;
	if (myfile.is_open())
	{  
		while (getline(myfile, line))
		{
			t.Tokenize(line);
		}
		myfile.close();
		int totalLine = t.getsize();
		for (int i = 0; i < totalLine; i++)
		{


			OutputToken = t.GetTokens();
			int sizeofoutputtoken = OutputToken.size();
			try{

				if (!p.parse(OutputToken))
				{
					
					
					throw "Parse error on line ";
				}
			}
			catch (const char*msg)
			{
				cout << msg << i + 1 << ":";
				for (int j = 0; j < sizeofoutputtoken; j++)
					cout << OutputToken[j] << " ";
				cout << endl;
				exit(0);
			}
			for (int j = 0; j < sizeofoutputtoken; j++)
				OutputTokenStore[i].push_back(OutputToken[j]);

		}
		for (int i = 0; i < totalLine; i++){
			for (int j = 0; j < OutputTokenStore[i].size(); j++)
			{
				if (j + 1 < OutputTokenStore[i].size())
					cout << OutputTokenStore[i][j] << ",";
				else
					cout << OutputTokenStore[i][j] << endl;
			}
		}
	}

	else
		cout << "Unable to open file";

	return 0;
}
