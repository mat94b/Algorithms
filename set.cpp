#include <iostream>

using namespace std;

struct set
{
	int ranking;
	set *parent;
};

void MakeSet(set& rep)
{
	rep.ranking = 0;
	rep.parent = &rep;
}

set* Find(set& x)
{
	if(&x != x.parent) x.parent = Find(*x.parent);
	return x.parent;
}

void Union(set& x, set& y)
{
	if(x.ranking > y.ranking) y.parent = &x;
	else 
	{
		x.parent = &y;
		if(x.ranking == y.ranking) y.ranking = y.ranking + 1;
	}
}

int main()
{
	return 0;
}
