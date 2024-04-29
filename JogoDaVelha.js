function main() {
    // Criar o tabuleiro, jogadores e zerar as variáveis
    // 
    // 0: Posição vazia
    // 1: jogada na posição jogador 1
    // 2: jogada na posição jogador 2
    var velha;
    var linha;
    var coluna;

    // Limpar tabuleiro
    var i;
    var tabuleiro = createArray(9);

    for (i = 0; i <= 8; i++) {
        tabuleiro[i] = 0;
    }
    var jogada;

    // Iniciar o jogo, definir quem joga primeiro
    var jogadorDaVez;

    jogadorDaVez = 1;

    // Registrar a jogada dos jogadores
    var haVencedor;

    haVencedor = 0;
    velha = 1;
    do {
        window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
        window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
        window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
        window.alert("Digite a posição de sua peça JOGADOR" + jogadorDaVez);
        jogada = window.prompt('Enter a value for jogada');
        if (validaPosicao(jogada)) {
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));
            window.alert("Linha: " + linha + " ; Coluna: " + coluna);

            // Verificar se a posição 'jogada' é valida.
            // Converter a jogada texto em dois inteiros, linha e coluna
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;
                haVencedor = validatabuleiro(tabuleiro, jogadorDaVez);
                if (haVencedor == 0) {
                    if (jogadorDaVez == 1) {
                        jogadorDaVez = 2;
                    } else {
                        jogadorDaVez = 1;
                    }
                }

                // Se não houver vencedor ou empate, finalizar o jogo
                // Verificar jogada vencedora nas linhas
                velha = velha + 1;

                // Se não houver vencedor ou empate, finalizar o jogo
            } else {
                window.alert("Posição ocupada, jogue novamente!");

                // Informar ao Jogador 1 que a posição está preeenchida, é inválida e ele precisa informar uma posição válida
            }
        } else {
            window.alert("Jogada invalida");
        }

        // Simula a função Serial.parseint() do Arduino
    } while (haVencedor == 0 && velha <= 9);
    if (haVencedor != 0) {
        window.alert("Parabéns pela vitória, jogador " + jogadorDaVez);
    } else {
        window.alert("Deu velha!!");
    }
}

function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
    window.alert(entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function validatabuleiro(tabuleiro, jogadorDaVez) {
    var vencedor;

    vencedor = 0;
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        vencedor = 2;
    } else {

        // Verificar jogada vencedora nas colunas
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            vencedor = 2;
        } else {

            // Verificar jogada vencedora nas diagonais
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                vencedor = 2;
            }
        }
    }
    
    return vencedor;
}
