#include <stdio.h>//Supaya bisa menggunakan fungsi exit
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define BIAYA_ADM 2500.00 //Saya pakai define supaya mudah dalam perhitungan total nanti
#define BPM_R 9000.00 // biaya Pemeliharaan meter untuk rumah tangga
#define BPM_U 15000.00 //biaya Pemeliharaan meter untuk usaha


//=====================================================================
//  DEKLARASI
void cover ();
void menu();
void rumahtangga();
void subsidi();
void tanpabersubsidi();
void usaha();
void niaga();
void industri();

float tarif[40][3]= {{1780, 2060, 5880},     //D1 - 1
                    {2060, 2340, 5940},      //D1 - 2
                    {2340, 2620, 6000},      //D2 - 1
                    {2620, 2900, 6060},      //D2 - 2
                    {2900, 3180, 6120},      //D3 - 1
                    {3180, 3460, 6180},      //D3 - 2
                    {3460, 3740, 6240},      //D4 - 1
                    {3740, 4020, 6300},      //D4 - 2
                    {6340, 9200, 9600},      //D1 - 3
                    {6420, 9350, 9650},      //D1 - 4
                    {6490, 9500, 9800},      //D2 - 3
                    {6570, 9650, 9950},      //D2 - 4
                    {6640, 9800, 10100},     //D3 - 3
                    {6720, 9950, 10250},     //D3 - 4
                    {6790, 10100, 10400},    //D4 - 3
                    {6870, 10250, 10550},    //D4 - 4
                    {6940, 10400, 10700},    //D5 - 1
                    {7020, 10550, 10850},    //D5 - 2
                    {7090, 10700, 11000},    //D5 - 3
                    {7170, 10850, 11150},    //D5 - 4
                    {9200, 9850, 10950},     //E1 - 1
                    {9500, 10150, 11250},    //E1 - 2
                    {9800, 10450, 11550},    //E1 - 3
                    {10100, 10750, 11850},   //E1 - 4
                    {10400, 11050, 12150},   //E2 - 1
                    {10700, 11350, 12550},   //E2 - 2
                    {11000, 11650, 13150},   //E2 - 3
                    {11300, 11950, 13950},   //E2 - 4
                    {11600, 12250, 14750},   //E3 - 1
                    {11900, 12550, 15050},   //E3 - 2
                    {12200, 12850, 15850},   //E3 - 3
                    {12500, 13150, 16650},   //E3 - 4
                    {12950, 17450},          //F1 - 1
                    {13400, 17900},          //F1 - 2
                    {13850, 18850},          //F1 - 3
                    {14300, 20300},          //F1 - 4
                    {14750, 20750},          //F2 - 1
                    {15200, 21200},          //F2 - 2
                    {15650, 21650},          //F2 - 3
                    {16100, 22100}};         //F2 - 4

float denda[2] = {20000, 10000};//denda pemakaian>100 = 20000
                               //10<denda pemakaian<=100 = 10000


//=====================================================================
//FUNGSI PEMAKAIAN
float besarpemakaian (float pemakaian_saat_ini, float pemakaian_lalu){
    float besar_pemakaian;
    besar_pemakaian = pemakaian_saat_ini - pemakaian_lalu;
    return besar_pemakaian;
}

