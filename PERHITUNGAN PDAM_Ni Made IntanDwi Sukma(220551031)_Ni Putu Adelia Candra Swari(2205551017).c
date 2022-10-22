#include <stdio.h>//Supaya bisa menggunakan fungsi exit
#include<stdlib.h>
#define BIAYA_ADM 2500.00 //Saya pakai define supaya mudah dalam perhitungan total nanti
#define BPM_R 9000.00 // biaya Pemeliharaan meter untuk rumah tangga
#define BPM_U 15000.00 //biaya Pemeliharaan meter untuk usaha

int pilihan;
float pemakaian_lalu;
float pemakaian_saat_ini;
float besar_pemakaian;
float biaya_pemakaian;
int tanggal;
float denda;
float total;

//FUNGSI PEMAKAIAN
float besarpemakaian (float pemakaian_saat_ini, float pemakaian_lalu){
    float besar_pemakaian;
    besar_pemakaian = pemakaian_saat_ini - pemakaian_lalu;
    return besar_pemakaian;
}

//FUNGSI BIAYA PEMAKAIAN
float biayapemakaianD11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*1780.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*2060.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*5880.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*2060.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*2340.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*5940.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*2340.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*2620.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6000.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*2620.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*2900.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6060.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD31 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*2900.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*3180.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6120.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD32 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*3180.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*3460.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6180.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD41 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*3460.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*3740.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6240.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD42 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*3740.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*4020.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*6300.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6340.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9200.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*9600.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6420.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9350.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*9650.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6940.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9500.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*9800.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6570.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9650.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*9950.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD33 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6640.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9800.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10100.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD34 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6720.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9950.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10250.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD43 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6790.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10100.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10400.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD44 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6870.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10250.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10550.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD51 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*6940.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10400.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10700.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD52 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7020.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10550.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10850.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD53 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7090.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10700.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11000.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD54 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7170.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10850.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11150.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD61 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7240.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11000.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11300.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD62 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7320.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11150.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11450.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD63 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7390.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11350.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11750.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD64 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*7470.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11750.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*12150.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*9200.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*9850.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*10950.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*9500.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10150.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11250.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*9800.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10450.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11550.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*10100.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*10750.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*11850.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*10400.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11050.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*12150.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*10700.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11350.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*12550.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*11000.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11650.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*13150.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*11300.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*11950.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*13950.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE31 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*11600.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*12250.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*14750.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE32 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*11900.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*12550.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*15050.00;
    }else {
        biaya_pemakaian=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    return biaya_pemakaian;
}
float biayapemakaianE33 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*12200.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*12850.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*15850.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE34 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*12500.00;
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*13150.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*16650.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*12950.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*17450.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*13400.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*17900.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*13850.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*18850.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*14300.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*20300.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*14750.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*20750.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*15200.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*21200.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*15650.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*21650.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*16100.00;
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*22100.00;
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}

//FUNGSI TOTAL TAGIHAN
float totaltagihanR ( float biaya_pemakaian, float denda){
    float total;
    total = biaya_pemakaian + BPM_R + BIAYA_ADM + denda;
    return total;
}
float totaltagihanU ( float biaya_pemakaian, float denda){
    float total;
    total = biaya_pemakaian + BPM_U + BIAYA_ADM + denda;
    return total;
}
//FUNGSI VALIDASI

int validasimain (){
    int valid = 0;
    char punten[100];
    while (valid != 1){
        gets(punten);
        for(int a=0; a<100; a++){
            if(isalpha(punten[a])){
                printf("\nInput tidak valid...\nSilahkan masukkan ulang : ");
                valid = 0;
                break;
                }
    else if(isdigit(punten[a])){
        valid = 1;
    }else{
        break;
    }
    }
    }
    int cek = atoi(punten);
    return cek ;
}

int validasiPilihan (){
    int valid = 0;
    char punten[100];
    while (valid != 1){
        gets(punten);
        for(int a=0; a<100; a++){
            if(isalpha(punten[a])){
                printf("\nInput tidak valid...\nSilahkan masukkan ulang : ");
                valid = 0;
                break;
                }
    else if(isdigit(punten[a])){
        valid = 1;
    }else{
        break;
    }
    }
    }
    int cek = atoi(punten);
    return cek ;
}

