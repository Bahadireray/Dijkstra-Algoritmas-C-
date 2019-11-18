/* Yönlü agirliksiz bir grafta çevrim bulan program.
   Bulunan cevrime neden olan dügümler sirasiyla ekrana yazdirilacak.
   Grafta cevrim yoksa, "Cevrim Yoktur" yazdirilacak. Olasi ornek ciktilar:

   "Cevrim Yoktur!"
   "*. dugumden *. dugume Cevrim var!"

   Bahadir Eray
   141002034
   BM207 VERİ YAPILARI - 2017 - 2018 Güz Dönemi Proje Ödevi
*/

#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graf
{
    int V;    // Matris Kenar sayisinin Tutuldugu degisken
    list<int> *tut;    // Liste oluþturup, Pointer olarak tutuyoruz.
    bool DoneneKadar(int v, bool ziyaret[], bool *KayitliBellek);  //DoneneKadar() Tarafindan kullanilan döngüsel fonksiyon. bool(var yok) true, False
public:
    Graf(int V);   // Matris Kenarlari Grafa gondermek
    void KenarEkle(int v, int w);   // Grafa kenar eklemek
    bool Dongu();    // Bu Grat'ta döngü varsa, true yada False deðerlerini döndürecek.
};

Graf::Graf(int V)
{
    this->V = V;        //listeye kenar ekleme, hafizada kenar tutma.
    tut = new list<int>[V];
}

void Graf::KenarEkle(int v, int w)
{
    tut[v].push_back(w); //Listeye bagli oldugu kenar ekleme


}

bool Graf::DoneneKadar(int v, bool ziyaret[], bool *KayitliBellek)
{
    if(ziyaret[v] == false)
    {
       // Gecerli dugumu ziyaret eder, tekrara dusen dongu varsa işaretle, true yap
        ziyaret[v] = true;
        KayitliBellek[v] = true;


        list<int>::iterator i;
        for(i = tut[v].begin(); i != tut[v].end(); ++i)
        { // islemdeki "V" kenarina bagli tum koseler için tekrarlar.


            if ( !ziyaret[*i] && DoneneKadar(*i, ziyaret, KayitliBellek) )
            {

// cout<<endl<<*i<<endl; bu kodu aktif edince grafin baslangic noktasindan cevrime neden olan dugumleri gösteriyor.

                return true;
            }
            else if (KayitliBellek[*i])
            {   //Listede tekrara, Cevrime dusen Kenari hangi dugumde sagliyorsa birlikte ekrana yazdirir.

                 cout <<endl<<"Grafta cevrime dusen dugum " <<v<<".  dugumden  "<<*i;
                return true;
            }
            }

    }
    KayitliBellek[v] = false; //tekrara dusen kenar yoksa, bellekten kaldirir.
    return false;
}

//Graf bir döngü içeriyorsa true, aksi halde false döndürür.

bool Graf::Dongu()
{
    // Tüm koseleri ziyaret edip isaretler, bellekte dongu Yineleme yoksa isaretler
    bool *ziyaret = new bool[V];
    bool *KayitliBellek = new bool[V];
    for(int i = 0; i < V; i++)
    {
        ziyaret[i] = false;
        KayitliBellek[i] = false;

    }

    // Farkli döngüleri algilamak icin cevrime yardimci islevi cagirir, Her kenar icin tekrarlar.
    for(int i = 0; i < V; i++)
        if (DoneneKadar(i, ziyaret, KayitliBellek))
        {

            return true;
        }

    return false;
}

int main()
{
  //Yukarida ki belirtilen Grafi, komsuluk matrisi gösterim

    const int boyut = 20;
    int komsulukMatrisi[boyut][boyut] = {{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                                         {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    Graf g(boyut);
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            if (komsulukMatrisi[i][j] == 1)
                g.KenarEkle(i,j);

//Komsuluk matrisini Grafa Donusumu

    if(g.Dongu())

        cout << ". Dugume Cevrim var!"<<endl; // Son adimda kontrol edilen dongusel fonsiyona cagrida bulunur.
    else
        cout << "Cevrim yoktur!" << endl; // Cevrim Var (X) dugummde bulundu ya da Cevrim Yok.
    return 0;


}
