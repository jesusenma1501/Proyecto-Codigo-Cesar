#include <iostream>
#include <conio.h>
#include<fstream>
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

int main(int argc, char** argv) {
	int avanza=0,tam;
	string texto, mostrar, opc;
	bool verifica=true;
	cout<<"Bienvenido agente! Este programa le ayuda a codificar y decodificar\nmensajes.\n"<<endl;
	cout<<"Ingrese el numero de codificacion"<<endl;
    cin>>avanza;
    system("cls");
    cout<<"Digite la el numero que corresponda a la tarea que desea realizar...\n\n1) Codificar y guardar en archivo\n\n2)Decodificar un archivo\n\nOpc:";
	cin>>opc;
	if(opc=="1"){
		system("cls");
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
		ofstream archivo("Mensaje.txt",std::ios::out|std::ios::trunc);
		if(archivo.is_open()){
			archivo<<texto;
		}
		archivo.close();
        system("pause");
    }else if(opc=="2"){
    	
    	
	}else{
		system("cls");
		cout<<"No te pases de listo"<<endl;
		system("pause");
		system("cls");
	}

	return 0;
}
