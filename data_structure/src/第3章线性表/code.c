#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start,stop;
double duration;
#define MAXN 10		/*多项式最大项数，即多项式阶数+1*/
#define MAXK 1e5	/* 被测函数最大重复调用次数 */
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );
void run_and_time(int k,double (*function)(int n, double a[], double x), int n,double a[], double x,const char *c);

int main()
{
    int i;
    double a[MAXN];	/*存储多项式的系数*/
    for (i=0;i<MAXN;i++) a[i]= (double)i;
    
	run_and_time(MAXK,f1, MAXN - 1,a, 1.1,"1");		//MAXN - 1防止数组访问越界 
	run_and_time(MAXK,f2, MAXN - 1,a, 1.1,"2");
	    
    
    return 0;
}

double f1( int n, double a[], double x ){
    int i;
    double p = a[0];
    for( i = 1; i <=n; i++ )
        p += (a[i] * pow(x,i));
    return p;
}

double f2( int n, double a[], double x ){
    int i;
    double p = a[n];
    for( i = n; i >0; i-- )
        p = a[i-1] + x*p;
    return p;
}

void run_and_time(int k,double (*function)(int n, double a[], double x), int n,double a[], double x,const char *c)
{
	start = clock();
	for(int i = 0;i < k; i++)	//重复调用获得充分多的时钟打点数 
    	function(n, a, x);
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK/MAXK;	/*多除以运算次数MAXK，计算单次运行时间*/
    printf("ticks%s = %f\n",c,duration);
    printf("duration%s = %6.2e\n",c,duration);
}
