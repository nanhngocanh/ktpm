#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct time{
    int gio, phut, ngay, thang, nam;
}Time;

typedef struct Kho{
    int ban, ghe, loa, dai,man_hinh, phong;
}Kho;

typedef struct su_kien_struct{
    char ten_su_kien[400];
    Kho do_muon;
    Time start,end;
    int xet_duyet;
    struct su_kien_struct *nextSK,*prevSK;//dung de noi cac su kien do cung 1 nguoi to chuc
}SuKien;

typedef struct date{
    int ngay,thang,nam;
}Date;

//typedef struct dia_chi{
//  int So_nha;
//  char duong[20];
//    char phuong[20];
//    char quan[20];
//    char thanh_pho[20];
//}DiaChi;

typedef struct ghi_chu_struct{
    Date ngay;
    char noi_dung[400];
    struct ghi_chu_struct *nextGC, *prevGC;
}GhiChu;

typedef struct nhan_khau_struct{
    char Ten[400];
    char BiDanh[400];
    int chu_ho;//0 khong; 1 co;
    char gioi_tinh[30];//0 nam; 1 nu;
    int tuoi;
    Date ngay_sinh;
    char noi_sinh[400];
    char que_quan[400];
    char dan_toc[400];
    char nghe_nghiep[400];
    char noi_lam_viec[400];
    char CMND[400];
    char noi_cap[400];
    Date ngay_cap, dang_ki/*thuong tru*/;
    GhiChu *gcNK;
    char quan_he[400];
    SuKien *chu_tri;//cac su kien do nguoi nay chu tri
    int tt;
    struct nhan_khau_struct *nextNK, *prevNK;//chu nha luon dung dau
}NhanKhau;

typedef struct ho_khau_struct{
    int ID;
//    DiaChi dc;
    char dc[400];
    NhanKhau *NK;
    GhiChu *gcHK;
    struct ho_khau_struct *nextHK,*prevHK;
}HoKhau;

typedef struct danh_sach_su_kien{
    int ID;
    NhanKhau *nguoi_to_chuc;
    SuKien *su_kien_to_chuc;
    struct danh_sach_su_kien *leftSK, *rightSK;
}dsSuKien;



typedef struct{
    char username[10];
    char pass[10];
}nguoiquanly;
nguoiquanly user[3];

void int_to_string(int a,char* s){
    sprintf(s,"%d",a);
}

void date_to_string(Date a,char* s){
    char s1[400];
    int_to_string(a.ngay,s1);
    strcpy(s,s1);
    strcat(s,"/");
    int_to_string(a.thang,s1);
    strcat(s,s1);
    strcat(s,"/");
    int_to_string(a.nam,s1);
    strcat(s,s1);
}

void time_to_string(Time a,char* s){
    char s1[400];
    int_to_string(a.gio,s1);
    strcpy(s,s1);
    strcat(s,":");
    int_to_string(a.phut,s1);
    strcat(s,s1);
    strcat(s," ");
    int_to_string(a.ngay,s1);
    strcat(s,s1);
    strcat(s,"/");
    int_to_string(a.thang,s1);
    strcat(s,s1);
    strcat(s,"/");
    int_to_string(a.nam,s1);
    strcat(s,s1);
}
#endif 
