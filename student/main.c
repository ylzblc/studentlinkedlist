#include <stdio.h>
#include <stdlib.h>


struct student{
    int number;
    char name[10];
    char surname[10];
    float midtermGrade, finalGrade;

    struct student *next;

};
typedef struct student node;
node *head, *newNode, *previousNode, *enBasarili;


void studenList()
{
    int n, k;

    printf("Kac ogrenci gireceksiniz?: ");
    scanf("%d", &n);

    for(k=0;k<n;k++)
    {
        if(k==0)
        {
            newNode = (node *)malloc(sizeof(node));
            head = newNode;
        }
        else
        {
            newNode->next = (node *)malloc(n*sizeof(node));
            newNode = newNode->next;
        }
        printf("------BILGILERINIZI GIRINIZ------\n");
        printf("Ogrenci No: "); scanf("%d", &newNode->number);
        printf("Ogrenci Adi: "); scanf("%s", newNode->name);
        printf("Ogrenci Soyadi: "); scanf("%s", newNode->surname);
        printf("Ogrenci Vize Notu: "); scanf("%f", &newNode->midtermGrade);
        printf("Ogrenci Final Notu: "); scanf("%f", &newNode->finalGrade);
    }
    newNode->next = NULL;
}

void ogrenciListele(void)
{
    double donemNotu=0;
    node *p;
    p = head;
    while(p!=NULL)
    {
        printf("******ALINAN BILGILER******\n");
        printf("Ogrenci No: %d\n", p->number);
        printf("Ogrenci Adi: %s\n", p->name);
        printf("Ogrenci Soyadi: %s\n", p->surname);
        printf("Ogrenci Vize Notu: %f\n", p->midtermGrade);
        printf("Ogrenci Final Notu: %f\n", p->finalGrade);
        donemNotu = p->midtermGrade*0.4+p->finalGrade*0.6;
        printf("Donem Notu: %.2f\t\n", donemNotu);

        p = p->next;
    }
}

void ogrenciEkle()
{
    int kayitNo;
    node *p, *q;
    newNode = (node *) malloc(sizeof(node));

    printf("Ogrenci No: "); scanf("%d", &newNode->number);
    printf("Ogrenci Adi: "); scanf("%s", newNode->name);
    printf("Ogrenci Soyadi: "); scanf("%s", newNode->surname);
    printf("Ogrenci Vize Notu: "); scanf("%f", &newNode->midtermGrade);
    printf("Ogrenci Final Notu: "); scanf("%f", &newNode->finalGrade);

    printf("Hangi kayittan oncesine eklemek istiyorsunuz");
    printf("\nListe sonuna eklemek için 0 gir");
    scanf("%d", &kayitNo);

    p = head;
    if(p->number == kayitNo) //basa ekle
    {
        newNode->next = p;
        head = newNode;
    }else
    {
        while(p->next != NULL)
        {
            q=p;
            p=p->next;
            if(p->number == kayitNo) break;
        }
        if(p->number == kayitNo) //araya ekleme
        {
            q->next == newNode;
            newNode->next = p;
        }
        else if(p->next == NULL)
        {
            p->next = newNode;
            newNode->next = NULL;
        }
    }

}

void ogrenciSil()
{
    int kayitNo;
    node *p, *q;

    printf("Silmek istediginiz ogrencinin numarasini giriniz: ");
    scanf("%d", &kayitNo);

    p = head;
    if(p->number == kayitNo)
    {
        head = p->next;
        free(p);
    }
    else
    {
        while(p->next != NULL)
        {
            if(p->number == kayitNo)
                break;
            else
            {
                q=p;
                p=p->next;
            }
        }
        if(p->number == kayitNo)
        {
            q->next = p->next;
            free(p);
        }
        else if(p->next == NULL)
        {
            printf("Silinecek ogrenci no yok!\n");
        }
    }
}

double basariNotuHesapla(int midtermGrade, int finalGrade)
{
    return (0.4*midtermGrade)+(0.6*finalGrade);
}

void enBasariliOgrenci()
{
    double basariNotu = 0;

    node *p;
    p = head;
    enBasarili = head;

    while(p->next!=NULL)
    {
        p=p->next;
        if(basariNotuHesapla(p->midtermGrade,p->finalGrade)>basariNotuHesapla(enBasarili->midtermGrade,enBasarili->finalGrade))
            enBasarili=p;
    }
    printf("En basarili ogrenci:\n");
    printf("No: %d - Ad: %s Basari Notu: %.2f\n", enBasarili->number, enBasarili->name, basariNotuHesapla(enBasarili->midtermGrade,enBasarili->finalGrade));
}

void sinifBasariOrtalamasi()
{
    double basariNotuOrtalamasi=0;
    double toplam=0;
    int sayac=0;
    node *p;
    p = head;
    if(p == NULL)
    {
        printf("Listede kayit yok!");
    }
    else
    {
        do
        {
            toplam += basariNotuHesapla(p->midtermGrade, p->finalGrade);
            p=p->next;
            sayac++;
        }
        while(p!=NULL);

        basariNotuOrtalamasi = toplam/sayac;
        printf("Basari Notu Ortalamasi: %.2f\n", basariNotuOrtalamasi);
    }
}

int main(void)
{
    int secim=0;
    printf("1-Liste Olustur\n2-Yeni Kayit Ekle\n3-Kayit Sil\n4-En Yuksek Basari Notu\n5-Sinif Ortalamasi\n");
    while(1)
    {
        printf("Secim yap [1-5]?\n");
        scanf("%d", &secim);
        switch(secim)
        {
            case 1: studenList();ogrenciListele();break;
            case 2: ogrenciEkle(); ogrenciListele();break;
            case 3: ogrenciSil();ogrenciListele();break;
            case 4: enBasariliOgrenci();break;
            case 5: sinifBasariOrtalamasi();break;
        }
    }
}


