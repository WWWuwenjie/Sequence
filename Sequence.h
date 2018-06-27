#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Sequence
{
public:
Sequence(string);
int length();
int numberOf(char);
int consecutive(char);
//int CountLines(const char*);
string longestConsecutive();
string longestRepeated();
private:
string sequence;
};

#endif
