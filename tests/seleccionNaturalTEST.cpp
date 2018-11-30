#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, false, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, PeriodicoVsMuerto){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t1);
    int res = seleccionNatural(ts);

    bool esperado = ((res == 1) || (res == 2));
    EXPECT_TRUE(esperado);
}

TEST(seleccionNaturalTEST, t1MuereAntesQuet2){
    toroide t1 = {
            {false,  false, false},
            {false,  true,  false},
            {false,  false, false}};
    toroide t2 = {
            {true,  false,  false},
            {false, true,   false},
            {false, false,  true}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}

TEST(seleccionNaturalTEST, t1PeriodicoVst2Muere){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,true, true, false} };
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, t1SeVuelvePeriodicot2EsPeriodico){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,true, true, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);

    bool esperado = ((res == 0) || (res == 2));
    EXPECT_TRUE(esperado);
}

TEST(seleccionNaturalTEST, t1MuertoVst2Peridico){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);

    bool esperado = ((res == 0) || (res == 2));
    EXPECT_TRUE(esperado);
}

TEST(seleccionNaturalTEST, t1Muertot2NoPeriodico){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);

    bool esperado = ((res == 0) || (res == 2));
    EXPECT_TRUE(esperado);
}

TEST(seleccionNaturalTEST, todosMuertos){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);

    bool esperado = ((res == 0) || (res == 1) || (res == 2));
    EXPECT_TRUE(esperado);
}

TEST(seleccionNaturalTEST, t1Periodicot2Muerto){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,true, true, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, t1MuereEnUntickt2Muertot3SeMuereEnMasDeUnTick){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};

    toroide t2 = {
            {false,false,false}};


    toroide t3 = {
            {false, false, false},
            {true, false, true},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res,2);
}

TEST(seleccionNaturalTEST, UnoVivoVstoroideDiagonal){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    bool expect = (res == 1 || res == 2);
    EXPECT_TRUE(expect);
}

TEST(seleccionNaturalTEST, periodicoVsMortal) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, true,  false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, desembocaEnPeriodicoVsMortal) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, true,  false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, t1yt2SeMuerenEnUnTickt3SeMuereEnDosTicks){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false},
            {false, true, false},
            {false, false, false}};
    toroide t3 = {{true, false, false},
                  {false, true, false},
                  {false, false, true}};

    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}

TEST(seleccionNaturalTEST, sinToroidesPeriodicos){
    toroide t1 = {
            {true, false, false, false},
            {false, true, false, false},
            {false, true, false, false},
            {false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, ultimoElementoEsElMasLongevo){
    toroide t1 = {
            {true, false, false, false},
            {false, true, false, false},
            {false, true, false, false},
            {false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    toroide t3 = {
            {true, false, false, false},
            {true, true, false, false},
            {true, false, false, true},
            {false, false, true, true},
            {true, true, false, true}};

    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}
