#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(soloBloquesTEST,toroideMuerto){
	toroide t = {
			{false,false,false},
			{false,false,false},
			{false,false,false}
	};
	EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST, toroide2x2TodoTrue){
	toroide t = {
			{true,true},
			{true,true}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideBloqueEnEsquinas){
	toroide t = {
			{true,false,true},
			{false,false,false},
			{true,false,true}
	};
	EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideBloquesSuperpuestos){
	toroide t = {
			{false,true,true,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEI1){
	toroide t = {
			{false,false,true,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEI2){
	toroide t = {
			{false,false,false,true},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEI3){
	toroide t = {
			{false,false,false,false},
			{false,true,true,true},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueED1){
	toroide t = {
			{false,true,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueED2){
	toroide t = {
			{true,false,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueED3){
	toroide t = {
			{false,false,false,false},
			{true,true,true,false},
			{false,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEID1){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{true,true,true,false},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEID2){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{true,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEID3){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{true,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEII1){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,true,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEII2){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{false,true,true,false},
			{false,false,false,true}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideCasiBloqueEII3){
	toroide t = {
			{false,false,false,false},
			{false,true,true,false},
			{false,true,true,true},
			{false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideBloquesDiagonales){
	toroide t = {
			{false,false,false,false,false,false},
			{false,false,false,true,true,false},
			{false,false,false,true,true,false},
			{false,true,true,false,false,false},
			{false,true,true,false,false,false},
			{false,false,false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideBloquesPegados){
	toroide t = {
			{false,false,false,false,false,false},
			{false,false,false,false,false,false},
			{false,true,true,true,true,false},
			{false,true,true,true,true,false},
			{false,false,false,false,false,false},
			{false,false,false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideBloquesConPosVivaSuelta){
	toroide t = {
			{false,false,false,false,false,false},
			{false,false,false,false,false,false},
			{false,true,true,false,true,true},
			{false,true,true,false,true,true},
			{false,false,false,false,false,false},
			{false,true,false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST,toroideNoBloque){
	toroide t = {
			{false,false,false,false,false},
			{false,true,false,true,false},
			{false,false,false,false,false},
			{false,true,false,true,false},
			{false,false,false,false,false}
	};
	EXPECT_FALSE(soloBloques(t));
}