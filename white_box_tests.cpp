//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     ROMAN STEPANIUK <xstepa64@stud.fit.vutbr.cz>
// $Date:       $2020-03-01
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author ROMAN STEPANIUK
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class TestovaniMatice : public :: testing :: Test{
    protected:
        Matrix matice;
    // vytvoreni konstruktoru pro matici
    Matrix vytvaritPrazdnouMatice1x1()
    {
        matice = Matrix();
        return matice;
    }

    // vytvoreni prazne matice
    Matrix vytvaritMatice1x1()
    {
        matice = Matrix(1, 1);
        matice.set(std::vector<std::vector<double>>{
                {99}
            });
        return matice;
    }    

    // vytvoreni matice 2x2
    Matrix vytvaritMatice2x2()
    {
        matice = Matrix(2, 2);
        matice.set(std::vector<std::vector<double>>{
                {2, 0},
                {5, 1}
            });
        return matice;
    }  

    // vytvoreni matice 4x4
    Matrix vytvaritMatice4x4()
    {
        matice = Matrix(4, 4);
        matice.set(std::vector<std::vector<double>>{
                {2, 2, 2, 2},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
                {2, 2, 2, 2}
            });
        return matice;
    }  

    // vytvoreni matice 3x1
    Matrix vytvaritMatice3x1()
    {
        matice = Matrix(3, 1);
        matice.set(std::vector<std::vector<double>>{
                {-2},
                {1.5},
                {0}
            });
        return matice;
    } 

    // vytvoreni matice 1x3
    Matrix vytvaritMatice1x3()
    {
        matice = Matrix(1, 3);
        matice.set(std::vector<std::vector<double>>{
                {0.2, -1, 3}
                
            });
        return matice;
    } 

};

TEST_F(TestovaniMatice, Vytvarit)
{
    // testovani matic validnich velikosti
    ASSERT_NO_THROW(Matrix());
    ASSERT_NO_THROW(Matrix(1, 1));
    ASSERT_NO_THROW(Matrix(2, 1));
    ASSERT_NO_THROW(Matrix(37, 1));
    ASSERT_NO_THROW(Matrix(1000, 34));

    // testovati vytvoreni matic nevalidnich velikosti
    ASSERT_ANY_THROW(Matrix(0, 2));
    ASSERT_ANY_THROW(Matrix(0, 0));
    ASSERT_ANY_THROW(Matrix(-1, 3));
    ASSERT_ANY_THROW(Matrix(10, 0.5));
    ASSERT_ANY_THROW(Matrix(-3, -2));
    ASSERT_ANY_THROW(Matrix(-0.333, 0.2));
}

TEST_F(TestovaniMatice, dosaditHodnoty1x1)
{
    vytvaritMatice1x1();

    // dosadit hodnotu na validnu pozice a vzit hodnotu z validne pozici
    EXPECT_TRUE(matice.set(0, 0, 0));
    EXPECT_TRUE(matice.set(0, 0, -1));
    EXPECT_TRUE(matice.set(0, 0, 100000));
    EXPECT_TRUE(matice.set(0, -0, 0.0002));
    EXPECT_TRUE(matice.set(0, 0, -5.25));
    EXPECT_TRUE(matice.set(0.2, 0, 5));
    EXPECT_TRUE(matice.set(0, -0.7, 2));  
    EXPECT_NO_THROW(matice.get(0, 0));
    EXPECT_EQ(matice.get(0, 0), 2);
    
    // zkouseni dosadit hodnotu na nevalidni pozice 
    EXPECT_FALSE(matice.set(1, 0, 6));
    EXPECT_FALSE(matice.set(0, 1, 0));
    EXPECT_FALSE(matice.set(-1, -1, 0));
    EXPECT_FALSE(matice.set(0, -11, 5));
    EXPECT_FALSE(matice.set('a', 0, 5));
    EXPECT_FALSE(matice.set('a', 0, 'A'));
    EXPECT_ANY_THROW(matice.get(4, 4));
    EXPECT_NE(matice.get(0, 0), -1);

}

