#include <iostream>
#include  <limits>
#include <list>
#include <iterator>


using namespace std;
class Diller{
private:
    int N=7;
    int **mas;
    int *vmas;
    int imax = numeric_limits<int>::max();
    int  Bs=1;
    int  Bl=5;

public:


    Diller() {
       mas = new int *[N + 1];

       vmas = new int[N + 1];

       for (int x = 1; x <= N; x++) {
           mas[x] = new int[N];
           for (int y = 1; y <= N; y++) {
               mas[x][y] = 0;
           }
       }

       mas[1][2] = 6;
       mas[1][3] = 6;
       mas[1][4] = 3;


       mas[2][3] = 2;
       mas[2][6] = 5;

       mas[3][6] = 5;
       mas[3][5] = 6;
       mas[3][7] = 2;


       mas[4][3] = 2;
       mas[4][7] = 3;

       mas[5][6] = 1;

       mas[7][5] = 3;
       mas[7][6] = 5;
   };

    void Min(){

       for (int x =1;x<=N;x++){
           if(x==Bs){vmas[x]=0;}
           else{vmas[x]=imax;}
       };


       for(int x=1;x<=N;x++){
           for (int y=1;y<=N;y++){
               if(mas[x][y]!=0){

                   if(vmas[y]-vmas[x]>mas[x][y]){
                       vmas[y]=mas[x][y]+vmas[x];

                   }
               }
           }
       }
       int k = Bl;
       int f = Bl;
       list<int> path;


        for(int x=N;x>=1;x--) {
            for (int y = 1; y <= N; y++) {

                if (y==k && mas[x][y]!=0) {

                    if (vmas[y] - vmas[x] ==  mas[x][y]) {
                        cout<<x<<endl;
                        cout << y << endl;
                        cout << vmas[x] << endl;
                        cout << vmas[y] << endl;
                        cout << mas[x][y] << endl;

                        cout<<endl;

                        path.push_back(x);

                        k = x;
                        f = x;


                    }
                }

            }
        }


        copy(path.begin(), path.end(), ostream_iterator<int>(cout," "));
        cout<<endl;

       for (int x =1;x<=N;x++){
           cout<<"Vershina num"<<x<<" : "<<vmas[x]<<endl;
       };


   }



    void Set_Source(){
        cout<<"Choose source Vertex"<<endl;
        cin>>Bs;
    };

    void Set_Final(){
        cout<<"Choose final Vertex"<<endl;
        cin >>Bl;

    };

    void Vvod(){
        cout<<"Vertexes amaount "<<endl;
        cin>>N;

        mas = new int*[N+1];

        vmas = new int[N+1];

        for(int x=1;x<=N;x++){
            mas[x]=new int[N];
            for (int y=1;y<=N;y++){
                mas[x][y]=0;
            }
        }


        for(int x=1;x<=N;x++){
            for (int y=1;y<=N;y++){
                cout<<"Vertex "<<x<<" to vertex "<<y<<endl;
                cin>>mas[x][y];
            }}

    };


};

