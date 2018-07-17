#include <iostream>
#include <fstream>
#include <string>
#include <ctime>        // time no srand
#include <stdlib.h>     // srand, rand

using namespace std;

struct POKEMON{
    int id;
    string name;
    string element;
    int attack;
    int magicalAttack;
    int defese;
    int magicalDefese;
    int hp;
    int sp;
    int speed;
};

void damageInvestida(int typeAtack, float mult, POKEMON *pokeIvestida, int i, POKEMON *pokeDefense, int d){
        if(typeAtack==0){
            if(pokeIvestida[i].attack - pokeDefense[d].defese < pokeIvestida[i].attack*1.1){
                pokeDefense[d].hp -= pokeIvestida[i].attack*0.1;
            } else {
                pokeDefense[d].hp -= pokeIvestida[i].attack - pokeDefense[d].defese;
            }
        } else{
            if(pokeIvestida[i].magicalAttack - pokeDefense[d].magicalDefese < pokeIvestida[i].magicalAttack*1.1){
                pokeDefense[d].hp -= (pokeIvestida[i].magicalAttack*0.1)*mult;
                pokeIvestida[i].sp--;
            } else {
                pokeDefense[d].hp -= (pokeIvestida[i].magicalAttack*mult) - pokeDefense[d].magicalDefese;
                pokeIvestida[i].sp--;
            }
        }
}

void printStatusBattle(POKEMON *pokeStatus, int i){
    if(pokeStatus[i].hp<=0){
        cout << pokeStatus[i].name << " - [HP 0]" << endl;
    } else {
        cout << pokeStatus[i].name << " - [PP " << pokeStatus[i].sp << "] [HP " << pokeStatus[i].hp << "]" << endl;
    }
}

