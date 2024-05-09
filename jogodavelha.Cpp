int velha;
int linha;
int coluna;
int index;
bool haVencedor;
int tabuleiro[9];
String jogada;
int jogadorDaVez;
String jogador1 = "Jogador 1";
String jogador2 = "Jogador 2";

int getValArrayInt(int linha, int coluna, int matriz[], int qtdeLinhas) {
  int valor;

  valor = matriz[qtdeLinhas * linha + coluna];

  return valor;
}
bool validaPosicao(int linha, int coluna) {
  if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2) {
    if (tabuleiro[3 * linha + coluna] == 0) {
      return true;
    }
  }
  return false;
}
// Criar o tabuleiro e jogadores, zerar as variáveis.
//
// 0: Posição vazia
// 1: jogada na Posição do jogador 1
// 2: jogada na Posição do jogador 2

// Limpar/zerar o tabuleiro

// Anotar/Registrar a jogada, do primeiro jogador
void setup() {
  Serial.begin(112500);
}

void loop() {
  haVencedor = false;
  velha = 1;
  for (index = 0; index <= 8; index++) {
    tabuleiro[index] = 0;
  }

  // Iniciar o jogo, definir quem joga primeiro
  jogadorDaVez = 1;

  do {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);
    jogada = "";
    Serial.print("Digite a posição da sua peça JOGADOR ");
    Serial.println(jogadorDaVez);

    while (!Serial.available())
      ;

    jogada = Serial.readString();

    linha = int(jogada[0]) - '0';
    coluna = int(jogada[2]) - '0';

    if (validaPosicao(linha, coluna)) {

      // Converter a jogada texto em dois inteiros linha e coluna.
      // Simula a função Serial.parseInt() do Arduino

      Serial.print("Linha: ");
      Serial.println(linha);
      Serial.print("Coluna: ");
      Serial.println(coluna);

      // Verificar se a posição 'jogada' é valida
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {

          // Verificar a jogada vencedora nas colunas.
          if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            haVencedor = true;
          } else {

            // Verificar a jogada vencedora nas diagonais.
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
              haVencedor = true;
            } else {

              // Trocar o jogador
              if (jogadorDaVez == 1) {
                jogadorDaVez = 2;
              } else {
                jogadorDaVez = 1;
              }
            }
          }
        }
        velha++;
      } else {
        Serial.println("Posição ocupada, jogue novamente !!!");

        // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar um posição válida.
      }
    } else {
      Serial.println("Jogada inválida !!!");
    }

    // Verificar a jogada vencedora nas linhas.
  } while (!haVencedor && velha <= 9);
  // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
  if (haVencedor) {
    Serial.print("Parabéns pela a vitória, jogador ");
    Serial.println(jogadorDaVez);
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);
    Serial.println(" ");
    Serial.println("Novo jogo!");
  } else {
    Serial.println("Deu VELHA!!!");
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);
    Serial.println(" ");
    Serial.println("Novo jogo!");
  }
}
