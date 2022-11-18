#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>

using namespace std;

struct numeros
{
	 int n1;
	 int n2;
	 int n3;
	 int n4;
	 int n5;
	 int n6;
};

float bubble(long i, long j, const long tam, long aux, vector<numeros> A)
{
	clock_t t;
	auto start = chrono::system_clock::now();
	for(i=0;i<tam;i++)
	{
		for(j=0; j<(tam -1);j++)
		{
			if(A.at(j).n1>A.at(j+1).n1)
			{
				aux=A.at(j).n1;
				A.at(j).n1=A.at(j+1).n1;
				A.at(j+1).n1=aux;	
			}
		}
	}
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}
float selection(const long tam, long i, long j, long aux, vector <numeros> A)
{
	long int minimo;
	clock_t t;
	auto start = chrono::system_clock::now();
	for(i=0; i<tam-1; i++)
	{
		minimo=i;
		for(j=i+1; j<tam;j++)
		{
			if(A.at(j).n2<A.at(minimo).n2)
			minimo=j;
		}
		if (minimo!=i)
		{
			aux=A.at(i).n2;
			A.at(i).n2=A.at(minimo).n2;
			A.at(minimo).n2=aux;
		}
	}
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}
float insertion(const long tam, long i, long j, vector <numeros> A)
{
	long valor;
	clock_t t;
	auto start = chrono::system_clock::now();
	for(i=1;i<tam;i++)
	{
		valor=A.at(i).n3;
		j=i;
		while(j>0 && A.at(j-1).n3>valor)
		{
			A.at(j).n3=A.at(j-1).n3;
			j--;
		};
		A.at(j).n3=valor;
	}
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}
float shell(const long tam, long i, long j, long aux, vector <numeros> A)
{
	long incremento;
	clock_t t;
	auto start = chrono::system_clock::now();
	incremento=tam/2;
	while(incremento>0)
	{
		for(i=incremento;i<tam;i++)
		{
			aux=A.at(i).n4;
			j=i-incremento;
			while(j>=0 && aux<A.at(j).n4)
			{
				A.at(j+incremento).n4=A.at(j).n4;
				j=j-incremento;
			}
			A.at(j+incremento).n4=aux;
		}
		incremento/=2;
	}
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}
void merge(vector <numeros> A,int inicio, int mitad, int final)
{
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    numeros izquierda[elementosIzq];
    numeros derecha[elementosDer];

    for(int i = 0; i < elementosIzq; i++)
	{
        izquierda[i].n5 = A[inicio+i].n5;
    }
    for(int j = 0; j < elementosDer; j++)
	{
        derecha[j].n5 = A[mitad + 1 + j].n5;
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer)
	{
        if(izquierda[i].n5 <= derecha[j].n5)
		{
            A.at(k).n5 = izquierda[i].n5;
            i++;
        }else
		{
            A.at(k).n5 = derecha[j].n5;
            j++;
        }
        k++;
    }

    while(j < elementosDer)
	{
        A.at(k).n5 = derecha[j].n5;
        j++;
        k++;
    }

    while(i < elementosIzq)
	{
        A.at(k).n5 = izquierda[i].n5;
        i++;
        k++;
    }

}
float mergeSort(vector<numeros> A,int inicio, int final)
{
	clock_t t;
	auto start = chrono::system_clock::now();
    if(inicio < final)
	{
        int mitad = inicio + (final - inicio)/2;
        mergeSort(A,inicio,mitad);
        mergeSort(A,mitad+1,final);
        merge(A,inicio,mitad,final);
    }
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}
void swap(int &a,int &b)
{
    int aux = a;
    a = b;
    b = aux;
}
int particion(vector <numeros> A,int inicio, int fin)
{
    int pivote = A.at(inicio).n6;
    int i = inicio + 1;
    for(int j = i; j <= fin; j++)
	{
        if(A.at(j).n6 < pivote)
		{
            swap(A.at(i).n6,A.at(j).n6);
            i++;
        }
    }
    swap(A.at(inicio).n6,A.at(i-1).n6);
    return i-1;
}
float quickSort(vector <numeros> A, int inicio, int fin)
{
	clock_t t;
	auto start = chrono::system_clock::now();
    if(inicio < fin){
        int pivote = particion(A,inicio,fin);
        quickSort(A,inicio,pivote-1);
        quickSort(A,pivote+1,fin);
    }
	auto end = chrono::system_clock::now();
	chrono::duration<float,milli> duration = end - start;
	float tiempo = duration.count();	
	return tiempo;
}