void CompareType(float &mult, string type1, string type2){

    if(type1=="Bug"){
        if(type2=="Dark" || type2=="Grass" || type2=="Psychic"){
            mult = 2;
        }
        else if(type2=="Fire" || type2=="Fighting" || type2=="Poison" || type2=="Flying" || type2=="Ghost" || type2=="Steel" || type2=="Fairy"){
            mult = 0.5;
        }
    }

    else if(type1=="Dragon"){
        if(type2=="Dragon"){
            mult = 2;
        }
        else if(type2=="Stell"){
            mult = 0.5;
        }
        else if(type2=="Fairy"){
            mult = 0.2;
        }
    }

    else if(type1=="Electric"){
        if(type2=="Water" || type2 == "Flying"){
            mult = 2;
        }
        else if(type2=="Grass" || type2=="Electric" || type2=="Dragon"){
            mult = 0.5;
        }
        else if(type2=="Ground"){
            mult = 0.2;
        }
    }

    else if(type1=="Fairy"){
        if(type2=="Dark" || type2=="Dragon" || type2=="Fighting"){
            mult = 2;
        }
        else if(type2 == "Poison" || type2=="Steel" || type2=="Fire"){
            mult = 0.5;
        }
    }

    else if(type1=="Fighting"){
        if(type2=="Dark" || type2=="Ice" || type2=="Normal" || type2=="Rock" || type2=="Steel"){
            mult = 2;
        }
        else if(type2=="Poison" || type2=="Flying" || type2=="Psychic" || type2=="Bug" || type2=="Fairy"){
            mult = 0.5;
        }
        else if(type2=="Ghost"){
            mult = 0.2;
        }
    }

    else if(type1=="Fire"){
        if(type2=="Bug" || type2=="Grass" || type2=="Ice" || type2=="Steel"){
            mult = 2;
        }
        else if(type2=="Fire" || type2=="Ground" || type2=="Rock" || type2=="Water"){
            mult = 0.5;
        }
    }

    else if(type1=="Flying"){
        if(type2=="Bug" || type2=="Fighting" || type2=="Grass"){
            mult = 2;
        }
        else if(type2=="Electric" || type2=="Rock" || type2=="Steel"){
            mult = 0.5;
        }
    }

    else if(type1=="Ghost"){
        if(type2=="Ghost" || type2=="Psychic"){
            mult = 2;
        }
        if(type2=="Dark"){
            mult = 0.5;
        }
        else if(type2=="Normal"){
            mult = 0.2;
        }
    }

    else if(type1=="Grass"){
        if(type2=="Ground" || type2=="Rock" || type2=="Water"){
            mult = 2;
        }
        else if(type2=="Bug" || type2=="Fire" || type2=="Flying" || type2=="Ice" || type2=="Poison" || type2=="Dragon" || type2=="Steel"){
            mult = 0.5;
        }
    }

    else if(type1=="Ground"){
        if(type2=="Electric" || type2=="Fire" || type2=="Poison" || type2=="Rock" || type2=="Steel"){
            mult = 2;
        }
        if(type2=="Grass" || type2=="Bug"){
            mult = 0.5;
        }
        else if(type2=="Flying"){
            mult = 0.2;
        }
    }

    else if(type1=="Ice"){
        if(type2=="Dragon" || type2=="Flying" || type2=="Grass" || type2=="Ground"){
            mult = 2;
        }
        else if(type2=="Grass" || type2=="Bug"){
            mult = 0.5;
        }
    }

    else if(type1=="Normal"){
        if(type2=="Rock" || type2=="Stell"){
            mult = 0.5;
        }
        else if(type2=="Ghost"){
            mult = 0.2;
        }
    }

    else if(type1=="Poison"){
        if(type2=="Fairy" || type2=="Grass"){
            mult = 2;
        }
        else if(type2=="Ground" || type2=="Poison" || type2=="Rock" || type2=="Ghost"){
            mult = 0.5;
        }
        else if(type2=="Steel"){
            mult = 0.2;
        }
    }

    else if(type1=="Psychic"){
        if(type2=="Fight" || type2=="Poison"){
            mult = 2;
        }
        else if(type2=="Psychic" || type2=="Stell"){
            mult = 0.5;
        }
        else if(type2=="Dark"){
            mult = 0.2;
        }
    }

    else if(type1=="Rock"){
        if(type2=="Bug" || type2=="Fire" || type2=="Flying" || type2=="Ice"){
            mult = 2;
        }
        else  if(type2=="Fighting" || type2=="Ground" || type2=="Steel"){
            mult = 0.5;
        }
    }

    else if(type1=="Steel"){
        if(type2=="Fairy" || type2=="Ice" || type2=="Rock"){
            mult = 2;
        }
        else if(type2=="Water" || type2=="Electric" || type2=="Steel"){
            mult = 0.5;
        }
    }

    else if(type1=="Water"){
        if(type2=="Fairy" || type2=="Ice" || type2=="Rock"){
            mult = 2;
        }
        else if(type2=="Water" || type2=="Electric" || type2=="Steel"){
            mult = 0.5;
        }
    }
}

