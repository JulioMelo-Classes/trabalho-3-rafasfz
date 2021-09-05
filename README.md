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
15 10 7
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
15 10 1
##########
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#*       #
##########
```

No arquivo acima temos 2 níveis sendo o primeiro mapa com 15 linhas, 10 colunas, 7 comidas, e o segundo com 15 linhas, 10 colunas e 1 comida.

Agora no terminal dentro da pasta build execute o projeto usando o seguinte comando
```bash
./snaze {"nome do arquivo"} {"modo de jogo"} loop # caso queira jogar repetindo os levels
./snaze {"nome do arquivo"} {"modo de jogo"} # caso queira jogar 1 level por vez

#executando o arquivo no diretorio ../data/maze1.txt e no modo snake e com loop
./snaze ../data/maze1.txt snake loop

#executando o arquivo no diretorio ../data/maze1.txt e no modo pacman e sem loop
./snaze ../data/maze1.txt pacman
```
# trabalho-3-rafasfz
# trabalho-3-rafasfz
