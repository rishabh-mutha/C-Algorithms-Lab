#include<iostream>
using namespace std;

class Currexchange
{

public:
int n;
int bill;
int deno[100];
int freq[100];

void input()
{
cout<<"enter the number of denominations"<<endl;
cin>>n;
cout<<"enter the denominations"<<endl;
for(int i=0; i<n; i++)
cin>>deno[i];
cout<<"enter the bill value"<<endl;
cin>>bill;
}

void calc()
{
int i,j,amt;
amt=bill;
for(int i=0; i<n; i++)
{
if(amt>0)
{
freq[i]=amt/deno[i];
amt = amt - freq[i]*deno[i]; 
}
else break;
}
}

void output()
{
for(int i=0; i<n; i++)
for (int j=0; j<freq[i]; j++)
cout<<deno[i]<<" ";
}

};


int main()
{
Currexchange c;
c.input();
c.calc();
c.output();

return 0;
}