void CreatePokemon(){

    POKEMON pokemon;

    int id=0, type=0;

    fstream file;

    file.open("pokemons.txt", ios::in | ios::out);
    file >> id;
    file.close();

    file.open("pokemons.txt", ios::in | ios::out | ios::app);
    pokemon.id = id;
    cout << "Digite o nome do Pokemon: ";
    cin >> pokemon.name;

    cout
    << "Digite o elemento do Pokemon:\n"
    << "1 - Bug\n"
    << "2 - Dragon\n"
    << "3 - Electric\n"
    << "4 - Fairy\n"
    << "5 - Fighting\n"
    << "6 - Fire\n"
    << "7 - Ghost\n"
    << "8 - Grass\n"
    << "9 - Ground\n"
    << "10 - Ice\n"
    << "11 - Normal\n"
    << "12 - Poison\n"
    << "13 - Psychic\n"
    << "14 - Rock\n"
    << "15 - Steel\n"
    << "16 - Water\n";

    cin >> type;

    while(type < 1 || type > 16){
        cout << "Numero Invalido" << endl;
        cin >> type;
    }

    switch(type){
        case 1:
            pokemon.element = "Bug";
            break;
        case 2:
            pokemon.element = "Dragon";
            break;
        case 3:
            pokemon.element = "Electric";
            break;
        case 4:
            pokemon.element = "Fighting";
            break;
        case 5:
            pokemon.element = "Fairy";
            break;
        case 6:
            pokemon.element = "Fire";
            break;
        case 7:
            pokemon.element = "Ghost";
            break;
        case 8:
            pokemon.element = "Grass";
            break;
        case 9:
            pokemon.element = "Ground";
            break;
        case 10:
            pokemon.element = "Ice";
            break;
        case 11:
            pokemon.element = "Normal";
            break;
        case 12:
            pokemon.element = "Poison";
            break;
        case 13:
            pokemon.element = "Psychic";
            break;
        case 14:
            pokemon.element = "Rock";
            break;
        case 15:
            pokemon.element = "Steel";
            break;
        case 16:
            pokemon.element = "Water";
    }

// vet["Grass", "Rock", "Ground"...] vet[digitado];

    cout << "Digite o nivel de ataque fisico do Pokemon: ";
    cin >> pokemon.attack;
    cout << "Digite o nivel de ataque magico do Pokemon: ";
    cin >> pokemon.magicalAttack;
    cout << "Digite o nivel de defesa fisica do Pokemon: ";
    cin >> pokemon.defese;
    cout << "Digite o nivel de defesa magica do Pokemon: ";
    cin >> pokemon.magicalDefese;
    cout << "Digite o HP do Pokemon: ";
    cin >> pokemon.hp;
    cout << "Digite o SP do Pokemon: ";
    cin >> pokemon.sp;
    cout << "Digite a velocidade do Pokemon: ";
    cin >> pokemon.speed;

    file >> id;

    file
    << pokemon.id << endl
    << pokemon.name << endl
    << pokemon.element << endl
    << pokemon.attack << endl
    << pokemon.magicalAttack << endl
    << pokemon.defese << endl
    << pokemon.magicalDefese << endl
    << pokemon.hp << endl
    << pokemon.sp << endl
    << pokemon.speed << endl;

    file.close();

    file.open("pokemons.txt", ios::in | ios::out);

    if(file.fail()){
        cout << "O arquivo nao pode ser aberto!\n";
    }
    else{
        file << id+1;
    }

    file.close();
    cout << endl;
}

void SimpleList(){
    POKEMON pokemon;

    fstream file;

    int pokemonsNumber = 0;

    file.open("pokemons.txt", ios::in | ios::out);

    if(file.fail()){
        cout << "O arquivo nao pode ser aberto!\n";
    }
    else{
        file >> pokemonsNumber;

        while (!file.fail()){
            file >> pokemon.id;
            if (file.fail()) break;
            file
            >> pokemon.name
            >> pokemon.element
            >> pokemon.attack
            >> pokemon.magicalAttack
            >> pokemon.defese
            >> pokemon.magicalDefese
            >> pokemon.hp
            >> pokemon.sp
            >> pokemon.speed;

            cout
            << "Id/Nome "
            << pokemon.id
            << "-"
            << pokemon.name
            << endl;
        }
    }

    cout << endl;

    file.close();
}

void FullList(){
    POKEMON pokemon;

    fstream file;

    int pokemonsNumber = 0;

    file.open("pokemons.txt", ios::in | ios::out);

    if(file.fail()){
        cout << "O arquivo nao pode ser aberto!\n";
    }
    else{
        file >> pokemonsNumber;

        while (!file.fail()){
            file >> pokemon.id;
            if (file.fail()) break;
            file
            >> pokemon.name
            >> pokemon.element
            >> pokemon.attack
            >> pokemon.magicalAttack
            >> pokemon.defese
            >> pokemon.magicalDefese
            >> pokemon.hp
            >> pokemon.sp
            >> pokemon.speed;

            cout
            << "Id " << pokemon.id << " "
            << "[" << pokemon.name << "] "
            << pokemon.element << " "
            << "Atk:" << pokemon.attack << " "
            << "Satk:" << pokemon.magicalAttack << " "
            << "Def:" << pokemon.defese << " "
            << "Sdef:" << pokemon.magicalDefese << " "
            << "HP:" << pokemon.hp << " "
            << "SP:" << pokemon.sp << " "
            << "Speed:" << pokemon.speed
            << endl;
        }
    }

    file.close();
    cout << endl;
}

