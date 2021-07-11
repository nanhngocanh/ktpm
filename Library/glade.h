#include "gtk/gtk.h"
#include "datatype.h"
#include "input.h"
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
clock_t start, end;
GtkBuilder *builder;
GtkWidget *window_login;
GtkWidget *window_start;
GtkWidget *window_main;
GtkWidget *nhan_khau_window;
GtkWidget *label_result;
GtkWidget *options_window;
//nhan khau screen
    GtkWidget *NK_win;
    GtkWidget *NK_fixed;

    GtkTreeStore *HK1_ts;
    GtkWidget *HK_sw1;
    GtkWidget *HK_vp1;
    GtkTreeView *HK_tv1;
    GtkTreeViewColumn *HK1c1;
    GtkCellRenderer *HK1cr1;
    GtkTreeViewColumn *HK1c2;
    GtkCellRenderer *HK1cr2;
    GtkTreeSelection *select_HK1;

    GtkTreeStore *HK2_ts;
    GtkWidget *HK_sw2;
    GtkWidget *HK_vp2;
    GtkTreeView *HK_tv2;
    GtkTreeViewColumn *HK2c1;
    GtkCellRenderer *HK2cr1;
    GtkTreeViewColumn *HK2c2;
    GtkCellRenderer *HK2cr2;
    GtkTreeSelection *select_HK2;

    GtkTreeStore *NK16_ts;
    GtkWidget *NK_sw16;
    GtkWidget *NK_vp16;
    GtkTreeView *NK_tv16;
    GtkTreeViewColumn *NK16c1;
    GtkCellRenderer *NK16cr1;
    GtkTreeViewColumn *NK16c2;
    GtkCellRenderer *NK16cr2;
    GtkTreeSelection *select_NK16;

    GtkWidget *NK_sw1;
    GtkWidget *NK_vp1;
    GtkWidget *NK_tv1;
    GtkTextBuffer *NK_tb1;

    GtkWidget *NK_sw2;
    GtkWidget *NK_vp2;
    GtkWidget *NK_tv2;
    GtkTextBuffer *NK_tb2;

    GtkWidget *NK_sw3;
    GtkWidget *NK_vp3;
    GtkWidget *NK_tv3;
    GtkTextBuffer *NK_tb3;

    GtkWidget *NK_sw4;
    GtkWidget *NK_vp4;
    GtkWidget *NK_tv4;
    GtkTextBuffer *NK_tb4;

    GtkWidget *NK_sw51;
    GtkWidget *NK_vp51;
    GtkWidget *NK_tv51;
    GtkTextBuffer *NK_tb51;

    GtkWidget *NK_sw52;
    GtkWidget *NK_vp52;
    GtkWidget *NK_tv52;
    GtkTextBuffer *NK_tb52;

    GtkWidget *NK_sw53;
    GtkWidget *NK_vp53;
    GtkWidget *NK_tv53;
    GtkTextBuffer *NK_tb53;

    GtkWidget *NK_sw6;
    GtkWidget *NK_vp6;
    GtkWidget *NK_tv6;
    GtkTextBuffer *NK_tb6;

    GtkWidget *NK_sw7;
    GtkWidget *NK_vp7;
    GtkWidget *NK_tv7;
    GtkTextBuffer *NK_tb7;

    GtkWidget *NK_sw8;
    GtkWidget *NK_vp8;
    GtkWidget *NK_tv8;
    GtkTextBuffer *NK_tb8;
   
    GtkWidget *NK_sw9;
    GtkWidget *NK_vp9;
    GtkWidget *NK_tv9;
    GtkTextBuffer *NK_tb9;

    GtkWidget *NK_sw10;
    GtkWidget *NK_vp10;
    GtkWidget *NK_tv10;
    GtkTextBuffer *NK_tb10;

    GtkWidget *NK_sw11;
    GtkWidget *NK_vp11;
    GtkWidget *NK_tv11;
    GtkTextBuffer *NK_tb11;

    GtkWidget *NK_sw121;
    GtkWidget *NK_vp121;
    GtkWidget *NK_tv121;
    GtkTextBuffer *NK_tb121;

    GtkWidget *NK_sw122;
    GtkWidget *NK_vp122;
    GtkWidget *NK_tv122;
    GtkTextBuffer *NK_tb122;

    GtkWidget *NK_sw123;
    GtkWidget *NK_vp123;
    GtkWidget *NK_tv123;
    GtkTextBuffer *NK_tb123;

    GtkWidget *NK_sw13;
    GtkWidget *NK_vp13;
    GtkWidget *NK_tv13;
    GtkTextBuffer *NK_tb13;

    GtkWidget *NK_sw141;
    GtkWidget *NK_vp141;
    GtkWidget *NK_tv141;
    GtkTextBuffer *NK_tb141;

    GtkWidget *NK_sw142;
    GtkWidget *NK_vp142;
    GtkWidget *NK_tv142;
    GtkTextBuffer *NK_tb142;

    GtkWidget *NK_sw143;
    GtkWidget *NK_vp143;
    GtkWidget *NK_tv143;
    GtkTextBuffer *NK_tb143;

    GtkWidget *NK_sw15;
    GtkWidget *NK_vp15;
    GtkWidget *NK_tv15;
    GtkTextBuffer *NK_tb15;

    GtkWidget *NK_ten_label;
    GtkWidget *NK_dang_ki_label;
    GtkWidget *NK_noi_sinh_label;
    GtkWidget *NK_que_quan_label;
    GtkWidget *NK_CMND_label;
    GtkWidget *NK_ngay_cap_label;
    GtkWidget *NK_dan_toc_label;
    GtkWidget *NK_nghe_nghiep_label;
    GtkWidget *NK_gioi_tinh_label;
    GtkWidget *NK_bi_danh_label;
    GtkWidget *NK_tuoi_label;
    GtkWidget *NK_noi_lam_viec_label;
    GtkWidget *NK_ngay_sinh_label;
    GtkWidget *NK_noi_cap_label;
    GtkWidget *NK_quan_he_label;
    GtkWidget *NK_ghi_chu_label;

    GtkWidget *NK_add;
    GtkWidget *HK_add;
    GtkWidget *NK_del;
    GtkWidget *HK_del;
    GtkWidget *NK_adj;
    GtkWidget *NK_top;
    GtkWidget *NK_srch;
    GtkWidget *NK_save;
    GtkWidget *NK_cal;
    GtkWidget *NK_qd;
    GtkWidget *NK_cqd;
    GtkWidget *NK_ms;
    GtkWidget *NK_cms;



    GtkWidget *NK_swtt1;
    GtkWidget *NK_vptt1;
    GtkWidget *NK_tvtt1;
    GtkTextBuffer *NK_tbtt1;

    GtkWidget *NK_swtt2;
    GtkWidget *NK_vptt2;
    GtkWidget *NK_tvtt2;
    GtkTextBuffer *NK_tbtt2;

    GtkWidget *NK_swtt3;
    GtkWidget *NK_vptt3;
    GtkWidget *NK_tvtt3;
    GtkTextBuffer *NK_tbtt3;

    int NK_is_edit_mode;
    int NK_is_add_mode;
    int NK_is_NK;
    int att;

    GtkWidget *NK_return_button;

//Su kien
    GtkWidget *SK_win;
    GtkWidget *SK_fixed;

    GtkWidget *SK_fix1;
    GtkWidget *SK_fix2;
    GtkWidget *SK_fix3;

    GtkWidget *SKts1_cg;
    GtkWidget *SKts2_cg;
    GtkWidget *SKts3_cg;

    GtkTreeStore *SK1_ts;
    GtkWidget *SK_sw1;
    GtkWidget *SK_vp1;
    GtkTreeView *SK_tv1;
    GtkTreeViewColumn *SK1c1;
    GtkCellRenderer *SK1cr1;
    GtkTreeViewColumn *SK1c2;
    GtkCellRenderer *SK1cr2;
    GtkTreeSelection *select_SK1;

    GtkWidget *SK_sw2;
    GtkWidget *SK_vp2;
    GtkWidget *SK_tv2;
    GtkTextBuffer *SK_tb2;

    GtkWidget *SK_sw31;
    GtkWidget *SK_vp31;
    GtkWidget *SK_tv31;
    GtkTextBuffer *SK_tb31;
    
    GtkWidget *SK_sw32;
    GtkWidget *SK_vp32;
    GtkWidget *SK_tv32;
    GtkTextBuffer *SK_tb32;
    
    GtkWidget *SK_sw33;
    GtkWidget *SK_vp33;
    GtkWidget *SK_tv33;
    GtkTextBuffer *SK_tb33;
    
    GtkWidget *SK_sw34;
    GtkWidget *SK_vp34;
    GtkWidget *SK_tv34;
    GtkTextBuffer *SK_tb34;
    
    GtkWidget *SK_sw35;
    GtkWidget *SK_vp35;
    GtkWidget *SK_tv35;
    GtkTextBuffer *SK_tb35;
    
    GtkWidget *SK_sw41;
    GtkWidget *SK_vp41;
    GtkWidget *SK_tv41;
    GtkTextBuffer *SK_tb41;
    
    GtkWidget *SK_sw42;
    GtkWidget *SK_vp42;
    GtkWidget *SK_tv42;
    GtkTextBuffer *SK_tb42;
    
    GtkWidget *SK_sw43;
    GtkWidget *SK_vp43;
    GtkWidget *SK_tv43;
    GtkTextBuffer *SK_tb43;
    
    GtkWidget *SK_sw44;
    GtkWidget *SK_vp44;
    GtkWidget *SK_tv44;
    GtkTextBuffer *SK_tb44;
    
    GtkWidget *SK_sw45;
    GtkWidget *SK_vp45;
    GtkWidget *SK_tv45;
    GtkTextBuffer *SK_tb45;

    GtkWidget *SK_sw5;
    GtkWidget *SK_vp5;
    GtkWidget *SK_tv5;
    GtkTextBuffer *SK_tb5;
    
    GtkWidget *SK_sw6;
    GtkWidget *SK_vp6;
    GtkWidget *SK_tv6;
    GtkTextBuffer *SK_tb6;
    
    GtkWidget *SK_sw7;
    GtkWidget *SK_vp7;
    GtkWidget *SK_tv7;
    GtkTextBuffer *SK_tb7;

    GtkWidget *SK_sw8;
    GtkWidget *SK_vp8;
    GtkWidget *SK_tv8;
    GtkTextBuffer *SK_tb8;
    
    GtkWidget *SK_sw9;
    GtkWidget *SK_vp9;
    GtkWidget *SK_tv9;
    GtkTextBuffer *SK_tb9;

    GtkWidget *SK_sw10;
    GtkWidget *SK_vp10;
    GtkWidget *SK_tv10;
    GtkTextBuffer *SK_tb10;

    GtkWidget *SK_lb1;
    GtkWidget *SK_lb2;
    GtkWidget *SK_lb3;
    GtkWidget *SK_lb31;
    GtkWidget *SK_lb32;
    GtkWidget *SK_lb33;
    GtkWidget *SK_lb34;
    GtkWidget *SK_lb35;
    GtkWidget *SK_lb4;
    GtkWidget *SK_lb50;
    GtkWidget *SK_lb5;
    GtkWidget *SK_lb6;
    GtkWidget *SK_lb7;
    GtkWidget *SK_lb8;
    GtkWidget *SK_lb9;
    GtkWidget *SK_lb10;
    GtkWidget *SK_lb51;
    GtkWidget *SK_lb61;
    GtkWidget *SK_lb71;
    GtkWidget *SK_lb81;
    GtkWidget *SK_lb91;
    GtkWidget *SK_lb101;
    
    GtkWidget *SK_save;
    GtkWidget *SK_reset;
    GtkWidget *SK_cal;

    GtkWidget *SK_srch1;

    GtkWidget *SK_return_button;

    int SK_is_add_mode;

