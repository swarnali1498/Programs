void sparse()
{
    int **ar,**s,r,c,i,j,z=0,nz=0,a=1;
    int op;
    printf("\nEnter number of rows and columns : ");
    scanf("%d%d",&r,&c);
    ar=(int**)malloc(r*sizeof(int*));
    for(i=0; i<r; i++)
    {
        ar[i]=(int*)malloc(c*sizeof(int));
    }
    printf("\nEnter elements in matrix : ");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    printf("\nOriginal matrix : \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d",&ar[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
           if(ar[i][j]!=0)
            z++;
           else
            nz++;
        }
    }
    s=(int**)malloc((nz+1)*sizeof(int*));
    for(i=0; i<(nz+1); i++)
    {
        s[i]=(int*)malloc(3*sizeof(int));
    }
    if((3*z)>((2*r*c)+3))
    {
        s[0][0]=r;
        s[0][1]=c;
        s[0][2]=nz;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(ar[i][j]!=0)
                {
                    s[a][0]=i;
                    s[a][1]=j;
                    s[a][2]=ar[i][j];
                    a++;
                }
            }
        }
        printf("\nSparse matrix is : \nROWS\tCOLUMNS\tNON-ZERO ELEMENTS");
        for(i=0; i<(nz+1); i++)
        printf("\n%d\t%d\t%d",s[i][0],s[i][1],s[i][2]);
        printf("\nTranspose sparse matrix is : \nROWS\tCOLUMNS\tNON-ZERO ELEMENTS");
        for(i=0; i<(nz+1); i++)
        printf("\n%d\t%d\t%d",s[i][1],s[i][0],s[i][2]);
        int w=sizeof(int);
        op=((r*c*w)-((nz+1)*3*w));
        float p=((float)op/(r*c*w))*100;
        printf("\nOptimization is : %d bytes, %f %",op,p);
    }
    else
        printf("\nSparse matrix is not beneficial");
    for(i=0; i<r; i++)
        free(ar[i]);
    free(ar);
    for(i=0; i<(nz+1); i++)
        free(s[i]);
    free(s);
}
