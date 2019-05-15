#ifndef MUSTERI_H
#define MUSTERI_H
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Musteri
{
	string musteriNo;
	string musteriTC;
	string musteriAdi;
	string musteriSoyadi;
};

void musteriEkle()
{
	system("cls");
	ofstream dosyaYaz;
	Musteri musteri;
	dosyaYaz.open("musteriler.txt", ios::app);
	cout << "M��teri ad� giriniz: ";
	cin >> musteri.musteriAdi;
	cout << "M��teri soyad� giriniz: ";
	cin >> musteri.musteriSoyadi;
	cout << "M��teri no giriniz: ";
	cin >> musteri.musteriNo;
	cout << "M��teri TC no giriniz: ";
	cin >> musteri.musteriTC;
	if (musteri.musteriTC.length() == 11)
	{
		dosyaYaz << musteri.musteriAdi << "\t" << musteri.musteriSoyadi << "\t" << musteri.musteriNo << "\t" << musteri.musteriTC << "\n";
	}
	else
	{
		cout << "TC kimlik numaras� hatal� girildi, men�ye d�nmek i�in bir tu�a bas�n�z." << endl;
		system("pause");
	}
	dosyaYaz.close();
}

void musteriSil()
{
	string a;
	int k = 0;
	string b[1000];
	string c[1000];
	string d[1000];
	string e[1000];
	system("cls");
	cout << "Silinecek odan�n numaras�n� giriniz: ";
	cin >> a;

	ifstream dosyaOku;
	dosyaOku.open("musteriler.txt", ios::in);
	ofstream dosyaYaz;
	dosyaYaz.open("geciciDosya.txt", ios::app);
	Musteri musteri;
	while (!dosyaOku.eof())
	{
		dosyaOku >> musteri.musteriAdi >> musteri.musteriSoyadi >> musteri.musteriNo >> musteri.musteriTC;
		if (dosyaOku.eof())	break;
		b[k] = musteri.musteriAdi;
		c[k] = musteri.musteriSoyadi;
		d[k] = musteri.musteriNo;
		e[k] = musteri.musteriTC;

		if (d[k] != a)
		{
			dosyaYaz << b[k] << "\t" << c[k] << "\t" << d[k] << "\t" << e[k] << "\n";
		}
		k++;

	}
	dosyaYaz.close();
	dosyaOku.close();

	remove("musteriler.txt");
	rename("geciciDosya.txt", "musteriler.txt");
}

void musteriListele()
{
	system("cls");
	ifstream dosyaOku;
	dosyaOku.open("musteriler.txt");
	while (!dosyaOku.eof())
	{
		Musteri musteri;
		dosyaOku >> musteri.musteriAdi >> musteri.musteriSoyadi >> musteri.musteriNo >> musteri.musteriTC;
		if (dosyaOku.eof())	break;
		cout << "M��teri ad�        : " << musteri.musteriAdi << endl;
		cout << "M��teri soyad�     : " << musteri.musteriSoyadi << endl;
		cout << "M��teri numaras�   : " << musteri.musteriNo << endl;
		cout << "M��teri TC numaras�: " << musteri.musteriTC << endl;
		cout << endl;
	}
	dosyaOku.close();
	
}

#endif // !MUSTERI_H
