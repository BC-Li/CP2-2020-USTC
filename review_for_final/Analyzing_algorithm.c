#include<stdio.h>
int main(){
    int a_1,b_1;
    int counter = 0;
    int maximum_cycle_length;
    while (scanf("&d &d", &a_1, &b_1) != EOF)
    {
        for (int i = a_1;i<=b_1;i++){
            if(i == 1 && counter > maximum_cycle_length){
                maximum_cycle_length = counter;
                continue;
            }
            if(i != 1){
                while(i != 1){
                    if (i%2!=0){
                        i = i/2;
                        counter++;
                    }
                    else{
                        n = n * 3 + 1;
                        counter++;
                    }
                }
            }
            if(counter > maximum_cycle_length){
                maximum_cycle_length = counter;
                continue;
            }
            counter = 0;
        }
        print("%d %d %d", a_1, b_1, maximum_cycle_length);
    }
    return 0;
}