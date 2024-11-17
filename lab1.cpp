#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

class Sort
{
private:
int array[10];

public:
int bubblesort();
int insertionsort();
int selectionsort();
};


int Sort::bubblesort()
{
int i;
//cout<<"performing bubblesort\n";
for(i=0;i<10;i++)
array[i]=rand()%30+2;

//bubble sort
int temp,j;
int bubblecount=0; 
   for (i = 0; i < 9; i++)       
   
   for (j = 0; j < 9-i; j++)  
           {
           bubblecount++;
           if (array[j] > array[j+1]) 
           {
              temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
           }
		   }
		   
//for(i=0;i<10;i++)
//cout<<array[i]<<" ";

return bubblecount;
}




int Sort::insertionsort()

{
int i;
//cout<<"performing insertionsort\n";
for(i=0;i<10;i++)
array[i]=rand()%30+2;

// insertion sort

int key,j;
int insertioncount=0;
for (i = 1; i < 10; i++) 
   { 
       key = array[i]; 
       j = i-1; 
  
       while (j >= 0 && array[j] > key) 
       { 
           insertioncount++;
           array[j+1] = array[j]; 
           j = j-1; 
       } 
       array[j+1] = key; 
   } 
 

//for(i=0;i<10;i++)
//cout<<array[i]<<" ";

return insertioncount;
}



int Sort::selectionsort()
{
int i;
//cout<<"performing selectionsort\n";
for(i=0;i<10;i++)
array[i]=rand()%30+2;

// selection sort

int j;
int selectioncount=0;
int min_idx; 
int temp;  
for (i = 0; i < 10-1; i++) 
    { 
        
        min_idx = i; 
        for (j = i+1; j < 10; j++) 
          if (array[j] < array[min_idx]) 
            {min_idx = j; selectioncount++;} 
  
        temp=array[min_idx];
        array[min_idx]=array[i];
        array[i]=temp;
  
    } 

//for(i=0;i<10;i++)
//cout<<array[i]<<" ";

return selectioncount;
}





int main()
{

srand(time(0));
class Sort s;

s.bubblesort();     
s.insertionsort();     
s.selectionsort();     
     
int bub[20];
int ins[20];
int sel[20];


int x;

for(x=0;x<20;x++)

{
bub[x]=s.bubblesort();     
ins[x]=s.insertionsort();
sel[x]=s.selectionsort();     
}

cout<<"bubblesort       insertionsort         selectionsort\n";


for(x=0;x<20;x++)
cout<<bub[x]<<"  	         "<<ins[x]<<"                 	    "<<sel[x]<<"\n";


int bubmean=0,insmean=0, selmean=0;

for(x=0;x<20;x++)
{
bubmean+=bub[x];
insmean+=ins[x];
selmean+=sel[x];

}

bubmean=bubmean/20;
insmean=insmean/20;
selmean=selmean/20;

cout<<"\n\n\n"<<bubmean<<" 	          "<<insmean<<"               	    "<<selmean<<"\n";




















}
