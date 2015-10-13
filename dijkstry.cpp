/*
*	autor: Mateusz Buczynski
*	data: 5.V.2015
*	projekt: AiSD
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int tablica[3][225];
int visited[10];
bool fir=false;
int licznik=1;
bool sec=false;

bool security(char o){
	if(o==',' || o==' ' || o=='1' || o=='2' || o=='3' || o=='4' || o=='5' || o=='6' || o=='7' || o=='8' || o=='9') return false;
	else return true;	
}

bool securityFirst(string o){
	if(o=="," || o==" " || o=="1" || o=="2" || o=="3" || o=="4" || o=="5" || o=="6" || o=="7" || o=="8" || o=="9") return false;
	else return true;
}

bool securityNumber(int o, int p){
	for(int k=0;k<p;++k){
		if(o==k) return false;
	}
	return true;
}


int dijkstry(int p, int k)
{	
	int uzyte_iterator=0;
	int poczatkowy = p;
	int koncowy = k;
	int findFirst=0;
	int noodTemporary;
	int shortest=999;
	int shortestY;
	int temp;
	bool busyempty=false;
	bool checker=false;
	bool exist=false;
	while(tablica[0][findFirst]!=p)	++findFirst;
	while(tablica[0][findFirst]==p){
		for(int z=0;z<100;++z){
			if(tablica[1][findFirst]==visited[z]) checker=true;
		}
		if(tablica[2][findFirst]<shortest && checker==false){
			shortest=tablica[2][findFirst];
			shortestY=tablica[1][findFirst];
			exist=true;
		}
		++findFirst;
		checker=false;
	}

	for(int i=0;i<11;++i){
		if(shortestY==visited[i]) busyempty=true;
	}	
	if(busyempty==false){
		visited[licznik]=shortestY;
		++licznik;
	}
	if(exist==false){
		cout<<"Sciezki nie udalo sie odnalezc!"<<endl;
	 	return 99;
	}

	cout<<"z punktu: "<<p<<" do punktu "<<shortestY<< " KOSZT======> " <<shortest<<endl;
	
	if(shortestY==koncowy) return 0;
	else if(shortestY!=koncowy){
		exist=false;
		return dijkstry(shortestY,koncowy);
	}	
}

int main(int argc, char *argv[])
{
	if(argc!=2) cout<<"BLEDNA LICZBA PARAMETROW! JAKO PARAMETR PODAJ NAZWE PLIKU\n";
        string napis;
	int start;
	int stop;
	char *in=argv[1];
	fstream plik;
    	plik.open( in, ios::in );
    	if( plik.good() )
    	{
        	string napis; 	
               	getline( plik, napis );
		if (securityFirst(napis)==true){
			cout<<"\n\n\nPLIK Z DANYMI DO ODCZYTU MA BLEDNA STRUKTURE!!!"<<endl;
			cout<<"1-linjia, musi zawierac liczbe wierzcholkow!"<<endl;
			return 0;
		}
		int i=atoi(napis.c_str());
		bool character_controler;
		int nood=1;
		int index=0;
		char c;
		while( !plik.eof())
		{
               		getline( plik, napis );
			int string_l=napis.length(); 
			character_controler=false;
			for(int i=0; i<string_l; ++i)
			{
				c=napis.at(i);
				if (security(c)==true){
					cout<<"\n\n\nPLIK Z DANYMI DO ODCZYTU MA BLEDNA STRUKTURE!!!"<<endl;
					cout<<"PROSZE PODAC POPRAWNY PLIK"<<endl;
					return 0;
				}
				if(c==' ') continue;
				else if(character_controler==false)
				{
					tablica[0][index]=nood;
					int z=c-'0';
					tablica[1][index]=z;
					character_controler=true;
				}
				else if(character_controler==true && c!=' ' && c!=','){ tablica[2][index]=c-'0'; ++index;}
				else if(c==',')	character_controler=false;
			}	
			++nood;
        	}
        	plik.close();			

		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"- autor:            -------------------- data     ----------------"<<endl;
		cout<<"- Mateusz Buczynski -------------------- 5.V.2015 ----------------"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		do{
			cout<<"\n\n\n\nPODAJ WIERZCHOLEK POCZATKOWY: "; cin>>start;
			if(securityNumber(start,i)==true){
				cout<<"WIERZCHOLEK O TAKIM NUMERZE NIE ISTNIEJE"<<endl;
				cout<<"SPROBUJ WPISAC PONOWNIE! ";
		}
		}while(securityNumber(start,i)==true);
		do{
			sec=false;
			cout<<"PODAJ WIERZCHOLEK KONCOWY: "; cin>>stop;
			if(securityNumber(stop,i)==true){
				cout<<"WIERZCHOLEK O TAKIM NUMERZE NIE ISTNIEJE"<<endl;
				cout<<"SPROBUJ WPISAC PONOWNIE! "<<endl;
			}
			if(start==stop){
				cout<<"WIERZCHOLEK STARTOWY, ORAZ KONCOWY NIE MOGA BYC IDENTYCZNE!"<<endl; 
				sec=true;
			}
		}while(securityNumber(stop,i)==true || sec ==true);


		visited[0]=start;
		dijkstry(start,stop);


		cout<<"\n";
    	} else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;

    return( 0 );
}
