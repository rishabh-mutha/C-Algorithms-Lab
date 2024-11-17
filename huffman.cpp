#include<bits/stdc++.h>
using namespace std;

string s;
string decoded;

struct MinHeapNode{
char data;
int freq;

MinHeapNode *left, *right;

MinHeapNode(char data, int freq)
	{
	   left=right=NULL;
	   this->data=data;
	   this->freq=freq;
	}
};

struct compare{

bool operator()(MinHeapNode *l, MinHeapNode *r)
	{
	return(l->freq > r->freq);	
	}
};

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

void printCodes(struct MinHeapNode *root, string str)
{
	if(!root)
	return;

	if(root->data!='$')
	cout<<root->data<<": "<<str<<endl;
	
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
struct MinHeapNode *left, *right, *top;

for(int i=0; i<size; i++)
minHeap.push(new MinHeapNode(data[i],freq[i]) );

while(minHeap.size() != 1)
	{
	left=minHeap.top();
	minHeap.pop();

	right=minHeap.top();
	minHeap.pop();

	top=new MinHeapNode('$',left->freq + right->freq);
	top->left=left;
	top->right=right;

	minHeap.push(top);
	}
printCodes(minHeap.top(),"");


}
/*
void HuffmanCodes1(char data[], int freq[], int size)
{
struct MinHeapNode *left, *right, *top;


for(int i=0; i<size; i++)
minHeap.push(new MinHeapNode(data[i],freq[i]) );

while(minHeap.size() != 1)
	{
	left=minHeap.top();
	minHeap.pop();

	right=minHeap.top();
	minHeap.pop();

	top=new MinHeapNode('$',left->freq + right->freq);
	top->left=left;
	top->right=right;

	minHeap.push(top);
	}

decoded="";

struct MinHeapNode *curr=minHeap.top();
for(int i=0; i<s.size(); i++)
	{
	if(s[i]==0)
	curr=curr->left;
	else 
	curr=curr->right;
	

if(curr->left==NULL && curr->right==NULL)
{
decoded+=curr->data;
curr=minHeap.top();
}

}
cout<<decoded;
}

*/

string answer(struct MinHeapNode *root, string s)
{
string ans="";
struct MinHeapNode *curr=root;
for(int i=0; i<s.size(); i++)
	{
	if(s[i]=='0')
	curr=curr->left;
	else 
	curr=curr->right;
	

if(curr->left==NULL && curr->right==NULL)
{
ans+=curr->data;
curr=root;
}

}
return ans;
}


int main()
{
char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
int freq[] = { 1, 11, 12, 5, 6, 7 };  
int size = sizeof(arr) / sizeof(arr[0]); 
  
HuffmanCodes(arr, freq, size);

cout<<"enter string to be decoded"<<endl;
cin>>s;

printCodes(minHeap.top(),"");
decoded=answer(minHeap.top(),s);
cout<<decoded;
return 0;
}