TEST_F(TestovaniMatice, dosaditHodnoty2x2)
{
    vytvaritMatice2x2();
    // dosadit hodnotu na validnu pozice a vzit hodnotu z validne pozici
    EXPECT_TRUE(matice.set(0, 0, 0));
    EXPECT_TRUE(matice.set(1, 0, -1));
    EXPECT_TRUE(matice.set(0, 0, 100000));
    EXPECT_TRUE(matice.set(0, -0, 0.0002));
    EXPECT_TRUE(matice.set(0, 1, -5.25));
    EXPECT_TRUE(matice.set(1.2, 0, 5));
    EXPECT_TRUE(matice.set(0, -0.7, 2));  
    EXPECT_NO_THROW(matice.get(1, 0));
    EXPECT_EQ(matice.get(1, 0), 5);
    
    // zkouseni dosadit hodnotu na nevalidni pozice
    EXPECT_FALSE(matice.set(2, 0, 6));
    EXPECT_FALSE(matice.set(0, 2, 0));
    EXPECT_FALSE(matice.set(-1, -1, 0));
    EXPECT_FALSE(matice.set(0, -11, 5));
    EXPECT_FALSE(matice.set('a', 0, 5));
    EXPECT_FALSE(matice.set('a', 0, 'A'));
    EXPECT_ANY_THROW(matice.get(4, 4));
    EXPECT_NE(matice.get(1, 0), -2);
}

TEST_F(TestovaniMatice, dosaditHodnoty3x1)
{
    vytvaritMatice3x1();

    // dosadit hodnotu na validnu pozice a vzit hodnotu z validne pozici
    EXPECT_TRUE(matice.set(0, 0, 0));
    EXPECT_TRUE(matice.set(2, 0, -1));
    EXPECT_TRUE(matice.set(1, 0, 100000));
    EXPECT_TRUE(matice.set(0, -0, 0.0002));
    EXPECT_TRUE(matice.set(2, 0, -5.25));
    EXPECT_TRUE(matice.set(1.2, 0, 5));
    EXPECT_TRUE(matice.set(0, -0.7, 2));  
    EXPECT_TRUE(matice.get(0, 0));
    EXPECT_EQ(matice.get(0, 0), 2);
    
    // zkouseni dosadit hodnotu na nevalidni pozice
    EXPECT_FALSE(matice.set(3, 0, 6));
    EXPECT_FALSE(matice.set(0, 1, 0));
    EXPECT_FALSE(matice.set(-1, -1, 0));
    EXPECT_FALSE(matice.set(0, -11, 5));
    EXPECT_FALSE(matice.set('a', 0, 5));
    EXPECT_FALSE(matice.set('a', 0, 'A'));
    EXPECT_ANY_THROW(matice.get(4, 4));
    EXPECT_NE(matice.get(0, 0), 1);
}

TEST_F(TestovaniMatice, dosaditHodnoty1x3)
{
    vytvaritMatice1x3();

    // dosadit hodnotu na validnu pozice a vzit hodnotu z validne pozici
    EXPECT_TRUE(matice.set(0, 0, 0));
    EXPECT_TRUE(matice.set(0, 1, -1));
    EXPECT_TRUE(matice.set(0, 0, 100000));
    EXPECT_TRUE(matice.set(0, -0, 0.0002));
    EXPECT_TRUE(matice.set(0, 0, -5.25));
    EXPECT_TRUE(matice.set(0.2, 2, 5));
    EXPECT_TRUE(matice.set(0, -0.7, 2));  
    EXPECT_NO_THROW(matice.get(0, 0));
    EXPECT_EQ(matice.get(0, 2), 5);
    
    // zkouseni dosadit hodnotu na nevalidni pozice
    EXPECT_FALSE(matice.set(1, 0, 6));
    EXPECT_FALSE(matice.set(0, 3, 0));
    EXPECT_FALSE(matice.set(-1, -1, 0));
    EXPECT_FALSE(matice.set(0, -11, 5));
    EXPECT_FALSE(matice.set('a', 0, 5));
    EXPECT_FALSE(matice.set(4, 0, 'A'));
    EXPECT_ANY_THROW(matice.get(4, 4));
    EXPECT_NE(matice.get(0, 2), -1);

}

