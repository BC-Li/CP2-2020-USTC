//ȷ���˷���f(x)=0�����䣨a,b�����������ֻ��һ��������ô���ǿ���������С�����ܴ��ڵķ�Χ�ķ���ȷ����ĳ�����¸�����ֵ������涨���ľ�����0.01��������ö��ַ������䣨a,b���ڷ��̵ĸ����������£�
//��1��ȡ��ǰ���ܴ��ڽ�����䣨a,b��;
//��2����a+0.001>b��f((a+b)/2)=0,���ȷ����Ϊ��a+b��/2���˳����̣�
//��3����f(a)��f((a+b)/2)<0,��������䣨a, (a+b)/2���У��ʶ����䣨a, (a+b)/2���ظ��ù��̣�
//��4����f(a)�� f((a+b)/2)>0,���Ȼ�� f((a+b)/2)��f(b)<0��Ҳ����˵���ڣ�(a+b)/2,b���У�Ӧ�öԴ������ظ��ù��̡�
#include <stdio.h>
#include <math.h>
double function(double a, double b, double c, double d, double x){
    return (a * pow(x, 3) + b * pow(x, 2) + c * x + d);
}
double findsolution(double a ,double b,double c,double d, double x){
    double solution,solution_1;
    solution = x;
    solution_1 = x + 1;
    while(1){
        if(function(a,b,c,d,(solution+solution_1)/2)*function(a,b,c,d,solution)>0){
            solution = (solution + solution_1) / 2;
        }
        else{
            solution_1 = (solution + solution_1) / 2;
        }
        if((function(a,b,c,d,(solution+solution_1)/2)==0)){
            solution = (solution + solution_1) / 2;
            break;
        }
        if((fabs(solution-solution_1)<0.0001)){
            break;
        }
    }
         return solution;

   
}
int main(){
    double a, b, c, d;
    double solutions[3];
    int counter = 0;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for (int i = -100; i < 100;i++){
        if(function(a,b,c,d,i)*function(a,b,c,d,i+1)<0){
            solutions[counter]=findsolution(a, b, c, d, i);
            counter++;
        }
        if(function(a,b,c,d,i)*function(a, b, c,d,i+1)==0){
             if(function(a,b,c,d,i)==0){
                solutions[counter] = i;
                counter++;
            }
        }
    }
    if(function(a,b,c,d,200)==0){
        solutions[2] = 200;
    }
    printf("%.2lf %.2lf %.2lf", solutions[0], solutions[1], solutions[2]);
    return 0;
}