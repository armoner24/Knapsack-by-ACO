#include<stdio.h>
#include<stdlib.h>
float prob(int N[],int j,float t[],float u[],int n)
{

      float sum=0;;
        int i;
        for(i=0;i<n;i++)
            if(N[i]==1)
                sum+=t[i]*u[i];


        return (float)(t[j]*u[j])/sum;

}
int nextBool(double probability)
{
    return (int)(rand() <  probability * ((double)RAND_MAX + 1.0));
}
void probablity(int a[],int b[],int c);
int Best_profit;
int allowed_weight=8;
main()
{   int n;
    printf("Enter the size of knapsack/items ");
    scanf("%d",&n);
    int w[n],c[n],i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the weight of object  ");
        scanf("%d",&w[i]);
        printf("\nEnter the cost of the object  ");
        scanf("%d",&c[i]);
    }
    printf("\nEnter the allowed weight ");
    scanf("%d",&allowed_weight);
    int sizes=n,j;
    float t[n];
    float u[n];
    for(j=0;j<n;j++)
    {
        t[j]=1;
        u[j]=c[i]/w[i];
    }
    int ants=100;


    int aplha=3;
    int beta=2;
    int best_profit=0;

    probablity(w,c,sizes);
    while(ants--)
    {                                                                                                                                                           }
        while(sizes--)
        {   int Vc=allowed_weight;
            int N[n],i=0,curr_profit=0,k;
            for(k=0;k<n;k++)
            {
                N[k]=0;
            }
            while(Vc>0&&i<4)
            {
                if(nextBool(prob(N,i,t,u,sizes))==1)
                {
                    N[i]=1;
                    Vc=Vc-w[i];
                    curr_profit+=c[i];

                }

            i++;
            }



            if(curr_profit>best_profit)
                        best_profit=curr_profit;
            for(k=0;k<n;k++)
                if(N[k]==1)
                    t[k]+=1/(1+(best_profit-curr_profit)/(float)best_profit);
                else
                    t[k]=t[k]*0.5;






    }
printf("\n%d",Best_profit);
}
