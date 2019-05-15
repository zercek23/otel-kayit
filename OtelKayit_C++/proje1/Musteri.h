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
	cout << "Müþteri adý giriniz: ";
	cin >> musteri.musteriAdi;
	cout << "Müþteri soyadý giriniz: ";
	cin >> musteri.musteriSoyadi;
	cout << "Müþteri no giriniz: ";
	cin >> musteri.musteriNo;
	cout << "Müþteri TC no giriniz: ";
	cin >> musteri.musteriTC;
	if (musteri.musteriTC.length() == 11)
	{
		dosyaYaz << musteri.musteriAdi << "\t" << musteri.musteriSoyadi << "\t" << musteri.musteriNo << "\t" << musteri.musteriTC << "\n";
	}
	else
	{
		cout << "TC kimlik numarasý hatalý girildi, menüye dönmek için bir tuþa basýnýz." << endl;
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
	cout << "Silinecek odanýn numarasýný giriniz: ";
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
		cout << "Müþteri adý        : " << musteri.musteriAdi << endl;
		cout << "Müþteri soyadý     : " << musteri.musteriSoyadi << endl;
		cout << "Müþteri numarasý   : " << musteri.musteriNo << endl;
		cout << "Müþteri TC numarasý: " << musteri.musteriTC << endl;
		cout << endl;
	}
	dosyaOku.close();
	
}

#endif // !MUSTERI_H
