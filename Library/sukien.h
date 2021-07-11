#ifndef SU_KIEN_H
#define SU_KIEN_H

#include"datatype.h"
#include"timeset.h"
#include"kho.h"

dsSuKien* allSK;
int IDSK;

void setIDSK(){
	IDSK=0;
	allSK=NULL;
}

SuKien* makeNewSuKien(char* ten,Kho do_muon,Time start,Time end,int xd){
	SuKien* New=(SuKien*)malloc(sizeof(SuKien));
	New->do_muon=do_muon;
	New->start=start;
	New->end=end;
	New->xet_duyet=xd;
	strcpy(New->ten_su_kien,ten);
	New->nextSK=New->prevSK=NULL;
}

void addSuKien(SuKien **root,SuKien *add){
	if(*root!=NULL){
		(*root)->prevSK=add;
		add->nextSK=*root;
	}
	*root=add;
}

void insertSuKien(SuKien **root,char* ten,Kho do_muon,Time start,Time end,int xd){
	SuKien* New=makeNewSuKien(ten,do_muon,start,end,xd);
	addSuKien(root,New);
}

dsSuKien* makeNewdsSuKien(NhanKhau *a, SuKien* b){
	
	addSuKien(&a->chu_tri,b);//Cu moi lan co su kien moi duoc add vao danh sach thi them luon cho nguoi to chuc
	
    dsSuKien *New = (dsSuKien*)malloc(sizeof(dsSuKien));
    New->nguoi_to_chuc = a;
    New->su_kien_to_chuc = b;
    New->leftSK = NULL;
    New->rightSK = NULL;
    New->ID=++IDSK;
    return New;
}

void adddsSuKien(dsSuKien **root, dsSuKien* add){
    if((*root) == NULL) (*root) = add;
    else {
        if(timecmp(add->su_kien_to_chuc->start,(*root)->su_kien_to_chuc->start)==-1) adddsSuKien(&(*root)->leftSK,add);
		else adddsSuKien(&(*root)->rightSK,add);
    }
}

void insertdsSuKien(dsSuKien **root,NhanKhau *a, SuKien* b){
	dsSuKien* New=makeNewdsSuKien(a,b);
	adddsSuKien(root,New);
}

void freeSuKien(SuKien **root, SuKien *del){
    if(*root==del) *root=del->nextSK;
	else{
		if(del->nextSK!=NULL){
			del->nextSK->prevSK=del->prevSK;
		}
		del->prevSK->nextSK=del->nextSK;
	}
	free(del);
}

void freedsSuKien(dsSuKien **T){
	freeSuKien(&(*T)->nguoi_to_chuc->chu_tri,(*T)->su_kien_to_chuc);
	free(*T);
	*T=NULL;
}

void deletemindsSuKien(dsSuKien** root,dsSuKien** del){
	if((*del)->leftSK == NULL){
		//Hoan doi noi dung 2 node
		(*root)->nguoi_to_chuc=(*del)->nguoi_to_chuc;
		(*root)->su_kien_to_chuc=(*del)->su_kien_to_chuc;
		
		dsSuKien *tmp=(*del)->rightSK;
		freedsSuKien(del);
		*del=tmp;
		return;
	}
	else deletemindsSuKien(root,&(*del)->leftSK);
}

void deletedsSuKien(dsSuKien** root, SuKien *del){
	if(*root!=NULL){
	    if((*root)->su_kien_to_chuc==del){
	    	if((*root)->leftSK == NULL && (*root)->rightSK == NULL){
	    		freedsSuKien(root);
			}
		    else if((*root)->leftSK == NULL){
				dsSuKien *tmp=(*root)->rightSK;
				freedsSuKien(root);
			}
		    else if((*root)->rightSK == NULL){
		    	dsSuKien *tmp=(*root)->leftSK;
				freedsSuKien(root);
	    		*root=tmp;
			}
		    else
		    	deletemindsSuKien(root,&(*root)->rightSK);
		}
		else if(timecmp(del->start,(*root)->su_kien_to_chuc->start)==-1) deletedsSuKien(&(*root)->leftSK,del);
	    else deletedsSuKien(&(*root)->rightSK,del);
	}
}

void freeAllSuKien(dsSuKien **T){
	if(*T==NULL) return;
	freeAllSuKien(&(*T)->leftSK);
	freeAllSuKien(&(*T)->rightSK);
	freedsSuKien(T);
}

dsSuKien* dsSuKiensearchID(dsSuKien* cur,int ID){
	if(cur==NULL) return NULL;
	dsSuKien* SK=NULL;
	SK=dsSuKiensearchID(cur->leftSK,ID);
	if(SK!=NULL) return SK;
	if(cur->ID==ID) return cur;
	return SK=dsSuKiensearchID(cur->rightSK,ID);
}

Kho checkDo(dsSuKien *cur, Kho able, Time Start,Time End, dsSuKien* except){//Kiem tra xem la co muon duoc do khong
	if(cur==NULL) return able;
	able=checkDo(cur->leftSK,able,Start,End,except);
	if(cur!=except&&cur->su_kien_to_chuc->xet_duyet!=0){
		if(timecmp(Start,cur->su_kien_to_chuc->start)==-1){//cur dien ra sau
			if(timecmp(End,cur->su_kien_to_chuc->start)==-1){//Su kien cur dien ra tach biet
				return checkDo(cur->leftSK,able,Start,End,except);
			}
			else{//trung vao 1 phan thoi gian cua nhau
				able.ban-=cur->su_kien_to_chuc->do_muon.ban;
				able.dai-=cur->su_kien_to_chuc->do_muon.dai;
				able.ghe-=cur->su_kien_to_chuc->do_muon.ghe;
				able.loa-=cur->su_kien_to_chuc->do_muon.loa;
				able.man_hinh-=cur->su_kien_to_chuc->do_muon.man_hinh;
				able.phong-=cur->su_kien_to_chuc->do_muon.phong;
			}
		}
		else{//cur dien ra truoc
			if(timecmp(Start,cur->su_kien_to_chuc->end)==-1){//trung vao 1 phan thoi gian cua nhau
				able.ban-=cur->su_kien_to_chuc->do_muon.ban;
				able.dai-=cur->su_kien_to_chuc->do_muon.dai;
				able.ghe-=cur->su_kien_to_chuc->do_muon.ghe;
				able.loa-=cur->su_kien_to_chuc->do_muon.loa;
				able.man_hinh-=cur->su_kien_to_chuc->do_muon.man_hinh;
				able.phong-=cur->su_kien_to_chuc->do_muon.phong;
			}
		}
	}
	return checkDo(cur->rightSK,able,Start,End,except);
}

int chiPhi(Kho toan_bo,Kho hong){
	return ((toan_bo.ban*gia_thue.ban)+(toan_bo.dai*gia_thue.dai)+(toan_bo.ghe*gia_thue.ghe)+
			(toan_bo.loa*gia_thue.loa)+(toan_bo.man_hinh*gia_thue.man_hinh)+(toan_bo.phong*gia_thue.phong)+
			(hong.ban*gia_sua.ban)+(hong.dai*gia_sua.dai)+(hong.ghe*gia_sua.ghe)+
			(hong.loa*gia_sua.loa)+(hong.man_hinh*gia_sua.man_hinh)+(hong.phong*gia_sua.phong));
}

void duoc_duyet(SuKien *A){
	A->xet_duyet=1;
}

#endif
