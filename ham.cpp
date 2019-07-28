#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,j,m,r,p,n,err,d,x;
    cout<<"Enter the no of message bits:m= \n";
    cin>>m;
    cout<<"\nEnter the message bits:\n";
    int a[m];
 
    for(i=m;i>0;i--)
   cin>>a[i];
   cout<<"\n";
    r=0;
    while((m+r+1)> pow(2,r))
    r++;
    for(i=m;i>0;i--)
    cout<<a[i];
 
    cout<<"\n The no of redundancy bits to add r :"<<r;
    n=r+m;
    int b[n];
 
    for(i=1,p=0,j=1;i<=n;i++)
    {
        if(i == pow(2,p))
        {
            b[i]=0;
            p++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
    }
    cout<<"The dummy hamming code is:\n";
     for(i=n;i>0;i--)
     cout<<b[i];
      cout<<"\n";
 
     for(i=1,x=0;i<pow(2,r);i=pow(2,x))
     {
         for(j=1;j<=n;j++)
         {
             if((i&j)==i)
             b[i]=b[i]^b[j];
         }
         x++;
         cout<<"\n"<<b[i]<<"  "<<i;
 
     }
     cout<<"The final hamming code is:\n";
       for(i=n;i>0;i--)
     cout<<b[i];
     cout<<"\nThe value of bit to change:";
     cin>>err;
      if(b[err]==0)
      b[err]=1;
      else
      b[err]=0;
      cout<<"The new error code is:\n";
     for(i=n;i>0;i--)
     cout<<b[i];
     cout<<"\n";
     
   
     for(i=1,x=0;i<pow(2,r);i=pow(2,x))
     {
         for(j=1;j<=n;j++)
         {
             if((i&j)==i)
             b[i]=b[i]^b[j];
         }
         x++;
         cout<<"\n"<<b[i]<<"  "<<i;
 
     }
     
cout<<b[4]<<b[2]<<b[1]<<endl;
     
     return 0;
 
 
}