// Task 1
    GtkTreeStore *SKts1_ts;
    GtkWidget *SKts1_sw;
    GtkWidget *SKts1_vp;
    GtkTreeView *SKts1_tv;
    GtkTreeViewColumn *SKts1c1;
    GtkCellRenderer *SKts1cr1;
    GtkTreeViewColumn *SKts1c2;
    GtkCellRenderer *SKts1cr2;
    GtkTreeViewColumn *SKts1c3;
    GtkCellRenderer *SKts1cr3;
    GtkTreeViewColumn *SKts1c4;
    GtkCellRenderer *SKts1cr4;
    GtkTreeViewColumn *SKts1c5;
    GtkCellRenderer *SKts1cr5;
    GtkTreeViewColumn *SKts1c6;
    GtkCellRenderer *SKts1cr6;
    GtkTreeSelection *select_SKts1;
    
    GtkWidget *SKts1_add;
    GtkWidget *SKts1_srch;
    GtkWidget *SKts1_del;
    GtkWidget *SKts1_edt;

//
// Task 2
    GtkTreeStore *SKts2_ts;
    GtkWidget *SKts2_sw;
    GtkWidget *SKts2_vp;
    GtkTreeView *SKts2_tv;
    GtkTreeViewColumn *SKts2c1;
    GtkCellRenderer *SKts2cr1;
    GtkTreeViewColumn *SKts2c2;
    GtkCellRenderer *SKts2cr2;
    GtkTreeViewColumn *SKts2c3;
    GtkCellRenderer *SKts2cr3;
    GtkTreeViewColumn *SKts2c4;
    GtkCellRenderer *SKts2cr4;
    GtkTreeViewColumn *SKts2c5;
    GtkCellRenderer *SKts2cr5;
    GtkTreeViewColumn *SKts2c6;
    GtkCellRenderer *SKts2cr6;
    GtkTreeSelection *select_SKts2;
    
    GtkWidget *SKts2_cf;
    GtkWidget *SKts2_srch;

//
// Task 3
    GtkTreeStore *SKts3_ts;
    GtkWidget *SKts3_sw;
    GtkWidget *SKts3_vp;
    GtkTreeView *SKts3_tv;
    GtkTreeViewColumn *SKts3c1;
    GtkCellRenderer *SKts3cr1;
    GtkTreeViewColumn *SKts3c2;
    GtkCellRenderer *SKts3cr2;
    GtkTreeViewColumn *SKts3c3;
    GtkCellRenderer *SKts3cr3;
    GtkTreeViewColumn *SKts3c4;
    GtkCellRenderer *SKts3cr4;
    GtkTreeViewColumn *SKts3c5;
    GtkCellRenderer *SKts3cr5;
    GtkTreeViewColumn *SKts3c6;
    GtkCellRenderer *SKts3cr6;
    GtkTreeSelection *select_SKts3;
    
    GtkWidget *SKts3_cf;
    GtkWidget *SKts3_srch;

//

    int SK_is_ts,SK_is_edit_mode;

HoKhau*   curHK, *curHKts, *curHKts2;
NhanKhau* curNK, *curNKts, *curNKts2;
dsSuKien* curSK, *curSKts, *curSKts2;
Kho able;

nguoiquanly dangdangnhap;

void login_screen();
void log_out_clicked(GtkButton *b);
void main_screen();
void import_button_clicked(GtkButton *b);
void add_button_clicked(GtkButton *b);
void search_button_clicked(GtkButton *b);

//ham cua Hoanh tu day tro len

void on_NK_return_button_clicked(GtkButton *b);

//ham cua Hoanh tu day tro xuong
void nhan_khau_screen();
void nhan_khau_clicked(GtkButton *b);
void nha_van_hoa_clicked(GtkButton* b);
void options_screen();
GtkWidget *spinner;
GtkWidget *log_out_button;


//Nhung ham dung chung cho ca 2 ben


void on_date1_changed(GtkTextBuffer *tb){

}

void on_date2_changed(GtkTextBuffer *tb){
    
}

void on_date3_changed(GtkTextBuffer *tb){
    
}

void remove_tree_all(GtkTreeView *tv,GtkTreeStore **ts) {
  GtkTreeModel *model;
  GtkTreeIter  iter;

  model = gtk_tree_view_get_model(GTK_TREE_VIEW(tv));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return;
  }
  
  gtk_tree_store_clear(*ts);
}

int findSKTree(GtkTreeModel *model,GtkTreeIter iter,GtkTreeSelection *srch,int col,int level,int *ID){
  char* text;
  GtkTreeIter iterChild;
  if(srch==NULL){
    return 0;
  }
  for(;1;){
    gtk_tree_model_get(model, &iter, col, &text,  -1);
    if (gtk_tree_selection_path_is_selected(srch,gtk_tree_model_get_path(model,&iter))){
        if(level==0){
            *ID=atoi(text);
        }
        return 1;
    }
    if(gtk_tree_model_iter_has_child(model,&iter)){
        gtk_tree_model_iter_children(model,&iterChild,&iter);
        if(findSKTree(model,iterChild,srch,col,level+1,ID)){
            *ID=atoi(text);
            return 1;
        }
    }

    if(!gtk_tree_model_iter_next(model,&iter)) return 0;
  }
}

int findHKnNKTree(GtkTreeModel *model,GtkTreeIter iter,GtkTreeSelection *srch,int col,int level,char **dc,char **ten){
  char* text;
  GtkTreeIter iterChild;
  if(srch==NULL){
    return 0;
  }
  for(;1;){
    gtk_tree_model_get(model, &iter, col, &text,  -1);
    if (gtk_tree_selection_path_is_selected(srch,gtk_tree_model_get_path(model,&iter))){
        if(level==0){
            *dc=text;
            if(gtk_tree_model_iter_has_child(model,&iter)){
                gtk_tree_model_iter_children(model,&iterChild,&iter);
                gtk_tree_model_get(model, &iterChild, col, ten,  -1);
                printf("Found %s %s\n",*dc,*ten );
            }
            else{
                *ten[0]='\0';
            }
        }
        else gtk_tree_model_get(model, &iter, col, ten,  -1);
        NK_is_NK=level;
        return 1;
    }
    if(gtk_tree_model_iter_has_child(model,&iter)){
        gtk_tree_model_iter_children(model,&iterChild,&iter);
        if(findHKnNKTree(model,iterChild,srch,col,level+1,dc,ten)){
            *dc=text;
            printf("Found %s %s\n",*dc,*ten );
            return 1;
        }
    }

    if(!gtk_tree_model_iter_next(model,&iter)) return 0;
  }
}

int findRowTree(GtkTreeModel *model,GtkTreeIter iter,const char *srch,int col,GtkTreeView **tv){
  const char* text;
  GtkTreeIter iterChild;
  GtkTreePath *path;
  for(;1;){
    gtk_tree_model_get(model, &iter, col, &text,  -1);
    if (strncasecmp(text,srch,strlen(srch))==0){
      path=gtk_tree_model_get_path(model,&iter);
      gtk_tree_view_expand_to_path(*tv,path);
      gtk_tree_view_scroll_to_cell(*tv,path,NULL,TRUE,0.0,0.0);

      gtk_tree_view_set_cursor_on_cell(*tv,path,NULL,NULL,FALSE);
      return 1;
    }
    if(gtk_tree_model_iter_has_child(model,&iter)){
      gtk_tree_model_iter_children(model,&iterChild,&iter);
      if(findRowTree(model,iterChild,srch,col,tv)) return 1;
    }

    if(!gtk_tree_model_iter_next(model,&iter)) return 0;
  }
}

void search_on_tree(char* text,GtkTreeView **tv,int num){
    int i;
  GtkTreeIter iter;
  GtkTreeModel *model= gtk_tree_view_get_model(*tv);
  if(strlen(text)==0) return;
  if(gtk_tree_model_get_iter_first(model,&iter)==FALSE) return;
  for(i=0;i<num;++i){
    if(findRowTree(model,iter,text,i,tv)) break;
  }
}

void on_search_tree_changed(GtkSearchEntry *s,GtkTreeView **tv,int num){
  int i;
  GtkTreeIter iter;
  GtkTreeModel *model= gtk_tree_view_get_model(*tv);
  const char *text=gtk_entry_get_text(GTK_ENTRY(s));
  if(strlen(text)==0) return;
  if(gtk_tree_model_get_iter_first(model,&iter)==FALSE) return;
  for(i=0;i<num;++i){
    if(findRowTree(model,iter,text,i,tv)) break;
  }
  
}

void set_GC_tree(GtkTreeStore **gc,GhiChu* GC){
    char s[20];
    GtkTreeIter iter;
    for(;GC!=NULL;GC=GC->nextGC){
        gtk_tree_store_append(*gc, &iter, NULL);          //"NULL" is the father of "iter"
        date_to_string(GC->ngay,s);
        gtk_tree_store_set(*gc, &iter, 0, s, -1);
        gtk_tree_store_set(*gc, &iter, 1, GC->noi_dung, -1);
    }
}

void set_HK_tree(GtkTreeStore **hk){
    GtkTreeIter iter,iterChild;
    HoKhau* HK;
    NhanKhau *NK;
    char s[20];
    for(HK=allHK;HK!=NULL;HK=HK->nextHK){
        gtk_tree_store_append(*hk, &iter, NULL);          //"NULL" is the father of "iter"
        int_to_string(HK->ID,s);
        gtk_tree_store_set(*hk, &iter, 0, s, -1);
        gtk_tree_store_set(*hk, &iter, 1, HK->dc, -1);
        for(NK=HK->NK;NK!=NULL;NK=NK->nextNK){
            gtk_tree_store_append(*hk, &iterChild, &iter);          //"NULL" is the father of "iter"
            gtk_tree_store_set(*hk, &iterChild, 0, "", -1);
            gtk_tree_store_set(*hk, &iterChild, 1, NK->Ten, -1);
        }
    }
}

void set_SK_tree(GtkTreeStore **sk,dsSuKien* SK,int choice){
    GtkTreeIter iter;
    char s[200],t[40];

    if(SK==NULL) return;
    set_SK_tree(sk,SK->leftSK,choice);
    if(choice==2||SK->su_kien_to_chuc->xet_duyet==choice){
        gtk_tree_store_append(*sk, &iter, NULL);          //"NULL" is the father of "iter"
        int_to_string(SK->ID,s);
        gtk_tree_store_set(*sk, &iter, 0, s, -1);
        gtk_tree_store_set(*sk, &iter, 1, SK->su_kien_to_chuc->ten_su_kien, -1);
        gtk_tree_store_set(*sk, &iter, 2, SK->nguoi_to_chuc->Ten, -1);
        
        strcpy(s,"Tu ");
        time_to_string(SK->su_kien_to_chuc->start,t);
        strcat(s,t);
        strcat(s," den ");
        time_to_string(SK->su_kien_to_chuc->end,t);
        strcat(s,t);

        gtk_tree_store_set(*sk, &iter, 3, s, -1);
        
        s[0]='\0';
        if(SK->su_kien_to_chuc->do_muon.phong>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.phong,t);
            strcat(s,t);
            strcat(s,"phong, ");
        }
        if(SK->su_kien_to_chuc->do_muon.ban>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.ban,t);
            strcat(s,t);
            strcat(s,"ban, ");
        }
        if(SK->su_kien_to_chuc->do_muon.ghe>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.ghe,t);
            strcat(s,t);
            strcat(s,"ghe, ");
        }
        if(SK->su_kien_to_chuc->do_muon.loa>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.loa,t);
            strcat(s,t);
            strcat(s,"loa, ");
        }
        if(SK->su_kien_to_chuc->do_muon.dai>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.dai,t);
            strcat(s,t);
            strcat(s,"dai, ");
        }
        if(SK->su_kien_to_chuc->do_muon.man_hinh>0){
            int_to_string(SK->su_kien_to_chuc->do_muon.man_hinh,t);
            strcat(s,t);
            strcat(s,"man hinh, ");
        }
        if(strlen(s)>0) s[strlen(s)-2]='\0';

        gtk_tree_store_set(*sk, &iter, 4, s, -1);
    }
    if(choice==2){
        if(SK->su_kien_to_chuc->xet_duyet==0){
            gtk_tree_store_set(*sk, &iter, 5, "Chua duoc duyet", -1);
        }
        else if(SK->su_kien_to_chuc->xet_duyet==1){
            gtk_tree_store_set(*sk, &iter, 5, "Duoc duyet", -1);
        }
        else{
            gtk_tree_store_set(*sk, &iter, 5, "Da thanh toan", -1);
        }
    }
    
    set_SK_tree(sk,SK->rightSK,choice);

}

