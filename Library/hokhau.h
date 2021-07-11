#ifndef HO_KHAU_H
#define HO_KHAU_H

#include<stdio.h>
#include "stdlib.h"
#include "datatype.h"
#include "sukien.h"
#include<string.h>

#define ThuongTrutraver(root,tmp)	for(tmp=root;tmp!=NULL;tmp=tmp->nextTT)
#define NhanKhautraver(root,tmp)	for(tmp=root;tmp!=NULL;tmp=tmp->nextNK)
#define HoKhautraver(root,tmp)		for(tmp=root;tmp!=NULL;tmp=tmp->nextHK)

HoKhau *allHK;
int IDnha;

void setIDnha(){
	IDnha=0;
	allHK=NULL;
}

GhiChu* makeNewGhiChu(Date ngay,char* noi_dung){
	GhiChu *New=(GhiChu*)malloc(sizeof(GhiChu));
	New->ngay=ngay;
	strcpy(New->noi_dung,noi_dung);
	New->nextGC=New->prevGC=NULL;
	return New;
}

void addGhiChu(GhiChu **root, GhiChu *add){//them vao dau
	if(*root!=NULL){
		GhiChu* tmp;
		for(tmp=*root;tmp->nextGC!=NULL;tmp=tmp->nextGC){}
		add->prevGC=tmp;
		tmp->nextGC=add;
	}
	else *root=add;
}

void insertGhiChu(GhiChu **root,Date ngay,char *noi_dung){
	GhiChu *New=makeNewGhiChu(ngay,noi_dung);
	addGhiChu(root,New);
}

void changeNKcontent(	NhanKhau* New,
						char* Ten,
					    char* BiDanh,
					    int chu_ho,
					    char* gioi_tinh,
					    int tuoi,
					    Date ngay_sinh,
					    char* noi_sinh,
					    char* que_quan,
					    char* dan_toc,
					    char* nghe_nghiep,
					    char* noi_lam_viec,
					    char* CMND,
					    Date ngay_cap,
					    char* noi_cap,
						Date dang_ki,
					    GhiChu* gcNK,
					    char* quan_he,
						SuKien* duoc_to_chuc,
						int tt				){
	strcpy(New->BiDanh,BiDanh);
	New->chu_ho=chu_ho;
	strcpy(New->CMND,CMND);
	New->dang_ki=dang_ki;
	strcpy(New->noi_cap,noi_cap);
	strcpy(New->dan_toc,dan_toc);
	strcpy(New->gioi_tinh,gioi_tinh);
	New->ngay_cap=ngay_cap;
	New->ngay_sinh=ngay_sinh;
	strcpy(New->nghe_nghiep,nghe_nghiep);
	strcpy(New->noi_lam_viec,noi_lam_viec);
	strcpy(New->noi_sinh,noi_sinh);
	strcpy(New->quan_he,quan_he);
	strcpy(New->que_quan,que_quan);
	strcpy(New->Ten,Ten);
	New->tuoi=tuoi;
	New->tt=tt;
}

NhanKhau *makeNewNhanKhau(	char* Ten,
						    char* BiDanh,
						    int chu_ho,
						    char* gioi_tinh,
						    int tuoi,
						    Date ngay_sinh,
						    char* noi_sinh,
						    char* que_quan,
						    char* dan_toc,
						    char* nghe_nghiep,
						    char* noi_lam_viec,
						    char* CMND,
						    Date ngay_cap,
						    char* noi_cap,
							Date dang_ki,
						    GhiChu* gcNK,
						    char* quan_he,
							SuKien* duoc_to_chuc,
							int tt				){
	
	NhanKhau *New=(NhanKhau*)malloc(sizeof(NhanKhau));
	strcpy(New->BiDanh,BiDanh);
	New->chu_ho=chu_ho;
	strcpy(New->CMND,CMND);
	New->dang_ki=dang_ki;
	strcpy(New->noi_cap,noi_cap);
	New->gcNK=gcNK;
	strcpy(New->dan_toc,dan_toc);
	strcpy(New->gioi_tinh,gioi_tinh);
	New->ngay_cap=ngay_cap;
	New->ngay_sinh=ngay_sinh;
	strcpy(New->nghe_nghiep,nghe_nghiep);
	strcpy(New->noi_lam_viec,noi_lam_viec);
	strcpy(New->noi_sinh,noi_sinh);
	strcpy(New->quan_he,quan_he);
	strcpy(New->que_quan,que_quan);
	strcpy(New->Ten,Ten);
	New->tuoi=tuoi;
	New->chu_tri=duoc_to_chuc;
	New->nextNK=New->prevNK=NULL;
	New->tt=tt;
	return New;
}

