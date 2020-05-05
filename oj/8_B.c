//确定了方程f(x)=0在区间（a,b）内如果有且只有一个根，那么我们可以有逐步缩小根可能存在的范围的方法确定出某精度下根的数值。本题规定根的精度是0.01，下面采用二分法求区间（a,b）内方程的根，过程如下：
//（1）取当前可能存在解的区间（a,b）;
//（2）若a+0.001>b或f((a+b)/2)=0,则可确定根为（a+b）/2并退出过程；
//（3）若f(a)×f((a+b)/2)<0,则根在区间（a, (a+b)/2）中，故对区间（a, (a+b)/2）重复该过程；
//（4）若f(a)× f((a+b)/2)>0,则必然有 f((a+b)/2)×f(b)<0，也就是说根在（(a+b)/2,b）中，应该对此区间重复该过程。
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