//het

//Su kien bat dau tu day
void show_SK_edit(){
    SK_is_edit_mode=1;
    gtk_widget_show(SK_fix1);
    gtk_widget_hide(SK_fix2);
    gtk_widget_hide(SK_fix3);

    gtk_widget_hide(SKts1_cg);
    gtk_widget_show(SKts2_cg);
    gtk_widget_show(SKts3_cg);

    gtk_widget_show(SK_lb1);
    gtk_widget_show(SK_sw1);
    gtk_widget_show(SK_lb2);
    gtk_widget_show(SK_sw2);
    if(SK_is_add_mode==1){
        gtk_widget_hide(SK_lb3);
        gtk_widget_hide(SK_lb31);
        gtk_widget_hide(SK_lb32);
        gtk_widget_hide(SK_lb33);
        gtk_widget_hide(SK_lb34);
        gtk_widget_hide(SK_lb35);
        gtk_widget_hide(SK_sw31);
        gtk_widget_hide(SK_sw32);
        gtk_widget_hide(SK_sw33);
        gtk_widget_hide(SK_sw34);
        gtk_widget_hide(SK_sw35);
        gtk_widget_hide(SK_lb4);
        gtk_widget_hide(SK_sw41);
        gtk_widget_hide(SK_sw42);
        gtk_widget_hide(SK_sw43);
        gtk_widget_hide(SK_sw44);
        gtk_widget_hide(SK_sw45);
        gtk_widget_hide(SK_lb50);
        gtk_widget_hide(SK_lb5);
        gtk_widget_hide(SK_lb6);
        gtk_widget_hide(SK_lb7);
        gtk_widget_hide(SK_lb8);
        gtk_widget_hide(SK_lb9);
        gtk_widget_hide(SK_lb10);
        gtk_widget_hide(SK_lb51);
        gtk_widget_hide(SK_lb61);
        gtk_widget_hide(SK_lb71);
        gtk_widget_hide(SK_lb81);
        gtk_widget_hide(SK_lb91);
        gtk_widget_hide(SK_lb101);
        gtk_widget_hide(SK_sw5);
        gtk_widget_hide(SK_sw6);
        gtk_widget_hide(SK_sw7);
        gtk_widget_hide(SK_sw8);
        gtk_widget_hide(SK_sw9);
        gtk_widget_hide(SK_sw10);
    }
    else{
        gtk_widget_show(SK_lb3);
        gtk_widget_show(SK_lb31);
        gtk_widget_show(SK_lb32);
        gtk_widget_show(SK_lb33);
        gtk_widget_show(SK_lb34);
        gtk_widget_show(SK_lb35);
        gtk_widget_show(SK_sw31);
        gtk_widget_show(SK_sw32);
        gtk_widget_show(SK_sw33);
        gtk_widget_show(SK_sw34);
        gtk_widget_show(SK_sw35);
        gtk_widget_show(SK_lb4);
        gtk_widget_show(SK_sw41);
        gtk_widget_show(SK_sw42);
        gtk_widget_show(SK_sw43);
        gtk_widget_show(SK_sw44);
        gtk_widget_show(SK_sw45);
        gtk_widget_show(SK_lb50);
        gtk_widget_show(SK_lb5);
        gtk_widget_show(SK_lb6);
        gtk_widget_show(SK_lb7);
        gtk_widget_show(SK_lb8);
        gtk_widget_show(SK_lb9);
        gtk_widget_show(SK_lb10);
        gtk_widget_show(SK_lb51);
        gtk_widget_show(SK_lb61);
        gtk_widget_show(SK_lb71);
        gtk_widget_show(SK_lb81);
        gtk_widget_show(SK_lb91);
        gtk_widget_show(SK_lb101);
        gtk_widget_show(SK_sw5);
        gtk_widget_show(SK_sw6);
        gtk_widget_show(SK_sw7);
        gtk_widget_show(SK_sw8);
        gtk_widget_show(SK_sw9);
        gtk_widget_show(SK_sw10);
    }
    gtk_widget_show(SK_save);
    gtk_widget_show(SK_reset);
    gtk_widget_show(SK_cal);
    gtk_widget_show(SK_srch1);

    gtk_widget_hide(SKts1_sw);
    gtk_widget_hide(SKts1_add);
    gtk_widget_hide(SKts1_srch);
    gtk_widget_hide(SKts1_add);
    gtk_widget_hide(SKts1_srch);
    gtk_widget_hide(SKts1_del);
    gtk_widget_hide(SKts1_edt);
    

}

void show_SK_opt(){
    SK_is_edit_mode=0;
    SK_is_add_mode=0;
    gtk_widget_show(SKts1_sw);
    gtk_widget_show(SKts1_add);
    gtk_widget_show(SKts1_srch);
    gtk_widget_hide(SKts1_edt);
    gtk_widget_hide(SKts1_del);
    

    gtk_widget_show(SK_fix1);
    gtk_widget_hide(SK_fix2);
    gtk_widget_hide(SK_fix3);
    gtk_widget_hide(SKts1_cg);
    gtk_widget_show(SKts2_cg);
    gtk_widget_show(SKts3_cg);

    gtk_widget_hide(SK_save);
    gtk_widget_hide(SK_reset);
    gtk_widget_hide(SK_cal);
    gtk_widget_hide(SK_srch1);

    gtk_widget_hide(SK_lb1);
    gtk_widget_hide(SK_sw1);
    gtk_widget_hide(SK_lb2);
    gtk_widget_hide(SK_sw2);
    gtk_widget_hide(SK_lb3);
    gtk_widget_hide(SK_lb31);
    gtk_widget_hide(SK_lb32);
    gtk_widget_hide(SK_lb33);
    gtk_widget_hide(SK_lb34);
    gtk_widget_hide(SK_lb35);
    gtk_widget_hide(SK_sw31);
    gtk_widget_hide(SK_sw32);
    gtk_widget_hide(SK_sw33);
    gtk_widget_hide(SK_sw34);
    gtk_widget_hide(SK_sw35);
    gtk_widget_hide(SK_lb4);
    gtk_widget_hide(SK_sw41);
    gtk_widget_hide(SK_sw42);
    gtk_widget_hide(SK_sw43);
    gtk_widget_hide(SK_sw44);
    gtk_widget_hide(SK_sw45);
    gtk_widget_hide(SK_lb50);
    gtk_widget_hide(SK_lb5);
    gtk_widget_hide(SK_lb6);
    gtk_widget_hide(SK_lb7);
    gtk_widget_hide(SK_lb8);
    gtk_widget_hide(SK_lb9);
    gtk_widget_hide(SK_lb10);
    gtk_widget_hide(SK_lb51);
    gtk_widget_hide(SK_lb61);
    gtk_widget_hide(SK_lb71);
    gtk_widget_hide(SK_lb81);
    gtk_widget_hide(SK_lb91);
    gtk_widget_hide(SK_lb101);
    gtk_widget_hide(SK_sw5);
    gtk_widget_hide(SK_sw6);
    gtk_widget_hide(SK_sw7);
    gtk_widget_hide(SK_sw8);
    gtk_widget_hide(SK_sw9);
    gtk_widget_hide(SK_sw10);
}

int get_SK_buffer(SuKien* SK){
    GtkTextIter begin,end;
    char *text;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb2),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb2),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb2),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    strcpy(SK->ten_su_kien,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb31),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb31),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb31),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->start.gio=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb32),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb32),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb32),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->start.phut=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb33),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb33),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb33),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->start.ngay=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb34),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb34),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb34),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->start.thang=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb35),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb35),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb35),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->start.nam=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb41),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb41),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb41),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->end.gio=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb42),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb42),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb42),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->end.phut=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb43),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb43),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb43),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->end.ngay=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb44),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb44),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb44),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->end.thang=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb45),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb45),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb45),&begin,&end,TRUE);
    if(strlen(text)==0) return 0;
    SK->end.nam=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb5),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb5),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb5),&begin,&end,TRUE);
    SK->do_muon.phong=atoi(text);
    if(SK->do_muon.phong>able.phong) return 0;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb6),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb6),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb6),&begin,&end,TRUE);
    SK->do_muon.ban=atoi(text);
    if(SK->do_muon.ban>able.ban) return 0;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb7),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb7),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb7),&begin,&end,TRUE);
    SK->do_muon.ghe=atoi(text);
    if(SK->do_muon.ghe>able.ghe) return 0;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb8),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb8),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb8),&begin,&end,TRUE);
    SK->do_muon.loa=atoi(text);
    if(SK->do_muon.loa>able.loa) return 0;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb9),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb9),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb9),&begin,&end,TRUE);
    SK->do_muon.dai=atoi(text);
    if(SK->do_muon.dai>able.dai) return 0;

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb10),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb10),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb10),&begin,&end,TRUE);
    SK->do_muon.man_hinh=atoi(text);
    if(SK->do_muon.man_hinh>able.man_hinh) return 0;

    return 1;
}

void set_SK_text(SuKien *SK){
    gtk_label_set_text(GTK_LABEL(SK_lb51),"/");
    gtk_label_set_text(GTK_LABEL(SK_lb61),"/");
    gtk_label_set_text(GTK_LABEL(SK_lb71),"/");
    gtk_label_set_text(GTK_LABEL(SK_lb81),"/");
    gtk_label_set_text(GTK_LABEL(SK_lb91),"/");
    gtk_label_set_text(GTK_LABEL(SK_lb101),"/");
    if(SK!=NULL){
        char s[20];
        gtk_text_buffer_set_text(SK_tb2,SK->ten_su_kien,(gint)-1);

        int_to_string(SK->start.gio,s);
        gtk_text_buffer_set_text(SK_tb31,s,(gint)-1);
        int_to_string(SK->start.phut,s);
        gtk_text_buffer_set_text(SK_tb32,s,(gint)-1);
        int_to_string(SK->start.ngay,s);
        gtk_text_buffer_set_text(SK_tb33,s,(gint)-1);
        int_to_string(SK->start.thang,s);
        gtk_text_buffer_set_text(SK_tb34,s,(gint)-1);
        int_to_string(SK->start.nam,s);
        gtk_text_buffer_set_text(SK_tb35,s,(gint)-1);

        int_to_string(SK->end.gio,s);
        gtk_text_buffer_set_text(SK_tb41,s,(gint)-1);
        int_to_string(SK->end.phut,s);
        gtk_text_buffer_set_text(SK_tb42,s,(gint)-1);
        int_to_string(SK->end.ngay,s);
        gtk_text_buffer_set_text(SK_tb43,s,(gint)-1);
        int_to_string(SK->end.thang,s);
        gtk_text_buffer_set_text(SK_tb44,s,(gint)-1);
        int_to_string(SK->end.nam,s);
        gtk_text_buffer_set_text(SK_tb45,s,(gint)-1);

        int_to_string(SK->do_muon.phong,s);
        gtk_text_buffer_set_text(SK_tb5,s,(gint)-1);
        int_to_string(SK->do_muon.ban,s);
        gtk_text_buffer_set_text(SK_tb6,s,(gint)-1);
        int_to_string(SK->do_muon.ghe,s);
        gtk_text_buffer_set_text(SK_tb7,s,(gint)-1);
        int_to_string(SK->do_muon.loa,s);
        gtk_text_buffer_set_text(SK_tb8,s,(gint)-1);
        int_to_string(SK->do_muon.dai,s);
        gtk_text_buffer_set_text(SK_tb9,s,(gint)-1);
        int_to_string(SK->do_muon.man_hinh,s);
        gtk_text_buffer_set_text(SK_tb10,s,(gint)-1);
    }
    else{
        gtk_text_buffer_set_text(SK_tb2,"",(gint)-1);

        gtk_text_buffer_set_text(SK_tb31,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb32,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb33,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb34,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb35,"",(gint)-1);

        gtk_text_buffer_set_text(SK_tb41,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb42,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb43,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb44,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb45,"",(gint)-1);

        gtk_text_buffer_set_text(SK_tb5,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb6,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb7,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb8,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb9,"",(gint)-1);
        gtk_text_buffer_set_text(SK_tb10,"",(gint)-1);
    }
}

