#ifndef INTERFACEGRAFICA_H
#define INTERFACEGRAFICA_H

#include <Windows.h>
#include <cmath>
#include <cstring>
#include <exception>

#include <type_traits>
#include <vector>
#include <algorithm>
#include <numeric>

#include <utility>
#include <string>

using namespace std;

struct dadosTela {
    string titulo = "";
    float tamanho = 0;
};

struct dadosTexto {
    string texto;
    bool navegavel = false;
    bool entrada = false;
};

struct manipulavel {
    wstring texto;
    SHORT linha;
    SHORT coluna;
};

enum modoTexto {
    INICIO,
    MEIO,
    FIM
};

class InterfaceGrafica {
    private:
        vector<string> titulos = {};
        vector<pair<SHORT, SHORT>> colunasTelas;
        vector<manipulavel> navegaveis;
        vector<manipulavel> entradas;
        vector<vector<string>> textosAuxiliares;

        CONSOLE_CURSOR_INFO info;
        HANDLE telaOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE telaInput = GetStdHandle(STD_INPUT_HANDLE);
        SHORT colunas, linhas;

        void limparTela(int tela);
        void renderChar(int caractere, SHORT coluna, SHORT linha);
        void renderLinha(manipulavel linhaManipulavel, WORD atributos);

    public:
        InterfaceGrafica();

        void setTextosAuxiliares(vector<vector<string>> textosAuxiliares);
        SHORT getLinhas();
        int navegar(bool background = true, bool pagination = false, bool returnable = false);

        string input();

        template <typename T>
        T inputNumber() {
            if (entradas.size() == 0) return static_cast<T>(0);

            T retorno;

            info.bVisible = true;
            SetConsoleCursorInfo(telaOutput, &info);
            SetConsoleMode(telaInput, ENABLE_WINDOW_INPUT);

            DWORD cNumRead, fdwMode, i;
            INPUT_RECORD inputRecord;

            SHORT index = 0;
            SHORT posInicial = entradas[0].texto.size() + entradas[0].coluna;

            renderLinha(entradas[0], FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            string inputString = "";

            while (true) {
                COORD cursorPos { static_cast<SHORT>(posInicial + index), entradas[0].linha };
                SetConsoleCursorPosition(telaOutput, cursorPos);

                if (!ReadConsoleInput(
                    telaInput,
                    &inputRecord,
                    1,
                    &cNumRead
                )) {
                    // Nada acontece
                }

                if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
                    if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN) {
                        if (inputString.size() > 0) {
                            try {
                                if (is_integral<T>())
                                    retorno = stoi(inputString, nullptr, 10);
                                else if (is_floating_point<T>())
                                    retorno = stof(inputString);

                                if (retorno < 0)
                                    continue;

                                entradas.erase(entradas.begin());

                                info.bVisible = false;
                                SetConsoleCursorInfo(telaOutput, &info);
                                return retorno;
                            } catch (...) {
                                continue;
                            }
                        }

                        continue;
                    }

                    int caractere = inputRecord.Event.KeyEvent.uChar.AsciiChar;

                    if (caractere == 0)
                        continue;

                    if (caractere == 8) {
                        if (index > 0) {
                            inputString.pop_back();
                            renderChar(' ', posInicial + --index, entradas[0].linha);
                        }
                        continue;
                    }

                    inputString += char(caractere);

                    renderChar(caractere, posInicial + index++, entradas[0].linha);
                }
            }
        }

        void setTelas(vector<dadosTela> dadosTelas);
        void setTelas(int telas);
        void renderTexto(int tela = 0, vector<dadosTexto> linhasVector = {}, modoTexto horizontal = INICIO, modoTexto vertical = INICIO);
        void renderTela();
        void limparTela();
};

#endif
