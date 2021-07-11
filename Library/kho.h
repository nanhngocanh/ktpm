#ifndef KHO_H
#define KHO_H

#include<stdio.h>
#include"datatype.h"

Kho allSP, gia_thue,gia_sua;

void duyetkho(){
	allSP.ban=allSP.ghe=200;
	allSP.dai=allSP.loa=40;
	allSP.man_hinh=allSP.phong=14;
	gia_thue.ban=gia_thue.ghe=10000;
	gia_thue.dai=gia_thue.loa=20000;
	gia_thue.man_hinh=40000;
	gia_thue.phong=100000;
	gia_sua.ban=gia_sua.ghe=40000;
	gia_sua.dai=gia_sua.loa=80000;
	gia_sua.man_hinh=
	gia_sua.phong=1400000;
//    Kho a;
//    FILE* input = fopen("kho.txt", "r");
//    fscanf(input, "%d\t%d",&a.ban.so_luong, &a.ban.gia_tien);
//    fscanf(input, "%d\t%d",&a.ghe.so_luong, &a.ghe.gia_tien);
//    fscanf(input, "%d\t%d",&a.loa.so_luong, &a.loa.gia_tien);
//    fscanf(input, "%d\t%d",&a.dai.so_luong, &a.dai.gia_tien);
//    fscanf(input, "%d\t%d",&a.phong.so_luong, &a.phong.gia_tien);
//    fclose(input);
//    return a;
}

#endif
