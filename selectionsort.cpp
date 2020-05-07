#include<iostream>
using namespace std;

template <typename item>
class Sort{
    public:
    int n;
    item* arr;
    void createarray(int Size);
    bool lessthan(int a, int b);
    void exchange(int c, int d);
    void printarray();
};

template <typename item>
void Sort<item>::createarray(int Size){
    n = Size;
    arr = new item[Size];
    cout<<"enter the elements of the array - ";
    for(int i=0;i<Size;i++){
        cin>>arr[i];
    }
}

template <typename item>
bool Sort<item>::lessthan(int a, int b){
    return arr[a]<arr[b];
}

template <typename item>
void Sort<item>::exchange(int c, int d){
    item temp;
    temp = arr[c];
    arr[c] = arr[d];
    arr[d] = temp;
}

template <typename item>
void Sort<item>::printarray(){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";    }
}

int main(){
    int n;
    cout<<"enter the number of elements - ";
    cin>>n;
    cout<<"enter the data type - ";
    char r[10];
    cin>>r;

    Sort<string> s;
    s.createarray(n);
    for(int i = 0;i<n;i++){
        int tempmin = i;
        for(int j = i+1;j<n;j++){
                if(s.lessthan(j,tempmin)){
                    tempmin = j;
                    }
        }
        s.exchange(i, tempmin);
    }
    cout<<"sorted array - "<<endl;
    s.printarray();
}
