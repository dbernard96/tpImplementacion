#include "es.h"
#include "definiciones.h"
using namespace std;
/******************************** EJERCICIO cargarToroide *******************************/
toroide cargarToroide(string nombreArchivo, bool &status){
	toroide t;
	ifstream fin;
	fin.open(nombreArchivo);
	int filas;
	fin >> filas;
	int columnas;
	fin >> columnas;
	for (int i = 0; i < filas; ++i) {
		vector<bool> v;
		int aux;
		for (int j = 0; j < columnas; ++j) {
			fin >> aux;
			if(aux == 1){
				v.push_back(true);
			}else{
				v.push_back(false);
			}
		}
		t.push_back(v);
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
		}
		fout << endl;
	}
	fout.close();
	return res;
}
