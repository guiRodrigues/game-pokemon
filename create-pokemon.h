#include <iostream>
#include <fstream>
#include <string>

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
}

void DeletePokemon(){
    fstream file;

    int pokemonsNumber = 0;
    int deleteId = 0;

    file.open("pokemons.txt", ios::in | ios::out);

    file >> pokemonsNumber;

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
            cout << "Id/Nome " << pokemon.id << "-" << pokemon.name << endl;
        }
    }

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
            << "PP:" << pokemon.sp
            << endl;
        }
    }

    file.close();
}

void Choose(){
    char option = 's';

    while(option=='s'){
        char opt = '\0';
        cout << endl;
        cout << "[S] Lista de Pokemons - Simples" << endl;
        cout << "[C] Lista de Pokemons - Completa" << endl;
        cout << "[A] Adicionar Pokemon" << endl;
        cout << "[R] Remover Pokemon" << endl;
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
            case 'E':
                cout << endl << "GoodBye Mestre Pokemon!" << endl;;
                option='n';
                break;
            default:
                cout << "Opcao invalida";
                Choose();
        }
    }
}
