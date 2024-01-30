#pragma once
#include <exception>
using namespace std;

class GNepostojeciTekuci : public exception
{
public:
	GNepostojeciTekuci() : exception("GRESKA: Tekuci element ne postoji") {};
};

class GPorukaVecPoslata : public exception
{
public:
	GPorukaVecPoslata() : exception("GRESKA: Poruka je vec poslata, ne moze se menjati text") {};
};