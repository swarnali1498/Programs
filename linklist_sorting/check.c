void check()
{
    int ar[5];
    int i,j;
    printf("\nEnter elements in array : ");
    for(i=0;i<5;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",ar[i]);
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(ar[j]>ar[j+1])
            {
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",ar[i]);
    }
}