int nowSelectSKts(HoKhau **HK,NhanKhau **NK,dsSuKien **SK,GtkTreeView **tv,GtkTreeSelection **sl){
    GtkTreeModel *model= gtk_tree_view_get_model(*tv);
    GtkTreeIter iter;
    int ID;
    
    if(gtk_tree_model_get_iter_first(model,&iter)==FALSE){
        return 0;
    }
    else if(findSKTree(model,iter,*sl,0,0,&ID)){
        *SK=dsSuKiensearchID(allSK,ID);
        *NK=(*SK)->nguoi_to_chuc;
        *HK=HoKhausearchNhanKhau(*NK);
        return 1;
    }
    else return 0;
}

void renew_ts1(){
    show_SK_opt();

    curHKts=NULL;
    curNKts=NULL;
    curSKts=NULL;

    set_SK_text(NULL);
    remove_tree_all(SKts1_tv,&SKts1_ts);
    remove_tree_all(SK_tv1,&SK1_ts);
    set_SK_tree(&SKts1_ts,allSK,2);

    SK_is_ts=1;
}


void renew_ts2(){
    gtk_widget_show(SK_fix2);
    gtk_widget_hide(SK_fix1);
    gtk_widget_hide(SK_fix3);
    gtk_widget_hide(SKts2_cg);
    gtk_widget_show(SKts1_cg);
    gtk_widget_show(SKts3_cg);
    gtk_widget_hide(SKts2_cf);

    curHKts=NULL;
    curNKts=NULL;
    curSKts=NULL;

    remove_tree_all(SKts2_tv,&SKts2_ts);
    set_SK_tree(&SKts2_ts,allSK,0);
    SK_is_ts=2;
}

void renew_ts3(){
    gtk_widget_show(SK_fix3);
    gtk_widget_hide(SK_fix1);
    gtk_widget_hide(SK_fix2);
    gtk_widget_hide(SKts3_cg);
    gtk_widget_show(SKts1_cg);
    gtk_widget_show(SKts2_cg);
    gtk_widget_hide(SKts3_cf);

    curHKts=NULL;
    curNKts=NULL;
    curSKts=NULL;

    remove_tree_all(SKts3_tv,&SKts3_ts);
    set_SK_tree(&SKts3_ts,allSK,1);
    SK_is_ts=3;
}

void on_SKts1_cg_clicked(GtkButton* b){
    renew_ts1();
}

void on_SKts2_cg_clicked(GtkButton* b){
    renew_ts2();
}

void on_SKts3_cg_clicked(GtkButton* b){
    renew_ts3();
}


// task1




void on_select_SKts1_changed(){
    if(nowSelectSKts(&curHKts,&curNKts,&curSKts,&SKts1_tv,&select_SKts1)){
        gtk_widget_show(SKts1_del);
        gtk_widget_show(SKts1_edt);
    }
}

void on_SKts1_add_clicked(GtkButton* b){
    SK_is_add_mode=1;
    show_SK_edit();
    remove_tree_all(SK_tv1,&SK1_ts);
    set_HK_tree(&SK1_ts);
    set_SK_text(NULL);
}

void on_SKts1_del_clicked(GtkButton* b){
    deletedsSuKien(&allSK, curSKts->su_kien_to_chuc);
    renew_ts1();
}

void on_SKts1_edt_clicked(GtkButton* b){
    SK_is_add_mode=0;
    show_SK_edit();
    remove_tree_all(SK_tv1,&SK1_ts);
    set_HK_tree(&SK1_ts);
    search_on_tree(curNKts->Ten,&SK_tv1,2);
    set_SK_text(curSKts->su_kien_to_chuc);
}

void on_SKts1_srch_changed(GtkSearchEntry *s){
    on_search_tree_changed(s,&SKts1_tv,6);
}

//


// task2



void on_select_SKts2_changed(){
    if(nowSelectSKts(&curHKts,&curNKts,&curSKts,&SKts2_tv,&select_SKts2)){
        gtk_widget_show(SKts2_cf);
    }
    else if(SK_is_ts==2){
        curNKts=NULL;
        curSKts=NULL;
        curHKts=NULL;
    }
}

void on_SKts2_cf_clicked(GtkButton* b){
    curSKts->su_kien_to_chuc->xet_duyet=1;
    renew_ts2();
}

void on_SKts2_srch_changed(GtkSearchEntry *s){
    on_search_tree_changed(s,&SKts2_tv,6);
}

//

// task3



void on_select_SKts3_changed(){
    if(nowSelectSKts(&curHKts,&curNKts,&curSKts,&SKts3_tv,&select_SKts3)){
        gtk_widget_show(SKts3_cf);
    }
    else if(SK_is_ts==3){
        curNKts=NULL;
        curSKts=NULL;
        curHKts=NULL;
    }
}

void on_SKts3_cf_clicked(GtkButton* b){
    curSKts->su_kien_to_chuc->xet_duyet=2;
    renew_ts3();
}

void on_SKts3_srch_changed(GtkSearchEntry *s){
    on_search_tree_changed(s,&SKts3_tv,6);
}

//


int nowSelectSK1(HoKhau **HK,NhanKhau **NK){
    GtkTreeModel *model= gtk_tree_view_get_model(SK_tv1);
    GtkTreeIter iter;
    char *ten,*dc;
    
    if(gtk_tree_model_get_iter_first(model,&iter)==FALSE){
        return 0;
    }
    else if(findHKnNKTree(model,iter,select_SK1,1,0,&dc,&ten)){
        *HK=HoKhausearchDiaChi(dc);
        *NK=NhanKhausearchTenvaDiaChi(ten,NULL,*HK);
        return 1;
    }
    else return 0;
}

void on_select_SK1_changed(GtkTreeSelection *widget){
    HoKhau* HK;
    NhanKhau* NK;
    
    if(nowSelectSK1(&HK,&NK)){
        if(SK_is_add_mode){
            gtk_widget_show(SK_lb3);
            gtk_widget_show(SK_lb31);
            gtk_widget_show(SK_lb32);
            gtk_widget_show(SK_lb33);
            gtk_widget_show(SK_lb34);
            gtk_widget_show(SK_lb35);
            gtk_widget_show(SK_sw31);
            gtk_widget_show(SK_sw32);
            gtk_widget_show(SK_sw33);
            gtk_widget_show(SK_sw34);
            gtk_widget_show(SK_sw35);
            gtk_widget_show(SK_lb4);
            gtk_widget_show(SK_sw41);
            gtk_widget_show(SK_sw42);
            gtk_widget_show(SK_sw43);
            gtk_widget_show(SK_sw44);
            gtk_widget_show(SK_sw45);
        }
        curHK=HK;
        curNK=NK;
    }
    else {
        curHK=NULL;
        curNK=NULL;
    }
}

void on_SK_time_changed(GtkTextBuffer *t){
    GtkTextIter begin,end;
    char *text;
    Time S,E;
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb31),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb31),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb31),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    S.gio=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb32),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb32),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb32),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    S.phut=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb33),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb33),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb33),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    S.ngay=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb34),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb34),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb34),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    S.thang=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb35),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb35),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb35),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    S.nam=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb41),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb41),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb41),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    E.gio=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb42),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb42),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb42),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    E.phut=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb43),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb43),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb43),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    E.ngay=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb44),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb44),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb44),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    E.thang=atoi(text);
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb45),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(SK_tb45),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(SK_tb45),&begin,&end,TRUE);
    if(strlen(text)==0) return;
    E.nam=atoi(text);

    gtk_widget_show(SK_lb50);
    gtk_widget_show(SK_lb5);
    gtk_widget_show(SK_lb6);
    gtk_widget_show(SK_lb7);
    gtk_widget_show(SK_lb8);
    gtk_widget_show(SK_lb9);
    gtk_widget_show(SK_lb10);
    gtk_widget_show(SK_lb51);
    gtk_widget_show(SK_lb61);
    gtk_widget_show(SK_lb71);
    gtk_widget_show(SK_lb81);
    gtk_widget_show(SK_lb91);
    gtk_widget_show(SK_lb101);
    gtk_widget_show(SK_sw5);
    gtk_widget_show(SK_sw6);
    gtk_widget_show(SK_sw7);
    gtk_widget_show(SK_sw8);
    gtk_widget_show(SK_sw9);
    gtk_widget_show(SK_sw10);

    able=checkDo(allSK, allSP, S,E, curSK);
    char s[400];
    strcpy(s,"/ ");
    int_to_string(able.phong,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb51),s);
    strcpy(s,"/ ");
    int_to_string(able.ban,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb61),s);
    strcpy(s,"/ ");
    int_to_string(able.ghe,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb71),s);
    strcpy(s,"/ ");
    int_to_string(able.loa,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb81),s);
    strcpy(s,"/ ");
    int_to_string(able.dai,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb91),s);
    strcpy(s,"/ ");
    int_to_string(able.man_hinh,text);
    strcat(s,text);
    gtk_label_set_text(GTK_LABEL(SK_lb101),s);
    free(text);
}


void on_SK_save_clicked(GtkButton* b){
    SuKien* SK=NULL,a;
    if(!get_SK_buffer(&a)) return;
    if(!SK_is_add_mode){
        deletedsSuKien(&allSK,curSKts->su_kien_to_chuc);
    }
    insertSuKien(&SK,a.ten_su_kien,a.do_muon,a.start,a.end,0);
    insertdsSuKien(&allSK,curNK, SK);
    renew_ts1();
}

void on_SK_reset_clicked(GtkButton* b){
    if(SK_is_add_mode){
        set_SK_text(NULL);
        show_SK_edit();
    }
    else{
        search_on_tree(curNKts->Ten,&SK_tv1,2);
        set_SK_text(curSKts->su_kien_to_chuc);
    }
}

void on_SK_cal_clicked(GtkButton* b){
    renew_ts1();
}

void on_SK_srch1_changed(GtkSearchEntry *s){
    on_search_tree_changed(s,&SK_tv1,2);
}

void on_SK_return_button_clicked(GtkButton *b){
    gtk_widget_destroy(SK_win);
    main_screen();
}

