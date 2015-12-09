struct _a3
{
    int a;
    int b;
    int c;
};

struct _a6
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct _fff
{
    struct _a3 aa;
    struct _a6 bb;
    struct _a3 cc;
} zzz;

struct _a6 make_default_a6()
{
    struct _a6 ret;
    ret.a = 11;
    ret.b = 12;
    ret.c = 13;
    ret.d = 14;
    ret.e = 15;
    ret.f = 16;
    return ret;
}

struct _a3 make_default_a3()
{
    struct _a3 ret;
    ret.a = 21;
    ret.b = 22;
    ret.c = 23;
    return ret;
}

struct _fff make_default_fff()
{
    struct _fff aaa;
    aaa.aa = make_default_a3();
    aaa.bb = make_default_a6();
    aaa.cc = make_default_a3();
    return aaa;
}

int main(){

    zzz.aa = make_default_a3();
    zzz.bb = make_default_a6();
    zzz.cc = make_default_a3();
    
    write_int(zzz.aa.a); write_string("\n");
    write_int(zzz.aa.b); write_string("\n");
    write_int(zzz.aa.c); write_string("\n");
    
    write_int(zzz.bb.a); write_string("\n");
    write_int(zzz.bb.b); write_string("\n");
    write_int(zzz.bb.c); write_string("\n");
    write_int(zzz.bb.d); write_string("\n");
    write_int(zzz.bb.e); write_string("\n");
    write_int(zzz.bb.f); write_string("\n");
    
    write_int(zzz.cc.a); write_string("\n");
    write_int(zzz.cc.b); write_string("\n");
    write_int(zzz.cc.c); write_string("\n");
 
    
    write_int(make_default_a3().a); write_string("\n");
    write_int(make_default_a3().b); write_string("\n");
    write_int(make_default_a3().c); write_string("\n");
    
    write_int(make_default_fff().aa.a); write_string("\n");
    write_int(make_default_fff().aa.b); write_string("\n");
    write_int(make_default_fff().aa.c); write_string("\n");
    
    write_int(make_default_fff().bb.a); write_string("\n");
    write_int(make_default_fff().bb.b); write_string("\n");
    write_int(make_default_fff().bb.c); write_string("\n");

    write_int(make_default_fff().cc.a); write_string("\n");
    write_int(make_default_fff().cc.b); write_string("\n");
    write_int(make_default_fff().cc.c); write_string("\n");
    
    return 0;
}