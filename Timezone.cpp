#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void profil();
void loginmember();
void daftarbaru();
void masukteller();
void menumasuk();
void menu_program();
void verifikasi();
void verifikasiteller();
void menusaldo();
void tiket();


char kondisi;
int loginedIndex = -1;
int memberSize = 2;
int pilih_menu;


struct Member{
    char nama[50];
    int pin;
    int kartu;
    int saldo;
    int tiket;
  
};

struct Member members[] = {
	{"Maria Christina Hartono", 1122, 221017, 500000,611},
	{"Benita Carissa Sutrisno Putri", 2233, 568635, 750000,320},
};


struct Teller{
    char namapetugas[50];
    int pintel;

};

struct Teller petugas[] = {
	{"Putu Ayu", 1111}
};


int main(){
    profil();
    masukteller();
    menumasuk();
 //Fungsi untuk tampilan utama
	menu_program();
	menusaldo();
	tiket();

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

void verifikasiteller(int pintel){
	int i;
	
  //Perulangan untuk mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	for (i = 0; i < memberSize; i++){
		if (pintel == petugas[i].pintel){
			loginedIndex = i;
		}
	}
	
	if(loginedIndex == -1){
		// jika member tidak ditemukan
		printf  ("Pegawai Tidak Dikenali \n");
		printf  ("                                                     \n");
		printf  ("=====================================================\n");
		printf  ("           Tekan ENTER  untuk mengulang....          \n");
	    printf  ("=====================================================\n");
	
		getchar();
		system ("cls");
		
		masukteller();
	}else{
		// jika member ditemukan
		printf  ("Nama Pegawai           : %s                          \n", petugas[loginedIndex].namapetugas);
		printf  ("                                                     \n");
		printf  ("=====================================================\n");
		printf  ("          Tekan ENTER  untuk melanjutkan....         \n");
	    printf  ("=====================================================\n");
	
		getchar ();
		system ("cls");		
	}
}

void masukteller(){
    mengulang:
	system("cls");
	
    int inputPin; //Deklarasi variabel untuk input pin
    
    printf  ("=====================================================\n");	
	printf  ("              SELAMAT DATANG DI TIMEZONE             \n");
	printf  ("=====================================================\n");
    
	//Memasukkan pin
	printf  ("Masukkan Kode Member   : ");
	scanf   ("%d", &inputPin);
	fflush(stdin);
	
  verifikasiteller(inputPin);
}

void menumasuk(){

  system("cls");
  pilih:
  printf  ("\n");
  printf  ("=======================================================\n");
  printf  ("                          MENU                         \n");
  printf  ("=======================================================\n");
  printf  ("PILIHAN   : \n");
  printf  ("1. Login Member\n");
  printf  ("2. Registrasi Member Baru \n");
  printf  ("3. Keluar Program \n");
  printf  ("\n");
  printf  ("MASUKAN PILIHAN : ");
  scanf   ("%d", &pilih_menu);
  
  system("cls");

  switch(pilih_menu){
    case 1:
    loginmember();
    break;
    case 2:
    daftarbaru();
    break;
    case 3:
    exit (0);
    break;
    default:
    printf("Ketikkan Pilihan Anda dengan Benar");
    menumasuk();
    break;
  }

}

void loginmember(){
  system("cls");
	mengulang:
	system("cls");
	
    int inputPin; //Deklarasi variabel untuk input pin
    
    printf  ("=====================================================\n");	
	printf  ("              SELAMAT DATANG DI TIMEZONE             \n");
	printf  ("=====================================================\n");
    
	//Memasukkan pin
	printf  ("Masukkan Kode Member   : ");
	scanf   ("%d", &inputPin);
	fflush(stdin);
	
    verifikasi(inputPin);
}

