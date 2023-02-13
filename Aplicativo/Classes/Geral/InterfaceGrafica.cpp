#include "InterfaceGrafica.h"

std::wstring stringToWideString(const char* utf8Bytes) {
    const std::string& str(utf8Bytes);
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

InterfaceGrafica::InterfaceGrafica() {
    info.dwSize = 100;
    info.bVisible = false;
    SetConsoleCursorInfo(telaOutput, &info);
}

void InterfaceGrafica::limparTela(int tela) {
    SHORT colunasTela = colunasTelas[tela].second - colunasTelas[tela].first - 2;
    SHORT linhasTela = linhas - 2;

    DWORD caracteresEscritos;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo( telaOutput, &csbi )) return;

    for (unsigned i = 0; i < linhasTela; i++) {
        if (!FillConsoleOutputCharacter(
        telaOutput,
        (TCHAR) ' ',
        colunasTela,
        {
            static_cast<SHORT>(colunasTelas[tela].first + 1),
            static_cast<SHORT>(i + 1)
        },
        &caracteresEscritos
        )) return;

        if (!FillConsoleOutputAttribute(
            telaOutput,
            csbi.wAttributes,
            colunasTela,
            {
                static_cast<SHORT>(colunasTelas[tela].first + 1),
                static_cast<SHORT>(i + 1)
            },
            &caracteresEscritos
        )) return;
    }
}

void InterfaceGrafica::renderChar(int caractere, SHORT coluna, SHORT linha) {
    CHAR_INFO charBuf[1];
    COORD charBufSize = { 1, 1 };
    COORD charPos = { 0, 0 };

    SMALL_RECT areaEscrita = { coluna, linha, coluna, linha };

    charBuf[0].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    charBuf[0].Char.AsciiChar = caractere;

    WriteConsoleOutputA(telaOutput, charBuf, charBufSize, charPos, &areaEscrita);
}

void InterfaceGrafica::renderLinha(manipulavel linhaManipulavel, WORD atributos) {
    CHAR_INFO charBuf[linhaManipulavel.texto.size()];
    COORD charBufSize = { static_cast<SHORT>(linhaManipulavel.texto.size()), 1};
    COORD charPos = { 0, 0 };

    SMALL_RECT areaEscrita = {
        linhaManipulavel.coluna,
        linhaManipulavel.linha,
        static_cast<SHORT>(linhaManipulavel.coluna + linhaManipulavel.texto.size()),
        linhaManipulavel.linha
    };

    for (unsigned i = 0; i < linhaManipulavel.texto.size(); i++) {
        charBuf[i].Attributes = atributos;
        charBuf[i].Char.UnicodeChar = linhaManipulavel.texto.c_str()[i];
    }

    WriteConsoleOutputW(telaOutput, charBuf, charBufSize, charPos, &areaEscrita);
}

void InterfaceGrafica::setTextosAuxiliares(vector<vector<string>> textosAuxiliares) {
    this->textosAuxiliares = textosAuxiliares;
}

SHORT InterfaceGrafica::getLinhas() {
    return this->linhas;
}

