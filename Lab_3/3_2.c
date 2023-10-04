#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r,c,i,j,count1=0,co1=0,count2=0,co2=0;
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&r,&c);
    int sparse1[r][c],sparse2[r][c];
    printf("Enter matrix 1 elements :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&sparse1[i][j]);
            if(sparse1[i][j]==0)
            count1++;
            else
            co1++;
        }
    }
    printf("Enter matrix 2 elements :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&sparse2[i][j]);
            if(sparse2[i][j]==0)
            count2++;
            else
            co2++;
        }
    }
    if(count2>co2&&count1>co1)
    {

        int tup1[co1+1][3],tup2[co2+1][3],k1=1,k2=1,k3=1,size=0;
        tup1[0][0]=r;
        tup1[0][1]=c;
        tup1[0][2]=co1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(sparse1[i][j]!=0)
                {
                    tup1[k1][0]=i;
                    tup1[k1][1]=j;
                    tup1[k1][2]=sparse1[i][j];
                    k1++;
                }
            }
        }
        printf("3 tuple form is :\n");
        for(i=0;i<=co1;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",tup1[i][j]);
            }
            printf("\n");
        }
        tup2[0][0]=r;
        tup2[0][1]=c;
        tup2[0][2]=co2;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(sparse2[i][j]!=0)
                 {
                    tup2[k2][0]=i;
                    tup2[k2][1]=j;
                    tup2[k2][2]=sparse2[i][j];
                    k2++;
                }
            }
        }
        printf("3 tuple form is :\n");
        for(i=0;i<=co2;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",tup2[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(sparse1[i][j]!=0||sparse2[i][j]!=0)
                size++;
            }
        }
        int tup3[size+1][3];
        tup3[0][0]=r;
        tup3[0][1]=c;
        tup3[0][2]=size;
        for(i=1;i<=size;i++)
        {
            if(tup1[i][0]==tup2[i][0]&&tup1[i][1]==tup2[i][1])
            {
                tup3[k3][0]=tup1[k3][0];
                tup3[k3][1]=tup1[k3][1];
                 tup3[k3][2]=tup1[k3][2]+tup2[k3][2];
                k3++;
            }
            else
            {
                if(tup1[i][0]!=tup2[i][0]||tup1[i][1]!=tup2[i][1])
                {
                    tup3[k3][0]=tup1[i][0];
                    tup3[k3][1]=tup1[i][1];
                    tup3[k3][2]=tup1[i][2];
                    k3++;
                    tup3[k3][0]=tup2[i][0];
                    tup3[k3][1]=tup2[i][1];
                    tup3[k3][2]=tup2[i][2];
                    k3++;
                }
            }
        }
        printf("Sum of sparse matrix is : \n");
        for(i=0;i<=size;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",tup3[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Not Sparse Matrix\n");
        exit(0);
    }
}

