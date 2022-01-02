//Header yang di gunakan untuk standar input output pada bahasa C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi fungsi-fungsi yang digunakan pada program
void profil();
void loginmember();					//fungsi yang digunakan untuk meminta user menginputkan kode member yang telah terdaftar
void registrasiMember();			//fungsi yang digunakan untuk untuk menyimpan perintah-perintah yang dibutuhkan untuk registrasi member
void loginteller();					//fungsi yang digunakan untuk meminta teller yang terdaftar untuk menginputkan kode teller
void menuTeller();					//fungsi yang digunakan untuk menampilkan pilihan menu teller yang ada
void menuMember();					//fungsi yang digunakan untuk meminta user memilih menu yang ada pada menu member
void menusaldo();					//fungsi yang digunakan untuk menambah saldo sesuai dengan yang ada pada pilihan tambah saldo
void tiket();						//fungsi yang digunakan untuk menukarkan tiket sesuai dengan poin tiket yang tersedia pada akun member
void redeemTiket(int requirement); 	//fungsi yang digunakan untuk mengecek ketersediaan tiket member
void updateDataMember();			//fungsi yang digunakan untuk memperbarui data member

int pilih_menu;						//variabel untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada fungsi menuTeller dan menuMember


//Struct Member untuk menyimpan member nama, pin, kartu, saldo, tiket
typedef struct 
{
	char nama[50];
	int pin;
	int kartu;
	int saldo;
	int tiket;
}Member;

Member loginedMember; //Deklarasi variabel loginedMember pada struct Member

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
	profil(); //pemanggilan fungsi profil
	loginteller(); //Pemanggilan fungsi login teller
	return 0;
}

//=======================================================================//
//*****       Fungsi Untuk Menampilkan Profil Pembuat Program       *****//
//=======================================================================//
// Nama Fungsi    : profil                                               //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan nama dari pembuat program                //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 5-12-2021                                Tgl: -               //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Kelas A                                                               //
//=======================================================================//

void profil()
{
	system("cls");
	printf("=====================================================\n");
	printf("                TUGAS BESAR PEMROGRAMAN              \n");
	printf("     PROGRAM TOP UP SALDO DAN TUKAR TIKET TIMEZONE   \n");
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

//=======================================================================//
//*****                Fungsi Untuk Login Petugas                   *****//
//=======================================================================//
// Nama Fungsi    : loginteller                                          //
// Input Argumen  : int inputpin                                         //
// Output Argumen : Nama Petugas                                         //
// Deskripsi      : Fungsi ini ditujukan untuk menginputkan pin 		 //
//					petugas yang terdaftar              				 //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 5-12-2021                               Tgl: -                //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Kelas A                                                               //
//=======================================================================//

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

	//Percabangan yang akan ditampilkan jika inputpin yang dimasukkan adalah sama dengan pin petugas
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

	//Percabangan yang ditampilkan apabila kode petugas yang diinputkan salah
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

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Teller            *****//
//=======================================================================//
// Nama Fungsi    : menuTeller                                           //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Pilihan Menu yang ada pada Menu Teller   //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 5-12-2021                               Tgl: -                //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Kelas A                                                               //
//=======================================================================//

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

	//pada menu switch case bagian ini ,  lanjutan proses dari pilihan yang di inputkan sebelumnya pada pilihan MENU pada menuTeller
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
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		goto mengulang;
		break;
	}
}

//=======================================================================//
//*****                 Fungsi Untuk Login Member                   *****//
//=======================================================================//
// Nama Fungsi    : loginmember                                          //
// Input Argumen  : int i, int pin                                       //
// Output Argumen : Nama Member, Nomer Kartu, Jumlah Saldo, Jumlah Tiket //
// Deskripsi      : Fungsi ini ditujukan untuk menginputkan kode member  //
//					untuk berlanjut ke menu berikutnya					 //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Menambahkan fungsi file.txt									 //
// Kelas A                                                               //
//=======================================================================//

