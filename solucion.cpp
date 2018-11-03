#include "solucion.h"

/************************ Funciones Auxiliares Generales *************************/

bool viva(toroide t, posicion p);
bool viva(toroide t, posicion p){				//Dado un toroide y una posición decide si esta está viva
	return t[p<0>][p<1>];					//Incluida por comodida y limpieza del códigod
}

int mod(int n, int d){
	return abs(n) % d;
}
/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t){
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].size() == t[0].size()) {res++;}
    }
    return res == t.size();
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t){
	vector<posicion> res;
	posicion aux;

	for (i = 0; i < t.size(); i++){
		for (j = 0; j < t[0].size(); j++){
		
			aux<0> = i;
			aux<1> = j;	
			if (t[i][j]) res.push_back(aux);
		}
	}

	return res;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
float densidadPoblacion(toroide t){
    float densidad = 0;
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t[0].size();j++){			//Acá puedes usar posicionesVivas
            if(t[i][j]){densidad++;}
        }
    }
    densidad /= t.size()*t[0].size();
    return densidad;
}

/**************************** EJERCICIO evolucionDePosicion *****************************/

int vecinosVivos(toroide t, posicion p);
int vecinosVivos(toroide t, posicion p){ 		 		//Cuenta la cantidad de vecinos vivos. Basado en la especificación entregada

	int contador = 0;
	posicion vecino;						//Stand-in para el vecino a ser chequeado

	for (int i = -1; i <= 1; i++){
		for (int j = -1; i <= 1; j++){
			
			vecino<0> = (p<0> + i) % t.size(); 
			vecino<1> = (p<1> + j) % t[0].size(); 

			if (viva(t,vecino)) contador++;	
			
		}
	}

	if (viva(t,p)) contador--;					//La posición no es vecina de si misma

	return contador;
}

//bool evolucionDePosicion(toroide t, posicion p){
    
//	if (t[p<0>][p<1>]) {  //Si la posición está viva
		
		
//	} else {
	
//	}

//}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide& t){
}

/***************************** EJERCICIO evolucionMultiple ******************************/
toroide evolucionMultiple(toroide t, int k){
    toroide result;
    return result;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool esPeriodico(toroide t, int& p){
    return false;
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    return false;
}

/****************************** EJERCICIO seleccionNatural ******************************/
int seleccionNatural(vector<toroide> ts){
    int indice;
    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2){
    toroide t;
    return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2){
    bool res = false;
    return res;
}

/******************************* EJERCICIO enCrecimiento ********************************/
bool enCrecimiento(toroide t){
    bool res;
    return res;
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
bool soloBloques(toroide t){
    bool res;
    return res;
}
