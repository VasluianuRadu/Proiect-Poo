#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class Eveniment
{
private:
	char* numeEveniment;
	struct dataEveniment
	{
		int zi;
		int luna;
		int an;
	};
	dataEveniment data;
	struct oraEveniment
	{
		int ora;
		int minut;
	};
	oraEveniment o;
	string locatieEveniment;

public:
	Eveniment()
	{
		this->numeEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->numeEveniment, "Necunoscut");
		this->data.zi = 0;
		this->data.luna = 0;
		this->data.an = 0;
		this->o.ora = 0;
		this->o.minut = 0;
		this->locatieEveniment = "Necunoscut";
	}
	Eveniment(char* numeEveniment, int zi, int luna, int an, int ora, int minut, string locatieEveniment)
	{
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy(this->numeEveniment, numeEveniment);
		this->data.zi = zi;
		this->data.luna = luna;
		this->data.an = an;
		this->o.ora = ora;
		this->o.minut = minut;
		this->locatieEveniment = locatieEveniment;
	}
	Eveniment(const Eveniment& e)
	{
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy(this->numeEveniment, e.numeEveniment);
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->o.ora = e.o.ora;
		this->o.minut = e.o.minut;
		this->locatieEveniment = e.locatieEveniment;
	}
	~Eveniment()
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
	}
	Eveniment& operator=(const Eveniment& e)
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy(this->numeEveniment, e.numeEveniment);
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->o.ora = e.o.ora;
		this->o.minut = e.o.minut;
		this->locatieEveniment = e.locatieEveniment;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Eveniment& e)
	{
		out << "Numele evenimentului: " << e.numeEveniment << endl;
		out << "Data evenimentului: " << e.data.zi << "." << e.data.luna << "." << e.data.an << endl;
		out << "Ora evenimentului: " << e.o.ora << ":" << e.o.minut << endl;
		out << "Locatia evenimentului: " << e.locatieEveniment << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Eveniment& e)
	{
		cout << "Numele evenimentului: ";
		char buffer[50];
		in >> ws;
		in.getline(buffer, 50);
		if (e.numeEveniment != NULL)
		{
			delete[] e.numeEveniment;
		}
		e.numeEveniment = new char[strlen(buffer) + 1];
		strcpy(e.numeEveniment, buffer);
		cout << "Data evenimentului: ";
		in >> e.data.zi;
		cout << ".";
		in >> e.data.luna;
		cout << ".";
		in >> e.data.an;
		cout << "Ora evenimentului: ";
		in >> e.o.ora;
		cout << ":";
		in >> e.o.minut;
		cout << "Locatia evenimentului: ";
		in >> ws;
		getline(in, e.locatieEveniment);
		return in;
	}
	void setNumeEveniment(char* numeEveniment)
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy(this->numeEveniment, numeEveniment);
	}
	char* getNumeEveniment()
	{
		if (this->numeEveniment != NULL)
		{
			return this->numeEveniment;
		}
		else
		{
			return NULL;
		}
	}
	void setDataEveniment(int zi, int luna, int an)
	{
		this->data.zi = zi;
		this->data.luna = luna;
		this->data.an = an;
	}
	void getDataEveniment(int& zi, int& luna, int& an)
	{
		zi = this->data.zi;
		luna = this->data.luna;
		an = this->data.an;
	}
	void setOraEveniment(int ora, int minut)
	{
		this->o.ora = ora;
		this->o.minut = minut;
	}
	void getOraEveniment(int& ora, int& minut)
	{
		ora = this->o.ora;
		minut = this->o.minut;
	}
	void setLocatieEveniment(string locatieEveniment)
	{
		this->locatieEveniment = locatieEveniment;
	}
	string getLocatieEveniment()
	{
		return this->locatieEveniment;
	}
	void afisare()
	{
		cout << "Numele evenimentului: " << this->numeEveniment << endl;
		cout << "Data evenimentului: " << this->data.zi << "." << this->data.luna << "." << this->data.an << endl;
		cout << "Ora evenimentului: " << this->o.ora << ":" << this->o.minut << endl;
		cout << "Locatia evenimentului: " << this->locatieEveniment << endl;
	}
	void citire()
	{
		cout << "Numele evenimentului: ";
		char buffer[50];
		cin >> ws;
		cin.getline(buffer, 50);
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(buffer) + 1];
		strcpy(this->numeEveniment, buffer);
		cout << "Data evenimentului: ";
		cin >> this->data.zi;
		cout << ".";
		cin >> this->data.luna;
		cout << ".";
		cin >> this->data.an;
		cout << "Ora evenimentului: ";
		cin >> this->o.ora;
		cout << ":";
		cin >> this->o.minut;
		cout << "Locatia evenimentului: ";
		cin >> ws;
		getline(cin, this->locatieEveniment);
	}
};