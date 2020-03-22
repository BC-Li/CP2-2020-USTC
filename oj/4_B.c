#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char arr_origin[1000], arr_code[2][1000];
    char alphabet[26][2];
    int alarmer = 0;
    char code_to_possess[1010];
    memset(arr_origin, 0, sizeof(arr_origin));
    memset(arr_code, 0, sizeof(arr_code));
    for (int j = 0; j < 26;j++){
        alphabet[j][0] = j;
        alphabet[j][1] = 0;
    }
    gets(arr_origin);
    gets(arr_code[0]);
    gets(code_to_possess);
    for (int scanner = 0; arr_origin[scanner] != '\0'; scanner++)
        {
            for (int i = 0; i < 26; i++)
            {
                if ((int)arr_origin[scanner]-'A' == i)
                {
                    if (alphabet[i][1] == 0)
                    {
                        alphabet[i][0] = (int)arr_code[0][scanner] - 'A';
                        alphabet[i][1] = 1;
                        break;
                    }
                    else if (alphabet[i][1] == 1&&alphabet[i][0] != (int)arr_code[0][scanner] - 'A')
                    {
                        alarmer = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 26;i++){
            if(alphabet[i][1]==0){
                alarmer = 1;
            }
            for (int j = 0; j < 26;j++){
                if(alphabet[i][0]==alphabet[j][0]){
                    if(i!=j){
                        alarmer = 1;
                    }
                }
            }
        }
        if (alarmer == 1)
            {
                printf("Failed");
                return 0;
            }
        else
            {
                for (int i = 0; code_to_possess[i] != EOF; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if ((int)code_to_possess[i] - 'A' == j)
                        {
                            code_to_possess[i] = alphabet[j][0]+'A';
                            break;
                        }
                    }
                }
                printf("%s", code_to_possess);
                return 0;
            }
}