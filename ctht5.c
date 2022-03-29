#include <stdio.h>
#include <string.h>

int jmlData = 0;

struct warga{
    char nik[100],nikcopy[100] ;
    char hp[100],email[100],tgl[100];
    char nama[100];
    int temp;
}node[100];

int size = sizeof(node)/sizeof(node[0]);


int cekNIK(long long int nik){
    int i;
    int n = 1;
    for(i=0;i<jmlData;i++){
        if(node[i].nik == nik){
            n = 0;
        }
    }
    return n;
}

int tambahData(){
    int n = 0;
    while(n == 0){
        system("cls");
        printf("Menu tambah data warga\n");
        printf("======================\n");
        printf("NIK Warga\t\t\t: ");
        scanf(" %[^\n]",node[jmlData].nik);
        n = cekNIK(node[jmlData].nik);
        if(n == 0){
            printf("Nik sudah tersedia\n");
            getch();
        }
    }
    printf("Nama Warga\t\t\t: ");
    scanf(" %[^\n]",&node[jmlData].nama);
    printf("Tanggal Lahir\t\t\t: ");
    scanf(" %[^\n]",&node[jmlData].tgl);
    printf("No Hp\t\t\t\t: ");
    scanf(" %[^\n]",&node[jmlData].hp);
    printf("Email\t\t\t\t: ");
    scanf(" %[^\n]",&node[jmlData].email);
	strcpy(node[jmlData].nikcopy, node[jmlData].nik);
	node[jmlData].temp = 1;
	jmlData++;
	printf("\nTambah Data Berhasil\n");
    getch();
    system("cls");
    main();

}
int lihatData(){
    int i,n;
    n = 0;
    printf("Menu Lihat Data Warga\n");
    printf("===============\n");
    if(jmlData == 0){
		printf("\nBelum Ada Data, Silahkan Mengisi Data Terlebih Dahulu");
		getch();
		system("cls");
		main();
	}
else{
        printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
		for(int i = 0; i < jmlData; i++)
		{
			if(node[i].temp == 1){
				printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", n+1, node[i].nik, node[i].nama, node[i].email, node[i].hp, node[i].tgl);
				++n;
				printf("\n");
			}
		}
		printf("\n Tekan enter untuk kembali ke menu..");
		getch();
		system("cls");
		main();
	}
}



int cariData(){

        char nik [100];
        int posisi = 0;

            printf("Menu Cari Data Warga\n");
            printf("======================\n");
            printf("Masukan NIK yang dicari : ");
            scanf(" %[^\n]s", nik);

            for(int i=0; i<size;i++){
                if(strcmp( node[i].nik, nik )  == 0){
                    printf("\nData penduduk ditemukan !\n\n");
                    printf("Informasi Data dengan NIK %s \n", nik);
                    printf("=============================\n");
                    printf("NIK\t\t\t : %s\n", node[i].nik);
                    printf("Nama\t\t\t : %s\n", node[i].nama);
                    printf("Tanggal Lahir\t\t : %s\n", node[i].tgl);
                    printf("No HP\t\t\t : %s\n", node[i].hp);
                    printf("Email\t\t\t : %s\n", node[i].email);
                    posisi++;
                    break;
                }
            }
            if(posisi == 0){
                printf("\nData penduduk dengan NIK %s tidak ditemukan\n", nik);
            }

            printf("\nTekan Enter untuk kembali ke Menu Utama..");
            getch();
            system("cls");
            main();
}
int angka(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return atoi(a->nik) > atoi(b->nik) ? 1 : atoi(b->nik) > atoi(a->nik) ? -1 : 0;
}

int huruf(const void *va, const void *vb){
        const struct warga *a = va;
        const struct warga *b = vb;
        return a->nama[0] > b->nama[0] ? 1 : b->nama[0] > a->nama[0] ? -1 : 0;
}

void shortNIK(){
	qsort(node, sizeof node / sizeof *node, sizeof *node, angka);

	int n = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan NIK Ascending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].temp == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", n, node[i].nikcopy, node[i].nama, node[i].email, node[i].hp, node[i].tgl);
			++n;
			printf("\n");
		}
	}
	printf("\nTekan Enter Untuk Kembali ke Menu Utama..");
	getch();
	system("cls");
	main();
}

void shortNama(){
	qsort(node, sizeof node / sizeof *node, sizeof *node, huruf);

	int n = 1;
	printf("\n");
	printf("Data diurutkan berdasarkan Nama Ascending\n");
	printf("========================================\n");


	printf("No\t|NIK\t|Nama Warga\t\t|Email\t\t\t|No Handphone\t\t|Tanggal Lahir\n");
	for(int i = 0; i < size; i++)
	{
		if(node[i].temp == 1){
			printf("%d\t|%s\t|%s\t\t|%s\t|%s\t\t|%s", n, node[i].nikcopy, node[i].nama, node[i].email, node[i].hp, node[i].tgl);
			++n;
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
			shortNama();
            system("cls");
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
