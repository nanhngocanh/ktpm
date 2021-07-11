#include<stdio.h>
#include "DataType.h"

Kho duyetkho(){
    Kho a;
    FILE *input = fopen("kho.txt", "r");
    fscanf(input, "%d\t%d",&a.ban.so_luong, &a.ban.gia_tien);
    fscanf(input, "%d\t%d",&a.ghe.so_luong, &a.ghe.gia_tien);
    fscanf(input, "%d\t%d",&a.loa.so_luong, &a.loa.gia_tien);
    fscanf(input, "%d\t%d",&a.dai.so_luong, &a.dai.gia_tien);
    fscanf(input, "%d\t%d",&a.phong.so_luong, &a.phong.gia_tien);
    fclose(input);
    return a;
}

void read_user_data(){
    FILE *input = fopen("user_infor.txt","r");
    for(int i = 0; i < 3; i++){
    fscanf(input, "%s\t%s",user[i].username, user[i].pass);
    }
    fclose(input);
    return;
    
}
