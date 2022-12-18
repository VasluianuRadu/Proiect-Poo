#include"Bilete.h"
#include"Eveniment.h"
#include"LocatieBilete.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


int main()
{
	Eveniment e;
	Bilete b;
	LocatieBilete a;
	e.citire();
	e.afisare();
	a.citire();
	a.afisare();
	b.citire();
	b.afisare();


}
