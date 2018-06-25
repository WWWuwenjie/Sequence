#include"Sequence.h"
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<fstream> 
using namespace std;

Sequence::Sequence(string filename)
{
	cout << filename << endl;
	ifstream ReadFile;
	ReadFile.open(filename.c_str(), ios::in);
	if (ReadFile.fail())
		cout << "File can not be opened." << endl;
	while (!ReadFile.eof())
	{
		string seq;
		getline(ReadFile, seq);
		sequence.append(seq);
	}
	ReadFile.close();
}

int Sequence::CountLines(const char *filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename, ios::in);
	if (ReadFile.fail())
	{
		cout << "File can not be opened." << endl;
		return 0;
	}
	else
	{
		while (getline(ReadFile, tmp, '\n'))
			n++;
		ReadFile.close();
		return n;
	}
}

int Sequence::length()
{
	return sequence.length();
}

int Sequence::numberOf(char base)
{

	/*string tester(1,base);
	while (string::npos!=sequence.find(tester))
	{
		tester.append(string(1,base));
	}
	tester.erase(0, 1);
	return tester.length();*/
        return count(sequence.begin(),sequence.end(),base);
}

string longestConsecutive()
{
	return "";
}

string longestRepeated()
{
	return "";
}
