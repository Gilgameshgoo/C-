#include <iostream>
#include  <limits>
#include <list>
#include <iterator>

using namespace std;
int  imax = 214748;


class Diller{


private:

public:


    int **mas; //Указатель на матрицу весов у вершин
    int *vmas[2]; // Указатель на матрицу Вектора stage 2
    int N=7;     // Размерность графа
    int Bl=7;
    int Bs;
    
    Diller(){
        mas = new int *[N + 1];

        for (int x = 1; x <= N; x++) {
            mas[x] = new int[N+1];
            for (int y = 1; y <= N; y++) {
                if(x==y){mas[x][y] = 0;}
                else{mas[x][y]=imax;}
            }
        }
        for(int* &x: vmas){
            x= new int[N+1];
        }

        
        mas[1][2] = 5;
        mas[1][3] = 3;
        mas[1][4] = 5;
        mas[1][5] = 6;
        mas[1][6] = 8;


        mas[2][4] = 1;
        mas[2][5] = 4;

        mas[3][5] = 2;


        mas[4][5] = 3;
        mas[4][6] = 5;

        mas[5][6] = 4;

        mas[5][7] = 6;
        mas[6][7] = 5;


        for(int x =1;x<=N;x++){
            vmas[0][x]=mas[x][Bl];
        }
    }

    bool Comparer() {               
        bool value= true;

        for (int x=1;x<=N;x++){
            if (vmas[0][x] != vmas[1][x]){
                value = false;
                break;
            }
        }
        return value;
    }


    int Getting_Min_Element(int vertex){
        int vr[N+1];

        for(int x=1;x<=N;x++) {
            if(vertex != x){ vr[x]= mas[vertex][x] + vmas[0][x];
            }
            else if(x==Bl){vr[x]=0;}
            else{vr[x]=imax;}
        }

        int value = imax;
        for (int x = 1; x <= N; x++) {
            if (vr[x] < value) {
                value = vr[x];

            }
        }
        return  value;

    }

    void VectroV() {                      // counting
        while (true) {
            for (int x = 1; x <= N; x++) {

                vmas[1][x] = Getting_Min_Element(x);
            }

            if (Comparer()) {break; }
            else { vmas[0] = vmas[1];}
        }
    }


    void Printer() {
        for (int x = 1; x <= N; x++) {
            cout << vmas[1][x] << endl;

        }
    }


    void Set_Source(){
        cout<<"Choose source Vertex"<<endl;
        cin>>Bs;
    };

    void Set_Final(){
        cout<<"Choose final Vertex"<<endl;
        cin >>Bl;

    };

};
