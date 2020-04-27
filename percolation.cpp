#include<iostream>
#include<iomanip>
using namespace std;
class percolate{
    public:
    int grid_num;
    int perc[100][100];
    int printar[100][100];
    int open_sites = 0;

    bool isconnected(int p, int q, int r, int s){
        if(perc[p][r]==1&&perc[q][s]){
            return true;
        }
        return false;
    }

    void union_cell(int p, int q, int r, int s){
        perc[p][r] = 1;
        perc[q][s] = 1;
    }

    bool move1(int r, int c){
        int bottom = grid_num-1;
        int temp_arr[2];
        if(r<bottom&&isconnected(r,r+1,c,c)){
                //printar[r][c] = 1;
                if(move1(r+1, c)){
                        printar[r+1][c] = 1;
                        return true;}
        }
        else if(r == bottom){
            printar[r+1][c] = 1;
            return true;
        }
        if(c<grid_num-1&&isconnected(r,r,c+1,c)){
            if(move1(r,c+1)){
                    printar[r+1][c] = 1;
                    return true;}
        }
        //cout<<"moving done"<<endl;
        return false;
    }
    bool perc_test(){
        int first_row = 0;
        //cout<<"perctest started"<<endl;
        for(int i = 0;i<grid_num;i++){
            if(perc[first_row][i]==1){
                //printar[0][i] = 1;
                if(move1(first_row, i))
                    return true;
            }
        }
        //cout<<"perctest done"<<endl;
        return false;
    }

    int percolation_open(int n){
        grid_num = n;
        bool test = false;
        for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                perc[i][j] = 0;
                printar[i][j] = 0;}}
        while(test==false){
            int id1 = rand()%(n);
            int id2 = rand()%(n);
            int id3 = rand()%(n);
            int id4 = rand()%(n);
            //cout<<id1<<" "<<id2<<" "<<id3<<" "<<id4<<endl;
            bool con_test = isconnected(id1, id2, id3, id4);
            if(con_test==false){
                union_cell(id1, id2, id3, id4);
                test = perc_test();
                //cout<<"percolation test"<<endl;
                //cout<<open_sites<<endl;
                }
        }
        cout<<"test done"<<endl;
        int count0 = 0;
        for(int i = 0;i<n;i++){
            for(int j =0 ;j<n;j++){
                if(perc[i][j]==0){
                    count0++;
                }
                cout<<perc[i][j]<<" ";
            }
            cout<<"\n";
        }
        int id = 0;
        for(int i = 1;i<=1;i++){
            for(int j = 0;j<n;j++){
                if(printar[i][j]==1){
                    id = j;
                }
            }
        }
        printar[0][id] = 1;
        cout<<"printarr"<<endl;
        for(int i = 0;i<n;i++){
            for(int j =0 ;j<n;j++){
                if(perc[i][j]==1){
                    open_sites++;
                }
                cout<<printar[i][j]<<" ";
            }
            cout<<"\n";
        }
        return ((n*n)-count0);
}

};
int main(){
    percolate obj1;
    int n;
    cout<<"enter any number - ";
    cin>>n;
    int open = obj1.percolation_open(n);
    float thresh = float(open)/float((n*n));
    cout<<open<<endl;
    cout<<setprecision(2)<<thresh<<endl;
}
