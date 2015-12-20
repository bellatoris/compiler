struct str3{int a; int b;};

struct str3 kk(){
    struct str3 stt;
    stt.a = 3;
    stt.b = 4;
    return stt;
}

int main()
{
    struct str3 a;
    a = kk();
    write_int(a.a);
}
