int main()
{
    struct str{int a; int b; struct st2{int c; int d;}str2;}str1;
    struct st2 kk;
    kk.c = 3;
    kk.d = 5;
    str1.str2 = kk;
    write_int(str1.str2.c);

}
