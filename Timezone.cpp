//Header yang di gunakan untuk standar input output pada bahasa C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi fungsi-fungsi yang digunakan pada program 
void profil();						
void loginmember();				//Merupakan fungsi yang digunakan untuk meminta user yang telah terdaftar menginputkan kode member 
void registrasiMember();			//Merupakan fungsi yang digunakan untuk untuk menyimpan perintah-perintah yang dibutuhkan untuk registrasi member
void loginteller();				//Merupakan fungsi yang digunakan untuk meminta teller yang terdaftar untuk menginputkan kode teller
void menuTeller();				//Merupakan fungsi yang digunakan untuk menampilkan pilihan menu teller yang ada
void menuMember();				//Merupakan fungsi yang digunakan untuk meminta user memilih menu yang ada pada menu member
void verifikasi(int pin);			//Merupakan fungsi yang digunakan memverifikasi kode member yang diinputkan telah terdaftar atau belum
void menusaldo();				//Merupakan fungsi yang digunakan untuk menambah saldo sesuai dengan yang ada pada pilihan tambah saldo
void tiket();					//Merupakan fungsi yang digunakan untuk menukarkan tiket sesuai dengan poin tiket yang tersedia pada akun member

int loginedIndex = -1;				//inisialisasi variabel loginIndex untuk menyimpan
int memberSize = 2;				//inisialisasi variabel memberSize untuk menyimpan banyaknya member yang sudah terdaftar
int pilih_menu;					//variabel untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada fungsi menuTeller dan menuMember


// Struct Member untuk menyimpan member nama, pin, kartu, saldo, tiket
struct Member
{
	char nama[50];
	int pin;
	int kartu;
	int saldo;
	int tiket;
};

//Mendeklarasikan struct Member dengan variabel members beserta dengan 
struct Member members[] = {
	{"Maria Christina Hartono", 1122, 221017, 500000, 611},
	{"Benita Carissa Sutrisno Putri", 2233, 568635, 750000, 320},
};

//Struct Teller untuk menyimpan teller namapetugas, dan pin
struct Teller
{
	char namapetugas[50];
	int pin;
};

//Mendeklarasikan struct Teller dengan variabel petugas
struct Teller petugas = {
	"Putu Ayu", 1111};


// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
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
	int inputpin; //Deklarasi untuk variabel input pin
	mengulang:

	printf("=====================================================\n");
	printf("                     LOGIN PETUGAS                   \n");
	printf("=====================================================\n");
	printf("Masukkan Kode Petugas   : ");
	scanf("%d", &inputpin);
	fflush(stdin);
	
	//Perulangan yang akan ditampilkan jika inputpin yang dimasukkan adalah sama dengan pin petugas
	if (inputpin == petugas.pin)
	{
		printf("Nama Petugas            : %s                         \n", petugas.namapetugas);
		printf("=====================================================\n");
		printf("                  Petugas Terdeteksi                 \n");
		printf("          Tekan ENTER  untuk melanjutkan....         \n");
		printf("=====================================================\n");
		getchar();
		system("cls");

		menuTeller(); //Fungsi untuk tampilan utama
	}
	
	//perulangan yang ditampilkan apabila kode petugas yang diinputkan salah 
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
	
	//pada menu switch case bagian ini , merupakan lanjutan proses dari pilihan yang di inputkan sebelumnya pada pilihan MENU pada menuTeller
	switch (pilih_menu) 
	{
	//pada case 1 ini, karena pegawai memilih login member maka program akan menampilkan menu loginmember dan user akan diminta untuk memasukkan kode member yang selanjutnya akan diverifikasi apakah kode member yang diinputkan terdaftar pada sistem atau tidak
	case 1:
		loginmember();
		break;
	
	//pada case 2 ini, karena pegawai memilih registrasi member maka program akan menampilkan menu registrasiMember dan user akan diminta untuk memasukkan data-data yang diperlukan untuk selanjutnya diproses agar user dapat login ke sistem
	case 2:
		registrasiMember();
		break;
			
	//pada case 3 ini, karena pegawai memilih exit maka program akan keluar dari sistem.
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
	fflush(stdin); //Perintah untuk membersihkan buffer

	verifikasi(inputPin);
}

