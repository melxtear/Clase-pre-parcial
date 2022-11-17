// Clase prac.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct Pacientes {

	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	unsigned int natalicio;
	bool estado;
	unsigned int id_os;
	//Contactos contacto;//tendria que tener 2? uno de emergencia y otra dle mismo paciente
	//Consultas consulta;//consulta asociada, lee la del paciente
	//ObraSocial obra_social;

} Pacientes;

typedef struct nota {
	float nota1;
	float nota2;
} nota;

typedef struct alumno {
	unsigned int dni;
	string nombre;
	string apellido;
	nota n;
}alu;

void agregar(alu*& lista_alu, alu alumno, int* tamactual) {
	*tamactual = *tamactual + 1; 
	int i = 0;
	alu* aux = new alu[*tamactual];//vector de alumnos con tamaño actual+1
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_alu[i];
		i++;
	}
	aux[i] = alumno; //

	delete[] lista_alu;
	lista_alu = aux;

	return;
}

void resize(alu*& lista_alu, int* tamactual, int cantidad_aumentar) {
	*tamactual = *tamactual + cantidad_aumentar;
	int i = 0;
	alu* aux = new alu[*tamactual];
	while (i < *tamactual - cantidad_aumentar) {
		aux[i] = lista_alu[i];
		i++;
	}

	delete[] lista_alu;
	lista_alu = aux;

	return;
}
void agregar_alumno(alu alumno, string a1) {
	fstream archi;

	archi.open(a1, ios::app); //en vez de app, puede ir out para crear o in para leer archivo

	if (archi.is_open()) {
		archi << alumno.dni << " ," << alumno.apellido << ", " << alumno.nombre << endl;
	}
	else
		cout << "Archivo no encontrado. " << endl;
	archi.close();
}
int buscar_alumno(alu*&lista_alu, alu alumno, int* tamactual) {
	alu alumno_nuevo = alumno;
	for (int i = 0; i < *tamactual; i++) {
		if (lista_alu[i].dni == alumno_nuevo.dni) {
			return i;
		}
	}
}
void eliminar_alumno(alu*& lista_alu, int alumno_a_eliminar_pos, string a1, int *tamactual) {

	fstream archi;
	alu* aux = new alu[*tamactual-1];
	archi.open(a1, ios::app);
	if (archi.is_open()) {
		for (int i = 0; i < *tamactual; i++) {
			if (i != alumno_a_eliminar_pos) {
				aux[i] = lista_alu[i];
			}
		}
	}
	delete[] lista_alu;
	lista_alu = aux;
	archi.close();
}
Pacientes* leer_archivos_pacientes(string a1) {

	Pacientes* l_pac = new Pacientes[200];
	Pacientes aux;
	/*Contactos aux2;
	Medicos aux3;
	ObraSocial aux4;
	Consulta aux5;*/

	string dummy;
	char coma;
	unsigned int dniaux;
	unsigned int matricula_aux;
	unsigned int id_obra_social_aux;
	int tamact = 0;

	fstream fp;
	fp.open(a1, ios::in);
	/*fp2.open(a2, ios::in);
	fp3.open(a3, ios::in);
	fp4.open(a4, ios::in);
	fp5.open(a5, ios::in);*/


	if (!(fp.is_open()))
		return nullptr;

	fp >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//pacientes

	while (fp) { //lee archivo de pacientes 
		fp >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
		cout << "Lei paciente: " << aux.nombre << endl;
	}

	//agregar(l_pac, aux, &tamact);


	fp.close();


	return l_pac;
}

