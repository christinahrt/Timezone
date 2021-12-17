#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void profil();
void loginmember();
void registrasiMember();
void loginteller();
void menuTeller();
void menuMember();
void verifikasi(int pin);
void menusaldo();
void tiket();

int loginedIndex = -1;
int memberSize = 2;
int pilih_menu;

struct Member
{
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

struct Teller
{
	char namapetugas[50];
	int pin;
};

struct Teller petugas = {
	"Putu Ayu", 1111};

int main()
{
	profil();
	loginteller();

	return 0;
}

void profil()
{
	system("cls");
	printf("=====================================================\n");
	printf("                TUGAS BESAR PEMROGRAMAN              \n");
	printf("             PROGRAM TOP UP SALDO TIMEZONE           \n");
	printf("=====================================================\n");
	printf("          Program disusun dan dibuat oleh :          \n");
	printf("                                                     \n");
	printf("  1. Benita Carissa Sutrisno Putri (2105551002)      \n");
	printf("  2. Maria Christina Hartono       (2105551010)      \n");
	printf("                                                     \n");
	printf("             Jurusan Teknologi Informasi             \n");
	printf("                   Fakultas Teknik                   \n");
	printf("                 Universitas Udayana                 \n");
	printf("                       2021                          \n");
	printf("=====================================================\n");
	printf("          Tekan ENTER  untuk melanjutkan....         \n");
	printf("=====================================================\n");
	getchar();
	system("cls");
}

void loginteller()
{
	int inputpin;
	mengulang:

	printf("=====================================================\n");
	printf("                      LOGIN TELLER                   \n");
	printf("=====================================================\n");
	printf("Masukkan Kode Petugas   : ");
	scanf("%d", &inputpin);
	fflush(stdin);

	if (inputpin == petugas.pin)
	{
		printf("Nama Petugas            : %s                         \n", petugas.namapetugas);
		printf("=====================================================\n");
		printf("          Tekan ENTER  untuk melanjutkan....         \n");
		printf("=====================================================\n");
		getchar();
		system("cls");

		menuTeller(); //Fungsi untuk tampilan utama
	}

	else
	{
		printf("=====================================================\n");
		printf("              Masukkan kode dengan benar             \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();
		system("cls");
		goto mengulang;
	}
}

void menuTeller()
{
	mengulang:

	printf("=====================================================\n");
	printf("                         MENU                        \n");
	printf("=====================================================\n");
	printf("PILIHAN   : \n");
	printf("1. Login Member\n");
	printf("2. Registrasi Member Baru \n");
	printf("3. Keluar Program \n");
	printf("\n");
	printf("MASUKAN PILIHAN : ");
	scanf("%d", &pilih_menu);
	fflush(stdin);

	switch (pilih_menu)
	{
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
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		goto mengulang;
		break;
	}
}

void loginmember()
{

	int inputPin; //Deklarasi variabel untuk input pin
	mengulang:
	system("cls");

	printf("=====================================================\n");
	printf("              SELAMAT DATANG DI TIMEZONE             \n");
	printf("=====================================================\n");

	//Memasukkan pin
	printf("Masukkan Kode Member   : ");
	scanf("%d", &inputPin);
	fflush(stdin);

	verifikasi(inputPin);
}

void registrasiMember()
{

	int newPin, i;
	mengulang:
	system("cls");

	printf("=====================================================\n");
	printf("               REGISTRASI MEMBER BARU      	   	   \n");
	printf("=====================================================\n");

	printf("Masukkan Kode     : ");
	scanf("%d", &newPin);
	fflush(stdin);

	for (i = 0; i < memberSize; i++)
	{
		if (newPin == members[i].pin)
		{
			printf("=====================================================\n");
			printf("          Kode Sudah Digunakan. Coba Lainnya         \n");
			printf("           Tekan ENTER  untuk mengulang....          \n");
			printf("=====================================================\n");
			getchar();
			goto mengulang;
		}
	}

	members[memberSize].pin = newPin;

	printf("Masukkan Nama     : ");
	scanf("%[^\n]", members[memberSize].nama);
	fflush(stdin);

	printf("Masukkan No Kartu : ");
	scanf("%d", &members[memberSize].kartu);
	fflush(stdin);

	printf("Saldo Anda        : 0\n");
	members[memberSize].saldo = 0;

	memberSize++;

	printf("\nMember %s telah didaftarkan\n", members[memberSize - 1].nama);
	printf("=====================================================\n");
	printf("            Member Baru Berhasil Terdaftar           \n");
	printf("          Tekan ENTER  untuk melanjutkan....         \n");
	printf("=====================================================\n");
	getchar();
	system("cls");
	menuTeller();
}

void verifikasi(int pin)
{
	int i;

	//Perulangan untuk mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	for (i = 0; i < memberSize; i++)
	{
		if (pin == members[i].pin)
		{
			loginedIndex = i;
		}
	}

	if (loginedIndex == -1)
	{
		// jika member tidak ditemukan

		printf("=====================================================\n");
		printf("            Member tersebut belum terdaftar          \n");
		printf("            Tekan ENTER  untuk mengulang...          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");

		loginmember();
	}
	else
	{
		// jika member ditemukan
		printf("Nama Member            : %s                          \n", members[loginedIndex].nama);
		printf("Nomer Kartu            : %d                          \n", members[loginedIndex].kartu);
		printf("Jumlah Saldo           : Rp %d                       \n", members[loginedIndex].saldo);
		printf("Jumlah Tiket           : %d                          \n", members[loginedIndex].tiket);
		printf("                                                     \n");
		printf("=====================================================\n");
		printf("          Tekan ENTER  untuk melanjutkan....         \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		menuMember();
	}
}

void menuMember()
{
	printf("\n");
	printf("=====================================================\n");
	printf("                      MENU PROGRAM                   \n");
	printf("=====================================================\n");
	printf("PILIHAN   : \n");
	printf("1. Tambah Saldo Timezone\n");
	printf("2. Penukaran Tiket \n");
	printf("3. Keluar Program \n");
	printf("\n");
	printf("MASUKAN PILIHAN : ");
	scanf("%d", &pilih_menu);
	system("cls");

	switch (pilih_menu)
	{
	case 1:
		menusaldo();
		break;
	case 2:
		tiket();
		break;
	case 3:
		exit(0);
		break;
	default:
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		menuMember();
		break;
	}
}

void menusaldo()
{
	char kondisi;
	int input;
	mengulang:

	printf("=====================================================\n");
	printf("                   MENU TAMBAH SALDO    	     	   \n");
	printf("=====================================================\n");
	printf("  1. 50.000\n");
	printf("  2. 100.000\n");
	printf("  3. 150.000 bonus 50.000\n");
	printf("  4. 200.000 bonus 150.000\n");
	printf("  5. 300.000 bonus 300.000\n");
	printf("\n\nPILIHAN : ");
	scanf("%d", &input);
	fflush(stdin);

	switch (input)
	{
	case 1: //nilai variabel input = 1
		members[loginedIndex].saldo += 50000;
		break; //Melompat ke baris setelah bagian akhir dari switch

	case 2: //nilai variabel input = 2
		members[loginedIndex].saldo += 100000;
		break; //Melompat ke baris setelah bagian akhir dari switch

	case 3: //nilai variabel input = 3
		members[loginedIndex].saldo += 150000 + 50000;
		break;

	case 4: //nilai variabel input = 4
		members[loginedIndex].saldo += 200000 + 150000;
		break;

	case 5: //nilai variabel input = 5
		members[loginedIndex].saldo += 300000 + 300000;
		break;

	default:
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		system("cls");
		goto mengulang;
		break;
	}

	printf("\nTotal Saldo: Rp.%d\n", members[loginedIndex].saldo);
	printf("=====================================================\n");
	printf("                Saldo Berhasil Diisi                 \n");
	printf("          Ingin Isi Saldo Lagi? (tekan 'y')          \n");
	printf("          Kembali ke Menu Utama (tekan 'm')          \n");
	printf("=====================================================\n");
	scanf("\n%c", &kondisi);

	if (kondisi == 'y' || kondisi == 'Y')
	{
		system("cls");
		goto mengulang;
	}

	else if ((kondisi == 'm' || kondisi == 'M'))
	{
		menuMember();
	}

	else
	{
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		goto mengulang;
	}
}

void tiket()
{
	char kondisi;
	int inputtiket;
	mengulang:

	printf("=====================================================\n");
	printf("                      MENU HADIAH     	     	   \n");
	printf("=====================================================\n");
	printf("Jumlah Tiket   : %d                                  \n\n", members[loginedIndex].tiket);
	printf("  1. 50 Tiket  = Pulpen\n");
	printf("  2. 100 Tiket = Buku Tulis\n");
	printf("  3. 150 Tiket = Penggaris\n");
	printf("  4. 200 Tiket = Gantungan Kunci\n");
	printf("  5. 250 Tiket = Penghapus Pensil dan Pensil\n");
	printf("  6. 300 Tiket = Boneka Teddy Bear\n");
	printf("  7. 350 Tiket = Bantal Leher\n");
	printf("  8. 400 Tiket = Karet Rambut\n");
	printf("  9. 450 Tiket = Mobil Remot\n");
	printf(" 10. 500 Tiket = Mini Doll\n");
	printf("  0. Kembali\n\n");

	printf("Masukan Pilihan Hadiah : ");
	scanf("%d", &inputtiket);
	fflush(stdin);

	switch (inputtiket)
	{
	case 1:
		members[loginedIndex].tiket - 50;
		break;
	case 2:
		members[loginedIndex].tiket -= 100;
		break;
	case 3:
		members[loginedIndex].tiket -= 150;
		break;
	case 4:
		members[loginedIndex].tiket -= 200;
		break;
	case 5:
		members[loginedIndex].tiket -= 250;
		break;
	case 6:
		members[loginedIndex].tiket -= 300;
		break;
	case 7:
		members[loginedIndex].tiket -= 350;
		break;
	case 8:
		members[loginedIndex].tiket -= 400;
		break;
	case 9:
		members[loginedIndex].tiket -= 450;
		break;
	case 10:
		members[loginedIndex].tiket -= 500;
		break;
	case 0:
		menuMember();
		break;
	default:
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		goto mengulang;
		system("cls");
		break;
	}

	printf("Sisa Tiket Anda Sebesar : %d\n", members[loginedIndex].tiket);
	printf("=====================================================\n");
	printf("           Penukaran Tiket Telah Berhasil            \n");
	printf("         Ingin Tukar Tiket Lagi? (tekan 'y')         \n");
	printf("          Kembali ke Menu Utama (tekan 'm')          \n");
	printf("=====================================================\n");
	scanf("%c", &kondisi);
	fflush(stdin);

	if (kondisi == 'y' || kondisi == 'Y')
	{
		goto mengulang;
	}

	else if ((kondisi == 'm' || kondisi == 'M'))
	{
		menuMember();
	}

	else
	{
		printf("=====================================================\n");
		printf("           Pilihan yang Anda masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		system("cls");
		goto mengulang;
	}
}
