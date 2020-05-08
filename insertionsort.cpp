#include<iostream>
using namespace std;

int main(){
    int n, temp;
    cout<<"enter the number of elements of array - "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array - "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
        }
    }
    cout<<"sorted array - "<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";    }
}
