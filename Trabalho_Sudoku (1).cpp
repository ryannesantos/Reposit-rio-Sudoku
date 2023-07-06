#include <iostream>
#include <time.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); //semente randomica gerada a partir da hora do sistema

    int MG[9][9], MJ[9][9], i, j, tipo, coor_i, coor_j, ganhou, x, diff=0,jogadas=0;
    int MP[9][9] = {2,3,7,8,4,1,5,6,9,
                    1,8,6,7,9,5,2,4,3,
                    5,9,4,3,2,6,7,1,8,
                    3,1,5,6,7,4,8,9,2,
                    4,6,9,5,8,2,1,3,7,
                    7,2,8,1,3,9,4,5,6,
                    6,4,2,9,1,8,3,7,5,
                    8,5,3,4,6,7,9,2,1,
                    9,7,1,2,5,3,6,8,4};
    char menu = '0', dificuldade='0';
    i = 0;
    ganhou = 0;

 while (menu != '4'){//while para o jogo
    //MENU

    cout<<"\n";
    cout<<"SUDOKU"<<endl;
    cout<<"\n";
    cout<<"MENU"<<endl;
    cout<<"1. Jogar"<<endl;
    cout<<"2. Dificuldade"<<endl;
    cout<<"3. Sobre"<<endl;
    cout<<"4. Fim"<<endl;
    cin>>menu;

        switch (menu){

    case '1':
    ganhou=0;
    jogadas=0;

    system("cls"); //� um comando que limpa a tela do console
    tipo = rand() % 4 + 1; //

    if (tipo == 1){ //Matriz gabrito fica igual a matriz principal
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
            MG [i][j] = MP[i][j];
            }
        }
    } else if (tipo == 2) { //Gera a matriz gabarito transposta
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
            MG [i][j] = MP[j][i];
            }
        }
    } else if (tipo == 3){ //Gera a matriz gabarito inversa por linha
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++){
            MG [i][j] = MP [8-i][j];
            }
        }
    } else if (tipo == 4){ //Gera a matriz gabarito inversa por coluna
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++){
            MG [i][j] = MP [i][8-j];
            }
        }
    }

    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
        MJ [i][j] = MG [i][j];
        }
    }

  if (dificuldade != '1' && dificuldade != '2' && dificuldade != '3'){
    system ("cls");
    cout<<"Escolha primeiramente o n�vel de dificuldade"<<endl;
    cout<<"\n1. F�cil"<<endl;
    cout<<"2. M�dio"<<endl;
    cout<<"3. Dif�cil"<<endl;
    cin>>dificuldade;
    while (dificuldade != '1' && dificuldade != '2' && dificuldade != '3'){
        cout<<"Op��o inv�lidade. Digite '1' para f�cil, '2' para m�dio, '3' para dif�cil"<<endl;
        cin>>dificuldade;
    }
    }

    if (dificuldade == '1'){
        i=0;
        while (i<40) {
        coor_i = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada linha
        coor_j = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada coluna
        if (MJ[coor_i][coor_j] > 0) {    // Confere se o valor j� foi zerado
        i++;
        }
        MJ[coor_i][coor_j] = 0;
        diff=40;
        }
    }
    if (dificuldade == '2'){
      i=0;
     while (i<52) {
        coor_i = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada linha
        coor_j = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada coluna
        if (MJ[coor_i][coor_j] > 0) { // Confere se o valor j� foi zerado
        i = i + 1;
        }
        MJ[coor_i][coor_j] = 0;
        diff=52;
     }
    }
    if (dificuldade == '3'){
      i=0;
        while (i<61) {
        coor_i = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada linha
        coor_j = rand() % 9; // Gera um n�mero pseudo-aleat�rio de 0 a 8 para definir coordenada coluna
           if (MJ[coor_i][coor_j] > 0) { // Confere se o valor j� foi zerado
           i = i + 1;
           }
             MJ[coor_i][coor_j] = 0;
             diff=61;
        }
    }
    while (ganhou != diff){
     system("cls");
      for (i=0;i<9;i++){
cout<<" =====================================\n";

         for (j=0;j<9;j++){

           if (MJ[i][j]!= 0){
            cout<<" | "<<MJ[i][j];

             if(j==8){
                cout<<" |";
             }
           } else{
             cout<<" |  ";

               if (j==8){
               cout<<" |";
               }
             }
        }cout<<"\n";
     }
cout<<" =====================================\n";


    cout<<"Digite a posi��o da linha em que deseja inserir sua resposta"<<endl;
    cin>>i;

    cout<<"Digite a posi��o da coluna em que deseja inserir sua resposta"<<endl;
    cin>>j;

    i = i-1; ///em c++ a primeira linha � zero, ent�o a pesssoa vai digitar o numero da linha que deseja (de 1 � 9) e essa express�o adapta para a linha correta.
    j = j-1;///em c++ a primeira coluna � zero, ent�o a pesssoa vai digitar o numero da coluna que deseja(de 1 � 9) e essa express�o adapta para a coluna correta.

    while(MJ[i][j]!=0){
        cout<<"Essa posi��o j� est� respondida.\nDigite outra linha"<<endl;//Caso a posi��o ja tenha numero
        cin>>i;
        cout<<"Digite outra coluna."<<endl;
        cin>>j;
     i--;
     j--;
    }
    cout<<"\nDigite a resposta da posi��o escolhida"<<endl;
    cin>>MJ[i][j];
    jogadas++;///calcula o numero de jogadas feitas


    while (MJ[i][j]!= MG[i][j]){
    cout<<"Tente novamente. N�o vale roubar. Voc� � capaz, confie em voc� mesmo!"<<endl;
    cin>>MJ[i][j];
    jogadas++;

    }


    ganhou++;
    if(ganhou!=diff){
    cout<<"Digite 2 se voc� deseja parar de jogar, ou qualquer outro numero para continuar"<<endl;
    cin>>x;
        if (x==2){
            cout<<"FIM DE JOGO!"<<endl;
            cout<<"Numero de jogadas: "<<jogadas;
            ganhou = diff; //Para sair do while
        }
    }else{
    cout<<"\nVoc� ganhou!"<<endl;
    cout<<"Numero de jogadas: "<<jogadas;
    }

    }


    break;

    case '2':
    system ("cls");
    cout<<"1. F�cil"<<endl;
    cout<<"2. M�dio"<<endl;
    cout<<"3. Dif�cil"<<endl;
    cin>>dificuldade;
    while (dificuldade != '1' && dificuldade != '2' && dificuldade != '3'){
        cout<<"Op��o inv�lidade. Digite '1' para f�cil, '2' para m�dio, '3' para dif�cil"<<endl;
        cin>>dificuldade;
    }

    cout<<"Boa Sorte, para jogar nessa dificuldade no menu digite 1"<<endl;
    break;


    case '3':
    system("cls");
    cout <<"\nDesenvolvedoras:     Elizabete Lucindo da Silva\n";
    cout<<"                     Fabiane Santos Soares\n";
    cout<<"                     Marilia Hentz\n";
    cout<<"                     Ryanne dos Santos \n\n";
    cout<<"Professora: Cristina Ono Horita\n";
    cout<<"Disciplina: Algoritmos e Programa��o\n";
    cout<<"Junho/2023\n";
    cout<<"\nDigite '4' para finalizar, ou qualquer outro numero/letra para voltar ao menu principal"<<endl;
    cin>>menu;
        if (menu == '4'){
        system("cls");
        cout<<"FIM"<<endl;
return 0;

        } else {
        system("cls");
        menu = '0';
        }

    break;

    case '4':
    system ("cls");
    cout<<"FIM"<<endl;
    break;

    default:
    system ("cls");
    cout<<"Op��o inv�lida. "<<endl;
    }
    }
    return 0;
}





