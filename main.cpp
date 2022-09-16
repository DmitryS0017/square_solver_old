#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <locale.h>

int SolveSq( double a, double b, double c, double* const x1, double* const x2 );
int SolveLn( double b, double c, double* const x1 );
bool IsZero(int num);
void Input(double* a, double* b, double* c);
void Output(int const amount_sl, double* const x1, double* const x2 );


int main()
{
    setlocale(LC_ALL, "Rus");

    double a=0, b=0, c=0;
    double x1 = 0, x2 = 0;
    Input(&a, &b, &c);

    int amount_sl = SolveSq(a, b, c, &x1, &x2);
    Output(amount_sl, &x1, &x2);
    
}


int SolveSq( double const a, double const b, double const c,
             double* const x1, double* const x2 ){

                if (x1==x2){
                    return -1;
                }
                else if (IsZero(a)){
                    return SolveLn(b, c, x1);
                }
                else if (IsZero(b) && IsZero(c)){
                    *x1=0;
                    return 1;
                }
                else if (IsZero(c)){
                    *x1=0;
                    return SolveLn(a, b, x1)!=7 ? 2 : 7;
                }
                
                double d = b*b-4*a*c;
                
                if (d<0){
                    return 0;
                }
                else if (d==0){
                    *x1 = *x1 = -b/2/a;
                    return 1;
                }
                else{
                    *x1 = (-b-sqrt(d))/2/a;
                    *x2 = (-b+sqrt(d))/2/a;
                    return 2;
                }
             }


int SolveLn( double const b, double const c,
             double* const x1 ){

                if (b==0){
                    return 7;
                }
                else{
                    *x1 = -c/b;
                    return 1;
                }
             }


bool IsZero(int num)
{
    const double Zero = 0.0000001;

    if (num<Zero && num>-Zero)
        return 1;
    else
        return 0;
}


void Input(double* const a, double* const b, double* const c)
{
    printf("Введите коэффиценты квадратного уравнения a, b, c: ");
    while (scanf("%lf %lf %lf", a, b, c)!=3)
    {
        while (getchar()!='\n');
        printf("Некорректный ввод, повторите попытку: ");
    }
}


void Output(int const amount_sl, double* const x1, double* const x2 )
{
    switch (amount_sl){
        case -1:
            printf("Invalid input parameters");
            break;
        case 0: 
            printf("Уравнение не имеет корней\n"); 
            break;
        case 1: 
            printf("Корень уравнения:\nx1 = %.5lf\n", *x1); 
            break;
        case 2: 
            printf("Корени уравнения:\nx1 = %.5lf\nx2 = %.5lf\n", *x1, *x2); 
            break;
        case 7: 
            printf("Уравнение умеет бесконечно много корней\n"); 
            break;
        default:
            break;
    }
}