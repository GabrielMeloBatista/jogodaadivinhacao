#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    int chute;
    bool usuarioAcertou = false;
    bool chuteMaior;
    int tentativas = 0;
    double Pontos = 1000.00;
    double PontosPerdidos;
    char Dificuldade;
    int NumeroDeTentativas;
    bool temTentativas;

    cout << "******************************************" << endl;
    cout << "* Bem-vindos(as) ao jogo de adivinhação! *" << endl;
    cout << "******************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade" << endl;
    cout << "Fácil (F), Médio (M), Difícil (D)" << endl;
    cin >> Dificuldade;

    if (Dificuldade == 'F' || Dificuldade == 'f')
    {
        cout << "Fácil Selecionado" << endl;
        NumeroDeTentativas = 15;
    }
    else if (Dificuldade == 'M' || Dificuldade == 'm')
    {
        cout << "Médio Selecionado" << endl;
        NumeroDeTentativas = 10;
    }
    else
    {
        cout << "Difícil Selecionado" << endl;
        NumeroDeTentativas = 5;
    }

    temTentativas = tentativas <= NumeroDeTentativas;
    for (tentativas = 1; temTentativas && !usuarioAcertou; tentativas++)
    {
        cout << "tentativa n° " << tentativas << endl;

        cout << "Qual e seu chute? ";
        cin >> chute;

        PontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        Pontos -= PontosPerdidos;

        usuarioAcertou = chute == NUMERO_SECRETO;
        chuteMaior = chute > NUMERO_SECRETO;

        if (usuarioAcertou)
        {
            cout << "Parabens, você acertou." << endl;
            break;
        }
        else if (chuteMaior)
        {
            cout << "Seu chute e maior que o numero secreto!!" << endl;
        }
        else
        {
            cout << "Seu chute e menor que o numero secreto!!" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if (usuarioAcertou)
    {
        cout << "Você acertou o numero secreto em " << tentativas << " tentativa(s)!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua Pontuação foi de " << Pontos << " pontos." << endl;
    }
    else
    {
        cout << "Você não acertou! Tente novamente" << endl;
    }

    return 0;
}
