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


