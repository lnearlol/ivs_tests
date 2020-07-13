//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     ROMAN STEPANIUK <xstepa64@stud.fit.vutbr.cz>
// $Date:       $2020-02-22
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author ROMAN STEPANIUK
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu

//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//
/*** Konec souboru black_box_tests.cpp ***/

class EmptyTree: public ::testing::Test {
    protected:
    BinaryTree myTree;   // vytvareni dreva
};

TEST_F(EmptyTree, InsertNode)   // prvni test pro vkladani bunky ve prazny strom
{
    // vkladani a testovani prvni bunky
    std::pair<bool, BinaryTree::Node_t *> element1 = myTree.InsertNode(7); // vytvareni elementu z hodnotou 7
    ASSERT_FALSE(element1.second == NULL); 
    EXPECT_TRUE(element1.first == true); // kontrola ze element existuje
    EXPECT_TRUE(element1.second->pParent == NULL); // kontrola ze element je korenem
    EXPECT_TRUE(element1.second->color == BLACK); // kontrola barvy
    EXPECT_TRUE(element1.second->key == 7);  // kontrola hodnoty

    // vkladani a testovani druhe bunky
    std::pair<bool, BinaryTree::Node_t *> element2 = myTree.InsertNode(10); //vkladani bunky z hodnotou 10
    ASSERT_FALSE (element2.second == NULL);
    EXPECT_TRUE(element2.first == true);
    EXPECT_FALSE(element2.second->pParent == NULL); // kontrola ze rodic existuje
    EXPECT_TRUE(element2.second->color == RED);
    EXPECT_TRUE(element2.second->pParent->color == BLACK); // kontrola barvy rodice
    EXPECT_EQ(element2.second->pParent->key, 7); // kontrola hodnoty rodice
    EXPECT_EQ(element2.second->key, 10);
    
    // vkladani a testovani druhe bunky
    std::pair<bool, BinaryTree::Node_t *> element3 = myTree.InsertNode(12);
    ASSERT_FALSE(element3.second == NULL);
    EXPECT_TRUE(element3.first == true);
    EXPECT_FALSE(element3.second->pParent == NULL);
    EXPECT_EQ(element3.second->color, RED);
    EXPECT_EQ(element3.second->pParent->color, BLACK);
    EXPECT_EQ(element3.second->pParent->key, 10); 
    EXPECT_EQ(element3.second->key, 12);

    // pokus vkladani uz existujiciho elementu
    std::pair<bool, BinaryTree::Node_t *> element_same = myTree.InsertNode(10);
    ASSERT_FALSE(element_same.second == NULL); // testovani ze element ze stejnou hodnotou uz existuje (ukazatel ukazuje ne na nulu)
    EXPECT_FALSE(element_same.first == true); // kontrola ze boolova cast pairu se rovna 0 protoze element uz existuje a boolova cast neni ukazatel

    // vkladani a testovani elementu se zapornou hodnotou
    std::pair<bool, BinaryTree::Node_t *> element_negative = myTree.InsertNode(-2);
    ASSERT_FALSE(element_negative.second == NULL);
    EXPECT_TRUE(element_negative.first == true);
    EXPECT_FALSE(element_negative.second->pParent == NULL);
    EXPECT_EQ(element_negative.second->color, RED);
    EXPECT_EQ(element_negative.second->pParent->key, 7); 
    EXPECT_EQ(element_negative.second->key, -2);
    EXPECT_EQ(element_negative.second->pParent->color, BLACK); 
}


TEST_F(EmptyTree, DeleteNode){
    // testovani odstraneni elementu (ocekavani 'false' protoze strom je prazny)
    EXPECT_FALSE(myTree.DeleteNode(1));
    EXPECT_FALSE(myTree.DeleteNode(-5));
    EXPECT_FALSE(myTree.DeleteNode(55));
   
}

