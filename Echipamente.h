#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Echipament
{
private:
	const int Cod;
	string Nume = "-----";
	float P = 0; //Pretul unui echipament.
	int Q = 0; //Numarul de echipamente cumparate.
	int* Laborator = NULL; //Codul laboratorului la care se trimite echipamentul;
	static float ProcentTaxeImpoziteEchipament;
	static float MarirePret;

public:

	Echipament(int Cod):Cod(Cod){}

	Echipament(int Cod, string Nume, float P, int Q, int* Laborator) :Cod(Cod)
	{
		this->Nume = Nume;
		this->P = P;
		this->Q = Q;
		this->Laborator = new int[this->Q];
		for (int i = 0; i < this->Q; i++)
		{
			this->Laborator[i] = Laborator[i];
		}
	}

	Echipament(const Echipament& E) :Cod(E.Cod)
	{
		this->Nume = E.Nume;
		this->P = E.P;
		this->Q = E.Q;
		this->Laborator = new int[this->Q];
		for (int i = 0; i < this->Q; i++)
		{
			this->Laborator[i] = E.Laborator[i];
		}
	}

	~Echipament()
	{
		delete[]this->Laborator;
	}

	Echipament& operator=(const Echipament& E)
	{
		if (this != &E)
		{
			this->Nume = E.Nume;
			this->P = E.P;
			this->Q = E.Q;
			this->Laborator = new int[this->Q];
			for (int i = 0; i < this->Q; i++)
			{
				this->Laborator[i] = E.Laborator[i];
			}
		}
		return *this;
	}

	int operator[](int Pozitie)
	{
		return this->Laborator[Pozitie];
	}

	void EchipamentInsertValues(int Nr, int* V)
	{
		Echipament Copie = *this;
		delete[]this->Laborator;
		this->Q = this->Q + Nr;
		this->Laborator = new int[this->Q];
		std::copy(Copie.Laborator, Copie.Laborator + Copie.Q, this->Laborator);
		std::copy(V, V + Nr, this->Laborator + Copie.Q);
	}

	void ExhipamentDeleteValue(int V)
	{
		for (int i = 0; i < this->Q; i++)
		{
			if (this->Laborator[i] == V)
			{
				this->Laborator[i] = 0;
			}
		}
	}

	Echipament operator+=(int Nr)
	{
		Echipament Copie = *this;
		delete[]this->Laborator;
		this->Q += Nr;
		this->Laborator = new int[this->Q];
		for (int i = 0; i < Copie.Q; i++)
		{
			this->Laborator[i] = Copie.Laborator[i];
		}
		for (int i = Copie.Q; i < this->Q; i++)
		{
			this->Laborator[i] = 0;
		}
		return *this;
	}

	Echipament operator-=(int Nr)
	{
		Echipament Copie = *this;
		delete[]this->Laborator;
		this->Q -= Nr;
		this->Laborator = new int[this->Q];
		for (int i = 0; i < this->Q; i++)
		{
			this->Laborator[i] = Copie.Laborator[i];
		}
		return *this;
	}

	Echipament operator++()//++E;
	{
		this->P += Echipament::MarirePret;
		return *this;
	}

	Echipament operator++(int)//E++;
	{
		Echipament Rezultat = *this;
		this->P += Echipament::MarirePret;
		return Rezultat;
	}

	Echipament operator--()//--E;
	{
		this->P -= Echipament::MarirePret;
		return *this;
	}

	Echipament operator--(int)//E--;
	{
		Echipament Rezultat = *this;
		this->P -= Echipament::MarirePret;
		return Rezultat;
	}

	Echipament operator*(int Nr)
	{
		this->P = this->P * Nr;
		return *this;
	}

	Echipament operator/(int Nr)
	{
		this->P = this->P / Nr;
		return *this;
	}

	Echipament operator!()
	{
		this->Nume = "-----";
		this->P = 0;
		this->Q = 0; //Numarul de echipamente cumparate.
		delete[]this->Laborator; this->Laborator = NULL;
		return *this;
	}

	operator float()
	{
		return this->P;
	}

	friend bool operator>(Echipament& E1, Echipament& E2)
	{
		return E1.P > E2.P;
	}

	friend bool operator>=(Echipament& E1, Echipament& E2)
	{
		return E1.P >= E2.P;
	}

	friend bool operator<(Echipament& E1, Echipament& E2)
	{
		return E1.P < E2.P;
	}

	friend bool operator<=(Echipament& E1, Echipament& E2)
	{
		return E1.P <= E2.P;
	}

	friend bool operator==(Echipament& E1, Echipament& E2)
	{
		int b = 1;
		if ((E1.Nume == E2.Nume) && (E1.P == E2.P) && (E1.Q == E2.Q))
		{
			for (int i = 0; i < E1.Q; i++)
			{
				if (E1.Laborator[i] != E2.Laborator[i])
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

	friend istream& operator>>(istream& in, Echipament& E)
	{
		delete[]E.Laborator;
		getline(in, E.Nume);
		in >> E.P;
		in >> E.Q;
		E.Laborator = new int[E.Q];
		for (int a = 0; a < E.Q; a++)
		{
			in >> E.Laborator[a];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Echipament& E)
	{
		out << "\n" << E.Nume;
		out << "\n" << E.P;
		for (int a = 0; a < E.Q; a++)
		{
			out << "\n" << E.Laborator[a];
		}
		return out;
	}

	void SETNume(string Nume)
	{
		if (Nume.length() > 1)
		{
			this->Nume = Nume;
		}
	}

	string GETNume()
	{
		return this->Nume;
	}

	void SETPret(float P)
	{
		if (P > 0)
		{
			this->P = P;
		}
	}

	float GETPret()
	{
		return this->P;
	}

	void SETCantitate(int Q)
	{
		if (Q > 0)
		{
			this->Q = Q;
		}
	}

	int GETCantitate()
	{
		return this->Q;
	}

	void SETLaboratoare(int* Laborator, int Q)
	{
		this->Q = Q;
		delete[]this->Laborator;
		this->Laborator = new int[this->Q];
		for (int i = 0; i < this->Q; i++)
		{
			this->Laborator[i] = Laborator[i];
		}
	}

	int* GETLaboratoare()
	{
		return this->Laborator;
	}
};
float Echipament::ProcentTaxeImpoziteEchipament = 0.027;
float Echipament::MarirePret = 50;