void registrasiMember()
{

	int newPin; //deklarasi variabel newPin untuk kode registrasi member baru
	int i; // deklarasi variabel i untuk perulangan mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	mengulang:
	system("cls");

	printf("=====================================================\n");
	printf("               REGISTRASI MEMBER BARU      	     \n");
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
	int i; // deklarasi variabel i untuk perulangan mengecek pin member baru agar tidak sama dengan pin member yang sudah ada

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
	//pada case 1, karena user memilih menu saldo maka program akan menampilkan menusaldo dan selanjutnya user akan menambah saldo sesuai dengan yang ada pada pilihan
	case 1:
		menusaldo();
		break;
			
	//pada case 2 ini, karena user memilih menu tiket, maka program akan menampilkan menu tiket dimana selanjutnya user akan menukarkan tiket yang dimiliki dengan hadiah yang ditawarkan
	case 2:
		tiket();
		break;
		
	//pada case 3 ini, karena user memilih menu exit, maka program akan berhenti atau user keluar dari program
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
	char kondisi; //deklarasi untuk variabel input
	int input; //deklarasi untuk variabel input
	mengulang:

	printf("=====================================================\n");
	printf("                   MENU TAMBAH SALDO    	     	   \n");
	printf("=====================================================\n");
	printf("  1. 50.000\n");
	printf("  2. 100.000\n");
	printf("  3. 150.000 bonus 50.000\n");
	printf("  4. 200.000 bonus 150.000\n");
	printf("  5. 300.000 bonus 300.000\n");
	printf("  0. Kembali\n\n");

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
	case 0:
		system("cls");
		menuMember();
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
		goto mengulang; //akan kembali ke fungsi menusaldo
	}

	else if ((kondisi == 'm' || kondisi == 'M'))
	{
		system("cls");
		menuMember(); //akan kembali ke fungsi menuMember
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
	char kondisi; //deklarasi variabel kondisi
	int inputtiket; //deklarasi variabel inputtiket
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
	//pada case 1 ini, karena user memilih option nomer 1 maka jumlah tiket yang ada pada akun akan dikurang dengan 50 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 1:
		members[loginedIndex].tiket - 50;
		break;
	
	//pada case 2 ini, karena user memilih option nomer 2 maka jumlah tiket yang ada pada akun akan dikurang dengan 100 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 2:
		members[loginedIndex].tiket -= 100;
		break;
	
	//pada case 3 ini, karena user memilih option nomer 3 maka jumlah tiket yang ada pada akun akan dikurang dengan 150 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 3:
		members[loginedIndex].tiket -= 150;
		break;
	
	//pada case 4 ini, karena user memilih option nomer 4 maka jumlah tiket yang ada pada akun akan dikurang dengan 200 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 4:
		members[loginedIndex].tiket -= 200;
		break;
	
	//pada case 5 ini, karena user memilih option nomer 5 maka jumlah tiket yang ada pada akun akan dikurang dengan 250 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 5:
		members[loginedIndex].tiket -= 250;
		break;
	
	//pada case 6 ini, karena user memilih option nomer 6 maka jumlah tiket yang ada pada akun akan dikurang dengan 300 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 6:
		members[loginedIndex].tiket -= 300;
		break;
	
	//pada case 7 ini, karena user memilih option nomer 7 maka jumlah tiket yang ada pada akun akan dikurang dengan 350 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 7:
		members[loginedIndex].tiket -= 350;
		break;
	
	//pada case 8 ini, karena user memilih option nomer 8 maka jumlah tiket yang ada pada akun akan dikurang dengan 400 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 8:
		members[loginedIndex].tiket -= 400;
		break;
	
	//pada case 9 ini, karena user memilih option nomer 9 maka jumlah tiket yang ada pada akun akan dikurang dengan 450 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 9:
		members[loginedIndex].tiket -= 450;
		break;
	
	//pada case 10 ini, karena user memilih option nomer 10 maka jumlah tiket yang ada pada akun akan dikurang dengan 500 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 10:
		members[loginedIndex].tiket -= 500;
		break;
	
	//pada case 0 ini, karena user memilih option nomer 0 maka program akan kembali ke menu member 
	case 0:
		system("cls");
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
		goto mengulang; //akan mengulang ke fungsi tiket
	}

	else if ((kondisi == 'm' || kondisi == 'M'))
	{
		menuMember(); //program akan kembali ke fungsi menuMember 
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