TEST_F(TestovaniMatice, dosaditHodnoty4x4)
{
    // dosadit hodnotu na validnu pozice a vzit hodnotu z validne pozici
    vytvaritMatice4x4();
    EXPECT_TRUE(matice.set(0, 0, 0));
    EXPECT_TRUE(matice.set(1, 0, -1));
    EXPECT_TRUE(matice.set(0, 3, 100000));
    EXPECT_TRUE(matice.set(0, -0, 0.0002));
    EXPECT_TRUE(matice.set(0, 0, -5.25));
    EXPECT_TRUE(matice.set(2.2, 2, 5));
    EXPECT_TRUE(matice.set(0, -0.7, 2));  
    EXPECT_TRUE(matice.get(3, 2));
    EXPECT_EQ(matice.get(2, 2), 5);
    
    // zkouseni dosadit hodnotu na nevalidni pozice
    EXPECT_FALSE(matice.set(4, 0, 6));
    EXPECT_FALSE(matice.set(0, 4, 0));
    EXPECT_FALSE(matice.set(-1, -1, 0));
    EXPECT_FALSE(matice.set(0, -11, 5));
    EXPECT_FALSE(matice.set('a', 0, 5));
    EXPECT_FALSE(matice.set('a', 0, 'A'));
    EXPECT_ANY_THROW(matice.get(4, 4));
    EXPECT_NE(matice.get(2, 2), -5);

    
     matice = Matrix(4, 4);

     // kontrola chybneho stavu pro matice vytvoreni matic spatne velikosti

       EXPECT_FALSE(matice.set(std::vector<std::vector<double>>{
                {2, 2, 2, 2, 2},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
                {2, 2, 2, 2}
            }));
}


TEST_F(TestovaniMatice, Porovnani)
{
    // porovnani stejnych matic
    Matrix matice = vytvaritMatice2x2();
    ASSERT_TRUE(matice.operator==(vytvaritMatice2x2())); 

    Matrix matice1 = vytvaritMatice2x2();
    matice1.set(std::vector<std::vector<double>>{
                {1, 2},
                {2, 2}
    });
    ASSERT_FALSE(matice1.operator==(vytvaritMatice2x2()));

    // kontrola na vyjimky
    EXPECT_NO_THROW(matice.operator==(vytvaritMatice2x2()));
    EXPECT_ANY_THROW(matice.operator==(vytvaritMatice4x4()));
}

TEST_F(TestovaniMatice, porovnaniMatic)
{
    // porovnani stejnych matic
    Matrix matice = vytvaritMatice2x2();
    ASSERT_TRUE(matice.operator==(vytvaritMatice2x2()));

    Matrix matice1 = vytvaritMatice2x2();
    matice1.set(std::vector<std::vector<double>>{
                {1, 2},
                {2, 2}
    });
    ASSERT_FALSE(matice1.operator==(vytvaritMatice2x2())); //porovnani ruznych matic (ocekavani false)
    // kontrola spravnych a stejnych stavu
    EXPECT_NO_THROW(matice.operator==(vytvaritMatice2x2()));
    EXPECT_ANY_THROW(matice.operator==(vytvaritMatice4x4()));
}

