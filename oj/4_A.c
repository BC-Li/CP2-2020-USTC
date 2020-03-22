#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void * a,const void * b){
    return (*(int *)a - *(int *)b);
}
int prime_decider(int n){
    int reminder = 0;
    int arr_prime_numbers[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int j = 0; j < 25;j++){
        if(n == arr_prime_numbers[j]){
            reminder = 1;
        }
     }
     return reminder;
}
int main(){
    int arr_numbers[26];
    int i = 0, min = 0;
    char arr_word[100];
    memset(arr_numbers, 0, sizeof(arr_numbers));
    while(scanf("%c",&arr_word[i])!=EOF){
        i++;
    }
    for (int k = 0; arr_word[k] != EOF;k++){
        arr_numbers[arr_word[k] - 'a'] = arr_numbers[arr_word[k] - 'a'] + 1;
    }
    qsort(arr_numbers, 26, sizeof(int), compare);
    for (int o = 0; o < 26;o++){
        if(arr_numbers[o]!=0){
            min = arr_numbers[o];
            break;
        }
    }
        if (prime_decider(arr_numbers[25] - min)==1)
        {
            printf("Lucky Word\n");
            printf("%d", arr_numbers[25] - min);
        }
        else{
        printf("No Answer\n");
        printf("%d", 0);
    }
    return 0;
}