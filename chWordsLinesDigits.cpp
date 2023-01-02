#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
    char ch;
    FILE *fr;
    fr=fopen("prog1.txt", "r");
    int noc=0,nol=0,now=0,digit=0;
    if(fr==NULL){
        cout<<"File not found";
        exit(0);
    }
    while(ch!=EOF){
        if(ch!='\n' && ch!=' ')
            noc++;

        if(ch==' ')
            now++;
        if(ch=='\n' && ch!=' '){
            now++;
            ch++;
            nol++;
        }
        if(isdigit(ch))
        {
            digit++;
        }
        ch=fgetc(fr);
    }
    fclose(fr);
    cout<<"\n Characters: "<<noc++;    
    cout<<"\n Words: "<<now++;    
    cout<<"\n lines: "<<nol++;    
    cout<<"\n digits: "<<digit++; 
    return 0;
}