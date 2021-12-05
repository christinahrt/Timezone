#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome();
void verifikasi(int p, int *inputPin);
void saldoATM(int *saldoAkun, int saldoSisa);
void noRekening(int *noRek, int rekeningAkun);
void menu(int *input);
char *akunTZ, akun1[]="John Doe";
int input;
int pin, pin1 = 111000;
int saldo = 0, saldo1 = 500000;
int rek = 0, rek1 = 221017;


void verifikasi(int p, int *inputPin)
{
        char **akunAktif;
        if(p == pin1)
        {
                *inputPin = p;
                akunAktif = &akunTZ;
                *akunAktif = (char*) malloc(100 * sizeof(char));
                strcpy(*akunAktif, akun1);
                printf("\nNama akun : %s\n", akunTZ);
                saldoATM(&saldo,saldo1);
                printf("Saldo akun Rp %d\n", saldo);
                noRekening(&rek,rek1);
                printf("Rekening akun :%d\n", rek);
              	menu(&input);
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

void saldoATM(int *saldoAkun, int saldoSisa)
{
  *saldoAkun = saldoSisa;
}

void noRekening(int *noRek, int rekeningAkun) 
{
  *noRek = rekeningAkun;
}

void menu(int *input){
	int list;
	int totalsaldo;
printf("\n\n");
printf("                    MENU UTAMA\n");
printf("  1. 50.000\n");
printf("  2. 100.000\n");
printf("  3. 150.000 bonus 50.000\n");
printf("  4. 200.000 bonus 150.000\n");
printf("  4. 300.000 bonus 300.000\n");
printf("\n\nPILIHAN : ");
scanf("%d", &input);
switch(list)
{
	case 1 : //nilai variabel input = 1
  		totalsaldo = saldo + 50000;
		break; //Melompat ke baris setelah bagian akhir dari switch
		
	case 2 : //nilai variabel input = 1
		totalsaldo = saldo + 50000;
		break; //Melompat ke baris setelah bagian akhir dari switch
    default:

    break;
    
}
}