void daftarbaru(){
	
	int newPin, i;
	mengulang:
	system("cls");
	
	printf  ("=====================================================\n");	
	printf  ("               REGISTRASI MEMBER BARU      	   	   \n");
	printf  ("=====================================================\n");

	printf("Masukkan Kode     : ");
	scanf("%d", &newPin);
	fflush(stdin);
	
	for (i = 0; i < memberSize; i++){
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

	printf("Masukkan Nama     : ");
	scanf("%[^\n]",members[memberSize].nama);
//	fgets(members[memberSize].nama, sizeof(members[memberSize].nama), stdin);
//	scanf("%s", &members[memberSize].nama);
	fflush(stdin);
	
	printf("Masukkan No Kartu : ");
	scanf("%d", &members[memberSize].kartu);
	fflush(stdin);

	printf("Saldo Anda        : 0\n");
	members[memberSize].saldo = 0;
	
	memberSize++;
	
	printf  ("\nMember %s telah didaftarkan\n", members[memberSize-1].nama);
	printf  ("=====================================================\n");
	printf  ("            Member Baru Berhasil Terdaftar           \n");
	printf  ("          Tekan ENTER  untuk melanjutkan....         \n");
    printf  ("=====================================================\n");	
	getchar();
	
}

void verifikasi(int pin){
	int i;
	
  //Perulangan untuk mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	for (i = 0; i < memberSize; i++){
		if (pin == members[i].pin){
			loginedIndex = i;
		}
	}
	
	if(loginedIndex == -1){
		// jika member tidak ditemukan
		printf  ("Member tersebut belum terdaftar \n");
		printf  ("                                                     \n");
		printf  ("=====================================================\n");
		printf  ("           Tekan ENTER  untuk mengulang....          \n");
	    printf  ("=====================================================\n");
	
		getchar();
		system ("cls");
		
		loginmember();
	}else{
		// jika member ditemukan
		printf  ("Nama Member            : %s                          \n", members[loginedIndex].nama);
	    printf  ("Nomer Kartu            : %d                          \n", members[loginedIndex].kartu);
		printf  ("Jumlah Saldo           : Rp %d                       \n", members[loginedIndex].saldo);
	    printf  ("Jumlah Tiket           : %d                          \n", members[loginedIndex].tiket);
		printf  ("                                                     \n");
		printf  ("=====================================================\n");
		printf  ("          Tekan ENTER  untuk melanjutkan....         \n");
	    printf  ("=====================================================\n");
	
		getchar ();
		system ("cls");		
	}
}

void menusaldo(){
  system("cls");
	int input;
	mengulang:
	system("cls");

    printf  ("=====================================================\n");	
	printf  ("                      MENU TAMBAH SALDO      	     	   \n");
	printf  ("=====================================================\n");
	printf  ("  1. 50.000\n");
	printf  ("  2. 100.000\n");
	printf  ("  3. 150.000 bonus 50.000\n");
	printf  ("  4. 200.000 bonus 150.000\n");
	printf  ("  5. 300.000 bonus 300.000\n");
	printf  ("\n\nPILIHAN : ");
	scanf   ("%d", &input);
	fflush(stdin);

	switch(input)
	{
		case 1 : //nilai variabel input = 1
	  		members[loginedIndex].saldo += 50000;
			break; //Melompat ke baris setelah bagian akhir dari switch
			
		case 2 : //nilai variabel input = 2
	  		members[loginedIndex].saldo += 100000;
			break; //Melompat ke baris setelah bagian akhir dari switch
			
		case 3 : //nilai variabel input = 3
	  		members[loginedIndex].saldo += 150000 + 50000;
			break;
	
		case 4 : //nilai variabel input = 4
	  		members[loginedIndex].saldo += 200000 + 150000;
			break;
	
		case 5 : //nilai variabel input = 5
	  		members[loginedIndex].saldo += 300000 + 300000;
			break;
			
		default :
			printf  ("=====================================================\n");
			printf  ("           Pilihan yang Anda masukkan Salah          \n");
			printf  ("           Tekan ENTER  untuk mengulang....          \n");
		    printf  ("=====================================================\n");
		    getchar();
		    
			goto mengulang;
			break;
	}
	
	printf  ("\nTotal Saldo: Rp.%d\n", members[loginedIndex].saldo);
	printf  ("=====================================================\n");
	printf  ("                Saldo Berhasil Diisi                 \n");	
	printf  ("             Ingin Isi Saldo Lagi? (y/t)             \n");
    printf  ("=====================================================\n");
	scanf("\n%c",&kondisi);
	
	if(kondisi == 'y'||kondisi =='Y')
	{
		goto mengulang;
	}
	
	else if((kondisi == 't'||kondisi =='T'))
	{
    menu_program();
	}
	
    else 
    {
    	printf("Masukkan pilihan dengan benar");
	}
}


