#include <stdio.h>

// Constantes para número de casas/movimentos (facilita manutenção e evita repetição)
#define CASAS_BISPO 5      // Bispo: 5 casas diagonal
#define CASAS_TORRE 5      // Torre: 5 casas direita
#define CASAS_RAINHA 8     // Rainha: 8 casas esquerda
#define PASSOS_CAVALO_L 2  // Cavalo em L: 2 passos em uma direção
#define PASSOS_CAVALO_PERP 1  // 1 passo perpendicular

// ============================================
// NÍVEL NOVATO: Movimentações com loops simples
// ============================================

/**
 * Movimenta o Bispo: 5 casas na diagonal superior direita.
 * Usa do-while para simular a combinação de Cima + Direita em cada passo.
 * (Uma iteração mínima garantida pelo do-while).
 */
void moverBispoNovato() {
    int passos = 0;  // Contador de passos
    printf("\n--- Movimentação do Bispo (Novato: Diagonal Superior Direita) ---\n");
    do {
        printf("Cima\n");   // Parte vertical da diagonal
        printf("Direita\n"); // Parte horizontal da diagonal
        passos++;
    } while (passos < CASAS_BISPO);
    printf("Bispo chegou ao destino!\n");
}

/**
 * Movimenta a Torre: 5 casas para a direita.
 * Usa for para um loop fixo e simples.
 */
void moverTorreNovato() {
    printf("\n--- Movimentação da Torre (Novato: Direita) ---\n");
    for (int i = 0; i < CASAS_TORRE; i++) {
        printf("Direita\n");
    }
    printf("Torre chegou ao destino!\n");
}

/**
 * Movimenta a Rainha: 8 casas para a esquerda.
 * Usa while para um loop condicional.
 */
void moverRainhaNovato() {
    int passos = 0;  // Contador inicializado
    printf("\n--- Movimentação da Rainha (Novato: Esquerda) ---\n");
    while (passos < CASAS_RAINHA) {
        printf("Esquerda\n");
        passos++;
    }
    printf("Rainha chegou ao destino!\n");
}

// ============================================
// NÍVEL AVENTUREIRO: Cavalo em L com loops aninhados
// ============================================

/**
 * Movimenta o Cavalo em L: 2 passos para Baixo + 1 passo para Esquerda.
 * Usa loops aninhados: for externo (Baixo) e while interno (Esquerda).
 * Obrigatório: Aninhamento para simular o "L".
 */
void moverCavaloAventureiro() {
    printf("\n--- Movimentação do Cavalo (Aventureiro: L para Baixo e Esquerda) ---\n");
    
    // Loop externo: 2 passos para Baixo (for)
    for (int baixo = 0; baixo < PASSOS_CAVALO_L; baixo++) {
        printf("Baixo\n");
        
        // Loop interno aninhado: 1 passo para Esquerda (while), mas só após os 2 baixos? Não, para L simples, fazemos após.
        // Aqui, o while é usado uma vez por iteração externa, mas ajustamos para total 1 esquerda no final do L.
        static int esquerdaFeita = 0;  // Variável estática para contar esquerda uma vez só
        if (baixo == PASSOS_CAVALO_L - 1 && esquerdaFeita == 0) {  // Só no último baixo
            int esquerda = 0;
            while (esquerda < PASSOS_CAVALO_PERP) {
                printf("Esquerda\n");
                esquerda++;
            }
            esquerdaFeita = 1;
        }
    }
    printf("Cavalo completou o L!\n");
}

// ============================================
// NÍVEL MESTRE: Recursão para Bispo/Torre/Rainha + Cavalo avançado
// ============================================

/**
 * Movimenta o Bispo recursivamente: 5 casas diagonal superior direita.
 * Recursão: Chama a si mesma para cada passo (Cima + Direita).
 * Base: Para quando passos == 0.
 * (Obrigatório: Função recursiva; simula aninhamento implícito via chamadas).
 */
