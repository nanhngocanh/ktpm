#ifndef FILE_WORK_H
#define FILE_WORK_H

#include<stdio.h>
#include "datatype.h"
#include"hokhau.h"
#include"sukien.h"

void readghichufile(char* file){
	FILE* fptr=fopen(file,"r");
	if(fptr==NULL){
		printf("cant open %s",file);
	}
    char dc[200],ten[100];
    GhiChu a,*GC;
	int i,n,choice;
	NhanKhau* NK;
	HoKhau* HK;
    
    for(;fgets(dc, 200, fptr)!= NULL;){
    	printf("%s",dc);
		dc[strlen(dc)-1]='\0';
		
		fscanf(fptr,"%d\n",&choice);
		printf("%d\n",choice);
		if(choice==1){
			fgets(ten,100,fptr);
			printf("%s",ten);
			ten[strlen(ten)-1]='\0';
			NK=NhanKhausearchTenvaDiaChi(ten,dc,NULL);
		}
		else{
			HK=HoKhausearchDiaChi(dc);
		}
		
    	fscanf(fptr,"%d\n",&n);
    	printf("%d\n",n);
    	for(i=0,GC=NULL;i<n;++i){
		    fscanf(fptr,"\n");
		    
		    fscanf(fptr,"%d %d %d\n",&a.ngay.ngay,&a.ngay.thang,&a.ngay.nam);
		    printf("%d %d %d\n",a.ngay.ngay, a.ngay.thang,a.ngay.nam);
		    
		    fgets(a.noi_dung, 400, fptr);
		    if(a.noi_dung[strlen(a.noi_dung)-1]=='\n') a.noi_dung[strlen(a.noi_dung)-1]='\0';
		    
		    insertGhiChu(&GC,a.ngay,a.noi_dung);
			printf("\ndone %d ghi chu\n\n",i+1);
		}
		
		if(choice==1){
			if(NK!=NULL) addGhiChu(&(NK->gcNK),GC);
			printf("%s\n%s\n",NK->Ten,NK->gcNK->noi_dung);
		}
		else{
			if(HK!=NULL) addGhiChu(&(HK->gcHK),GC);
		}
		
		printf("\ndone ghi chu\n\n");
		if(fgetc(fptr)==EOF) break;
	}
		
    fclose(fptr);
    return;
}

void writeghichufile(char* file,char* dc, char* ten, GhiChu* GC,int isNK){
	FILE* fptr=fopen(file,"a");
	if(fptr==NULL){
		printf("cant open %s",file);
	}
	int i,n;
	NhanKhau* NK;
	HoKhau* HK;
    
    fprintf(fptr,"%s\n%d\n",dc,isNK);
    if(isNK==1) fprintf(fptr,"%s\n",ten);
    
    for(n=1;GC->nextGC!=NULL;GC=GC->nextGC){
    	++n;
	}
	
	fprintf(fptr,"%d\n",n);
    
    for(;GC!=NULL;GC=GC->prevGC){
	    fprintf(fptr,"\n%d %d %d\n%s\n",GC->ngay.ngay,GC->ngay.thang,GC->ngay.nam,GC->noi_dung);
	}
	fprintf(fptr,"\n");
	
    fclose(fptr);
    return;
}

