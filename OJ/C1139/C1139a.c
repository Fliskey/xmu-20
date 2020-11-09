#include <stdio.h>
#include <string.h>

int main(){
    char line[104];
    int if_name = 0;
    int if_title = 0;
    int if_tel = 0;
    char name[104];
    char title[104];
    char tel[104];
    memset(name,0,sizeof(name));
    memset(title,0,sizeof(title));
    memset(tel,0,sizeof(tel));

    while(gets(line)){
        char head = line[0];
        switch(head){
            case 'N':{
                if(!if_name){
                    if(line[1] == 'a')
                    if(line[2] == 'm')
                    if(line[3] == 'e')
                    if(line[4] == ':')
                    {
                        for(int i=6 ; line[i] != '\0' ; i++){
                            name[i-6] = line[i];
                        }
                        name[strlen(name)] = '\0';
                        if_name = 1;
                    }
                }
            }
            case 'T':{
                switch(line[1]){
                    case 'i':{
                        if(!if_title){
                            if(line[2] == 't')
                            if(line[3] == 'l')
                            if(line[4] == 'e')
                            if(line[5] == ':')
                            {
                                for(int i=7 ; line[i] != '\0' ; i++){
                                    title[i-7] = line[i];
                                }
                                title[strlen(title)] = '\0';
                                if_title = 1;
                            }
                        }
                    }
                    case 'E':{
                        if(!if_tel){
                            if(line[2] == 'L')
                            if(line[3] == ':')
                            {
                                for(int i=5 ; line[i] != '\0' ; i++){
                                    tel[i-5] = line[i];
                                }
                                tel[strlen(tel)] = '\0';
                                if_tel = 1;
                            }
                        }
                    }
                }
            }
        }
        if(if_name && if_title & if_tel){
            break;
        }
    }
    printf("%s %s's telephone number is %s.",title,name,tel);

    return 0;
}