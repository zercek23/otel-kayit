/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI....:5
**				ÖĞRENCİ ADI......:Burak Bayram
**				ÖĞRENCİ NUMARASI.:b171210076
**				DERS GRUBU.......:C
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "Oda.h"
#include "Musteri.h"
#include "OdaKayit.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"Turkish");
	int secim1, secim2;
	do
	{
		system("cls");
		cout << "Otel İşlemleri" << endl;
		cout << "------------------" << endl;
		cout << "1-Oda İşlemleri" << endl;
		cout << "2-Müşteri İşlemleri" << endl;
		cout << "3-Oda Kayıt İşlemleri" << endl;
		cout << "99-Çıkış" << endl;
		cout << "Seçiminiz: "; cin >> secim1;
		if (secim1 == 1)
		{
			do
			{
				system("cls");
				cout << "Oda İşlemleri" << endl;
				cout << "------------------" << endl;
				cout << "1-Oda Ekle" << endl;
				cout << "2-Oda Sil" << endl;
				cout << "3-Odalari Listele" << endl;
				cout << "99-Üst Menü" << endl;
				cout << "Seçiminiz: "; cin >> secim2;
				if (secim2 == 1)
				{
					odaEkle();
				}
				else if (secim2 == 2)
				{
					odaSil();
				}
				else if (secim2 == 3)
				{
					odaListele();
					system("pause");
				}
				
			} while (secim2 != 99);
		}
		else if (secim1 == 2)
		{
			do
			{
				system("cls");
				cout << "Müşteri İşlemleri" << endl;
				cout << "------------------" << endl;
				cout << "1-Müşteri Ekle" << endl;
				cout << "2-Müşteri Sil" << endl;
				cout << "3-Müşteri Listele" << endl;
				cout << "99-Üst Menü" << endl;
				cout << "Seçiminiz: "; cin >> secim2;
				if (secim2 == 1)
				{
					musteriEkle();
				}
				else if (secim2 == 2)
				{
					musteriSil();
				}
				else if (secim2 == 3)
				{
					musteriListele();
					system("pause");
				}
			} while (secim2 != 99);
		}
		else if (secim1 == 3)
		{
			do
			{
				system("cls");
				cout << "Oda Kayıt İşlemleri" << endl;
				cout << "------------------" << endl;
				cout << "1-Oda Kayıt Ekle" << endl;
				cout << "2-Oda Kayıt Sil" << endl;
				cout << "3-Oda Kayıt Listele" << endl;
				cout << "99-Üst Menü" << endl;
				cout << "Seçiminiz: "; cin >> secim2;
				if (secim2 == 1)
				{
					odaKayitEkle();
				}
				else if (secim2 == 2)
				{
					odaKayitSil();
				}
				else if (secim2 == 3)
				{
					odaKayitListele();
				}
			} while (secim2 != 99);
		}
		
	} while (secim1 != 99);
	
    return 0;
}

