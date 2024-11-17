#include<iostream>
using namespace std;
#include <stdlib.h>
#include<time.h>

class Search
{
private:
int array[100];

public:
void buildrandomarray();
int linearsearch(int x);
int binarysearch(int x);
void avgtime();
};


void Search::buildrandomarray()
{
for(int i=0; i<100 ; i++)
array[i]=rand()%100;
}


int Search::linearsearch(int x)
{
int lscount=0;
for(int i=0; i<100 ; i++)

if(x==array[i])
	{
	lscount++;
	break;
	}

else lscount++;

return lscount;
}


int Search::binarysearch(int x)
{
//bubble sort
int temp;
for (int i = 0; i < 99; i++)       
   
   for (int j = 0; j < 99-i; j++)  
           {
           
           if (array[j] > array[j+1]) 
           {
              temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
           }
		   }

int beg=0;
int end=99;
int mid;
int flag=0;

while(beg<=end)
	{
	mid=(beg+end)/2;
		if(x==array[mid])
	 	{ flag++; break;}

		else if(x<array[mid])
		{
		end=mid-1;
		flag++;
		}

		else 
		{
		beg=mid+1;
		flag++;
		}

	}

return flag;
}


void Search::avgtime()
{

int ls=0;
int bs=0;
int i;
int random;
for(i=0; i<1000;i++)
	{
	Search::buildrandomarray();
	random=rand()%1000;
	ls+=Search::linearsearch(random);
	bs+=Search::binarysearch(random);
	}
ls=ls/1000;
bs=bs/1000;


cout<<"avg no of comp in ls is "<<ls<<" and avg no of comp in bs is "<<bs; 


}





int main()
{
srand(time(0));
class Search s;

int z=rand()%100;
int y;
s.buildrandomarray();
//int y=s.linearsearch(z);
//cout<<y<<"\n";

y=s.binarysearch(z);
cout<<y;

//s.buildrandomarray();
//s.avgtime();



}





