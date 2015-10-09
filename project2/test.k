int main()
{
    int i;
    int j;
    int* k;
    k = &j;
    *k[1] = 3;


    for(j = 0; j < 3; j++)
    {
        i = j;
    }

    if(i==3)
    {
        i = 4;
    }
    
    if(j==3)
    {
        j = 4;
    }
   

    else
    {
        i = 4;
    }

}