void loginmember()
{

	int i;		// deklarasi variabel i untuk perulangan mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	int pin;	// deklarasi variabel pin untuk memasukkan kode member 
	
	FILE *regis= fopen("data.txt","a+"); //Membuka file "data.txt" dengan mode "a+"
	mengulang:
	system("cls");

	printf("=====================================================\n");
	printf("              SELAMAT DATANG DI TIMEZONE             \n");
	printf("=====================================================\n");

	//Memasukkan pin
	printf("Masukkan Kode Member   : ");
	scanf("%d", &pin);
	fflush(stdin); //Perintah untuk membersihkan buffer
	
	//Perulangan untuk mengecek apakah pin yang diinputkan terdaftar pada sistem atau tidak
	while(!feof(regis)){
	  Member member;
	  
      fscanf(regis,"%[^#]#%d#%d#%d#%d\n", &member.nama, &member.pin, &member.kartu, &member.saldo, &member.tiket);
      fflush(stdin);
    
      if (member.pin == pin){
      	loginedMember = member;
		// jika pin member ditemukan maka sistem akan menampilkan data yang sesuai dengan pin yang diinputkan
		printf("Nama Member            : %s                          \n", member.nama);
		printf("Nomer Kartu            : %d                          \n", member.kartu);
		printf("Jumlah Saldo           : Rp %d                       \n", member.saldo);
		printf("Jumlah Tiket           : %d                          \n", member.tiket);
		printf("                                                     \n");
		printf("=====================================================\n");
		printf("          Tekan ENTER  untuk melanjutkan....         \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
	    fclose(regis);
		menuMember();

	  }
	  i++;
	};
	
	//Jika pin member yang dimasukkan tidak ditemukan pada akun, sistem akan mengulang kembali ke fungsi loginmember 
	printf("=====================================================\n");
	printf("            Member tersebut belum terdaftar          \n");
	printf("            Tekan ENTER  untuk mengulang...          \n");
	printf("=====================================================\n");

	getchar();
	system("cls");

	loginmember();
	fclose(regis);
}
	
//=======================================================================//
//*****               Fungsi Untuk Registrasi Member                *****//
//=======================================================================//
// Nama Fungsi    : registrasiMember                                     //
// Input Argumen  : int i, Member newMember                              //
// Deskripsi      : Fungsi ini ditujukan untuk menginputkan kode member  //
//					untuk disimpan pada file data.txt yang nantinya      //
//					akan divalidasi saat login           				 //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Menambahkan fungsi file.txt									 //
// Kelas A                                                               //
//=======================================================================//


void registrasiMember()
{

	int i; // deklarasi variabel i untuk perulangan mengecek pin member baru agar tidak sama dengan pin member yang sudah ada
	Member newMember;

	FILE *regis= fopen("data.txt","a+"); //Membuka file "data.txt" dengan mode "a+"

	mengulang:
	system("cls");

	printf("=====================================================\n");
	printf("                REGISTRASI MEMBER BARU      	     \n");
	printf("=====================================================\n");

	printf("Masukkan Kode     : ");
	scanf("%d", &newMember.pin);
	fflush(stdin);
	
	//Perulangan untuk mengecek apakah kode yang diinputkan sudah terdaftar atau belum, jika sudah terdaftar maka sistem akan meminta user untuk mengulang memasukan kode 
	while(!feof(regis)){
	  Member member;
	  
      fscanf(regis,"%[^#]#%d#%d#%d#%d\n", &member.nama, &member.pin, &member.kartu, &member.saldo, &member.tiket);
      fflush(stdin);
    
      if (member.pin == newMember.pin){
      	printf("=====================================================\n");
		printf("          Kode Sudah Digunakan. Coba Lainnya         \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getch();
		goto mengulang;
	  }
	  i++;
	};
	
	//Jika kode yang diinputkan belum terdaftar pada sistem maka sistem akan meminta user untuk menginputkan nama, no. kartu dengan jumlah saldo dan tiket awal adalah 0
    printf("Masukkan Nama     : ");
	scanf("%[^\n]", newMember.nama);
	fflush(stdin);

	printf("Masukkan No Kartu : ");
	scanf("%d", &newMember.kartu);
	fflush(stdin);

	printf("Saldo Anda        : 0\n");
	newMember.saldo = 0;
    
    printf("Tiket Anda        : 0\n");
	newMember.tiket = 0;
			 
	fprintf(regis,"%s#%d#%d#%d#%d\n",newMember.nama, newMember.pin, newMember.kartu, newMember.saldo, newMember.tiket);
    fclose(regis);

	printf("\nMember %s telah didaftarkan\n", newMember.nama); //Pemberitahuan member telah terdaftar pada sistem dan disimpan dalam file data.txt
	printf("=====================================================\n");
	printf("            Member Baru Berhasil Terdaftar           \n");
	printf("          Tekan ENTER  untuk melanjutkan....         \n");
	printf("=====================================================\n");
	getchar();
	system("cls");
	menuTeller();
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Member            *****//
//=======================================================================//
// Nama Fungsi    : menuMember                       	                 //
// Input Argumen  : -                                                    //
// Deskripsi      : Fungsi ini ditujukan untuk Menampilkan Pilihan pada  //
//					Menu Member                                          //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 5-12-2021                               Tgl: -                //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Kelas A                                                               //
//=======================================================================//

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
	printf("Masukkan Pilihan : ");
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
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		menuMember();
		break;
	}
}

//=======================================================================//
//*****       Fungsi Untuk Menambahkan Saldo Pada Akun Member       *****//
//=======================================================================//
// Nama Fungsi    : menusaldo		                                     //
// Input Argumen  : char kondisi, int input                              //
// Output Argumen : Total Saldo Pada Akun Member						 //
// Deskripsi      : Fungsi ini ditujukan untuk menambahkan saldo pada	 //
//					kode member untuk disimpan pada file data.txt        //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Menambahkan fungsi updateDataMember							 //
// Kelas A                                                               //
//=======================================================================//


void menusaldo()
{
	char kondisi; //deklarasi untuk variabel kondisi
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

	printf("\n\nMasukkan Pilihan : ");
	scanf("%d", &input);
	fflush(stdin);
	
	//Percabangan untuk menambahkan saldo yang ada pada akun sesuai dengan pilihan yang diinputkan
	switch (input)
	{
	case 1: //nilai variabel input = 1
		loginedMember.saldo += 50000; 
		updateDataMember();
		break; //Melompat ke baris setelah bagian akhir dari switch

	case 2: //nilai variabel input = 2
		loginedMember.saldo += 100000;
		updateDataMember();
		break; //Melompat ke baris setelah bagian akhir dari switch

	case 3: //nilai variabel input = 3
		loginedMember.saldo += 150000 + 50000;
		updateDataMember();
		break;

	case 4: //nilai variabel input = 4
		loginedMember.saldo += 200000 + 150000;
		updateDataMember();
		break;

	case 5: //nilai variabel input = 5
		loginedMember.saldo += 300000 + 300000;
		updateDataMember();
		break;
	case 0:
		system("cls");
		menuMember();
		break;

	default:
		printf("=====================================================\n");
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		system("cls");
		goto mengulang;
		break;
	}

//	printf("\nTotal Saldo: Rp.%d\n", members[loginedIndex].saldo);
	printf("=====================================================\n");
	printf("                Saldo Berhasil Diisi                 \n");
	printf("          Ingin Isi Saldo Lagi? (tekan 'y')          \n");
	printf("          Kembali ke Menu Utama (tekan 'm')          \n");
	printf("=====================================================\n");
	scanf("\n%c", &kondisi);
	fflush(stdin);

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
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");

		getchar();
		system("cls");
		goto mengulang;
	}
}

