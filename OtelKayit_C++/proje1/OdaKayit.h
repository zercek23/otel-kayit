#ifndef ODAKAYIT_H
#define ODAKAYIT_H
#include "stdafx.h"
#include <iostream>
#include "Musteri.h"
#include "Oda.h"
using namespace std;

struct OdaKayit
{
	string odaSecim;
	string musteriSecim;
};

void odaKayitListele();

void odaKayitEkle()
{
	OdaKayit odaKayit;
	Musteri musteri;
	Oda oda;
	ofstream dosyaYaz;
	dosyaYaz.open("odaKayitlar.txt", ios::app);
	cout << "MEVCUT ODALAR" << endl << "-------------------" << endl;
	odaListele();
	cout << "Kayýdýný yapacaðýnýz bir oda numarasý giriniz: ";
	cin >> odaKayit.odaSecim;
	cout << "MEVCUT MÜÞTERÝLER" << endl << "-------------------" << endl;
	musteriListele();
	cout << "Kayýdýný yapacaðýnýz bir müþteri numarasý giriniz: ";
	cin >> odaKayit.musteriSecim;
	
	ifstream dosyaOku;
	dosyaOku.open("musteriler.txt", ios::in);
	while (!dosyaOku.eof())
	{
		dosyaOku >> musteri.musteriAdi >> musteri.musteriSoyadi >> musteri.musteriNo >> musteri.musteriTC;
		if (dosyaOku.eof())	break;
		if (odaKayit.musteriSecim == musteri.musteriNo)
		{
			dosyaYaz << musteri.musteriNo << "\t" << musteri.musteriAdi
				<< "\t" << musteri.musteriSoyadi << "\t" << musteri.musteriTC << "\t";
		}
	}
	dosyaOku.close();

	dosyaOku.open("odalar.txt", ios::in);
	while (!dosyaOku.eof())
	{
		dosyaOku >> oda.odaNo >> oda.odaUcreti;
		if (dosyaOku.eof())	break;
		if (odaKayit.odaSecim == oda.odaNo)
		{
			dosyaYaz << oda.odaNo << "\t" << oda.odaUcreti << "\n";
		}
	}
	dosyaOku.close();
	
	dosyaYaz.close();

}

void odaKayitSil()
{
	string a;
	int k = 0;
	string b[1000];
	string c[1000];
	string d[1000];
	string e[1000];
	string f[1000];
	string g[1000];
	system("cls");
	odaKayitListele();
	cout << "Silinecek kaydýn odasýnýn numarasýný giriniz: ";
	cin >> a;

	ifstream dosyaOku;
	dosyaOku.open("odaKayitlar.txt", ios::in);
	ofstream dosyaYaz;
	dosyaYaz.open("geciciDosya.txt", ios::app);
	Oda oda;
	Musteri musteri;
	while (!dosyaOku.eof())
	{
		dosyaOku >> musteri.musteriNo >> musteri.musteriAdi >> musteri.musteriSoyadi >> musteri.musteriTC >> oda.odaNo >> oda.odaUcreti;
		if (dosyaOku.eof())	break;
		b[k] = musteri.musteriNo;
		c[k] = musteri.musteriAdi;
		d[k] = musteri.musteriSoyadi;
		e[k] = musteri.musteriTC;
		f[k] = oda.odaNo;
		g[k] = oda.odaUcreti;

		if (f[k] != a)
		{
			dosyaYaz << b[k] << "\t" << c[k] << "\t" << d[k] << "\t" << e[k] << "\t" << f[k] << "\t" << g[k] << "\n";
		}
		k++;

	}
	dosyaYaz.close();
	dosyaOku.close();

	remove("odaKayitlar.txt");
	rename("geciciDosya.txt", "odaKayitlar.txt");
}

void odaKayitListele()
{
	system("cls");
	ifstream dosyaOku;
	dosyaOku.open("odaKayitlar.txt");
	while (!dosyaOku.eof())
	{
		Oda oda;
		Musteri musteri;
		dosyaOku >> musteri.musteriNo >> musteri.musteriAdi >> musteri.musteriSoyadi >> musteri.musteriTC;
		dosyaOku >> oda.odaNo >> oda.odaUcreti;
		if (dosyaOku.eof())	break;
		cout << "Oda numarasý       : " << oda.odaNo << endl;
		cout << "Oda ücreti         : " << oda.odaUcreti << endl;
		cout << "Müþteri adý        : " << musteri.musteriAdi << endl;
		cout << "Müþteri soyadý     : " << musteri.musteriSoyadi << endl;
		cout << "Müþteri numarasý   : " << musteri.musteriNo << endl;
		cout << "Müþteri TC numarasý: " << musteri.musteriTC << endl;
		cout << endl;
	}

	dosyaOku.close();
	system("pause");
}


#endif // !ODAKAYIT_H

