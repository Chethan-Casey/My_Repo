/* Copyright (C) 2013-14 Green Turtles Technologies <www.greenturtles.in>, Inc.  All rights reserved.

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors: Sunil Kumar <skjmca51@gmail.com>
            Ganesh Kumar <ganeshkumar14@gmail.com>
 * -*- coding: utf-8 -*-
 */


#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "export.h"
#define PERMS 0666 
#define path "/var/lib/nfs/etab"     
    
void error(char *,  ...);
struct nfs* Get_Export_List()
{
    char ch1[40];
    int i,j=0,k=0;
    int n,f1;   
    char buf[BUFSIZ];
    if ((f1 = open(path, O_RDONLY, 0)) == -1)
		error("cp: can't open ");
    while ((n = read(f1, buf, BUFSIZ)) > 0);
    struct nfs *ptr = malloc(sizeof(struct nfs));
    ptr->share=(char**)malloc(sizeof(char*)*50);
    for(i=0;buf[i]!='\0';i++,k++) {
		if(isspace(buf[i])) {                
	        while(buf[i]!='\n')i++;
    	                i++;
			ch1[k]='\0';             
        	ptr->share[j] = calloc(strlen(ch1) + 1, 1);                                                          
        	strcpy(ptr->share[j],ch1);        
        	ptr->countshare=j+1;              
        	j++;
        	k=0;                                                                
     	}
		ch1[k]=buf[i];
   	}
    return ptr;
}


