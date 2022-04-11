#include "estudiante.cpp"
#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
class estu{

const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
	string direccion;
	
		protected : 
		estudiantes(){
			
		}	
		estudiantes (char nom,char ape, string dire, int tel,string){
			nombres=nom;
			apellidos=ape;
			direccion =dire;
			telefono=tel;
		}	
	//metodo

	void mostrar();
};
void crear();
void leer();
void actualizar();
void buscar();
main(){

 	crear();
	system("PAUSE");
		//constructor

}
void buscar(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombres << endl;
        cout << "Apellido: " << estudiante.apellidos << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
	
	datos obj = datos(nombres,apellidos,direccion,telefono,codigo);
	obj.mostrar();
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");
		}
		
		Estudiante estudiante;
		int id=0;
		fread(&estudiante,sizeof(Estudiante),1, archivo);
		do{
			
			cout<<id<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.telefono<<endl;
			fread(&estudiante,sizeof(Estudiante),1, archivo);
			id+=1;
		}while(feof(archivo)==0);
		datos obj = datos(nombres,apellidos,direccion,telefono,codigo);
	obj.mostrar();
}
void crear(){
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	char continuar;
	string nombre,apellido;
	do{
		fflush(stdin);
			int id=0;
			cout<<"Ingrese el Id que desea Modifica:";
			cin>>id;
			
			cout<<"Ingrese Codigo:";
			cin>>estudiante.codigo;
			cin.ignore();
			
			cout<<"Ingrese Nombres:";
			getline(cin,nombre);
			strcpy(estudiante.nombres,nombre.c_str());
	cout<<"Ingrese Apellidos:";
			getline(cin,apellido);
			strcpy(estudiante.apellidos,apellido.c_str());
			
			cout<<"Ingrese Telefono:";
			cin>>estudiante.telefono;
			cin.ignore();
			fwrite(&estudiante,sizeof(Estudiante),1, archivo);
	
	
		cout<<"Desea Agregar otro Estudiante (s/n):";
		cin>>continuar;
	}while(continuar=='s' || continuar=='S');
		datos obj = datos(nombres,apellidos,direccion,telefono,codigo);
	obj.mostrar();
	fclose(archivo);
	leer();
}
void actualizar(){
		FILE* archivo = fopen(nombre_archivo,"r+b");
			Estudiante estudiante;
			string nombre,apellido;
			int id=0;
			cout<<"Ingrese el Id que desea Modifica:";
			cin>>id;
			fseek(archivo,id*sizeof(Estudiante),SEEK_SET);//indicar que registros vamos a actualizar
			
			cout<<"Ingrese Codigo:";
			cin>>estudiante.codigo;
			cin.ignore();
			
cout<<"Ingrese Nombres:";
			getline(cin,nombre);
			strcpy(estudiante.nombres,nombre.c_str());
			
			cout<<"Ingrese Apellidos:";
			getline(cin,apellido);
			strcpy(estudiante.apellidos,apellido.c_str());
			
			cout<<"Ingrese Telefono:";
			cin>>estudiante.telefono;
			cin.ignore();
			fwrite(&estudiante,sizeof(Estudiante),1, archivo);
		fclose(archivo);
		leer(); }
			datos obj = datos(nombres,apellidos,direccion,telefono,codigo);
	obj.mostrar();
		};

