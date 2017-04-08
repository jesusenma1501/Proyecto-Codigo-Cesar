#include <iostream>
#include <conio.h>
#include<fstream>
#include<cctype>
#include<sstream>
#include <string>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool salir(string texto){
	bool verifica=true;
	int tam=texto.size();
	if(texto[tam-8]==':'&&texto[tam-7]=='S'&&texto[tam-6]=='A'&&texto[tam-5]=='C'&&texto[tam-4]=='A'&&texto[tam-3]=='M'&&texto[tam-2]=='E'){
		verifica=false;
	}
	return verifica;
       
}
bool entradaNumero(string entrada){
    bool valida=true;
    int tam=entrada.size();
	for(int i=0;i<tam;i++){
		if((entrada[i]<48 || entrada[i]>57)){
			valida=false;
			break;
		}
	}
	return valida;
}
bool validaNombre(string entrada){
	bool valida=true;
	int tam=entrada.size();
	for(int i=0;i<tam;i++){
		if((entrada[i]<=64 && entrada[i]>=65)&&(entrada[0]>=48 && entrada[0]<=57)){
	       valida=false;      
		}else if((entrada[i]!=32) && (entrada[i]<48||entrada[i]>57) && (entrada[i]<65||entrada[i]>90) && (entrada[i]<97|entrada[i]>122)){
		valida=false;
	   	}
	}
		return valida;

}

int main(int argc, char** argv) {
	char *nombre;
	int avanza=0,tam;
	string texto, mostrar, opc, temporal;
	bool verifica=true;
	cout<<"Bienvenido agente! Este programa le ayuda a codificar y decodificar\nmensajes.\n"<<endl;
	system("pause");
	system("cls");  
    do{
    	texto="";
    	system("cls");
	    cout<<"Digite la el numero que corresponda a la tarea que desea realizar...\n\n1) Codificar y guardar en archivo\n\n2)Decodificar un archivo\n\n3) Salir\n\nOpc:";
		cin>>opc;
		system("cls");
		if(opc=="1"){
			int bandera=0;	
			do{
				
				fflush(stdin);
			    bandera=0;   	
			 	cout<<"Ingrese el numero de codificacion : ";
				cin>>temporal;
				if(entradaNumero(temporal)==false){
			    	system("cls");
				    cout<<"Error! ingrese solo caracteres numericos enteros.\n";
				    system("pause");
				    system("cls");
				}else{	
					istringstream(temporal)>>avanza;
					bandera=1;
			    }
			}while(bandera==0);
			system("cls");
			verifica=true;
			while(verifica==true){
				fflush(stdin);
	 	        cout<<"Escriba el mensaje a codificar. Cuando desee salir escriba el comando \":SACAME\" sin las comillas.\n";
	   		    cout<<texto;
	   		    getline(cin,mostrar);
	            texto=texto+mostrar+'\n';
	            system("cls");
	            tam=texto.size();
	            for(int x=0;x<tam;x++){
	    		    if(texto[x]>96&&texto[x]<123){
	    		    	texto[x]=texto[x]-32;	
				    }
		      	}
	            verifica=salir(texto);
	        }
	    	tam=texto.size();
	    	if(texto[tam-9]=='\n'){
	    		texto[tam-9]=NULL;
			}
	    	for(int i=tam-8;i<tam-1;i++){
	    		texto[i]=NULL;
	    	}
	    	tam=texto.size();
	      	//Comienza la codificacion.
	    	tam=texto.size();
	        for(int i=0;i<tam;i++){
	        	if(texto[i]>64&&texto[i]<91){
	        		texto[i]=texto[i]-((avanza%26)-1);
					if(texto[i]>90){
					    texto[i]=texto[i]-26;  
				    }
				    if(texto[i]<65){
				        texto[i]=texto[i]+26;
				    }
				/*}else if(texto[i]>96&&texto[i]<123){
	        		texto[i]=texto[i]-((avanza%26)-1);
					if(texto[i]>122){
					    texto[i]=texto[i]-26;  
				    }
				    if(texto[i]<97){
				        texto[i]=texto[i]+26;
				    }
				Servía con minusculas tambien :c pero el profe no quiso.	
				*/	
				}
	        }
	        cout<<"Texto codificado a:\n"<<texto<<endl;
			system("pause");
			system("cls");
			bandera=0;
			do{
				fflush(stdin);
			    bandera=0;   	
			 	cout<<"Ingrese el nombre del archivo el que va a guardar su mensaje: ";
				getline(cin,temporal);
				if(validaNombre(temporal)==false){
			    	system("cls");
				    cout<<"Error! ingrese solo caracteres imprimibles\n";
				    system("pause");
				    system("cls");
				}else{	
					nombre= strdup(temporal.c_str());
					bandera=1;
			    }
			}while(bandera==0); 
			ofstream archivo(nombre,std::ios::out|std::ios::trunc);
			if(archivo.is_open()){
				archivo<<texto;
			}else{
				system("cls");
				cout<<"No se pudo abrir el archivo"<<endl;
				system("pause");
				system("cls");
			}
			archivo.close();
	    }else if(opc=="2"){
	    	int bandera=0;	
			do{	
			
				fflush(stdin);
			    bandera=0;   	
			 	cout<<"Ingrese el numero de codificacion : ";
				cin>>temporal;
				if(entradaNumero(temporal)==false){
			    	system("cls");
				    cout<<"Error! ingrese solo caracteres numericos enteros.\n";
				    system("pause");
				    system("cls");
				}else{	
					istringstream(temporal)>>avanza;
					bandera=1;
				}
			}while(bandera==0);
	  
	    	system("cls");
	    	bool band=false;
	    	do{
			    band=false; 
		    	do{
					fflush(stdin);
				    bandera=0;   	
				 	cout<<"Ingrese el nombre del archivo a decodificar: ";
					getline(cin,temporal);
					if(validaNombre(temporal)==false){
				    	system("cls");
					    cout<<"Error! ingrese solo caracteres imprimibles\n";
					    system("pause");
					    system("cls");
					}else{	
						nombre= strdup(temporal.c_str());
						bandera=1;
				    }
				}while(bandera!=1);
		    	ifstream archivo (nombre);
		    	tam=archivo.tellg();
		        while(getline(archivo,mostrar)){
		        	texto=texto+mostrar+'\n';
				}
				tam=texto.size();
				if(archivo.is_open()){
					band=true;
			        for(int i=0;i<tam;i++){
			        	if(texto[i]>64&&texto[i]<91){
			        		texto[i]=texto[i]+((avanza%26)-1);
							if(texto[i]>90){
							    texto[i]=texto[i]-26;  
						    }
						    if(texto[i]<65){
						        texto[i]=texto[i]+26;
						    }
						/*}else if(texto[i]>96&&texto[i]<123){
			        		texto[i]=texto[i]+((avanza%26)-1);
							if(texto[i]>122){
							    texto[i]=texto[i]-26;  
						    }
						    if(texto[i]<97){
						        texto[i]=texto[i]+26;
						    }
						Servía con minusculas tambien :c pero el profe no quiso.	
						*/	
						}
			        }
			        system("cls");
					cout<<"Mensaje decodificado:\n"<<texto;
					system("pause");
				}else{
					system("cls");
					cout<<"Archivo no encontrado. Ingrese un nombre de archivo valido."<<endl;
					system("pause");
					system("cls");		
				}
			}while(band!=true);
				    	
		}else if(opc=="3"){
		}else{
			system("cls");
			cout<<"Opcion no valida."<<endl;
			system("pause");
			system("cls");
		}
	}while(opc!="3");
	return 0;
}
