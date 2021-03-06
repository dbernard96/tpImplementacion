#ifndef JUEGODELAVIDA_SOLUCION_H
#define JUEGODELAVIDA_SOLUCION_H
#include "definiciones.h"

bool esValido(toroide t);
vector<posicion> posicionesVivas(toroide t);
float densidadPoblacion(toroide t);
int cantidadBloques(toroide t);
bool evolucionDePosicion(toroide t, posicion p);
void evolucionToroide(toroide& t);
toroide evolucionMultiple(toroide t, int k);
bool esPeriodico(toroide t, int& p);
bool primosLejanos(toroide t1, toroide t2);
int seleccionNatural(vector<toroide> ts);
toroide fusionar(toroide t1, toroide t2);
bool vistaTrasladada(toroide t1, toroide t2);
void cercarCelulasVivas(toroide& t);
bool enCrecimiento(toroide t);
bool soloBloques(toroide t);

bool viva(toroide t, posicion p);
int mod(int n, int d);
int vecinosVivos(toroide t, posicion p);
bool toroideMuerto(toroide t);
bool hayRepetidosEntre(vector<toroide> s, int a, int b);
bool esTraslacion(toroide t1, toroide t2, int i, int j);
toroide evolucionT(toroide t);
vector<toroide> listaDeEvoluciones(toroide t);
bool buscarSiPrimos(toroide t1,toroide t2);
toroide trasponer(toroide t);
bool esTPeriodico(toroide t);

int areaTrasladada(toroide t);
int areaMinima(toroide t);
bool colMuerta(toroide t, int i);
bool filaMuerta(toroide t, int i);
toroide trasladarColumnas(toroide t);
toroide trasladarFilas(toroide t);
int calculoArea(vector<posicion> p);
bool mismaDimension(toroide t1,toroide t2);
#endif //JUEGODELAVIDA_SOLUCION_H
