#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class Bilete
{
private:
	const int idBilet;
	static int contor;
	int NumarLoc;
	int NumarScaun;
	int numarCategorieBilete;
	char* CategorieBilete;
	float PretBilet;
public:
	Bilete() :idBilet(contor++)
	{
		this->NumarLoc = 0;
		this->NumarScaun = 0;
		this->numarCategorieBilete = 0;
		this->CategorieBilete = NULL;
		this->PretBilet = 0;
	}
	Bilete(int NumarLoc, int NumarScaun, int numarCategorieBilete, char* CategorieBilete, float PretBilet) :idBilet(contor++)
	{
		this->NumarLoc = NumarLoc;
		this->NumarScaun = NumarScaun;
		this->numarCategorieBilete = numarCategorieBilete;
		this->CategorieBilete = new char[strlen(CategorieBilete) + 1];
		strcpy(this->CategorieBilete, CategorieBilete);
		this->PretBilet = PretBilet;
	}
	Bilete(const Bilete& b) :idBilet(contor++)
	{
		this->NumarLoc = b.NumarLoc;
		this->NumarScaun = b.NumarScaun;
		this->numarCategorieBilete = b.numarCategorieBilete;
		this->CategorieBilete = new char[strlen(b.CategorieBilete) + 1];
		strcpy(this->CategorieBilete, b.CategorieBilete);
		this->PretBilet = b.PretBilet;
	}
	~Bilete()
	{
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
	}
	int getIdBilet()
	{
		return this->idBilet;
	}
	int getNumarLoc()
	{
		return this->NumarLoc;
	}
	int getNumarScaun()
	{
		return this->NumarScaun;
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
		return NULL;
	}
	float getPretBilet()
	{
		return this->PretBilet;
	}
	void setNumarLoc(int NumarLoc)
	{
		this->NumarLoc = NumarLoc;
	}
	void setNumarScaun(int NumarScaun)
	{
		this->NumarScaun = NumarScaun;
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
	void setPretBilet(float PretBilet)
	{
		this->PretBilet = PretBilet;
	}
	Bilete& operator=(const Bilete& b)
	{
		this->NumarLoc = b.NumarLoc;
		this->NumarScaun = b.NumarScaun;
		this->numarCategorieBilete = b.numarCategorieBilete;
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		this->CategorieBilete = new char[strlen(b.CategorieBilete) + 1];
		strcpy(this->CategorieBilete, b.CategorieBilete);
		this->PretBilet = b.PretBilet;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Bilete& b)
	{
		out << "NumarLoc: " << b.NumarLoc << endl;
		out << "NumarScaun: " << b.NumarScaun << endl;
		out << "numarCategorieBilete: " << b.numarCategorieBilete << endl;
		out << "CategorieBilete: " << b.CategorieBilete << endl;
		out << "PretBilet: " << b.PretBilet << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Bilete& b)
	{
		cout << "NumarLoc: ";
		in >> b.NumarLoc;
		cout << "NumarScaun: ";
		in >> b.NumarScaun;
		cout << "numarCategorieBilete: ";
		in >> b.numarCategorieBilete;
		if (b.CategorieBilete != NULL)
		{
			delete[] b.CategorieBilete;
		}
		b.CategorieBilete = new char[20];
		cout << "CategorieBilete: ";
		in >> b.CategorieBilete;
		cout << "PretBilet: ";
		in >> b.PretBilet;
		return in;
	}
	void citire()
	{
		cout << "NumarLoc: ";
		cin >> this->NumarLoc;
		cout << "NumarScaun: ";
		cin >> this->NumarScaun;
		cout << "numarCategorieBilete: ";
		cin >> this->numarCategorieBilete;
		if (this->CategorieBilete != NULL)
		{
			delete[] this->CategorieBilete;
		}
		this->CategorieBilete = new char[20];
		cout << "CategorieBilete: ";
		cin >> this->CategorieBilete;

	}
	void afisare()
	{
		cout << "NumarLoc: " << this->NumarLoc << endl;
		cout << "NumarScaun: " << this->NumarScaun << endl;
		cout << "numarCategorieBilete: " << this->numarCategorieBilete << endl;
		cout << "CategorieBilete: " << this->CategorieBilete << endl;
		cout << "PretBilet: " << this->PretBilet << endl;

	}
};
int Bilete::contor = 0;
