#ifndef CLASSES_H
#define CLASSES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class item {
private:
    const float SCALE_X = 800.f;
    const float SCALE_Y = 850.f;

protected:
    sf::Texture tx;
    sf::Sprite sp;
    string name;

public:
    item() {}
    item(string n);
    void setName(const string& n);
    void loadFromFile();
    sf::Sprite& getsprite();
    string getName();
};

class shirts : public item {
public:
    shirts() {}
    shirts(string a);
    void loadfromfile();
};

class pants : public item {
public:
    pants() {}
    pants(string a);
    void loadfromfile();
};

class shoes : public item {
public:
    shoes() {}
    shoes(string a);
    void loadfromfile();
};

class earrings : public item {
public:
    earrings() {}
    earrings(string a);
    void loadfromfile();
};

class bags : public item {
public:
    bags() {}
    bags(string a);
    void loadfromfile();
};

class watches : public item {
public:
    watches() {}
    watches(string a);
    void loadfromfile();
};

class formal : public item {
public:
    formal() {}
    formal(string a);
    void loadfromfile();
};

// Function prototypes
int findNextAvailableOutfitNumber();
void addNewItems(
    shirts s1[], pants p1[], shoes sh[], earrings ear[], bags b[],
    shirts menShirts[], pants menPants[], shoes menShoes[], watches menWatch[],
    formal f1[], shoes shf[], earrings ef[], bags bagf[],
    formal mf_shirt[], pants mf_pant[], formal mf_blazer[], formal mf_tie[], shoes mf_shoes[],
    int& scount, int& pcount, int& shcount, int& ecount, int& bagcount,
    int& mShCount, int& mPCount, int& mShCount2, int& mWCount,
    int& outfitc, int& shoesc, int& earringc, int& bagc,
    int& mfSCount, int& mfPCount, int& mfBCount, int& mfTCount, int& mfShCount,
    const int size
);
void deleteItems(
    shirts s1[], pants p1[], shoes sh[], earrings ear[], bags b[],
    shirts menShirts[], pants menPants[], shoes menShoes[], watches menWatch[],
    formal f1[], shoes shf[], earrings ef[], bags bagf[],
    formal mf_shirt[], pants mf_pant[], formal mf_blazer[], formal mf_tie[], shoes mf_shoes[],
    int& scount, int& pcount, int& shcount, int& ecount, int& bagcount,
    int& mShCount, int& mPCount, int& mShCount2, int& mWCount,
    int& outfitc, int& shoesc, int& earringc, int& bagc,
    int& mfSCount, int& mfPCount, int& mfBCount, int& mfTCount, int& mfShCount,
    const int size
);
#endif#pragma once
