#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void tambahData();
void lihatData();
void shortData();
void cariData();

struct warga
{
	char nik[100], nikcopy[100], nama[100], tgl_lahir[100], no_hp[100], email[100];
	int flag;
};

struct warga node[100];
struct warga temp;
int size = sizeof(node)/sizeof(node[0]);

int jmlhData = 0;

void tambahData(){
	printf("Menu Tambah Data Warga\n");
	printf("=======================\n");

	printf("NIK Warga 		: ");
	scanf(" %[^\n]s", node[jmlhData].nik);
	for (int i = 0; i < jmlhData; i++)
	{
		if(strcmp(node[i].nikcopy, node[jmlhData].nik) == 0)
		{
			printf("NIK Sudah Tersedia\n\n");
			getch();
			tambahData();
		}
	}

	printf("Nama Warga 		: ");
	scanf(" %[^\n]s", &node[jmlhData].nama);

	printf("Tanggal Lahir 		: ");
	scanf(" %[^\n]s", &node[jmlhData].tgl_lahir);

	printf("No HP			: ");
	scanf(" %[^\n]s", &node[jmlhData].no_hp);

	printf("Email	 		: ");
	scanf(" %[^\n]s", &node[jmlhData].email);

	strcpy(node[jmlhData].nikcopy, node[jmlhData].nik);
	node[jmlhData].flag = 1;
	jmlhData++;
	printf("\nTambah Data Berhasil\n");
	getch();
	system("cls");
	main();
}


void lihatData(){
	int number = 1;
	printf("Menu Lihat Data Warga\n");
	printf("======================\n");

	if(jmlhData == 0)
	{
		printf("\nBelum Ada Data, Silahkan Mengisi Data Terlebih Dahulu");
		getch();
		system("cls");
		main();
	}
	else
	{
		printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
		for(int i = 0; i < size; i++)
		{
			if(node[i].flag == 1){
				printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", number, node[i].nikcopy, node[i].nama, node[i].email, node[i].no_hp, node[i].tgl_lahir);
				++number;
				printf("\n");
			}
		}
		printf("\n Tekan enter untuk kembali ke menu..");
		getch();
		system("cls");
		main();
	}
}

void cariData(){
	char nik[20];
	int c = 0;

	printf("Menu Cari Data Warga\n");
	printf("======================\n");
	printf("Masukan NIK yang dicari : ");
	scanf(" %[^\n]s", nik);

	for(int i=0; i<size;i++){
		if(strcmp( node[i].nik, nik )  == 0){
			printf("Data penduduk ditemukan !\n\n");
			printf("Informasi Data dengan NIK %s \n", nik);
			printf("=============================\n");
			printf("NIK\t\t\t : %s\n", node[i].nik);
			printf("Nama\t\t\t : %s\n", node[i].nama);
			printf("Tanggal Lahir\t\t : %s\n", node[i].tgl_lahir);
			printf("No HP\t\t\t : %s\n", node[i].no_hp);
			printf("Email\t\t\t : %s\n", node[i].email);
			c++;
			break;
		}
	}
	if(c == 0){
		printf("Data penduduk dengan NIK %s tidak ditemukan", nik);
	}

	printf("\nTekan Enter untuk kembali ke Menu Utama..");
	getch();
	system("cls");
	main();
}

int comp(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return atoi(a->nik) > atoi(b->nik) ? 1 : atoi(b->nik) > atoi(a->nik) ? -1 : 0;
}

int comp_d(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return atoi(a->nik) > atoi(b->nik) ? -1 : atoi(b->nik) > atoi(a->nik) ? 1 : 0;
}

int comp_nama_a(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return a->nama[0] > b->nama[0] ? 1 : b->nama[0] > a->nama[0] ? -1 : 0;
}

int comp_nama_d(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return a->nama[0] > b->nama[0] ? -1 : b->nama[0] > a->nama[0] ? 1 : 0;
}

void shortNIK(){
	qsort(node, sizeof node / sizeof *node, sizeof *node, comp);

	int number = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan NIK Ascending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].flag == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", number, node[i].nikcopy, node[i].nama, node[i].email, node[i].no_hp, node[i].tgl_lahir);
			++number;
			printf("\n");
		}
	}

	qsort(node, sizeof node / sizeof *node, sizeof *node, comp_d);

	number = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan NIK Descending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].flag == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", number, node[i].nikcopy, node[i].nama, node[i].email, node[i].no_hp, node[i].tgl_lahir);
			++number;
			printf("\n");
		}
	}
	printf("\nTekan Enter Untuk Kembali ke Menu Utama..");
	getch();
	system("cls");
	main();

}

void shortNama(){
	qsort(node, sizeof node / sizeof *node, sizeof *node, comp_nama_a);

	int number = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan Nama Ascending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].flag == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", number, node[i].nikcopy, node[i].nama, node[i].email, node[i].no_hp, node[i].tgl_lahir);
			++number;
			printf("\n");
		}
	}

	qsort(node, sizeof node / sizeof *node, sizeof *node, comp_nama_d);

	number = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan Nama Descending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].flag == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", number, node[i].nikcopy, node[i].nama, node[i].email, node[i].no_hp, node[i].tgl_lahir);
			++number;
			printf("\n");
		}
	}
	printf("\nTekan Enter Untuk Kembali ke Menu Utama..");
	getch();
	system("cls");
	main();
}

void shortData(){
	int pil;
	printf("Menu Urut Data Warga\n");
	printf("Urutkan Data Berdasarkan : \n");
	printf("1. Nik\n");
	printf("2. Nama\n");
	printf("Masukan Pilihan : ");
	scanf(" %d", &pil);
	switch(pil){
		case 1:
			shortNIK();
			system("cls");
			break;
		case 2:
			system("cls");
			shortNama();
			break;
		default:
			printf("Pilihan tidak ada !\n");
			printf("Tekan Enter untuk kembali ke Menu Utama");
			getch();
			system("cls");
			main();
			break;
	}
}

void main(){
	int menu;

	printf("Sistem Informasi Kependudukan Desa Konoha\n");
	printf("=========================================");
	printf("\n1. Tambah Data Penduduk");
	printf("\n2. Lihat Data Penduduk");
	printf("\n3. Urutkan Data");
	printf("\n4. Cari Data");
	printf("\n5. Exit");
	printf("\nMasukan Pilihan : ");
	scanf("%d", &menu);

	switch(menu){
		case 1:
			system("cls");
			tambahData();
			break;
		case 2:
			system("cls");
			lihatData();
			break;
		case 3:
			system("cls");
			shortData();
			break;
		case 4:
			system("cls");
			cariData();
			break;
		case 5:
			printf("Menutup Program...");
			exit(0);
		default:
			printf("Pilihan tidak ada !\n");
			printf("Tekan Enter untuk kembali ke Menu Utama");
			getch();
			system("cls");
			main();
			break;
	}
}
