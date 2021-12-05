#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome();
void verifikasi(int p, int *inputPin);
void saldoTZ(int *saldoAkun, int saldoSisa);
void noKartu(int *noRek, int kartuAkun);
void tampilkanStrukTimezone();
void menu();
char *akunTZ, akun1[]="Christina Hartono", akun2[]="Benita Carissa";
int input, totalsaldo;
int pin, pin1 = 1122, pin2 = 2233;
int saldo = 0, saldo1 = 500000, saldo2 = 750000;
int kartu = 0, kartu1 = 221017, kartu2 = 568635;


void verifikasi(int p, int *inputPin)
{
        char **akunAktif;
        if(p == pin1)
        {
                *inputPin = p;
                akunAktif = &akunTZ;
                *akunAktif = (char*) malloc (100 * sizeof(char));
                strcpy(*akunAktif, akun1);
                printf("\nNama Pemilik : %s\n", akunTZ);
                saldoTZ(&saldo,saldo1);
                printf("Jumlah Saldo : Rp %d\n", saldo);
                noKartu(&kartu,kartu1);
                printf("Nomer Kartu :%d\n", kartu);
              	menu();
         }
         
        else if(p == pin2)
        {
                *inputPin = p;
                akunAktif = &akunTZ;
                *akunAktif = (char*) malloc (100 * sizeof(char));
                strcpy(*akunAktif, akun2);
                printf("\nNama Pemilik : %s\n", akunTZ);
                saldoTZ(&saldo,saldo2);
                printf("Jumlah Saldo : Rp %d\n", saldo);
                noKartu(&kartu,kartu2);
                printf("Nomer Kartu :%d\n", kartu);
              	menu();
         }
         else
         {
                welcome();
         }
}

int main()
{
        welcome(); //Fungsi untuk tampilan utama
return 0;
}
void welcome()
{
        int inputPin; //Deklarasi variabel untuk input pin
		printf("===============================================================================================\n");
		printf("\t\t\t\t  SELAMAT DATANG DI TIMEZONE \n");
		printf("===============================================================================================\n\n");
        printf("Masukkan password anda :");
		scanf("%d", &inputPin);
 //Memasukkan pin
        verifikasi(inputPin, &pin);
 //Memanggil fungsi verifikasi dari file header 'fungsi.h'
}

void saldoTZ(int *saldoAkun, int saldoSisa)
{
  *saldoAkun = saldoSisa;
}

void noKartu(int *noRek, int kartuAkun) 
{
  *noRek = kartuAkun;
}

void menu(){
	int input;

printf("\n\n");
printf("===============================================================================================\n");
printf("\t\t\t\t\t  MENU UTAMA \n");
printf("===============================================================================================\n\n");
printf("  1. 50.000\n");
printf("  2. 100.000\n");
printf("  3. 150.000 bonus 50.000\n");
printf("  4. 200.000 bonus 150.000\n");
printf("  5. 300.000 bonus 300.000\n");
printf("\n\nPILIHAN : ");
scanf("%d", &input);
switch(input)
{
	case 1 : //nilai variabel input = 1
  		totalsaldo = saldo + 50000;
  		printf("\nTotal Saldo: Rp.%d", totalsaldo);
		break; //Melompat ke baris setelah bagian akhir dari switch
		
	case 2 : //nilai variabel input = 2
		totalsaldo = saldo + 100000;
		printf("\nTotal Saldo: Rp.%d", totalsaldo);
		break; //Melompat ke baris setelah bagian akhir dari switch
		
	case 3 : //nilai variabel input = 3
  		totalsaldo = saldo + 150000 + 50000;
  		printf("\nTotal Saldo: Rp.%d", totalsaldo);
		break;

	case 4 : //nilai variabel input = 4
  		totalsaldo = saldo + 200000 + 150000;
  		printf("\nTotal Saldo: Rp.%d", totalsaldo);
		break;

	case 5 : //nilai variabel input = 5
  		totalsaldo = saldo + 300000 + 300000;
  		printf("\nTotal Saldo: Rp.%d", totalsaldo);
		break;

    default:

    break;
    
}
}

