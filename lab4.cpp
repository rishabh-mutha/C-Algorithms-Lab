#include<iostream>
using namespace std;

class Celebrity
{
private:
	int n;

public:
	int celebrity();
    int dosa();
};

int Celebrity::celebrity()
{

cout<<"enter the number of people"<<endl;
cin>>n;
int a[n][n];
int i,j;
	for(i=0;i<n;i++)
	{
	cout<<"enter the know-relationship of person "<<i<<endl;
	for(j=0; j<n; j++)	
		cin>>a[i][j];
	}


int b[n];

for(i=0;i<n;i++)
b[i]=1;

i=0;j=0;
int k=0;

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
if(i!=j)
if(a[i][j]==1)
{
b[i]=0;
}

else
{
b[j]=0;
}

}

for(i=0; i<n; i++)
cout<<b[i]<<endl;

//cout<<a[0][0];
}


int dosa(int end, int count, int a[])
{
if(end==0)
return count;

int max=a[0], imax=0;
int i;

for(i=0;i<end;i++)
if(a[i]>max)
	{
	max=a[i];
	imax=i;
	}

// flip from 0 to imax
int x;
for(i=0;i<=imax/2;i++)
{
x=a[i];
a[i]=a[imax-i];
a[imax-i]=x;
}

// flip from 0 to end
for(i=0;i<=end/2;i++)
{
x=a[i];
a[i]=a[imax-i];
a[imax-i]=x;
}

count=count+2;

return(dosa(end-1,count,a));


}


int main()
{
Celebrity c;
c.celebrity();

int end;

cout<<"enter the number of dosas"<<endl;
cin>>end;
int i;
int a[end];
	
cout<<"enter the radii of dosas "<<endl;	

for(i=0;i<end;i++)
	{
		cin>>a[i];
	}


cout<<endl<<dosa(end,0,a);

}




