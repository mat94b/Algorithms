#include <iostream>


int tabtosort[] = {5, 2, 15, 8, 5, 13, 3, 1, 10, 2, 3, 31,30,7};



int num = sizeof(tabtosort)/sizeof(int);
using namespace std;



void display (int tab[])
{
	for(int z=0; z<num; ++z)
	{
		cout<<tab[z]<<", ";
	}
}

void sort(int tab[], int size)
{
	
	int i,p,count[256];
	for(i=0; i<256; i++) count[i] = 0;
	for(i=0; i<size; i++) count[tab[i]]++;
	for(p=i=0; i<256; i++) while(count[i]-- > 0) tab[p++] = i;
}



int main()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"-------------------------- SORTOWANIE ------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"-------- autor: MATEUSZ BUCZYNSKI --------- data: 04.03.2015 -------"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
	cout<<"Liczby do posortowania to: ";
	display(tabtosort);
	sort(tabtosort, num);
	cout<<"\n\n\n";
	cout<<"Liczby posortowane to: ";
	display(tabtosort);
	cout<<"\n\n\n";
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"---------------------------- KONIEC --------------------------------"<<endl;
	return 0;
}


