#include<iostream>
using namespace std;

class knapsack
{

public:
int n;
int max;
int price[100];
int weight[100];
int freq[100];

void input()
{
cout<<"enter the number of objects"<<endl;
cin>>n;
cout<<"enter the prices and weights"<<endl;
for(int i=0; i<n; i++)
{
cin>>price[i];
cin>>weight[i];
}

cout<<"enter the max weight value"<<endl;
cin>>max;
}

void calc()
{
int i,j,amt;
amt=max;
for(int i=0; i<n; i++)
{
if(amt>0)
{
freq[i]=amt/weight[i];
amt = amt - freq[i]*weight[i]; 
}
else break;
}
}

void output()
{
for(int i=0; i<n; i++)
for (int j=0; j<freq[i]; j++)
cout<<price[i]<<" ";
}

};


int main()
{
knapsack c;
c.input();
c.calc();
c.output();

return 0;
}