float validasiBil (){
    int valid = 0;
    char punten[100];
    while (valid != 1){
        gets(punten);
        for(int a=0; a<100; a++){
            if(isalpha(punten[a])){
                printf("\nInput tidak valid...\nSilahkan masukkan ulang : ");
                valid = 0;
                break;
                }
    else if(isdigit(punten[a])){
        valid = 1;
    }else{
        break;
    }
    }
    }
    int cek = atoi(punten);
    return cek ;
}

//MENU INSTRUKSI PELANGGAN
void menu(){
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM PERHITUNGAN TAGIHAN PENGGUNAAN     |\n");
    printf("\t\t\t\t|                  AIR MINUM PDAM                 |\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("---------IKUTI LANGKAH BERIKUT AGAR PENGGUNA DAPAT MENGETAHUI TAGIHAN DENGAN BENAR!---------\n");
    printf("\t1.Pengguna dapat memilih kelompok golongan Rumah Tangga atau Usaha \n");
    printf("\t2.Pada pilihan selanjutnya, pengguna bisa memilih kembali kelompok golongan :\n");
    printf("\t\tRumah tangga: Subsidi atau Tanpa Subsidi;\n");
    printf("\t\tUsaha: Niaga atau Industri;\n");
    printf("\t3.Pada pilihan selanjutnya, pengguna memilih kembali kelompok golongan\n");
    printf("\t4.Hingga tampil menu pilihan golongan, pengguna dapat memilih kelompok golongan\n");
    printf("\t\t!Pilihlah kelompok golongan yang sesuai!\n");
    printf("\t5.Baru kemudian pengguna memasukkan data yang sudah di intruksikan!\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("SETIAP PENGGUNA DIKENAKAN BIAYA ADMIN : Rp. 2500\n");
    printf("SETIAP PENGGUNA GOLONGAN RUMAH TANGGA DIKENAKAN BIAYA BPM : Rp. 9000\n");
    printf("SETIAP PENGGUNA GOLONGAN USAHA DIKENAKAN BIAYA BPM : Rp. 15000\n");
    printf("ADAPUN SANKSI APABILA TELAH MELEWATI JATUH TEMPO (20 HARI):\n");
    printf("\tA. besar_pemakaian>100) =>> denda = 20000; \n");
    printf("\tB.10<besar_pemakaian<=100) =>> denda = 10000; \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("\nMasukkan apapun untuk ke menu selanjutnya! : ");
    getch();
    system("cls");
}

//MENU KELOMPOK GOLONGAN PELANGGAN
int main(){
    menu();
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |    \n");
    printf("\t\t\t\t|                   AIR PDAM                      |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Golongan Pengguna :\n\n");
    printf("\t1.Rumah Tangga\n");
    printf("\t2.Usaha\n");
    printf("\t3.Keluar\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda\n(1 untuk Rumah Tangga, 2 untuk Usaha) : ");
    pilihan = validasiPilihan();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    rumahtangga();
	    break;
	    case 2:
	    usaha();
	    break;
	    default:
        printf("PROGRAM TELAH BERHENTI\n\n");
	    break;
	 }
}


//MENU KELOMPOK RUMAH TANGGA
int rumahtangga(){
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |\n");
    printf("\t\t\t\t|                    AIR PDAM                     |\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              KELOMPOK RUMAH TANGGA              |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Rumah Tangga :\n\n");
    printf("\t1.Bersubsidi\n");
    printf("\t2.Tanpa Bersubsidi\n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda : ");
    pilihan = validasimain();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    bersubsidi();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
        main();
	    break;
	 }
}

//MENU KELOMPOK PELANGGAN BERSUBSIDI
int bersubsidi(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                    AIR PDAM                       |\n");
    printf("\t\t\t\t|---------------------------------------------------|\n");
    printf("\t\t\t\t|       KELOMPOK RUMAH TANGGA BERSUBSIDI            |\n");
    printf("\t\t\t\t|===================================================\n\n");
    printf("Pilihan Golongan Pengguna Rumah Tangga Bersubsidi:\n\n");
    printf("\tA.Rumah Tangga A1\n");
    printf("\t\t1.D1 - 1 \n");
    printf("\t\t[Lebar Jalan :0-3,99 m||daya listrik 450 VA] \n");
    printf("\t\t2.D1 - 2\n");
    printf("\t\t[Lebar Jalan :0-3,99 m||daya listrik 900 VA] \n");
    printf("\tB.Rumah Tangga A2\n");
    printf("\t\t3.D2 - 1\n");
    printf("\t\t[Lebar Jalan :4-6,99 m||daya listrik 450 VA] \n");
    printf("\t\t4.D2 - 2\n");
    printf("\t\t[Lebar Jalan :4-6,99 m||daya listrik 900 VA] \n");
    printf("\tC.Rumah Tangga A3\n");
    printf("\t\t5.D3 - 1\n");
    printf("\t\t[Lebar Jalan 7-10 m||daya listrik 450 VA] \n");
    printf("\t\t6.D3 - 2\n");
    printf("\t\t[Lebar Jalan 7-10 m||daya listrik 900 VA] \n");
    printf("\tD.Rumah Tangga A4\n");
    printf("\t\t7.D4 - 1\n");
    printf("\t\t[Lebar Jalan >10 m||daya listrik 450 VA] \n");
    printf("\t\t8.D4 - 2\n");
    printf("\t\t[Lebar Jalan >10 m||daya listrik 900 VA] \n");
    printf("\t9.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan golongan anda:  ");
    pilihan = validasiPilihan();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    D11();
	    break;
	    case 2:
	    D12();
	    break;
	    case 3:
	    D21();
	    break;
	    case 4:
	    D22();
	    break;
	    case 5:
	    D31();
	    break;
	    case 6:
	    D32();
	    break;
	    case 7:
	    D41();
	    break;
	    case 8:
	    D42();
	    default:
        rumahtangga();
	    break;
	 }
}

