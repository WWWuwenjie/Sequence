#include"Sequence.h"
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<fstream> 
using namespace std;

Sequence::Sequence(string filename)
{
//	cout << filename << endl;
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

/*int Sequence::CountLines(const char *filename)
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
}*/

int Sequence::length()
{
	return sequence.length();
}

int Sequence::numberOf(char base)
{
        return count(sequence.begin(),sequence.end(),base);
}

int Sequence::consecutive(char base)
{
string tester(1,base);
while(string::npos!=sequence.find(tester))
   tester.append(string(1,base));
return tester.length()-1;
}

string Sequence::longestConsecutive()
{
int a=Sequence::consecutive('A');
int g=Sequence::consecutive('G');
int c=Sequence::consecutive('C');
int t=Sequence::consecutive('T');
int max=a;
char base='A';

if(g>max)
  {
   max=g;
   base='G';
  }
if(c>max)
  {
   max=c;
   base='C';
  }
if(t>max)
  {
   max=t;
   base='T';
  }

string longest(max,base);
return longest;
}

string Sequence::longestRepeated()
{
//need about 1.5h
size_t maxleng=1;
string longest;
int begin=0;
while(begin+maxleng-1<sequence.length())
 {
  bool f=0;
  int end=begin+maxleng-1;
  string str(sequence,begin,maxleng);
  size_t found=sequence.find(str,end+1);
  while(found!=string::npos)
   {
     f=1;
     end++;
     maxleng++;
     char ch=sequence[end];
     char s1[2]={ch,0};
     string s=s1;
     str.append(s);
     found=sequence.find(str,end); 
   }
   
  if(f)
   {
     longest=str;
     longest.erase(longest.end()-1);
   }
  begin++; 
  if(begin%1000==0)
    cout<<begin<<endl;
 } 
return longest;
}
