#include <stdio.h>


void main() {
  int menu, a[3][4], b[3][4], result[3][4];;
    menu:
        printf("Pilihan menu: \n");
        printf("1.Tambah Matrix\n");
        printf("2.Kali Matrix\n");
        printf("3.Keluar\n");
        printf("Masukan pilihan anda di sini:");
        scanf("%i",&menu);
      switch(menu){
          case 1:
        printf("Masukkan Nilai dari Matrix A:\n");
        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("Masukkan A [%d][%d]:",i + 1,j + 1);
            scanf("%d",&a[i][j]);
          }
        }
        printf("\nMasukkan Nilai dari Matrix B:\n");
        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("Masukkan B [%d][%d]:",i + 1,j + 1);
            scanf("%d",&b[i][j]);
          }
        }
          //PENJUMLAHAN MATRIKS
        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            result[i][j] = a[i][j] + b[i][j];
          }
        }

        printf("\nHasil penjumlahan kedua matriks: \n");

        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("%d\t",result[i][j]);
            if(j==1) printf("\n");
         }
        }
        getch();
        system("CLS");
        goto menu;
      case 2:
          printf("Masukkan Nilai dari Matrix A:\n");
        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("Masukkan A [%d][%d]:",i + 1,j + 1);
            scanf("%d",&a[i][j]);
          }
        }
        printf("\nMasukkan Nilai dari Matrix B:\n");
        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("Masukkan B [%d][%d]:",i + 1,j + 1);
            scanf("%d",&b[i][j]);
          }
        }
            for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                result[i][j]=(a[i][0]*b[0][j])+(a[i][1]*b[1][j]);
        }
        }
        printf("\nHasil Perkalian kedua matriks:\n");

        for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            printf("%d\t",result[i][j]);
            if(j==1) printf("\n");
         }
        }
      getch();
      system("CLS");
      goto menu;

      case 3:
      printf("\nTerimakasih\n");
      break;

      default:
        printf("\nKode Salah\n");
        getch();
        system("CLS");
        goto menu;
      }
}
