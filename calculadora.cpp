/*
 Calculadora - v1.0 - 09 / 11 / 2022
 Author: Pedro Moura
*/

// dependencias

#include <iostream> // std::cin, std::cout, std:endl
#include <string>   // para cadeias de caracteres
#include <stdlib.h>
#include <sstream>      // std::istringstream

using namespace std;
// instruction

#define PI 3.14159265359

// ----------------------------------------------- classes / pacotes
    double sum (double num1, double num2) { return (num1 + num2); }
    double sub (double num1, double num2) { return (num1 - num2); }
    double mult (double num1, double num2) { return (num1 * num2); }
    double div (double num1, double num2) { return (num1 / num2); }
    double convertRad (double num) { return num*PI/180; }
    double pot (double num1, double pot){
        double result = num1;
        for (int i = 1; i<pot;i++){result = result * num1;}
        return result;
    }
    double percen (double num1, double percen) { return ((num1/100)*percen); }
    int fat (double n){
        if (n < 2){ return 1; }
        int prod = n;
        for (int i = n-1; i > 0; i--){ prod *= i; }
        return prod;
    }
    int getLength (string x){
        int contador = 0;
        while (x [contador] != '\0'){ contador ++; }
        return contador;
    }
    double converter2 (string str){
        str.erase (0,1);
        istringstream iss(str);
        int X = 0;
        iss >> X;
        while (X>0){
            X/10;
        }
        return X;
    }
    double converter (string str){
        if (!(str[0] >= '0' && str[0] <= '9')) {str.erase (0,1);}
        istringstream iss(str);
        int X = 0;
        iss >> X;
        return X;
    }
    string freee (string op){
        int x = 0;
        do{ x++; }while((op[x] >= '0' && op[x] <= '9'));
        op.erase (0,x);
        return op;
    }
void pause(string text)
{
    string dummy;
    cin.clear();
    cout << endl
              << text;
    cin.ignore();
    getline(cin, dummy);
    cout << endl
              << endl;
} // end pause ( )
double operations2 (string op, double jota){
    string aux = to_string(jota);
    op = aux + op;
    int length = getLength (op); //RETORNA TAMANHO DA STRING
    double x =0;
    int i = 0;
    double result = converter(op);
    op = freee (op);
    result += converter2(op);
    op = freee (op);
    while (op[i] != '\0'){
        if (op[i] == '+'){
             x = converter(op);
            result = sum(result, x);
        }
        if (op[i] == '-'){
             x = converter(op);
             op = freee (op);
            result = sub(result, x);
        }
        if (op[i] == 'x' || op[i] == '*'){
             x = converter(op);
            result = mult(result, x);
        }
        if (op[i] == '/' || op[i] == ':'){
             x = converter(op);
            result = div(result, x);
        }
        if (op[i] == '^'|| op[i] == '~'){
             x = converter(op);
            result = pot(result, x);
        }
        if (op[i] == '%'){
             x = converter(op);
            result = percen (x, result);
        }

        i++;
    }
    return result;
}

double operations (string op){
    int length = getLength (op); //RETORNA TAMANHO DA STRING
    double x =0;
    int i = 0;
    double result = converter(op);
    op = freee (op);
    while (op[i] != '\0'){
        if (op[i] == '+'){
             x = converter(op);
            result = sum(result, x);
        }
        if (op[i] == '-'){
             x = converter(op);
             op = freee (op);
            result = sub(result, x);
        }
        if (op[i] == 'x' || op[i] == '*'){
             x = converter(op);
            result = mult(result, x);
        }
        if (op[i] == '/' || op[i] == ':'){
             x = converter(op);
            result = div(result, x);
        }
        if (op[i] == '^'|| op[i] == '~'){
             x = converter(op);
            result = pot(result, x);
        }
        if (op[i] == '%'){
             x = converter(op);
            result = percen (x, result);
        }
        i++;
    }
    return result;
}

/**
 * Funcao principal
 * @return codigo de encerramento
 */
int main(int argc, char **argv)
{
    int x = 0;
    double jota = 0;
    string op;
    printf ("\nCalculadora - v1.0 - 01 / 11 / 2022\nAuthors: Pedro Marcelo Ciriaco Moura, Joao Luiz Carvalho de Araujo, Pedro Henrique Salles.\n");
    printf ("\nOperadores Aritmeticos: \n");
    printf ("\nAdicao: '+'\nSubtracao: '-'\nMultiplicacao: 'x' ou '*'\nDivisao: ':' ou '/'\nPotencia: '~' ou '^'\nPorcentagem: '%%'\n");
    printf ("\nEntre com a operacao desejada: ");
    getline (cin, op);
    jota = operations(op);
    printf ("\nResultado da operacao: %.2lf\n", jota);
    do{
        printf ("Digite '1' para continuar e '0' para parar: ");
        scanf ("%d", &x);
        cin.ignore();
        switch (x)
        {
        case 1:
            printf ("\nAdicao: '+'\nSubtracao: '-'\nMultiplicacao: 'x' ou '*'\nDivisao: ':' ou '/'\nPotencia: '~' ou '^'\nPorcentagem: '%%'\n");
            printf ("\nEntre com a operacao desejada: %.2lf", jota);
            getline (cin, op);
            jota = operations2(op, jota);
            printf ("\nResultado da operacao: %.2lf\n", jota);
            break;
        
        default:
            break;
        }
    }while (x!=0);

    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
