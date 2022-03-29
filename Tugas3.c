#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char user[10],pass[10];

FILE *fp;
char ch, fileName[254];


void readFile(){
  fp = fopen(fileName, "r");

  //EOF = End Of File
  printf("Isi dari file %s : \n", fileName);
  while((ch = fgetc(fp)) != EOF){
    printf("%c", ch);
  }
  getch();
  fclose(fp);
}

void updateFile(){
  fp = fopen(fileName,"a");
  printf("Masukkan Isi file : ");
  while(1){
    ch = getchar();
    if(ch == -1){
      break;
    }
    fputc(ch,fp);
  }
  fclose(fp);

  printf("File berhasil di ubah\n");
  getch();
}

void deleteFile(){
  system("cls");
  char choice;
  printf("Apakah anda yakin menghapus file? (y/t) : ");
  scanf(" %c", &choice);
  switch(choice){
    case 'y':
      if(remove(fileName) == 0){
        printf("file berhasil dihapus\n");
      } else {
        printf("err: File tidak berhasil dihapus\n");
      }
      getch();
      system("CLS");
      menu_admin();
    break;
    case 't':
      printf("file tidak jadi dihapus..\n");
      getch();
      system("CLS");
      menu1();
    break;
    default: printf("Invalid Input\n"); getch();

  }
  main();
}
void printTxtInDirectory() {
  DIR *folder;
  char nama[100];
  struct dirent *entry;
  char *ext, txtFiles[10][50];
  int files = 0, r = 1, i;
  system("CLS");

  printf("===Menu Satu Lihat, Update, Delete TXT===\n");

  folder = opendir(".");
  ext = strrchr(entry->d_name, '.');
  if (folder == NULL)
  {
    printf("File tidak ditemukan!\n");
    exit(EXIT_FAILURE);
  }

  while ((entry = readdir(folder)))
  {
    files++;
    ext = strrchr(entry->d_name, '.');

    if (ext == NULL) {
            getch();
            printf("\n\n\n");

            menu1();


    }

    if (strcmp(ext, ".txt") == 0)
    {
      strcpy(txtFiles[r], entry->d_name);
      printf("%d. %s\n",
             r,
             entry->d_name);

             strcpy(fileName,entry->d_name);
      r++;
    }

  }



  if (r == 1)
  {
    printf("File dengan ekstensi TXT tidak ditemukan!\n");
    system("pause");
    getch();
  }
  closedir(folder);



}

void menu1(){
  // Read Update Delete File
  int choice;
  fp = fopen(fileName, "r");

  if(fp == NULL){
    printf("File belum ada");
    getch();
    system("CLS");
    menu_admin();
  }
  else {
    do {
      system("cls");
      printf("Menu 1 : Read, Update Delete File\n");
      printf("Current File : %s\n", fileName);
      printf("1. Read File\n");
      printf("2. Update File\n");
      printf("3. Delete File\n");
      printf("4. Return to main menu\n");

      printf("Choice : "); scanf("%d", &choice);

      switch(choice){
        case 1: fclose(fp); readFile(); break;
        case 2: fclose(fp); updateFile(); break;
        case 3: fclose(fp); deleteFile(); break;
        case 4: menu_admin(); break;
        default: printf("Invalid Input\n");
      }
    } while(choice != 4);

    getch();
  }

}
void menu2(){
  // Create New File
  system("CLS");
  printf("Menu 2 : Create New File\n");
  printf("Masukkan nama file : ");
   scanf("%s", &fileName);

  /*
    Fungsi String
    - strcpy = Copy 2 String
    - strcmp = compare (Membandingkan 2 String)
    - strcat = Menggabungkan 2 String
  */

strcat(fileName,".txt");

  fp = fopen(fileName, "w");

  printf("File %s berhasil dibuat\n", fileName);

  fclose(fp);
  getch();
  system("CLS");
  menu_admin();
}

void menu_admin(){
    int menu_admin;
    system("CLS");
    menu_admin:
    printf("====MENU====\n");
    printf("1. Menu Satu (Lihat, Update, Delete TXT)\n");
    printf("2. Menu dua (membuat TXT)\n");
    printf("3. Logout\n");
    printf("4.Exit \n");
    printf("Masukan Pilihan di sini: ");
    scanf("%d",&menu_admin);

    switch(menu_admin){
    case 1:
        printTxtInDirectory();
        getch();
        system("CLS");
    case 2:
        menu2();

    case 3:
        system("CLS");
        login();
    case 4:
        printf("\n\nTerimakasih Telah Menggunakan Program Saya\n\n");
        exit(1);
    }
}
void main(){
    login();
}
void login(){
    int status=0, salah=0;
    while(status<100){
    printf("=====Menu=====\n");
    printf("Masukan Username : ");
    scanf("%s",&user);
    printf("Masukan Password : ");
    scanf("%s",&pass);
    if(strcmp(user,"admin")==0 && strcmp(pass,"123")==0){
        printf("\nAkses diterima. Selamat Datang\n");
        getch();
        system("CLS");
        menu_admin();
    }
    else{
         printf("\nUsername dan Password tidak match\n");
         getch();
         system("CLS");
         salah++;
         if(salah>100){
            exit(1);
         }
        }
        status++;
    }
}

