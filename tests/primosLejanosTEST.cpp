#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}, 
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, diferentesDimensiones){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}}; 
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}


TEST(primosLejanosTEST, gliderConsigoMismo){
    toroide t1 = {
            {false, false, true, false, false},
            {false, false, false, true, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, true, false},
            {false, true, false, true, false},
            {false, false, true, true, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, ambosMuertos){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, noPrimosSegundoPeriodico){
    toroide t1 = {
            {true, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, mismasDimensiones){
    toroide t1 = {
                  {false, false, false, false, false},
                  {false, false, false, false, false},
                  {false, true, true, true, false},
                  {false, false, false, false, false},
                  {false, false,false, false, false} };
		toroide t2 = {
                  {false, true, false, false, false},
                  {false, false, false, false, false},
                  {false, true, true, true, false},
                  {false, false, false, false, false},
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, unoEsPeriodico){
    toroide t1 = {
                  {true, true, false},
                  {true, true, false},
                  {false, false, false} };
		toroide t2 = {
	                {true, false, false},
	                {false, true, false},
	                {false, false, true} };
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, t1EvolucionaAt2Muerto) {
    toroide t1 = {{true,  false, false},
                  {false, true,  false},
                  {false, false, true}};

    toroide t2 = {{false, false, false},
                  {false, false, false},
                  {false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, t1yt2conDistintoPeriodo) {
    toroide t1 = { {false, false, false, false},
                   {false, true, true, false},
                   {false, true, true, false},
                   {false, false, false, false} };

    toroide t2 = {{true, false, false, false},
                  {false, true, false, false},
                  {false, false, true, false},
                  {false, false, false, true}};
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, t1SeVuelvePeriodot2) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, true, true, false, false},
            {false, true, true, false, false},
            {false, false, false, false, false},
            {false, false,false, false, true} };

    toroide t2 = {
            {false, false, false, false, false},
            {false, true, true, false, false},
            {false, true, true, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, t1SeVuelvePeriodicoYt2EsPeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false,false, false, true} };

    toroide t2 = {
            {false, false, false, false, false},
            {false, true, true, false, false},
            {false, true, true, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, t1seVuelvePeriodicot2NoPeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false,false, false, true} };

    toroide t2 = {
            {false, false, false, false, false},
            {false, true, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, unCeldaVivaVSMuerto){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, toroideNoPeriodicoVsUnoMuerto) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true,  false, true,  true,  false},
            {true,  false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, t1NoPeriodicoEvolucionaAt2) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, true,  false},
            {false, false, false, true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, mismoToroideNoPeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, mismoToroidePeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, desembocaEnPeriodicoVsToroideEnPartePeriodica) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};

    toroide t2 = {
            {false, false, true,  false, false},
            {false, true,  false, true,  false},
            {true,  true,  false, true,  true},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, toroidesEvolucionanAMuertos){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, true},
            {false, false, true}};
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, toroidesIgualesPeriodicos) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t, t));
}

TEST(primosLejanosTEST, toroidesIgualesNoPeriodicos) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, true,  false}
    };

    EXPECT_TRUE(primosLejanos(t, t));
}

TEST(primosLejanosTEST, evolucionNoInmediata) {
    toroide t1 = {
            {false, true,  false, false},
            {false, true,  true,  false},
            {false, false, true,  false},
            {false, false, false, false}
    };

    toroide t2 = {
            {true,  true,   true,  true},
            {true,  false,  false, true},
            {true,  true,   true,  true},
            {false, false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t1, t2));
}

TEST(primosLejanosTEST, primerToroideMuere){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

