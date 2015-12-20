struct str{int i; int j; struct str1{int k; int l;}k;} a;
int main(){
    struct str1 b;
    a.k.k = 3;
    a.k.l = 4;
    b.k = 4;
    b.l = 5;

    

    write_int(b.k);
    write_string("\n");
    write_int(b.l);
    write_string("\n");

}
