void add()
{
    int nz,nz1,i,j,k,**m,**n,**p;
    printf("\nEnter number of non-zero elements in first matrix : ");
    scanf("%d",&nz);
    m=(int**)malloc((nz+1)*sizeof(int*));
    for(i=0; i<(nz+1); i++)
        m[i]=(int*)malloc(3*sizeof(int));
    printf("\nEnter elements in first matrix in sparse matrix form : ");
    for(i=0; i<(nz+1); i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    printf("\nEnter number of non-zero elements in second matrix : ");
    scanf("%d",&nz1);
    n=(int**)malloc((nz1+1)*sizeof(int*));
    for(i=0; i<(nz1+1); i++)
        n[i]=(int*)malloc(3*sizeof(int));
    printf("\nEnter elements in second matrix in sparse matrix form : ");
    for(i=0; i<(nz1+1); i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&n[i][j]);
        }
    }
    printf("\nFirst sparse matrix : ");
    printf("\nROWS\tCOLUMNS\tNON-ZERO ELEMENTS");
    for(i=0; i<(nz+1); i++)
    {
        printf("\n%d\t%d\t%d",m[i][0],m[i][1],m[i][2]);
    }
    printf("\nSecond sparse matrix : ");
    printf("\nROWS\tCOLUMNS\tNON-ZERO ELEMENTS");
    for(i=0; i<(nz1+1); i++)
    {
       printf("\n%d\t%d\t%d",n[i][0],n[i][1],n[i][2]);
    }
    p=(int**)malloc((nz+nz1+1)*sizeof(int*));
    for(i=0; i<(nz+nz1+1); i++)
        p[i]=(int*)malloc(3*sizeof(int));
    k=1; i=1; j=1;
    p[0][0]=m[0][0]; p[0][1]=m[0][1];
    while(i<(nz+1) && j<(nz1+1))
    {
        if(m[i][0]==n[j][0] && m[i][1]==n[j][1])
        {
            p[k][0]=m[i][0];
            p[k][1]=m[i][1];
            p[k][2]=m[i][2]+n[j][2];
            i++; j++; k++;
        }
        else if(m[i][0]<n[j][0])
        {
            p[k][0]=m[i][0];
            p[k][1]=m[i][1];
            p[k][2]=m[i][2];
            i++; k++;
        }
        else if(m[i][0]>n[j][0])
        {
            p[k][0]=n[j][0];
            p[k][1]=n[j][1];
            p[k][2]=n[j][2];
            j++; k++;
        }
        else if(m[i][0]==n[j][0])
        {
            if(m[i][1]<n[j][1])
            {
                p[k][0]=m[i][0];
                p[k][1]=m[i][1];
                p[k][2]=m[i][2];
                i++; k++;
            }
            else
            {
                p[k][0]=n[j][0];
                p[k][1]=n[j][1];
                p[k][2]=n[j][2];
                j++; k++;
            }
        }
    }
    while(i<(nz+1))
    {
        p[k][0]=m[i][0];
        p[k][1]=m[i][1];
        p[k][2]=m[i][2];
        i++; k++;
    }
    while(j<(nz1+1))
    {
        p[k][0]=n[j][0];
        p[k][1]=n[j][1];
        p[k][2]=n[j][2];
        j++; k++;
    }k--;
    p=(int**)realloc(p,((k+1)*sizeof(int*)));
    for(i=0; i<(k+1); i++)
        p[i]=(int*)realloc(p[i],(3*sizeof(int)));
    p[0][2]=k;
    printf("\nROWS\tCOLUMNS\tNON-ZERO ELEMENTS");
    for(i=0; i<(k+1); i++)
        printf("\n%d\t%d\t%d",p[i][0],p[i][1],p[i][2]);
    for(i=0; i<(nz+1); i++)
        free(m[i]);
    free(m);
    for(i=0; i<(nz1+1); i++)
        free(n[i]);
    free(n);
    for(i=0; i<(k+1); i++)
        free(p[i]);
    free(p);
}