TEST_F(TestovaniMatice, soucetMatic)
{
    // vytvareni nutnych matic
    Matrix matice = vytvaritMatice1x3();

    Matrix matice1 = vytvaritMatice1x3();
    matice1.set(std::vector<std::vector<double>>{
                {0.4, -2, 6}
    });

    
    Matrix matice2 = vytvaritMatice1x3();
    matice2.set(std::vector<std::vector<double>>{
                {0.1, -2, 6}
    });

    // kontrola na spravne/chybne reseni
    EXPECT_TRUE(matice.operator+(vytvaritMatice1x3()) == matice1);
    EXPECT_FALSE(matice.operator+(vytvaritMatice1x3()) == matice2);
    // kontrola spravnych a chybovych stavu
    EXPECT_ANY_THROW(matice.operator+(vytvaritMatice2x2()));
    EXPECT_NO_THROW(matice.operator+(vytvaritMatice1x3()));
}

TEST_F(TestovaniMatice, nasobitConst)
{   
    // vytvareni nutnych matic
     Matrix matice = vytvaritMatice4x4();

     Matrix matice1 = vytvaritMatice4x4();
     matice1.set(std::vector<std::vector<double>>{
                {4, 4, 4, 4},
                {4, 4, 4, 4},
                {4, 4, 4, 4},
                {4, 4, 4, 4}
            });

    // kontrola nasobeni constantou
    EXPECT_TRUE(matice.operator*(2) == matice1);
    EXPECT_FALSE(matice.operator*(3) == matice1);
    EXPECT_NO_THROW(matice.operator*(2.0));
}

TEST_F(TestovaniMatice, nasobitMat)
{
    // vytvoreni matic 3x3
    Matrix matice = vytvaritMatice3x1();
    Matrix matice1 = Matrix(3, 3);
     matice1.set(std::vector<std::vector<double>>{
                {-0.4, 2, -6},
                {0.3, -1.5, 4.5},
                {0, 0, 0}
            });
    Matrix matice2 = Matrix(3, 3);
     matice2.set(std::vector<std::vector<double>>{
                {-0.4, 2, -6},
                {0.3, -1.5, 4.5},
                {0, 1, 0}
            });

    // kontrola nasobeni matic
    EXPECT_FALSE(matice.operator*(vytvaritMatice1x3()) == matice1);
    EXPECT_FALSE(matice.operator*(vytvaritMatice1x3()) == matice2);
    
    // nasobeni matic spatneho rozsahu
    EXPECT_ANY_THROW(matice.operator*(vytvaritMatice2x2()));
    // spravne nasobeni matic
    EXPECT_NO_THROW(matice.operator*(vytvaritMatice1x3()));
}


TEST_F(TestovaniMatice, kramerMat)
{   
    // pokud pocet prvku metody solveEquation se rovna poctu radku matice
    Matrix matice = vytvaritMatice3x1();
    EXPECT_ANY_THROW(matice.solveEquation({2, 1, 3}));
    EXPECT_ANY_THROW(matice.solveEquation({2}));


    Matrix matice1 = vytvaritMatice1x1();
    EXPECT_NO_THROW(matice1.solveEquation({3}));
    EXPECT_NO_THROW(matice1.solveEquation({99}));
    
    //pokud pocet leve strany rovnice odpovida poctu radku matice -> soustava ma reseni (na prave strane)
    EXPECT_TRUE(matice1.solveEquation({99}) == (std::vector<double>{1}));

    Matrix matice2 = vytvaritMatice2x2();
    matice2.set(std::vector<std::vector<double>>{
                {2, 2},
                {2, 2}
    });

    // kontrola chybneho stavu kdyz determinant = 0;
    EXPECT_ANY_THROW(matice2.solveEquation({2, 1}));

    // kontrola pro maticu 3x3
 Matrix matice3 = Matrix(3, 3);
     matice3.set(std::vector<std::vector<double>>{
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}
            });
    EXPECT_NO_THROW(matice3.solveEquation({1, 2, 3}) == (std::vector<double>{1, 2, 3}));

    // kontrola kdyz matice je ctvrcova
    Matrix matice4 = Matrix(4, 4);
     matice4.set(std::vector<std::vector<double>>{
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
            });
    EXPECT_NO_THROW(matice4.solveEquation({1, 2, 3, 4}) == (std::vector<double>{1, 2, 3, 4}));

}

/*** Konec souboru white_box_tests.cpp ***/