//=======================================================================//
//*****            Fungsi Untuk Penukaran Tiket Member              *****//
//=======================================================================//
// Nama Fungsi    : tiket                                                //
// Input Argumen  : char kondisi, int inputtiket                         //
// Deskripsi      : Fungsi ini ditujukan untuk menukarkan tiket yang ada //
//					sesuai dengan jumlah saldo pada akun member			 //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Menampilkan pilihan hadiah penukaran tiket sesuai dengan     //
//			jumlah saldo tiket yang tersedia pada akun member			 //
// Kelas A                                                               //
//=======================================================================//


void tiket()
{
	char kondisi; //deklarasi variabel kondisi
	int inputtiket; //deklarasi variabel inputtiket
	mengulang:

	printf("=====================================================\n");
	printf("                      MENU HADIAH     	     	     \n");
	printf("=====================================================\n");
	printf("Jumlah Tiket   : %d                                  \n\n", loginedMember.tiket);
	
	//Menampilkan pilihan sesuai dengan jumlah tiket yang tersedia
	if (loginedMember.tiket >= 50){ //jika saldo tiket pada akun member lebih besar sama dengan 50 maka muncul pilihan 1
		printf("  1. 50 Tiket  = Pulpen\n");
	}
	if (loginedMember.tiket >= 100){ //jika saldo tiket pada akun member lebih besar sama dengan 100 maka muncul pilihan 2
		printf("  2. 100 Tiket = Buku Tulis\n");
	}
	if (loginedMember.tiket >= 150){ //jika saldo tiket pada akun member lebih besar sama dengan 150 maka muncul pilihan 3
		printf("  3. 150 Tiket = Penggaris\n");
	}
	if (loginedMember.tiket >= 200){
		printf("  4. 200 Tiket = Gantungan Kunci\n");
	}
	if (loginedMember.tiket >= 250){
		printf("  5. 250 Tiket = Penghapus Pensil dan Pensil\n");
	}
	if (loginedMember.tiket >= 300){
		printf("  6. 300 Tiket = Boneka Teddy Bear\n");
	}
	if (loginedMember.tiket >= 350){
		printf("  7. 350 Tiket = Bantal Leher\n");
	}
	if (loginedMember.tiket >= 400){
		printf("  8. 400 Tiket = Karet Rambut\n");
	}
	if (loginedMember.tiket >= 450){
		printf("  9. 450 Tiket = Mobil Remot\n");
	}
	if (loginedMember.tiket >= 500){
		printf(" 10. 500 Tiket = Mini Doll\n");
	}
	printf("  0. Kembali\n\n");

	printf("Masukan Pilihan Hadiah : ");
	scanf("%d", &inputtiket);
	fflush(stdin);
	
	//Percabangan dengan variabel inputtiket
	switch (inputtiket)
	{
	//pada case 1 ini, karena user memilih option nomer 1 maka jumlah tiket yang ada pada akun akan dikurang dengan 50 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 1:
		redeemTiket(50); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 2 ini, karena user memilih option nomer 2 maka jumlah tiket yang ada pada akun akan dikurang dengan 100 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 2:
		redeemTiket(100); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 3 ini, karena user memilih option nomer 3 maka jumlah tiket yang ada pada akun akan dikurang dengan 150 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 3:
		redeemTiket(150); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 4 ini, karena user memilih option nomer 4 maka jumlah tiket yang ada pada akun akan dikurang dengan 200 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 4:
		redeemTiket(200); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 5 ini, karena user memilih option nomer 5 maka jumlah tiket yang ada pada akun akan dikurang dengan 250 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 5:
		redeemTiket(250); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 6 ini, karena user memilih option nomer 6 maka jumlah tiket yang ada pada akun akan dikurang dengan 300 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 6:
		redeemTiket(300); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 7 ini, karena user memilih option nomer 7 maka jumlah tiket yang ada pada akun akan dikurang dengan 350 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 7:
		redeemTiket(350); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 8 ini, karena user memilih option nomer 8 maka jumlah tiket yang ada pada akun akan dikurang dengan 400 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 8:
		redeemTiket(400); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 9 ini, karena user memilih option nomer 9 maka jumlah tiket yang ada pada akun akan dikurang dengan 450 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 9:
		redeemTiket(450); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 10 ini, karena user memilih option nomer 10 maka jumlah tiket yang ada pada akun akan dikurang dengan 500 tiket untuk dapat menukarkan hadiah yang telah ditetapkan
	case 10:
		redeemTiket(500); //Pemanggilan fungsi redeemTiket
		break;

	//pada case 0 ini, karena user memilih option nomer 0 maka program akan kembali ke menu member
	case 0:
		system("cls");
		menuMember(); 
		break;
	}



	printf("Sisa Tiket Anda Sebesar : %d\n", loginedMember.tiket); //Jumlah sisa tiket setelah melakukan penukaran tiket dilakukan
	printf("=====================================================\n");
	printf("           Penukaran Tiket Telah Berhasil            \n");
	printf("         Ingin Tukar Tiket Lagi? (tekan 'y')         \n");
	printf("          Kembali ke Menu Utama (tekan 'm')          \n");
	printf("=====================================================\n");
	scanf("%c", &kondisi);
	fflush(stdin);

	if (kondisi == 'y' || kondisi == 'Y')
	{
		system("cls");
		goto mengulang; //akan mengulang ke fungsi tiket
	}

	else if ((kondisi == 'm' || kondisi == 'M'))
	{
		system("cls");
		menuMember(); //program akan kembali ke fungsi menuMember
	}

	else
	{
		printf("=====================================================\n");
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		system("cls");
		goto mengulang;
	}
}