//=====================================================================
//FUNGSI BIAYA PEMAKAIAN
float biayapemakaianD11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[0][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[0][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[0][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[1][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[1][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[1][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[2][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[2][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[2][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[3][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[3][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[3][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD31 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[4][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[4][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[4][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD32 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[5][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[5][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[5][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD41 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[6][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[6][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[6][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD42 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[7][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[7][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[7][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[8][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[8][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[8][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[9][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[9][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[9][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[10][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[10][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[10][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[11][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[11][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[11][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD33 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[12][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[12][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[12][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD34 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[13][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[13][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[13][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD43 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[14][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[14][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[14][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD44 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[15][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[15][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[15][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD51 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[16][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[16][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[16][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD52 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[17][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[17][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[17][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD53 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[18][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[18][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[18][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianD54 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[19][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[19][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[19][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}

float biayapemakaianE11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[20][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[20][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[20][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[21][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[21][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[21][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[22][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[22][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[22][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[23][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[23][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[23][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[24][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[24][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[24][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[25][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[25][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[25][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[26][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[26][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[26][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[27][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[27][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[27][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE31 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[28][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[28][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[28][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE32 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[29][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[29][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[29][2];
    }else {
        biaya_pemakaian=0;
        printf ("Pembayaran tidak dikenakan denda");
        }
    return biaya_pemakaian;
}
float biayapemakaianE33 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[30][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[30][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[30][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianE34 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=10 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[31][0];
    }else if (besar_pemakaian<=20 && besar_pemakaian>10){
         biaya_pemakaian = besar_pemakaian*tarif[31][1];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[31][2];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF11 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[32][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[32][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF12 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[33][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[33][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF13 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[34][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[34][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF14 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[35][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[35][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF21 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[36][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[36][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}

float biayapemakaianF22 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[37][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[37][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}

float biayapemakaianF23 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[38][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[38][1];
    }else {
        biaya_pemakaian=0;
    }
    return biaya_pemakaian;
}
float biayapemakaianF24 (float besar_pemakaian){
    float biaya_pemakaian;
    if(besar_pemakaian<=20 && besar_pemakaian>=0) {
        biaya_pemakaian = besar_pemakaian*tarif[39][0];
    }else if (besar_pemakaian>20){
         biaya_pemakaian = besar_pemakaian*tarif[39][1];
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

//=====================================================================
//FUNGSI VALIDASI
//Cek Pilihan Menu
int validasimenu() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=50){ // PEMBATAS PADA ASCII DIMANA 49-50 BERNILAI "1-2"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasimenu();
        }
    }
}


int validasimenu2() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=51){ // PEMBATAS PADA ASCII DIMANA 49-54 BERNILAI "1-3"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasimenu2();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasimenu2();
        }
    }
}

//Cek Pilihan
int validasipil() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-57 BERNILAI "1-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Anda : ");
        validasipil();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=9){
        return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Anda : ");
            validasipil();
        }
    }
}

//Cek Pilihan1
int validasipil1() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=61){ // PEMBATAS PADA ASCII DIMANA 49-61 BERNILAI "1-13"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Pilihan Anda : ");
        validasipil1();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=13){
        return val;
        }else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Pilihan Anda : ");
            validasipil1();
        }
    }
}

//Cek Bilangan
float validasiBil(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    gets(angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }else{
        salah += 1;
    }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
        }else{
            salah += 1;
        }
    }

    if(salah>0 || titik>1){
        printf("\nHARAP Masukkan BILANGAN YANG SESUAI\n");
        printf("Silahkan masukkan ulang : ");
        validasiBil();
    }else{
        val = atof(angka);
        return val;
    }
}

//Cek tanggal
int validasitanggal(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    gets(angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
        printf("Silahkan Masukkan Ulang Tanggal : ");
        validasitanggal()                       ;
    }else{
        val = atoi(angka);
        if(val>=1 && val<=31){
            return val;
        } else{
            printf("MAAF INPUTAN ANDA TIDAK SESUAI ^.^\n");
            printf("Silahkan Masukkan Ulang Tanggal : ");
            validasitanggal()                       ;
        }
    }
}

//=====================================================================
//MAIN
int main(){
    system("COLOR F5");
    menu();
    system("pause");
    return 0;
}

//=====================================================================
//COVER INSTRUKSI PELANGGAN
void cover(){
    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|                 Hi! Halo! Ni Hao!               |\n");
    printf("\t\t\t\t|              ^0^ SELAMAT DATANG ^v^             |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|     PROGRAM PERHITUNGAN TAGIHAN PENGGUNAN       |\n");
    printf("\t\t\t\t|                 AIR MINUM (PDAM)                |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|              PDAM TIRTA HARUMNING               |\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t|=================================================|\n\n");

    printf("---------IKUTI LANGKAH BERIKUT AGAR PENGGUNA DAPAT MENGETAHUI TAGIHAN DENGAN BENAR!---------\n\n");
    printf("\t1.Pengguna dapat memilih kelompok golongan Rumah Tangga atau Usaha \n");
    printf("\t2.Pada pilihan selanjutnya, pengguna bisa memilih kembali kelompok golongan :\n");
    printf("\t\t>> Rumah tangga: Subsidi atau Tanpa Subsidi;\n");
    printf("\t\t>> Usaha: Niaga atau Industri;\n");
    printf("\t3.Pada pilihan selanjutnya, pengguna memilih kembali kelompok golongan\n");
    printf("\t4.Hingga tampil menu pilihan golongan, pengguna dapat memilih kelompok golongan\n");
    printf("\t\t!Pilihlah kelompok golongan yang sesuai!\n");
    printf("\t5.Baru kemudian pengguna memasukkan data yang sudah di intruksikan!\n");
    printf("--------------------------------------------------------------------------------------------\n\n");
    printf("\tSETIAP PENGGUNA DIKENAKAN BIAYA ADMIN : Rp. 2500\n");
    printf("\tSETIAP PENGGUNA GOLONGAN RUMAH TANGGA DIKENAKAN BIAYA BPM : Rp. 9000\n");
    printf("\tSETIAP PENGGUNA GOLONGAN USAHA DIKENAKAN BIAYA BPM : Rp. 15000\n");
    printf(".............................................................................................\n");
    printf("ADAPUN SANKSI APABILA TELAH MELEWATI JATUH TEMPO (20 HARI):\n");
    printf("\tA. biaya pemakaian>100      =>> denda = 20000; \n");
    printf("\tB. 10<biaya pemakaian<=100  =>> denda = 10000; \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("\nMasukkan apapun untuk ke menu selanjutnya! : ");
    getch();
    system("cls");
}

//MENU KELOMPOK GOLONGAN PELANGGAN
int sekalimuncul = 0;
void menu(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |\n");
    printf("\t\t\t\t|                      PDAM                       |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Golongan Pengguna :\n\n");
    printf("\t1.Rumah Tangga\n");
    printf("\t2.Usaha\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda\n(1 untuk Rumah Tangga, 2 untuk Usaha) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    rumahtangga();
	    break;
	    case 2:
	    usaha();
	    break;
	 }
}


//MENU KELOMPOK RUMAH TANGGA
void rumahtangga(){
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |\n");
    printf("\t\t\t\t|                      PDAM                       |\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              KELOMPOK RUMAH TANGGA              |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Rumah Tangga :\n\n");
    printf("\t1.Bersubsidi\n");
    printf("\t2.Tanpa Bersubsidi\n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda : ");
    pilihan = validasimenu2();
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
        menu();
	    break;
	 }
}

//MENU KELOMPOK PELANGGAN BERSUBSIDI
void bersubsidi(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                      PDAM                         |\n");
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
    pilihan = validasipil();
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
void D11(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                      ;
    printf("Masukkan Nama Anda                   :") ;
    gets(nama)                                       ;
    printf(" Masukkan Nomor Rekening Anda        : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk[0]<=20 && struk[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Tanggal input anda salah");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD11 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer,"\t\t\t+========================================================================+\n");
    fprintf(fPointer,"\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer,"\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer,"\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer,"\t\t\t+========================================================================+\n\n");
    fprintf(fPointer,"\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer,"\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer,"\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer,"\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer,"\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer,"\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer,"\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD11 (struk[2]);
    fprintf(fPointer,"\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer,"\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer,"\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer,"\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer,"\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer,"\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer,"\t\t\t=========================================================================\n");
    fprintf(fPointer,"\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer,"\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D11();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D1 - 2
void D12(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD12 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD12 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D12();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D2 - 1
void D21(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD21 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");


    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD21 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D21();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D2 - 2
void D22(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD22 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD22 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D22();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D3 - 1
void D31(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                   \n");
    printf("----------------------------D3-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD31 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD31 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D31();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// RUMAH TANGGA D3- 2
void D32(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD32 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD32 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D32();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D4 - 1
void D41(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD41 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");


    fprintf(fPointer, "t\t\t+========================================================================+\n");
    fprintf(fPointer, "t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD41 (struk[2]);
    fprintf(fPointer, "t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "t\t\t=========================================================================\n");
    fprintf(fPointer, "t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D41();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// RUMAH TANGGA D4 - 2
void D42(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD42 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD42 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D42();
	    break;
	    case 2:
	    bersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


//MENU KELOMPOK PELANGGAN TANPA BERSUBSIDI
void tanpabersubsidi(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                    PDAM                       |\n");
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

    pilihan = validasipil1();
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
void D13(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD13 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD13 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D13();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D1 - 4
void D14(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A1                    \n");
    printf("----------------------------D1-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD14 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD14 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D14();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}
// RUMAH TANGGA D2 - 3
void D23(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD23(struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD23(struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D23();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// RUMAH TANGGA D2 - 4
void D24(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A2                    \n");
    printf("----------------------------D2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD24 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD24 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D24();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// RUMAH TANGGA D3 - 3
void D33(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD33 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

   fprintf(fPointer, "\t\t\t+========================================================================+\n");
   fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
   fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
   fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
   fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
   fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
   fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
   fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
   fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
   fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
   fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
   fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
   struk[4] = biayapemakaianD33 (struk[2]);
   fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
   fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
   fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
   fprintf(fPointer, "\t\t\t.........................................................................\n");
   struk[5] = totaltagihanR (struk[4], struk[3]);
   fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
   fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
   fprintf(fPointer, "\t\t\t=========================================================================\n");
   fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
   fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D33();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D3 - 4
void D34(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A3                    \n");
    printf("----------------------------D3-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD34 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD34 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D34();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}
// RUMAH TANGGA D4- 3
void D43(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD43 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD43 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D43();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}
// RUMAH TANGGA D4 - 4
void D44(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA A4                    \n");
    printf("----------------------------D4-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD44 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD44 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D44();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D5 - 1
void D51(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD51 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD51 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D51();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}
// RUMAH TANGGA D5 - 2
void D52(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD52(struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD52(struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D52();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// RUMAH TANGGA D5 - 3
void D53(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD53 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD53 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D53();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// RUMAH TANGGA D5 - 4
void D54(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK RUMAH TANGGA B                    \n");
    printf("----------------------------D5-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD54 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianD54 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    D54();
	    break;
	    case 2:
	    tanpabersubsidi();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

//MENU KELOMPOK USAHA
void usaha(){
    int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|      PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN      |\n");
    printf("\t\t\t\t|                      PDAM                       |\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|                 KELOMPOK USAHA                  |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Kelompok Usaha :\n\n");
    printf("\t1.Niaga\n");
    printf("\t2.Industri\n");
    printf("\t3.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukkan kelompok golongan anda : ");
    pilihan = validasimenu2();
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
        menu();
	    break;
	 }
}


//MENU GOLONGAN PELANGGAN NIAGA
void niaga(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|     PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN         |\n");
    printf("\t\t\t\t|                      PDAM                         |\n");
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

    pilihan = validasipil1();
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
void E11(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE11 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

   fprintf(fPointer, "\t\t\t+========================================================================+\n");
   fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
   fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
   fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
   fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
   fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
   fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
   fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
   fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
   fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
   fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
   fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE11 (struk[2]);
   fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
   fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
   fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
   fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
   fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
   fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
   fprintf(fPointer, "\t\t\t=========================================================================\n");
   fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
   fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E11();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E1 - 2
void E12(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE12 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE12 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E12();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// USAHA NIAGA E1 - 3
void E13(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE13 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE13 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E13();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E1 - 4
void E14(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA KECIL                    \n");
    printf("----------------------------E1-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE14 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE14 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E14();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E2 - 1
void E21(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE21 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE21 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E21();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E2 - 2
void E22(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE22 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE22 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E22();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E2- 3
void E23(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE23 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE23 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E23;
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}

// USAHA NIAGA E2 - 4
void E24(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA SEDANG                    \n");
    printf("----------------------------E2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE24 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE24 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E24;
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// USAHA NIAGA E3 - 1
void E31(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE31 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE31 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E31();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// USAHA NIAGA E3 - 2
void E32(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE32 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE32 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E32();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// USAHA NIAGA E3 - 3
void E33(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE33 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE33 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E33();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}


// USAHA NIAGA E3 - 4
void E34(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                    KELOMPOK NIAGA BESAR                    \n");
    printf("----------------------------E3-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE34 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");


    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianE34 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    E34();
	    break;
	    case 2:
	    niaga();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }

}




//MENU GOLONGAN PELANGGAN INDUSTRI
void industri(){
    int pilihan;

    printf("\t\t\t\t|===================================================|\n");
    printf("\t\t\t\t|       PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN       |\n");
    printf("\t\t\t\t|                        PDAM                       |\n");
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

    pilihan = validasipil();
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
void F11(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF11 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF11 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F11();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}

// USAHA INDUSTRI F1 - 2
void F12(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF12 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF12 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F12();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}


// USAHA INDUSTRI F1 - 3
void F13(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF13 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF13 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");


    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F13();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}


// USAHA INDUSTRI F1 - 4
void F14(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                     KELOMPOK INDUSTRI                       \n");
    printf("----------------------------F1-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF14 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF14 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F14();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}


// USAHA INDUSTRI F2 - 1
void F21(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-1---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF21 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF21 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");
    getch();

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F21();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}

// USAHA INDUSTRI F2 - 2
void F22(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-2---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF22 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF22 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F22();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}

// USAHA INDUSTRI F2 - 3
void F23(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-3---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] =0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF23 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF23 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F23();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}

// USAHA INDUSTRI F2 - 4
void F24(){
    FILE *fPointer =fopen ("Struk Pembayaran.txt", "w");
    char nama[100];
    int struk1[2];//indeks 0 untuk tanggal
                  //indeks 1 untuk no rekening

    float struk[6];//indeks 0 untuk pemakaian bulan lalu
                   //indeks 1 untuk pemakaian bulan ini
                   //indeks 2 untuk total pemakaian
                   //indeks 3 untuk denda
                   //indeks 4 untuk biaya pemakaian
                   //indeks 5 untuk total biaya
	int pilihan;
    printf("===========================================================\n\n");
    printf("                 KELOMPOK INDUSTRI BESAR                     \n");
    printf("----------------------------F2-4---------------------------  \n");
    printf("===========================================================\n\n");
    printf("Masukkan Tanggal Pembayaran          : ");
    struk1[0]= validasitanggal()                       ;
    printf("Masukkan Nama Anda                   : ");
    gets(nama)                               ;
    printf("Masukkan Nomor Rekening Anda         : ");
    struk1[1]= validasiBil()                          ;
    printf("Masukkan Pemakaian Bulan Lalu (M3)   : ");
    struk[0]= validasiBil();
    printf("Masukkan Pemakaian Bulan Ini (M3)    : ");
    struk[1]= validasiBil();
    struk[2]= besarpemakaian (struk[1], struk[0]);
    printf("Total Pemakaian adalah               : %.2f M3\n",struk[2]);

    if(struk1[0]>20 ) {

        if(struk[2]>100) {
        struk[3] = denda[0];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else if (10<struk[2]<=100){
        struk[3] = denda[1];
        printf("Denda : Rp %.2f\n",struk[3]);

        }else {
        struk[2] = 0;
        printf("Denda : Rp. %.2f\n",struk[3]);}

    }else if (struk1[0]<=20 && struk1[0]>0){
        struk[3] = 0;
        printf("Denda : Rp. %.2f\n");

    }else {
        struk1[0]=0;
        printf ("Pembayaran tidak dikenakan denda");
        }

    system("cls");
    printf("\t\t\t+========================================================================+\n");
    printf("\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    printf("\t\t\t|------------------------------------------------------------------------|\n");
    printf("\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    printf("\t\t\t+========================================================================+\n\n");
    printf("\t\t\t Nama Pelanggan           : %s\n", nama);
    printf("\t\t\t No. REK                  : %d\n", struk1[1]);
    printf("\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    printf("\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    printf("\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    printf("\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    printf("\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF24 (struk[2]);
    printf("\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    printf("\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    printf("\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    printf("\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    printf("\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    printf("\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    printf("\t\t\t=========================================================================\n");
    printf("\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    printf("\t\t\t-------------------------------------------------------------------------\n");
    getch();
    system("cls");

    fprintf(fPointer, "\t\t\t+========================================================================+\n");
    fprintf(fPointer, "\t\t\t|                           PDAM TIRTA HARUMNING                         |\n");
    fprintf(fPointer, "\t\t\t|------------------------------------------------------------------------|\n");
    fprintf(fPointer, "\t\t\t|                             BUKTI PEMBAYARAN                           |\n");
    fprintf(fPointer, "\t\t\t+========================================================================+\n\n");
    fprintf(fPointer, "\t\t\t Nama Pelanggan           : %s\n", nama);
    fprintf(fPointer, "\t\t\t No. REK                  : %d\n", struk1[1]);
    fprintf(fPointer, "\t\t\t Tanggal Pembayaran       : %d\n", struk1[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Lalu     : %.2f\n", struk[0]);
    fprintf(fPointer, "\t\t\t Pemakaian Bulan Ini      : %.2f\n", struk[1]);
    fprintf(fPointer, "\t\t\t Total Pemakaian          : %.2f\n", struk[2]);
    fprintf(fPointer, "\t\t\t Denda                    : %.2f\n", struk[3]);
    struk[4] = biayapemakaianF24 (struk[2]);
    fprintf(fPointer, "\t\t\t Biaya Pemakaian adalah   : Rp. %.2f\n",struk[4]);
    fprintf(fPointer, "\t\t\t Biaya BPM                : Rp. %.2f\n",BPM_R);
    fprintf(fPointer, "\t\t\t Biaya Administrasi       : Rp. %.2f\n",BIAYA_ADM);
    fprintf(fPointer, "\t\t\t.........................................................................\n");
    struk[5] = totaltagihanR (struk[4], struk[3]);
    fprintf(fPointer, "\t\t\t Total  : Rp %.2f + Rp %.2f + Rp %.2f + Rp %.2f \n",struk[4],BPM_R,BIAYA_ADM, struk[3], struk[4]+BPM_R+BIAYA_ADM+struk[3]);
    fprintf(fPointer, "\t\t\t Maka, jumlah tagihan anda adalah  : %.2f.\n",struk[5]);
    fprintf(fPointer, "\t\t\t=========================================================================\n");
    fprintf(fPointer, "\t\t\t                 ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^              \n");
    fprintf(fPointer, "\t\t\t-------------------------------------------------------------------------\n");

    printf("=========================================================================\n");
    printf("                1.Ulangi      2.Kembali       3.Keluar \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Masukkan Pilihan Anda    : ");
    pilihan = validasimenu2();
    system("cls");

    switch(pilihan){
	    case 1:
	    F24();
	    break;
	    case 2:
	    industri();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
	    break;
	 }
}
