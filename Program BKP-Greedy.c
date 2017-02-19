#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
//DEKLARASI PROSEDUR//
void Input_Data(int item[], int jum);
void Tampil_Data(int item[], int jum);
void Urutan_Profit(int *no, float *weight, float *profit, int *pieces, int c);
void Urutan_Density(int *no, float *weight, float *profit, int *pieces, double *density, int c);
void Urutan_Weight(int *no, float *weight, float *profit, int *pieces, int c);
void Seleksi_Data(int *no, float *weight, float *profit, int *pieces, int c);

typedef struct
{
    int b, no;
    float w, p;
    double d;         //rekaman data yakni berupa bobot, profit, densitas, tersedia, dan nomor//
    char ket[15];
}item;
item item1[100], item2[100];

float ransel;
char ulang;
int bnyk, k[100], n[100];
double o[100];
float l[100], m[100];

int main()
{
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("-PENYELESAIAAN OPTIMASI PADA BOUNDED KNAPSACK+\n");
    printf("+-+                                       -+-+\n");
    printf("-+-+-+-DENGAN MENGGUNAKAN METODE GREEDY+-+-+-+\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("----------------------------------------------\n");
    printf("                             by: Nanda Zulhija\n");
    printf("----------------------------------------------\n");
    printf("\n");

    ulang='y';
    for(;ulang=='Y' || ulang=='y';)

    {
    int X[100];


    printf("Ukuran ransel : "); scanf("%f", &ransel);
    printf("Banyak variasi item : "); scanf("%d", &bnyk);
    printf("\n");
    Input_Data(X,bnyk); //MEMASUKKAN SELURUH DATA KEDALAM PROSEDUR INPUT DATA//
    Tampil_Data(X,bnyk); //MENAMPILKAN KETERANGAN DATA YANG TELAH DIBUAT//
    /*TAHAP GREEDY BY PROFIT DIMULAI*/
    int i, j, c;
    float totw, totp;
    c=0, totw=0, totp=0;
    for(i=0; i<bnyk; i++)
    for(j=0; j<item1[i].b; j++)
    {
        k[c]=item1[i].no;
        l[c]=item1[i].w;
        m[c]=item1[i].p;
        n[c]=item1[i].b;
        c++;
    }
    Urutan_Profit(k,l,m,n,c); //PROSES PENGURUTAN BERDASARKAN PROFIT//
    Seleksi_Data(k,l,m,n,c);
    for(i=0; i<c; i++)
    {
        if(strcmp(item2[i].ket, "Take")==0)
        {
            totw=totw+item2[i].w;
            totp=totp+item2[i].p;
        }
    }
    /*HASIL GREEDY BY PROFIT*/

    printf("\n");
    printf("=================Greedy by Profit==============\n");
    printf("Objek     weight     profit     keterangan     \n");
    printf("-----------------------------------------------\n");
    for(i=0; i<c; i++)
    {
        printf("%d  %10f %10f %10s\n", item2[i].no, item2[i].w, item2[i].p, item2[i].ket);
    }
    printf("\n");
    printf("Total berat yg diambil : %f\n", totw);
    printf("Total profit yg diperoleh : %f\n", totp);

 /*TAHAP GREEDY BY DENSITY DIMULAI*/

    float totwd, totpd;
    c=0, totwd=0, totpd=0;
    for(i=0; i<bnyk; i++)
    for(j=0; j<item1[i].b; j++)
    {
        k[c]=item1[i].no;
        l[c]=item1[i].w;
        m[c]=item1[i].p;
        n[c]=item1[i].b;
        o[c]=item1[i].d;
        c++;
    }
    Urutan_Density(k,l,m,n,o,c);
    Seleksi_Data(k,l,m,n,c);
    for(i=0; i<c; i++)
    {
        if(strcmp(item2[i].ket, "Take")==0)
        {
            totwd=totwd+item2[i].w;
            totpd=totpd+item2[i].p;
        }
    }
    /*HASIL*/

    printf("\n");
    printf("======================Greedy by Density=================\n");
    printf("Objek     weight     profit     keterangan      density \n");
    printf("--------------------------------------------------------\n");
    for(i=0; i<c; i++)
    {
        item2[i].d=item2[i].p/item2[i].w;
        printf("%d  %10f %10f %10s %15f\n", item2[i].no, item2[i].w, item2[i].p, item2[i].ket, item2[i].d);
    }
    printf("\n");
    printf("Total berat yg diambil : %f\n", totwd);
    printf("Total profit yg diperoleh : %f\n", totpd);

    printf("\n");

    /*TAHAP GREEDY BY WEIGHT*/
    float totww, totpw;
    c=0, totww=0, totpw=0;
    for(i=0; i<bnyk; i++)
    for(j=0; j<item1[i].b; j++)
    {
        k[c]=item1[i].no;
        l[c]=item1[i].w;
        m[c]=item1[i].p;
        n[c]=item1[i].b;
        c++;
    }
    Urutan_Weight(k,l,m,n,c);
    Seleksi_Data(k,l,m,n,c);
    for(i=0; i<c; i++)
    {
        if(strcmp(item2[i].ket, "Take")==0)
        {
            totww=totww+item2[i].w;
            totpw=totpw+item2[i].p;
        }
    }
    /*HASIL GREEDY BY WEIGHT*/

    printf("\n");
    printf("==================Greedy by weight============\n");
    printf("Objek     weight     profit     keterangan    \n");
    printf("----------------------------------------------\n");
    for(i=0; i<c; i++)
    {
        printf("%d  %10f %10f %10s\n", item2[i].no, item2[i].w, item2[i].p, item2[i].ket);
    }
    printf("\n");
    printf("Total berat yg diambil : %f\n", totww);
    printf("Total profit yg diperoleh : %f\n", totpw);

    printf("\n");
    printf("\n");
    printf("PERBANDINGAN PROFIT HASIL OPTIMASI\n");
    printf("==================================\n");
    printf("G-Profit    G-Density    G-Wight\n");
    printf("----------------------------------\n");
    printf(" %f  %10f  %10f", totp, totpd, totpw);
    printf("\n");
    //*PERBANDINGAN DARI KETIGA METODE*//
    float terbaik;
    char note[40];
    terbaik=totp;
    strcpy(note, "Greedy by Profit");
    if(terbaik<totpw){
    terbaik=totpw;
    strcpy(note, "Greedy by Weight");
    }
    if(terbaik<totpd){
    terbaik=totpd;
    strcpy(note, "Greedy by Density");
    }

    printf("\n");
    printf("REKOMENDASI : %s dengan KEUNTUNGAN : %f\n", note, terbaik);

    printf("\n");

    printf("\n");

    printf("ulang pekerjaan (y\\n) : "); ulang=getche();
    printf("\n\n");

    }
}
void Input_Data(int item[], int jum)
{
    int i;
    for(i=0; i<jum; i++)
    {
        printf("Berat objek ke %d : ", i+1); scanf("%f", &item1[i].w);
        printf("Profit objek ke %d : ", i+1); scanf("%f", &item1[i].p);
        printf("Jumlah objek ke %d : ", i+1); scanf("%d", &item1[i].b);
        item1[i].no=i+1;
    }
}

void Tampil_Data(int item[], int jum)
{
    int i;
    printf("\n");
    printf("Objek(i)    Berat(w)     Profit(p)    Banyak(b)    Density(d)\n");
    printf("-------------------------------------------------------------\n");
    for(i=0; i<jum; i++)
    {
        item1[i].d=item1[i].p/item1[i].w;
        printf("%2d %12f %12f %12d %12f\n", item1[i].no, item1[i].w, item1[i].p, item1[i].b, item1[i].d);
    }
}
void Urutan_Profit(int *no, float *weight, float *profit, int *pieces, int c)
{
    int i, j, sementara;
    for(i=0; i<c-1; i++)
        for(j=i; j<c; j++)
        {
            if(profit[i]<profit[j])
            {
                sementara=no[i];
                no[i]=no[j];
                no[j]=sementara;
                sementara=weight[i];
                weight[i]=weight[j];
                weight[j]=sementara;
                sementara=profit[i];
                profit[i]=profit[j];
                profit[j]=sementara;
                sementara=pieces[i];
                pieces[i]=pieces[j];
                pieces[j]=sementara;
            }
        }
}
void Urutan_Density(int *no, float *weight, float *profit, int *pieces, double *density, int c)
{
    int i, j;
    double temp;
    for(i=0; i<c-1; i++)
        for(j=i; j<c; j++)
        {
            if(density[i]<density[j])
            {
                temp=no[i];
                no[i]=no[j];
                no[j]=temp;
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
                temp=pieces[i];
                pieces[i]=pieces[j];
                pieces[j]=temp;
                temp=density[i];
                density[i]=density[j];
                density[j]=temp;
            }
        }
}
void Urutan_Weight(int *no, float *weight, float *profit, int *pieces, int c)
{
    int i, j, sementara;
    for(i=0; i<c-1; i++)
        for(j=i; j<c; j++)
        {
            if(weight[i]>weight[j])
            {
                sementara=no[i];
                no[i]=no[j];
                no[j]=sementara;
                sementara=weight[i];
                weight[i]=weight[j];
                weight[j]=sementara;
                sementara=profit[i];
                profit[i]=profit[j];
                profit[j]=sementara;
                sementara=pieces[i];
                pieces[i]=pieces[j];
                pieces[j]=sementara;
            }
        }
}

void Seleksi_Data(int *no, float *weight, float *profit, int *pieces, int c)
{
    int i;
    float acc;
    acc=0;
    for(i=0; i<c; i++)
    {
        item2[i].no=k[i];
        item2[i].w=l[i];
        item2[i].p=m[i];
        item2[i].b=n[i];
    }
    for(i=0; i<c; i++)
    {
        if(acc+item2[i].w<=ransel){
        acc=acc+item2[i].w;
        strcpy(item2[i].ket, "Take");
        }
        else
        {
            strcpy(item2[i].ket, "Leave");
        }

    }
}
