#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(fusionarTEST, sinInterseccion){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, true, true},
                  {true, false, true},
                  {true, true, false}}; 
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0].size(), 3);
    EXPECT_EQ(res[1].size(), 3);
    EXPECT_EQ(res[2].size(), 3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            EXPECT_FALSE(res[i][j]);
        }
    }
}

TEST(fusionarTEST, interseccionSoloDiagonal){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0].size(), 3);
    EXPECT_EQ(res[1].size(), 3);
    EXPECT_EQ(res[2].size(), 3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            if (i != j) EXPECT_FALSE(res[i][j]);
            else EXPECT_TRUE(res[i][j]);
        }
    }
}

TEST(fusionarTEST, conInterseccionParcial){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, true, false},
            {true, true, true},
            {true, true, true}};
    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0].size(), 3);
    EXPECT_EQ(res[1].size(), 3);
    EXPECT_EQ(res[2].size(), 3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            if (i != j || (i == 0 && j == 0)) EXPECT_FALSE(res[i][j]);
            else EXPECT_TRUE(res[i][j]);
        }
    }
}

TEST(fusionarTEST, Toroides4x5){
    toroide t1 = {{true, false, false, false, true},
                  {true, false, true, false, true},
                  {true, false, false, false, true},
                  {true, true, true, true, true}};

    toroide t2 = {{true, false, true, true, false},
                  {false, false, false, true, false},
                  {false, false, false, false, true},
                  {true, false, false, true, true}};
    toroide res = fusionar(t1,t2);
    EXPECT_EQ(res.size(), 4);
    EXPECT_EQ(res[0].size(), 5);
    EXPECT_EQ(res[1].size(), 5);
    EXPECT_EQ(res[2].size(), 5);
    EXPECT_EQ(res[3].size(), 5);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            if ((i == 0 && j == 0) || (i == 2 && j == 4) || (i == 3 && (j == 0 || j == 3 ||j == 4)))
                EXPECT_TRUE(res[i][j]);
            else EXPECT_FALSE(res[i][j]);
        }
    }
}
