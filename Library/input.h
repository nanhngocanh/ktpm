#ifndef INPUT_H
#define INPUT_H

#include<stdio.h>
#include "datatype.h"
#include"hokhau.h"
#include"sukien.h"
// #include"glade.h"
// void log_out_clicked(GtkButton *b){
// 	gtk_widget_destroy(window_main);
//     login_screen();
// }
// Kho duyetkho(){
//     Kho a;
//     FILE* input = fopen("kho.txt", "r");
//     fscanf(input, "%d\t%d",&a.ban.so_luong, &a.ban.gia_tien);
//     fscanf(input, "%d\t%d",&a.ghe.so_luong, &a.ghe.gia_tien);
//     fscanf(input, "%d\t%d",&a.loa.so_luong, &a.loa.gia_tien);
//     fscanf(input, "%d\t%d",&a.dai.so_luong, &a.dai.gia_tien);
//     fscanf(input, "%d\t%d",&a.phong.so_luong, &a.phong.gia_tien);
//     fclose(input);
//     return a;
// }

// void consoleInputHoKhau(){
// 	int i,n,j,m;
// 	NhanKhau* NK=NULL;
// 	DiaChi dc;
// 	char Ten[20];
//     char BiDanh[20];
//     int chu_ho;//0 khong; 1 co;
//     int gioi_tinh;//0 nam; 1 nu;
//     Date ngay_sinh;
//     char que_quan[20];
//     char dan_toc[20];
//     char nghe_nghiep[30];
//     char noi_lam_viec[30];
//     char CMND[12];
//     Date ngay_cap, dang_ki/*thuong tru*/;
//     ThuongTru *danh_sach_noi_o=NULL;
// 	Date ngay; DiaChi noi;
//     char quan_he[30];
//     int qua_doi;
// 	printf("Nhap dia chi(so_nha duong phuong quan thanh_pho): ");
// 	scanf("%d %s %s %s %s",&dc.So_nha, dc.duong,dc.phuong,dc.quan,dc.thanh_pho);
// 	printf("Nhap so nhan khau: ");
// 	scanf("%d",&n);
// 	for(i=0;i<n;++i){
// 		printf("Nhap ten: ");
// 		scanf("%s",Ten);
// 		printf("Nhap bi danh: ");
// 		scanf("%s",BiDanh);
// 		printf("Co la chu ho(1 co, 0 khong): ");
// 		scanf("%d",&chu_ho);
// 		printf("Gioi tinh(0 nam, 1 nu): ");
// 		scanf("%d",&gioi_tinh);
// 		printf("Ngay sinh(ngay thang nam): ");
// 		scanf("%d %d %d",&ngay_sinh.ngay,&ngay_sinh.thang,&ngay_sinh.nam);
// 		printf("Que quan(viet_khong_cach): ");
// 		scanf("%s",que_quan);
// 		printf("Dan toc: ");
// 		scanf("%s", dan_toc);
// 		printf("Nghe nghiep: ");
// 		scanf("%s",nghe_nghiep);
// 		printf("Noi lam viec: ");
// 		scanf("%s",noi_lam_viec);
// 		printf("CMND: ");
// 		scanf("%s",CMND);
// 		printf("Ngay cap CMND(ngay thang nam): ");
// 		scanf("%d %d %d",&ngay_cap.ngay,&ngay_cap.thang,&ngay_cap.nam);
// 		printf("Ngay dang ki ho khau(ngay thang nam): ");
// 		scanf("%d %d %d",&dang_ki.ngay,&dang_ki.thang,&dang_ki.nam);
// 		printf("Nhap so dia diem thuong tru truoc dia diem nay: ");
// 		scanf("%d",&m);
// 		for(j=0;j<m;++j){
// 			printf("Nhap dia chi(so_nha duong phuong quan thanh_pho): ");
// 			scanf("%d %s %s %s %s",&noi.So_nha, noi.duong,noi.phuong,noi.quan,noi.thanh_pho);
// 			printf("Ngay chuyen ho khau(ngay thang nam): ");
// 			scanf("%d %d %d",&ngay.ngay,&ngay.thang,&ngay.nam);
// 			insertThuongTru(&danh_sach_noi_o,ngay,noi);
// 		}
// 		printf("Quan he voi chu ho: ");
// 		scanf("%s",quan_he);
// 		printf("Da qua doi(1 dung, 0 sai): ");
// 		scanf("%d",&qua_doi);
// 		insertNhanKhau(&NK,Ten,BiDanh,chu_ho,gioi_tinh,ngay_sinh,que_quan,dan_toc,nghe_nghiep,noi_lam_viec,CMND,ngay_cap,dang_ki,danh_sach_noi_o,quan_he,qua_doi,NULL);
// 	}
// 	insertHoKhau(&allHK,NK,dc);
// }

void read_user_data(){
    FILE *input = fopen("user_infor.txt","r");
    for(int i = 0; i < 3; i++){
    fscanf(input, "%s\t%s",user[i].username, user[i].pass);
    }
    fclose(input);
    return;
    
}

#endif
