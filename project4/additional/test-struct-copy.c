struct B{
	int x;
	int y;
	int z;
};

void foo2()
{
	struct B a;
	struct B b;
	struct B c;

	c.x= 100;
	c.y= 200;
	c.z= 300;
	
	a = b = c;

	b.x++;
	b.y++;
	b.z++;

	c.x++;
	c.y++;
	c.z++;

	c.x++;
	c.y++;
	c.z++;

	write_int(a.x); write_string("\n");
	write_int(a.y); write_string("\n");
	write_int(a.z); write_string("\n");

	write_int(b.x); write_string("\n");
	write_int(b.y); write_string("\n");
	write_int(b.z); write_string("\n");

	write_int(c.x); write_string("\n");
	write_int(c.y); write_string("\n");
	write_int(c.z); write_string("\n");
}



struct A
{
	int xa;
	int xb;
	int xc;
};

int main()
{
	struct A aa;		/* 3 words */
	struct A bb;		/* 3 words */
	struct A *cc;

	cc = &bb;

	aa.xa = 100;
	aa.xb = 200;
	aa.xc = 300;

	cc->xb = cc->xb+1;

	write_int(cc->xb);
	write_string("\n");

	write_int(bb.xb);
	write_string("\n");

	foo2();
}

