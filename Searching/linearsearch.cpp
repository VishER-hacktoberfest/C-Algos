#include<iostream>
using namespace std;

int main(){
    int n, i, item, temp=-1;
    
    cout<<"How many elements you want to enter \n";
    cin>>n;
    int arr[n];
    cout<<"enter the elements : \n";

    for(i=0; i<n; i++){
        cin>>arr[i];
    }


    cout<<"enter the element to be searched : \n";
    cin>>item;
   for(i=0; i<n; i++){
        if(arr[i]==item){
            cout<<"Element found at index "<<i<<endl;
            temp=0;
           break;
        }
        }
        if(temp==-1){
            cout<<"Element is not found \n";
        }
    return 0;
}
