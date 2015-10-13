#include<iostream>
#define SIZE 256

using namespace std;

struct Car
{
	char PlateNumber[12];
	int Year;
	bool Truck;

};

Car stug[SIZE];
int counter=-1;

void Enqueue(Car str)
{
	int Year=str.Year;
	bool Truck=str.Truck;
	Car buffer;
	Car l;
	int k=counter;
	while(k!=0)
	{
		if(stug[k].Year < stug[(k-1)/2].Year){
			buffer=stug[k];
			l=stug[(k-1)/2];
			stug[k]=l;
			k=(k-1)/2;
			stug[k]=buffer;
		}
	}
}

void Dequeue()
{
	//nie zdazylem tego poprawic
	//*************************************
	Car temporary;
	int n;
	Car buffer=stug[counter];
	stug[0]=buffer;
	int zm=0;
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
			buffer.Year=stug[(2*zm)+1].Year;
			n=1;
			if(stug[(2*zm)+2].Year<buffer.Year)
			{
				buffer=stug[(2*zm)+2];
				n=2;
			}
		}

		if(buffer.Year<stug[zm].Year)
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
	for(int i=0;i<counter+1;i++)
	{
		int maxOsobowe=2018;
		int minCiezarow=1900;
		if(stug[i].Year<maxOsobowe && stug[i].Truck==0)maxOsobowe=stug[i].Year;
		if(stug[i].Year>minCiezarow && stug[i].Truck==1)minCiezarow=stug[i].Year;
	
		cout<<"najstarszy osobowy to: "<<maxOsobowe<<endl;
		cout<<"najmlodszy ciezarowy to: "<<minCiezarow<<endl;
		cout<<endl;
	}
}







int main()
{
	Car suzuki;
	Car audi;
	suzuki.Year=2012;
	suzuki.Truck=false;
	suzuki.Year=2009;
	suzuki.Truck=false;
	Enqueue(suzuki);
	Enqueue(audi);
	
   FindMin();
	
	return 0;
}
