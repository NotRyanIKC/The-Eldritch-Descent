# 👾 Dungeon Crawler: The Eldritch Descent

## 📖 Descrição

Este é um jogo de **aventura/puzzle** em linguagem C, onde o jogador deve explorar mapas, interagir com objetos e evitar perigos para concluir **três fases** desafiadoras. Inspirado nos clássicos dos jogos de aventura, o jogo é jogado via terminal e utiliza símbolos ASCII para representar o cenário e os personagens.

## 🗝️ História do jogo: Eldritch Trials

    Em uma vila isolada, cercada por florestas sombrias e lendas esquecidas, existe uma caverna misteriosa chamada "A Boca do Rei". 
    Dizem que lá dentro está escondido o Tesouro Perdido de Eldrich, 
    o antigo rei que enlouqueceu e desapareceu nas profundezas há séculos.

    Segundo a tradição, todo mês um morador da vila é escolhido aleatoriamente para entrar na caverna e tentar recuperar o tesouro. Nenhum voltou.

    Agora... é a sua vez.

    Você é apenas um aldeão comum — sem armas, sem treinamento, sem chance. A única coisa que leva com você é a esperança de escapar.

    Dentro da caverna, tudo é traiçoeiro: espinhos, monstros, armadilhas. Vozes sussurram pelas paredes, testando sua sanidade.

## 🎯 Objetivo

O jogador precisa:
- Explorar os mapas de cada fase.
- Encontrar e interagir com a **chave (@)** para abrir a **porta (D → =)**.
- Evitar armadilhas, monstros e resolver pequenos desafios.
- Concluir todas as três fases para vencer o jogo.

## 🕹️ Controles

- `W` – Move o jogador para **cima**
- `A` – Move o jogador para **esquerda**
- `S` – Move o jogador para **baixo**
- `D` – Move o jogador para **direita**
- `i` – Interagir com o objeto embaixo do jogador

## 🔤 Elementos do Jogo

| Símbolo | Significado                            |
|---------|----------------------------------------|
| `&`     | Jogador                                |
| `P`     | NPC                                     |
| `*`     | Parede (bloqueia passagem)              |
| `@`     | Chave                                   |
| `D`     | Porta fechada                           |
| `=`     | Porta aberta                            |
| `O`     | Botão interativo                        |
| `#`     | Espinho                                 |
| `>`     | Teletransporte                          |
| `X`     | Monstro nível 1 (movimento aleatório)   |
| `V`     | Monstro nível 2 (segue o jogador)       |

## 🗺️ Estrutura das Fases

- **Vila (10x10)**  
  Tutorial com NPCs, paredes, chave e porta.

- **Fase 1 (10x10)**  
  Mapa simples com jogador, parede, chave e porta.

- **Fase 2 (20x20)**  
  Adiciona botão (`O`), espinhos (`#`) e monstro nível 1 (`X`).

- **Fase 3 (40x40)**  
  Introduz teletransporte (`>`), monstro nível 2 (`V`) e desafios mais complexos.

## 🧩 Telas do Jogo

- **Menu Principal**: Jogar | Créditos | Sair  
- **Créditos**: Lista os desenvolvedores do jogo  
- **Vila**: Introdução/tutorial com NPCs  
- **Fases 1-3**: Mapa, desafios e inimigos  
- **Vitória**: Parabeniza o jogador após vencer  
- **Derrota**: Exibe mensagem e retorna ao menu após falha

## 🧑‍💻 Como Jogar

1. Compile o código-fonte com um compilador C (ex: `gcc`).
2. Execute o jogo no terminal.
3. Use os controles para se mover e interagir.
4. Complete as três fases para vencer!

## 👥 Equipe de Desenvolvimento

- Ryan Cavalcanti  
- Pedro Augusto
- Luan Ramiro
