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
  int terminal;
  int comb;
  int direct1;
  int direct2;
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

void buscar_Terminales(vector <Estacion> &metro)
{
	for(int i=0;i<metro.size();i++)
	{
		if(metro[i].id!=0)
		{
			if(metro[i-1].id==0 || metro[i+1].id==0)
			{
				metro[i].terminal=1;
			}
			else
			{
				metro[i].terminal=0;
			}
		}
	}
}

int buscar_Estacion(vector <Estacion> &metro, string inic, string final, int *in, int *fin)
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
void buscar_Direcciones(vector <Estacion> &metro)
{
	for(int i=0;i<metro.size();i++)
	{
		if(metro[i].id!=0)
		{
			metro[i].direct1= metro[i+1].id;
			metro[i].direct2= metro[i-1].id;
		}
	}
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

void buscando_Opciones(vector <Estacion> &metro, int *cont, string &cam, int inic, int des, vector <string> &posibles, vector <int> &valores)
{
	int movd,movi,contd,conti,checkd=0,checki=0;
	string caminod,caminoi,can;
	if(*cont>50)
	{
		*cont=1000;
	}
	else
	{
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

void planificar_Viaje(vector <Estacion> &metro, int ini, int des)
{
	string recorrido=metro[ini].nombre;
	vector <string> posibles;
	vector <int> valores;
	int cont=0,menor=999,indice;

	if(ini==des)
	{
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
				indice=i;
			}
		}
		cout<<posibles[indice]<<endl;
	}
}


int main(int argc, char* argv[])
{
	vector <Estacion> metro;
	string hola=argv[1];
	string inic=argv[2];
	string final=argv[3];
	int in,fin;

	if(argc==4)
	{
		if(hola=="-v")
		{
			imprimir_Nombres();
		}
		else
		{
			if(hola=="-f")
			{
				llenar_Metro(metro);
				if(buscar_Estacion(metro,inic,final,&in,&fin)==2)
				{	
					buscar_Terminales(metro);
					buscar_Direcciones(metro);
					buscar_Combis(metro);
					planificar_Viaje(metro,in,fin);
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
	}
	else
	{
		cout<<"Error en datos ingresados"<<endl;
	}
}