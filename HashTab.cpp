#include <iostream>
#include <string>

const int SIZE = 150;
const int MASK = (SIZE - 1);
using namespace std;

class HashTable {
    string s;
    int    i;
public:
    HashTable(const string& s = "No Name", int i=0) {
        this->s = s;
        this->i = i;
    }
    int getInt() { return i; }
    string getString() { return s; }
};

HashTable ktab[SIZE]; // Tablica przechowuje pary string, int jako obiekty, w tablicy obiektow

int hash(string s, int a)
{
	// Funkcja haszujaca nr. 1
	// wylicza "hash" za pomoca string
        unsigned int h = 0;
        for (unsigned int i = 0; i < s.length(); i++)
            h += s[i];
		int hasz=(h * 1049) & MASK;
	// Funkcja haszujaca nr. 2 
		if(ktab[hasz].getString() != "EMPTY")
		{
			--hasz;
		}
		return hasz;
}


void Insert(string s, int i)
{
	int index = hash(s,i); // wylicza index za pomoca funkcji haszujacej
	
	// Upewnia sie ze wyliczony index jest pusty, jesli nie to szuka nowej pozycji.
	if(ktab[index].getString() != "EMPTY")
	{
		for(int i=0; ktab[index].getString() != "EMPTY" && i != SIZE; ++i)
		{
			--index;	
			if(index==0) index = MASK;
		}
	}
	
	// Wstawia pary string i int w odnaleziony index
	if(ktab[index].getString() == "EMPTY")
	{
	
		HashTable in_obj(s,i);
		ktab[index] = in_obj;
	}
	else cout<< "Zabraklo miejsca w tablicy.. Nie mozna wstawic elementu\n";
}

void Find(string s, int i)
{
	int index = hash(s,i); // wylicza index za pomoca funkcji haszujacej
	
	// Jesli na pozycji nie ma szukanego elementu, przeszukuje tablice dalej
	if(ktab[index].getString() != s)
	{
		for(int i=0; ktab[index].getString() != s && i != SIZE; ++i)
		{
			--index;	
			if(index==0) index = MASK;
		}
	}
	
	// Jak juz odnajdzie to wypisuje na ekran, gdzie sie element znajduje
	if(ktab[index].getString() == s)
	{
		cout<<"Wyszukiwanie dla elementu String: "<<ktab[index].getString()<<", Int: "<<ktab[index].getInt()<<endl;
		cout<<"Element znajduje sie na pozycji: "<<index<<endl;
		cout<<"---------------------------------------------------------"<<endl;
	}
	else cout<< "Nie ma takiego elementu w tablicy!\n";
}

void Delete(string s, int i)
{
	int index = hash(s,i); // wylicza index za pomoca funkcji haszujacej
	
	// Jesli szukanego elementu tam nie ma, przeszukuje tablice dalej
	if(ktab[index].getString() != s)
	{
		for(int i=0; ktab[index].getString() != s && i != SIZE; ++i)
		{
			--index;	
			if(index==0) index = MASK;
		}
	}
	
	// Usuwa element
	if(ktab[index].getString() == s)
	{
	
		HashTable empty("EMPTY", 0);
		ktab[index] = empty;
	}
	else cout<< "Nie ma takiego elementu w tablicy!\n";
}

void Display()
{
	// Wyswietla aktualny stan tablicy
	    for (int i = 0; i < 150; i++)
        cout <<"Index["<<i<<"]"<< "   String: "<< ktab[i].getString() << "    Int: "
             << ktab[i].getInt()  << endl;
}

int main(void) {
	
	// Inicjalizuje tablice flagami <EMPTY>
	HashTable empty("EMPTY", 0);
	for(int a=0; a<SIZE; ++a) ktab[a]=empty;

cout<<"---------------------------------------------------------"<<endl;
cout<<"Mateusz Buczynski-----------------------25.03.2015-------"<<endl;
cout<<"---------------------------------------------------------"<<endl;

// Tablica przechowuje pary string, int jako obiekty, w tablicy obiektow

  Insert("Test 1", 2000);
  Insert("Test 2", 43);
  Insert("Test 3", 23);
  Insert("Test 4", 1);
  Insert("Test Test Test 23", 88);
  Insert("Test Test Test Test", 901);
  
  Find("Test 4", 2000);
  
  Delete("Test 1", 0);

  Display(); // Wyswietla koncowy stan tablicy
}
