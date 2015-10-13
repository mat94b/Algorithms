#include<iostream>
#define SIZE 256

using namespace std;

int result;
int zm;
int stug[SIZE];
int counter=-1;


void Enqueue(int liczba)
{
	int buffer;
	int l;
	stug[++counter]=liczba;
	zm=counter;
	while(zm!=0){
		if(stug[zm]<stug[(zm-1)/2])
		{
			buffer=stug[zm];
			l=stug[(zm-1)/2];
			stug[zm]=l;
			zm=(zm-1)/2;
			stug[zm]=buffer;
			cout<<"---- WSTAWIONO ELEMENT NA POCZATEK KOLEJKI -----"<<endl;
		}
		else break;
	}
}

void Dequeue()
{
	int temporary;
	int n;
	int buffer=stug[counter];
	stug[0]=buffer;
	zm=0;
	counter--;

	while(zm<=counter)
	{
		if(((2*zm)+1)==counter) 
			{
				buffer=stug[(2*zm)+1];
				n=1;
			}
		else if(((2*zm)+1)>counter)break;
		else 
		{
			buffer=stug[(2*zm)+1];
			n=1;
			if(stug[(2*zm)+2]<buffer)
			{
				buffer=stug[(2*zm)+2];
				n=2;
			}
		}

		if(buffer<stug[zm])
		{
			temporary=stug[zm];
			stug[zm]=buffer;
			stug[(2*zm)+n]=temporary;
		}

		else break;
	}
}

int FindMin()
{
	result=stug[0];
	cout<<"------ FindMin() wynosi: "<<result<<" ---------------------"<<endl;
	return result;
}


void display()
{
	cout<<"------------------------------------------------"<<endl;
	cout<<"------ AKTUANLIE W KOLEJCE ZNAJDUJA SIE --------"<<endl;
	cout<<"************************************************"<<endl;
	for(int i=0;i<counter+1;i++)
	{
		cout<<stug[i]<<" ";
		cout<<endl;
	}
	cout<<"************************************************"<<endl;
	cout<<"------------------------------------------------"<<endl;
}

void testEnqueue()
{
	Enqueue(2);
	Enqueue(1);
	Enqueue(4);
	Enqueue(11);
	Enqueue(1);
	Enqueue(3);
	Enqueue(23);
	Enqueue(24);
	Enqueue(32);
	Enqueue(0);
	Enqueue(18);
	Enqueue(99);

}

void testDequeue()
{
	Dequeue();
	Dequeue();
	Dequeue();
}


int main()
{
	cout<<"------------------------------------------------"<<endl;	
	cout<<"----- data: 21.V.2015 --------------------------"<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"------------------------------------------------"<<endl;
	testEnqueue();
	testDequeue();
	FindMin();
	display();
	cout<<"------------------------------------------------"<<endl;
	cout<<"-------------- KONIEC --------------------------"<<endl;
return 0;
}
