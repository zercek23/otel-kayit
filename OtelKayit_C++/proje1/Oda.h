#ifndef ODA_H
#define ODA_H
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Oda
{
	string odaNo;
	string odaUcreti;
};

void odaEkle()
{
	system("cls");
	ofstream dosyaYaz;
	dosyaYaz.open("odalar.txt", ios::app);
	Oda oda;
	cout << "Oda no giriniz: ";
	cin >> oda.odaNo;
	cout << "Oda Ücreti giriniz: ";
	cin >> oda.odaUcreti;
	dosyaYaz << oda.odaNo << "\t" << oda.odaUcreti << "\n";
	dosyaYaz.close();
}

void odaSil()
{
	string a;
	int k = 0;
	string b[1000];
	string c[1000];
	system("cls");
	cout << "Silinecek odanýn numarasýný giriniz: ";
	cin >> a;

	ifstream dosyaOku;
	dosyaOku.open("odalar.txt", ios::in);
	ofstream dosyaYaz;
	dosyaYaz.open("geciciDosya.txt", ios::app);
	Oda oda;
	while (!dosyaOku.eof())
	{
		dosyaOku >> oda.odaNo >> oda.odaUcreti;
		if (dosyaOku.eof())	break;
		b[k] = oda.odaNo;
		c[k] = oda.odaUcreti;
		
		if (b[k] != a)
		{
			dosyaYaz << b[k] << "\t" << c[k] << "\n";
		}
		k++;
		
	}
	dosyaYaz.close();
	dosyaOku.close();

	remove("odalar.txt");
	rename("geciciDosya.txt", "odalar.txt");
}

void odaListele()
{
	system("cls");
	ifstream dosyaOku;
	dosyaOku.open("odalar.txt");
	while (!dosyaOku.eof())
	{
		Oda oda;
		dosyaOku >> oda.odaNo >> oda.odaUcreti;
		if (dosyaOku.eof())	break;
		cout << "Oda numarasý: " << oda.odaNo << endl;
		cout << "Oda ücreti  : " << oda.odaUcreti << endl;
		cout << endl;
	}
	dosyaOku.close();
}

#endif // !ODA_H