int InterfaceGrafica::navegar(bool background, bool pagination, bool returnable) {
    if (navegaveis.size() == 0) return -1;

    SetConsoleMode(telaInput, ENABLE_WINDOW_INPUT);

    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD inputRecord;

    int index = 0;

    renderLinha(navegaveis[0], FOREGROUND_GREEN | FOREGROUND_INTENSITY | (background ? BACKGROUND_BLUE : 0));

    if (textosAuxiliares.size() > index) {
        vector<dadosTexto> textos;

        for (unsigned i = 0; i < textosAuxiliares[index].size(); i++)
            textos.push_back({ textosAuxiliares[index][i] });

        if (this->colunasTelas.size() > 1) {
            this->limparTela(1);
            this->renderTexto(1, textos);
        }
    }

    while (true) {
        if (!ReadConsoleInput(
            telaInput,
            &inputRecord,
            1,
            &cNumRead
        )) {
            // Mensagem ou Throw de Erro ou Nada
        }

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            switch(inputRecord.Event.KeyEvent.wVirtualKeyCode) {
                // Seta Cima
                case VK_UP:
                    if (index == 0) break;

                    renderLinha(navegaveis[index], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    renderLinha(navegaveis[--index], FOREGROUND_GREEN | FOREGROUND_INTENSITY | (background ? BACKGROUND_BLUE : 0));

                    if (textosAuxiliares.size() > index) {
                        vector<dadosTexto> textos;

                        for (unsigned i = 0; i < textosAuxiliares[index].size(); i++)
                            textos.push_back({ textosAuxiliares[index][i] });

                        if (this->colunasTelas.size() > 1) {
                            this->limparTela(1);
                            this->renderTexto(1, textos);
                        }
                    }


                    break;
                // Seta Baixo
                case VK_DOWN:
                    if (index == navegaveis.size() - 1) break;

                    renderLinha(navegaveis[index], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    renderLinha(navegaveis[++index], FOREGROUND_GREEN | FOREGROUND_INTENSITY | (background ? BACKGROUND_BLUE : 0));

                    if (textosAuxiliares.size() >= index) {
                        vector<dadosTexto> textos;

                        for (unsigned i = 0; i < textosAuxiliares[index].size(); i++)
                            textos.push_back({ textosAuxiliares[index][i] });

                        if (this->colunasTelas.size() > 1) {
                            this->limparTela(1);
                            this->renderTexto(1, textos);
                        }
                    }

                    break;
                // Seta Esquerda
                case VK_LEFT:
                    if (!pagination) break;
                    return -1;
                // Seta Direita
                case VK_RIGHT:
                    if (!pagination) break;
                    return -2;
                // Backspace:
                case VK_BACK:
                   if (!returnable) break;
                   return -3;
                // Enter
                case VK_RETURN:
                    return index;
            }
        }
    }
}

string InterfaceGrafica::input() {
    if (entradas.size() == 0) return "";

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
            // Mensagem ou Throw de Erro ou Nada
        }

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN) {
                if (inputString.size() > 0) {
                    entradas.erase(entradas.begin());
                    info.bVisible = false;
                    SetConsoleCursorInfo(telaOutput, &info);
                    return inputString;
                }

                continue;
            }

            int caractere = inputRecord.Event.KeyEvent.uChar.AsciiChar;

            /*
                Ao colocar acentuação, como em primeira instância o valor
                ele não é inserido, o Sistema detecta a Key apertada como 0,
                e para evitar espaços vazios na linha de input, é necessário
                tratar essa ocasião.
            */
            if (caractere == 0)
                continue;

            /*
                Devido a utilização do WriteConsoleInput, o valor 0x8 é visto
                como um símbolo e não como o backspace em si, fazendo com que
                se seja necessário tratar esse valor e posicionar o cursor na
                tela de maneira correta.
            */
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

void InterfaceGrafica::setTelas(vector<dadosTela> dadosTelas) {
    colunasTelas.clear();

    CONSOLE_SCREEN_BUFFER_INFO infoConsole;

    GetConsoleScreenBufferInfo(telaOutput, &infoConsole);
    this->colunas = infoConsole.srWindow.Right - infoConsole.srWindow.Left + 1;
    this->linhas = infoConsole.srWindow.Bottom - infoConsole.srWindow.Top + 1;

    for (auto tela: dadosTelas)
        if (tela.tamanho == 0)
            throw invalid_argument("Nem todos os valores foram passados corretamente!");

    float somaTamanhos = accumulate(dadosTelas.begin(), dadosTelas.end(), 0.0,
        [](float acc, dadosTela a) {
            return acc + a.tamanho;
        }
    );

    /*
        Calcular posição relativa de cada tela
            - Limitado a telas lateralmente paralelas apenas
    */
    for (unsigned i = 0; i < dadosTelas.size(); i++) {
        titulos.push_back(dadosTelas[i].titulo);

        if (i == 0) {
            colunasTelas.push_back(
                make_pair(
                    0,
                    dadosTelas[i].tamanho / somaTamanhos * this->colunas
                )
            );
            continue;
        }

        if (i == dadosTelas.size() - 1) {
            colunasTelas.push_back(
                make_pair(
                    colunasTelas[i - 1].second,
                    this->colunas
                )
            );
            continue;
        }

        colunasTelas.push_back(
            make_pair(
                colunasTelas[i - 1].second,
                (dadosTelas[i].tamanho / somaTamanhos * this->colunas) + colunasTelas[i - 1].second + 1
            )
        );
    }
}

void InterfaceGrafica::setTelas(int telas) {
    colunasTelas.clear();
    vector<dadosTela> dadosTelas;

    for (unsigned i = 0; i < telas; i++)
        dadosTelas.push_back( dadosTela { "", static_cast<float>(100.0 / telas) });

    this->setTelas(dadosTelas);
}

