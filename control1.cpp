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


void buscar_Linea(string inicio, string destino)
{
	
}

int main(int argc, char* argv[])
{
	string hola=argv[1];
	if(hola=="-v")
	{
		imprimir_Nombres();
	}
	else
	{
		if(hola=="-f")
		{

		}
		else
		{
			cout<<"Entrada Invalida"<<endl;
		}
	}
}