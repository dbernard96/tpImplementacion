#include "solucion.h"
#include "iostream"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t){
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].size() == t[0].size() && t[0].size() > 0) {res++;}
    }
    return t.size() > 0 && res == t.size();
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t){
	vector<posicion> res;
	for (int i = 0; i < t.size(); i++){
		for (int j = 0; j < t[0].size(); j++){
            posicion a;
            get<0>(a) = i;
            get<1>(a) = j;
			if (t[i][j]) res.push_back(a);
		}
	}
	return res;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
float densidadPoblacion(toroide t){
    float densidad = 0;
    densidad = posicionesVivas(t).size();
    densidad /= t.size()*t[0].size();
    return densidad;
}

/**************************** EJERCICIO evolucionDePosicion *****************************/

bool evolucionDePosicion(toroide t, posicion p){
    int vecinos = vecinosVivos(t,p);
	return vecinos == 3 || (vecinos == 2 && viva(t,p));
}

int vecinosVivos(toroide t, posicion p){
    int contador = 0;
    posicion vecino;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            get<0>(vecino) = mod( (get<0>(p) + i), t.size() ) ;
            get<1>(vecino) = mod( (get<1>(p) + j), t[0].size() );
            if (viva(t,vecino)) contador++;
        }
    }
    if (viva(t,p)) contador--;
    return contador;
}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide& t){
    toroide aux = t;
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < t[0].size(); j++){
            posicion a;
            get<0>(a)=i;
            get<1>(a)=j;
            aux[i][j] = evolucionDePosicion(t,a);
        }
    }
    t = aux;
    return;
}

/***************************** EJERCICIO evolucionMultiple ******************************/
toroide evolucionMultiple(toroide t, int k){
	toroide result = t;
	for (int i = 0; i < k; i++){
		evolucionToroide(result);
	}
	return result;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool esPeriodico(toroide t, int& p){
    vector<toroide> s = listaDeEvoluciones(t);
    int i = 0;
    if(toroideMuerto(t)){
        p = 1;
    }else if(s[0] == s[s.size()-1]){
        p = s.size()-1;
    }
    return hayRepetidosEntre(s,0,s.size()) || toroideMuerto(t);
}

/******************************* EJERCICIO primosLejanos ********************************/
bool buscarSiPrimos(toroide t1,toroide t2){
	vector<toroide> s = listaDeEvoluciones(t1);
	int i = 0;
	while(t2 != s[i] && i<s.size()){
	    i++;
	}
	return i<s.size();
}

bool primosLejanos(toroide t1, toroide t2) {

	return buscarSiPrimos(t1,t2) || buscarSiPrimos(t2,t1);

}	
/****************************** EJERCICIO seleccionNatural ******************************/
int seleccionNatural(vector<toroide> ts){
    int indice = -1;
    for (int i = 0; i < ts.size() && indice==-1; ++i) {
        int c;
        if(esPeriodico(ts[i],c)){
            indice = i;
        }
    }

    if(indice==-1){
        indice++;
        vector<vector<toroide>> crono;
        int i = 0;
        while(i < ts.size()){
            crono.push_back(listaDeEvoluciones(ts[i]));
            if(crono[i].size() > crono[indice].size()){
                indice = i;
            }
            i++;
        }
    }
    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2){
	toroide t;
	for (int i = 0; i < t1.size(); i++){
        vector<bool> v;
		for (int j = 0; j < t1[0].size(); j++){
			v.push_back(t1[i][j] && t2[i][j]);
		}
        t.push_back(v);
	}
	return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2){
    int i = 0;
    int j = 0;
    while(i<t1.size() && !esTraslacion(t1,t2,i,j)){
        if(j!=t1.size()-1){
            j++;
        }else{
            j=0;
            i++;
        }
    }
    return i<t1.size();
}

bool esTraslacion(toroide t1, toroide t2,int i, int j){
    int f = 0;
    int c = 0;
    while(f < t1.size() && t2[f][c] == t1[mod(f+i,t1.size())][mod(c+j,t1[0].size())]){
        if(c!=t1[0].size()-1){
            c++;
        }else{
            c=0;
            f++;
        }
    }

    return  f>=t1.size();
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
/************************ Funciones Auxiliares Generales *************************/
bool viva(toroide t, posicion p){				//Dado un toroide y una posición decide si esta está viva
    return t[get<0>(p)][get<1>(p)];					//Incluida por comodida y limpieza del código
}

int mod(int n, int d){
    if(n < 0){
        n += d;
    }else {
        n = n % d;
    }
    return n;
}

bool toroideMuerto(toroide t){
    return posicionesVivas(t).size() == 0;
}

bool hayRepetidosEntre(vector<toroide> s, int a, int b){
    while(a < b) {
        for (int i = a; i < b; i++) {
            if(s[a] == s[i] && a!=i){return true;}
        }
        a++;
    }
    return false;
}

toroide evolucionT(toroide t){
    evolucionToroide(t);
    return t;
}

vector<toroide> listaDeEvoluciones(toroide t){
    vector<toroide> s = {t};
    int i = 0;
    while(!toroideMuerto(s[i]) && !hayRepetidosEntre(s,0,s.size())){
        s.push_back(evolucionT(s[i]));
        i++;
    }
    return s;
}