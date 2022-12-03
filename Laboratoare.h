#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Laborator
{
private:
	const int Cod;
	string Nume = "-----";
	string Adresa = "-----";
	float Chirie = 0;
	int NrAngajati = 0; //Numarul de angajati al fiecarui laborator.
	float* NrClientiAngajat = NULL; //Vector cu numarul de clienti al fiecarui angajat.
	static float CostTotalChirie;
	static int NrLaboratoare;
public:

	Laborator(int Cod):Cod(Cod)
	{
		Laborator::NrLaboratoare++;
	}

	Laborator(int Cod, string Nume, string Adresa, float Chirie, int NrAngajati, float* NrClientiAngajat) :Cod(Cod)
	{
		this->Nume = Nume;
		this->Adresa = Adresa;
		this->Chirie = Chirie;
		this->NrAngajati = NrAngajati;
		this->NrClientiAngajat = new float[this->NrAngajati];
		for (int i = 0; i < this->NrAngajati; i++)
		{
			this->NrClientiAngajat[i] = NrClientiAngajat[i];
		}
		Laborator::CostTotalChirie = Laborator::CostTotalChirie + this->Chirie;
		Laborator::NrLaboratoare++;
	}

	Laborator(const Laborator& L) :Cod(L.Cod)
	{
		this->Nume = L.Nume;
		this->Adresa = L.Adresa;
		this->Chirie = L.Chirie;
		this->NrAngajati = L.NrAngajati;
		this->NrClientiAngajat = new float[this->NrAngajati];
		for (int i = 0; i < this->NrAngajati; i++)
		{
			this->NrClientiAngajat[i] = L.NrClientiAngajat[i];
		}
	}

	~Laborator()
	{
		delete[]this->NrClientiAngajat;
	}

	Laborator& operator=(const Laborator& L)
	{
		if (this != &L)
		{
			this->Nume = L.Nume;
			this->Adresa = L.Adresa;
			this->Chirie = L.Chirie;
			this->NrAngajati = L.NrAngajati;
			this->NrClientiAngajat = new float[this->NrAngajati];
			for (int i = 0; i < this->NrAngajati; i++)
			{
				this->NrClientiAngajat[i] = L.NrClientiAngajat[i];
			}
		}
		return *this;
	}

	float operator[](int Pozitie)
	{
		return this->NrClientiAngajat[Pozitie];
	}

	void LaboratorInsertValues(int NrAC, float* V)
	{
		Laborator Copie = *this;
		delete[]this->NrClientiAngajat;
		this->NrAngajati = this->NrAngajati + NrAC;
		this->NrClientiAngajat = new float[this->NrAngajati];
		std::copy(Copie.NrClientiAngajat, Copie.NrClientiAngajat + Copie.NrAngajati, this->NrClientiAngajat);
		std::copy(V, V + NrAC, this->NrClientiAngajat + Copie.NrAngajati);
	}

	void LaboratorDeleteValues(float V)
	{
		for (int i = 0; i < this->NrAngajati; i++)
		{
			if (this->NrClientiAngajat[i] == V)
			{
				this->NrClientiAngajat[i] = 0;
			}
		}
	}

	Laborator operator+=(int Nr)
	{
		/* Se adauga Nr angajati noi care au 0 clienti */
		Laborator Copie = *this;
		delete[]this->NrClientiAngajat;
		this->NrAngajati += Nr;
		this->NrClientiAngajat = new float[this->NrAngajati];
		for (int i = 0; i < Copie.NrAngajati; i++)
		{
			this->NrClientiAngajat[i] = Copie.NrClientiAngajat[i];
		}
		for (int i = Copie.NrAngajati; i < this->NrAngajati; i++)
		{
			this->NrClientiAngajat[i] = 0;
		}
		return *this;
	}

	Laborator operator-=(int Nr)
	{
		/* Se adauga Nr angajati noi care au 0 clienti */
		Laborator Copie = *this;
		delete[]this->NrClientiAngajat;
		this->NrAngajati -= Nr;
		this->NrClientiAngajat = new float[this->NrAngajati];
		for (int i = 0; i < this->NrAngajati; i++)
		{
			this->NrClientiAngajat[i] = Copie.NrClientiAngajat[i];
		}
		return *this;
	}

	Laborator operator++() //++L
	{
		this->Chirie += 100;
		Laborator::CostTotalChirie += 100;
		return *this;
	}

	Laborator operator++(int) //L++
	{
		Laborator Rezultat = *this;
		this->Chirie += 100;
		Laborator::CostTotalChirie += 100;
		return Rezultat;
	}

	Laborator operator--() //--L
	{
		this->Chirie -= 100;
		Laborator::CostTotalChirie -= 100;
		return *this;
	}

	Laborator operator--(int) //L--
	{
		Laborator Rezultat = *this;
		this->Chirie -= 100;
		Laborator::CostTotalChirie -= 100;
		return Rezultat;
	}

	Laborator operator*(int V)
	{
		Laborator Copie = *this;
		Laborator::CostTotalChirie -= Copie.Chirie;
		this->Chirie = this->Chirie * V;
		Laborator::CostTotalChirie += this->Chirie;
		return *this;
	}

	Laborator operator/(int V)
	{
		Laborator Copie = *this;
		Laborator::CostTotalChirie -= Copie.Chirie;
		this->Chirie = this->Chirie / V;
		Laborator::CostTotalChirie += this->Chirie;
		return *this;
	}

	operator float()
	{
		return this->Chirie;
	}

	Laborator operator!()
	{
		this->Nume = "-----";
		this->Adresa = "-----";
		this->Chirie = 0;
		this->NrAngajati = 0;
		delete[]this->NrClientiAngajat;
		this->NrClientiAngajat = NULL;
		return *this;
	}

	friend bool operator>(Laborator& L1, Laborator& L2)
	{
		return L1.Chirie > L2.Chirie;
	}

	friend bool operator<(Laborator& L1, Laborator& L2)
	{
		return L1.Chirie < L2.Chirie;
	}

	friend bool operator>=(Laborator& L1, Laborator& L2)
	{
		return L1.Chirie >= L2.Chirie;
	}

	friend bool operator<=(Laborator& L1, Laborator& L2)
	{
		return L1.Chirie <= L2.Chirie;
	}

	friend bool operator==(Laborator& L1, Laborator& L2)
	{
		int b = 1;
		if ((L1.Cod == L2.Cod) && (L1.Nume == L2.Nume) && (L1.Chirie == L2.Chirie) && (L1.NrAngajati == L2.NrAngajati))
		{
			for (int i = 0; i < L1.NrAngajati; i++)
			{
				if (L1.NrClientiAngajat[i] != L2.NrClientiAngajat[i])
				{
					b = 0;
				}
			}
			if (b)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	friend istream& operator>>(istream& in, Laborator& L)
	{
		delete[]L.NrClientiAngajat;
		getline(in, L.Nume);
		getline(in, L.Adresa);
		in >> L.Chirie;
		in >> L.NrAngajati;
		L.NrClientiAngajat = new float[L.NrAngajati];
		for (int a = 0; a < L.NrAngajati; a++)
		{
			in >> L.NrClientiAngajat[a];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Laborator& L)
	{
		out << "\n" << L.Nume;
		out << "\n" << L.Adresa;
		out << "\n" << L.Chirie;
		for (int a = 0; a < L.NrAngajati; a++)
		{
			out << "\n" << L.NrClientiAngajat[a];
		}
		out << "\n" << Laborator::CostTotalChirie;
		out << "\n" << Laborator::NrLaboratoare;
		return out;
	}

	void SETNume(string Nume);
	void SETAdresa(string Adresa);
	void SETChirie(float Chirie);
	void SETClientiAngajati(int NrAngajati, float* NrClientiAngajat);
	string GETNume();
	string GETAdresa();
	float GETChirie();
	float* GETClientiAngajati();
};
float Laborator::CostTotalChirie = 0;
int Laborator::NrLaboratoare = 0;

void Laborator::SETNume(string Nume)
{
	if (Nume.length() > 1)
	{
		this->Nume = Nume;
	}
}

void Laborator::SETAdresa(string Adresa)
{
	if (Adresa.length() > 1)
	{
		this->Adresa = Adresa;
	}
}

void Laborator::SETChirie(float Chirie)
{
	if (Chirie > 0)
	{
		this->Chirie = Chirie;
	}
}

void Laborator::SETClientiAngajati(int NrAngajati, float* NrClientiAngajat)
{
	this->NrAngajati = NrAngajati;
	delete[]this->NrClientiAngajat;
	this->NrClientiAngajat = new float[this->NrAngajati];
	for (int i = 0; i < this->NrAngajati; i++)
	{
		this->NrClientiAngajat[i] = NrClientiAngajat[i];
	}
}

string Laborator::GETNume()
{
	return this->Nume;
}

string Laborator::GETAdresa()
{
	return this->Adresa;
}

float Laborator::GETChirie()
{
	return this->Chirie;
}

float* Laborator::GETClientiAngajati()
{
	return this->NrClientiAngajat;
}