//Include Library
#include<stdio.h>

//Masuk ke fungsi
void main(){
    float btc,usdt,idrt,eth;
    int menu;
    menu:
    printf("----- KONVERSI UANG CRIPTO -----\n");
    printf("1. IDRT KE BTC\n");
    printf("2. IDRT KE ETH\n");
    printf("3. IDRT KE USDT\n");
    printf("4. Keluar\n");
    printf("Masukan Pilihan anda di sini: ");
    scanf("%i",&menu);
//menu switch case untuk membuat pilihan
    switch(menu){
        case 1:
        printf("----------\n\n");
        printf("IDR KE BTC\n");
        printf("\n----------\n\n");
        printf("IDRT:Rp. ");
        scanf("%f",&idrt);
        //mata uang sebenarnya di bagi mata uang crypto
        btc=idrt/547974483;


        printf("BTC = %.6f \n\n ",btc);
        goto menu;

    case 2:
        printf("----------\n\n");
        printf("IDR KE ETH\n");
        printf("\n----------\n\n");
        printf("IDRT:Rp. ");
        scanf("%f",&idrt);
        eth=idrt/37897476;

        printf("ETH = %.6f \n\n ",eth);
        goto menu;

    case 3:
        printf("----------\n\n");
        printf("IDR KE USDT\n");
        printf("\n----------\n\n");
        printf("IDRT:Rp. ");
        scanf("%f",&idrt);
        usdt=idrt/14.342;

        printf("USDT = %.6f \n\n ",usdt);
        goto menu;// Perintah untuk kembali ke menu

    case 4:
        printf("----------\n\n");
        printf("TERIMA KASIH <3 \n");
        break;
        //Kasus dimana user salah menginput kode
        default: ("Kode Salah\n");
        goto menu;
    };
}