//=======================================================================//
//*****                 Fungsi Untuk Redeem Tiket                   *****//
//=======================================================================//
// Nama Fungsi    : redeemTiket(int requirement)                         //
// Input Argumen  : -							                         //
// Deskripsi      : Fungsi ini ditujukan untuk melakukan pengecekan      //
//					apabila pilihan yang diinputkan melebihi dari apa    //
//					yang tersedia pada pilihan, maka sistem akan meminta //
//					user memasukan pilihan dengan benar sesuai tiket     //
//					yang tersedia										 //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Menambahkan fungsi updateDataMember setelah melakukan        //
//			penukaran tiket untuk mengubah data yang ada pada file       //
//			data.txt			                                         //
// Kelas A                                                               //
//=======================================================================//
 

void redeemTiket(int requirement){
    if (requirement > loginedMember.tiket){ //Jika requirement yang diinputkan melebihi dari saldo tiket yang ada pada akun member
		printf("=====================================================\n");
		printf("           Pilihan Yang Anda Masukkan Salah          \n");
		printf("           Tekan ENTER  untuk mengulang....          \n");
		printf("=====================================================\n");
		getchar();

		system("cls");
		tiket();
    }else{ //Jika requirement yang diinputkan tidak melebihi dari saldo tiket pada akun member maka requirement yang diinputkan akan dikurangi dengan jumlah tiket yang ada
        loginedMember.tiket -= requirement;
        updateDataMember(); //data yang ada pada data.txt akan diupdate
    }
}

