#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void insert(vector<int>&v,int n)
{
    cout<<"enter:";
    for(int i=0;i<n;i++)
        cin>>v[i];
}

void print(vector<int>v,int n)
{
    cout<<"array=";
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b; 
    *b=temp;
}
int partition(vector<int>&v,int l,int h)
{
    int r=l+rand()%(h-l);
    swap(&v[r],&v[h]);
    
    int p=h,j=l-1;
    for(int i=l;i<h;i++)
    {
        if(v[i]<=v[p]){
            j++;
            swap(&v[i],&v[j]);
        }
    }
    swap(&v[j+1],&v[p]);
    return j+1;
} 

void quick(vector<int>&v,int l,int h)
{
    int p;
    if(l<h)
    {
        p=partition(v,l,h);
        quick(v,l,p-1);
        quick(v,p+1,h);
    }
}

int main()
{
    int n;
    cout<<"enter size=";
    cin>>n;

    vector<int>v(n);
    
    insert(v,n);
    quick(v,0,n-1);
    print(v,n);

}
