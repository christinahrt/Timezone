#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome();
void header();
void verifikasi(int pin);
void tampilkanStrukTimezone();
void menu();

int loginedIndex;
int memberSize = 2;

struct Member{
    char nama[50];
    int pin;
    int kartu;
    int saldo;
};

struct Member members[] = {
	{"Maria Christina Hartono", 1122, 221017, 500000},
	{"Benita", 2233, 568635, 750000},
};

int main(){
    header();
	welcome(); //Fungsi untuk tampilan utama
	menu();

	return 0;
}

void header (){
    system ("cls");
	printf  ("=====================================================\n");	
	printf  ("                TUGAS BESAR PEMROGRAMAN              \n");
	printf  ("             PROGRAM TOP UP SALDO TIMEZONE           \n");
	printf  ("=====================================================\n");
	printf  ("          Program disusun dan dibuat oleh :          \n");
	printf  ("                                                     \n");
	printf  ("  1. Benita Carissa Sutrisno Putri (2105551002)      \n");
	printf  ("  2. Maria Christina Hartono       (2105551010)      \n");
	printf  ("                                                     \n");
	printf  ("             Jurusan Teknologi Informasi             \n");
	printf  ("                   Fakultas Teknik                   \n");
	printf  ("                 Universitas Udayana                 \n");
	printf  ("                       2021                          \n");
	printf  ("=====================================================\n");
	printf  ("          Tekan ENTER  untuk melanjutkan....         \n");
    printf  ("=====================================================\n");
	getchar ();
    system ("cls");
}

void welcome(){
	mengulang:
	system("cls");
	
    int inputPin; //Deklarasi variabel untuk input pin
    
    printf  ("=====================================================\n");	
	printf  ("              SELAMAT DATANG DI TIMEZONE             \n");
	printf  ("=====================================================\n");
    
    
//	printf("===============================================================================================\n");
//	printf("\t\t\t\t  SELAMAT DATANG DI TIMEZONE \n");
//	printf("===============================================================================================\n\n");
//	
	//Memasukkan pin
	printf  ("Masukkan password anda   : ");
	scanf("%d", &inputPin);
	fflush(stdin);
	
    verifikasi(inputPin);
}

void verifikasi(int pin){
	int i;
	
	for (i = 0; i <memberSize ; ++i){
		if (pin == members[i].pin){
			loginedIndex = i;
		}
	}
	
	printf  ("Nama Pemilik 			 : %s                          \n", members[loginedIndex].nama);
	printf  ("Jumlah Saldo			 : Rp %d                       \n", members[loginedIndex].saldo);
  printf  ("Nomer Kartu 			 : %d                          \n", members[loginedIndex].kartu);

	printf  ("                                                     \n");
	printf  ("=====================================================\n");
	printf  ("          Tekan ENTER  untuk melanjutkan....         \n");
    printf  ("=====================================================\n");

	
	
//	printf("\nNama Pemilik : %s\n", members[loginedIndex].nama);
//	printf("Jumlah Saldo : Rp %d\n", members[loginedIndex].saldo);
//    printf("Nomer Kartu :%d\n", members[loginedIndex].kartu);
//    printf("tekan enter untuk melanjutkan\n");
//	getchar ();
    system ("cls");
}

void menu(){
	int input;

	printf  ("\n\n");
    printf  ("=====================================================\n");	
	printf  ("     					 MENU UTAMA     	     	   \n");
	printf  ("=====================================================\n");
	printf  ("  2. 100.000\n");
	printf  ("  3. 150.000 bonus 50.000\n");
	printf  ("  4. 200.000 bonus 150.000\n");
	printf  ("  5. 300.000 bonus 300.000\n");
	printf  ("\n\nPILIHAN : ");
	scanf("%d", &input);
	
	switch(input)
	{
		case 1 : //nilai variabel input = 1
	  		members[loginedIndex].saldo += 50000;
	  		printf("\nTotal Saldo: Rp.%d", members[loginedIndex].saldo);
			break; //Melompat ke baris setelah bagian akhir dari switch
			
		case 2 : //nilai variabel input = 2
	  		members[loginedIndex].saldo += 100000;
			printf("\nTotal Saldo: Rp.%d", members[loginedIndex].saldo);
			break; //Melompat ke baris setelah bagian akhir dari switch
			
		case 3 : //nilai variabel input = 3
	  		members[loginedIndex].saldo += 150000 + 50000;
	  		printf("\nTotal Saldo: Rp.%d", members[loginedIndex].saldo);
			break;
	
		case 4 : //nilai variabel input = 4
	  		members[loginedIndex].saldo += 200000 + 150000;
	  		printf("\nTotal Saldo: Rp.%d", members[loginedIndex].saldo);
			break;
	
		case 5 : //nilai variabel input = 5
	  		members[loginedIndex].saldo += 300000 + 300000;
	  		printf("\nTotal Saldo: Rp.%d", members[loginedIndex].saldo);
			break;
	}
}

