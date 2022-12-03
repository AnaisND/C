#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Angajat
{
private:
	const int Cod;
	string Nume = "-----";
	string Functie = "-----";
	float Salariu = 0;
	int NrComenzi = 0; //Numarul comenzilor la care trebuie sa lucreze angajatul.
	float* Valori = NULL; //Valoarea muncii sale pentru fiecare comanda ca mai apoi sa ii poata fi calculat salariul.
	static int NrAngajati;
	static float CrestereSalariuPromovare;
public:

	Angajat(int Cod) :Cod(Cod)
	{
		/* Apel constructor cu un parametru. */
		Angajat::NrAngajati++;
	}

	Angajat(int Cod, string Nume, string Functie, int NrComenzi, float* Valori) :Cod(Cod)
	{
		/* Apel constructor cu toti parametrii posibili */
		this->Nume = Nume;
		this->Functie = Functie;
		this->NrComenzi = NrComenzi;
		this->Valori = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Valori[i] = Valori[i];
		}
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Salariu += this->Valori[i];
		}
		Angajat::NrAngajati++;
	}

	Angajat(const Angajat& A) : Cod(A.Cod)
	{
		/* Apel constructor de copiere */
		delete[] this->Valori;
		this->Nume = A.Nume;
		this->Functie = A.Functie;
		this->NrComenzi = A.NrComenzi;
		this->Valori = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Valori[i] = A.Valori[i];
		}
		for (int i = 0; i < A.NrComenzi; i++)
		{
			this->Salariu += A.Valori[i];
		}
	}

	~Angajat()
	{
		/* Apel destructor */
		delete[] this->Valori;
	}

	Angajat& operator=(const Angajat& A)
	{
		/* Supraincarcarea operatorului "=" in locul crearii unui constructor de copiere. Acest operator oricum il va apela. */
		if (this != &A)
		{
			delete[] this->Valori;
			this->Nume = A.Nume;
			this->Functie = A.Functie;
			this->NrComenzi = A.NrComenzi;
			this->Valori = new float[this->NrComenzi];
			for (int i = 0; i < this->NrComenzi; i++)
			{
				this->Valori[i] = A.Valori[i];
			}
			for (int i = 0; i < A.NrComenzi; i++)
			{
				this->Salariu += A.Valori[i];
			}
		}
		return *this;
	}

	float operator[](int Pozitie)
	{
		/* Returneaza valoarea comenzii de pe o anumita pozitie */
		return this->Valori[Pozitie];
	}

	void AngajatInsertValues(int NrC, float* V)
	{
		Angajat Copie = *this;
		delete[]this->Valori;
		this->NrComenzi = this->NrComenzi + NrC;
		this->Valori = new float[this->NrComenzi];
		std::copy(Copie.Valori, Copie.Valori + Copie.NrComenzi, this->Valori);
		std::copy(V, V + NrC, this->Valori + Copie.NrComenzi);
		for (int i = 0; i < NrC; i++)
		{
			this->Salariu += V[i];
		}
	}

	void AngajatDeleteValues(float V)
	{
		for (int i = 0; i < this->NrComenzi; i++)
		{
			if (this->Valori[i] == V)
			{
				this->Salariu -= this->Valori[i];
				this->Valori[i] = 0;
			}
		}
	}

	Angajat operator+=(int Nr)
	{
		Angajat Copie = *this;
		delete[]this->Valori;
		this->NrComenzi = this->NrComenzi + Nr;
		this->Valori = new float[this->NrComenzi];
		for (int i = 0; i < Copie.NrComenzi; i++)
		{
			this->Valori[i] = Copie.Valori[i];
		}
		for (int i = Copie.NrComenzi; i < this->NrComenzi; i++)
		{
			this->Valori[i] = 0;
		}
		return *this;
	}

	Angajat operator-=(int Nr)
	{
		Angajat Copie = *this;
		delete[]this->Valori;
		this->NrComenzi = this->NrComenzi - Nr;
		this->Valori = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Valori[i] = Copie.Valori[i];
		}
		return *this;
	}

	Angajat operator++() //++A;
	{
		this->Salariu += Angajat::CrestereSalariuPromovare;
		return *this;
	}

	Angajat operator++(int) //A++;
	{
		Angajat Rezultat = *this;
		this->Salariu += Angajat::CrestereSalariuPromovare;
		return Rezultat;
	}

	Angajat operator--() //--A;
	{
		this->NrComenzi -= Angajat::CrestereSalariuPromovare;
		return *this;
	}

	Angajat operator--(int) //A--;
	{
		Angajat Rezultat = *this;
		this->Salariu -= Angajat::CrestereSalariuPromovare;
		return Rezultat;
	}

	Angajat operator*(int V)
	{
		this->Salariu = this->Salariu * V;
		return *this;
	}

	Angajat operator/(int V)
	{
		this->Salariu = this->Salariu / V;
		return *this;
	}

	operator float()
	{
		return this->Salariu;
	}

	Angajat operator!()
	{
		this->Nume = "-----";
		this->Functie = "-----";
		this->Salariu = 0;
		this->NrComenzi = 0;
		delete[] this->Valori;  this->Valori = NULL;
		return *this;
	}

	friend bool operator>(Angajat& A1, Angajat& A2)
	{
		return A1.Salariu > A2.Salariu;
	}

	friend bool operator>=(Angajat& A1, Angajat& A2)
	{
		return A1.Salariu >= A2.Salariu;
	}

	friend bool operator<(Angajat& A1, Angajat& A2)
	{
		return A1.Salariu < A2.Salariu;
	}

	friend bool operator<=(Angajat& A1, Angajat& A2)
	{
		return A1.Salariu <= A2.Salariu;
	}

	friend bool operator==(Angajat& A1, Angajat& A2)
	{
		int b = 1;
		if ((A1.Nume == A2.Nume) && (A1.Functie == A2.Functie) && (A1.NrComenzi == A2.NrComenzi))
		{
			for (int i = 0; i < A1.NrComenzi; i++)
			{
				if (A1.Valori[i] != A2.Valori[i])
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

	friend istream& operator>>(istream& in, Angajat& A)
	{
		getline(in, A.Nume);
		getline(in, A.Functie);
		in >> A.NrComenzi;
		delete[]A.Valori;
		A.Valori = new float[A.NrComenzi];
		for (int a = 0; a < A.NrComenzi; a++)
		{
			in >> A.Valori[a];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Angajat& A)
	{
		out << "\n" << A.Nume;
		out << "\n" << A.Functie;
		out << "\n" << A.NrComenzi;
		for (int a = 0; a < A.NrComenzi; a++)
		{
			out << "\n" << A.Valori[a];
		}
		return out;
	}

	void SETNume(string Nume);
	void SETFunctie(string Functie);
	void SETComenzi(int NrComenzi, float* Valori);
	string GETNume();
	string GETFunctie();
	float* GETComenzi();
	float GETSalariu()
	{
		return this->Salariu;
	}
};
int Angajat::NrAngajati = 0; //Count-ul angajatilor incepe de la 0.
float Angajat::CrestereSalariuPromovare = 350;
void Angajat::SETNume(string Nume)
{
	if (Nume.length() > 1)
	{
		this->Nume = Nume;
	}
}
void Angajat::SETFunctie(string Functie)
{
	if (Functie.length() > 1)
	{
		this->Functie = Functie;
	}
}
void Angajat::SETComenzi(int NrComenzi, float* Valori)
{
	if ((NrComenzi > 0) && (Valori != NULL))
	{
		delete[] this->Valori;
		this->NrComenzi = NrComenzi;
		this->Valori = new float[this->NrComenzi];
		for (int i = 0; i < this->NrComenzi; i++)
		{
			this->Valori[i] = Valori[i];
		}
	}
}
string Angajat::GETNume()
{
	return this->Nume;
}
string Angajat::GETFunctie()
{
	return this->Functie;
}
float* Angajat::GETComenzi()
{
	return this->Valori;
}