void menu_program(){
  system("cls");
  pilih:

  printf("\n");
  printf("=======================================================\n");
  printf("                       MENU PROGRAM                    \n");
  printf("=======================================================\n");
  printf("PILIHAN   : \n");
  printf("1. Tambah Saldo Timezone\n");
  printf("2. Penukaran Tiket \n");
  printf("3. Keluar Program \n");
  printf("\n");
  printf("MASUKAN PILIHAN : ");
  scanf("%d", &pilih_menu);
  system ("cls");

  switch(pilih_menu){
    case 1:
    menusaldo();
    break;
    case 2:
    tiket();
    break;
    case 3:
    exit (0);
    break;
    default:
    printf("Ketikkan Pilihan Anda dengan Benar");
    menu_program();
    break;

  }

}

void tiket(){
  system("cls");
	int inputtiket;
	mengulang:
	system("cls");

    printf  ("\n=====================================================\n");	
	printf  ("                      MENU HADIAH     	     	   \n");
	printf  ("=====================================================\n");
	printf  ("Jumlah Tiket   : %d                                  \n\n", members[loginedIndex].tiket);
	printf  ("  1. 50 Tiket  = Pulpen\n");
	printf  ("  2. 100 Tiket = Buku Tulis\n");
	printf  ("  3. 150 Tiket = Penggaris\n");
	printf  ("  4. 200 Tiket = Gantungan Kunci\n");
	printf  ("  5. 250 Tiket = Penghapus Pensil dan Pensil\n");
	printf  ("  6. 300 Tiket = Boneka Teddy Bear\n");
	printf  ("  7. 350 Tiket = Bantal Leher\n");
	printf  ("  8. 400 Tiket = Karet Rambut\n");
	printf  ("  9. 450 Tiket = Mobil Remot\n");
	printf  (" 10. 500 Tiket = Mini Doll\n\n");
	
	printf  ("Masukan Pilihan Hadiah : ");
	scanf   ("%d", &inputtiket);
	fflush(stdin);
	
	switch(inputtiket)
	{
		case 1 :
			members[loginedIndex].tiket - 50;
			break;
		case 2 :
			members[loginedIndex].tiket -=100;
			break;
		case 3 :
			members[loginedIndex].tiket -=150;
			break;
		case 4 :
			members[loginedIndex].tiket -=200;
			break;
		case 5 :
			members[loginedIndex].tiket -=250;
			break;
		case 6 :
			members[loginedIndex].tiket -=300;
			break;
		case 7 :
			members[loginedIndex].tiket -=350;
			break;
		case 8 :
			members[loginedIndex].tiket -=400;
			break;
		case 9 :
			members[loginedIndex].tiket -=450;
			break;
		case 10 :
			members[loginedIndex].tiket -=500;
			break;
	}
	
	printf  ("\nSisa Tiket Anda Sebesar : %d\n", members[loginedIndex].tiket);
	printf  ("=====================================================\n");
	printf  ("            Ingin Tukar Tiket Lagi? (y/t)            \n");
    printf  ("=====================================================\n");
	scanf("\n%c",&kondisi);
	
	if(kondisi == 'y'||kondisi =='Y')
	{
		goto mengulang;
	}
	
	else if((kondisi == 't'||kondisi =='T'))
	{
    exit(0);
	}
	
    else 
    {
    	printf("Masukkan pilihan dengan benar");
	}
	getchar();

}
	

