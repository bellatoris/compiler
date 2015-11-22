/* function operation */

int func1(int a, char b) {
	return 0;
}

char func2(void) {
	return 'a';
}

void func3(int *a, int b) {
	int *c;

	c = a + b;
}

void func4(int a, int b, int *c, int d)
{
}

void func5(int a, int c, int d[10], int *j[10])
{
}

void func6(int d[10])
{
}

int main(void) {
	int a;
	char b;
	int k[10];
	int *kk[10];

	int c;
	char d;

	a = 1;
	b = 'c';

	c = func1(a, b);
	c = func1(a, b, b); /* error */
	c = func1(a, b);
	d = func2(b); /* error */
	d = func2();
	
	func3(&a, c);
	func3(&b, a); /* error */

	d = func1(a, b); /* error */
	c = func3(&c, d); /* error */

	func4(a,a,&a,a);

	func5(a, a, k, kk);

	func6(k);

	return 0;
}
