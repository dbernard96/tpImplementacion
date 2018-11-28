#include "solucion.h"
#include "iostream"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t){
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].size() == t[0].size()) {
            res++;
        }
    }
    return t.size() > 0 && t[0].size() > 0 && res == t.size();
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t){
	vector<posicion> res;
	for (int i = 0; i < t.size(); i++){
		for (int j = 0; j < t[0].size(); j++){
			posicion a = maketuple(i,j);
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
	int p0 = get<0>(p);
	int p1 = get<1>(p);
//  posicion vecino;
	for (int i = -1; i <= 1; i++){
        	for (int j = -1; j <= 1; j++){
//        	get<0>(vecino) = mod( (get<0>(p) + i), t.size() ) ;
//        	get<1>(vecino) = mod( (get<1>(p) + j), t[0].size() );
			posicion vecino = make_tuple( mod(p0+i, t.size()), mod(p1+j, t[0].size() ) );

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
           		posicion a = make_tuple(i,j);
            		t[i][j] = evolucionDePosicion(aux,a);
	        }
	}
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

bool enCrecimiento(toroide t){
    toroide tEvolucion = evolucionT(t);
    return !toroideMuerto(t) && areaTrasladada(t) < areaTrasladada(tEvolucion);
}

int areaTrasladada(toroide t){
    int areaBase = areaMinima(t);
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j <= t[0].size(); ++j) {
            trasladarColumnas(t);
            int aux = areaMinima(t);
            if(areaBase > aux) areaBase = aux;
        }
        trasladarFilas(t);
    }
    return areaBase;
}

int areaMinima(toroide t){
	posicion p1 = make_tuple(0,0);
	posicion p2 = make_tuple(t.size()-1, t[0].size()-1);

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
    return calculoArea({p1,p2});
}

void trasladarColumnas(toroide &t){
    t = trasponer(t);
    trasladarFilas(t);
    t = trasponer(t);
}

void trasladarFilas(toroide &t){
	toroide aux;
	aux.push_back(t[t.size()-1]);
	int i = 0;
	while(i<t.size()-1){
		aux.push_back(t[i]);
		i++;
	}
	t = aux;
}

int calculoArea(vector<posicion> p){
    return (get<0>(p[1])+1 - get<0>(p[0])) * (get<1>(p[1])+1 - get<1>(p[0]));
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
bool soloBloques(toroide t){
    bool res = true;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
			posicion p = make_tuple(i,j);
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
        n = (n+d) % d;
    return n;
}

bool toroideMuerto(toroide t){
    return posicionesVivas(t).size() == 0;
}

bool hayRepetidosEntre(vector<toroide> s, int a, int b){
    int i = a+1;
    while(a < b && s[a] != s[i]) {
        if(i<b-1){
            i++;
        }else{
            a++;
            i = a + 1;
        }
    }
    return a<b;
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
