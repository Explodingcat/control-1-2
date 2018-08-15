#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void imprimir_Nombres()
{
	cout<<"Felipe Roa Aguilera"<<endl;
	cout<<"Carolina Martinez Valenzuela"<<endl;
	cout<<"Mario Miranda Luengo"<<endl;
}


void separar_Entrada(char * entrada, string prog[3])
{
	string enter=entrada;
	int pos;
	for(int i=0;i<3;i++)
	{
		pos=enter.find(" ");
		prog[i]=enter.substr(0,pos);
		enter=enter.substr(pos+1);
	}

} 

void buscar_Linea(string inicio, string destino)
{
	
}

int main(int argc, char* argv[])
{
	string programa[3];
	separar_Entrada(argv[1],programa);
	if(programa[0]=="-v")
	{
		imprimir_Nombres();
	}
	else
	{
		if(programa[0]=="-f")
		{

		}
		else
		{
			cout<<"Entrada Invalida"<<endl;
		}
	}
}