void su_kien_screen(){
    builder = gtk_builder_new_from_file("../su_kien.glade");
    SK_win = GTK_WIDGET(gtk_builder_get_object(builder, "SK_win"));
    g_signal_connect(SK_win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    SK_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "SK_fixed"));
    gtk_builder_connect_signals(builder, NULL);
    SK_fix1 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_fix1"));
    SK_fix2 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_fix2"));
    SK_fix3 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_fix3"));
    
    SKts1_cg=GTK_WIDGET(gtk_builder_get_object(builder,"SKts1_cg"));
    g_signal_connect(SKts1_cg, "clicked", G_CALLBACK(on_SKts1_cg_clicked),NULL);

    SKts2_cg=GTK_WIDGET(gtk_builder_get_object(builder,"SKts2_cg"));
    g_signal_connect(SKts2_cg, "clicked", G_CALLBACK(on_SKts2_cg_clicked),NULL);

    SKts3_cg=GTK_WIDGET(gtk_builder_get_object(builder,"SKts3_cg"));
    g_signal_connect(SKts3_cg, "clicked", G_CALLBACK(on_SKts3_cg_clicked),NULL);



    SK_return_button=GTK_WIDGET(gtk_builder_get_object(builder,"SK_return_button"));
    g_signal_connect(SK_return_button, "clicked", G_CALLBACK(on_SK_return_button_clicked),NULL);

    SK_sw1 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw1"));
    SK_vp1 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp1"));
    SK1_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"SK1_ts"));
    SK_tv1=GTK_TREE_VIEW(gtk_builder_get_object(builder,"SK_tv1"));
    SK1c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SK1c1"));
    SK1cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SK1cr1"));
    gtk_tree_view_column_add_attribute(SK1c1, SK1cr1, "text", 0); //Attach the renderer to the column
    SK1c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SK1c2"));
    SK1cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SK1cr2"));
    gtk_tree_view_column_add_attribute(SK1c2, SK1cr2, "text", 1); //Attach the renderer to the column
    select_SK1=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_SK1"));
    g_signal_connect(select_SK1,"changed",G_CALLBACK(on_select_SK1_changed),NULL);

    SK_sw2 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw2"));
    SK_vp2 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp2"));
    SK_tv2 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv2"));
    SK_tb2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv2));

    SK_sw31 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw31"));
    SK_vp31 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp31"));
    SK_tv31 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv31"));
    SK_tb31 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv31));
    g_signal_connect(SK_tb31, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw32 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw32"));
    SK_vp32 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp32"));
    SK_tv32 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv32"));
    SK_tb32 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv32));
    g_signal_connect(SK_tb32, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw33 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw33"));
    SK_vp33 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp33"));
    SK_tv33 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv33"));
    SK_tb33 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv33));
    g_signal_connect(SK_tb33, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw34 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw34"));
    SK_vp34 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp34"));
    SK_tv34 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv34"));
    SK_tb34 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv34));
    g_signal_connect(SK_tb34, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw35 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw35"));
    SK_vp35 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp35"));
    SK_tv35 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv35"));
    SK_tb35 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv35));
    g_signal_connect(SK_tb35, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw41 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw41"));
    SK_vp41 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp41"));
    SK_tv41 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv41"));
    SK_tb41 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv41));
    g_signal_connect(SK_tb41, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw42 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw42"));
    SK_vp42 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp42"));
    SK_tv42 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv42"));
    SK_tb42 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv42));
    g_signal_connect(SK_tb42, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw43 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw43"));
    SK_vp43 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp43"));
    SK_tv43 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv43"));
    SK_tb43 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv43));
    g_signal_connect(SK_tb43, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw44 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw44"));
    SK_vp44 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp44"));
    SK_tv44 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv44"));
    SK_tb44 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv44));
    g_signal_connect(SK_tb44, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw45 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw45"));
    SK_vp45 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp45"));
    SK_tv45 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv45"));
    SK_tb45 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv45));
    g_signal_connect(SK_tb45, "changed", G_CALLBACK(on_SK_time_changed),NULL);

    SK_sw5 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw5"));
    SK_vp5 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp5"));
    SK_tv5 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv5"));
    SK_tb5 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv5));

    SK_sw6 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw6"));
    SK_vp6 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp6"));
    SK_tv6 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv6"));
    SK_tb6 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv6));

    SK_sw7 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw7"));
    SK_vp7 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp7"));
    SK_tv7 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv7"));
    SK_tb7 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv7));

    SK_sw8 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw8"));
    SK_vp8 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp8"));
    SK_tv8 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv8"));
    SK_tb8 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv8));

    SK_sw9 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw9"));
    SK_vp9 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp9"));
    SK_tv9 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv9"));
    SK_tb9 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv9));

    SK_sw10 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_sw10"));
    SK_vp10 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_vp10"));
    SK_tv10 = GTK_WIDGET(gtk_builder_get_object(builder, "SK_tv10"));
    SK_tb10 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SK_tv10));

    SK_lb1=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb1"));
    SK_lb2=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb2"));
    SK_lb3=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb3"));
    SK_lb31=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb31"));
    SK_lb32=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb32"));
    SK_lb33=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb33"));
    SK_lb34=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb34"));
    SK_lb35=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb35"));
    SK_lb4=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb4"));
    SK_lb50=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb50"));
    SK_lb5=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb5"));
    SK_lb6=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb6"));
    SK_lb7=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb7"));
    SK_lb8=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb8"));
    SK_lb9=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb9"));
    SK_lb10=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb10"));
    SK_lb51=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb51"));
    SK_lb61=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb61"));
    SK_lb71=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb71"));
    SK_lb81=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb81"));
    SK_lb91=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb91"));
    SK_lb101=GTK_WIDGET(gtk_builder_get_object(builder, "SK_lb101"));

    SK_save=GTK_WIDGET(gtk_builder_get_object(builder,"SK_save"));
    g_signal_connect(SK_save, "clicked", G_CALLBACK(on_SK_save_clicked),NULL);
    SK_reset=GTK_WIDGET(gtk_builder_get_object(builder,"SK_reset"));
    g_signal_connect(SK_reset, "clicked", G_CALLBACK(on_SK_reset_clicked),NULL);
    SK_cal=GTK_WIDGET(gtk_builder_get_object(builder,"SK_cal"));
    g_signal_connect(SK_cal, "clicked", G_CALLBACK(on_SK_cal_clicked),NULL);

    SK_srch1=GTK_WIDGET(gtk_builder_get_object(builder,"SK_srch1"));
    g_signal_connect(SK_srch1, "changed", G_CALLBACK(on_SK_srch1_changed),NULL);
    


    //task1
    SKts1_sw = GTK_WIDGET(gtk_builder_get_object(builder, "SKts1_sw"));
    SKts1_vp = GTK_WIDGET(gtk_builder_get_object(builder, "SKts1_vp"));
    SKts1_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"SKts1_ts"));
    SKts1_tv=GTK_TREE_VIEW(gtk_builder_get_object(builder,"SKts1_tv"));
    SKts1c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c1"));
    SKts1cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr1"));
    gtk_tree_view_column_add_attribute(SKts1c1, SKts1cr1, "text", 0); //Attach the renderer to the column
    SKts1c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c2"));
    SKts1cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr2"));
    gtk_tree_view_column_add_attribute(SKts1c2, SKts1cr2, "text", 1); //Attach the renderer to the column
    SKts1c3=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c3"));
    SKts1cr3=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr3"));
    gtk_tree_view_column_add_attribute(SKts1c3, SKts1cr3, "text", 2); //Attach the renderer to the column
    SKts1c4=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c4"));
    SKts1cr4=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr4"));
    gtk_tree_view_column_add_attribute(SKts1c4, SKts1cr4, "text", 3); //Attach the renderer to the column
    SKts1c5=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c5"));
    SKts1cr5=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr5"));
    gtk_tree_view_column_add_attribute(SKts1c5, SKts1cr5, "text", 4); //Attach the renderer to the column
    SKts1c6=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts1c6"));
    SKts1cr6=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts1cr6"));
    gtk_tree_view_column_add_attribute(SKts1c6, SKts1cr6, "text", 5); //Attach the renderer to the column

    select_SKts1=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_SKts1"));
    g_signal_connect(select_SKts1,"changed",G_CALLBACK(on_select_SKts1_changed),NULL);

    SKts1_add=GTK_WIDGET(gtk_builder_get_object(builder,"SKts1_add"));
    g_signal_connect(SKts1_add, "clicked", G_CALLBACK(on_SKts1_add_clicked),NULL);

    SKts1_del=GTK_WIDGET(gtk_builder_get_object(builder,"SKts1_del"));
    g_signal_connect(SKts1_del, "clicked", G_CALLBACK(on_SKts1_del_clicked),NULL);

    SKts1_edt=GTK_WIDGET(gtk_builder_get_object(builder,"SKts1_edt"));
    g_signal_connect(SKts1_edt, "clicked", G_CALLBACK(on_SKts1_edt_clicked),NULL);

    SKts1_srch=GTK_WIDGET(gtk_builder_get_object(builder,"SKts1_srch"));
    g_signal_connect(SKts1_srch, "changed", G_CALLBACK(on_SKts1_srch_changed),NULL);

    show_SK_opt();
    remove_tree_all(SKts1_tv,&SKts1_ts);
    set_SK_tree(&SKts1_ts,allSK,2);


//task2
    SKts2_sw = GTK_WIDGET(gtk_builder_get_object(builder, "SKts2_sw"));
    SKts2_vp = GTK_WIDGET(gtk_builder_get_object(builder, "SKts2_vp"));
    SKts2_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"SKts2_ts"));
    SKts2_tv=GTK_TREE_VIEW(gtk_builder_get_object(builder,"SKts2_tv"));
    SKts2c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts2c1"));
    SKts2cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts2cr1"));
    gtk_tree_view_column_add_attribute(SKts2c1, SKts2cr1, "text", 0); //Attach the renderer to the column
    SKts2c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts2c2"));
    SKts2cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts2cr2"));
    gtk_tree_view_column_add_attribute(SKts2c2, SKts2cr2, "text", 1); //Attach the renderer to the column
    SKts2c3=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts2c3"));
    SKts2cr3=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts2cr3"));
    gtk_tree_view_column_add_attribute(SKts2c3, SKts2cr3, "text", 2); //Attach the renderer to the column
    SKts2c4=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts2c4"));
    SKts2cr4=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts2cr4"));
    gtk_tree_view_column_add_attribute(SKts2c4, SKts2cr4, "text", 3); //Attach the renderer to the column
    SKts2c5=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts2c5"));
    SKts2cr5=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts2cr5"));
    gtk_tree_view_column_add_attribute(SKts2c5, SKts2cr5, "text", 4); //Attach the renderer to the column

    select_SKts2=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_SKts2"));
    g_signal_connect(select_SKts2,"changed",G_CALLBACK(on_select_SKts2_changed),NULL);

    SKts2_cf=GTK_WIDGET(gtk_builder_get_object(builder,"SKts2_cf"));
    g_signal_connect(SKts2_cf, "clicked", G_CALLBACK(on_SKts2_cf_clicked),NULL);

    SKts2_srch=GTK_WIDGET(gtk_builder_get_object(builder,"SKts2_srch"));
    g_signal_connect(SKts2_srch, "changed", G_CALLBACK(on_SKts2_srch_changed),NULL);

//task3
    SKts3_sw = GTK_WIDGET(gtk_builder_get_object(builder, "SKts3_sw"));
    SKts3_vp = GTK_WIDGET(gtk_builder_get_object(builder, "SKts3_vp"));
    SKts3_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"SKts3_ts"));
    SKts3_tv=GTK_TREE_VIEW(gtk_builder_get_object(builder,"SKts3_tv"));
    SKts3c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts3c1"));
    SKts3cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts3cr1"));
    gtk_tree_view_column_add_attribute(SKts3c1, SKts3cr1, "text", 0); //Attach the renderer to the column
    SKts3c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts3c2"));
    SKts3cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts3cr2"));
    gtk_tree_view_column_add_attribute(SKts3c2, SKts3cr2, "text", 1); //Attach the renderer to the column
    SKts3c3=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts3c3"));
    SKts3cr3=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts3cr3"));
    gtk_tree_view_column_add_attribute(SKts3c3, SKts3cr3, "text", 2); //Attach the renderer to the column
    SKts3c4=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts3c4"));
    SKts3cr4=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts3cr4"));
    gtk_tree_view_column_add_attribute(SKts3c4, SKts3cr4, "text", 3); //Attach the renderer to the column
    SKts3c5=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"SKts3c5"));
    SKts3cr5=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"SKts3cr5"));
    gtk_tree_view_column_add_attribute(SKts3c5, SKts3cr5, "text", 4); //Attach the renderer to the column

    select_SKts3=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_SKts3"));
    g_signal_connect(select_SKts3,"changed",G_CALLBACK(on_select_SKts3_changed),NULL);

    SKts3_cf=GTK_WIDGET(gtk_builder_get_object(builder,"SKts3_cf"));
    g_signal_connect(SKts3_cf, "clicked", G_CALLBACK(on_SKts3_cf_clicked),NULL);

    SKts3_srch=GTK_WIDGET(gtk_builder_get_object(builder,"SKts3_srch"));
    g_signal_connect(SKts3_srch, "changed", G_CALLBACK(on_SKts3_srch_changed),NULL);

    renew_ts1();

    gtk_widget_show(SK_win);
    gtk_main();
}


