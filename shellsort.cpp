#include<iostream>
using namespace std;

int main(){
    int n, temp;
    cout<<"enter the number of elements - "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array - "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int h = 1, k = 0;
    while(h<n/3){
        h = (3*h+1);
    }
    cout<<"the value of h is - "<<h<<endl;
    while(h>=1){
    for(int i=h;i<n;i++){
        for(int j=i;j>=h;j=j-h){
                if(arr[j]<arr[j-h]){
                    temp = arr[j];
                    arr[j] = arr[j-h];
                    arr[j-h] = temp;
                }
        }
    }
    h = h/3;
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