TEST_F(EmptyTree, FindNode){
    // testovani hledani elementu ve praznem drevi (oceakavani 'false' protoze strom je prazny)
    EXPECT_FALSE(myTree.FindNode(1));
    EXPECT_FALSE(myTree.FindNode(-5));
    EXPECT_FALSE(myTree.FindNode(55));
}

    // vytvareni neprazneho stromu vcetne nulove a zapornych hodnot
class NonEmptyTree: public ::testing::Test {
    protected:
    void SetUp(){
        myTree2.InsertNode(-33);
        myTree2.InsertNode(-22);
        myTree2.InsertNode(-11);
        myTree2.InsertNode(0);
        myTree2.InsertNode(11);
        myTree2.InsertNode(22);
        myTree2.InsertNode(33);
    }
    BinaryTree myTree2;
};


TEST_F(NonEmptyTree, InsertNode){

    // pridavani novych bunek v neprazny strom
    std::pair<bool, BinaryTree::Node_t *> element1_1 = myTree2.InsertNode(77);
    ASSERT_FALSE(element1_1.second == NULL);
    EXPECT_TRUE(element1_1.first == true);
    EXPECT_TRUE(element1_1.second->pParent->key == 33);
    EXPECT_TRUE(element1_1.second->pParent->color == BLACK);
    EXPECT_TRUE(element1_1.second->color == RED);
    EXPECT_TRUE(element1_1.second->key == 77);

    std::pair<bool, BinaryTree::Node_t *> element2_2 = myTree2.InsertNode(100);
    ASSERT_FALSE (element2_2.second == NULL);
    EXPECT_TRUE(element2_2.first == true);
    EXPECT_FALSE(element2_2.second->pParent == NULL);
    EXPECT_TRUE(element2_2.second->color == RED);
    EXPECT_TRUE(element2_2.second->pParent->color == BLACK);
    EXPECT_EQ(element2_2.second->pParent->key, 77);
    EXPECT_EQ(element2_2.second->key, 100);
    
    std::pair<bool, BinaryTree::Node_t *> element3_3 = myTree2.InsertNode(122);
    ASSERT_FALSE(element3_3.second == NULL);
    EXPECT_TRUE(element3_3.first == true);
    EXPECT_FALSE(element3_3.second->pParent == NULL);
    EXPECT_EQ(element3_3.second->color, RED);
    EXPECT_EQ(element3_3.second->pParent->color, BLACK);
    EXPECT_EQ(element3_3.second->pParent->key, 100); 
    EXPECT_EQ(element3_3.second->key, 122);

    // pokus pridani uz existujiciho elementu ve prazny strom
    std::pair<bool, BinaryTree::Node_t *> element_same_s = myTree2.InsertNode(100);
    ASSERT_FALSE(element_same_s.second == NULL);
    EXPECT_FALSE(element_same_s.first == true);

    // pridani a testovani neprazneho 
    std::pair<bool, BinaryTree::Node_t *> element_negative_n = myTree2.InsertNode(-222);
    ASSERT_FALSE(element_negative_n.second == NULL);
    EXPECT_TRUE(element_negative_n.first == true);
    EXPECT_FALSE(element_negative_n.second->pParent == NULL);
    EXPECT_EQ(element_negative_n.second->color, RED);
    EXPECT_EQ(element_negative_n.second->key, -222); 
    EXPECT_EQ(element_negative_n.second->pParent->key, -33); 
    EXPECT_EQ(element_negative_n.second->pParent->color, BLACK); 
}

TEST_F(NonEmptyTree, DeleteNode){
    
    // testovani odstraneni uz existujicich elementu (ocekavani 'true')
    EXPECT_TRUE(myTree2.DeleteNode(11));
    EXPECT_TRUE(myTree2.DeleteNode(0));
    EXPECT_TRUE(myTree2.DeleteNode(-22));
    
    // testovani odstraneni uz odstranenoho elementu (ocekavani 'false')
    EXPECT_FALSE(myTree2.DeleteNode(11));
    // testovani odstraneni neexistujicich elementu (ocekavani 'false')
    EXPECT_FALSE(myTree2.DeleteNode(129));
    EXPECT_FALSE(myTree2.DeleteNode(-5));
    EXPECT_FALSE(myTree2.DeleteNode(55));

}