//het

void nhan_khau_clicked(GtkButton *b){
    gtk_widget_destroy(window_main);
    nhan_khau_screen();
}

void nha_van_hoa_clicked(GtkButton* b){
    if(strcmp(dangdangnhap.username,"admin") != 0) return; // thg khac admin ko duoc truy cap vao day
    else {
        gtk_widget_destroy(window_main);
        su_kien_screen();
    }
}


//Nhan khau
void show_NK_opt(){
    gtk_widget_show(HK_sw1);
    gtk_widget_show(HK_sw2);
    gtk_widget_show(NK_sw16);
    gtk_widget_show(NK_ghi_chu_label);

    gtk_widget_show(NK_add);
    gtk_widget_show(HK_add);
    gtk_widget_show(NK_del);
    gtk_widget_show(HK_del);
    gtk_widget_show(NK_adj);
    gtk_widget_show(NK_top);
    gtk_widget_hide(NK_cal);
    gtk_widget_hide(NK_save);
    gtk_widget_hide(NK_qd);
    gtk_widget_hide(NK_cqd);
    gtk_widget_hide(NK_ms);
    gtk_widget_hide(NK_cms);
    gtk_widget_hide(NK_swtt1);
    gtk_widget_hide(NK_swtt2);
    gtk_widget_hide(NK_swtt3);
    
    NK_is_edit_mode=0;
    NK_is_add_mode=0;
}

void show_NK_no_sel(){
    gtk_widget_show(HK_sw1);
    gtk_widget_show(HK_sw2);
    gtk_widget_show(NK_sw16);
    gtk_widget_show(NK_ghi_chu_label);

    gtk_widget_hide(NK_add);
    gtk_widget_show(HK_add);
    gtk_widget_hide(NK_del);
    gtk_widget_hide(HK_del);
    gtk_widget_hide(NK_adj);
    gtk_widget_hide(NK_top);
    gtk_widget_hide(NK_cal);
    gtk_widget_hide(NK_save);
    gtk_widget_hide(NK_qd);
    gtk_widget_hide(NK_cqd);
    gtk_widget_hide(NK_ms);
    gtk_widget_hide(NK_cms);
    gtk_widget_hide(NK_swtt1);
    gtk_widget_hide(NK_swtt2);
    gtk_widget_hide(NK_swtt3);

    NK_is_edit_mode=0;
    NK_is_add_mode=0;
}

void show_NK_edit(){
    gtk_widget_hide(HK_sw1);
    gtk_widget_hide(HK_sw2);
    gtk_widget_hide(NK_sw16);
    gtk_widget_hide(NK_ghi_chu_label);

    gtk_widget_hide(NK_add);
    gtk_widget_hide(HK_add);
    gtk_widget_hide(NK_del);
    gtk_widget_hide(HK_del);
    gtk_widget_hide(NK_adj);
    gtk_widget_hide(NK_top);
    gtk_widget_show(NK_cal);
    gtk_widget_show(NK_save);
    gtk_widget_hide(NK_cms);
    if(NK_is_add_mode==1){
        gtk_widget_show(NK_cms);
        att=0;
    }
    else{
        att=curNK->tt;
        if(att==1) {
            gtk_widget_show(NK_qd);
            gtk_widget_show(NK_swtt1);
            gtk_widget_show(NK_swtt2);
            gtk_widget_show(NK_swtt3);
            gtk_text_buffer_set_text(NK_tbtt1,"",(gint)-1);
            gtk_text_buffer_set_text(NK_tbtt2,"",(gint)-1);
            gtk_text_buffer_set_text(NK_tbtt3,"",(gint)-1);
        }
        else gtk_widget_show(NK_cqd);
    }
    
    
    NK_is_edit_mode=1;
}

void get_NK_buffer(NhanKhau *a){
    GtkTextIter begin,end;
    char *text;
    
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb1),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb1),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb1),&begin,&end,TRUE);
    strcpy(a->Ten,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb2),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb2),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb2),&begin,&end,TRUE);
    strcpy(a->BiDanh,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb3),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb3),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb3),&begin,&end,TRUE);
    strcpy(a->gioi_tinh,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb4),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb4),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb4),&begin,&end,TRUE);
    a->tuoi=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb51),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb51),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb51),&begin,&end,TRUE);
    a->ngay_sinh.ngay=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb52),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb52),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb52),&begin,&end,TRUE);
    a->ngay_sinh.thang=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb53),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb53),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb53),&begin,&end,TRUE);
    a->ngay_sinh.nam=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb6),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb6),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb6),&begin,&end,TRUE);
    strcpy(a->noi_sinh,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb7),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb7),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb7),&begin,&end,TRUE);
    strcpy(a->que_quan,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb8),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb8),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb8),&begin,&end,TRUE);
    strcpy(a->dan_toc,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb9),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb9),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb9),&begin,&end,TRUE);
    strcpy(a->nghe_nghiep,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb10),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb10),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb10),&begin,&end,TRUE);
    strcpy(a->noi_lam_viec,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb11),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb11),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb11),&begin,&end,TRUE);
    strcpy(a->CMND,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb121),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb121),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb121),&begin,&end,TRUE);
    a->ngay_cap.ngay=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb122),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb122),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb122),&begin,&end,TRUE);
    a->ngay_cap.thang=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb123),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb123),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb123),&begin,&end,TRUE);
    a->ngay_cap.nam=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb13),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb13),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb13),&begin,&end,TRUE);
    strcpy(a->noi_cap,text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb141),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb141),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb141),&begin,&end,TRUE);
    a->dang_ki.ngay=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb142),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb142),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb142),&begin,&end,TRUE);
    a->dang_ki.thang=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb143),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb143),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb143),&begin,&end,TRUE);
    a->dang_ki.nam=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb15),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tb15),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tb15),&begin,&end,TRUE);
    strcpy(a->quan_he,text);

}

void set_NK_text(NhanKhau *NK){
    if(NK!=NULL){
        char s[20];
        gtk_text_buffer_set_text(NK_tb1,NK->Ten,(gint)-1);
        gtk_text_buffer_set_text(NK_tb2,NK->BiDanh,(gint)-1);
        gtk_text_buffer_set_text(NK_tb3,NK->gioi_tinh,(gint)-1);
        int_to_string(NK->tuoi,s);
        gtk_text_buffer_set_text(NK_tb4,s,(gint)-1);
        int_to_string(NK->ngay_sinh.ngay,s);
        gtk_text_buffer_set_text(NK_tb51,s,(gint)-1);
        int_to_string(NK->ngay_sinh.thang,s);
        gtk_text_buffer_set_text(NK_tb52,s,(gint)-1);
        int_to_string(NK->ngay_sinh.nam,s);
        gtk_text_buffer_set_text(NK_tb53,s,(gint)-1);
        gtk_text_buffer_set_text(NK_tb6,NK->noi_sinh,(gint)-1);
        gtk_text_buffer_set_text(NK_tb7,NK->que_quan,(gint)-1);
        gtk_text_buffer_set_text(NK_tb8,NK->dan_toc,(gint)-1);
        gtk_text_buffer_set_text(NK_tb9,NK->nghe_nghiep,(gint)-1);
        gtk_text_buffer_set_text(NK_tb10,NK->noi_lam_viec,(gint)-1);
        gtk_text_buffer_set_text(NK_tb11,NK->CMND,(gint)-1);
        int_to_string(NK->ngay_cap.ngay,s);
        gtk_text_buffer_set_text(NK_tb121,s,(gint)-1);
        int_to_string(NK->ngay_cap.thang,s);
        gtk_text_buffer_set_text(NK_tb122,s,(gint)-1);
        int_to_string(NK->ngay_cap.nam,s);
        gtk_text_buffer_set_text(NK_tb123,s,(gint)-1);
        gtk_text_buffer_set_text(NK_tb13,NK->noi_cap,(gint)-1);
        int_to_string(NK->dang_ki.ngay,s);
        gtk_text_buffer_set_text(NK_tb141,s,(gint)-1);
        int_to_string(NK->dang_ki.thang,s);
        gtk_text_buffer_set_text(NK_tb142,s,(gint)-1);
        int_to_string(NK->dang_ki.nam,s);
        gtk_text_buffer_set_text(NK_tb143,s,(gint)-1);
        gtk_text_buffer_set_text(NK_tb15,NK->quan_he,(gint)-1);
        remove_tree_all(NK_tv16,&NK16_ts);
        set_GC_tree(&NK16_ts,NK->gcNK);
    }
    else{
        gtk_text_buffer_set_text(NK_tb1,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb2,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb3,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb4,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb51,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb52,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb53,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb6,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb7,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb8,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb9,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb10,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb11,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb121,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb122,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb123,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb13,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb141,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb142,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb143,"",(gint)-1);
        gtk_text_buffer_set_text(NK_tb15,"",(gint)-1);
        remove_tree_all(NK_tv16,&NK16_ts);
    }
}

void renewNK(){
    show_NK_no_sel();
    remove_tree_all(HK_tv1,&HK1_ts);
    set_HK_tree(&HK1_ts);
    remove_tree_all(HK_tv2,&HK2_ts);
    set_GC_tree(&HK2_ts,NULL);
    set_NK_text(NULL);
}

int nowSelectHK1(HoKhau **HK,NhanKhau **NK){
    GtkTreeModel *model= gtk_tree_view_get_model(HK_tv1);
    GtkTreeIter iter;
    char *ten,*dc;
    
    if(gtk_tree_model_get_iter_first(model,&iter)==FALSE){
        return 0;
    }
    else if(findHKnNKTree(model,iter,select_HK1,1,0,&dc,&ten)){
        *HK=HoKhausearchDiaChi(dc);
        *NK=NhanKhausearchTenvaDiaChi(ten,NULL,*HK);
        return 1;
    }
    else return 0;
}

void on_select_HK1_changed(GtkTreeSelection *widget){
    HoKhau* HK;
    NhanKhau* NK;
    
    if(nowSelectHK1(&HK,&NK)){
        curHK=HK;
        curNK=NK;
        remove_tree_all(HK_tv2,&HK2_ts);
        set_GC_tree(&HK2_ts,HK->gcHK);
        if(NK_is_edit_mode==0) set_NK_text(NK);
        show_NK_opt();
    }
    else {
        curHK=NULL;
        curNK=NULL;
        remove_tree_all(HK_tv2,&HK2_ts);
        set_NK_text(NULL);
        show_NK_no_sel();
    }
}

void on_select_HK2_changed(GtkTreeSelection *widget){

}

void on_select_NK16_changed(GtkTreeSelection *widget){

}

void on_NK_qd_clicked(GtkButton *B){
    att=0;
    gtk_widget_show(NK_cqd);
    gtk_widget_hide(NK_qd);
    gtk_widget_hide(NK_swtt1);
    gtk_widget_hide(NK_swtt2);
    gtk_widget_hide(NK_swtt3);
}

