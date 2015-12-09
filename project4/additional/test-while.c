int global1;
int global2;

struct _str1 {
        int x;
        int y;
        struct _str2 {
                int z;
                int w[5];
        }strstr;
} sample_str;

int outprint(int *j)
{
        *j = *j + 10;
        write_string("\n");
        write_string("*j = ");
        write_int(*j);
        write_string("\n");
        return *j;
}

void main()
{
        int i;
        int j;
        int k;
        int *l;
        struct _str1 teststr[10];

        i = 0; j = 0; k = 10;

        l = &k;
        sample_str.strstr.z = 1000;
        write_string("sample_str.strstr.z = ");
        write_int(sample_str.strstr.z);
        write_string("\n");

        while (i < 10) {
                teststr[i].y = i - 10;
                teststr[i].strstr.w[3] = 10;
				i++;
        }

        write_string("\n");
        while (j < 10) {
                write_string("teststr[j].y = ");
                write_int(teststr[j].y);
                write_string("\n");
                j++;
        }
        i = outprint(l);

        write_string("outprint(l) = ");
        write_int(i);
        write_string("\n");
}
