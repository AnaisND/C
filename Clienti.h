#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Client
{
private:
	const int Cod;
	string Nume = "-----";
	int NrComenzi = 0;
	int* Comenzi = NULL; //Codurile comenzilor.
	float* Preturi = NULL;
	static int NrClienti;

public:
	Client(int Cod) :Cod(Cod)
	{
		/* Apel constructor cu un parametru. */
		Client::NrClienti++;
	}

	Client(int Cod, string Nume, int NrComenzi, int* Comenzi, float* Preturi) :Cod(Cod)
	{
		/* Apel constructor cu toti parametrii. */
		this->Nume = Nume;
		this->NrComenzi = NrComenzi;
		this->Comenzi = new int[this->NrComenzi];
		this->Preturi = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Comenzi[i] = Comenzi[i];
			this->Preturi[i] = Preturi[i];
		}
		Client::NrClienti++;
	}

	Client(const Client& C) : Cod(C.Cod)
	{
		delete[] this->Comenzi;
		delete[] this->Preturi;
		this->Nume = C.Nume;
		this->NrComenzi = C.NrComenzi;
		this->Comenzi = new int[this->NrComenzi];
		this->Preturi = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Comenzi[i] = C.Comenzi[i];
		}
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Preturi[i] = C.Preturi[i];
		}
	}

	~Client()
	{
		/* Apel destructor */
		delete[] this->Comenzi;
		delete[] this->Preturi;
	}

	Client& operator=(const Client& C)
	{
		if (this != &C)
		{
			delete[] this->Comenzi;
			delete[] this->Preturi;
			this->Nume = C.Nume;
			this->NrComenzi = C.NrComenzi;
			this->Comenzi = new int[this->NrComenzi];
			this->Preturi = new float[this->NrComenzi];
			for (int i = 0; i < this->NrComenzi; i++)
			{
				this->Comenzi[i] = C.Comenzi[i];
				this->Preturi[i] = C.Preturi[i];
			}
		}
		return *this;
	}

	float operator[](int Pozitie)
	{
		return this->Preturi[Pozitie];
	}

	void ClientInsertValues(int Nr, float* P, int* C)
	{
		Client Copie = *this;
		delete[]this->Preturi;
		delete[]this->Comenzi;
		this->NrComenzi += Nr;
		this->Preturi = new float[this->NrComenzi];
		this->Comenzi = new int[this->NrComenzi];
		std::copy(Copie.Preturi, Copie.Preturi + Copie.NrComenzi, this->Preturi);
		std::copy(P, P + Nr, this->Preturi + Copie.NrComenzi);
		std::copy(Copie.Comenzi, Copie.Comenzi + Copie.NrComenzi, this->Comenzi);
		std::copy(C, C + Nr, this->Comenzi + Copie.NrComenzi);
	}

	void ClientDeleteValues(int C)
	{
		for (int i = 0; i < this->NrComenzi; i++)
		{
			if (this->Comenzi[i] == C)
			{
				this->Comenzi[i] = 0;
				this->Preturi[i] = 0;
			}
		}
	}

	Client operator+=(int Nr)
	{
		/* Adauga Nr Preturi noi care vor fi media tuturor preturilor anterioare */
		/* Toate comenzile noi primesc codul 0 */
		Client Copie = *this;
		float M = 0;
		for (int i = 0; i < Copie.NrComenzi; i++)
		{
			M += Copie.Preturi[i];
		}
		M = M / Copie.NrComenzi;
		delete[]this->Preturi;
		delete[]this->Comenzi;
		this->NrComenzi = this->NrComenzi + Nr;
		this->Preturi = new float[this->NrComenzi];
		this->Comenzi = new int[this->NrComenzi];
		for (int i = 0; i < Copie.NrComenzi; i++)
		{
			this->Preturi[i] = Copie.Preturi[i];
			this->Comenzi[i] = Copie.Comenzi[i];
		}
		for (int i = Copie.NrComenzi; i < this->NrComenzi; i++)
		{
			this->Preturi[i] = M;
			this->Comenzi[i] = 0;
		}
		return *this;
	}

	Client operator-=(int Nr)
	{
		Client Copie = *this;
		delete[]this->Preturi;
		this->NrComenzi = this->NrComenzi - Nr;
		this->Preturi = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Preturi[i] = Copie.Preturi[i];
		}
		return *this;
	}

	Client operator++(int Pozitie) //++Preturi[Pozitie-1];
	{
		/* Pretul de pe o pozitie creste cu o unitate */
		this->Preturi[Pozitie]++;
		return *this;
	}

	Client operator--(int Pozitie) //--Preturi[Pozitie-1];
	{
		/* Pretul de pe o pozitie scade cu o unitate */
		this->Preturi[Pozitie]--;
		return *this;
	}

	Client operator*(int Pozitie)
	{
		/* Pretul de pe o pozitie se dubleaza */
		this->Preturi[Pozitie] = this->Preturi[Pozitie] * 2;
		return *this;
	}

	Client operator/(int Pozitie)
	{
		/* Pretul de pe o pozitie se injumatateste */
		this->Preturi[Pozitie] = this->Preturi[Pozitie] / 2;
		return *this;
	}

	operator float()
	{
		/* Primul pret */
		return this->Preturi[0];
	}

	Client& operator!()
	{
		this->Nume = "-----";
		this->NrComenzi = 0;
		delete[]this->Comenzi; this->Comenzi = NULL;
		delete[]this->Preturi; this->Preturi = NULL;
		return *this;
	}

	float operator()(int Pozitie1, int Pozitie2)
	{
		/* Aduna preturile de pe pozitia 1 pana la pozitia 2 inclusiv */
		if ((Pozitie1 >= 0) && (Pozitie2 <= this->NrComenzi))
		{
			float S = 0;
			for (int i = Pozitie1; i <= Pozitie2; i++)
			{
				S += this->Preturi[i];
			}
			return S;
		}
	}

	friend bool operator<(Client& C1, Client& C2)
	{
		return C1.NrComenzi < C2.NrComenzi;
	}

	friend bool operator<=(Client& C1, Client& C2)
	{
		return C1.NrComenzi <= C2.NrComenzi;
	}

	friend bool operator>(Client& C1, Client& C2)
	{
		return C1.NrComenzi > C2.NrComenzi;
	}

	friend bool operator>=(Client& C1, Client& C2)
	{
		return C1.NrComenzi >= C2.NrComenzi;
	}

	friend bool operator==(Client& C1, Client& C2)
	{
		int b = 1;
		if ((C1.Nume == C2.Nume) && (C1.NrComenzi == C2.NrComenzi))
		{
			for (int i = 0; i < C1.NrComenzi; i++)
			{
				if ((C1.Comenzi[i] != C2.Comenzi[i]) || (C1.Preturi[i] != C2.Preturi[i]))
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

	float NotaDePlata()
	{
		/* Stabileste cat are de platit un client */
		float P = 0;
		for (int i = 0; i < this->NrComenzi; i++)
		{
			P += this->Preturi[i];
		}
		return P;
	}

	friend istream& operator>>(istream& in, Client& C)
	{
		delete[] C.Comenzi;
		delete[] C.Preturi;
		getline(in, C.Nume);
		in >> C.NrComenzi;
		C.Comenzi = new int[C.NrComenzi];
		C.Preturi = new float[C.NrComenzi];
		for (int a = 0; a < C.NrComenzi; a++)
		{
			in >> C.Comenzi[a];
		}
		for (int a = 0; a < C.NrComenzi; a++)
		{
			in >> C.Preturi[a];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Client C)
	{
		out << "\n" << C.Nume;
		out << "\n" << C.NrComenzi;
		for (int a = 0; a < C.NrComenzi; a++)
		{
			out << "\n" << C.Comenzi[a] << " -> " << C.Preturi[a];
		}
		out << "\n" << Client::NrClienti;
		return out;
	}

	void SETNume(string Nume);
	void SETNrComenzi(int NrComenzi);
	void SETComenzi(int* Comenzi);
	void SETPreturi(float* Preturi);
	string GETNume();
	int GETNrComenzi();
	int* GETComenzi();
	float* GETPreturi();
};
int Client::NrClienti = 0;
void Client::SETNume(string Nume)
{
	if (Nume.length() > 1)
	{
		this->Nume = Nume;
	}
}
void Client::SETNrComenzi(int NrComenzi)
{
	if (NrComenzi >= 0)
	{
		this->NrComenzi = NrComenzi;
	}
}
void Client::SETComenzi(int* Comenzi)
{
	delete[] this->Comenzi;
	this->Comenzi = new int[this->NrComenzi];
	for (int i = 0; i < this->NrComenzi; i++)
	{
		this->Comenzi[i] = Comenzi[i];
	}
}
void Client::SETPreturi(float* Preturi)
{
	delete[] this->Preturi;
	this->Preturi = new float[this->NrComenzi];
	for (int i = 0; i < this->NrComenzi; i++)
	{
		this->Preturi[i] = Preturi[i];
	}
}
string Client::GETNume()
{
	return this->Nume;
}
int Client::GETNrComenzi()
{
	return this->NrComenzi;
}
int* Client::GETComenzi()
{
	return this->Comenzi;
}
float* Client::GETPreturi()
{
	return this->Preturi;
}