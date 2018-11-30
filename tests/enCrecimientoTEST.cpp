#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(enCrecimientoTEST, toroideDiagonalSeHaceTodoTrue){
    toroide t1 = { 
                  {true, false, false}, 
                  {false, true, false}, 
                  {false, false, true}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, todoFalsoNoCrece){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroidePeriodicoNoCrece){
    toroide t1 = {
            {false, false, false, false},
            {true,  true,  true,  false},
            {false, false, false, false},
            {false, false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroideLSeHaceBloque){
    toroide t1 = {
            {false, false, false, false},
            {false, true,  true,  false},
            {false, false, true,  false},
            {false, false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroideExtremosEsBloque){
    toroide t1 = {
            {true,  false, false, true},
            {false, false, false, false},
            {false, false, false, false},
            {true,  false, false, true}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroideBloqueConUnoMasCrece){
    toroide t1 = {
            {false, false, true, false},
            {false, true,  true,  false},
            {false, true,  true,  false},
            {false, false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}

TEST(enCrecimientoTEST, toroideLineaDeCuatroCrece){
    toroide t1 = {
            {false, false, false, false},
            {true,  true,  true,  true},
            {false, false, false, false},
            {false, false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}


TEST(enCrecimientoTEST, toroideGlider){
    toroide t1 = {
            {false, false, false, true, false, false},
            {false, false, false, false, true, false},
            {false, false, true, true, true, false},
            {false, false, false, false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroideSeVuelvePeriodicoDecrece){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,true, true, false} };
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, toroideBloque3x2CortadoCrece){
    toroide t1 = {
            {true, true, false, false, true},
            {true, true, false, false, true},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}

TEST(enCrecimientoTEST, toroidePatronCrece){
    toroide t1 = {{false, true, false, true,false, true, true, false},
                  {false, true, false, true,false, true, true, false},
                  {false, true, true, true,true, true, true, false},
                  {false, true, true, false,false, false, false, false},
                  {false, true, true, false,false, false, false, false},
                  {false, false, false, true,false, false, false, false},
                  {false, false, true, false,true, false, false, false},
                  {false, true, false, false,false, true, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}

TEST(enCrecimientoTEST, periodicoMantieneArea) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false}};
    EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, creceArea) {
    toroide t1 = {
            {false, false, false},
            {true,  true,  true},
            {false, false, false}};
    EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, periodicoMantieneAreaBorder) {
    toroide t1 = {
            {false, true,  true,  true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, reduceAreaBorder) {
    toroide t1 = {
            {false, true,  true, false},
            {true,  false, false, false},
            {false, false, false, false}};
    EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, toroideCrece) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, toroideCrece1) {
    toroide t1 = {
            {false, false, false, false, true, false, false, false, false},
            {false, false, false, false, true, false, false, false, false},
            {false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false},
            {false, false, false, true,  true,  true,  false, false, false},
            {false, false, false, true,  false, true,  false, false, false},
            {false, false, false, true,  false, true,  false, false, false},
            {false, false, false, false, true,  false, false, false, false},
            {false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false},
            {false, false, false, false, true, false, false, false, false}};
    EXPECT_TRUE(enCrecimiento(t1));
}


TEST(enCrecimientoTEST, bloque){
    toroide t1 = {
            {false, true,  true},
            {false, false, false},
            {false, true,  true}};
    EXPECT_FALSE(enCrecimiento(t1));
}


TEST(enCrecimientoTEST, miniL){
    toroide t1 = {
            {true,  false, false},
            {true,  true,  false},
            {false, false, false}};
    EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, toroideQueMuere){
    toroide t1 = {
            {false, false, false},
            {false, true,  false},
            {false, false, false}};

    EXPECT_FALSE(enCrecimiento(t1));
}


TEST(enCrecimientoTEST, toroideAlgunasVivas){
    toroide t1 = {
            {false, false, false, false, false},
            {true, true, true, false, false},
            {true, false, true, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};

    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}

TEST(enCrecimientoTEST, TodosVivos){
    toroide t1 = {{true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true},
                  {true, true, true, true, true, true, true}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