//=======================================================================//
//*****               Fungsi Untuk Update Data Member               *****//
//=======================================================================//
// Nama Fungsi    : updateDataMember                                     //
// Input Argumen  : int i, int size=0			                         //
// Deskripsi      : Fungsi ini ditujukan untuk mengupdate data yang ada  //
//					pada file data member pada data.txt		     	     //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 5-12-2021                               Tgl: 1-01-2022        //
// Benita Carissa Sutrisno Putri - 2105551002                            //
// Maria Christina Hartono - 2105551002									 //
// Revisi : Mengupdate setiap data setelah melakukan penambahan saldo    //
//			atau penukaran tiket			                             //
// Kelas A                                                               //
//=======================================================================//


void updateDataMember() {
	FILE *file= fopen("data.txt", "a+"); // Membuka file "data.txt" dengan mode "a+"
	FILE *fTemp = fopen("copy.txt", "a"); // Membuka file "copy.txt" dengan mode "a"
	int i; //deklarasi variabel i dengan tipe data integer
	int size = 0; //deklarasi variabel size=0 dengan tipe data integer
	Member members[500];//deklarasi variabel member[500] dengan struct Member
	
	//Perulangan untuk mengecek data dalam file data.txt hingga akhir
	while(!feof(file)){
	  Member member;
	  
      fscanf(file,"%[^#]#%d#%d#%d#%d\n",  &member.nama, &member.pin, &member.kartu, &member.saldo, &member.tiket);
      fflush(stdin);
    
      if (member.pin == loginedMember.pin){
	    member = loginedMember;
	  }
	  members[size] = member;
	  size++;
	};
	
	for(i=0; i<size;i++){
		fprintf(fTemp,"%s#%d#%d#%d#%d\n",members[i].nama, members[i].pin, members[i].kartu, members[i].saldo, members[i].tiket);
	}

    fclose(file);	
    fclose(fTemp);
    remove("data.txt");
    rename("copy.txt", "data.txt");
}
