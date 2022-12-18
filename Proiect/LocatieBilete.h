#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class LocatieBilete
{
private:
	int NrMaxLocuri;
	int numarCategorieBilete;
	char* CategorieBilete;
	int* NumarScaun;
public:
	LocatieBilete()
	{
		this->NrMaxLocuri = 0;
		this->numarCategorieBilete = 0;
		this->CategorieBilete = new char[strlen("Necunoscut") + 1];
		strcpy(this->CategorieBilete, "Necunoscut");
		this->NumarScaun = new int[0];
	}
	LocatieBilete(int NrMaxLocuri, int numarCategorieBilete, char* CategorieBilete, int* NumarScaun)
	{
		this->NrMaxLocuri = NrMaxLocuri;
		this->numarCategorieBilete = numarCategorieBilete;
		this->CategorieBilete = new char[strlen(CategorieBilete) + 1];
		strcpy(this->CategorieBilete, CategorieBilete);
		this->NumarScaun = new int[numarCategorieBilete];
		for (int i = 0; i < numarCategorieBilete; i++)
		{
			this->NumarScaun[i] = NumarScaun[i];
		}
	}
	LocatieBilete(const LocatieBilete& l)
	{
		this->NrMaxLocuri = l.NrMaxLocuri;
		this->numarCategorieBilete = l.numarCategorieBilete;
		this->CategorieBilete = new char[strlen(l.CategorieBilete) + 1];
		strcpy(this->CategorieBilete, l.CategorieBilete);
		this->NumarScaun = new int[l.numarCategorieBilete];
		for (int i = 0; i < l.numarCategorieBilete; i++)
		{
			this->NumarScaun[i] = l.NumarScaun[i];
		}
	}
	~LocatieBilete()
	{
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		if (this->NumarScaun != NULL)
		{
			delete[] this->NumarScaun;
		}
	}
	LocatieBilete& operator=(const LocatieBilete& l)
	{
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		if (this->NumarScaun != NULL)
		{
			delete[] this->NumarScaun;
		}
		this->NrMaxLocuri = l.NrMaxLocuri;
		this->numarCategorieBilete = l.numarCategorieBilete;
		this->CategorieBilete = new char[strlen(l.CategorieBilete) + 1];
		strcpy(this->CategorieBilete, l.CategorieBilete);
		this->NumarScaun = new int[l.numarCategorieBilete];
		for (int i = 0; i < l.numarCategorieBilete; i++)
		{
			this->NumarScaun[i] = l.NumarScaun[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, LocatieBilete& l)
	{
		out << "Numarul maxim de locuri este: " << l.NrMaxLocuri << endl;
		out << "Numarul de categorii de bilete este: " << l.numarCategorieBilete << endl;
		out << "Categoriile de bilete sunt: " << l.CategorieBilete << endl;
		out << "Numarul de scaune este: " << endl;
		for (int i = 0; i < l.numarCategorieBilete; i++)
		{
			out << l.NumarScaun[i] << " ";
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, LocatieBilete& l)
	{
		cout << "Introduceti numarul maxim de locuri: ";
		in >> l.NrMaxLocuri;
		cout << "Introduceti numarul de categorii de bilete: ";
		in >> l.numarCategorieBilete;
		cout << "Introduceti categoriile de bilete: ";
		char buffer[50];
		in >> buffer;
		if (l.CategorieBilete != NULL)
		{
			delete[] l.CategorieBilete;
		}
		l.CategorieBilete = new char[strlen(buffer) + 1];
		strcpy(l.CategorieBilete, buffer);
		if (l.NumarScaun != NULL)
		{
			delete[] l.NumarScaun;
		}
		l.NumarScaun = new int[l.numarCategorieBilete];
		for (int i = 0; i < l.numarCategorieBilete; i++)
		{
			cout << "Introduceti numarul de scaune pentru categoria " << i + 1 << ": ";
			in >> l.NumarScaun[i];
		}
		return in;
	}
	int getNrMaxLocuri()
	{
		return this->NrMaxLocuri;
	}
	int getNumarCategorieBilete()
	{
		return this->numarCategorieBilete;
	}
	char* getCategorieBilete()
	{
		if (this->CategorieBilete != NULL)
		{
			return this->CategorieBilete;
		}
		else
		{
			return NULL;
		}
	}
	int* getNumarScaun()
	{
		if (this->NumarScaun != NULL)
		{

			return this->NumarScaun;
		}
		else
		{
			return NULL;
		}
	}
	void setNrMaxLocuri(int NrMaxLocuri)
	{
		this->NrMaxLocuri = NrMaxLocuri;
	}
	void setNumarCategorieBilete(int numarCategorieBilete)
	{
		this->numarCategorieBilete = numarCategorieBilete;
	}
	void setCategorieBilete(char* CategorieBilete)
	{
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		this->CategorieBilete = new char[strlen(CategorieBilete) + 1];
		strcpy(this->CategorieBilete, CategorieBilete);
	}
	void setNumarScaun(int* NumarScaun)
	{
		if (this->NumarScaun != NULL)
		{
			delete[] this->NumarScaun;
		}
		this->NumarScaun = new int[this->numarCategorieBilete];
		for (int i = 0; i < this->numarCategorieBilete; i++)
		{
			this->NumarScaun[i] = NumarScaun[i];
		}
	}
	bool operator==(LocatieBilete& l)
	{
		return (this->NrMaxLocuri == l.NrMaxLocuri && this->numarCategorieBilete == l.numarCategorieBilete && strcmp(this->CategorieBilete, l.CategorieBilete) == 0);
	}
	void operator++()
	{
		this->NrMaxLocuri++;
	}
	void citire()
	{

		cout << "Introduceti numarul maxim de locuri: ";
		cin >> this->NrMaxLocuri;
		cout << "Introduceti numarul de categorii de bilete: ";
		cin >> this->numarCategorieBilete;
		cout << "Introduceti categoriile de bilete: ";
		char buffer[50];
		cin >> buffer;
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		this->CategorieBilete = new char[strlen(buffer) + 1];
		strcpy(this->CategorieBilete, buffer);
		if (this->NumarScaun != NULL)
		{
			delete[] this->NumarScaun;
		}
		this->NumarScaun = new int[this->numarCategorieBilete];
		for (int i = 0; i < this->numarCategorieBilete; i++)
		{
			cout << "Introduceti numarul de scaune pentru categoria " << i + 1 << ": ";
			cin >> this->NumarScaun[i];
		}
	};
	void afisare()
	{
		cout << "Numarul maxim de locuri este: " << this->NrMaxLocuri << endl;
		cout << "Numarul de categorii de bilete este: " << this->numarCategorieBilete << endl;
		cout << "Categoriile de bilete sunt: " << this->CategorieBilete << endl;
		cout << "Numarul de scaune este: " << endl;
		for (int i = 0; i < this->numarCategorieBilete; i++)
		{
			cout << this->NumarScaun[i] << " ";
		}
		cout << endl;
	}
};
