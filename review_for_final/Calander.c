#include <stdio.h>
int type(int years_current){
    if(years_current%4 == 0){
        if(years_current%400!=0&&years_current%100==0){
        return 0;
        }
        else{
            return 1;
        }
        return 0;
    }
}
int main(){
    int days[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
			31,29,31,30,31,30,31,31,30,31,30,31};
    int days_of_years[2] = {365,366};
    char weekdays[7][10]={"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int input_day;
    int month = 0;
    int years_current = 2000;
    scanf("%d",&input_day);
    while(input_day!= -1){
        int days_of_week = input_day % 7;
        while(input_day>days_of_years[type(years_current)]){
            input_day = input_day - days_of_years[type(years_current)];
            years_current ++;            
            }
        while(input_day>days[type(years_current)][month]){
            input_day = input_day - days[type(years_current)][month];
            month ++;            
            }
        printf("%d-%02d-%02d %s\n",
        years_current,month+1,input_day+1,weekdays[days_of_week]);
        month = 0;
        years_current = 2000;  
        scanf("%d",&input_day);  
    }
    return 0;

}