// RUMAH TANGGA D1 - 1
int D11(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD11 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D11();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D1 - 2
int D12(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD12 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D12();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D2 - 1
int D21(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-1---------------------------  \n");
    printf("===========================================================\n\n");
 printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD21 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D21();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D2 - 2
int D22(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-2---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD22 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D22();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}
// RUMAH TANGGA D3 - 1
int D31(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                   \n");
    printf("----------------------------D3-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD31 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D31();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D3- 2
int D32(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-2---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp.%.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD32 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("======================================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("----------------------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D32();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D4 - 1
int D41(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-1---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD41 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D41();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}


// RUMAH TANGGA D4 - 2
int D42(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-2---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD42 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D42();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}


//MENU KELOMPOK PELANGGAN TANPA BERSUBSIDI
int tanpabersubsidi(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                    AIR PDAM                       |\n");
    printf("\t\t\t\t|---------------------------------------------------|\n");
    printf("\t\t\t\t|     KELOMPOK RUMAH TANGGA TANPA BERSUBSIDI        |\n");
    printf("\t\t\t\t|===================================================\n\n");
    printf("Pilihan Golongan Pengguna Rumah Tangga Tanpa Bersubsidi:\n\n");
    printf("\tA.Rumah Tangga A1\n");
    printf("\t\t1.D1 - 3 \n");
    printf("\t\t[Lebar Jalan :0 - 3,99 m||daya listrik 1.300 VA VA] \n");
    printf("\t\t2.D1 - 4\n");
    printf("\t\t[Lebar Jalan :0 - 3,99 m||daya listrik >1.300 VA VA] \n");
    printf("\tB.Rumah Tangga A2\n");
    printf("\t\t3.D2 - 3\n");
    printf("\t\t[Lebar Jalan :4 - 6,99 m||daya listrik 1.300 VA] \n");
    printf("\t\t4.D2 - 4\n");
    printf("\t\t[Lebar Jalan :4 - 6,99 m||daya listrik >1.300 VA] \n");
    printf("\tC.Rumah Tangga A3\n");
    printf("\t\t5.D3 - 3\n");
    printf("\t\t[Lebar Jalan 7 - 10 m||daya listrik 1.300 VA] \n");
    printf("\t\t6.D3 - 4\n");
    printf("\t\t[Lebar Jalan 7 - 10 m||daya listrik >1.300 VA] \n");
    printf("\tD.Rumah Tangga A4\n");
    printf("\t\t7.D4 - 3\n");
    printf("\t\t[Lebar Jalan >10 m||daya listrik 1.300 VA] \n");
    printf("\t\t8.D4 - 4\n");
    printf("\t\t[Lebar Jalan >10 m||daya listrik >1.300 VA] \n");
    printf("\tE.Rumah Tangga b [tempat tinggal sekaligus tempat usaha]\n");
    printf("\t\t9.D5 - 1\n");
    printf("\t\t[daya listrik 450 VA] \n");
    printf("\t\t10.D5 - 2\n");
    printf("\t\t[daya listrik 900 VA] \n");
    printf("\t\t12.D5 - 3\n");
    printf("\t\t[daya listrik 1.300 VA] \n");
    printf("\t\t12.D5 - 4\n");
    printf("\t\t[daya listrik >1.300 VA] \n");
    printf("\t13.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan golongan anda:  ");

    pilihan = validasiPilihan();
    printf("\n");
    system("cls");


    switch (pilihan){
	    case 1:
	    D13();
	    break;
	    case 2:
	    D14();
	    break;
	    case 3:
	    D23();
	    break;
	    case 4:
	    D24();
	    break;
	    case 5:
	    D33();
	    break;
	    case 6:
	    D34();
	    break;
	    case 7:
	    D43();
	    break;
	    case 8:
	    D44();
	    break;
        case 9:
	    D51();
	    break;
	    case 10:
	    D52();
	    break;
	    case 11:
	    D53();
	    break;
	    case 12:
	    D54();
	    break;
	    default:
        rumahtangga();
	    break;
	 }
}

// RUMAH TANGGA D1 - 3
int D13(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-3---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD13 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D13();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}
// RUMAH TANGGA D1 - 4
int D14(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD14 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D14();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D2 - 3
int D23(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-3---------------------------  \n");
    printf("===========================================================\n\n");
 printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD23 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D23();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}


// RUMAH TANGGA D2 - 4
int D24(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD24 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D24();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}


// RUMAH TANGGA D3 - 3
int D33(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-3---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD33 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D33();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D3 - 4
int D34(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-4---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD34 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D34();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}


// RUMAH TANGGA D4- 3
int D43(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD43 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D43();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D4 - 4
int D44(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-3---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD44 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D44();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D5 - 1
int D51(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-1---------------------------  \n");
    printf("===========================================================\n\n");
 printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD51 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D51();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D5 - 2
int D52(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-2---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD52 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D52();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D5 - 3
int D53(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD53 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D53();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

// RUMAH TANGGA D5 - 4
int D54(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-4---------------------------  \n");
    printf("===========================================================\n\n");
     printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianD54 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_R);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanR (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_R,BIAYA_ADM, denda, biaya_pemakaian+BPM_R+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    D54();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    main();
	    break;
	 }

}

//MENU KELOMPOK USAHA
int usaha(){
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |\n");
    printf("\t\t\t\t|                    AIR PDAM                     |\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|                 KELOMPOK USAHA                  |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Usaha :\n\n");
    printf("\t1.Niaga\n");
    printf("\t2.Industri\n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda : ");
    pilihan = validasimain();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    niaga();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
        main();
	    break;
	 }
}


//MENU GOLONGAN PELANGGAN NIAGA
int niaga(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                    AIR PDAM                       |\n");
    printf("\t\t\t\t|---------------------------------------------------|\n");
    printf("\t\t\t\t|              KELOMPOK USAHA NIAGA                 |\n");
    printf("\t\t\t\t|===================================================|\n\n");
    printf("Pilihan Golongan Pengguna Usaha Niaga:\n\n");
    printf("\tA.Niaga Kecil A1\n");
    printf("\t\t1.E1 - 1 \n");
    printf("\t\t[Lebar Jalan :0 - 6,99 m||daya listrik 450 VA] \n");
    printf("\t\t2.E1 - 2 \n");
    printf("\t\t[Lebar Jalan :0 - 6,99 m||daya listrik 900 VA] \n");
    printf("\t\t3.E1 - 3\n");
    printf("\t\t[Lebar Jalan :0 - 6,99 m||daya listrik 1300 VA] \n");
    printf("\t\t4.E1 - 4\n");
    printf("\t\t[Lebar Jalan :0 - 6,99 m||daya listrik >1300 VA] \n");
    printf("\tB.Niaga Sedang\n");
    printf("\t\t5.E2 - 1\n");
    printf("\t\t[Lebar Jalan :7 - 10 m||daya listrik 450 VA] \n");
    printf("\t\t6.E2 - 2\n");
    printf("\t\t[Lebar Jalan :7 - 10 m||daya listrik 900 VA] \n");
    printf("\t\t7.E2 - 3\n");
    printf("\t\t[Lebar Jalan :7 - 10 m||daya listrik 1300 VA] \n");
    printf("\t\t8.E2 - 4\n");
    printf("\t\t[Lebar Jalan :7 - 10 m||daya listrik >1300 VA] \n");
    printf("\tC.Niaga Besar\n");
    printf("\t\t9.E3 - 1\n");
    printf("\t\t[Lebar Jalan :>10 m||daya listrik 450 VA] \n");
    printf("\t\t10.E3 - 2\n");
    printf("\t\t[Lebar Jalan :>10 m||daya listrik 900 VA] \n");
    printf("\t\t11.E3 - 3\n");
    printf("\t\t[Lebar Jalan :>10 m||daya listrik 1300 VA] \n");
    printf("\t\t12.E3 - 4\n");
    printf("\t\t[Lebar Jalan :>10 m||daya listrik >1300 VA] \n");
    printf("\t13.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan golongan anda:  ");

    pilihan = validasiPilihan();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    E11();
	    break;
	    case 2:
	    E12();
	    break;
	    case 3:
	    E13();
	    break;
	    case 4:
	    E14();
	    break;
	    case 5:
	    E21();
	    break;
	    case 6:
	    E22();
	    break;
	    case 7:
	    E23();
	    break;
	    case 8:
	    E24();
	    break;
	    case 9:
	    E31();
	    break;
	    case 10:
	    E32();
	    break;
	    case 11:
	    E33();
	    break;
	    case 12:
	    E34();
	    default:
        usaha();
	    break;
	 }
}

// USAHA NIAGA E1 - 1
int E11(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE11 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E11();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E1 - 2
int E12(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE12 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E12();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E1 - 3
int E13(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE13 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E13();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E1 - 4
int E14(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-4---------------------------  \n");
    printf("===========================================================\n\n");
   printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE14 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E14();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E2 - 1
int E21(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-1---------------------------  \n");
    printf("===========================================================\n\n");
   printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE21 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E21();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E2 - 2
int E22(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE22 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E22();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E2- 3
int E23(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE23 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E23();
	    break;
	    case 2:
	    usaha();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E2 - 4
int E24(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE24 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E24();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E3 - 1
int E31(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE31 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E31();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E3 - 2
int E32(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE32 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E32();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E3 - 3
int E33(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE33 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E33();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA NIAGA E3 - 4
int E34(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianE34 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    E34();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    main();
	    break;
	 }

}


//MENU GOLONGAN PELANGGAN INDUSTRI
int industri(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|       PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN       |\n");
    printf("\t\t\t\t|                      AIR PDAM                     |\n");
    printf("\t\t\t\t|---------------------------------------------------|\n");
    printf("\t\t\t\t|              KELOMPOK USAHA INDUSTRI              |\n");
    printf("\t\t\t\t|===================================================|\n\n");
    printf("Pilihan Golongan Pengguna Usaha Industri:\n\n");
    printf("\tA.Industri\n");
    printf("\t\t 1.F1 - 1\n");
    printf("\t\t[daya listrik 450 VA] \n");
    printf("\t\t 2.F1 - 2\n");
    printf("\t\t[daya listrik 900 VA] \n");
    printf("\t\t 3.F1 - 3\n");
    printf("\t\t[aya listrik 1300 VA] \n");
    printf("\t\t 4.F1 - 4\n");
    printf("\t\t[daya listrik >1300 VA] \n");
    printf("\tB.Industri Besar\n");
    printf("\t\t 5.F2 - 1\n");
    printf("\t\t[daya listrik 450 VA] \n");
    printf("\t\t 6.F2 - 2\n");
    printf("\t\t[daya listrik 900 VA] \n");
    printf("\t\t 7.F2 - 3\n");
    printf("\t\t[daya listrik 1300 VA] \n");
    printf("\t\t 8.F2 - 4\n");
    printf("\t\t[daya listrik >1300 VA] \n");
    printf("\t9.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan golongan anda:  ");

    pilihan = validasiPilihan();
    printf("\n");
    system("cls");


    switch (pilihan){
	    case 1:
	    F11();
	    break;
	    case 2:
	    F12();
	    break;
	    case 3:
	    F13();
	    break;
	    case 4:
	    F14();
	    break;
	    case 5:
	    F21();
	    break;
	    case 6:
	    F22();
	    break;
	    case 7:
	    F23();
	    break;
	    case 8:
	    F24();
	    break;
	    default:
        usaha();
	    break;
	 }
}

// USAHA INDUSTRI F1 - 1
int F11(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF11 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F11();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F1 - 2
int F12(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF12 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F12();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F1 - 3
int F13(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF13 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F13();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F1 - 4
int F14(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF14(besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F14();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F2 - 1
int F21(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf ("Masukan Tanggal Pembayaran: ");
   printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF21 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F21();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F2 - 2
int F22(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-2---------------------------  \n");
    printf("===========================================================\n\n");
   printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF22 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F22();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F2 - 3
int F23(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF23 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F23();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }

}

// USAHA INDUSTRI F2 - 4
int F24(){
    int tanggal;
	float pemakaian_lalu;
	float pemakaian_saat_ini;
	float besar_pemakaian;
	float biaya_pemakaian;
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("\nMasukan Pemakaian Bulan Lalu (M3) : ");
    pemakaian_lalu= validasiBil();
    printf("\nMasukan Pemakaian Bulan Ini (M3) : ");
    pemakaian_saat_ini= validasiBil();
    besar_pemakaian = besarpemakaian (pemakaian_saat_ini, pemakaian_lalu);
    printf("\nBesar Pemakaian adalah : %.2f M3\n",besar_pemakaian);
    printf ("Masukan Tanggal Pembayaran: ");
    tanggal= validasiBil();
    if(tanggal>20 ) {

        if(besar_pemakaian>100) {
        denda = 20000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else if (10<besar_pemakaian<=100){
        denda = 10000.00;
        printf("Denda : Rp %.2f\n",denda);

        }else {
        besar_pemakaian = 0;
        printf("Denda : Rp. %.2f\n",denda);}

    }else if (tanggal<=20 && tanggal>0){
        denda = 0;
        printf("Denda = Rp. %.2f\n");

    }else {
        tanggal=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    biaya_pemakaian = biayapemakaianF24 (besar_pemakaian);
    printf("Biaya Pemakaian adalah : Rp. %.2f\n",biaya_pemakaian);
    printf("Biaya BPM : Rp. %.2f\n",BPM_U);
    printf("Biaya Administrasi : Rp. %.2f\n",BIAYA_ADM);
    printf("======================================================================\n");
    total = totaltagihanU (biaya_pemakaian, denda);
    printf("Total : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f = Rp %.2f\n",biaya_pemakaian,BPM_U,BIAYA_ADM, denda, biaya_pemakaian+BPM_U+BIAYA_ADM+denda);
    printf("Maka, jumlah tagihan anda adalah : %.2f.\n",total);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
	    case 1:
	    F24();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    main();
	    break;
	 }
    return 0;
}