TEST_F(NonEmptyTree, FindNode){

    // testovani hledani uz existujicich elementu
    BinaryTree::Node_t *foundNode = myTree2.FindNode(11);
    ASSERT_FALSE(NULL == foundNode);
    EXPECT_TRUE(foundNode->key == 11);
    EXPECT_TRUE(foundNode->pParent->key == 22);
    EXPECT_TRUE(foundNode->color == RED);
    EXPECT_TRUE(foundNode->pParent->color == BLACK);

    BinaryTree::Node_t *foundNode2 = myTree2.FindNode(-33);
    ASSERT_FALSE(NULL == foundNode2);
    EXPECT_TRUE(foundNode2->key == -33);
    EXPECT_TRUE(foundNode2->pParent->key == -22);
    EXPECT_TRUE(foundNode2->color == BLACK);

    // testovani hledani neexistujicicho elementu (ocekavani ukazatel == NULL)
    BinaryTree::Node_t *notFoundNode = myTree2.FindNode(-100);
    ASSERT_TRUE(NULL == notFoundNode);
}

    //// vytvareni neprazneho stromu pro tridu 'TreeAxioms' vcetne nulove a zapornych hodnot
class TreeAxioms: public ::testing::Test {
protected:

    void SetUp() //vkladani bunek do stromu
    {
        myTree3.InsertNode(66);
        myTree3.InsertNode(55);
        myTree3.InsertNode(44);
        myTree3.InsertNode(33);
        myTree3.InsertNode(22);
        myTree3.InsertNode(11);
        myTree3.InsertNode(1);
        myTree3.InsertNode(0);
        myTree3.InsertNode(-1);
        myTree3.InsertNode(-11);
        myTree3.InsertNode(-22); 
        myTree3.InsertNode(-33);
        myTree3.InsertNode(-44);
        myTree3.InsertNode(-55);
        myTree3.InsertNode(-66);
    } BinaryTree myTree3;
};

    // Testovani 1. axiomy: Vsechny listove uzly stromu jsou *VZDY* cerne.
TEST_F(TreeAxioms, Axiom1){
std::vector<BinaryTree::Node_t *> Leafs;
myTree3.GetLeafNodes(Leafs);
for (int value = 0; value < Leafs.size(); value++){
    EXPECT_TRUE(Leafs[value]->color == BLACK);
        }
}

    // Testovani 2. axiomy: Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
TEST_F(TreeAxioms, Axiom2){
std::vector<BinaryTree::Node_t *> nonLeafs;
myTree3.GetNonLeafNodes(nonLeafs);
for (int value = 0 ; value < nonLeafs.size(); value++){  
    if(nonLeafs[value]->color == RED){ 
        EXPECT_TRUE(nonLeafs[value]->pLeft->color == BLACK);
        EXPECT_TRUE(nonLeafs[value]->pRight->color == BLACK); 
        }
    }
}

    // Testovani 3. axiomy: Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji *STEJNY* pocet cernych uzlu.
TEST_F(TreeAxioms, Axiom3){
std::vector<BinaryTree::Node_t *> LeafsNew;
myTree3.GetLeafNodes(LeafsNew);
int summ = 0; // pocet cernych rodicu
int count; // hodnota pro porovnani poctu cernych rodicu (prijma hodnotu summ na nulove iteraci a pak se srovnaji se summ v jinych iteracich)
BinaryTree::Node_t * current; // ukazatel ktery skaka stromem pokud ne dojde do korene
for (int value = 0; value < LeafsNew.size(); value++){  
    current = LeafsNew[value]->pParent; 
        while(current->pParent != NULL){
            if(current->color == BLACK){
            summ++;
                }
                current = current->pParent;
            }

        if(value == 0){   // podminka pro nulovu iteraci (kdyz potrebujeme vedet kolik cernych prvku musi byt od prvniho listu do korene)
            count = summ;
        }
        EXPECT_TRUE(count == summ);
            summ = 0;
    }
}
