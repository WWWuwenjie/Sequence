#include"Sequence.h"
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
Sequence se("dna.txt");
cout<<"length: "<<se.length()<<endl;
cout<<"number of A: "<<se.numberOf('A')
    <<"\nnumber of G: "<<se.numberOf('G')
    <<"\nnumber of C: "<<se.numberOf('C')
    <<"\nnumber of T: "<<se.numberOf('T')<<endl;

return 0;
}
