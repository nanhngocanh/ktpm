#ifndef TIME_SET_H
#define TIME_SET_H

#include<stdio.h>
#include"datatype.h"

Date makeNewDate(int ngay, int thang, int nam){
	Date tmp;
	tmp.ngay=ngay;
	tmp.thang=thang;
	tmp.nam=nam;
	return tmp;
}

int timecmp(Time a, Time b){//if a>b 1; a=b 0; a<b -1;
	if(a.nam>b.nam) return 1;
	else if(a.nam<b.nam) return -1;
	else{
		if(a.thang>b.thang) return 1;
		else if(a.thang<b.thang) return -1;
		else{
			if(a.ngay>b.ngay) return 1;
			else if(a.ngay<b.ngay) return -1;
			else{
				if(a.gio>b.gio) return 1;
				else if(a.gio<b.gio) return -1;
				else{
					if(a.phut>b.phut) return 1;
					else if(a.phut<b.phut) return -1;
					else return 0;
				}
			}
		}
	}
}

#endif