void DeletePokemon(){
    int pokemonsNumber = 0;
    int deleteId = 0;
    string deletePoke = "\0";

    fstream file;
    file.open("pokemons.txt", ios::in | ios::out);

    file >> pokemonsNumber;

    SimpleList();

    cout << "Digite o Id do pokemon a ser deletado: ";
    cin >> deleteId;

    while(deleteId>pokemonsNumber){
        cout << "Digite um Id valido: ";
        cin >> deleteId;
    }

    POKEMON * lasttxt = new POKEMON [pokemonsNumber];

    int i=0;

    while(!file.fail()){
        file >> lasttxt[i].id;
        if(file.fail()) break;
        file
        >> lasttxt[i].name
        >> lasttxt[i].element
        >> lasttxt[i].attack
        >> lasttxt[i].magicalAttack
        >> lasttxt[i].defese
        >> lasttxt[i].magicalDefese
        >> lasttxt[i].hp
        >> lasttxt[i].sp
        >> lasttxt[i].speed;
        i++;
    }

    deletePoke = lasttxt[deleteId].name;

    for(int i=deleteId; i<pokemonsNumber-1; i++){
        lasttxt[i].id = lasttxt[i+1].id;
        lasttxt[i].name = lasttxt[i+1].name;
        lasttxt[i].element = lasttxt[i+1].element;
        lasttxt[i].attack = lasttxt[i+1].attack;
        lasttxt[i].magicalAttack = lasttxt[i+1].magicalAttack;
        lasttxt[i].defese = lasttxt[i+1].defese;
        lasttxt[i].magicalDefese = lasttxt[i+1].magicalDefese;
        lasttxt[i].hp = lasttxt[i+1].hp;
        lasttxt[i].sp = lasttxt[i+1].sp;
        lasttxt[i].speed = lasttxt[i+1].speed;
    }

    for(int i=0;i<pokemonsNumber;i++){
        lasttxt[i].id = i;
    }

    file.close();

    remove("pokemons.txt");

    ofstream newfile;

    newfile.open("pokemons.txt");

    newfile << pokemonsNumber-1 << endl;

    for(int i=0;i<pokemonsNumber-1;i++){
        newfile
        << lasttxt[i].id << endl
        << lasttxt[i].name << endl
        << lasttxt[i].element << endl
        << lasttxt[i].attack << endl
        << lasttxt[i].magicalAttack << endl
        << lasttxt[i].defese << endl
        << lasttxt[i].magicalDefese << endl
        << lasttxt[i].hp << endl
        << lasttxt[i].sp << endl
        << lasttxt[i].speed << endl;
    }

    file.close();

    cout << "O pokemon " << deletePoke << " foi removido!" << endl << endl;
}

void ChoosePokemons(POKEMON * player, POKEMON * machine){
    srand(time(NULL));
    bool ok=1;
    int pokemonsNumber=0, randle=0;
    int * machineId = new int[6];

    fstream file;
    file.open("pokemons.txt", ios::in | ios::out);

    file >> pokemonsNumber;

    POKEMON * pokedex = new POKEMON [pokemonsNumber];

    for( int i=0; i<pokemonsNumber; i++ ){
        file
        >> pokedex[i].id
        >> pokedex[i].name
        >> pokedex[i].element
        >> pokedex[i].attack
        >> pokedex[i].magicalAttack
        >> pokedex[i].defese
        >> pokedex[i].magicalDefese
        >> pokedex[i].hp
        >> pokedex[i].sp
        >> pokedex[i].speed;
    }

    SimpleList();
    cout << "Seu numero de sorte: \"" << pokemonsNumber << "\""<< endl << endl;

    for(int i=0; i<6; i++){
        // PLayer
        int choose=0;
        ok=1;

        cout << "Digite o ID do " << i+1 << " Pokemon:" << endl;
        cin >> choose;

        while(choose<0 || choose>pokemonsNumber){
            cout << "Escolha um Id valido: ";
            cin >> choose;
            cout << endl;
        }

        if(choose==pokemonsNumber) choose = rand()%pokemonsNumber;

        SimpleList();
        cout << "Seu numero da sorte: \"" << pokemonsNumber << "\"" << endl << endl;

        player[i].id = pokedex[choose].id;
        player[i].name = pokedex[choose].name;
        player[i].element = pokedex[choose].element;
        player[i].attack = pokedex[choose].attack;
        player[i].magicalAttack = pokedex[choose].magicalAttack;
        player[i].defese = pokedex[choose].defese;
        player[i].magicalDefese = pokedex[choose].magicalDefese;
        player[i].hp = pokedex[choose].hp;
        player[i].sp = pokedex[choose].sp;
        player[i].speed = pokedex[choose].speed;

        for(int j=1; j<=i; j++){
            if(player[j-1].id == choose){
                cout << "Voce ja escolheu esse Pokemon, tente novamente." << endl;
                ok=0;
                i--;
            }
        }

        // Machine
        randle = rand() % pokemonsNumber;

        machine[i].id = pokedex[randle].id;
        machine[i].name = pokedex[randle].name;
        machine[i].element = pokedex[randle].element;
        machine[i].attack = pokedex[randle].attack;
        machine[i].magicalAttack = pokedex[randle].magicalAttack;
        machine[i].defese = pokedex[randle].defese;
        machine[i].magicalDefese = pokedex[randle].magicalDefese;
        machine[i].hp = pokedex[randle].hp;
        machine[i].sp = pokedex[randle].sp;
        machine[i].speed = pokedex[randle].speed;

        for(int j=1; j<=i; j++){
            while(machineId[j-1] == randle){
                randle = rand() % pokemonsNumber;
            }
        }

        if(ok){
            cout
            << "----------------------------------" << endl
            << " Ash escolheu " << player[i].name << endl
            << " Gary escolheu " << machine[i].name << endl
            << "----------------------------------" << endl << endl;
        }
    }
}

