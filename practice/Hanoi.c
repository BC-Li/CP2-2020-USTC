#include <stdio.h>
void Hanoi(int n,char a,char b,char c){
    if(n == 1){
        printf("%c -> %c\n",a,b);
        return;
    }//���涼��ǰһ���Ĳ���������n������1��ʱ��������һ���Ĳ���
    Hanoi(n-1,a,c,b);//��ô��ǰһ��Ҳ����f(n - 1, other variables)
    printf("%c -> %c\n",a,b);//��Ȼ���Ƚ�n -1 ����A�����ϵ�����ͨ��C���ƶ���B���ϣ�
    Hanoi(n-1,c,b,a);//�ٽ���A�����ϵı��Ϊn�������ƶ���C���ϣ��ٽ�B�����ϵ�n-1������ͨ��A���ƶ���C����
}
int main(){
    int n;
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
    return 0;
}