#ifndef CODIGOCESAR_H
#define CODIGOCESAR_H
#include <string>
#include <cstring>

using namespace std;
class CodigoCesar{
	
	public:
		void setTextoCod(string v, int numero, int tam);
		void setTextoDecod(string v, int numero, int tam);
		string getTexto();
		CodigoCesar(); // el constructor de la clase
		~CodigoCesar();//el destructor de la clase
	private:
		string texto;
};



void CodigoCesar::setTextoCod(string tex, int numero, int tam){
	this->texto=tex;
	for(int x=0; x<tam; x++){
		if(this->texto[x]>64 && this->texto[x]<91){
			this->texto[x]=this->texto[x]-((numero%26));
			if(this->texto[x]<65){
				this->texto[x]=this->texto[x]+26;
			}
		}
		
		if(this->texto[x]==char(164)){
			this->texto[x]=this->texto[x]-129;
		}
		
		if(this->texto[x]==char(165)){
			this->texto[x]=this->texto[x]-130;
		}
		
			
	}
	
}

void CodigoCesar::setTextoDecod(string tex, int numero, int tam){
	this->texto=tex;
	for(int x=0; x<tam; x++){
		if(this->texto[x]>64 && this->texto[x]<91){
			this->texto[x]=this->texto[x]+((numero%26));
			if(this->texto[x]>90){
				this->texto[x]=this->texto[x]-26;
			}
		}
	
		if(this->texto[x]==char(35)){
				this->texto[x]=this->texto[x]+130;
			}
	}
}

string CodigoCesar::getTexto(){
	return this->texto;
}



CodigoCesar::CodigoCesar()//Constructor de la clase
{

}

// class destructor
CodigoCesar::~CodigoCesar()// destructor de la clase
{

}
#endif
