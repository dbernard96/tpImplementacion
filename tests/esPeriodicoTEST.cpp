#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, toroideTodoFalso){
    toroide t = { {false, false, false}, {false, false, false}, {false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}
TEST(esPeriodicoTEST, toroideDiagonal){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

TEST(esPeriodicoTEST, caeEnUnoPeriodico){
    toroide t = {{false, false, false, false},
                 {true, false, false, false},
                 {true, false, false, false},
                 {true, false, false, false},
                 {true, false, false, false},
                 {false, false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

TEST(esPeriodicoTEST, toroideBloque){
    toroide t = { {false, false, false, false},
                  {false, true, true, false},
                  {false, true, true, false},
                  {false, false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, toroidePeriodo2) {
    toroide t = {
            { false, false, false, false, false, false },
            { false, false, false, false, false, false },
            { false, false, true,  true,  true, false },
            { false, true,  true,  true,  false, false },
            { false, false, false, false, false, false },
            { false, false, false, false, false, false }
    };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, infinitoPeroNoEsSuPropiaEvolucion) {
    toroide t = {
            { false, false, false, false, false },
            { false, false, false, false, false },
            { false, false, true,  false, false },
            { true, true,  false, false, false },
            { false, true, false,  false, false }
    };
    int p;
    EXPECT_FALSE(esPeriodico(t, p));
}

TEST(esPeriodicoTEST, naveNoPeriodica4x4){
    toroide t = { {false, false, true, false}, {false, false, false, true}, {false, true, true, true},{false, false, false, false} };
    int p;
    int p0 = p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, p0);
}

TEST(esPeriodicoTEST, patronNoPeriodico){

    toroide t = {{false, false, false, false,false, false, false, false},
                 {true, false, false, false,false, false, false, false},
                 {false, true, true, false,false, false, false, false},
                 {true, false, false, true,false, false, false, false},
                 {false, true, true, false,false, false, false, false},
                 {false, false, false, false,false, false, false, false},
                 {false, false, false, false,false, false, true, true},
                 {false, false, false, false,false, false, true, true}};
    int p;
    int p0 = p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, p0);
}

TEST(esPeriodicoTEST, navePeriodica8x8){

    toroide t = {{false, false, false, false,false, false, false, false},
                 {false, false, false, false,false, false, false, false},
                 {false, false, false, true,false, false, false, false},
                 {false, false, false, false,true, false, false, false},
                 {false, false, true, true,true, false, false, false},
                 {false, false, false, false,false, false, false, false},
                 {false, false, false, false,false, false, false, false},
                 {false, false, false, false,false, false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 32);
}

TEST(esPeriodicoTEST, terminaMuerto) {
    toroide t = {
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, true,  false, false ,false, false, false},
            {false, false, false, false, true,  true,  true,  false ,false, false, false},
            {false, false, false, false, true,  false, true,  false ,false, false, false},
            {false, false, false, false, false, true,  false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 0);
}

TEST(esPeriodicoTEST, desembocaEnUnoPeriodico) {
    toroide t = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 0);
}

