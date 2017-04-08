#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	char palabra[100]={'0'};
	int numero,letras=0,resp;
	
	
	cout<<"que quieres opcion quieres tomar?\n1.Codificar\n2.Decodificar\nR:";
	cin>>resp;
	
	switch (resp){
	
	case 1:
	cout<<"Ingrese una palabra para codificarla:";
	cin>>palabra;
	cout<<"Ingrese el valor que tendra la codificacion:";
	cin>>numero;
	
	for(int x=0;x<100;x++){
		if(palabra[x]!='0' && palabra[x]!='\0'){
			letras++;
		}
	}

	for(int x=0;x<letras;x++){
		palabra[x]=palabra[x]-((numero%26));
		
		if(palabra[x]<65){
			palabra[x]=palabra[x]+26;
		}
		
	}
	cout<<"su palabra codificada es:"<<palabra;
	
	break;
	
	case 2:
		cout<<"Ingrese una palabra para decodificarla:";
		cin>>palabra;
		cout<<"Ingrese el valor que tendra la decodificacion:";
		cin>>numero;
	
			for(int x=0;x<100;x++){
				if(palabra[x]!='0' && palabra[x]!='\0'){
					letras++;
				}
			}

			for(int x=0;x<letras;x++){
				palabra[x]=palabra[x]+((numero%26)-1);
		
				if(palabra[x]>90){
					palabra[x]=palabra[x]-26;
				}	
			}
			cout<<"su palabra decodificada es:"<<palabra;
	
	break;
	}
	return 0;
}