void readnhankhaufile(char* file){
    FILE* fptr=fopen(file,"r");
    if(fptr==NULL){
    	printf("cant open %s\n",file);
    	return;
    }
    NhanKhau a,*NK;
    char dc[200];
	int i,n;
    printf("start\n");
    for(;fgets(dc, 200, fptr)!= NULL;){
    	printf("%s",dc);
		dc[strlen(dc)-1]='\0';
		printf("%s\n",dc);
    	fscanf(fptr,"%d\n",&n);
    	for(i=0,NK=NULL;i<n;++i){
		    fscanf(fptr,"\n");
		    fgets(a.Ten,100,fptr);
		    a.Ten[strlen(a.Ten)-1]='\0';
		    printf("%s\n",a.Ten);
		    
		    fgets(a.BiDanh,50,fptr);
		    
		    a.BiDanh[strlen(a.BiDanh)-1]='\0';
		    printf("%s\n",a.BiDanh);
		    
		    fscanf(fptr,"%d %d %d\n",&a.ngay_sinh.ngay,&a.ngay_sinh.thang,&a.ngay_sinh.nam);
		    printf("%d %d %d\n",a.ngay_sinh.ngay, a.ngay_sinh.thang,a.ngay_sinh.nam);
		    
		    fgets(a.noi_sinh, 20, fptr);
		    printf("%s",a.noi_sinh);
		    a.noi_sinh[strlen(a.noi_sinh)-1]='\0';
		    
		    fgets(a.que_quan, 100, fptr);
		    printf("%s",a.que_quan);
		    a.que_quan[strlen(a.que_quan)-1]='\0';
		    
		    fscanf(fptr,"%s %s %d %s %d\n",a.dan_toc,a.gioi_tinh,&a.tuoi,a.CMND ,&a.chu_ho);
		    printf("%s %s %d %s %d\n",a.dan_toc,a.gioi_tinh,a.tuoi,a.CMND ,a.chu_ho);
		    fscanf(fptr,"%d %d %d\n",&a.ngay_cap.ngay,&a.ngay_cap.thang,&a.ngay_cap.nam);
		    printf("%d %d %d\n",a.ngay_cap.ngay, a.ngay_cap.thang,a.ngay_cap.nam);
		    
		    fgets(a.noi_cap, 20, fptr);
		    printf("%s",a.noi_cap);
		    a.noi_cap[strlen(a.noi_cap)-1]='\0';
		    
		    fgets(a.nghe_nghiep, 50, fptr);
		    printf("%s",a.nghe_nghiep);
		    a.nghe_nghiep[strlen(a.nghe_nghiep)-1]='\0';
		    
		    fgets(a.noi_lam_viec, 100, fptr);
		    printf("%s",a.noi_lam_viec);
		    a.noi_lam_viec[strlen(a.noi_lam_viec)-1]='\0';
		    
		    fscanf(fptr,"%d %d %d\n",&a.dang_ki.ngay,&a.dang_ki.thang,&a.dang_ki.nam);
		    printf("%d %d %d\n",a.dang_ki.ngay, a.dang_ki.thang,a.dang_ki.nam);
		    
		    fscanf(fptr,"%d\n",&a.tt);
		    
		    fgets(a.quan_he, 30, fptr);
		    if(a.quan_he[strlen(a.quan_he)-1]=='\n') a.quan_he[strlen(a.quan_he)-1]='\0';
		    printf("%s\n",a.quan_he);
			insertNhanKhau(&NK,a.Ten,a.BiDanh,a.chu_ho,a.gioi_tinh,a.tuoi,a.ngay_sinh,a.noi_sinh,a.que_quan,a.dan_toc,a.nghe_nghiep,a.noi_lam_viec,a.CMND,a.ngay_cap,a.noi_cap,a.dang_ki,NULL,a.quan_he,NULL,a.tt);
			printf("\n%s\n%s\ndone %d man\n\n",NK->noi_sinh,a.noi_sinh,i+1);
		}
		insertHoKhau(&allHK,NK,dc,NULL);
		printf("\ndone ho khau\n\n");
		if(fgets(dc, 200, fptr)== NULL) break;
	}
		
    fclose(fptr);
    return;
}

