- [English](#english)
- [Português](#português)

# English

# So_long - 42

This project, So_long, is part of the curriculum at School 42. The goal of this project is to create a simple 2D game using the Minilibx library and the C programming language.

## Table of Contents

- [Features](#features)
- [How to Use](#how-to-use)
- [Building and Testing](#building-and-testing)
- [Credits](#credits)

## Features

The So_long game includes the following features:

- Player movement using WASD keys.
- Map rendering with walls, floor, and collectible items.
- Collectible items (e.g., books) that the player can pick up.
- Exit handling when the player reaches a certain point on the map.
- Simple graphics and input handling using Minilibx.

## How to Use

To play So_long or integrate it into your projects, follow these steps:

1. Clone the So_long repository:
   ```sh
   git clone https://github.com/rofnavarro/42-so_long.git
   cd 42-so_long
   ```

2. Compile the game:
   ```sh
   make
   ```

3. Run the game:
   ```sh
   ./so_long maps/map2.ber
   ```

4. Use WASD keys to move the player around the map.
5. Collect all the items and reach the exit to win the game.

## Building and Testing

The So_long project includes a `Makefile` that automates the compilation process. You can use the following commands:

- `make`: Compile the game.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the game executable.
- `make re`: Re-compile the game.

You can also test the game by creating custom maps (`.ber` files) and running the game with those maps to ensure everything works as expected.

## Credits
Image of player: "TheRealFusion & Manzana".
Edition of images: "Lala".

***

# Português

# So_long - 42

Este projeto, So_long, faz parte do currículo da Escola 42. O objetivo deste projeto é criar um jogo 2D simples usando a biblioteca Minilibx e a linguagem de programação C.

## Sumário

- [Funcionalidades](#funcionalidades)
- [Como Usar](#como-usar)
- [Compilação e Teste](#compilação-e-teste)
- [Créditos](#créditos)

## Funcionalidades

O jogo So_long inclui as seguintes funcionalidades:

- Movimentação do jogador usando as teclas de WASD.
- Renderização do mapa com paredes, piso e itens colecionáveis.
- Itens colecionáveis (como livros) que o jogador pode pegar.
- Tratamento de saída quando o jogador atinge um determinado ponto no mapa.
- Gráficos simples e manipulação de entrada usando Minilibx.

## Como Usar

Para jogar So_long ou integrá-lo em seus projetos, siga estas etapas:

1. Clone o repositório So_long:
   ```sh
   git clone https://github.com/rofnavarro/42-so_long.git
   cd 42-so_long
   ```

2. Compile o jogo:
   ```sh
   make
   ```

3. Execute o jogo:
   ```sh
   ./so_long maps/mapa2.ber
   ```

4. Use as teclas de WASD para movimentar o jogador pelo mapa.
5. Colete todos os itens e alcance a saída para vencer o jogo.

## Compilação e Teste

O projeto So_long inclui um `Makefile` que automatiza o processo de compilação. Você pode usar os seguintes comandos:

- `make`: Compila o jogo.
- `make clean`: Remove os arquivos de objeto.
- `make fclean`: Remove os arquivos de objeto e o executável do jogo.
- `make re`: Recompila o jogo.

Você também pode testar o jogo criando mapas personalizados (arquivos `.ber`) e executando o jogo com esses mapas para garantir que tudo funcione conforme o esperado.

## Créditos
Imagem do personagem: "TheRealFusion & Manzana".
Edição das imagens: "Lala".