alu* leer_archivos(string a1, string a2) {
	alu* l_alumnos = new alu[0];
	Pacientes aux;
	nota naux;
	string dummy;
	char coma;
	unsigned int dniaux;
	int tamact = 0;

	fstream fp, fp2;
	fp.open(a1, ios::in);
	//fp2.open(a2, ios::in);

	if (!(fp.is_open()))
		return nullptr;

	//fp >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//pacientes
	//cout << dummy;
	//fp >> dummy >> coma >> dummy >> coma >> dummy;
	//fp2 >> dummy >> coma >> dummy >> coma >> dummy;
	while (fp) { //lee archivo de pacientes 
		fp >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
		cout << "Lei paciente: " << aux.nombre << endl;
	}
	/*while (fp) {
		fp >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre;
		while (fp2) {
			fp2 >> dniaux >> coma >> naux.nota1 >> coma >> naux.nota2;
			if (dniaux == aux.dni) {
				aux.n = naux;
				break;
			}
		}*/
		 //setea posicion 0 1, vuelve a la pos 0

		// Volvemos a salter el encabezado de fp2, porque posicionamos el cursor de lectura al inicio del archivo.
		//fp2 >> dummy >> coma >> dummy >> coma >> dummy;

		//agregar(l_alumnos, aux, &tamact);
	

	fp.close();
	//fp2.close();

	return l_alumnos;
}

void crear_archivo(string nombre_a1, string nombre_a2) {
	fstream archi, archi2; 

	archi.open(nombre_a1, ios::out);
	archi2.open(nombre_a2, ios::out);

	if (archi.is_open() && archi2.is_open()) {
		archi << "dni , nota1 , nota2" << endl;
		archi << 1000 << " , " << 8 << " , " << 7 << endl;
		archi << 10932 << " , " << 6 << " , " << 8 << endl;
		archi << 1554 << ", " << 10 << ", " << 9 << endl;
		archi2 << "dni , apellido , nombre" << endl;
		archi2 << 10932 << " , Maradona , Diego" << endl;
		archi2 << 1000 << " , Messi , Lionel" << endl;
		archi2 << 1554 << ", Almada, Keila" << endl;
	}

	archi.close();
	archi2.close();

	return;
}

int main() {
	alu* lista;
	lista = leer_archivos("alumnos.csv", "");

	/*alu* lista;

	alu* lista2;
	lista2 = new alu[3];
	alu alumno_nuevo;
	alumno_nuevo.nombre = "Mario";
	alumno_nuevo.apellido = "Casas";
	alumno_nuevo.dni = 4542245;
	lista2[0] = alumno_nuevo;

	alu alumno_nuevo1;
	alumno_nuevo1.nombre = "Mario2";
	alumno_nuevo1.apellido = "Casas2";
	alumno_nuevo1.dni = 45422454;
	lista2[1] = alumno_nuevo1;
	
	alu alumno_nuevo2;
	alumno_nuevo2.nombre = "Oscar";
	alumno_nuevo2.apellido = "Casas3";
	alumno_nuevo2.dni = 4545566;
	lista2[2] = alumno_nuevo2;
	
	crear_archivo("notas.csv", "alumnos.csv");

	lista = leer_archivos("alumnos.csv", "notas.csv");

	cout << lista[0].dni << " " << lista[0].nombre << " " << lista[0].apellido << " " << lista[0].n.nota1 << " " << lista[0].n.nota2 << endl;
	cout << endl << endl;
	cout << lista[1].dni << " " << lista[1].nombre << " " << lista[1].apellido << " " << lista[1].n.nota1 << " " << lista[1].n.nota2 << endl;
	cout << endl << endl;
	cout << lista[2].dni << " " << lista[2].nombre << " " << lista[2].apellido << " " << lista[2].n.nota1 << " " << lista[2].n.nota2 << endl;
	for (int i = 0; i < 3; i++) {
		cout << lista2[i].dni << " " << lista2[i].nombre << " " << lista2[i].apellido << endl;
		agregar_alumno(lista2[i], "alumnos.csv");
	}

	int* size=new int;
	*size = 3;
	int pos_a_eliminar = buscar_alumno(lista, lista[1], size);
	eliminar_alumno(lista, pos_a_eliminar, "alumnos.csv", size);
	delete[] lista;
	*/
	return 0;


}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
