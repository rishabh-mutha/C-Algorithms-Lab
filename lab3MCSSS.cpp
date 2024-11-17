#include<iostream>    // include<iostream>
using namespace std;  // using namespace std;

int beg1,end1;     // int beg
class DNA{

public:
void read(char x[], char y[]);
	int bruteforce();
	int incdesign();
	int divnconq();
	int pruning();
	void print();
};

//a=2 c=1 g=-1 t=-2

void read(char x[], char y[])
{

cout<<"enter the DNA string of father\n";
cin>>x;
cout<<"enter the DNA string of son\n";
cin>>y;

}

void print(char x[], char y[])
{
cout<<x<<endl;
cout<<y<<endl;
}



int bruteforce(int a[])
{

int i,j,k;

int sum,msum=0;


for(i=0;i<20;i++)
for(j=i;j<20;j++)
{
sum=0;
for(k=i;k<=j;k++)
sum=sum+a[k];

if(msum<sum)
	{
	msum=sum;
        }

}

return msum;

}


int incdesign(int a[])
{
int i,j,msum=0,sum;

for(i=0;i<20;i++)
	{
	sum=0;
	
	for(j=i;j<20;j++)
		{
		sum+=a[j];
		if(msum<sum)
		{
		msum=sum;
		beg1=i;
   	    end1=j;
		}

		}
	}
return msum;
}


int divnconq(int a[],int beg, int end)
{
int i;
int mid,LS,RS,msum;
int rosum=0,losum=0,rsum=0,lsum=0;

if(beg==end)
	if(a[beg]<0)
	return 0;
	else
	return a[beg];

mid=(beg+end)/2;
LS=divnconq(a,beg,mid);
RS=divnconq(a,mid+1,end);

for(i=mid;i<20;i++) 
	{
	rsum+=a[i];
	if(rsum>rosum)
	rosum=rsum;
	}

for(i=mid-1;i>=beg;i--)
	{
	lsum+=a[i];
	if(lsum>losum)
	losum=lsum;
	}

msum=losum+rosum;


if(LS>=RS && LS>=msum)
	return LS;
else if(RS>=LS && RS>=msum) 
	return RS;
else 
	return msum;
}

int pruning(int a[])
{
int i;
int msum=0;
int csum=0;

for(i=0;i<20;i++)
	{
	csum+=a[i];
	if(csum<0)
	csum=0;
	if(csum>msum)
	msum=csum;
	}

return msum;
}

void subseq(char x[])
{
int i;
for(i=beg1;i<=end1;i++)
cout<<x[i];

}


int main()
{
char father[20], son[20];
read(father,son);
//print(father,son);

int i;
int a[20],b[20];

for(i=0;i<20;i++)

{
if(father[i]=='a')
a[i]=2;
else if(father[i]=='c')
a[i]=1;
else if(father[i]=='g')
a[i]=-1;
else if(father[i]=='t')
a[i]=-2;

if(son[i]=='a')
b[i]=2;
else if(son[i]=='c')
b[i]=1;
else if(son[i]=='g')
b[i]=-1;
else if(son[i]=='t')
b[i]=-2;

}

cout<<endl;

cout<<"MCSSS of father by brute force is "<<bruteforce(a)<<endl;
cout<<"MCSSS of father by inc design is "<<incdesign(a)<<endl;
cout<<"MCSSS of father by div and conq is "<<divnconq(a,0,19)<<endl;
cout<<"MCSSS of father by pruning is "<<pruning(a)<<endl<<endl;

subseq(father);
cout<<endl<<endl;


cout<<"MCSSS of son by brute force is "<<bruteforce(b)<<endl;
cout<<"MCSSS of son by inc design is "<<incdesign(b)<<endl;
cout<<"MCSSS of son by div and conq is "<<divnconq(b,0,19)<<endl;
cout<<"MCSSS of son by pruning is "<<pruning(b)<<endl<<endl;

subseq(son);
cout<<endl<<endl;


int f1=pruning(a);
int s1=pruning(b);

int diff=f1-s1;
if(diff<0)
diff=-diff;

cout<<"diff of DNA sequence for father and son is "<<diff<<endl; 
}

