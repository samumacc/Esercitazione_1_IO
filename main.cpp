#include <iostream>
#include <fstream>
#include <Eigen/Eigen>
using namespace Eigen;

double f(double a) //definisco funzione prima, poi nel main posso chiamarla
{
    double h = (3*a-7)/4;
    return h;
}


int main()
{
    //std::cout<<f(5)<<std::endl;

    std::string nameFile = "data.csv";
    std::ifstream ifstr(nameFile);
    if(ifstr.fail())
    {
        std::cerr<<"Error: file not found"<<std::endl;
        return 1;
    }

    std::ofstream fout("result.csv");

    double val = 0;
    double mean = 0;
    double sum = 0;
    unsigned int N = 0;
    unsigned int valoriCampione = 0;

    //RowVectorXd v = Vector2d::Zero(); vettore per valori es >= 2: per poterlo poi printare, deve esistere fuori dal ciclo: se creo nel ciclo, quando ci esco smette di esistere!
    while(ifstr >> val) //memorizzo in val il valore dal file, poi ciclo
    {
        //prendere tutti i valori ad es <= 2 dal file:
        //if(val <= 2)
        //{
           // v.conservativeResize(valoriCampione+1); //aggiungo ogni volta uno spazio nel vettore, per poter inserire questo val (inizializzato vettore a 2 componenti ma a caso, poi al primo val che prendo metto ad 1 e avanti si ingrandisce sempre di più)
          //  v[valoriCampione] = val;
            //valoriCampione++; //conto quanti valori ci sono <= di 2


        //}
        std::cout<<f(val)<<std::endl;

        sum += val;
        N++;
        mean = sum/N;
        fout << mean; //metto in file result la media per ogni iterazione
    }
    mean = sum/N;
    ifstr.close();
    fout.close();

    std::cout<<"media finale:"<<mean<<std::endl;
    std::cout<<"numero valori:"<<N<<std::endl;
    //std::cout<<"Ci sono "<<valoriCampione<<" valori tra -1 e 2, sono: "<< v << std::endl;


    std::ifstream file2("result.csv");
    if(file2.fail())
    {
        std::cerr<<"file non trovato"<<std::endl;
        return 2;
    }
    double valore = 0;
    int num = 0;

    while(file2 >> valore)
    {
        num++;
    }
    std::cout<<"Ci sono "<<num<<" valori nel file result"<<std::endl;


    return 0;
}
