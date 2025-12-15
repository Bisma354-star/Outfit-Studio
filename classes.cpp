#include "classes.h"


item::item(string n) : name(n) {}

void item::setName(const string& n) {
    name = n;
}

void item::loadFromFile() {
    tx.loadFromFile(name);
    sp.setTexture(tx);
    sp.setPosition(121, 47);
    float scaleX = SCALE_X / tx.getSize().x;
    float scaleY = SCALE_Y / tx.getSize().y;
    sp.setScale(scaleX, scaleY);
}

sf::Sprite& item::getsprite() {
    return sp;
}

string item::getName() {
    return name;
}

shirts::shirts(string a) : item(a) {}

void shirts::loadfromfile() {
    item::loadFromFile();
}


pants::pants(string a) : item(a) {}

void pants::loadfromfile() {
    item::loadFromFile();
}


shoes::shoes(string a) : item(a) {}

void shoes::loadfromfile() {
    item::loadFromFile();
}


earrings::earrings(string a) : item(a) {}

void earrings::loadfromfile() {
    item::loadFromFile();
}

bags::bags(string a) : item(a) {}

void bags::loadfromfile() {
    item::loadFromFile();
}

watches::watches(string a) : item(a) {}

void watches::loadfromfile() {
    item::loadFromFile();
}


formal::formal(string a) : item(a) {}

void formal::loadfromfile() {
    item::loadFromFile();
}

