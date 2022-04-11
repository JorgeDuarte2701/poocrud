#include "main.cpp"
#include <iostream>
using namespace std;

class estu : estudiantes {
	//atributos
	private :int codigo;
	
	//constructor
	public :
	datos (){
		}
		
	estudiantes(char nom,char ape,string dire,int tel,int c) : estudiantes(nom,ape,dire,tel,){
		codig =c;		
		}
		
	//metodos
	//set (modificar)
	void setCodigo(int codigo){nit=n;}
	void setNombres(string nom){nombres=nom;}
	void setApellidos(string ape){apellidos=ape;}
	void setDireccion(string dire){direccion=dire;}
	void setTelefono(int tel){telefono=tel;}

	//get (mostrar)
	char getCodigo(){return codigo;}

	char getNombres(){return nombres;}
	char getApellidos(){return apellidos;}
	string getDireccion(){return direccion;}
	int getTelefono(){return telefono;}


	
	void mostrar(){
		cout<<"---------------------------"<<endl;
		cout<<codigo<<","<<","<<nombres<<","<<apellidos<<","<<direccion<<","<<telefono<<","<<endl;
	}
};