void writenhankhaufile(char* file,HoKhau* HK,char* fileghichu){
    FILE* fptr=fopen(fileghichu,"w");
    if(fptr==NULL){
		printf("cant open %s",fileghichu);
	}
	fclose(fptr);
	fptr=fopen(file,"w");
	if(fptr==NULL){
		printf("cant open %s",file);
	}
    NhanKhau *p;
	int i,n;
    
    for(;HK!=NULL;HK=HK->nextHK){
    	if(HK->gcHK!=NULL) writeghichufile(fileghichu,HK->dc,NULL,HK->gcHK,0);
    	fprintf(fptr,"%s\n",HK->dc);
    	for(p=HK->NK,n=0;p!=NULL;p=p->nextNK){
    		printf("%s\n",p->noi_sinh);
    		++n;
		}
		printf("%d\n",n);
    	fprintf(fptr,"%d\n\n",n);
    	for(i=0,p=HK->NK;i<n;++i,p=p->nextNK){
		    fprintf(fptr,"%s\n%s\n%d %d %d\n%s\n%s\n%s %s %d %s %d\n%d %d %d\n%s\n%s\n%s\n%d %d %d\n%d\n%s\n\n"
	,p->Ten,p->BiDanh,p->ngay_sinh.ngay,p->ngay_sinh.thang,p->ngay_sinh.nam,p->noi_sinh,p->que_quan,p->dan_toc,p->gioi_tinh,p->tuoi,p->CMND,p->chu_ho,p->ngay_cap.ngay,p->ngay_cap.thang,p->ngay_cap.nam,p->noi_cap,p->nghe_nghiep,p->noi_lam_viec,p->dang_ki.ngay,p->dang_ki.thang,p->dang_ki.nam,p->tt,p->quan_he);
			if(p->gcNK!=NULL) writeghichufile(fileghichu,HK->dc,p->Ten,p->gcNK,1);
		}
	}
		
    fclose(fptr);
    return;
}

void readsukienfile(char *file){
    FILE* fptr = fopen(file,"r");
    if(fptr==NULL){
    	printf("cant open %s\n",file );
    	return;
    }
    SuKien a,*SK;
    NhanKhau* NK;
    char dia_chi[200];
    char ten_nguoi_tc[100];
    int n,i;
    while(fgets(dia_chi,200,fptr)!=NULL){
        dia_chi[strlen(dia_chi)-1] = '\0';
        fgets(ten_nguoi_tc,100,fptr); 
        ten_nguoi_tc[strlen(ten_nguoi_tc)-1] = '\0';
        NK=NhanKhausearchTenvaDiaChi(ten_nguoi_tc,dia_chi,NULL);
        fscanf(fptr,"%d\n", &n);
        for(i=0,SK=NULL;i<n;++i){
	        fscanf(fptr,"\n");
	        fgets(a.ten_su_kien,100,fptr); 
	        a.ten_su_kien[strlen(a.ten_su_kien)-1] = '\0';
	        fscanf(fptr,"%d %d %d %d %d %d\n",&a.do_muon.ban,&a.do_muon.ghe,&a.do_muon.loa,&a.do_muon.dai,&a.do_muon.man_hinh,&a.do_muon.phong);
	        fscanf(fptr,"%d %d %d %d %d\n",&a.start.gio, &a.start.phut,&a.start.ngay,&a.start.thang,&a.start.nam);
	        fscanf(fptr,"%d %d %d %d %d\n",&a.end.gio, &a.end.phut,&a.end.ngay,&a.end.thang,&a.end.nam);
	        fscanf(fptr,"%d\n",&a.xet_duyet);
	        if(NK!=NULL) insertSuKien(&SK,a.ten_su_kien,a.do_muon,a.start,a.end,a.xet_duyet);
	    }
	    if(NK!=NULL) insertdsSuKien(&allSK,NK, SK);
    	if(fgets(dia_chi,200,fptr)==NULL) break;
    }
    fclose(fptr);
}

void writedssukienfile(FILE* fptr,dsSuKien *a){
	if(a==NULL) return;
	writedssukienfile(fptr,a->leftSK);

	HoKhau* HK=HoKhausearchNhanKhau(a->nguoi_to_chuc);
	if(HK!=NULL){
		fprintf(fptr, "%s\n%s\n",HK->dc,a->nguoi_to_chuc->Ten );
		fprintf(fptr, "1\n\n%s\n", a->su_kien_to_chuc->ten_su_kien);
	    fprintf(fptr,"%d %d %d %d %d %d\n",a->su_kien_to_chuc->do_muon.ban,a->su_kien_to_chuc->do_muon.ghe,a->su_kien_to_chuc->do_muon.loa,a->su_kien_to_chuc->do_muon.dai,a->su_kien_to_chuc->do_muon.man_hinh,a->su_kien_to_chuc->do_muon.phong);
	    fprintf(fptr,"%d %d %d %d %d\n",a->su_kien_to_chuc->start.gio, a->su_kien_to_chuc->start.phut,a->su_kien_to_chuc->start.ngay,a->su_kien_to_chuc->start.thang,a->su_kien_to_chuc->start.nam);
	    fprintf(fptr,"%d %d %d %d %d\n",a->su_kien_to_chuc->end.gio, a->su_kien_to_chuc->end.phut,a->su_kien_to_chuc->end.ngay,a->su_kien_to_chuc->end.thang,a->su_kien_to_chuc->end.nam);
	    fprintf(fptr,"%d\n\n",a->su_kien_to_chuc->xet_duyet);
	} 
	
	writedssukienfile(fptr,a->rightSK);
}

