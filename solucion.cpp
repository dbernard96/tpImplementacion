#include "solucion.h"
#include "iostream"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t){
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].size() == t[0].size() && t[0].size() > 0) {
            res++;
        }
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
			if (viva(t,a)) {
                res.push_back(a);
            }
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
    if(toroideMuerto(t)){
        p = 1;
    }else if(s[0] == s[s.size()-1]){
        p = s.size()-1;
    }
    return toroideMuerto(t) || s[0] == s[s.size()-1];
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
	return buscarSiPrimos(t1,t2) || buscarSiPrimos(t2,t1);
}

bool buscarSiPrimos(toroide t1,toroide t2){
    vector<toroide> s = listaDeEvoluciones(t1);
    int i = 0;
    while(t2 != s[i] && i<s.size()){
        i++;
    }
    return i<s.size();
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
        if(j<t1.size()-1){
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
        if(c<t1[0].size()-1){
            c++;
        }else{
            c=0;
            f++;
        }
    }

    return  f>=t1.size();
}


/******************************* EJERCICIO enCrecimiento ********************************/

int calculoArea(vector<posicion> p){
	return (get<0>(p[1])+1 - get<0>(p[0])) * (get<1>(p[1])+1 - get<1>(p[0]));
}

void trasladarFilas(toroide &t){
	toroide aux;
	aux.push_back(t[t.size()-1]);
	int i = 0;
	while(i<t.size()-1){
		aux.push_back(t[i]);
		i++;
	}
}

toroide trasponer(toroide t){
	toroide res;
	for (int i = 0; i < t[0].size(); i++) {
		vector<bool> aux;
		for (int j = 0; j < t.size(); j++) {
			aux.push_back(t[j][i]);
		}
		res.push_back(aux);
	}
	return res;
}

void trasladarColumnas(toroide &t){
	t = trasponer(t);
	trasladarFilas(t);
	t = trasponer(t);
}

bool filaMuerta(toroide t, int i){
	int j = 0;
	bool res = false;
	while(j < t[0].size() && !res){
		res = res || t[i][j];
		j++;
	}
	return !res;
}

bool colMuerta(toroide t, int i){
	int j = 0;
	bool res = false;
	while(j < t.size() && !res){
		res = res || t[j][i];
		j++;
	}
	return !res;
}

vector<posicion> areaMinima(toroide t){
	posicion p1;get<0>(p1)=0;get<1>(p1)=0;
	posicion p2;get<0>(p2)=t.size()-1;get<1>(p2)=t[0].size()-1;


	while(filaMuerta(t,get<0>(p2))){
		get<0>(p2)--;
	}

	while(colMuerta(t,get<1>(p2))){
		get<1>(p2)--;
	}

	while(filaMuerta(t,get<0>(p1))){
		get<0>(p1)++;
	}

	while(colMuerta(t,get<1>(p1))){
		get<1>(p1)++;
	}

	return {p1,p2};
}

vector<posicion> areaTrasladada(toroide t){
	vector<posicion> areaBase = areaMinima(t);
	for (int i = 0; i < t.size(); ++i) {
		for (int j = 0; j <= t[0].size(); ++j) {
			trasladarColumnas(t);
			vector<posicion> aux = areaMinima(t);
			if(calculoArea(areaBase) > calculoArea(aux)){
				areaBase = aux;
			}
		}
		trasladarFilas(t);
	}
	return areaBase;
}

bool enCrecimiento(toroide t){
	toroide te = evolucionT(t);
	return !toroideMuerto(t) && calculoArea(areaTrasladada(t)) < calculoArea(areaTrasladada(te));
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
bool soloBloques(toroide t){
    bool res = true;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
			posicion p;get<0>(p)=i;get<1>(p)=j;
            if(viva(t,p) && vecinosVivos(t,p) != 3){
                res=false;
            }
        }
    }
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
        for (int i = a+1; i < b; i++) {
            if(s[a] == s[i]){return true;}
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