int findNextAvailableOutfitNumber() {
    for (int i = 1; i <= 100; i++) {
        std::string filename = "outfit_" + std::to_string(i) + ".png";
        std::ifstream file(filename);
        if (!file.good()) {
            return i;
        }
    }
    return -1;
}
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
) {
    string newItem;
    char choice;
    //asking for category choice
    int cat;
    cout << "Select category in which u wanna add items" << endl;
    cout << "1. Women Casual" << endl;
    cout << "2. Men Casual" << endl;
    cout << "3. Women Formal" << endl;
    cout << "4. Men Formal" << endl;
    cout << "Enter choice:" << endl;
    cin >> cat;
    switch (cat)
    {
    case 1:
        cout << "Add Shirt? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && scount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            s1[scount].setName(newItem);
            s1[scount].loadfromfile();
            scount++;
        }

        cout << "Add Pants? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && pcount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            p1[pcount].setName(newItem);
            p1[pcount].loadfromfile();
            pcount++;
        }

        cout << "Add Shoes? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && shcount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            sh[shcount].setName(newItem);
            sh[shcount].loadfromfile();
            shcount++;
        }

        cout << "Add Earrings? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && ecount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            ear[ecount].setName(newItem);
            ear[ecount].loadfromfile();
            ecount++;
        }

        cout << "Add Bag? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && bagcount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            b[bagcount].setName(newItem);
            b[bagcount].loadfromfile();
            bagcount++;
        }
        break;

    case 2:
        cout << "Add Shirt? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mShCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            menShirts[mShCount].setName(newItem);
            menShirts[mShCount].loadfromfile();
            mShCount++;
        }

        cout << "Add Pants? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mPCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            menPants[mPCount].setName(newItem);
             menPants[mPCount].loadfromfile(); 
            mPCount++;
        }

        cout << "Add Shoes? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mShCount2 < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            menShoes[mShCount2].setName(newItem);
            menShoes[mShCount2].loadfromfile();
            mShCount2++;
        }

        cout << "Add Watch? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mWCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            menWatch[mWCount].setName(newItem);
            menWatch[mWCount].loadfromfile();
            mWCount++;
        }
        break;

    case 3:
        cout << "Add Outfit? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && outfitc < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            f1[outfitc].setName(newItem);
            f1[outfitc].loadfromfile();
            outfitc++;
        }

        cout << "Add Shoes? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && shoesc < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            shf[shoesc].setName(newItem);
            shf[shoesc].loadfromfile();
            shoesc++;
        }

        cout << "Add Earrings? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && earringc < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            ef[earringc].setName(newItem);
            ef[earringc].loadfromfile();
            earringc++;
        }

        cout << "Add Bag? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && bagc < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            bagf[bagc].setName(newItem);
            bagf[bagc].loadfromfile();
            bagc++;
        }
        break;

    case 4:
        cout << "Add Shirt? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mfSCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            mf_shirt[mfSCount].setName(newItem);
            mf_shirt[mfSCount].loadfromfile();
            mfSCount++;
        }

        cout << "Add Pant? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mfPCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            mf_pant[mfPCount].setName(newItem);
            mf_pant[mfPCount].loadfromfile();
            mfPCount++;
        }

        cout << "Add Blazer? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mfBCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            mf_blazer[mfBCount].setName(newItem);
            mf_blazer[mfBCount].loadfromfile();
            mfBCount++;
        }

        cout << "Add Tie? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mfTCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            mf_tie[mfTCount].setName(newItem);
            mf_tie[mfTCount].loadfromfile();
            mfTCount++;
        }

        cout << "Add Shoes? (y/n): ";
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && mfShCount < size)
        {
            cout << "Filename: ";
            cin >> newItem;
            mf_shoes[mfShCount].setName(newItem);
            mf_shoes[mfShCount].loadfromfile();
            mfShCount++;
        }
        break;

    default:
        cout << "Invalid category selected.\n";
    }
}
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
) {
    int index;
    char choice;
    int cat;

    cout << "Select category from which u wanna delete items" << endl;
    cout << "1. Women Casual" << endl;
    cout << "2. Men Casual" << endl;
    cout << "3. Women Formal" << endl;
    cout << "4. Men Formal" << endl;
    cout << "Enter choice:" << endl;
    cin >> cat;

    switch (cat) {
    case 1:
        cout << "Delete Shirt? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << scount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < scount) {
                if (index != scount - 1) {
                    s1[index].setName(s1[scount - 1].getName());
                    s1[index].loadfromfile();
                }
                scount--;
                cout << "Shirt deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Pants? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << pcount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < pcount) {
                if (index != pcount - 1) {
                    p1[index].setName(p1[pcount - 1].getName());
                    p1[index].loadfromfile();
                }
                pcount--;
                cout << "Pants deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Shoes? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << shcount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < shcount) {
                if (index != shcount - 1) {
                    sh[index].setName(sh[shcount - 1].getName());
                    sh[index].loadfromfile();
                }
                shcount--;
                cout << "Shoes deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Earrings? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << ecount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < ecount) {
                if (index != ecount - 1) {
                    ear[index].setName(ear[ecount - 1].getName());
                    ear[index].loadfromfile();
                }
                ecount--;
                cout << "Earrings deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Bag? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << bagcount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < bagcount) {
                if (index != bagcount - 1) {
                    b[index].setName(b[bagcount - 1].getName());
                    b[index].loadfromfile();
                }
                bagcount--;
                cout << "Bag deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;

    case 2:
        cout << "Delete Shirt? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mShCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mShCount) {
                if (index != mShCount - 1) {
                    menShirts[index].setName(menShirts[mShCount - 1].getName());
                    menShirts[index].loadfromfile();
                }
                mShCount--;
                cout << "Men Shirt deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Pants? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mPCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mPCount) {
                if (index != mPCount - 1) {
                    menPants[index].setName(menPants[mPCount - 1].getName());
                    menPants[index].loadfromfile();
                }
                mPCount--;
                cout << "Men Pants deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Shoes? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mShCount2 - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mShCount2) {
                if (index != mShCount2 - 1) {
                    menShoes[index].setName(menShoes[mShCount2 - 1].getName());
                    menShoes[index].loadfromfile();
                }
                mShCount2--;
                cout << "Men Shoes deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Watch? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mWCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mWCount) {
                if (index != mWCount - 1) {
                    menWatch[index].setName(menWatch[mWCount - 1].getName());
                    menWatch[index].loadfromfile();
                }
                mWCount--;
                cout << "Watch deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;

    case 3:
        cout << "Delete Outfit? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << outfitc - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < outfitc) {
                if (index != outfitc - 1) {
                    f1[index].setName(f1[outfitc - 1].getName());
                    f1[index].loadfromfile();
                }
                outfitc--;
                cout << "Women Formal Outfit deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Shoes? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << shoesc - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < shoesc) {
                if (index != shoesc - 1) {
                    shf[index].setName(shf[shoesc - 1].getName());
                    shf[index].loadfromfile();
                }
                shoesc--;
                cout << "Women Formal Shoes deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Earrings? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << earringc - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < earringc) {
                if (index != earringc - 1) {
                    ef[index].setName(ef[earringc - 1].getName());
                    ef[index].loadfromfile();
                }
                earringc--;
                cout << "Women Formal Earrings deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Bag? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << bagc - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < bagc) {
                if (index != bagc - 1) {
                    bagf[index].setName(bagf[bagc - 1].getName());
                    bagf[index].loadfromfile();
                }
                bagc--;
                cout << "Women Formal Bag deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;

    case 4:
        cout << "Delete Shirt? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mfSCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mfSCount) {
                if (index != mfSCount - 1) {
                    mf_shirt[index].setName(mf_shirt[mfSCount - 1].getName());
                    mf_shirt[index].loadfromfile();
                }
                mfSCount--;
                cout << "Men Formal Shirt deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Pant? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mfPCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mfPCount) {
                if (index != mfPCount - 1) {
                    mf_pant[index].setName(mf_pant[mfPCount - 1].getName());
                    mf_pant[index].loadfromfile();
                }
                mfPCount--;
                cout << "Men Formal Pant deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Blazer? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mfBCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mfBCount) {
                if (index != mfBCount - 1) {
                    mf_blazer[index].setName(mf_blazer[mfBCount - 1].getName());
                    mf_blazer[index].loadfromfile();
                }
                mfBCount--;
                cout << "Men Formal Blazer deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Tie? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mfTCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mfTCount) {
                if (index != mfTCount - 1) {
                    mf_tie[index].setName(mf_tie[mfTCount - 1].getName());
                    mf_tie[index].loadfromfile();
                }
                mfTCount--;
                cout << "Men Formal Tie deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }

        cout << "Delete Shoes? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter index to delete (0 to " << mfShCount - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < mfShCount) {
                if (index != mfShCount - 1) {
                    mf_shoes[index].setName(mf_shoes[mfShCount - 1].getName());
                    mf_shoes[index].loadfromfile();
                }
                mfShCount--;
                cout << "Men Formal Shoes deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;

    default:
        cout << "Invalid category selected.\n";
    }
}