int main()
{
	srand(time(NULL));
	int op, opo;
	int numero;
	const long tam = 40000;
	long aux, i, j;
	float t1=0, t2=0, t3=0, t4=0, t5=0, t6=0;
	vector <numeros> A(tam);
	for(long i=0; i<tam; i++)
	{
		numero = 1+rand()%(5001-1);
		A.at(i).n1= numero;
		A.at(i).n2= numero;
		A.at(i).n3= numero;
		A.at(i).n4= numero;
		A.at(i).n5= numero;
		A.at(i).n6= numero;
	}
	
	do
	{
		cout<<"\n\t* * *MENU* * *"<<endl;
		cout<<"1.-Ordenamiento de Datos"<<endl;
		cout<<"2.-Busqueda de Datos"<<endl;
		cout<<"3.-Salir"<<endl;
		do{
			cout<<"\nSeleccione una opcion: ";
			cin>>op;
			if(op<1 || op>3)
				cout<<"Error...!Opcion incorrecta\n";
		}while(op<1 | op>3);
		switch(op)
		{
			case 1:
				do
				{
					cout<<"\n\tMENU ORDENAMIENTO"<<endl;
					cout<<"1) Metodo de la Burbuja"<<endl;
					cout<<"2) Metodo de Seleccion"<<endl;
					cout<<"3) Metodo de Insercion"<<endl;
					cout<<"4) Metodo Shell"<<endl;
					cout<<"5) Metodo MergeSort"<<endl;
					cout<<"6) Metodo Quick Sort"<<endl;
					cout<<"7) Tabla de tiempos de ejecucion"<<endl;
					cout<<"8) Salir"<<endl;
					do
					{
						cout<<"\nSeleccione una opcion: ";
						cin>>opo;
						if(opo<1 || opo>8)	
							cout<<"Error...!Opcion incorrecta\n";
					}while(opo<1 || opo>8);	
					switch(opo)
					{
						case 1: 
							t1 = bubble(i, j, tam, aux, A);
							cout<<"\nARREGLO ORDENADO"<<endl;
							break;
						case 2:
							t2 = selection(tam, i, j, aux, A);
							cout<<"\nARREGLO ORDENADO"<<endl;
						break;
						case 3:
							t3 = insertion(tam, i, j, A);
							cout<<"\nARREGLO ORDENADO"<<endl;
							break;
						case 4:
							t4 = shell(tam, i, j, aux, A);
							cout<<"\nARREGLO ORDENADO"<<endl;
							break;
						case 5:
							t5 = mergeSort(A, 0, tam-1);
							cout<<"\nARREGLO ORDENADO"<<endl;
							break;	
						case 6:
							t6 = quickSort(A,0,tam-1);
							cout<<"\nARREGLO ORDENADO"<<endl;
							break;
						case 7:
							cout<<"\tTABLA DE TIEMPOS"<<endl;	
							cout<<"1) Metodo de la Burbuja: "<<t1<<"milisegundos"<<endl;
							cout<<"2) Metodo de Seleccion: "<<t2<<"milisegundos"<<endl;
							cout<<"3) Metodo de Insercion: "<<t3<<"milisegundos"<<endl;
							cout<<"4) Metodo Shell: "<<t4<<"milisegundos"<<endl;
							cout<<"5) Metodo MergeSort: "<<t5<<"milisegundos"<<endl;
							cout<<"6) Metodo Quick Sort: "<<t6<<"milisegundos"<<endl;	
							break;
					}
				}while(opo!=8);
				break;
		}
	} while(op!=3);
		
	return 0;
}