void on_NK_cqd_clicked(GtkButton *B){
    att=1;
    gtk_widget_show(NK_qd);
    gtk_widget_hide(NK_cqd);
    gtk_widget_show(NK_swtt1);
    gtk_widget_show(NK_swtt2);
    gtk_widget_show(NK_swtt3);
    gtk_text_buffer_set_text(NK_tbtt1,"",(gint)-1);
    gtk_text_buffer_set_text(NK_tbtt2,"",(gint)-1);
    gtk_text_buffer_set_text(NK_tbtt3,"",(gint)-1);
}

void on_NK_ms_clicked(GtkButton *B){
    att=0;
    gtk_widget_show(NK_cms);
    gtk_widget_hide(NK_ms);
}

void on_NK_cms_clicked(GtkButton *B){
    att=2;
    gtk_widget_show(NK_ms);
    gtk_widget_hide(NK_cms);
}

void on_NK_add_clicked(GtkButton *B){
    NK_is_add_mode=1;
    show_NK_edit();
    set_NK_text(NULL);
}

void on_NK_del_clicked(GtkButton *B){
    if(NK_is_NK){
        deleteNhanKhau(&curHK->NK,curNK);
    }
    else{
        deleteHoKhau(&allHK,curHK);
    }
    renewNK();
}

void on_HK_add_clicked(GtkButton *B){
    HoKhau* HK;
    NhanKhau a,*NK;
    GtkTreeModel *model;
    GtkTreeIter iter;
    char *dc,*ten;
    if(findHKnNKTree(model,iter,select_HK1,1,0,&dc,&ten)){
        HK=HoKhausearchDiaChi(dc);
        NK=NhanKhausearchTenvaDiaChi(ten,NULL,HK);
        remove_tree_all(HK_tv2,&HK2_ts);
        set_GC_tree(&HK2_ts,HK->gcHK);
        if(NK_is_edit_mode==0) set_NK_text(NK);
        show_NK_opt();
    }
}

void on_HK_del_clicked(GtkButton *B){

}

void on_NK_adj_clicked(GtkButton *B){
    NK_is_add_mode=0;
    show_NK_edit();
    gtk_widget_hide(HK_sw1);
    gtk_widget_hide(HK_sw2);;
    set_NK_text(curNK);
}

void on_NK_top_clicked(GtkButton *B){

}

void get_tt_date(Date *a){
    GtkTextIter begin,end;
    char *text;
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt1),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt1),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tbtt1),&begin,&end,TRUE);
    a->ngay=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt2),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt2),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tbtt2),&begin,&end,TRUE);
    a->thang=atoi(text);

    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt3),&begin,(gint) 0);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(NK_tbtt3),&end,(gint) -1);
    text=gtk_text_buffer_get_text(GTK_TEXT_BUFFER(NK_tbtt3),&begin,&end,TRUE);
    a->nam=atoi(text);
}

void on_NK_save_clicked(GtkButton *B){
    HoKhau* HK;
    NhanKhau a,*NK;
    if(NK_is_add_mode==1){
        if(nowSelectHK1(&HK,&NK)){
            if(HK==NULL) return;
            get_NK_buffer(&a);
            NK=NULL;
            insertNhanKhau(&NK,a.Ten,a.BiDanh,0,a.gioi_tinh,a.tuoi,a.ngay_sinh,a.noi_sinh,a.que_quan,a.dan_toc,a.nghe_nghiep,a.noi_lam_viec,a.CMND,a.ngay_cap,a.noi_cap,a.dang_ki,NULL,a.quan_he,NULL,att);
            chuyenNhanKhau(NULL,HK,NK,NK->dang_ki);
            if(att==2){
                moi_sinh(curNK,a.ngay_sinh);
            }
        }
    }
    else{
        if(att==1&&curNK->tt!=att){
            get_tt_date(&a.ngay_sinh);
            da_qua_doi(curNK,a.ngay_sinh);
            curNK->tt=att;
        }
        get_NK_buffer(&a);
        changeNKcontent(curNK,a.Ten,a.BiDanh,0,a.gioi_tinh,a.tuoi,a.ngay_sinh,a.noi_sinh,a.que_quan,a.dan_toc,a.nghe_nghiep,a.noi_lam_viec,a.CMND,a.ngay_cap,a.noi_cap,a.dang_ki,NULL,a.quan_he,NULL,curNK->tt);
        
    }
    renewNK();
}

void on_NK_cal_clicked(GtkButton *B){
    renewNK();
}

void on_NK_srch_changed(GtkSearchEntry *s){
    on_search_tree_changed(s,&HK_tv1,2);
}

void return_nk_clicked(GtkButton* b){
    gtk_widget_destroy(options_window);
    return ;
}

// void options_button_clicked(GtkButton *b){
//     options_screen();
//     return;
// }
// void options_screen(){
//     builder = gtk_builder_new_from_file("../nhan_khau.glade");
//     options_window = GTK_WIDGET(gtk_builder_get_object(builder, "options_window"));
//     g_signal_connect(options_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//     gtk_builder_connect_signals(builder, NULL);
//     GtkWidget *options_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "options_fixed"));
//     GtkWidget *return_nk_btn = GTK_WIDGET(gtk_builder_get_object(builder, "return_nk_btn"));
//     GtkWidget *them_ho_khau_btn = GTK_WIDGET(gtk_builder_get_object(builder, "them_ho_khau_btn"));
//     GtkWidget *them_nhan_khau_btn = GTK_WIDGET(gtk_builder_get_object(builder, "them_nhan_khau_btn"));
//     GtkWidget *thay_doi_nhan_khau_btn = GTK_WIDGET(gtk_builder_get_object(builder, "thay_doi_nhan_khau_btn"));
//     GtkWidget *tam_tru_tam_vang_btn = GTK_WIDGET(gtk_builder_get_object(builder, "tam_tru_tam_vang_btn"));
//     g_signal_connect (return_nk_btn, "clicked", G_CALLBACK (return_nk_clicked), options_screen);
//     g_signal_connect (them_ho_khau_btn, "clicked", G_CALLBACK (them_hk_clicked), options_screen);
//     g_signal_connect (them_nhan_khau_btn, "clicked", G_CALLBACK (them_nk_clicked), options_screen);
//     g_signal_connect (tam_tru_tam_vang_btn, "clicked", G_CALLBACK (tam_tru_tam_vang_clicked), options_screen);
//     gtk_widget_show_all(options_window);
//     gtk_widget_hide(textview_find);
//     gtk_main();
// }

