#include<iostream>
//Alıcı,gönderen ve kargo tipi bilgilerini içeren kargo uygulaması
using namespace std;

class Package
{
public:

string aliciisim;
string alicisoyisim;
string aliciadres;
string alicisehir;
string aliciulke;
int alicipostakodu;

string gonderenisim;
string gonderensoyisim;
string gonderenadres;
string gonderensehir;
string gonderenulke;

int agirlik;
int grambasiucret;
string birim1,birim2;

Package()
{
    grambasiucret = 4;
    birim1 = "TL";
    birim2 = "gram";

    if (agirlik <= 0)
    {
        cout << "Agirlik 0 veya 0 dan kucuk olamaz.";
        exit(0);
    }
    
}

void BilgileriAl()
{
    cout << "Gondericinin bilgilerini giriniz. " << endl;
    cout << "Ad Soyad : ";
    cin >> gonderenisim >> gonderensoyisim;
    

    cout << "Adres : ";
    cin >> gonderenadres;
    

    cout << "Sehir ve ulke : ";
    cin >> gonderensehir >> gonderenulke;

    cout << endl;

    cout << "Alicinin bilgilerini giriniz. " << endl;
    cout << "Ad Soyad : ";
    cin >> aliciisim >> alicisoyisim;
    
    cout << "Adres :";
    cin >> aliciadres;

    cout << "Sehir ve ulke : ";
    cin >> alicisehir >> aliciulke;
}

};

class TwoDayPackage : public Package
{
public:

int sabitucret;
double ucret2;
TwoDayPackage()
{
    sabitucret = 10;
}

double UcretHesapla(double agirlik)
{
    ucret2 = ( (grambasiucret * agirlik) / 100 ) + sabitucret;
    return ucret2;
}
    

};

class OvernightPackage : public Package
{
public :

int grambasiucret2;
double ucret3;

OvernightPackage()
{
    grambasiucret2 = 6;
}

double UcretHesapla2(double agirlik)
{
    ucret3 = ( grambasiucret + grambasiucret2 ) * agirlik ;
    ucret3 = ucret3 / 100;
    return ucret3;
}

};

int main()
{
    int secim;
    cout << "Tarife seciniz  1- Twoday 2- Overnight :";
    cin >> secim;
    int ucret2,agirlik;
    int ucret3;
    switch (secim)
    {
    case 1:
    {
        
        TwoDayPackage twodaypackage;
        twodaypackage.BilgileriAl();

        cout << " Kargonun agirligini giriniz: " ;
        cin >> agirlik;

        twodaypackage.UcretHesapla(agirlik);
        

        cout << "GONDEREN " << endl;

        cout << "Ad Soyad : " << twodaypackage.gonderenisim << " " << twodaypackage.gonderensoyisim << endl;
        cout << "Adres : " << twodaypackage.gonderenadres <<  endl;
        cout << "Sehir ve ulke :" << twodaypackage.gonderensehir << " " << twodaypackage.gonderenulke << endl;
        
        cout << "ALICI " << endl;

        cout << "Ad Soyad : " << twodaypackage.aliciisim << " " << twodaypackage.alicisoyisim << endl;
        cout << "Adres : " << twodaypackage.aliciadres << endl ;
        cout << "Sehir ve Ulke : " << twodaypackage.alicisehir << " " << twodaypackage.aliciulke << endl;

        cout << "Ucretiniz : " << twodaypackage.ucret2 << " " << twodaypackage.birim1 << endl;
    break;

    }

    case 2:
    {
    
        OvernightPackage overnightpackage;
        overnightpackage.BilgileriAl();

        cout << " Kargonun agirligini giriniz: " ;
        cin >> overnightpackage.agirlik;

        overnightpackage.UcretHesapla2(overnightpackage.agirlik);
        
        cout << "GONDEREN " << endl;

        cout << "Ad Soyad : " << overnightpackage.gonderenisim << " " << overnightpackage.gonderensoyisim << endl;
        cout << "Adres : " << overnightpackage.gonderenadres <<  endl;
        cout << "Sehir ve ulke : " << overnightpackage.gonderensehir << " " << overnightpackage.gonderenulke << endl;

        cout << "ALICI " << endl;

        cout << "Ad Soyad : " << overnightpackage.aliciisim << " " << overnightpackage.alicisoyisim << endl;
        cout << "Adres : " << overnightpackage.aliciadres << endl;
        cout << "Sehir ve ulke " << overnightpackage.alicisehir << " " << overnightpackage.aliciulke << endl;

        cout << "Ucretiniz : " << overnightpackage.ucret3 << " " <<  overnightpackage.birim1 <<endl;
    break;
    }

}
}

