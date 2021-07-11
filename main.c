#include<stdio.h>
#include "Library/iclall.h"
#include <gtk/gtk.h>

int main(int argc, char*argv[]){
	setIDnha();
	setIDSK();
	duyetkho();
	readnhankhaufile("nhankhau.txt");
	readnhankhaufile("nhankhau2.txt");
	// readnhankhaufile("hộ-kk123.txt");
	// readnhankhaufile("hooooo.txt");
	readghichufile("ghichu.txt");
	readsukienfile("sukien.txt");
	// readsukienfile("su-kien123.txt");
    gtk_init(&argc,&argv);
     start_screen();
    //nhan_khau_screen();
    // su_kien_screen();
    writenhankhaufile("outHK.txt",allHK,"outGC.txt");
	writesukienfile("outSK.txt");
    freeAllHoKhau(&allHK);
    freeAllSuKien(&allSK);
}