void writesukienfile(char *file){
    FILE* fptr = fopen(file,"w");
    writedssukienfile(fptr,allSK);
 	fclose(fptr);
}

//
//void consoleInputHoKhau(){
//	int i,n,j,m;
//	NhanKhau* NK=NULL;
//	char dc[200];
//	char Ten[20];
//    char BiDanh[20];
//    int chu_ho;//0 khong; 1 co;
//    int gioi_tinh;//0 nam; 1 nu;
//    Date ngay_sinh;
//    char que_quan[20];
//    char dan_toc[20];
//    char nghe_nghiep[30];
//    char noi_lam_viec[30];
//    char CMND[12];
//    Date ngay_cap, dang_ki/*thuong tru*/;
//    GhiChu *GC=NULL;
//	Date ngay; char nd[400];
//    char quan_he[30];
//    int qua_doi;
//	printf("Nhap dia chi: ");
//	scanf("%s",&dc);
//	printf("Nhap so nhan khau: ");
//	scanf("%d",&n);
//	for(i=0;i<n;++i){
//		printf("Nhap ten: ");
//		scanf("%s",Ten);
//		printf("Nhap bi danh: ");
//		scanf("%s",BiDanh);
//		printf("Co la chu ho(1 co, 0 khong): ");
//		scanf("%d",&chu_ho);
//		printf("Gioi tinh(0 nam, 1 nu): ");
//		scanf("%d",&gioi_tinh);
//		printf("Ngay sinh(ngay thang nam): ");
//		scanf("%d %d %d",&ngay_sinh.ngay,&ngay_sinh.thang,&ngay_sinh.nam);
//		printf("Que quan(viet_khong_cach): ");
//		scanf("%s",que_quan);
//		printf("Dan toc: ");
//		scanf("%s", dan_toc);
//		printf("Nghe nghiep: ");
//		scanf("%s",nghe_nghiep);
//		printf("Noi lam viec: ");
//		scanf("%s",noi_lam_viec);
//		printf("CMND: ");
//		scanf("%s",CMND);
//		printf("Ngay cap CMND(ngay thang nam): ");
//		scanf("%d %d %d",&ngay_cap.ngay,&ngay_cap.thang,&ngay_cap.nam);
//		printf("Ngay dang ki ho khau(ngay thang nam): ");
//		scanf("%d %d %d",&dang_ki.ngay,&dang_ki.thang,&dang_ki.nam);
//		printf("Nhap so dia diem thuong tru truoc dia diem nay: ");
//		scanf("%d",&m);
//		for(j=0;j<m;++j){
//			printf("Nhap dia chi(so_nha duong phuong quan thanh_pho): ");
//			scanf("%d %s %s %s %s",&noi.So_nha, noi.duong,noi.phuong,noi.quan,noi.thanh_pho);
//			printf("Ngay chuyen ho khau(ngay thang nam): ");
//			scanf("%d %d %d",&ngay.ngay,&ngay.thang,&ngay.nam);
//			insertThuongTru(&danh_sach_noi_o,ngay,noi);
//		}
//		printf("Quan he voi chu ho: ");
//		scanf("%s",&quan_he);
//		printf("Da qua doi(1 dung, 0 sai): ");
//		scanf("%d",&qua_doi);
//		insertNhanKhau(&NK,Ten,BiDanh,chu_ho,gioi_tinh,ngay_sinh,que_quan,dan_toc,nghe_nghiep,noi_lam_viec,CMND,ngay_cap,dang_ki,danh_sach_noi_o,quan_he,qua_doi,NULL);
//	}
//	insertHoKhau(&allHK,NK,dc);
//}


#endif
