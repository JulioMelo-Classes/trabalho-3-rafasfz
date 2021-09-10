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
./snaze {"nome do arquivo"} {"modo de jogo"}

#executando o arquivo no diretorio ../data/maze1.txt e no modo snake
./snaze ../data/maze1.txt snake

#executando o arquivo no diretorio ../data/maze1.txt e no modo pacman
./snaze ../data/maze1.txt pacman
```
# trabalho-3-rafasfz
# trabalho-3-rafasfz

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Acho que o trabalho está muito bem adiantado, provavelmente vai ser tranquilo implementar o CP2 ou quebrar a cabeça com ele com tudo que você já entregou.
- Acho que você misturou um pouco das funcionalidades lá no update/process_actions, se você quiser melhorar o código uma boa seria tentar separar melhor o que são decisões da classe Player, que devem ficar no process_actions, e o que são atualizações do jogo que devem ficar no render.
