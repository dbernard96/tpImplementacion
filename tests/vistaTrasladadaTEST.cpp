#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}


TEST(vistaTrasladadaTEST, mismoToroideMuerto) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}
TEST(vistaTrasladadaTEST, muevoPrimeraColumnaParaAtras){
    toroide t1 = {
            {true, false, false},
            {true, true, false},
            {true, false, false}};
    toroide t2 = {
            {false, false, true},
            {true, false, true},
            {false, false, true}};

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, podriaSerPeroNoEs){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, true, true},
            {false, false, true},
            {false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, TraslacionEnXeY){
    toroide t1 = {
            {true, false, false},
            {false, false, false},
            {false, true, false}};
    toroide t2 = {
            {false, false, true},
            {false, true, false},
            {false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, noEsVistaTrasladada){
    bool status = false;
    toroide t1 = {{true, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {true, false, false, false,false, false, false, true},
                  {true, false, false, false,false, false, false, false},
                  {true, false, false, false,false, false, false, false}};

    toroide t2 = {{false, false, false, false,false, false, false, true},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, true, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false}};
    bool res = vistaTrasladada(t1,t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, esVistaTrasladada){
    bool status = false;
    toroide t1 = {{true, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {true, false, false, false,false, false, false, true},
                  {true, false, false, false,false, false, false, false},
                  {true, false, false, false,false, false, false, false}};

    toroide t2 = {{false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false},
                  {false, true, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, true, false,false, false, false, false},
                  {false, false, false, false,false, false, false, false}};
    bool res = vistaTrasladada(t1,t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, rotacionAmbosEjes) {
    toroide t1 = {
            {false, false,  true, false, false},
            {false, false, true,  false, false},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, true, true, true, false}};
    toroide t2 = {
            {false, false,  false, false, false},
            {true, false, false,  false, false},
            {true, true, false, false, true},
            {true, false, false, false, false},
            {true, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, mismoToroide) {
    toroide t1 = {
            {false, false,  false, false, false},
            {false, false, true,  false, false},
            {false, true, false, true, false},
            {false, false, true, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false,  false, false, false},
            {false, false, true,  false, false},
            {false, true, false, true, false},
            {false, false, true, false, false},
            {false, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, diferenteCantColumnas){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {true, true},
            {true, true},
            {true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, diferenteCantFilasYColumnas) {
    toroide t1 = {
            {false, false, false},
            {true,  true,  false},
            {false, false, false}
    };
    toroide t2 = {
            {false, false},
            {true,  true}
    };

    EXPECT_FALSE(vistaTrasladada(t1, t2));
}

TEST(vistaTrasladadaTEST, distintasFilasODistintasColumnas){
    toroide t1 = {
            {true, false, false}, // 1
            {false, true, false}, // 2
            {false, false, true}};// 3
    toroide t2 = {
            {false, false, true, false}, // 3
            {true, false, false, false}, // 1
            {false, true, false, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

