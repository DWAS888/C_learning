#include<cstdio>
using namespace std;
int Fibonacci(int n)
{
	switch (n) {
	case 1:
		return 0;
		break;
	case 2:
		return 1;
		break;
	default:
		return Fibonacci(n-1) +Fibonacci(n-2);
		break;
	}
}
int main()
{
	int n,ans;
	scanf("%d",&n);
	ans = Fibonacci(n);
	printf("%d\n",ans);
	return 0;
}
