#include <iostream>
#include <fstream>
#include <string>
#include"prog2_1.h"
using namespace std;

int main(int nargs,char * args[]) {
	ifstream myfile;
        cout<<"Assignment #2-2, Hoang Tran, tdll.trdphoang@gmail.com"<<endl;
	Tokenizer t;
	string line;
	vector<string >OutputToken;
	myfile.open(args[1]);
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
			for (int j = 0; j < sizeofoutputtoken; j++)
			if (j + 1 < sizeofoutputtoken)
				cout << OutputToken[j] << ",";
			else
				cout << OutputToken[j] << endl;
		}


	}

	else
		cout << "Unable to open file";

	return 0;
}