void nhan_khau_screen(){
    builder = gtk_builder_new_from_file("../nhan_khau.glade");
    NK_win = GTK_WIDGET(gtk_builder_get_object(builder, "NK_win"));
    g_signal_connect(NK_win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    NK_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "NK_fixed"));
    gtk_builder_connect_signals(builder, NULL);

    NK_return_button=GTK_WIDGET(gtk_builder_get_object(builder,"NK_return_button"));
    g_signal_connect(NK_return_button, "clicked", G_CALLBACK(on_NK_return_button_clicked),NULL);
    
    //Ho khau
    HK_sw1 = GTK_WIDGET(gtk_builder_get_object(builder, "HK_sw1"));
    HK_vp1 = GTK_WIDGET(gtk_builder_get_object(builder, "HK_vp1"));
    HK1_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"HK1_ts"));
    HK_tv1=GTK_TREE_VIEW(gtk_builder_get_object(builder,"HK_tv1"));
    HK1c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"HK1c1"));
    HK1cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"HK1cr1"));
    gtk_tree_view_column_add_attribute(HK1c1, HK1cr1, "text", 0); //Attach the renderer to the column
    HK1c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"HK1c2"));
    HK1cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"HK1cr2"));
    gtk_tree_view_column_add_attribute(HK1c2, HK1cr2, "text", 1); //Attach the renderer to the column
    select_HK1=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_HK1"));
    g_signal_connect(select_HK1,"changed",G_CALLBACK(on_select_HK1_changed),NULL);

    HK_sw2 = GTK_WIDGET(gtk_builder_get_object(builder, "HK_sw2"));
    HK_vp2 = GTK_WIDGET(gtk_builder_get_object(builder, "HK_vp2"));
    HK2_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"HK2_ts"));
    HK_tv2=GTK_TREE_VIEW(gtk_builder_get_object(builder,"HK_tv2"));
    HK2c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"HK2c1"));
    HK2cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"HK2cr1"));
    gtk_tree_view_column_add_attribute(HK2c1, HK2cr1, "text", 0); //Attach the renderer to the column
    HK2c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"HK2c2"));
    HK2cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"HK2cr2"));
    gtk_tree_view_column_add_attribute(HK2c2, HK2cr2, "text", 1); //Attach the renderer to the column
    select_HK2=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_HK2"));
    g_signal_connect(select_HK2,"changed",G_CALLBACK(on_select_HK2_changed),NULL);

    //Nhan khau
    NK_sw1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw1"));
    NK_vp1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp1"));
    NK_tv1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv1"));
    NK_tb1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv1));

    NK_sw2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw2"));
    NK_vp2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp2"));
    NK_tv2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv2"));
    NK_tb2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv2));

    NK_sw3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw3"));
    NK_vp3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp3"));
    NK_tv3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv3"));
    NK_tb3 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv3));
    
    NK_sw4 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw4"));
    NK_vp4 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp4"));
    NK_tv4 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv4"));
    NK_tb4 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv4));
    
    NK_sw51 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw51"));
    NK_vp51 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp51"));
    NK_tv51 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv51"));
    NK_tb51 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv51));
    g_signal_connect(NK_tb51,"changed", G_CALLBACK(on_date1_changed),NULL);

    NK_sw52 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw52"));
    NK_vp52 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp52"));
    NK_tv52 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv52"));
    NK_tb52 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv52));
    g_signal_connect(NK_tb52,"changed", G_CALLBACK(on_date2_changed),NULL);

    NK_sw53 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw53"));
    NK_vp53 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp53"));
    NK_tv53 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv53"));
    NK_tb53 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv53));
    g_signal_connect(NK_tb53,"changed", G_CALLBACK(on_date3_changed),NULL);
    
    NK_sw6 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw6"));
    NK_vp6 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp6"));
    NK_tv6 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv6"));
    NK_tb6 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv6));
    
    NK_sw7 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw7"));
    NK_vp7 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp7"));
    NK_tv7 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv7"));
    NK_tb7 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv7));
    
    NK_sw8 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw8"));
    NK_vp8 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp8"));
    NK_tv8 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv8"));
    NK_tb8 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv8));
    
    NK_sw9 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw9"));
    NK_vp9 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp9"));
    NK_tv9 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv9"));
    NK_tb9 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv9));
    
    NK_sw10 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw10"));
    NK_vp10 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp10"));
    NK_tv10 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv10"));
    NK_tb10 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv10));
    
    NK_sw11 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw11"));
    NK_vp11 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp11"));
    NK_tv11 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv11"));
    NK_tb11 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv11));
    
    NK_sw121 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw121"));
    NK_vp121 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp121"));
    NK_tv121 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv121"));
    NK_tb121 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv121));
    g_signal_connect(NK_tb121,"changed", G_CALLBACK(on_date1_changed),NULL);

    NK_sw122 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw122"));
    NK_vp122 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp122"));
    NK_tv122 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv122"));
    NK_tb122 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv122));
    g_signal_connect(NK_tb122,"changed", G_CALLBACK(on_date2_changed),NULL);

    NK_sw123 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw123"));
    NK_vp123 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp123"));
    NK_tv123 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv123"));
    NK_tb123 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv123));
    g_signal_connect(NK_tb123,"changed", G_CALLBACK(on_date3_changed),NULL);
    
    NK_sw13 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw13"));
    NK_vp13 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp13"));
    NK_tv13 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv13"));
    NK_tb13 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv13));
    
    NK_sw141 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw141"));
    NK_vp141 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp141"));
    NK_tv141 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv141"));
    NK_tb141 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv141));
    g_signal_connect(NK_tb141,"changed", G_CALLBACK(on_date1_changed),NULL);

    NK_sw142 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw142"));
    NK_vp142 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp142"));
    NK_tv142 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv142"));
    NK_tb142 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv142));
    g_signal_connect(NK_tb142,"changed", G_CALLBACK(on_date2_changed),NULL);

    NK_sw143 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw143"));
    NK_vp143 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp143"));
    NK_tv143 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv143"));
    NK_tb143 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv143));
    g_signal_connect(NK_tb143,"changed", G_CALLBACK(on_date3_changed),NULL);
    
    NK_sw15 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw15"));
    NK_vp15 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp15"));
    NK_tv15 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tv15"));
    NK_tb15 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tv15));
    
    NK_sw16 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_sw16"));
    NK_vp16 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vp16"));
    NK16_ts=GTK_TREE_STORE(gtk_builder_get_object(builder,"NK16_ts"));
    NK_tv16=GTK_TREE_VIEW(gtk_builder_get_object(builder,"NK_tv16"));
    NK16c1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"NK16c1"));
    NK16cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"NK16cr1"));
    gtk_tree_view_column_add_attribute(NK16c1, NK16cr1, "text", 0); //Attach the renderer to the column
    NK16c2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"NK16c2"));
    NK16cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"NK16cr2"));
    gtk_tree_view_column_add_attribute(NK16c2, NK16cr2, "text", 1); //Attach the renderer to the column
    select_NK16=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select_NK16"));
    g_signal_connect(select_NK16,"changed",G_CALLBACK(on_select_NK16_changed),NULL);

    NK_swtt1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_swtt1"));
    NK_vptt1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vptt1"));
    NK_tvtt1 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tvtt1"));
    NK_tbtt1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tvtt1));

    NK_swtt2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_swtt2"));
    NK_vptt2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vptt2"));
    NK_tvtt2 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tvtt2"));
    NK_tbtt2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tvtt2));

    NK_swtt3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_swtt3"));
    NK_vptt3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_vptt3"));
    NK_tvtt3 = GTK_WIDGET(gtk_builder_get_object(builder, "NK_tvtt3"));
    NK_tbtt3 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(NK_tvtt3));

    NK_ten_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_ten_label"));
    NK_tuoi_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_tuoi_label"));
    NK_CMND_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_CMND_label"));
    NK_noi_lam_viec_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_noi_lam_viec_label"));
    NK_ghi_chu_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_ghi_chu_label"));
    NK_quan_he_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_quan_he_label"));
    NK_noi_cap_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_noi_cap_label"));
    NK_ngay_sinh_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_ngay_sinh_label"));
    NK_bi_danh_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_bi_danh_label"));
    NK_gioi_tinh_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_gioi_tinh_label"));
    NK_nghe_nghiep_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_nghe_nghiep_label"));
    NK_dan_toc_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_dan_toc_label"));
    NK_ngay_cap_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_ngay_cap_label"));
    NK_que_quan_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_que_quan_label"));
    NK_dang_ki_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_dang_ki_label"));
    NK_noi_sinh_label=GTK_WIDGET(gtk_builder_get_object(builder, "NK_noi_sinh_label"));

    NK_add=GTK_WIDGET(gtk_builder_get_object(builder,"NK_add"));
    g_signal_connect(NK_add, "clicked", G_CALLBACK(on_NK_add_clicked),NULL);
    HK_add=GTK_WIDGET(gtk_builder_get_object(builder,"HK_add"));
    g_signal_connect(HK_add, "clicked", G_CALLBACK(on_HK_add_clicked),NULL);
    NK_del=GTK_WIDGET(gtk_builder_get_object(builder,"NK_del"));
    g_signal_connect(NK_del, "clicked", G_CALLBACK(on_NK_del_clicked),NULL);
    HK_del=GTK_WIDGET(gtk_builder_get_object(builder,"HK_del"));
    g_signal_connect(HK_del, "clicked", G_CALLBACK(on_HK_del_clicked),NULL);
    NK_adj=GTK_WIDGET(gtk_builder_get_object(builder,"NK_adj"));
    g_signal_connect(NK_adj, "clicked", G_CALLBACK(on_NK_adj_clicked),NULL);
    NK_top=GTK_WIDGET(gtk_builder_get_object(builder,"NK_top"));
    g_signal_connect(NK_top, "clicked", G_CALLBACK(on_NK_top_clicked),NULL);
    NK_save=GTK_WIDGET(gtk_builder_get_object(builder,"NK_save"));
    g_signal_connect(NK_save, "clicked", G_CALLBACK(on_NK_save_clicked),NULL);
    NK_cal=GTK_WIDGET(gtk_builder_get_object(builder,"NK_cal"));
    g_signal_connect(NK_cal, "clicked", G_CALLBACK(on_NK_cal_clicked),NULL);
    NK_qd=GTK_WIDGET(gtk_builder_get_object(builder,"NK_qd"));
    g_signal_connect(NK_qd, "clicked", G_CALLBACK(on_NK_qd_clicked),NULL);
    NK_cqd=GTK_WIDGET(gtk_builder_get_object(builder,"NK_cqd"));
    g_signal_connect(NK_cqd, "clicked", G_CALLBACK(on_NK_cqd_clicked),NULL);
    NK_ms=GTK_WIDGET(gtk_builder_get_object(builder,"NK_ms"));
    g_signal_connect(NK_ms, "clicked", G_CALLBACK(on_NK_ms_clicked),NULL);
    NK_cms=GTK_WIDGET(gtk_builder_get_object(builder,"NK_cms"));
    g_signal_connect(NK_cms, "clicked", G_CALLBACK(on_NK_cms_clicked),NULL);


    NK_srch=GTK_WIDGET(gtk_builder_get_object(builder,"NK_srch"));
    g_signal_connect(NK_srch, "changed", G_CALLBACK(on_NK_srch_changed),NULL);


    renewNK();
    gtk_widget_show(NK_win);
    gtk_main();
    
}

void on_NK_return_button_clicked(GtkButton *b){
    gtk_widget_destroy(NK_win);
    main_screen();
}


//Phan cua Hoanh tu day tro xuong

void main_screen(){
    // char tmp[100];
    // strcpy(tmp,"Welcome back ! ");
    // strcat(tmp,dangdangnhap.username);
    builder = gtk_builder_new_from_file("../main.glade");
    gtk_builder_connect_signals(builder, NULL);
    window_main = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    g_signal_connect(window_main, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *nhan_khau_button = GTK_WIDGET(gtk_builder_get_object(builder, "nhan_khau_button"));
    GtkWidget *nha_van_hoa_button = GTK_WIDGET(gtk_builder_get_object(builder, "nha_van_hoa_button"));
    log_out_button = GTK_WIDGET(gtk_builder_get_object(builder, "log_out_button"));
    GtkWidget *fixed_main = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_main"));
    GtkWidget *label_main = GTK_WIDGET(gtk_builder_get_object(builder, "label_main"));
    g_signal_connect (log_out_button, "clicked", G_CALLBACK (log_out_clicked), main_screen);
    g_signal_connect (nhan_khau_button, "clicked", G_CALLBACK (nhan_khau_clicked), main_screen);
    g_signal_connect (nha_van_hoa_button, "clicked", G_CALLBACK (nha_van_hoa_clicked), main_screen);
    // gtk_label_set_text(GTK_LABEL(label_main), (const gchar *)tmp);
    gtk_widget_show_all(window_main);
    gtk_main();

}
void log_out_clicked(GtkButton* b){
    gtk_widget_destroy(window_main);
    strcpy(dangdangnhap.username," ") ;
    strcpy(dangdangnhap.pass," ") ;
    FILE* a = fopen("checkname.txt","w");
    fprintf(a," ");
    login_screen();
}
void entry_user_typed(GtkEntry *e){ 
    //entry option
    char tmp[100];
    strcpy(tmp,gtk_entry_get_text(e));
    tmp[strlen(tmp)]='\0';
    //sprintf(tmp, "%s", gtk_entry_get_text(e));
    FILE* fptr = fopen("checkname.txt","w+");
    fprintf(fptr,"%s",tmp);
    fclose(fptr);
}
void entry_password_typed(GtkEntry *e){ //entry option
    char tmp[100];
    strcpy(tmp,gtk_entry_get_text(e));
    tmp[strlen(tmp)]='\0';
    //sprintf(tmp, "%s", gtk_entry_get_text(e));
    FILE* fptr = fopen("checkpass.txt","w+");
    fprintf(fptr,"%s",tmp);
    fclose(fptr);
}

void check_password_clicked(GtkButton *b){
    FILE* a1 = fopen("checkname.txt","r");
    FILE* a2 = fopen("checkpass.txt","r");
    int i = 0;
    
    while(i < 1000000){
        
        i++;
    }
       
    gtk_spinner_stop((GtkSpinner*)spinner);
    read_user_data();
    nguoiquanly a;
    fscanf(a1,"%s",a.username);
    fscanf(a2,"%s",a.pass);
    for(int i = 0; i< 3; i++){
        if(strcmp(user[i].username,a.username) == 0 && strcmp(user[i].pass,a.pass) == 0){
            strcpy(dangdangnhap.username,a.username) ;
            strcpy(dangdangnhap.pass,a.pass) ;
            gtk_widget_destroy(window_login);
            
            main_screen();
            return;
        }
        gtk_label_set_text(GTK_LABEL(label_result), (const gchar *)"Invalid username or password");
    }
}

void login_screen(){
    
    builder = gtk_builder_new_from_file("../login.glade");
    gtk_builder_connect_signals(builder, NULL);
    window_login = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
    spinner = GTK_WIDGET(gtk_builder_get_object(builder, "spinner"));
    g_signal_connect(window_start, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window_login, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkWidget *fixed_login = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_login"));
    GtkWidget *label_login = GTK_WIDGET(gtk_builder_get_object(builder, "label_login"));
               label_result = GTK_WIDGET(gtk_builder_get_object(builder, "label_result"));
    GtkWidget *login_button = GTK_WIDGET(gtk_builder_get_object(builder, "login_button"));
    GtkWidget *entry_username = GTK_WIDGET(gtk_builder_get_object(builder, "entry_username"));
    GtkWidget *entry_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_password"));
    g_signal_connect (login_button, "clicked", G_CALLBACK(check_password_clicked), window_login);
    g_signal_connect (entry_username, "changed", G_CALLBACK (entry_user_typed), entry_username);
    g_signal_connect (entry_password, "changed", G_CALLBACK (entry_password_typed), entry_password);
    gtk_widget_show_all(window_login);
    gtk_spinner_start((GtkSpinner*)spinner);
    gtk_main();
    
}
// void search_button_clicked(GtkButton *b){
    
//     GtkTextBuffer * buffer = gtk_text_view_get_buffer((GtkTextView*)textview_find);
//     GtkTextIter iter;
//     char *markup;
//     gtk_widget_show(textview_find);
//     //Nếu k thấy
//     markup = "Người bạn đang tìm không tồn tại trong danh sách";
//     gtk_text_buffer_get_start_iter(buffer, &iter);
//     gtk_text_buffer_insert_markup(buffer, &iter, markup, -1);
//     //Nếu thấy : nối chuỗi thông tin của người đó vào markup r in ra :v
// }


void start_clicked(GtkButton *b){
    gtk_widget_destroy(window_start);
    login_screen();
}
void start_screen(){
    
 
    builder = gtk_builder_new_from_file("../start.glade");
    gtk_builder_connect_signals(builder, NULL);
    window_start = GTK_WIDGET(gtk_builder_get_object(builder, "window_start"));
    g_signal_connect(window_start, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkWidget *fixed_start = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_start"));
    GtkWidget *start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
    g_signal_connect (start_button, "clicked", G_CALLBACK(start_clicked), window_start); 
    gtk_widget_show_all(window_start);
    
    gtk_main();
    
}


