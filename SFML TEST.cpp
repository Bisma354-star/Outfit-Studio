#include "classes.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Outfit Planner");

    int categorychoice = 0;
    //final outfit saving/////////////
    const int MAX_OUTFITS = 100;
    int outfitCount = 0;
    sf::Texture galleryTextures[MAX_OUTFITS];
    sf::Sprite gallerySprites[MAX_OUTFITS];
    int currentGalleryIndex = 0;
    bool showGallery = false;
    bool menuActive = true;
    ////////////////////////////
    const int size = 50;

    //for women
    shirts s1[size] = { shirts("s1.png"), shirts("s2.png"),shirts("s3.png"),shirts("s4.png"),shirts("s5.png"),
    shirts("s6.png"),shirts("s7.png") };
    pants p1[size] = { pants("p1.png"),pants("p2.png"),pants("p3.png"),pants("p4.png") };
    shoes sh[size] = { shoes("sh1.png"),shoes("sh2.png"),shoes("sh3.png"),shoes("sh4.png") };
    earrings ear[size] = { earrings("e1.png"),earrings("e2.png"),earrings("e3.png"),earrings("e4.png") };
    bags b[size] = { bags("b1.png"),bags("b2.png"),bags("b3.png"),bags("b4.png") };
    int scount = 7;
    int pcount = 4;
    int shcount = 4;
    int ecount = 4;
    int bagcount = 4;

    //for men 
    shirts menShirts[size] = { shirts("ms1.png"), shirts("ms2.png"), shirts("ms3.png"),shirts("ms4.png") };
    pants menPants[size] = { pants("mp1.png"), pants("mp2.png"),pants("mp3.png"), pants("mp4.png") };
    shoes menShoes[size] = { shoes("msh1.png"), shoes("msh2.png"),shoes("msh3.png"), shoes("msh4.png") };
    watches menWatch[size] = { watches("w1.png"), watches("w2.png"),watches("w3.png"), watches("w4.png") };

    int mShCount = 4, mPCount = 4, mShCount2 = 4, mWCount = 4;
    int selShirt = -1, selPant = -1, selShoe = -1, selWatch = -1;
    int idxShirt = 0, idxPant = 0, idxShoe = 0, idxWatch = 0;//display sel items
    bool shirtDone = false, pantDone = false, shoeDone = false; //unlock/lock sel items

    for (int i = 0; i < mShCount; i++) menShirts[i].loadfromfile();
    for (int i = 0; i < mPCount; i++) menPants[i].loadfromfile();
    for (int i = 0; i < mShCount2; i++) menShoes[i].loadfromfile();
    for (int i = 0; i < mWCount; i++) menWatch[i].loadfromfile();

    //file handling
    string shirtNames[size];
    string pantsNames[size];
    string shoesNames[size];
    string earringsNames[size];
    string bagNames[size];

    // load items
    for (int i = 0; i < scount; i++) s1[i].loadfromfile();
    for (int i = 0; i < pcount; i++) p1[i].loadfromfile();
    for (int i = 0; i < shcount; i++) sh[i].loadfromfile();
    for (int i = 0; i < ecount; i++) ear[i].loadfromfile();
    for (int i = 0; i < bagcount; i++) b[i].loadfromfile();

    int j = 0, selS = -1; bool displaySelS = false;
    int k = 0, selP = -1; bool displaySelP = false; bool pantsU = false;
    int l = 0, selsh = -1; bool displaySelsh = false; bool shoesUnlock = false;
    int m = 0, sele = -1; bool displaySelm = false; bool earringsunlock = false;
    int n = 0, seln = -1; bool displaySeln = false; bool bagsUnlock = false;
    bool displayoutfit = false;

    //for women formal//
    formal f1[size] = { formal("f1.png"), formal("f2.png"),formal("f3.png"),formal("f4.png") };
    shoes shf[size] = { shoes("fs1.png"),shoes("fs2.png"),shoes("fs3.png"),shoes("fs4.png") };
    earrings ef[size] = { earrings("fe1.png"),earrings("fe2.png"),earrings("fe3.png"),earrings("fe4.png") };
    bags bagf[size] = { bags("fb1.png"),bags("fb2.png"),bags("fb3.png"),bags("fb4.png") };

    int outfitc = 4;
    int shoesc = 4;
    int earringc = 4;
    int bagc = 4;

    int selO = -1, selShoes = -1, selearrings = -1, selBags = -1;
    int idxO = 0, idxShOES = 0, idxE = 0, idxB = 0;//display sel items
    bool outfitU = false, shoesU = false, earrU = false, BagsU = false; //unlock/lock sel items

    bool formalWomenActive = false;
    for (int i = 0; i < outfitc; i++)  f1[i].loadfromfile();
    for (int i = 0; i < shoesc; i++)   shf[i].loadfromfile();
    for (int i = 0; i < earringc; i++) ef[i].loadfromfile();
    for (int i = 0; i < bagc; i++)     bagf[i].loadfromfile();
    ///////////////////////////////////////////////////////////////

    //formal men *****************************//
    formal mf_shirt[size] = { formal("mfs1.png"), formal("mfs2.png"),formal("mfs4.png") };
    pants mf_pant[size] = { pants("mfp1.png"), pants("mfp2.png"),pants("mfp3.png") };
    formal mf_blazer[size] = { formal("bl1.png"), formal("bl2.png"),formal("bl4.png") };
    formal mf_tie[size] = { formal("t1.png"), formal("t2.png"),formal("t3.png"), formal("t4.png") };
    shoes mf_shoes[size] = { shoes("mfsh1.png"), shoes("mfsh2.png"),shoes("mfsh3.png"), shoes("mfsh4.png") };

    int mfSCount = 3, mfPCount = 3, mfBCount = 3, mfTCount = 4, mfShCount = 4;

    int selMFShirt = -1, selMFPant = -1, selMFBlazer = -1;
    int selMFTie = -1, selMFShoes = -1;

    int idxMFShirt = 0, idxMFPant = 0, idxMFBlazer = 0;
    int idxMFTie = 0, idxMFShoes = 0;

    bool mfShirtU = false, mfPantU = false, mfBlazerU = false;
    bool mfTieU = false, mfShoesU = false;

    bool formalMenActive = false;

    for (int i = 0; i < mfSCount; i++) mf_shirt[i].loadfromfile();
    for (int i = 0; i < mfPCount; i++) mf_pant[i].loadfromfile();
    for (int i = 0; i < mfBCount; i++) mf_blazer[i].loadfromfile();
    for (int i = 0; i < mfTCount; i++) mf_tie[i].loadfromfile();
    for (int i = 0; i < mfShCount; i++) mf_shoes[i].loadfromfile();

    //main menu just checking
    sf::Texture menu;
    sf::Sprite menuu;
    menu.loadFromFile("main menu oop.jpg");
    menuu.setTexture(menu);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = menu.getSize();
    menuu.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
    menuu.setPosition(0, 0);

    //bg image load
    // Load background ONCE
    sf::Texture bgTexture;
    bgTexture.loadFromFile("bg oop.jpg");
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTexture);

   
    bgSprite.setScale(
        window.getSize().x / (float)bgTexture.getSize().x,
        window.getSize().y / (float)bgTexture.getSize().y
    );

    bool womenActive = false;
    bool menActive = false;

    //whop sound
    sf::SoundBuffer keyBuffer;
    if (!keyBuffer.loadFromFile("whoop.wav"))
    {
        std::cout << "Failed to load sound\n";
    }

    sf::Sound keySound;
    keySound.setBuffer(keyBuffer);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::KeyPressed)
            {
                keySound.play();
            }

            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
            {
               
                menuActive = true;
            
                womenActive = false;
                menActive = false;
                formalWomenActive = false;
                showGallery = false;
                selS = selP = seln = sele = selsh = -1;
                selShirt = selPant = selShoe = selWatch = -1;
                selO = selShoes = selearrings = selBags = -1;
                continue; 
            }
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::KeyPressed) {
                if (menuActive && e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::Num6)
                    {
                        addNewItems(
                            s1, p1, sh, ear, b,
                            menShirts, menPants, menShoes, menWatch,
                            f1, shf, ef, bagf,
                            mf_shirt, mf_pant, mf_blazer, mf_tie, mf_shoes,
                            scount, pcount, shcount, ecount, bagcount,
                            mShCount, mPCount, mShCount2, mWCount,
                            outfitc, shoesc, earringc, bagc,
                            mfSCount, mfPCount, mfBCount, mfTCount, mfShCount,
                            size
                        );
                    }
                    if (e.key.code == sf::Keyboard::Num7)
                    {
                        deleteItems(
                            s1, p1, sh, ear, b,
                            menShirts, menPants, menShoes, menWatch,
                            f1, shf, ef, bagf,
                            mf_shirt, mf_pant, mf_blazer, mf_tie, mf_shoes,
                            scount, pcount, shcount, ecount, bagcount,
                            mShCount, mPCount, mShCount2, mWCount,
                            outfitc, shoesc, earringc, bagc,
                            mfSCount, mfPCount, mfBCount, mfTCount, mfShCount,
                            size
                        );
                    }
                    if (e.key.code == sf::Keyboard::Num1)
                    {
                        womenActive = true;
                        menuActive = false;
                    }
                    if (e.key.code == sf::Keyboard::Num2)
                    {
                        menActive = true;
                        menuActive = false;
                    }
                    if (e.key.code == sf::Keyboard::Num3)
                    {
                        formalWomenActive = true;
                        menuActive = false;
                    }
                    if (e.key.code == sf::Keyboard::Num5)
                    {
                        
                        outfitCount = 0; 
                        currentGalleryIndex = 0;

                        for (int i = 1; i <= MAX_OUTFITS; i++)
                        {
                            std::string filename = "outfit_" + std::to_string(i) + ".png";

                          
                            ifstream fileCheck(filename);
                            if (!fileCheck.good()) {
                                continue; 
                            }
                            fileCheck.close();

                            // Try to load the texture
                            if (galleryTextures[outfitCount].loadFromFile(filename))
                            {
                                gallerySprites[outfitCount].setTexture(galleryTextures[outfitCount]);
                                float scale = std::min(1000.f / galleryTextures[outfitCount].getSize().x,
                                    1000.f / galleryTextures[outfitCount].getSize().y);
                                gallerySprites[outfitCount].setScale(scale, scale);

                                float w = galleryTextures[outfitCount].getSize().x * scale;
                                float h = galleryTextures[outfitCount].getSize().y * scale;
                                gallerySprites[outfitCount].setPosition((1000 - w) / 2, (1000 - h) / 2);

                                outfitCount++;
                            }

                            if (outfitCount >= MAX_OUTFITS) break; 
                        }

                        if (outfitCount > 0)
                        {
                            showGallery = true;
                            menuActive = false;
                            std::cout << "Loaded " << outfitCount << " outfits.\n";
                        }
                        else
                        {
                            std::cout << "No saved outfits found.\n";
                        }
                    }
                    if (e.key.code == sf::Keyboard::Num4)
                    {
                        formalMenActive = true;
                        menuActive = false;
                    }
                }

                //gallery navigation
                if (showGallery && e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::Right)
                    {
                        if (currentGalleryIndex < outfitCount - 1)
                            currentGalleryIndex++;
                    }
                    if (e.key.code == sf::Keyboard::Left)
                    {
                        if (currentGalleryIndex > 0)
                            currentGalleryIndex--;
                    }
                    if (e.key.code == sf::Keyboard::Escape)
                    {
                        showGallery = false;
                        menuActive = true;
                    }
                }

                if (womenActive && !showGallery && e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::F1) {
                        selsh = selS = sele = selP = seln = -1;
                        bagsUnlock = shoesUnlock = earringsunlock = displayoutfit = false;
                        pantsU = false;
                        j = k = l = m = n = 0;

                        for (int i = 0; i < scount; i++) {
                            s1[i].getsprite().setPosition(121, 47);
                            s1[i].getsprite().setScale(800.0f / s1[i].getsprite().getTexture()->getSize().x,
                                850.0f / s1[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < pcount; i++) {
                            p1[i].getsprite().setPosition(121, 47);
                            p1[i].getsprite().setScale(800.0f / p1[i].getsprite().getTexture()->getSize().x,
                                850.0f / p1[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < shcount; i++) {
                            sh[i].getsprite().setPosition(121, 47);
                            sh[i].getsprite().setScale(800.0f / sh[i].getsprite().getTexture()->getSize().x,
                                850.0f / sh[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < ecount; i++) {
                            ear[i].getsprite().setPosition(121, 47);
                            ear[i].getsprite().setScale(800.0f / ear[i].getsprite().getTexture()->getSize().x,
                                850.0f / ear[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < bagcount; i++) {
                            b[i].getsprite().setPosition(100, 30);
                            b[i].getsprite().setScale(800.0f / b[i].getsprite().getTexture()->getSize().x,
                                850.0f / b[i].getsprite().getTexture()->getSize().y);
                        }
                    }
                    if (!pantsU) {
                        if (e.key.code == sf::Keyboard::Right) { j++; if (j >= scount) j = scount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { j--; if (j < 0) j = 0; }
                        if (e.key.code == sf::Keyboard::S) { selS = j; displaySelS = false; pantsU = true; }
                    }
                    else if (pantsU && selP == -1) {
                        if (e.key.code == sf::Keyboard::Right) { k++; if (k >= pcount) k = pcount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { k--; if (k < 0) k = 0; }
                        if (e.key.code == sf::Keyboard::S) { selP = k; displaySelP = false; shoesUnlock = true; }
                    }
                    else if (shoesUnlock && selsh == -1) {
                        if (e.key.code == sf::Keyboard::Right) { l++; if (l >= shcount) l = shcount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { l--; if (l < 0) l = 0; }
                        if (e.key.code == sf::Keyboard::S) { selsh = l; displaySelsh = false; earringsunlock = true; }
                    }
                    else if (earringsunlock && sele == -1) {
                        if (e.key.code == sf::Keyboard::Right) { m++; if (m >= ecount) m = ecount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { m--; if (m < 0) m = 0; }
                        if (e.key.code == sf::Keyboard::S) { sele = m; displaySelm = false; bagsUnlock = true; }
                    }
                    else if (bagsUnlock && seln == -1) {
                        if (e.key.code == sf::Keyboard::Right) { n++; if (n >= bagcount) n = bagcount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { n--; if (n < 0) n = 0; }
                        if (e.key.code == sf::Keyboard::S) { seln = n; displaySeln = false; displayoutfit = true; }
                    }
                }
                if (menActive && !showGallery && e.type == sf::Event::KeyPressed)
                {
                    /* Men category logic */
                    if (e.key.code == sf::Keyboard::F1) {
                        selShirt = selPant = selShoe = selWatch = -1;
                        idxShirt = idxPant = idxShoe = idxWatch = 0;
                        shirtDone = pantDone = shoeDone = false;

                        for (int i = 0; i < mShCount; i++) {
                            menShirts[i].getsprite().setPosition(121, 47);
                            menShirts[i].getsprite().setScale(800.0f / menShirts[i].getsprite().getTexture()->getSize().x,
                                850.0f / menShirts[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < mPCount; i++) {
                            menPants[i].getsprite().setPosition(121, 47);
                            menPants[i].getsprite().setScale(800.0f / menPants[i].getsprite().getTexture()->getSize().x,
                                850.0f / menPants[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < mShCount2; i++) {
                            menShoes[i].getsprite().setPosition(121, 47);
                            menShoes[i].getsprite().setScale(800.0f / menShoes[i].getsprite().getTexture()->getSize().x,
                                850.0f / menShoes[i].getsprite().getTexture()->getSize().y);
                        }
                        for (int i = 0; i < mWCount; i++) {
                            menWatch[i].getsprite().setPosition(121, 47);
                            menWatch[i].getsprite().setScale(800.0f / menWatch[i].getsprite().getTexture()->getSize().x,
                                850.0f / menWatch[i].getsprite().getTexture()->getSize().y);
                        }
                    }
                    if (!shirtDone) {
                        if (e.key.code == sf::Keyboard::Right) { idxShirt++; if (idxShirt >= mShCount) idxShirt = mShCount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { idxShirt--; if (idxShirt < 0) idxShirt = 0; }
                        if (e.key.code == sf::Keyboard::S) { selShirt = idxShirt; shirtDone = true; }
                    }
                    // Pants selection
                    else if (!pantDone) {
                        if (e.key.code == sf::Keyboard::Right) { idxPant++; if (idxPant >= mPCount) idxPant = mPCount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { idxPant--; if (idxPant < 0) idxPant = 0; }
                        if (e.key.code == sf::Keyboard::S) { selPant = idxPant; pantDone = true; }
                    }
                    // Shoes selection
                    else if (!shoeDone) {
                        if (e.key.code == sf::Keyboard::Right) { idxShoe++; if (idxShoe >= mShCount2) idxShoe = mShCount2 - 1; }
                        if (e.key.code == sf::Keyboard::Left) { idxShoe--; if (idxShoe < 0) idxShoe = 0; }
                        if (e.key.code == sf::Keyboard::S) { selShoe = idxShoe; shoeDone = true; }
                    }
                    // Watch selection
                    else if (selWatch == -1) {
                        if (e.key.code == sf::Keyboard::Right) { idxWatch++; if (idxWatch >= mWCount) idxWatch = mWCount - 1; }
                        if (e.key.code == sf::Keyboard::Left) { idxWatch--; if (idxWatch < 0) idxWatch = 0; }
                        if (e.key.code == sf::Keyboard::S) { selWatch = idxWatch; }
                    }
                }
                //for formal women fits
                if (formalWomenActive && !showGallery && e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::F1)
                    {
                        selO = selShoes = selearrings = selBags = -1;
                        idxO = idxShOES = idxE = idxB = 0;
                        outfitU = shoesU = earrU = BagsU = false;

                        for (int i = 0; i < outfitc; i++) {
                            f1[i].getsprite().setPosition(121, 47);
                            f1[i].getsprite().setScale(
                                800.f / f1[i].getsprite().getTexture()->getSize().x,
                                850.f / f1[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        for (int i = 0; i < shoesc; i++) {
                            shf[i].getsprite().setPosition(121, 47);
                            shf[i].getsprite().setScale(
                                800.f / shf[i].getsprite().getTexture()->getSize().x,
                                850.f / shf[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        for (int i = 0; i < earringc; i++) {
                            ef[i].getsprite().setPosition(121, 47);
                            ef[i].getsprite().setScale(
                                800.f / ef[i].getsprite().getTexture()->getSize().x,
                                850.f / ef[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        for (int i = 0; i < bagc; i++) {
                            bagf[i].getsprite().setPosition(100, 30);
                            bagf[i].getsprite().setScale(
                                800.f / bagf[i].getsprite().getTexture()->getSize().x,
                                850.f / bagf[i].getsprite().getTexture()->getSize().y
                            );
                        }
                    }
                    if (!outfitU) {
                        if (e.key.code == sf::Keyboard::Right)
                        {
                            idxO++; if (idxO >= outfitc) idxO = outfitc - 1;
                        }
                        if (e.key.code == sf::Keyboard::Left)
                        {
                            idxO--; if (idxO < 0) idxO = 0;
                        }
                        if (e.key.code == sf::Keyboard::S)
                        {
                            selO = idxO; outfitU = true;
                        }
                    }
                    else if (!shoesU) {
                        if (e.key.code == sf::Keyboard::Right)
                        {
                            idxShOES++;
                            if (idxShOES >= shoesc)
                                idxShOES = shoesc - 1;
                        }
                        if (e.key.code == sf::Keyboard::Left)
                        {
                            idxShOES--;
                            if (idxShOES < 0)
                                idxShOES = 0;
                        }
                        if (e.key.code == sf::Keyboard::S)
                        {
                            selShoes = idxShOES;
                            shoesU = true;
                        }
                    }
                    else if (!earrU) {
                        if (e.key.code == sf::Keyboard::Right)
                        {
                            idxE++;
                            if (idxE >= earringc)
                                idxE = earringc - 1;
                        }
                        if (e.key.code == sf::Keyboard::Left)
                        {
                            idxE--;
                            if (idxE < 0)
                                idxE = 0;
                        }
                        if (e.key.code == sf::Keyboard::S)
                        {
                            selearrings = idxE;
                            earrU = true;
                        }
                    }
                    else if (!BagsU) {
                        if (e.key.code == sf::Keyboard::Right)
                        {
                            idxB++;
                            if (idxB >= bagc)
                                idxB = bagc - 1;
                        }
                        if (e.key.code == sf::Keyboard::Left)
                        {
                            idxB--;
                            if (idxB < 0)
                                idxB = 0;
                        }
                        if (e.key.code == sf::Keyboard::S)
                        {
                            selBags = idxB;
                            BagsU = true;
                        }
                    }
                }
                // men formal fits
                if (formalMenActive && !showGallery && e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::F1)
                    {
                        selMFShirt = selMFPant = selMFBlazer = selMFTie = selMFShoes = -1;
                        idxMFShirt = idxMFPant = idxMFBlazer = idxMFTie = idxMFShoes = 0;
                        mfShirtU = mfPantU = mfBlazerU = mfTieU = mfShoesU = false;
                        // Men Formal Shirts
                        for (int i = 0; i < mfSCount; i++)
                        {
                            mf_shirt[i].getsprite().setPosition(121, 47);
                            mf_shirt[i].getsprite().setScale(
                                800.f / mf_shirt[i].getsprite().getTexture()->getSize().x,
                                850.f / mf_shirt[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        // Men Formal Pants
                        for (int i = 0; i < mfPCount; i++)
                        {
                            mf_pant[i].getsprite().setPosition(121, 47);
                            mf_pant[i].getsprite().setScale(
                                800.f / mf_pant[i].getsprite().getTexture()->getSize().x,
                                850.f / mf_pant[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        // Men Formal Blazers
                        for (int i = 0; i < mfBCount; i++)
                        {
                            mf_blazer[i].getsprite().setPosition(121, 47);
                            mf_blazer[i].getsprite().setScale(
                                800.f / mf_blazer[i].getsprite().getTexture()->getSize().x,
                                850.f / mf_blazer[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        // Men Formal Ties
                        for (int i = 0; i < mfTCount; i++)
                        {
                            mf_tie[i].getsprite().setPosition(121, 47);
                            mf_tie[i].getsprite().setScale(
                                800.f / mf_tie[i].getsprite().getTexture()->getSize().x,
                                850.f / mf_tie[i].getsprite().getTexture()->getSize().y
                            );
                        }
                        // Men Formal Shoes
                        for (int i = 0; i < mfShCount; i++)
                        {
                            mf_shoes[i].getsprite().setPosition(121, 47);
                            mf_shoes[i].getsprite().setScale(
                                800.f / mf_shoes[i].getsprite().getTexture()->getSize().x,
                                850.f / mf_shoes[i].getsprite().getTexture()->getSize().y
                            );
                        }
                    }
                    if (!mfShirtU)
                    {
                        if (e.key.code == sf::Keyboard::Right) idxMFShirt = min(idxMFShirt + 1, mfSCount - 1);
                        if (e.key.code == sf::Keyboard::Left)  idxMFShirt = max(idxMFShirt - 1, 0);
                        if (e.key.code == sf::Keyboard::S) { selMFShirt = idxMFShirt; mfShirtU = true; }
                    }
                    else if (!mfPantU)
                    {
                        if (e.key.code == sf::Keyboard::Right) idxMFPant = min(idxMFPant + 1, mfPCount - 1);
                        if (e.key.code == sf::Keyboard::Left)  idxMFPant = max(idxMFPant - 1, 0);
                        if (e.key.code == sf::Keyboard::S) { selMFPant = idxMFPant; mfPantU = true; }
                    }
                    else if (!mfBlazerU)
                    {
                        if (e.key.code == sf::Keyboard::Right) idxMFBlazer = min(idxMFBlazer + 1, mfBCount - 1);
                        if (e.key.code == sf::Keyboard::Left)  idxMFBlazer = max(idxMFBlazer - 1, 0);
                        if (e.key.code == sf::Keyboard::S) { selMFBlazer = idxMFBlazer; mfBlazerU = true; }
                    }
                    else if (!mfTieU)
                    {
                        if (e.key.code == sf::Keyboard::Right) idxMFTie = min(idxMFTie + 1, mfTCount - 1);
                        if (e.key.code == sf::Keyboard::Left)  idxMFTie = max(idxMFTie - 1, 0);
                        if (e.key.code == sf::Keyboard::S) { selMFTie = idxMFTie; mfTieU = true; }
                    }
                    else if (!mfShoesU)
                    {
                        if (e.key.code == sf::Keyboard::Right) idxMFShoes = min(idxMFShoes + 1, mfShCount - 1);
                        if (e.key.code == sf::Keyboard::Left)  idxMFShoes = max(idxMFShoes - 1, 0);
                        if (e.key.code == sf::Keyboard::S) { selMFShoes = idxMFShoes; mfShoesU = true; }
                    }
                }

                // saving outfits in gallery
                if (!showGallery && e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::F2)
                {
                    // Find the next available outfit number
                    int next = findNextAvailableOutfitNumber();

                    if (next != -1) // Found an available slot
                    {
                        std::string filename = "outfit_" + std::to_string(next) + ".png";

                        sf::Texture screenshot;
                        screenshot.create(window.getSize().x, window.getSize().y);
                        screenshot.update(window);

                        if (screenshot.copyToImage().saveToFile(filename))
                        {
                            std::cout << "Saved: " << filename << "\n";
                            // Don't increment outfitCount here - it will be updated when gallery is loaded
                        }
                        else
                        {
                            std::cout << "Error saving outfit.\n";
                        }
                    }
                    else
                    {
                        std::cout << "Maximum outfits (" << MAX_OUTFITS << ") reached.\n";
                    }
                }
            }
        }
        // Render
        window.clear(sf::Color::White);
        window.draw(bgSprite);
        if (menuActive) {
            window.draw(menuu);
        }
        else if (showGallery)
        {
            window.draw(gallerySprites[currentGalleryIndex]);
        }
        else if (womenActive) {
            if (selS == -1) window.draw(s1[j].getsprite());
            else if (selP == -1) window.draw(p1[k].getsprite());
            else if (selsh == -1) window.draw(sh[l].getsprite());
            else if (sele == -1) window.draw(ear[m].getsprite());
            else if (seln == -1) window.draw(b[n].getsprite());
            else if (displayoutfit) {
                s1[selS].getsprite().setScale(0.70f, 0.70f);
                s1[selS].getsprite().setPosition(120, -5);

                p1[selP].getsprite().setPosition(420, 100);

                b[seln].getsprite().setScale(0.5f, 0.5f);
                b[seln].getsprite().setPosition(20, 150);

                ear[sele].getsprite().setScale(0.4f, 0.4f);
                ear[sele].getsprite().setPosition(460, -120);

                sh[selsh].getsprite().setScale(0.7f, 0.7f);
                sh[selsh].getsprite().setPosition(150, 600);

                window.draw(s1[selS].getsprite());
                window.draw(p1[selP].getsprite());
                window.draw(sh[selsh].getsprite());
                window.draw(ear[sele].getsprite());
                window.draw(b[seln].getsprite());
            }
        }
        else if (menActive) {
            if (!shirtDone) window.draw(menShirts[idxShirt].getsprite());
            else if (!pantDone) window.draw(menPants[idxPant].getsprite());
            else if (!shoeDone) window.draw(menShoes[idxShoe].getsprite());
            else if (selWatch == -1) window.draw(menWatch[idxWatch].getsprite());
            else {
                menShirts[selShirt].getsprite().setPosition(20, -5);
                menPants[selPant].getsprite().setScale(0.7f, 0.7f);
                menPants[selPant].getsprite().setPosition(440, 150);
                menShoes[selShoe].getsprite().setScale(0.7f, 0.7f);
                menShoes[selShoe].getsprite().setPosition(90, 600);
                menWatch[selWatch].getsprite().setPosition(330, 620);
                menWatch[selWatch].getsprite().setScale(0.5f, 0.5f);
                window.draw(menShirts[selShirt].getsprite());
                window.draw(menPants[selPant].getsprite());
                window.draw(menShoes[selShoe].getsprite());
                window.draw(menWatch[selWatch].getsprite());
            }
        }
        else if (formalWomenActive)
        {
            if (selO == -1) window.draw(f1[idxO].getsprite());
            else if (selShoes == -1) window.draw(shf[idxShOES].getsprite());
            else if (selearrings == -1) window.draw(ef[idxE].getsprite());
            else if (selBags == -1) window.draw(bagf[idxB].getsprite());
            else
            {
               
                f1[selO].getsprite().setScale(0.9f, 0.9f);
                f1[selO].getsprite().setPosition(120, -10);
                
                bagf[selBags].getsprite().setScale(0.4f, 0.4f);
                bagf[selBags].getsprite().setPosition(620, 400);
               
                ef[selearrings].getsprite().setScale(0.6f, 0.6f);
                ef[selearrings].getsprite().setPosition(590, 40);
           
                shf[selShoes].getsprite().setScale(0.5f, 0.5f);
                shf[selShoes].getsprite().setPosition(5, 200);
                window.draw(f1[selO].getsprite());
                window.draw(shf[selShoes].getsprite());
                window.draw(ef[selearrings].getsprite());
                window.draw(bagf[selBags].getsprite());
            }
        }
        else if (formalMenActive)
        {
            if (selMFShirt == -1) window.draw(mf_shirt[idxMFShirt].getsprite());
            else if (selMFPant == -1) window.draw(mf_pant[idxMFPant].getsprite());
            else if (selMFBlazer == -1) window.draw(mf_blazer[idxMFBlazer].getsprite());
            else if (selMFTie == -1) window.draw(mf_tie[idxMFTie].getsprite());
            else if (selMFShoes == -1) window.draw(mf_shoes[idxMFShoes].getsprite());
            else
            {
                mf_shirt[selMFShirt].getsprite().setScale(0.6f, 0.6f);
                mf_shirt[selMFShirt].getsprite().setPosition(370, 20);
                mf_pant[selMFPant].getsprite().setScale(0.6f, 0.6f);
                mf_pant[selMFPant].getsprite().setPosition(550, 300);
                mf_blazer[selMFBlazer].getsprite().setScale(1.0f, 1.0f);
                mf_blazer[selMFBlazer].getsprite().setPosition(-50, -50);
                mf_tie[selMFTie].getsprite().setScale(0.3f, 0.3f);
                mf_tie[selMFTie].getsprite().setPosition(300, 570);
                mf_shoes[selMFShoes].getsprite().setScale(0.5f, 0.5f);
                mf_shoes[selMFShoes].getsprite().setPosition(30, 450);
                window.draw(mf_shirt[selMFShirt].getsprite());
                window.draw(mf_pant[selMFPant].getsprite());
                window.draw(mf_blazer[selMFBlazer].getsprite());
                window.draw(mf_tie[selMFTie].getsprite());
                window.draw(mf_shoes[selMFShoes].getsprite());
            }
        }
        window.display();
    }
    return 0;
}