void addNhanKhau(NhanKhau **root,NhanKhau *add){
	if(*root==NULL) *root=add;
	else{
		if(add->chu_ho){//la chu ho
			(*root)->prevNK=add;
			add->nextNK=*root;
			*root=add;
		}
		else{
			if((*root)->nextNK!=NULL){
				add->nextNK=(*root)->nextNK;
				(*root)->nextNK->prevNK=add;
			}
			add->prevNK=*root;
			(*root)->nextNK=add;
		}
	}
}

void insertNhanKhau(NhanKhau **root,
					char* Ten,
				    char* BiDanh,
				    int chu_ho,
				    char* gioi_tinh,
				    int tuoi,
				    Date ngay_sinh,
				    char* noi_sinh,
				    char* que_quan,
				    char* dan_toc,
				    char* nghe_nghiep,
				    char* noi_lam_viec,
				    char* CMND,
				    Date ngay_cap,
				    char* noi_cap,
					Date dang_ki,
				    GhiChu* gcNK,
				    char* quan_he,
					SuKien* duoc_to_chuc,
					int tt				){
	
	NhanKhau *New=makeNewNhanKhau(Ten,BiDanh,chu_ho,gioi_tinh,tuoi,ngay_sinh,noi_sinh,que_quan,dan_toc,nghe_nghiep,noi_lam_viec,CMND,ngay_cap,noi_cap,dang_ki,gcNK,quan_he,duoc_to_chuc,tt);
	addNhanKhau(root,New);
}

HoKhau *makeNewHoKhau(NhanKhau *NK,char* dia_chi,GhiChu *GC){
	HoKhau *New=(HoKhau*)malloc(sizeof(HoKhau));
	New->NK=NK;
	New->ID=++IDnha;
	New->gcHK=GC;
	strcpy(New->dc,dia_chi);
	New->nextHK=New->prevHK=NULL;
	return New;
}

void addHoKhau(HoKhau **root,HoKhau *add){//them vao dau
	if(*root!=NULL){
		HoKhau *tmp;
		for(tmp=*root;tmp->nextHK!=NULL;tmp=tmp->nextHK){}
		tmp->nextHK=add;
		add->prevHK=tmp;
	}
	else *root=add;
}

void insertHoKhau(HoKhau **root,NhanKhau *NK,char* dia_chi,GhiChu *GC){
	HoKhau *New=makeNewHoKhau(NK,dia_chi,GC);
	addHoKhau(root,New);
}

void chuyenNhanKhau(HoKhau *from,HoKhau *to,NhanKhau *person,Date ngay_chuyen){
	if(to==NULL){
		return;
	}
	char str[400];
	strcpy(str,"Da chuyen den ");
	strcat(str,to->dc);
	insertGhiChu(&person->gcNK,ngay_chuyen,str);
	if(from!=NULL){
		if(person==from->NK){//nguoi chuyen di la chu ho
			person->chu_ho=0;
			from->NK=person->nextNK;
			from->NK->chu_ho=1;
			from->NK->prevNK=NULL;
			person->nextNK=NULL;
		}
		else{
			if(person->nextNK!=NULL){
				person->nextNK->prevNK=person->prevNK;
			}
			person->prevNK->nextNK=person->nextNK;
		}
	}
	if(to->NK==NULL){
		to->NK=person;
		person->chu_ho=1;
	}
	else{
		addNhanKhau(&to->NK,person);
	}
}

void moi_sinh(NhanKhau *born,Date ngay){
	insertGhiChu(&born->gcNK,ngay,(char*)"Moi sinh");
}

void da_qua_doi(NhanKhau *dead,Date ngay){
	insertGhiChu(&dead->gcNK,ngay,(char*)"Da qua doi");
}