void InterfaceGrafica::renderTexto(int tela, vector<dadosTexto> linhasVector, modoTexto horizontal, modoTexto vertical) {
    SHORT telaInicio = colunasTelas[tela].first;
    SHORT telaFim = colunasTelas[tela].second;
    SHORT quantidadeColunas = telaFim - telaInicio;

    SHORT posLinha;

    switch (vertical) {
        case INICIO:
            posLinha = 2;
            break;

        case MEIO:
            posLinha = (linhas - linhasVector.size()) / 2;
            break;

        case FIM:
            posLinha = linhas - linhasVector.size() - 2;
            break;
    }

    for (unsigned i = 0; i < linhasVector.size(); i++) {
        wstring linha = stringToWideString(linhasVector[i].texto.c_str());

        CHAR_INFO charBuf[linha.size()];
        COORD charBufSize = { static_cast<SHORT>(linha.size()), 1 };
        COORD charPos = { 0, 0 };

        SHORT colunaInicio;

        switch (horizontal) {
            case INICIO:
                colunaInicio = (colunasTelas[tela].first + 2);
                break;

            case MEIO:
                colunaInicio = (colunasTelas[tela].first + colunasTelas[tela].second - linha.size()) / 2;
                break;

            case FIM:
                SHORT colunaInicio = (colunasTelas[tela].second - linha.size() - 2);
                break;
        }

        SHORT colunaFim = colunaInicio + linha.size();

        if (linhasVector[i].navegavel == true)
            navegaveis.push_back( manipulavel { linha, static_cast<SHORT>(posLinha + i), colunaInicio } );

        if (linhasVector[i].entrada == true) {
            entradas.push_back( manipulavel { linha, static_cast<SHORT>(posLinha + i), colunaInicio } );
            continue;
        }

        SMALL_RECT areaEscrita = { colunaInicio, static_cast<SHORT>(posLinha + i), colunaFim, static_cast<SHORT>(posLinha + i) };

        for (unsigned i = 0; i < linha.size(); i++) {
            charBuf[i].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            charBuf[i].Char.UnicodeChar = linha.c_str()[i];
        }

        WriteConsoleOutputW(telaOutput, charBuf, charBufSize, charPos, &areaEscrita);
    }
}

void InterfaceGrafica::renderTela() {
    for (unsigned i = 0; i < colunasTelas.size(); i++) {
        SHORT colunaInicio = colunasTelas[i].first;
        SHORT colunaFim = colunasTelas[i].second;
        SHORT quantColunas = colunaFim - colunaInicio;

        CHAR_INFO horCharBuf[quantColunas];
        COORD tamanhoCharBuf = { quantColunas, 1 };
        COORD posCaractere = { 0, 0 };

        SMALL_RECT areaEscrita = { colunaInicio, static_cast<SHORT>(linhas - 1), colunaFim, static_cast<SHORT>(linhas - 1) };

        horCharBuf[0].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        horCharBuf[quantColunas - 1].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

        horCharBuf[0].Char.UnicodeChar = 9492;
        horCharBuf[quantColunas - 1].Char.UnicodeChar = 9496;

        // Desenhar Horizontalmente
        for (unsigned j = 1; j < quantColunas - 1; j++) {
            horCharBuf[j].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            horCharBuf[j].Char.UnicodeChar = 9472;
        }

        WriteConsoleOutputW(telaOutput, horCharBuf, tamanhoCharBuf,  posCaractere, &areaEscrita);

        areaEscrita = { colunaInicio, 0, colunaFim, 0 };

        horCharBuf[0].Char.UnicodeChar = 9484;
        horCharBuf[quantColunas - 1].Char.UnicodeChar = 9488;

        if (titulos.size() >= i && titulos[i].size() > 0) {
            wstring wideString = stringToWideString(titulos[i].c_str());

            for (unsigned j = 0; j < wideString.size(); j++) {
                horCharBuf[2].Char.UnicodeChar = ' ';
                horCharBuf[j + 3].Char.UnicodeChar = wideString.c_str()[j];
                horCharBuf[wideString.size() + 3].Char.UnicodeChar = ' ';
            }
        }

        WriteConsoleOutputW(telaOutput, horCharBuf, tamanhoCharBuf,  posCaractere, &areaEscrita);

        CHAR_INFO vertCharBuf[linhas - 2];
        tamanhoCharBuf = { 1, static_cast<SHORT>(linhas - 2) };

        // Desenhar Verticalmente
        for (unsigned j = 0; j < linhas - 2; j++) {
            vertCharBuf[j].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            vertCharBuf[j].Char.UnicodeChar = 9474;
        }

        areaEscrita = { colunaInicio, 1, colunaInicio, static_cast<SHORT>(linhas - 1) };
        WriteConsoleOutputW(telaOutput, vertCharBuf, tamanhoCharBuf,  posCaractere, &areaEscrita);

        areaEscrita = { static_cast<SHORT>(colunaFim - 1), 1, static_cast<SHORT>(colunaFim - 1), static_cast<SHORT>(linhas - 1) };
        WriteConsoleOutputW(telaOutput, vertCharBuf, tamanhoCharBuf,  posCaractere, &areaEscrita);
    }
}

void InterfaceGrafica::limparTela() {
    navegaveis.clear();
    entradas.clear();
    titulos.clear();

    DWORD caracteresEscritos;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo( telaOutput, &csbi )) return;

    if (!FillConsoleOutputCharacter(
        telaOutput,
        (TCHAR) ' ',
        colunas * linhas,
        { 0, 0 },
        &caracteresEscritos
    )) return;

    if (!FillConsoleOutputAttribute(
    telaOutput,
    csbi.wAttributes,
    colunas * linhas,
    { 0, 0 },
    &caracteresEscritos
    )) return;
}
