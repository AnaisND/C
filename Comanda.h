#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Comanda
{
public:

	string NumeComanda = "-----";
	string NumeClasa = "-----";
	string NumeColoana = "-----";
	static int StartingPointAngajat;
	static int StartingPointClient;
	static int StartingPointEchipament;
	static int StartingPointLaborator; //Starting point = numarul de la care incep codurile fiecaruia.



	~Comanda() {}

	void SETNumeComanda(string NNumeComanda)
	{
		this->NumeComanda = NNumeComanda;
	}

	void SETNumeClasa(string NNumeClasa)
	{
		this->NumeClasa = NNumeClasa;
	}

	void SETNumeColoana(string NNumeColoana)
	{
		this->NumeColoana = NNumeColoana;
	}

	string GETNumeComanda()
	{
		return this->NumeComanda;
	}

	string GETNumeClasa()
	{
		return this->NumeClasa;
	}

	string GETNumeColoana()
	{
		return this->NumeComanda;
	}

	friend istream& operator>>(istream& in, Comanda& C)
	{
		getline(in, C.NumeComanda);
		getline(in, C.NumeClasa);
		getline(in, C.NumeColoana);
		return in;
	}

	friend ostream& operator<<(ostream& out, Comanda& C)
	{
		out << "\n" << C.NumeComanda;
		out << "\n" << C.NumeClasa;
		out << "\n" << C.NumeColoana;
		return out;
	}
};
int Comanda::StartingPointClient = 0;
int Comanda::StartingPointAngajat = 10;
int Comanda::StartingPointLaborator = 100;
int Comanda::StartingPointEchipament = 1000; //Generare de coduri numerice tip ID.


