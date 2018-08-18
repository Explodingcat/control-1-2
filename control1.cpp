#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 

using namespace std;

struct Estacion {
  int id;
  int linea;
  string cod;
  string nombre;
  int comb;
};

void imprimir_Nombres()
{
	cout<<"Felipe Roa Aguilera"<<endl;
	cout<<"Carolina Martinez Valenzuela"<<endl;
	cout<<"Mario Miranda Luengo"<<endl;
}

void llenar_Metro(vector <Estacion> &metro)
{
	Estacion a;
	string linea,cad4,cad3;
	int pos,cont=1,lin;
	ifstream fixero("estaciones.csv");
	while(!fixero.eof())
	{
		getline(fixero,linea);
		pos=linea.find(" ");
		cad4 = linea.substr(0,pos);
		pos=linea.find(" ")+1;
		cad3 =linea.substr(pos);
		pos=cad3.find(" ");
		if(cad4=="Línea")
		{
			pos=cad3.find(" ");
			cad3=cad3.substr(0,pos);
			if(cad3=="4a")
			{
				lin=3;
			}
			else
			{
				lin=atoi(cad3.c_str());
			}
			a.id=0;
			a.linea=0;
			a.nombre="";
			a.cod="";
			a.comb=0;
			metro.push_back(a);
		}
		else
		{
			a.id=cont;
			a.linea=lin;
			a.nombre=cad3;
			a.cod=cad4;
			a.comb=0;
			cont++;
			metro.push_back(a);
		}
	}
	metro.pop_back();
	Estacion b;
	b.id=0;
	b.linea=0;
	b.nombre="";
	b.cod="";
	b.comb=0;
	metro.push_back(b);
}


int buscar_Estacion(vector <Estacion> metro, string inic, string final, int *in, int *fin)
{
	int cont=0;
	for(int i=0;i<metro.size();i++)
	{
		if(metro[i].id!=0 && metro[i].cod==inic)
		{
			*in=i;
			cont++;
		}
		if(metro[i].id!=0 && metro[i].cod==final)
		{
			*fin=i;
			cont++;
		}
	}
	return cont;
}

void buscar_Combis(vector <Estacion> &metro)
{
	for(int i=0;i<metro.size();i++)
	{
		for(int j=0;j<metro.size();j++)
		{
			if(i!=j && metro[i].id!=0 && metro[j].id!=0 )
			{
				if(metro[i].nombre==metro[j].nombre && metro[i].comb==0)
				{
					metro[i].comb=metro[j].linea;
					metro[j].comb=metro[i].linea;
				}
			}
		}
	}
}

void buscando_Opciones(vector <Estacion> metro, int *cont, string &cam, int inic, int des, vector <string> &posibles, vector <int> &valores)
{
	int movd,movi,contd,conti,checkd=0,checki=0,aux;
	string caminod,caminoi,can;
	if(*cont>50)
	{
		*cont=1000;
	}
	else
	{
		if(*cont==0 && metro[inic].comb!=0)
		{
			for(int i=0;i<metro.size();i++)
			{
				if(metro[inic].nombre==metro[i].nombre && inic!=i)
				{
					aux=-1;
					buscando_Opciones(metro,&aux,cam,i,des,posibles,valores);
				}
			}
		}
		if(*cont==-1)
		*cont=0;
		contd=*cont;
		caminod=cam;
		movd=inic+1;
		while(metro[movd].id!=0 && checkd==0)
		{
			contd++;
			caminod=caminod+"->"+metro[movd].nombre;
			if(movd==des)
			{
				checkd=1;
				posibles.push_back(caminod);
				valores.push_back(contd);
			}
			else
			{
				if(metro[movd].comb!=0)
				{
					for(int i=0;i<metro.size();i++)
					{
						if(metro[movd].nombre==metro[i].nombre && movd!=i)
						{
							if(metro[i].nombre==metro[des].nombre)
							{
								checkd=1;
								posibles.push_back(caminod);
								valores.push_back(contd);
							}
							else
							{
								buscando_Opciones(metro,&contd,caminod,i,des,posibles,valores);
							}
						}
					}
				}
			}
			
			movd++;
		}
		conti=*cont;
		caminoi=cam;
		movi=inic-1;
		while(metro[movi].id!=0 && checki==0)
		{
			conti++;
			caminoi=caminoi+"->"+metro[movi].nombre;
			if(movi==des)
			{
				posibles.push_back(caminoi);
				valores.push_back(conti);
				checki=1;
			}
			else
			{
				if(metro[movi].comb!=0)
				{
					for(int i=0;i<metro.size();i++)
					{
						if(metro[movi].nombre==metro[i].nombre && movi!=i)
						{
							if(metro[i].nombre==metro[des].nombre)
							{
								posibles.push_back(caminoi);
								valores.push_back(conti);
								checki=1;
							}
							else
							{
								buscando_Opciones(metro,&conti,caminoi,i,des,posibles,valores);
							}
						}
					}
				}
			}
			movi--;
		}
	}
}

void planificar_Viaje(vector <Estacion> metro, int ini, int des)
{
	string recorrido=metro[ini].nombre;
	vector <string> posibles;
	vector <int> valores;
	int cont=0,menor=999,redy=0;

	if(metro[ini].nombre==metro[des].nombre)
	{
		cout<<"_________________RUTA PLANIFICADA___________________"<<endl;
		cout<<metro[ini].nombre<<endl;	
	}
	else
	{
		buscando_Opciones(metro,&cont,recorrido,ini,des,posibles,valores);
		for(int i=0;i<valores.size();i++)
		{
			if(valores[i]<menor)
			{
				menor=valores[i];
			}
		}
		for(int i=0;i<valores.size();i++) //verifica si existen mas de 1 ruta menor y entrega todas las opciones
		{
			if(valores[i]==menor)
			{
				cout<<"_________________RUTA PLANIFICADA___________________"<<endl;
				cout<<posibles[i]<<endl;
				cout<<endl;
			}
		}
	}
	
}


int main(int argc, char* argv[])
{
	vector <Estacion> metro;
	string inic,final,hola;
	int in,fin;

	if(argc==2) 
	{
		hola=argv[1];
		if(hola=="-v")
		{
			imprimir_Nombres();
		}
		else
		{
			cout<<"Entrada Invalida"<<endl;
		}
	}
	else
	{
		if(argc==4)
		{
			hola=argv[1];
			if(hola=="-f")
			{
				inic=argv[2];
				final=argv[3];
				llenar_Metro(metro); //llena el vector de estaciones
				if(buscar_Estacion(metro,inic,final,&in,&fin)==2)
				{	
					buscar_Combis(metro); //funcion busca todas las estaciones que poseen estacion en mas de una linea, si lo encuentra guarda en variable comb el numero de la linea a la que combina.
					planificar_Viaje(metro,in,fin);//planifica 
				}
				else
				{
					cout<<"Verifique codigo estaciones"<<endl;
				}
			}
			else
			{
				cout<<"Entrada Invalida"<<endl;
			}
		}
		else
		{
			cout<<"Error en datos ingresados"<<endl;
		}
	}
}