// IIIIIITS TIIIMEEE!!!!!

void Battle(){

    struct RESULTADO{
        char winRound;
        int winner;
        int loser;
    };

    float pMult=1, mMult=1;
    int r=0, p=0, m=0, pDefeated=0, mDefeated=0, pTypeAtk='0', mTypeAtk='0';
    char validation='\0';

    fstream file;
    file.open("pokemons.txt", ios::in | ios::out);

    int pokemonsNumber = 0;
    file >> pokemonsNumber;

    POKEMON * player = new POKEMON [6];
    POKEMON * machine = new POKEMON [6];
    string * resc_player = new string [6];
    string * resc_machine = new string [6];

    RESULTADO * resultado = new RESULTADO [11];

    ChoosePokemons(player, machine);

    for(int i=0;i<6;i++){
        resc_player[i] = player[i].name;
        resc_machine[i] = machine[i].name;
    }

    cout << "   Ash  VS  Gary  " << endl;
    for(int i=0; i<6; i++){
        cout
        << " "
        << resc_player[i]
        << "  x  "
        << resc_machine[i] << endl;
    }

    cout << endl << "Quem ira iniciar a batalha?" << endl << endl;

    for(int i=0;i<6;i++){
        if(player[i].hp>0){
            cout << i+1 << "-";
            printStatusBattle(player, i);
        }
    }

    cin >> p;
    p--;

    while(player[p].hp<=0 || p>5 || p<0){
        cout << "Escolha um numero valido..." << endl;
        cin >> p;
        p--;
    }

    cout << endl << endl
    << "----------------------------------" << endl
    << "        A batalha comecou!" << endl;

    while(pDefeated<6 && mDefeated<6){

        CompareType(pMult, player[p].element, machine[m].element);
        CompareType(mMult, machine[m].element, player[p].element);

        cout << "----------------------------------" << endl;
        printStatusBattle(machine, m);
        printStatusBattle(player, p);
        cout << "----------------------------------" << endl << endl;

        cout
        << "Escolha o tipo de ataque: " << endl
        << "1 - Ataque Corporal" << endl
        << "2 - Ataque Especial" << endl;

        cin >> validation;
        cout << endl;

        if(player[p].sp<1){
            cout << player[p].name << " esta cansado, optou pelo ataque corporal!" << endl << endl;
            validation = '1';
        }

        if(validation!='1' && validation!='2'){
            cout << "Ecolha 1 ou 2" << endl;
            cin >> validation;
        }

        if(validation=='1') pTypeAtk=0;
        else pTypeAtk=1;

        damageInvestida(pTypeAtk, pMult, player, p, machine, m);

        //srand(time(NULL));
        mTypeAtk = rand()%2;

        if(machine[m].sp<1){
            mTypeAtk = 0;
        }

        damageInvestida(mTypeAtk, mMult, machine, m, player, p);

        //if(player[p].hp<=0 && p<6){
        if(player[p].hp<=0){

            resultado[r].winRound = 'm';
            resultado[r].winner = m;
            resultado[r].loser = p;

            resc_player[p] = "------";

            cout << " Ash  VS  Gary  " << endl;

            for(int i=0; i<6; i++){
                cout
                << resc_player[i]
                << "  x  "
                << resc_machine[i] << endl;
            }

            cout
            << endl << "----------------------------------" << endl
            << "Seu " << player[p].name << " nao resistiu e retornou a pokebola!" << endl
            << "----------------------------------" << endl;

            if(pDefeated<5){
                cout << endl << "Quem ira substitui-lo?" << endl << endl;

                for(int i=0;i<6;i++){
                    if(player[i].hp>0){
                        cout << i+1 << "-";
                        printStatusBattle(player, i);
                    }
                }

                cin >> p;
                p--;

                while(player[p].hp<=0 || p>5 || p<0){
                    cout << "Escolha um numero valido..." << endl;
                    cin >> p;
                    p--;
                }
            } else {
                for(int i=0;i<6;i++){
                    if(player[i].hp>0){
                        p=i;
                        break;
                    }
                }
            }

            r++;
            pDefeated++;

            if(pDefeated<6){
                CompareType(pMult, player[p].element, machine[m].element);
                CompareType(mMult, machine[m].element, player[p].element);
                cout
                << endl
                << "----------------------------------" << endl
                << player[p].name << " entrou na batalha!" << endl;
            }
        }

        if(machine[m].hp<=0){

            resultado[r].winRound = 'p';
            resultado[r].winner = p;
            resultado[r].loser = m;

            resc_machine[m] = "------";

            cout << "  Ash  VS  Gary  " << endl;

            for(int i=0; i<6; i++){
                cout
                << resc_player[i]
                << "  x  "
                << resc_machine[i] << endl;
            }

            cout
            << endl << "----------------------------------" << endl
            << machine[m].name << " foi derrotado!" << endl;

            r++;
            m++;
            mDefeated++;

            if(mDefeated<6){
                CompareType(pMult, player[p].element, machine[m].element);
                CompareType(mMult, machine[m].element, player[p].element);
                cout
                << machine[m].name << " entrou para enfrenta-lo!" << endl;
            }
        }
    }

    cout << endl << "     RESULTADOS:" << endl;

    for(int i=0; i<r; i++){
        if(resultado[i].winRound=='p'){
            cout
            << player[resultado[i].winner].name
            << " <Win> "
            << machine[resultado[i].loser].name << endl;
        }
        else{
            cout
            << machine[resultado[i].winner].name
            << " <Lose> "
            << player[resultado[i].loser].name << endl;
        }
    }

    cout << endl;

    if(p<6){
        cout
        << "----------------------------------" << endl
        << "Garry foi derrotado! \nParabens voce e um grande mestre Pokemon!" << endl
        << "----------------------------------" << endl << endl;
    } else {
        cout
        << "----------------------------------" << endl
        << "Nao foi dessa vez... esta pronto para a proxima batalha?" << endl
        << "----------------------------------" << endl << endl;
    }
}

void Menu(){
    char option = 's';
    char opt = '\0';

    while(option=='s'){
        cout
        << "---------( MENU INICIAL )--------- " << endl << endl
        << "[S] Lista de Pokemons - Simples" << endl
        << "[C] Lista de Pokemons - Completa" << endl
        << "[A] Adicionar Pokemon" << endl
        << "[R] Remover Pokemon" << endl
        << "[B] Iniciar Batalha" << endl
        << "[E] Deixar o Game" << endl << endl
        << "---------( POKEMON UFC )----------" << endl;

        cin >> opt;

        if(opt>='A' && opt<='Z'){
            opt='a'+(opt-'A');
        }

        switch(opt){
            case 's':
                cout << endl;
                SimpleList();
                break;
            case 'c':
                cout << endl;
                FullList();
                break;
            case 'a':
                cout << endl;
                CreatePokemon();
                break;
            case 'r':
                cout << endl;
                DeletePokemon();
                break;
            case 'b':
                cout << endl;
                Battle();
                break;
            case 'e':
                cout << endl << "GoodBye Mestre Pokemon!" << endl;;
                exit(0);
                break;
            default:
                cout << "Opcao invalida" << endl << endl;
                Menu();
        }
    }
}
