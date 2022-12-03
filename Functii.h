#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Angajati.h";
#include "Laboratoare.h";
#include "Clienti.h";
#include "Echipamente.h";
#include "Comanda.h";
#include "Exception.h";

const int MAX = 30; //Numarul maxim de elemente dintr-un tabel.

int i = 0, j = 0, k = 0, l = 0; //Contori.

string BUFFER;
string Continue;
string Anume1, Anume2;
int Anr1, Anr2;
float anr1, anr2;

Angajat* ALista[MAX];
Client* CLista[MAX];
Laborator* LLista[MAX];
Echipament* ELista[MAX]; //Vectorii de obiecte care vor servi drept tabele

void Functie(Comanda& CC)
{
	ofstream f1,f2,f3,f4;
	f1.open("Angajati.txt", std::ios_base::app);
	f2.open("Clienti.txt", std::ios_base::app);
	f3.open("Laboratoare.txt", std::ios_base::app);
	f4.open("Echipamente.txt", std::ios_base::app);
	ifstream g1, g2, g3, g4;
	g1.open("Angajati.txt");
	g2.open("Clienti.txt");
	g3.open("Laboratoare.txt");
	g4.open("Echipamente.txt");
	string Com, Cla, Col;
	getline(cin,Com);
	CC.SETNumeComanda(Com);
	if (CC.NumeComanda == "CREATE TABLE") //Toate tabelele au fost deja create mai sus.
	{
		getline(cin, Cla);
		CC.SETNumeClasa(Cla);
		if (CC.NumeClasa == "Angajat")
		{
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost creat!";
		}
		else if (CC.NumeClasa == "Client")
		{
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost creat!";
		}
		else if (CC.NumeClasa == "Laborator")
		{
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost creat!";
		}
		else if (CC.NumeClasa == "Echipament")
		{
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost creat!";
		}
	}
	else if (CC.NumeComanda == "DROP TABLE")
	{
		getline(cin, Cla);
		CC.SETNumeClasa(Cla);
		if (CC.NumeClasa == "Angajat")
		{
			ofstream f1("Angajati.txt"); //Sterge continutul fisierului.
			delete[] *ALista;
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost sters!";
		}
		else if (CC.NumeClasa == "Client")
		{
			ofstream f2("Clienti.txt");
			delete[] *CLista;
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost sters!";
		}
		else if (CC.NumeClasa == "Laborator")
		{
			ofstream f3("Laboratoare.txt");
			delete[] *LLista;
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost sters!";
		}
		else if (CC.NumeClasa == "Echipament")
		{
			ofstream f4("Echipamente.txt");
			delete[] *ELista;
			cout << "\nTabelul '" << CC.NumeClasa << "' a fost sters!";
		}
	}
	else if (CC.NumeComanda == "DISPLAY TABLE")
	{
		getline(cin, Cla);
		CC.SETNumeClasa(Cla);
		if (CC.NumeClasa == "Angajat")
		{
			if (g1.is_open())
			{
				g1 >> BUFFER;
				while (!g1.eof())
				{
					cout << "\n" << BUFFER;
					g1 >> BUFFER;
				}
			}
		}
		else if (CC.NumeClasa == "Client")
		{
			if (g2.is_open())
			{
				g2 >> BUFFER;
				while (!g2.eof())
				{
					cout << "\n" << BUFFER;
					g2 >> BUFFER;
				}
			}
		}
		else if (CC.NumeClasa == "Laborator")
		{
			if (g3.is_open())
			{
				g3 >> BUFFER;
				while (!g3.eof())
				{
					cout << "\n" << BUFFER;
					g3 >> BUFFER;
				}
			}
		}
		else if (CC.NumeClasa == "Echipament")
		{
			if (g4.is_open())
			{
				g4 >> BUFFER;
				while (!g4.eof())
				{
					cout << "\n" << BUFFER;
					g4 >> BUFFER;
				}
			}
		}
	}
	else if (CC.NumeComanda == "INSERT INTO")
	{
		getline(cin, Cla);
		CC.SETNumeClasa(Cla);
		if (CC.NumeClasa == "Angajat")
		{
			if (i < MAX)
			{
				ALista[i] = new Angajat(Comanda::StartingPointAngajat);
				Comanda::StartingPointAngajat++;
				cin >> *ALista[i];
				if (f1)
				{
					f1 << *ALista[i];
				}
				cout << *ALista[i];
				i++;
			}
		}
		else if (CC.NumeClasa == "Client")
		{
			if (j < MAX)
			{
				CLista[j] = new Client(Comanda::StartingPointClient);
				Comanda::StartingPointClient++;
				cin >> *CLista[j];
				if (f2)
				{
					f2 << *CLista[j];
				}
				cout << *CLista[j];
				j++;
			}
		}
		else if (CC.NumeClasa == "Laborator")
		{
			if (k < MAX)
			{
				LLista[k] = new Laborator(Comanda::StartingPointLaborator);
				Comanda::StartingPointLaborator++;
				cin >> *LLista[k];
				if (f3)
				{
					f3 << *LLista[k];
				}
				cout << *LLista[k];
				k++;
			}
		}
		else if (CC.NumeClasa == "Echipament")
		{
			if (l < MAX)
			{
				ELista[l] = new Echipament(Comanda::StartingPointEchipament);
				Comanda::StartingPointEchipament++;
				cin >> *ELista[l];
				if (f4)
				{
					f4 << *ELista[l];
				}
				cout << *ELista[l];
				k++;
			}
		}
	}
	else if (CC.NumeComanda == "SELECT")
	{
		getline(cin, Col);
		CC.SETNumeColoana(Col);
		if (CC.NumeColoana == "Nume")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Angajat")
				{
					for (int a = 0; a < i; a++)
					{
						cout << "\n" << ALista[a]->GETNume();
					}
				}
				else if (CC.NumeClasa == "Client")
				{
					for (int a = 0; a < j; a++)
					{
						cout << "\n" << CLista[a]->GETNume();
					}
				}
				else if (CC.NumeClasa == "Laborator")
				{
					for (int a = 0; a < k; a++)
					{
						cout << "\n" << LLista[a]->GETNume();
					}
				}
				else if (CC.NumeClasa == "Echipament")
				{
					for (int a = 0; a < j; a++)
					{
						cout << "\n" << ELista[a]->GETNume();
					}
				}
			}
		}
		else if (CC.NumeColoana == "Functie")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Angajat")
				{
					for (int a = 0; a < i; a++)
					{
						cout << "\n" << ALista[a]->GETFunctie();
					}
				}
			}
		}
		else if (CC.NumeColoana == "Salariu")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Angajat")
				{
					for (int a = 0; a < i; a++)
					{
						cout << "\n" << ALista[a]->GETSalariu();
					}
				}
			}
		}
		else if (CC.NumeColoana == "Comenzi")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Angajat")
				{
					for (int a = 0; a < i; a++)
					{
						cout << "\n" << ALista[a]->GETComenzi();
					}
				}
				else if (CC.NumeClasa == "Client")
				{
					for (int a = 0; a < j; a++)
					{
						cout << "\n" << CLista[a]->GETComenzi();
					}
				}
			}
		}
		else if (CC.NumeColoana == "Preturi")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Client")
				{
					for (int a = 0; a < j; a++)
					{
						cout << "\n" << CLista[a]->GETPreturi();
					}
				}
			}
		}
		else if (CC.NumeColoana == "Adresa")
		{
			getline(cin, Continue);
			if (Continue == "FROM")
			{
				getline(cin, Cla);
				CC.SETNumeClasa(Cla);
				if (CC.NumeClasa == "Laborator")
				{
					for (int a = 0; a < k; a++)
					{
						cout << "\n" << LLista[a]->GETAdresa();
					}
				}
			}
			else if (CC.NumeColoana == "Chirie")
			{
				getline(cin, Continue);
				if (Continue == "FROM")
				{
					getline(cin, Cla);
					CC.SETNumeClasa(Cla);
					if (CC.NumeClasa == "Laborator")
					{
						for (int a = 0; a < k; a++)
						{
							cout << "\n" << LLista[a]->GETChirie();
						}
					}
				}
			}
			else if (CC.NumeColoana == "Numar Clienti Angajat")
			{
				getline(cin, Continue);
				if (Continue == "FROM")
				{
					getline(cin, Cla);
					CC.SETNumeClasa(Cla);
					if (CC.NumeClasa == "Laborator")
					{
						for (int a = 0; a < k; a++)
						{
							cout << "\n" << LLista[a]->GETClientiAngajati();
						}
					}
				}
			}
			else if (CC.NumeColoana == "Pret")
			{
				getline(cin, Continue);
				if (Continue == "FROM")
				{
					getline(cin, Cla);
					CC.SETNumeClasa(Cla);
					if (CC.NumeClasa == "Echipament")
					{
						for (int a = 0; a < l; a++)
						{
							cout << "\n" << ELista[a]->GETPret();
						}
					}
				}
			}
			else if (CC.NumeColoana == "Laboratoare")
			{
				getline(cin, Continue);
				if (Continue == "FROM")
				{
					getline(cin, Cla);
					CC.SETNumeClasa(Cla);
					if (CC.NumeClasa == "Echipament")
					{
						for (int a = 0; a < l; a++)
						{
							cout << "\n" << ELista[a]->GETLaboratoare();
						}
					}
				}
			}
		}
	}
	else if (CC.NumeComanda == "UPDATE")
	{
		getline(cin, Cla);
		CC.SETNumeClasa(Cla);
		if (CC.NumeClasa == "Angajat")
		{
			getline(cin, Continue);
			if (Continue == "SET")
			{
				getline(cin, Col);
				CC.SETNumeColoana(Col);
				if (CC.NumeColoana == "Nume")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Nume =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < i; a++)
							{
								if (ALista[a]->GETNume() == Anume2)
								{
									try
									{
										ALista[a]->SETNume(Anume1);
									}
									catch(exception *ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << ALista[a];
								}
							}
						}
					}
				}
				if (CC.NumeColoana == "Functie")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Functie =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < i; a++)
							{
								if (ALista[a]->GETFunctie() == Anume2)
								{
									try
									{
										ALista[a]->SETFunctie(Anume1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << ALista[a];
								}
							}
						}
					}
				}
			}
		}
		if (CC.NumeClasa == "Client")
		{
			getline(cin, Continue);
			if (Continue == "SET")
			{
				getline(cin, Col);
				CC.SETNumeColoana(Col);
				if (CC.NumeColoana == "Nume")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Nume =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < j; a++)
							{
								if (CLista[a]->GETNume() == Anume2)
								{
									try
									{
										CLista[a]->SETNume(Anume1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << CLista[a];
								}
							}
						}
					}
				}
			}
		}
		if (CC.NumeClasa == "Laborator")
		{
			getline(cin, Continue);
			if (Continue == "SET")
			{
				getline(cin, Col);
				CC.SETNumeColoana(Col);
				if (CC.NumeColoana == "Nume")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Nume =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < k; a++)
							{
								if (LLista[a]->GETNume() == Anume2)
								{
									try
									{
										LLista[a]->SETNume(Anume1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << LLista[a];
								}
							}
						}
					}
				}
				if (CC.NumeColoana == "Adresa")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Adresa =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < k; a++)
							{
								if (LLista[a]->GETAdresa() == Anume2)
								{
									try
									{
										LLista[a]->SETAdresa(Anume1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << LLista[a];
								}
							}
						}
					}
				}
				if (CC.NumeColoana == "Chirie")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						cin >> Anr1;
						getline(cin, Continue);
						if (Continue == "WHERE Chirie =")
						{
							cin >> Anr2;
							for (int a = 0; a < k; a++)
							{
								if (LLista[a]->GETChirie() == Anr2)
								{
									try
									{
										LLista[a]->SETChirie(Anr1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << LLista[a];
								}
							}
						}
					}
				}
			}
		}
		if (CC.NumeClasa == "Echipament")
		{
			getline(cin, Continue);
			if (Continue == "SET")
			{
				getline(cin, Col);
				CC.SETNumeColoana(Col);
				if (CC.NumeColoana == "Nume")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						getline(cin, Anume1);
						getline(cin, Continue);
						if (Continue == "WHERE Nume =")
						{
							getline(cin, Anume2);
							for (int a = 0; a < l; a++)
							{
								if (ELista[a]->GETNume() == Anume2)
								{
									try
									{
										ELista[a]->SETNume(Anume1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << ELista[a];
								}
							}
						}
					}
				}
				if (CC.NumeColoana == "Pret")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						cin >> anr1;
						getline(cin, Continue);
						if (Continue == "WHERE Pret =")
						{
							cin >> anr2;
							for (int a = 0; a < l; a++)
							{
								if (ELista[a]->GETPret() == anr2)
								{
									try
									{
										ELista[a]->SETPret(anr1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << LLista[a];
								}
							}
						}
					}
				}
				if (CC.NumeColoana == "Cantitate")
				{
					getline(cin, Continue);
					if (Continue == "=")
					{
						cin >> Anr1;
						getline(cin, Continue);
						if (Continue == "WHERE Cantitate =")
						{
							cin >> Anr2;
							for (int a = 0; a < l; a++)
							{
								if (ELista[a]->GETCantitate() == Anr2)
								{
									try
									{
										ELista[a]->SETCantitate(Anr1);
									}
									catch (exception* ex)
									{
										cout << ex->what();
										delete ex;
									}
									cout << ELista[a];
								}
							}
						}
					}
				}
			}
		}
	}
}