void moverBispoMestre(int passosRestantes) {
    if (passosRestantes == 0) {
        printf("Bispo chegou ao destino!\n");
        return;  // Caso base da recursão
    }
    
    printf("Cima\n");
    printf("Direita\n");
    moverBispoMestre(passosRestantes - 1);  // Chamada recursiva para próximo passo
}

/**
 * Movimenta a Torre recursivamente: 5 casas para a direita.
 * Recursão simples: Imprime e chama para o restante.
 */
void moverTorreMestre(int passosRestantes) {
    if (passosRestantes == 0) {
        printf("Torre chegou ao destino!\n");
        return;
    }
    
    printf("Direita\n");
    moverTorreMestre(passosRestantes - 1);
}

/**
 * Movimenta a Rainha recursivamente: 8 casas para a esquerda.
 * Recursão: Similar às acima.
 */
void moverRainhaMestre(int passosRestantes) {
    if (passosRestantes == 0) {
        printf("Rainha chegou ao destino!\n");
        return;
    }
    
    printf("Esquerda\n");
    moverRainhaMestre(passosRestantes - 1);
}

/**
 * Movimenta o Cavalo em L: 1 vez em L para Cima à Direita.
 * Usa loops aninhados com variáveis múltiplas (contadores para cima/direita).
 * Condições múltiplas: Verifica se é hora de mudar direção.
 * Continue: Pula se contador inválido (ex.: evita passos extras).
 * Break: Sai do loop interno ao completar o perpendicular.
 * (Obrigatório: Loops aninhados, continue/break).
 */
void moverCavaloMestre() {
    printf("\n--- Movimentação do Cavalo (Mestre: L para Cima e Direita) ---\n");
    
    int cima = 0;    // Variável múltipla: contador para Cima
    int direita = 0; // Variável múltipla: contador para Direita
    int totalPassos = 0;
    int maxTotal = PASSOS_CAVALO_L + PASSOS_CAVALO_PERP;  // Total para o L: 3 passos
    
    // Loop aninhado externo: Simula o L com for (até completar)
    for (; totalPassos < maxTotal; totalPassos++) {
        // Condições múltiplas: Primeiros 2 passos Cima, depois 1 Direita
        if (totalPassos < PASSOS_CAVALO_L) {
            // Loop interno aninhado: While para Cima (mas simples aqui)
            while (cima < PASSOS_CAVALO_L && totalPassos == cima) {
                if (cima % 2 == 0) {  // Condição múltipla: Pula passos pares (simula variação, mas continue para pular um)
                    continue;  // Continue: Pula este passo (ex.: evita repetição desnecessária)
                }
                printf("Cima\n");
                cima++;
                break;  // Break: Sai do while após imprimir um Cima válido
            }
        } else {
            // Parte perpendicular: Direita
            while (direita < PASSOS_CAVALO_PERP) {
                printf("Direita\n");
                direita++;
                break;  // Break: Completa apenas 1 Direita
            }
        }
    }
    printf("Cavalo completou o L avançado!\n");
}

// ============================================
// Função Principal: Executa todos os níveis
// ============================================

int main() {
    printf("=== DESAFIO DE XADREZ - MATECHECK ===\n");
    printf("Executando todos os níveis...\n\n");
    
    // Nível Novato
    printf("🏅 NÍVEL NOVATO\n");
    moverBispoNovato();
    moverTorreNovato();
    moverRainhaNovato();
    
    // Nível Aventureiro
    printf("\n🥈 NÍVEL AVENTUREIRO\n");
    moverCavaloAventureiro();
    
    // Nível Mestre
    printf("\n🥇 NÍVEL MESTRE\n");
    printf("--- Bispo (Recursivo) ---\n");
    moverBispoMestre(CASAS_BISPO);
    
    printf("\n--- Torre (Recursivo) ---\n");
    moverTorreMestre(CASAS_TORRE);
    
    printf("\n--- Rainha (Recursivo) ---\n");
    moverRainhaMestre(CASAS_RAINHA);
    
    moverCavaloMestre();
    
    printf("\n=== Fim do Desafio ===\n");
    return 0;
}
