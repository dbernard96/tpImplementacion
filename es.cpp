#include "es.h"
#include "definiciones.h"
#include "solucion.h"
#include "iostream"
using namespace std;

/******************************** EJERCICIO cargarToroide *******************************/
toroide cargarToroide(string nombreArchivo, bool &status){
	toroide t;
	ifstream fin;
	fin.open(nombreArchivo);
	if(fin.fail()) {
        status = false;
    }else{
     	int filas;
		int columnas;
		int aux;
		fin >> filas;
		fin >> columnas;
		vector<bool> v;
		while(!fin.eof() && t.size() != filas){
			fin >> aux;

			if(aux == 1){
				v.push_back(true);
			}else if(aux == 0){
				v.push_back(false);
			}else{
			    status = false;
			}

			if(v.size() == columnas){
				t.push_back(v);
				v = {};
			}
		}

		fin >> aux;
		if(posicionesVivas(t).size() == aux && esValido(t) && fin.eof() && t.size() == filas && t[0].size() == columnas){
		    status = true;
		}else{
			status = false;
		}
	}
	fin.close();
	return t;
}


/******************************** EJERCICIO escribirToroide *****************************/
bool escribirToroide(string nombreArchivo, toroide &t){
	bool res;
	ofstream fout;
	fout.open(nombreArchivo);
	fout << t.size() << " " << t[0].size() << endl;
	for (int i = 0; i < t.size(); ++i) {
		for (int j = 0; j < t[0].size(); ++j) {
			if(t[i][j]){
				fout << 1;
			}else{
				fout << 0;
			}
			fout << " ";
		}
		fout << endl;
	}
	fout << posicionesVivas(t).size();
	fout.close();
	return !fout.fail();
}