void thay_doi_chu_ho(HoKhau* HK,NhanKhau *chosen,Date ngay){
	NhanKhau* tmp;
	if(chosen!=HK->NK){
		HK->NK->chu_ho=0;
		chosen->chu_ho=1;
		char str[200];
		strcpy(str,"Doi chu ho tu ");
		strcat(str,HK->NK->Ten);
		strcat(str," sang cho ");
		strcat(str,chosen->Ten);
		insertGhiChu(&HK->gcHK,ngay,str);
		chosen->prevNK->nextNK=chosen->nextNK;
		if(chosen->nextNK!=NULL) chosen->nextNK->prevNK=chosen->prevNK;
		chosen->nextNK=HK->NK;
		chosen->prevNK=NULL;
		HK->NK=chosen;
//		if(HK->NK->nextNK==chosen){
//			HK->NK->nextNK=chosen->nextNK;
//			if(chosen->nextNK!=NULL) chosen->nextNK->prevNK=HK->NK;
//			chosen->nextNK=HK->NK;
//			HK->NK->prevNK=chosen;
//			chosen->prevNK=NULL;
//			HK->NK=chosen;
//		}
//		else{
//			tmp=HK->NK->nextNK;
//			HK->NK->nextNK=chosen->nextNK;
//			if(chosen->nextNK!=NULL) chosen->nextNK->prevNK=HK->NK;
//			HK->NK->prevNK=chosen->prevNK;
//			chosen->prevNK->nextNK=HK->NK;
//			chosen->nextNK=tmp;
//			tmp->prevNK=chosen;
//			chosen->prevNK=NULL;
//			HK->NK=chosen;
//		}
	}
}

HoKhau* HoKhausearchDiaChi(char* dia_chi){
	HoKhau *HK;
	HoKhautraver(allHK,HK){
		if(strcmp(HK->dc,dia_chi)==0) return HK;
	}
	return NULL;
}

NhanKhau* NhanKhausearchTenvaDiaChi(char *ten,char* dia_chi,HoKhau *HK){
	NhanKhau *NK;
	if(HK==NULL) HK=HoKhausearchDiaChi(dia_chi);
	if(HK==NULL) return NULL;
	NhanKhautraver(HK->NK,NK){
		if(strcmp(NK->Ten,ten)==0) return NK;
	}
	return NULL;
}

HoKhau* HoKhausearchNhanKhau(NhanKhau* srch){
	HoKhau *HK;
	NhanKhau *NK;
	if(srch==NULL) return NULL;
	HoKhautraver(allHK,HK){
		NhanKhautraver(HK->NK,NK){
			if(NK==srch) return HK;
		}
	}
	return NULL;
}

void freeNhanKhau(NhanKhau *to_free){
	GhiChu *tmp;
	for(tmp=to_free->gcNK;tmp!=NULL;tmp=to_free->gcNK){
		to_free->gcNK=tmp->nextGC;
		free(tmp);
	}
	
	SuKien* SK;
	for(SK=to_free->chu_tri;SK!=NULL;SK=to_free->chu_tri){
		deletedsSuKien(&allSK, SK);
	}
	free(to_free);
}

void deleteNhanKhau(NhanKhau **root, NhanKhau *del){
	if(*root==del) *root=del->nextNK;
	else{
		if(del->nextNK!=NULL){
			del->nextNK->prevNK=del->prevNK;
		}
		del->prevNK->nextNK=del->nextNK;
		
	}
	freeNhanKhau(del);
}

void freeHoKhau(HoKhau *to_free){
	NhanKhau *tmp;
	for(tmp=to_free->NK;tmp!=NULL;tmp=to_free->NK){
		to_free->NK=tmp->nextNK;
		freeNhanKhau(tmp);
	}
	free(to_free);
}

void deleteHoKhau(HoKhau **root, HoKhau *del){
	if(*root==del) *root=del->nextHK;
	else{
		if(del->nextHK!=NULL){
			del->nextHK->prevHK=del->prevHK;
		}
		del->prevHK->nextHK=del->nextHK;
	}
	freeHoKhau(del);
}

void freeAllHoKhau(HoKhau **root){
	HoKhau *tmp;
	for(tmp=(*root);tmp!=NULL;tmp=(*root)){
		(*root)=tmp->nextHK;
		freeHoKhau(tmp);
	}
	*root=NULL;
}

#endif
