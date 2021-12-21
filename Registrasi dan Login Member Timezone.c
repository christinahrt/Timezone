#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void profil();
void loginmember();
void registrasiMember();
void verifikasi(int pin);
void menu();

int loginedIndex = -1;
int memberSize =2;
int pilih_menu;


struct Member {
	char nama[50];
	int pin;
	int kartu;
	int saldo;
	int tiket;
};

struct Member members[] = {
	{"Maria Christina Hartono", 1122, 221017, 500000, 611},
	{"Benita Carissa Sutrisno Putri", 2233, 568635, 750000, 320},
};

int main(){
    profil();
    menu();

	return 0;
}

void profil (){
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


void menu(){
	mengulang:
		
	printf  ("=====================================================\n");	
	printf  ("                         MENU                        \n");
	printf  ("=====================================================\n");
	printf  ("PILIHAN : \n");
	printf  ("1. Login Member\n");
	printf  ("2. Registrasi Member\n");
	printf  ("3. Keluar Program\n");
	printf  ("MASUKKAN PILIHAN : ");
	scanf   ("%d", &pilih_menu);
	fflush(stdin);
	
	switch(pilih_menu){
		case 1:
			loginmember();
			break;
		case 2:
			registrasiMember();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf  ("=======================================================\n");
			printf  ("             Masukkan Pilihan Dengan Benar             \n");
			printf  ("            Tekan ENTER  untuk mengulang....           \n");
			printf  ("=======================================================\n");
			getchar();
			system("cls");
			goto mengulang;
			break;
	}
	
	
}



void loginmember(){
	mengulang:
	system("cls");
	int inputPin;
	
	printf  ("=====================================================\n");	
	printf  ("              SELAMAT DATANG DI TIMEZONE             \n");
	printf  ("=====================================================\n");
	printf  ("Masukkan Kode Member	: ");
	scanf   ("%d", &inputPin);
	fflush(stdin);
	
	verifikasi(inputPin);
}

void registrasiMember(){
	int newPin, i;
	mengulang:
	system("cls");
	
	printf  ("=====================================================\n");	
	printf  ("                REGISTRASI MEMBER BARU               \n");
	printf  ("=====================================================\n");
	printf  ("Masukkan Kode       : ");
	scanf   ("%d",&newPin);
	fflush(stdin);
	
	for (i=0; i<memberSize; i++){
		if (newPin == members[i].pin){
			printf  ("=====================================================\n");	
			printf  ("          Kode Sudah Digunakan. Coba Lainnya         \n");
			printf  ("           Tekan ENTER  untuk mengulang....          \n");
			printf  ("=====================================================\n");
			getchar();
			goto mengulang;	
		}
	}
	
	members[memberSize].pin = newPin;
	
	printf("Masukan Nama        : ");
	scanf("%[^\n]",members[memberSize].nama);
	fflush(stdin);
	
	printf("Masukan Nomor Kartu : ");
	scanf("%d", &members[memberSize].kartu);
	fflush(stdin);

	printf("Saldo Anda          : 0\n");
	members[memberSize].saldo = 0;
	
	memberSize++;
	
	printf  ("\nMember %s telah didaftarkan\n", members[memberSize-1].nama);
	printf  ("=======================================================\n");
	printf  ("             Member Baru Telah Terdaftar               \n");
	printf  ("           Tekan ENTER  untuk melanjutkan....          \n");
	printf  ("=======================================================\n");
	getchar();
	system("cls");
	menu();
}

void verifikasi(int pin){
	int i;
	for (i= 0; i<memberSize; i++){
		if(pin == members[i].pin){
			loginedIndex = i;
		}
	}
	
	if(loginedIndex == -1){
	printf  ("=======================================================\n");
	printf  ("             Member Tersebut Belum Terdaftar           \n");
	printf  ("             Tekan ENTER  untuk mengulang....           \n");
	printf  ("=======================================================\n");
	getchar();
	system("cls");
	
	loginmember();
	}
	
	else{
		printf  ("Nama Member		: %s \n", members[loginedIndex].nama);
		printf  ("Nomor Kartu 		: %d \n", members[loginedIndex].kartu);
		printf  ("Jumlah Saldo		: Rp %d \n", members[loginedIndex].saldo);
		printf  ("Jumlah Tiket		: %d \n", members[loginedIndex].tiket);
		printf  ("=======================================================\n");
		printf  ("          Tekan ENTER  untuk melanjutkan....        \n");
		printf  ("=======================================================\n");
	getchar();
	system("cls");
	}
}



