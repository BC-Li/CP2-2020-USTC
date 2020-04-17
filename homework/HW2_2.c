#include<stdio.h>
int charcompare(char *a,char *b){
    char *p_a,*p_b;
    int ichar_a = 0,ichar_b = 0;//a,b字符串的ASCII码值总和
    p_a = a;
    p_b = b;
    for (; *p_a != '\0';p_a++){
        if(*p_a>='a'&&*p_a<='z'){
            ichar_a = ichar_a + (int)*p_a;
        }
        if(*p_a>='A'&&*p_a<='Z'){
            ichar_a = ichar_a + (int)*p_a - ('A' - 'a');
        }
    }
    for (; *p_b != '\0';p_b++){
        if(*p_b>='a'&&*p_b<='z'){
            ichar_b = ichar_b + (int)*p_b;
        }
        if(*p_b>='A'&&*p_b<='Z'){
            ichar_b = ichar_b + (int)*p_b - ('A' - 'a');
        }
    }
    if(ichar_a == ichar_b){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char ca[101], cb[101];
    scanf("%s", ca);
    scanf("%s", cb);
    int reminder = charcompare(ca, cb);
    if(reminder == 1){
        printf("Same.");
    }
    else{
        printf("Not same.");
    }
    return 0;
}