#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class CustomException
{
	string Mesaj = "INPUT ERROR!";
public:
	CustomException(string Mesaj) : Mesaj(Mesaj) {}
	string what()
	{
		return this->Mesaj;
	}
};