#ifndef OUT_PUT_H
#define OUT_PUT_H

#include"datatype.h"

void printNhanKhau(NhanKhau *p){
	printf("Ten: %-30sBi danh: %s\nChu ho: %d\t\tGioi_tinh: %s\nNgay sinh: %-2d/%-2d/%-10d Tuoi: %d\nQue quan: %-30s Dan toc: %s\nNghe nghiep: %-20s Noi lam viec: %s\nCMND: %s\nNoi cap: %-30s Ngay cap CMND: %d/%d/%d\nNgay dang ki thuong tru: %d/%d/%d\nQuan he voi chu ho: %s\nQua doi: %d\n"
	,p->Ten,p->BiDanh,p->chu_ho,p->gioi_tinh,p->ngay_sinh.ngay,p->ngay_sinh.thang,p->ngay_sinh.nam,p->tuoi,p->que_quan,p->dan_toc,p->nghe_nghiep,p->noi_lam_viec,p->CMND,p->noi_cap,p->ngay_cap.ngay,p->ngay_cap.thang,p->ngay_cap.nam,p->dang_ki.ngay,p->dang_ki.thang,p->dang_ki.nam,p->quan_he);
}

void printHoKhau(HoKhau *p){
	printf("Ma ho khau: %d\nDia chi ho: %s\n",p->Ma_so_ho_khau,p->dc);
	NhanKhau *tmp;
	for(tmp=p->NK;tmp!=NULL;tmp=tmp->nextNK) printNhanKhau(tmp);
}

void printAllHoKhau(HoKhau* p){
	for(;p!=NULL;p=p->nextHK) printHoKhau(p);
}

void printdsSuKien(dsSuKien *p){
	printNhanKhau(p->nguoi_to_chuc);
}

#endif
