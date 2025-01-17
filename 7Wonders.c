#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



#define CARD_DECK 49
#define WONDERS 7
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

struct cost{
    int coins;
    int wood;
    int stone;
    int clay;
    int ore;
    int glass;
    int papyrus;
    int cloth;
};

struct benefic{
    int coins;//1
    int wood;//2
    int stone;//3
    int clay;//4
    int ore;//5
    int glass;//6
    int papyrus;//7
    int cloth;//8
    int shield;//9
    int neighbourLeft;//10
    int neighbourRight;//11
    int victoryPoints;//12
    int mechanicalWheel;//13
    int math;//14
    int literature;//15
};

struct benefical{
    int coins;//1
    int wood;//2
    int stone;//3
    int clay;//4
    int ore;//5
    int glass;//6
    int papyrus;//7
    int cloth;//8
    int shield;//9
    int victoryPoints;//12
    int mechanicalWheel;//13
    int math;//14
    int literature;//15
};


struct wonder{
    char name[101];
    struct cost CStages[3];
    struct benefical BStages[3];
    struct benefical startingItem;
    unsigned int used;
};

struct card{
    char name[50];
    unsigned int type; //0-brown, 1-blue, 2-yellow,  3-Red, 4- Green, 5- Gray
    struct cost cardCost;
    struct benefic getRich; // you will have those things
    unsigned int used;
};

struct items{
     int wood;
     int stone;
     int clay;
     int ore;
     int glass;
     int papyrus;
     int cloth;
     int math;
     int mechanicalWheel;
     int literature;
};

typedef struct items Items;

struct profil{
    char nickname[101];
    unsigned int points;
    unsigned int noOfShields;
    unsigned int coins;
    struct wonder myWonder;
    struct card myDeck[7];
    unsigned int before;
    unsigned int after;
    unsigned int noOfCards;
    struct card brown[7];
    unsigned int brown1;
    struct card blue[7];
    unsigned int blue1;
    struct card yellow[7];
    unsigned int yellow1;
    struct card red[7];
    unsigned int red1;
    struct card green[7];
    unsigned int green1;
    struct card gray[7];
    unsigned int gray1;
    Items myTools; //stock of items;
    unsigned int keepTrackOfStage;
};

typedef struct profil Profil;

