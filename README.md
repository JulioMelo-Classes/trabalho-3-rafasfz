# LP1 Projeto 3

Neste projeto você irá fazer um simulador para o jogo snaze, melhores informações podem ser encontradas no [documento de especificação](https://www.overleaf.com/read/prcdstrjrdjr);

## Sistema de build

Escolha um dos sistemas de build que melhor agradar você, lembre que já vimos exemplos com [Makefile](https://www.gnu.org/software/make/manual/make.html) 
e [Cmake](https://cmake.org/). Esta versão usa compilação básica usando a linha de comando, mas fica a ~~obrigação~~ sugestão, caso você queira mudar.

## Organização

Este repositório tem algumas classes iniciais que podem te ajudar a fazer o projeto, porém, fique à vontade para explorar as possibilidades.

## Compilando e executando o projeto

```bash
  # Cria um clone do projeto
  git clone https://github.com/JulioMelo-Classes/trabalho-3-rafasfz.git

  # Entra na pasta de build do projeto
  cd trabalho-3-rafasfz/build

  # Compila o projeto
  cmake ..
  make
```

## Executando o projeto

Primeiramente crie um arquivo com as entradas do programa, siga o exemplo abaixo
```
15 10 2
##########
#      ###
# #### ###
# #    ###
# # ######
# # ######
# # ######
# # ######
# # ######
# #*######
# # ##   #
# #    # #
# ###### #
#        #
##########
```

Nesse caso o mapa sera com 15 linhas 10 colunas e 2 comidas

Agora no terminal dentro da pasta build execute o projeto usando o seguinte comando
```bash
./snaze {"nome do arquivo"} {"modo de jogo"}

#executando o arquivo no diretorio ../data/maze1.txt e no modo snake
./snaze ../data/maze1.txt snake

#executando o arquivo no diretorio ../data/maze1.txt e no modo pacman
./snaze ../data/maze1.txt pacman
```
# trabalho-3-rafasfz
# trabalho-3-rafasfz
