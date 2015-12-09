struct changhyun{int a; int b; int c; struct doogie{int d; int e;} jj;};

int test(struct changhyun a[10], int b, int c[4]){
	return b;
}

int main(){
	struct changhyun i[10];
	int j;
	int k[4];
	int l;

	j = 2;
	k[3] = 3;

	l = test(i, 4, k);
}