void readWonderFromDataBase(struct wonder wonders[], char* inputDataBase){
    FILE* file;
    file=fopen(inputDataBase,"r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char buffer[200];
    unsigned int i=0;
    while(fgets(buffer, 200, file)!=NULL){
    #ifdef DEBUG
        printf("%s\n", buffer);
    #endif
        unsigned int j=0;
        char *p=strtok(buffer, ",");
        while(p){
            switch(j){
            case 0:{strcpy(wonders[i].name, p); break;};
            case 1:{wonders[i].startingItem.coins=atoi(p); break;};
            case 2:{wonders[i].startingItem.wood=atoi(p); break;};
            case 3:{wonders[i].startingItem.stone=atoi(p); break;};
            case 4:{wonders[i].startingItem.clay=atoi(p); break;};
            case 5:{wonders[i].startingItem.ore=atoi(p); break;};
            case 6:{wonders[i].startingItem.glass=atoi(p); break;};
            case 7:{wonders[i].startingItem.papyrus=atoi(p); break;};
            case 8:{wonders[i].startingItem.cloth=atoi(p); break;};
            case 9:{wonders[i].startingItem.shield=atoi(p); break;};
            case 10:{wonders[i].startingItem.literature=atoi(p);break;};
            case 11:{wonders[i].startingItem.math=atoi(p);break;};
            case 12:{wonders[i].startingItem.victoryPoints=atoi(p);break;};
            case 13:{wonders[i].CStages[0].coins=atoi(p); break;};
            case 14:{wonders[i].CStages[0].wood=atoi(p); break;};
            case 15:{wonders[i].CStages[0].stone=atoi(p); break;};
            case 16:{wonders[i].CStages[0].clay=atoi(p); break;};
            case 17:{wonders[i].CStages[0].ore=atoi(p); break;};
            case 18:{wonders[i].CStages[0].glass=atoi(p); break;};
            case 19:{wonders[i].CStages[0].papyrus=atoi(p); break;};
            case 20:{wonders[i].CStages[0].cloth=atoi(p); break;};
            case 21:{wonders[i].BStages[0].coins=atoi(p); break;};
            case 22:{wonders[i].BStages[0].wood=atoi(p); break;};
            case 23:{wonders[i].BStages[0].stone=atoi(p); break;};
            case 24:{wonders[i].BStages[0].clay=atoi(p); break;};
            case 25:{wonders[i].BStages[0].ore=atoi(p); break;};
            case 26:{wonders[i].BStages[0].glass=atoi(p); break;};
            case 27:{wonders[i].BStages[0].papyrus=atoi(p); break;};
            case 28:{wonders[i].BStages[0].cloth=atoi(p); break;};
            case 29:{wonders[i].BStages[0].shield=atoi(p); break;};
            case 30:{wonders[i].BStages[0].literature=atoi(p); break;};
            case 31:{wonders[i].BStages[0].math=atoi(p); break;};
            case 32:{wonders[i].BStages[0].victoryPoints=atoi(p); break;};
            case 33:{wonders[i].CStages[1].coins=atoi(p); break;};
            case 34:{wonders[i].CStages[1].wood=atoi(p); break;};
            case 35:{wonders[i].CStages[1].stone=atoi(p); break;};
            case 36:{wonders[i].CStages[1].clay=atoi(p); break;};
            case 37:{wonders[i].CStages[1].ore=atoi(p); break;};
            case 38:{wonders[i].CStages[1].glass=atoi(p); break;;};
            case 39:{wonders[i].CStages[1].papyrus=atoi(p); break;;};
            case 40:{wonders[i].CStages[1].cloth=atoi(p); break;};
            case 41:{wonders[i].BStages[1].coins=atoi(p); break;};
            case 42:{wonders[i].BStages[1].wood=atoi(p); break;};
            case 43:{wonders[i].BStages[1].stone=atoi(p); break;};
            case 44:{wonders[i].BStages[1].clay=atoi(p); break;};
            case 45:{wonders[i].BStages[1].ore=atoi(p); break;};
            case 46:{wonders[i].BStages[1].glass=atoi(p); break;};
            case 47:{wonders[i].BStages[1].papyrus=atoi(p); break;};
            case 48:{wonders[i].BStages[1].cloth=atoi(p); break;};
            case 49:{wonders[i].BStages[1].shield=atoi(p); break;};
            case 50:{wonders[i].BStages[1].literature=atoi(p); break;};
            case 51:{wonders[i].BStages[1].math=atoi(p); break;};
            case 52:{wonders[i].BStages[1].victoryPoints=atoi(p); break;};
            case 53:{wonders[i].BStages[1].mechanicalWheel=atoi(p); break;};
            case 54:{wonders[i].BStages[1].math=atoi(p); break;};
            case 55:{wonders[i].BStages[1].literature=atoi(p); break;};
            case 56:{wonders[i].CStages[2].coins=atoi(p); break;};
            case 57:{wonders[i].CStages[2].wood=atoi(p); break;};
            case 58:{wonders[i].CStages[2].stone=atoi(p); break;};
            case 59:{wonders[i].CStages[2].clay=atoi(p); break;};
            case 60:{wonders[i].CStages[2].ore=atoi(p); break;};
            case 61:{wonders[i].CStages[2].glass=atoi(p); break;};
            case 62:{wonders[i].CStages[2].papyrus=atoi(p); break;};
            case 63:{wonders[i].CStages[2].cloth=atoi(p); break;};
            case 64:{wonders[i].BStages[2].coins=atoi(p); break;};
            case 65:{wonders[i].BStages[2].wood=atoi(p); break;};
            case 66:{wonders[i].BStages[2].stone=atoi(p); break;};
            case 67:{wonders[i].BStages[2].clay=atoi(p); break;};
            case 68:{wonders[i].BStages[2].ore=atoi(p); break;};
            case 69:{wonders[i].BStages[2].glass=atoi(p); break;};
            case 70:{wonders[i].BStages[2].papyrus=atoi(p); break;};
            case 71:{wonders[i].BStages[2].cloth=atoi(p); break;};
            case 72:{wonders[i].BStages[2].shield=atoi(p); break;};
            case 73:{wonders[i].BStages[2].literature=atoi(p); break;};
            case 74:{wonders[i].BStages[2].math=atoi(p); break;};
            case 75:{wonders[i].BStages[2].victoryPoints=atoi(p); break;};
            case 76:{wonders[i].used=atoi(p); break;};
            default:{break;};
            }
            j++;
            p=strtok(NULL, ",");
        }
        i++;
    }
    fclose(file);
}

void printWonders(struct wonder wonders[]){
    for(unsigned int i=0; i<WONDERS; i++){
        printf("Wonders name: %s\n", wonders[i].name);
        printf("The benefit of the wonder:\nCOINS:%d;\nWOOD:%d;\nSTONE:%d;\nCLAY:%d;\nORE:%d;\nGLASS:%d;\nPAPYRUS:%d;\nCLOTH:%d;\nSHIELD:%d;\nVICTORY POINTS:%d; It is used: %d\n",
                wonders[i].startingItem.coins, wonders[i].startingItem.wood, wonders[i].startingItem.stone, wonders[i].startingItem.clay, wonders[i].startingItem.ore, wonders[i].startingItem.glass, wonders[i].startingItem.papyrus,
                wonders[i].startingItem.cloth, wonders[i].startingItem.shield, wonders[i].startingItem.victoryPoints, wonders[i].used);
        printf("\n");
        for(unsigned int j=0; j<3; j++){
             printf("What you need to have the %d's stage:\nCOINS:%d;\nWOOD:%d;\nSTONE:%d;\nCLAY:%d;\nORE:%d;\nGLASS:%d;\nPAPYRUS:%d;\nCLOTH:%d;\n",j+1,wonders[i].CStages[j].coins, wonders[i].CStages[j].wood, wonders[i].CStages[j].stone,
                    wonders[i].CStages[j].clay, wonders[i].CStages[j].ore, wonders[i].CStages[j].glass, wonders[i].CStages[j].papyrus, wonders[i].CStages[j].cloth);
             printf("The benefit of the stage:\nCOINS:%d;\nWOOD:%d;\nSTONE:%d;\nCLAY:%d;\nORE:%d;\nGLASS:%d;\nPAPYRUS:%d;\nCLOTH:%d;\nSHIELD:%d;\nVICTORY POINTS:%d;\n",
                wonders[i].BStages[j].coins, wonders[i].BStages[j].wood, wonders[i].BStages[j].stone, wonders[i].BStages[j].clay, wonders[i].BStages[j].ore, wonders[i].BStages[j].glass, wonders[i].BStages[j].papyrus,
                wonders[i].BStages[j].cloth, wonders[i].BStages[j].shield, wonders[i].BStages[j].victoryPoints);
        }
        printf("\n");
    }
}

void printWonder(struct wonder wonders){

        printf("Wonders name: %s\n", wonders.name);

        printf("The benefit of the wonder:\n");
        if(wonders.startingItem.coins!=0)
            printf("COINS:%d;\n", wonders.startingItem.coins);
        if(wonders.startingItem.wood!=0)
            printf("WOOD:%d;\n", wonders.startingItem.wood);
        if(wonders.startingItem.stone!=0)
            printf("STONE:%d;\n", wonders.startingItem.stone);
        if(wonders.startingItem.clay!=0)
            printf("CLAY:%d;\n", wonders.startingItem.clay);
        if(wonders.startingItem.ore!=0)
            printf("ORE:%d;\n", wonders.startingItem.ore);
        if(wonders.startingItem.glass!=0)
            printf("GLASS:%d;\n", wonders.startingItem.glass);
        if(wonders.startingItem.papyrus!=0)
            printf("PAPYRUS:%d;\n", wonders.startingItem.papyrus);
        if(wonders.startingItem.cloth!=0)
            printf("CLOTH:%d;\n", wonders.startingItem.cloth);
        if(wonders.startingItem.shield!=0)
            printf("SHEIELD:%d;\n", wonders.startingItem.shield);
        if(wonders.startingItem.victoryPoints!=0)
            printf("VICTORY POINTS:%d\n", wonders.startingItem.victoryPoints);
        printf("It's used: %d\n\n", wonders.used);

        for(unsigned int j=0; j<3; j++){
             printf("What you need to have the %d's stage:\n", j+1);
             if(wonders.CStages[j].coins!=0)
                printf("COINS:%d;\n", wonders.CStages[j].coins);
             if(wonders.CStages[j].wood!=0)
                printf("WOOD:%d;\n", wonders.CStages[j].wood);
             if(wonders.CStages[j].stone!=0)
                printf("STONE:%d;\n", wonders.CStages[j].stone);
             if(wonders.CStages[j].clay!=0)
                printf("CLAY:%d;\n", wonders.CStages[j].clay);
             if(wonders.CStages[j].ore!=0)
                printf("ORE:%d;\n", wonders.CStages[j].ore);
             if(wonders.CStages[j].glass!=0)
                printf("GLASS:%d;\n", wonders.CStages[j].glass);
             if(wonders.CStages[j].papyrus!=0)
                printf("PAPYRUS:%d;\n", wonders.CStages[j].papyrus);
             if(wonders.CStages[j].cloth!=0)
                printf("CLOTH:%d;\n", wonders.CStages[j].cloth);

             printf("The benefit of the stage:\n");
             if(wonders.BStages[j].coins!=0)
                printf("COINS:%d;\n", wonders.BStages[j].coins);
             if(wonders.BStages[j].wood!=0)
                printf("WOOD:%d;\n", wonders.BStages[j].wood);
             if(wonders.BStages[j].stone!=0)
                printf("STONE:%d;\n", wonders.BStages[j].stone);
             if(wonders.BStages[j].clay!=0)
                printf("CLAY:%d;\n", wonders.BStages[j].clay);
             if(wonders.BStages[j].ore!=0)
                printf("ORE:%d;\n", wonders.BStages[j].ore);
             if(wonders.BStages[j].glass!=0)
                printf("GLASS:%d;\n", wonders.BStages[j].glass);
             if(wonders.BStages[j].papyrus!=0)
                printf("PAPYRUS:%d;\n", wonders.BStages[j].papyrus);
             if(wonders.BStages[j].cloth!=0)
                printf("CLOTH:%d;\n", wonders.BStages[j].cloth);
             if(wonders.BStages[j].shield!=0)
                printf("SHIELD:%d;\n", wonders.BStages[j].shield);
             if(wonders.BStages[j].victoryPoints!=0)
                printf("VICTORY POINTS:%d;\n", wonders.BStages[j].victoryPoints);
             printf("\n");
        }
        printf("\n");

}


void readCardFromDataBase(struct card cardDeck[], char* inputDataBase){
    FILE *dataBase;
    char buffer[150];
    dataBase=fopen(inputDataBase, "r");
    if (dataBase == NULL) {
        printf("Error opening file!\n");
        return;
    }
    unsigned int i=0;
    while(fgets(buffer, 150, dataBase)!=NULL){
        #ifdef DEBUG
            printf("%s\n", buffer);
        #endif
        unsigned int j=0;
        char *p=strtok(buffer, ",");
        while(p){
           switch(j){
                case 0:{strcpy(cardDeck[i].name, p); break;};
                case 1:{cardDeck[i].cardCost.coins=atoi(p); break;};
                case 2:{cardDeck[i].cardCost.wood=atoi(p); break;};
                case 3:{cardDeck[i].cardCost.stone=atoi(p); break;};
                case 4:{cardDeck[i].cardCost.clay=atoi(p); break;};
                case 5:{cardDeck[i].cardCost.ore=atoi(p); break;};
                case 6:{cardDeck[i].cardCost.glass=atoi(p); break;};
                case 7:{cardDeck[i].cardCost.papyrus=atoi(p); break;};
                case 8:{cardDeck[i].cardCost.cloth=atoi(p); break;};
                case 9:{cardDeck[i].used=atoi(p); break;};
                case 10:{cardDeck[i].getRich.coins=atoi(p); break;};
                case 11:{cardDeck[i].getRich.wood=atoi(p); break;};
                case 12:{cardDeck[i].getRich.stone=atoi(p); break;};
                case 13:{cardDeck[i].getRich.clay=atoi(p); break;};
                case 14:{cardDeck[i].getRich.ore=atoi(p); break;};
                case 15:{cardDeck[i].getRich.glass=atoi(p); break;};
                case 16:{cardDeck[i].getRich.papyrus=atoi(p); break;};
                case 17:{cardDeck[i].getRich.cloth=atoi(p); break;};
                case 18:{cardDeck[i].getRich.shield=atoi(p); break;};
                case 19:{cardDeck[i].getRich.neighbourLeft=atoi(p); break;};
                case 20:{cardDeck[i].getRich.neighbourRight=atoi(p); break;};
                case 21:{cardDeck[i].getRich.victoryPoints=atoi(p); break;};
                case 22:{cardDeck[i].getRich.mechanicalWheel=atoi(p); break;};
                case 23:{cardDeck[i].getRich.math=atoi(p); break;};
                case 24:{cardDeck[i].getRich.literature=atoi(p); break;};
                case 25:{cardDeck[i].type=atoi(p); break;};
                default:{break;};
           }
           j++;
           p=strtok(NULL, ",");
        }
        i++;
    }
    fclose(dataBase);
}


void printCardDeck(struct card cardDeck[]){
    for(unsigned i=0; i<CARD_DECK; i++){
        printf("Card's name: %s\n", cardDeck[i].name);
        printf("What you need to have the card:\nCOINS:%d;\nWOOD:%d;\nSTONE:%d;\nCLAY:%d;\nORE:%d;\nGLASS:%d;\nPAPYRUS:%d;\nCLOTH:%d;\n",
               cardDeck[i].cardCost.coins, cardDeck[i].cardCost.wood, cardDeck[i].cardCost.stone, cardDeck[i].cardCost.clay, cardDeck[i].cardCost.ore,
               cardDeck[i].cardCost.glass, cardDeck[i].cardCost.papyrus, cardDeck[i].cardCost.cloth);
        printf("The card is current in deck:%d;\n",cardDeck[i].used);
        printf("The benefit:\nCOINS:%d;\nWOOD:%d;\nSTONE:%d;\nCLAY:%d;\nORE:%d;\nGLASS:%d;\nPAPYRUS:%d;\nCLOTH:%d;\nSHIELD:%d;\nVICTORY POINTS:%d;\n",cardDeck[i].getRich.coins, cardDeck[i].getRich.wood, cardDeck[i].getRich.stone, cardDeck[i].getRich.clay, cardDeck[i].getRich.ore, cardDeck[i].getRich.glass,
               cardDeck[i].getRich.papyrus, cardDeck[i].getRich.cloth, cardDeck[i].getRich.shield, cardDeck[i].getRich.victoryPoints);
        switch(cardDeck[i].type){
            case 0: {printf("COLOR:Brown;\n"); break;};
            case 1: {printf("COLOR:Blue;\n"); break;};
            case 2: {printf("COLOR:Yellow;\n"); break;};
            case 3: {printf("COLOR:Red;\n"); break;};
            case 4: {printf("SPECIAL ITEMS:\nMECHANICAL WHEEL:%d;\nMATH:%d;\nLITERATURE:%d\nCOLOR:Green;\n",cardDeck[i].getRich.mechanicalWheel, cardDeck[i].getRich.math, cardDeck[i].getRich.literature); break;};
            case 5: {printf("COLOR:Gray;\n"); break;};
            default: {break;};
        }
        printf("\n");
    }
}

void printCard(struct card cardDeck){
        printf("Card's name: %s\n", cardDeck.name);
        printf("What you need to have the card:\n");

        if(cardDeck.cardCost.coins!=0)
            printf("COINS:%d\n", cardDeck.cardCost.coins);
        if(cardDeck.cardCost.wood!=0)
            printf("WOOD:%d\n", cardDeck.cardCost.wood);
        if(cardDeck.cardCost.stone!=0)
            printf("STONE:%d\n", cardDeck.cardCost.stone);
        if(cardDeck.cardCost.clay!=0)
            printf("CLAY:%d\n", cardDeck.cardCost.clay);
        if(cardDeck.cardCost.ore!=0)
            printf("ORE:%d\n", cardDeck.cardCost.ore);
        if(cardDeck.cardCost.glass!=0)
            printf("GLASS:%d\n", cardDeck.cardCost.glass);
        if(cardDeck.cardCost.papyrus!=0)
            printf("PAPYRUS:%d\n", cardDeck.cardCost.papyrus);
        if(cardDeck.cardCost.cloth!=0)
            printf("CLOTH:%d\n", cardDeck.cardCost.cloth);

        printf("The card is current in deck:%d;\n",cardDeck.used);

        if(cardDeck.getRich.coins!=0)
            printf("COINS:%d\n", cardDeck.getRich.coins);
        if(cardDeck.getRich.wood!=0)
            printf("WOOD:%d\n", cardDeck.getRich.wood);
        if(cardDeck.getRich.stone!=0)
            printf("STONE:%d\n", cardDeck.getRich.stone);
        if(cardDeck.getRich.clay!=0)
            printf("CLAY:%d\n", cardDeck.getRich.clay);
        if(cardDeck.getRich.ore!=0)
            printf("ORE:%d\n", cardDeck.getRich.ore);
        if(cardDeck.getRich.glass!=0)
            printf("GLASS:%d\n", cardDeck.getRich.glass);
        if(cardDeck.getRich.papyrus!=0)
            printf("PAPYRUS:%d\n", cardDeck.getRich.papyrus);
        if(cardDeck.getRich.cloth!=0)
            printf("CLOTH:%d\n", cardDeck.getRich.cloth);
        if(cardDeck.getRich.shield!=0)
            printf("SHIELD:%d\n", cardDeck.getRich.shield);
        if(cardDeck.getRich.victoryPoints!=0)
            printf("VICTORY POINTS:%d\n", cardDeck.getRich.victoryPoints);

        switch(cardDeck.type){
            case 0: {printf("COLOR:Brown;\n"); break;};
            case 1: {printf("COLOR:Blue;\n"); break;};
            case 2: {printf("COLOR:Yellow;\n"); break;};
            case 3: {printf("COLOR:Red;\n"); break;};
            case 4: {
                printf("SPECIAL ITEMS:\n");
                if(cardDeck.getRich.mechanicalWheel!=0)
                    printf("\tMECHANICAL WHEEL:%d\n", cardDeck.getRich.mechanicalWheel);
                if(cardDeck.getRich.math!=0)
                    printf("\tMATH:%d\n", cardDeck.getRich.math);
                if(cardDeck.getRich.literature!=0)
                    printf("\tLITERATURE:%d\n", cardDeck.getRich.literature);
                printf("COLOR: Green;\n");
                break;
                }
            case 5: {printf("COLOR:Gray;\n"); break;};
            default: {break;};
        }
        printf("\n");
}

void swapCards(struct card *card1, struct card *card2) {
    struct card aux = *card1;
    *card1 = *card2;
    *card2 = aux;
}

void shuffleCards(struct card cardDeck[]){
    srand(time(NULL));
    for (int i = CARD_DECK - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapCards(&cardDeck[i], &cardDeck[j]);
    }
}

//starting player info

void gamePlayers(Profil players[], unsigned int noOfPlayers, struct wonder wonders[], struct card cardDeck[]){
    players[noOfPlayers+1];
    int choice;
    if(noOfPlayers!=0)
        printf("Write down your names (press Enter if you want to save that name!):\n");
    for(unsigned i=0; i<noOfPlayers; i++){
        scanf("%100s", players[i].nickname);
        players[i].coins=3;
        players[i].noOfCards=7;
        players[i].blue1=0;
        players[i].brown1=0;
        players[i].green1=0;
        players[i].red1=0;
        players[i].yellow1=0;
        players[i].gray1=0;

    }
    #ifdef DEBUG
    for(unsigned i=0; i<noOfPlayers; i++){
        printf("%s Coins:%d\n", players[i].nickname, players[i].coins);
    }
    #endif
    /*This defines the neighbours of each player.*/
    players[0].before=noOfPlayers-1;
    players[0].after=1;
    players[noOfPlayers-1].after=0;
    players[noOfPlayers-1].before=noOfPlayers-2;
    for(unsigned i=1; i<noOfPlayers-1; i++){
        players[i].before=i-1;
        players[i].after=i+1;
    }
    #ifdef DEBUG
    for(unsigned i=0; i<noOfPlayers; i++){
        printf("Before:%s %s After:%s\n", players[players[i].before].nickname, players[i].nickname, players[players[i].after].nickname);
    }
    #endif
    unsigned noWonders=WONDERS;
    for(unsigned i=0; i<noOfPlayers; i++){
        for(unsigned j=0; j<noWonders; j++){
            if(wonders[j].used==0){
                printf("#%d\n\n", j);
                printWonder(wonders[j]);
                }
            }
            printf("Player: %s, ", players[i].nickname);
            printf("choose a number between one wonder: 0-%d:\n", noWonders);
            scanf("%d", &choice);
            //pull off the wonders from the amount of all wonders!
            for(unsigned j=0; j<noWonders; j++)
                if(choice==j && wonders[j].used==0){
                      players[i].myWonder=wonders[j];
                      wonders[j].used=1;
                      for(unsigned e=j; e<noWonders; e++)
                            wonders[e]=wonders[e+1];
                    noWonders--;
            }

        printf("Your choice:\n");
        printWonder(players[i].myWonder);
    }
    unsigned int e=0;
    for(unsigned i=0; i<noOfPlayers; i++){
        for(unsigned j=e; j<(e+1)*7; j++){
            players[i].myDeck[j%7]=cardDeck[j];
        }
        e++;
    }

    #ifdef DEBUG
     for(unsigned i=0; i<noOfPlayers; i++){
            printf("%s\n", players[i].nickname);
            for(unsigned j=0; j<players[i].noOfCards; j++)
                printCard(players[i].myDeck[j]);
     }
     #endif

     // get the starting items from the players'wonder to their item stock;
     for(unsigned int i=0; i<noOfPlayers; i++){
        players[i].myTools.wood=players[i].myWonder.startingItem.wood;
        players[i].myTools.stone=players[i].myWonder.startingItem.stone;
        players[i].myTools.clay=players[i].myWonder.startingItem.clay;
        players[i].myTools.ore=players[i].myWonder.startingItem.ore;
        players[i].myTools.glass=players[i].myWonder.startingItem.glass;
        players[i].myTools.papyrus=players[i].myWonder.startingItem.papyrus;
        players[i].myTools.cloth=players[i].myWonder.startingItem.cloth;
        players[i].myTools.clay=players[i].myWonder.startingItem.clay;
     }

     // declare the tracking of stages of a player;

     for(unsigned int i=0; i<noOfPlayers; i++)
        players[i].keepTrackOfStage=0;

}

void switchDecks(Profil players[], unsigned int noOfPlayers){
    for(unsigned i=0; i<noOfPlayers; i++){
        for(unsigned j=0; j<players[i].noOfCards; j++)
            if(players[i].myDeck[j].used==0||players[i].myDeck[j].used==2)
                for(unsigned e=j; e<players[i].noOfCards-1; e++)
                    players[i].myDeck[e]=players[i].myDeck[e+1];
        players[i].noOfCards--;
    }
    /*for(unsigned i=0; i<noOfPlayers; i++){
        for(unsigned j=0; j<players[i].noOfCards; j++){
            printf("#%d\n\n", j);
            printCard(players[i].myDeck[j]);
        }
    }*/
    Profil aux=players[noOfPlayers-1];
    for(unsigned i=noOfPlayers-1; i>=1; i--){
        for(unsigned j=0; j<players[i].noOfCards; j++)
            players[i].myDeck[j]=players[i-1].myDeck[j];
    }
    for(unsigned i=0; i<players[0].noOfCards; i++)
        players[0].myDeck[i]=aux.myDeck[i];
}

//arrange players cards instantly in color decks for an easy following
void arrangePlayersCards(Profil *player, struct card Card){
        switch(Card.type){
            case 0:{
                player->brown[player->brown1]=Card;
                player->brown1++;
                break;
            };
            case 1:{
                player->blue[player->blue1]=Card;
                player->blue1++;
                break;
            };
            case 2:{
                player->yellow[player->yellow1]=Card;
                player->yellow1++;
                break;
            };
            case 3:{
                player->red[player->red1]=Card;
                player->red1++;
                break;
            };
            case 4:{
                player->green[player->green1]=Card;
                player->green1++;
                break;
            };
            case 5:{
                player->gray[player->gray1]=Card;
                player->gray1++;
                break;
            };
            default:{
                break;
            };

        }
}

// each operation that's done by player will be preceded by a player information.
void playerInfo(Profil *player){
    printf("Nickname: %s\n", player->nickname);
    printf("COINS: %d\n", player->coins);
    printf("SHIELDS: %d\n", player->noOfShields);
    printf("POINTS: %d\n", player->points);
    printWonder(player->myWonder);

    /*Resources*/

    printf("%s's resources:\n", player->nickname);
    if(player->myTools.wood!=0)
        printf("WOOD: %d; \n", player->myTools.wood);
    if(player->myTools.stone!=0)
        printf("STONE: %d; \n", player->myTools.stone);
    if(player->myTools.clay!=0)
        printf("CLAY: %d; \n", player->myTools.clay);
    if(player->myTools.ore!=0)
        printf("ORE: %d; \n", player->myTools.ore);
    if(player->myTools.glass!=0)
        printf("GLASS: %d; \n", player->myTools.glass);
    if(player->myTools.papyrus!=0)
        printf("PAPYRUS: %d; \n", player->myTools.papyrus);
    if(player->myTools.cloth!=0)
        printf("CLOTH: %d; \n", player->myTools.cloth);
    if(player->myTools.mechanicalWheel!=0)
        printf("MECHANICAL WHEEL: %d; \n", player->myTools.mechanicalWheel);
    if(player->myTools.math!=0)
        printf("MATH: %d; \n", player->myTools.math);
    if(player->myTools.literature!=0)
        printf("LITERATURE: %d; \n", player->myTools.literature);
    printf("\n");

    /*Cards*/

    printf("%s's cards:\n", player->nickname);

    if(player->brown1!=0){
        printf("\n");
        printf(MAG);
        for(unsigned int i=0; i<player->brown1; i++)
            printCard(player->brown[i]);
        printf(RESET);
    }
    else{
        printf(MAG);
        printf("Brown: 0 cards!\n");
        printf(RESET);
    }

    if(player->blue1!=0){
        printf(BLU);
        printf("\n");
        for(unsigned int i=0; i<player->blue1; i++)
            printCard(player->blue[i]);
        printf(RESET);
    }
    else{
        printf(BLU);
        printf("Blue: 0 cards!\n");
        printf(RESET);
    }

    if(player->yellow1!=0){
        printf(YEL);
        printf("\n");
        for(unsigned int i=0; i<player->yellow1; i++)
            printCard(player->yellow[i]);
        printf(RESET);
    }
    else{
        printf(YEL);
        printf("Yellow: 0 cards!\n");
        printf(RESET);
    }

    if(player->red1!=0){
        printf(RED);
        printf("\n");
        for(unsigned int i=0; i<player->red1; i++)
            printCard(player->red[i]);
        printf(RESET);
    }
    else{
        printf(RED);
        printf("Red: 0 cards!\n");
        printf(RESET);
    }

    if(player->green1!=0){
        printf(GRN);
        printf("\n");
        for(unsigned int i=0; i<player->green1; i++)
            printCard(player->green[i]);
        printf(RESET);
    }
    else{
        printf(GRN);
        printf("Green: 0 cards!\n");
        printf(RESET);
    }

    if(player->gray1!=0){
        printf(CYN);
        printf("\n");
        for(unsigned int i=0; i<player->gray1; i++)
            printCard(player->gray[i]);
        printf(RESET);
    }
    else{
        printf(CYN);
        printf("Gray: 0 cards!\n");
        printf(RESET);
    }

    printf("\n");
}

void oneRoundUpdate(Profil *player){
    // add items from Wonder;
    if(player->myWonder.startingItem.wood!=0)
        player->myTools.wood=player->myWonder.startingItem.wood+player->myTools.wood;
    if(player->myWonder.startingItem.stone!=0)
        player->myTools.stone=player->myWonder.startingItem.stone+player->myTools.stone;
    if(player->myWonder.startingItem.clay!=0)
        player->myTools.clay=player->myWonder.startingItem.clay+player->myTools.clay;
    if(player->myWonder.startingItem.ore!=0)
        player->myTools.ore=player->myWonder.startingItem.ore+player->myTools.ore;
    if(player->myWonder.startingItem.glass!=0)
        player->myTools.glass=player->myWonder.startingItem.glass+player->myTools.glass;
    if(player->myWonder.startingItem.papyrus!=0)
        player->myTools.papyrus=player->myWonder.startingItem.papyrus+player->myTools.papyrus;
    if(player->myWonder.startingItem.cloth!=0)
        player->myTools.cloth=player->myWonder.startingItem.cloth+player->myTools.cloth;
    if(player->myWonder.startingItem.coins!=0)
        player->coins=player->myWonder.startingItem.wood+player->coins;
    if(player->myWonder.startingItem.shield!=0)
        player->noOfShields=player->myWonder.startingItem.shield+player->noOfShields;
    if(player->myWonder.startingItem.victoryPoints!=0)
        player->points=player->myWonder.startingItem.victoryPoints+player->points;

    //add items via cards;
    if(player->brown1!=0){
        for(unsigned int i=0; i<player->brown1; i++){
            if(player->brown[i].getRich.wood!=0)
                player->myTools.wood=player->myTools.wood+player->brown[i].getRich.wood;
            if(player->brown[i].getRich.stone!=0)
                player->myTools.stone=player->myTools.stone+player->brown[i].getRich.stone;
            if(player->brown[i].getRich.clay!=0)
                player->myTools.clay=player->myTools.clay+player->brown[i].getRich.clay;
            if(player->brown[i].getRich.ore!=0)
                player->myTools.ore=player->myTools.ore+player->brown[i].getRich.ore;
        }
    }
    /*if(player->red1!=0){
        for(unsigned int i=0; i<player->red1; i++){
            if(player->red[i].getRich.shield!=0)
                player->noOfShields=player->noOfShields+player->red[i].getRich.shield;
        }
    }*/
    if(player->gray1!=0){
        for(unsigned int i=0; i<player->gray1; i++){
            if(player->gray[i].getRich.glass!=0)
                player->myTools.glass=player->gray[i].getRich.glass+player->myTools.glass;
            if(player->gray[i].getRich.papyrus!=0)
                player->myTools.papyrus=player->gray[i].getRich.papyrus+player->myTools.papyrus;
            if(player->gray[i].getRich.cloth!=0)
                player->myTools.cloth=player->gray[i].getRich.cloth+player->myTools.cloth;
        }
    }

    if(player->green1!=0){
        for(unsigned int i=0; i<player->green1; i++){
            if(player->green[i].getRich.mechanicalWheel!=0)
                player->myTools.mechanicalWheel=player->myTools.mechanicalWheel+player->green[i].getRich.mechanicalWheel;
            if(player->green[i].getRich.math!=0)
                player->myTools.math=player->myTools.math+player->green[i].getRich.math;
            if(player->green[i].getRich.literature!=0)
                player->myTools.literature=player->green[i].getRich.literature+player->myTools.literature;

        }
    }
}

void chooseACard(Profil *player, struct card* cardDeck){
    unsigned int choose=-1, choose1=-1;
    printCard(*cardDeck);
    if(cardDeck->used==1){
        while(choose<0 || choose>1){
            printf("Press 1 if you want the card, or 0 if you want to discard it and earn 3 coins\n");
            scanf("%d", &choose);

        }
        switch(choose){
            case 0: {
                player->coins=player->coins+3;
                cardDeck->used=2;
                printf("The n.o. of coins is now: %d\n", player->coins);
                break;
            }
            case 1:{
                if((player->coins>=cardDeck->cardCost.coins)&&(player->myTools.wood>=cardDeck->cardCost.wood)&&(player->myTools.stone>=cardDeck->cardCost.stone)&&(player->myTools.clay>=cardDeck->cardCost.clay)&&
                   (player->myTools.ore>=cardDeck->cardCost.ore)&&(player->myTools.glass>=cardDeck->cardCost.glass)&&(player->myTools.papyrus>=cardDeck->cardCost.papyrus)&&(player->myTools.cloth>=cardDeck->cardCost.cloth)){
                        cardDeck->used=0;
                        player->coins=player->coins-cardDeck->cardCost.coins;
                        player->myTools.wood=player->myTools.wood-cardDeck->cardCost.wood;
                        player->myTools.stone=player->myTools.stone-cardDeck->cardCost.stone;
                        player->myTools.clay=player->myTools.clay-cardDeck->cardCost.clay;
                        player->myTools.ore=player->myTools.ore-cardDeck->cardCost.ore;
                        player->myTools.glass=player->myTools.glass-cardDeck->cardCost.glass;
                        player->myTools.papyrus=player->myTools.papyrus-cardDeck->cardCost.papyrus;
                        player->myTools.clay=player->myTools.clay-cardDeck->cardCost.clay;

                        // Now, let's add the card's benefits into your Item myTools; :D

                        player->coins=player->coins+cardDeck->getRich.coins;
                        player->myTools.wood=player->myTools.wood+cardDeck->getRich.wood;
                        player->myTools.stone=player->myTools.stone+cardDeck->getRich.stone;
                        player->myTools.clay=player->myTools.clay+cardDeck->getRich.clay;
                        player->myTools.ore=player->myTools.ore+cardDeck->getRich.ore;
                        player->myTools.glass=player->myTools.glass+cardDeck->getRich.glass;
                        player->myTools.papyrus=player->myTools.papyrus+cardDeck->getRich.papyrus;
                        player->myTools.cloth=player->myTools.cloth+cardDeck->getRich.cloth;
                        player->noOfShields=player->noOfShields+cardDeck->getRich.shield;
                        if(cardDeck->type==4){
                            player->myTools.mechanicalWheel=player->myTools.mechanicalWheel+cardDeck->getRich.mechanicalWheel;
                            player->myTools.math=player->myTools.math+cardDeck->getRich.math;
                            player->myTools.literature=player->myTools.literature+cardDeck->getRich.literature;
                        }

                        printf("Congratulation! You gain the card!! ;)\n");
                        printf("Now you have to choose if you keep it in your card decks or build a your Wonder Stage! Press 0-to keep it and 1-to build the stage!\n");
                        while(choose1<0 || choose1>1)
                            scanf("%d", &choose1);

                        if(choose1==0)
                            arrangePlayersCards(player, *cardDeck);
                        else{
                            if((player->coins>=player->myWonder.CStages[player->keepTrackOfStage].coins) && (player->myTools.wood>=player->myWonder.CStages[player->keepTrackOfStage].wood)&&
                               (player->myTools.stone>=player->myWonder.CStages[player->keepTrackOfStage].stone) && (player->myTools.clay>=player->myWonder.CStages[player->keepTrackOfStage].clay) &&
                               (player->myTools.ore>=player->myWonder.CStages[player->keepTrackOfStage].ore) && (player->myTools.glass>=player->myWonder.CStages[player->keepTrackOfStage].glass) &&
                               (player->myTools.papyrus>=player->myWonder.CStages[player->keepTrackOfStage].papyrus) && (player->myTools.cloth>=player->myWonder.CStages[player->keepTrackOfStage].cloth)){


                                   player->coins=player->coins-player->myWonder.CStages[player->keepTrackOfStage].coins;
                                   player->myTools.wood=player->myTools.wood-player->myWonder.CStages[player->keepTrackOfStage].wood;
                                   player->myTools.stone=player->myTools.stone-player->myWonder.CStages[player->keepTrackOfStage].stone;
                                   player->myTools.clay=player->myTools.clay-player->myWonder.CStages[player->keepTrackOfStage].clay;
                                   player->myTools.ore=player->myTools.ore-player->myWonder.CStages[player->keepTrackOfStage].ore;
                                   player->myTools.glass=player->myTools.glass-player->myWonder.CStages[player->keepTrackOfStage].glass;
                                   player->myTools.papyrus=player->myTools.papyrus-player->myWonder.CStages[player->keepTrackOfStage].papyrus;
                                   player->myTools.cloth=player->myTools.cloth-player->myWonder.CStages[player->keepTrackOfStage].cloth;

                                   if(player->keepTrackOfStage>=2)
                                        player->keepTrackOfStage=2;
                                   else
                                        player->keepTrackOfStage=player->keepTrackOfStage+1;

                               }
                            else{
                                printf("Next round sry!! :(\n");
                                arrangePlayersCards(player, *cardDeck);
                            }

                        }
                }
                //IF YOU MAKE THE MISTAKE TO BUY THE CARDS WITHOUT HAVING RESOURCES, IT WILL GO IN CASE 0: SELLING CARD IN ORDER TO EARN COINS!!!
                else{
                    printf("Unfortunately you don't have enough resources in order to buy the card, instead you will earn 3 coins :)\n");
                    player->coins=player->coins+3;
                    cardDeck->used=2;
                }
                printf("The n.o. of coins is now: %d\n", player->coins);


                break;}

            default:{
                break;
            }
        }
        #ifdef DEBUG
         //   printCard(player->myDeck[noOfCards]);
            printf("NoOfCardsThatPlayerHave: %d\n", player->noOfCards);
        #endif
    }

}

void chooseFromMiniDeck(Profil *player, unsigned int PlayerCards, struct card cardDeck[], unsigned int noOfCards){
    struct card theCard;
    unsigned int choose=-1;
    playerInfo(player);
    for(unsigned int i=0; i<player->noOfCards; i++)
        if(cardDeck[i].used==1){
            printf("#%d\n\n", i%7);
            printCard(cardDeck[i]);
        }

    while(choose<0 || choose>noOfCards){
        printf("Choose a card from 0 to %d\n", noOfCards-1);
        scanf("%d", &choose);
    }

    for(unsigned int i=0; i<noOfCards; i++){
        if(choose==i && cardDeck[i].used==1)
            theCard=cardDeck[i];
    }
    chooseACard(player, &theCard);
    for(unsigned int i=0; i<noOfCards; i++){
        if(choose==i && cardDeck[i].used==1)
            cardDeck[i]=theCard;
    }
}

void transformRestCoins(Profil *player){
    if(player->coins!=0)
        player->points=player->coins/3;
}

void finalBattle(Profil players[], unsigned int noOfPlayers){
    printf("FINAL BATTLE IS STARTING\n");
    for(unsigned int i=0; i<noOfPlayers; i++){
        if(players[players[i].before].noOfShields > players[i].noOfShields){
            printf("%s win the battle, %s -1 victory points\n", players[players[i].before].nickname, players[i].nickname);
            players[i].points=players[i].points-1;
        }

        if(players[players[i].after].noOfShields > players[i].noOfShields){
            printf("%s win the battle, %s -1 victory points\n", players[players[i].after].nickname, players[i].nickname);
            players[i].points=players[i].points-1;
        }
         if(players[players[i].before].noOfShields < players[i].noOfShields){
            printf("%s lose the battle, %s +1 victory points\n", players[players[i].before].nickname, players[i].nickname);
            players[i].points=players[i].points+1;
        }
         if(players[players[i].after].noOfShields < players[i].noOfShields){
            printf("%s lose the battle, %s +1 victory points\n", players[players[i].after].nickname, players[i].nickname);
            players[i].points=players[i].points+1;
         }


    }
    for(unsigned int i=0; i<noOfPlayers; i++)
        transformRestCoins(&players[i]);

    printf("THE FINAL SCORE IS:\n");
    for(unsigned int i=0; i<noOfPlayers; i++)
        printf("%s: %d;\n", players[i].nickname, players[i].points);

}

void declareWinner(Profil players[], unsigned int noOfPlayers){
    Profil *winner;
    winner=(Profil *)malloc(sizeof(Profil));
    int minimPoints=INT_MIN;
     for(unsigned int i=0; i<noOfPlayers; i++)
        if(minimPoints>players[i].points){
            minimPoints=players[i].points;
            winner=&players[i];
     }
    printf("THE WINNER OF THE FIRST AGE IS %s \n", *winner);
    free(winner);
}


void oneAge(Profil players[], unsigned int noOfPlayers){
    for(unsigned e=0; e<7; e++){
        for(unsigned int i=0; i<noOfPlayers; i++){
            printf("%s is making the choice!\n\n\n", players[i].nickname);
            chooseFromMiniDeck(&players[i], players[i].noOfCards, players[i].myDeck, players[i].noOfCards);
            }
        switchDecks(players, noOfPlayers);
        for(unsigned i=0; i<noOfPlayers; i++)
            oneRoundUpdate(&players[i]);
    }
    finalBattle(players, noOfPlayers);
    declareWinner(players, noOfPlayers);
}

int main(){
    struct card cardDeck[CARD_DECK];
    struct wonder wonders[WONDERS];
    unsigned int noOfPlayers=0;
    unsigned int i=0;
    readCardFromDataBase(cardDeck, "cards1.csv");
    readWonderFromDataBase(wonders, "wonders1.csv");
    shuffleCards(cardDeck);
    #ifdef DEBUG
        printWonders(wonders);
        printCardDeck(cardDeck);
    #endif
    while(noOfPlayers<3 || noOfPlayers>7){
        i++;
        if(i%3==0)
            printf("ARE YOU KIDDING ME!? JUST CHOOSE THE NUMBER OF PLAYERS BETWEEN 3-7 =| \n");
        printf("How many players are playing? insert a number between 3-7:\n");
        scanf("%d", &noOfPlayers);
    }
    Profil players[noOfPlayers+1];
    gamePlayers(players,noOfPlayers, wonders, cardDeck);
    oneAge(players, noOfPlayers);

    return 0;
}
