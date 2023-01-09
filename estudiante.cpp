#include <bits/stdc++.h>

using namespace std;

class Estudiante{
    private:
        string codi;
        string nomb;
        float prom;
    public:
        Estudiante(){};
        void inserEstudiante(){
            cout<<"\nCodigo: ";cin>>codi;
            cout<<"\nNombre: ";cin>>nomb;
            cout<<"\nPromedio: ";cin>>prom;
        }
        int operator <(Estudiante p){
            if(codi>p.getCodi()){
                return 1;
            }
        }
        void ImprimeEst(){
            cout<<codi<<"   "<<nomb<<"   "<<prom;
        }

        string getCodi(){
            return codi;
        }
        string getNomb(){
            return nomb;
        }
        float getProm(){
            return prom;
        }
};


void interDirecto(Estudiante A[], int n){
    string aux;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-2;j++){
            if(A[j]<A[j+1]){
                aux=A[j].getCodi();
                A[j]=A[j+1];
                A[j+1].getCodi()=aux;
            }
        }
    }
}


int main(){
    int n=0;
    cout<<"Inserte el numero de estudiantes: ";cin>>n;
    Estudiante estu[n];
    for(int i=0;i<n;n++){
        estu[i].inserEstudiante();
    }

    interDirecto(estu,n);

    ofstream archivo("estudiantes.txt",ios::app);
        if(!archivo.is_open()){
            cout<<"No se puede abrir el archivo"<<endl;
        }
        else{
        for(int i=0;i<n;i++){
            archivo<<"\n"<<estu[i].getCodi()<<"   "<<estu[i].getNomb()<<"   "<<estu[i].getProm();
            estu[i].getCodi()="\0";
        }
        archivo.close();
        }
        
    return 0;
}



