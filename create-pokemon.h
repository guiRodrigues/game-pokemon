#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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
};

void CompareType(float &pMult, float &mMult, string typePlayer, string typeMachine){

    if(typePlayer=="Bug"){
        if(typeMachine=="Dark" || typeMachine=="Grass" || typeMachine=="Psychic"){
            pMult = 2;
        }
        else if(typeMachine=="Fire" || typeMachine=="Fighting" || typeMachine=="Poison" || typeMachine=="Flying" || typeMachine=="Ghost" || typeMachine=="Steel" || typeMachine=="Fairy"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Dragon"){
        if(typeMachine=="Dragon"){
            pMult = 2;
        }
        else if(typeMachine=="Stell"){
            pMult = 0.5;
        }
        else if(typeMachine=="Fairy"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Electric"){
        if(typeMachine=="Water" || typeMachine == "Flying"){
            pMult = 2;
        }
        else if(typeMachine=="Grass" || typeMachine=="Electric" || typeMachine=="Dragon"){
            pMult = 0.5;
        }
        else if(typeMachine=="Ground"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Fairy"){
        if(typeMachine=="Dark" || typeMachine=="Dragon" || typeMachine=="Fighting"){
            pMult = 2;
        }
        else if(typeMachine == "Poison" || typeMachine=="Steel" || typeMachine=="Fire"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Fighting"){
        if(typeMachine=="Dark" || typeMachine=="Ice" || typeMachine=="Normal" || typeMachine=="Rock" || typeMachine=="Steel"){
            pMult = 2;
        }
        else if(typeMachine=="Poison" || typeMachine=="Flying" || typeMachine=="Psychic" || typeMachine=="Bug" || typeMachine=="Fairy"){
            pMult = 0.5;
        }
        else if(typeMachine=="Ghost"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Fire"){
        if(typeMachine=="Bug" || typeMachine=="Grass" || typeMachine=="Ice" || typeMachine=="Steel"){
            pMult = 2;
        }
        else if(typeMachine=="Fire" || typeMachine=="Ground" || typeMachine=="Rock" || typeMachine=="Water"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Flying"){
        if(typeMachine=="Bug" || typeMachine=="Fighting" || typeMachine=="Grass"){
            pMult = 2;
        }
        else if(typeMachine=="Electric" || typeMachine=="Rock" || typeMachine=="Steel"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Ghost"){
        if(typeMachine=="Ghost" || typeMachine=="Psychic"){
            pMult = 2;
        }
        if(typeMachine=="Dark"){
            pMult = 0.5;
        }
        else if(typeMachine=="Normal"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Grass"){
        if(typeMachine=="Ground" || typeMachine=="Rock" || typeMachine=="Water"){
            pMult = 2;
        }
        else if(typeMachine=="Bug" || typeMachine=="Fire" || typeMachine=="Flying" || typeMachine=="Ice" || typeMachine=="Poison" || typeMachine=="Dragon" || typeMachine=="Steel"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Ground"){
        if(typeMachine=="Electric" || typeMachine=="Fire" || typeMachine=="Poison" || typeMachine=="Rock" || typeMachine=="Steel"){
            pMult = 2;
        }
        if(typeMachine=="Grass" || typeMachine=="Bug"){
            pMult = 0.5;
        }
        else if(typeMachine=="Flying"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Ice"){
        if(typeMachine=="Dragon" || typeMachine=="Flying" || typeMachine=="Grass" || typeMachine=="Ground"){
            pMult = 2;
        }
        else if(typeMachine=="Grass" || typeMachine=="Bug"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Normal"){
        if(typeMachine=="Rock" || typeMachine=="Stell"){
            pMult = 0.5;
        }
        else if(typeMachine=="Ghost"){
            pMult = 0.2;
        }
    }    

    else if(typePlayer=="Poison"){
        if(typeMachine=="Fairy" || typeMachine=="Grass"){
            pMult = 2;
        }
        else if(typeMachine=="Ground" || typeMachine=="Poison" || typeMachine=="Rock" || typeMachine=="Ghost"){
            pMult = 0.5;
        }
        else if(typeMachine=="Steel"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Psychic"){
        if(typeMachine=="Fight" || typeMachine=="Poison"){
            pMult = 2;
        }
        else if(typeMachine=="Psychic" || typeMachine=="Stell"){
            pMult = 0.5;
        }
        else if(typeMachine=="Dark"){
            pMult = 0.2;
        }
    }

    else if(typePlayer=="Rock"){
        if(typeMachine=="Bug" || typeMachine=="Fire" || typeMachine=="Flying" || typeMachine=="Ice"){
            pMult = 2;
        }
        else  if(typeMachine=="Fighting" || typeMachine=="Ground" || typeMachine=="Steel"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Steel"){
        if(typeMachine=="Fairy" || typeMachine=="Ice" || typeMachine=="Rock"){
            pMult = 2;
        }
        else if(typeMachine=="Water" || typeMachine=="Electric" || typeMachine=="Steel"){
            pMult = 0.5;
        }
    }

    else if(typePlayer=="Water"){
        if(typeMachine=="Fairy" || typeMachine=="Ice" || typeMachine=="Rock"){
            pMult = 2;
        }
        else if(typeMachine=="Water" || typeMachine=="Electric" || typeMachine=="Steel"){
            pMult = 0.5;
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
    << "Digite o elemento do Pokemon: "
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
        cout << "Número Invalido" << endl;
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
    << pokemon.sp << endl;

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
            >> pokemon.sp;

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
            >> pokemon.sp;

            cout
            << "Id " << pokemon.id << " "
            << "[" << pokemon.name << "] "
            << pokemon.element << " "
            << "Atk:" << pokemon.attack << " "
            << "Satk:" << pokemon.magicalAttack << " "
            << "Def:" << pokemon.defese << " "
            << "Sdef:" << pokemon.magicalDefese << " "
            << "HP:" << pokemon.hp << " "
            << "SP:" << pokemon.sp
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
        >> lasttxt[i].sp;
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
        << lasttxt[i].sp << endl;
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
        >> pokedex[i].sp;
    }

    SimpleList();

    for(int i=0; i<6; i++){
        // PLayer
        int choose=0;
        ok=1;

        cout << "Digite o ID do " << i+1 << " Pokemon:" << endl;
        cin >> choose;
 
        while(choose<0 || choose>pokemonsNumber-1){
            cout << "Escolha um Id valido: ";
            cin >> choose;
            cout << endl;
        }

        SimpleList();

        player[i].id = pokedex[choose].id;
        player[i].name = pokedex[choose].name;
        player[i].element = pokedex[choose].element;
        player[i].attack = pokedex[choose].attack;
        player[i].magicalAttack = pokedex[choose].magicalAttack;
        player[i].defese = pokedex[choose].defese;
        player[i].magicalDefese = pokedex[choose].magicalDefese;
        player[i].hp = pokedex[choose].hp;
        player[i].sp = pokedex[choose].sp;

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

        for(int j=1; j<=i; j++){
            while(machineId[j-1]==machine[i].id){
                randle = rand() % pokemonsNumber;
            }
        }

        if(ok){
            cout << "Ash escolheu " << player[i].name << endl
            << "Gary escolheu " << machine[i].name << endl << endl;
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

    int r=0, p=0, m=0, pTypeAtk=0, mTypeAtk=0, pp=0;
    float pMult=1, mMult=1;

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

    cout << "  Ash  X  Gary  " << endl;
    for(int i=0; i<6; i++){
        cout
        << resc_player[i]
        << " X "
        << resc_machine[i] << endl;
    }

    cout << endl << "A batalha comecou!" << endl << endl;

    while(p<6 && m<6){
        
        CompareType(pMult, mMult, player[p].element, machine[m].element);

        cout
        << "Escolha o tipo de ataque: " << endl
        << "1 - Ataque Corporal" << endl
        << "2 - Ataque Especial" << endl;

        cin >> pTypeAtk;
        cout << endl;

        while(pTypeAtk>2 || pTypeAtk<1){
            cout << "Ecolha 1 ou 2" << endl;
            cin >> pTypeAtk;
        }

        if(pTypeAtk==1){
            if(player[p].attack - machine[m].defese < player[p].attack*0.1){
                machine[m].hp -= (player[p].attack*0.1)*pMult;
            } else {
                machine[m].hp -= (player[p].attack*pMult) - machine[m].defese;                
            }
            if(machine[m].hp < 0) cout << machine[m].name << " - HP " << 0 << endl;
            else cout << machine[m].name << " - HP " << machine[m].hp << endl;
        } else {
            if(player[p].magicalAttack - machine[m].magicalDefese < player[p].magicalAttack*0.1){
                machine[m].hp -= (player[p].magicalAttack*0.1)*pMult;
            } else {
                machine[m].hp -= (player[p].magicalAttack*pMult) - machine[m].magicalDefese;
            }
            if(machine[m].hp < 0) cout << machine[m].name << " - HP " << 0 << endl;
            else cout << machine[m].name << " - HP " << machine[m].hp << endl;
        }

        //srand(time(NULL));
        mTypeAtk = rand()%2;

        if(mTypeAtk==0){
            if(machine[m].attack - player[p].defese < machine[m].attack*0.1){
                player[p].hp -= (machine[m].attack*0.1)*mMult;
            } else {
                player[p].hp -= (machine[m].attack*mMult) - player[p].defese;
            }
            if(player[p].hp<0) cout << player[p].name << " - HP " << 0 << endl << endl;
            else cout << player[p].name << " - HP " << player[p].hp << endl << endl;
        } else{
            if(machine[m].magicalAttack - player[p].magicalDefese < machine[m].magicalAttack*0.1){
                player[p].hp -= (machine[m].magicalAttack*0.1)*mMult;
            } else {
                player[p].hp -= (machine[m].magicalAttack*mMult) - player[p].magicalDefese;
            }
            if(player[p].hp < 0)cout << player[p].name << " - HP " << 0 << endl << endl;
            else cout << player[p].name << " - HP " << player[p].hp << endl << endl;
        }

        if(player[p].hp <= 0){

            resultado[r].winRound = 'm';
            resultado[r].winner = m;
            resultado[r].loser = p;

            resc_player[p] = "------";

            cout << "  Ash  X  Gary  " << endl;
        
            for(int i=0; i<6; i++){
                cout
                << resc_player[i]
                << " X "
                << resc_machine[i] << endl;
            }

            cout << endl << "Seu " << player[p].name << " nao resistiu e retornou a pokebola!" << endl;

            r++;
            p++;

            if(m<6) CompareType(pMult, mMult, player[p].element, machine[m].element);
            if(p<6) cout << player[p].name << " entrou na batalha!" << endl << endl;
        }

        if(machine[m].hp <= 0){

            resultado[r].winRound = 'p';
            resultado[r].winner = p;
            resultado[r].loser = m;

            resc_machine[m] = "------";

            cout << "  Ash  X  Gary  " << endl;
        
            for(int i=0; i<6; i++){
                cout
                << resc_player[i]
                << " X "
                << resc_machine[i] << endl;
            }

            cout << endl << machine[m].name << " foi derrotado!" << endl;

            r++;            
            m++;

            if(m<6) CompareType(pMult, mMult, player[p].element, machine[m].element);
            if(m<6) cout << machine[m].name << " entrou para enfrenta-lo!" << endl << endl;
        }
    }

    cout << endl << "   RESULTADOS:" << endl;
    
    for(int i=0; i<r; i++){
        if(resultado[i].winRound=='p'){
            cout
            << player[resultado[i].winner].name
            << " Win "
            << machine[resultado[i].loser].name << endl;
        }
        else{
            cout
            << machine[resultado[i].winner].name
            << " Lose "
            << player[resultado[i].loser].name << endl;
        }
    }

    cout << endl;

    if(p<6){
        cout << "Garry foi derrotado! \nParabens voce e um grande mestre Pokemon!" << endl << endl;
    } else {
        cout << "Nao foi dessa vez... esta pronto para a proxima batalha?" << endl << endl;
    }
}

void Menu(){
    char option = 's';

    while(option=='s'){
        char opt = '\0';
        cout << "[S] Lista de Pokemons - Simples" << endl;
        cout << "[C] Lista de Pokemons - Completa" << endl;
        cout << "[A] Adicionar Pokemon" << endl;
        cout << "[R] Remover Pokemon" << endl;
        cout << "[B] Iniciar Batalha" << endl;
        cout << "[E] Deixar o Game" << endl << endl;
        cin >> opt;

        if((opt>='a') && (opt<='z')){
            opt='A'+(opt-'a');
        }

        switch(opt){
            case 'S':
                cout << endl;
                SimpleList();
                break;
            case 'C':
                cout << endl;
                FullList();
                break;
            case 'A':
                cout << endl;
                CreatePokemon();
                break;
            case 'R':
                cout << endl;
                DeletePokemon();
                break;
            case 'B':
                cout << endl;
                Battle();
                break;
            case 'E':
                cout << endl << "GoodBye Mestre Pokemon!" << endl;;
                option='n';
                break;
            default:
                cout << "Opcao invalida" << endl << endl;
                Menu();
        }
    }
}
