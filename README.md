<div align = "center" >
<img src="./DFS/img/GraphIMG.png" height="35%" width="35%">
</div>

<div align="justify">

<div align="center">

# Busca em Largura e Profundidade

#### Algoritmos e Estrutura de Dados

#### Compatibilidade e Desenvolvimento
![Vscode](https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white) 
![C](https://img.shields.io/badge/-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)  

</div>

## Índice
 - [Introdução](#Introdução)
    - [Contextualizando os Algoritmos](#contextualizando-os-algoritmos)

 - [Fundamentação Teórica](#Fundamentação-Teórica)
    - [Estruturas de Dados](#Estruturas-de-Dados)
    - [Algoritmos](#Algoritmos)
        - [DFS em Grafos](#DFS-em-Grafos)
        - [DFS em Matrizes Bidimensionais](#DFS-em-Matrizes-Bidimensionais)
        - [BFS em Grafos](#BFS-em-Grafos)
        - [BFS em Matrizes Bidimensionais](#BFS-em-Matrizes-Bidimensionais)

 - [Objetivos](#Objetivos)

 - [Metodologia](#Metodologia)
    - [Solução](#Solução)
        - [Arquivos](#Arquivos)
            -[Primeira Leitura do Arquivo)](#1-Primeira-Leitura-do-Arquivo)
            -[Percorrendo a Matriz](#1-Percorrendo-a-Matriz)
                -[Casos especiais](#2.1-Casos-especiais)
                -[Implementação](#2.2-Percorrendo-a-Matriz)
    
    
- [Conclusão](#Conclusão)
    - [Por Qual Motivo Utilizar Matrizes Bidimensionais?
](#Conclusão)
    - [Reavaliando a Implementação do Algoritmo em Matrizes bidimensionais](#Conclusão)
- [Referências](#Referências)


- [Compilação e Execução](#Compilação-e-Execução)
- [Ambiente de Desenvolvimento](#Ambiente-de-Desenvolvimento)
<br><br>

## Introdução
Este repositório apresenta  a solução para um problema proposto na disciplina de Algoritmos e Estruturas de Dados. Para isso foi requisitado que a solução fosse desenvolvida em forma de 3 algoritmos, são eles o DFS(Deep First Search, ou Busca em Profundidade), o BFS(Brandth First Search ou Busca em Largura) e uma forma de realizar buscas escolhendo entre casas adjascentes aleatoriamente. Para isso considere as seguintes colocações:

- Nomes de diretórios, ou arquivos serão referênciados da seguinte forma: `Nome.txt` ou `Diretório_2`.

- $G$ - Um grafo qualquer.

- $V$ - Conjunto de vértices de um grafo.

- $E$ - Conjunto de arestas de um grafo.

- $n_{v}$ - Número de vértices em um percurso.

- $n_{e}$ - Número de arestas em um percurso.

- $K$ - Número de matrizes de entrada presentes no arquivo `input.data`.

- $N$ - Ordem das matrizes sendo representada pelos 2 primeiros números da primeira linha do arquivo `input.data`, portanto o código já espera que $N \in \mathbb{Z}$ e $N\geq 0$ e não trata essa variável.

- $i$ - Índice da linha de uma matriz, também pode ser abstraído como deslocamento na vertical, tal que $i \geq 0$ e $i \in \mathbb{Z}$.

- $j$ - Índice da coluna de uma matriz, também pode ser abstraído como deslocamento na horizontal, tal que $j \geq 0$ e $j \in \mathbb{Z}$.

- $a_{ij}$ - Elemento encontrado quando há deslocamento até a linha de índice $i$ e coluna de índice $j$.

- _Tralha ou jogo da velha_ - **Parede**: Local onde não se pode passar dentro de uma matriz.

- $*$ - **Perigo**: Local onde ao se passar haverá descrescimento em 1 da variável vida.

- $a_{ij}$ - Elemento encontrado quando há deslocamento até a linha de índice $i$ e coluna de índice $j$.

- $?$ - Elemento encontrado durante o percorrimento da matriz que representa o encerramento de uma pesquisa ou a saída do labirinto.



- Nomes de comandos digitados no terminal,funções ou variáveis serão referênciados da seguinte forma: _**touch main.cpp**_, _**make run**_.

- Para as **Figuras** de **1** à **x**, considere a legenda de cores:



    -   Azul:Uma posição futura possível.</kbd>
    -   Cinza: Uma posição futura impossível.
    -   Laranja: Posição atual ou inicial.
    -   Rosa: Posição futura escolhida.

## Fundamentação Teórica
- Para contextualizar o funcionamento do algoritmo, considere que um personagem caminha por um labirinto até encontrar uma saída definida por um ponto de interrogação($?$):
    - O personagem representa uma abstração para uma busca realizada em uma matriz, essa busca se encerra quando o elemento $?$ é encontrado.
    -   O caracter $*$ representa uma casa que reiniciar a pesquisa. Isso significa que, se o personagem passa pelo elemento $a_{ij} = *$, este haverá de reiniciar sua busca da posição $a_{00}$. Além disso o caminho entre $a_{ij}$ e $a_{00}$ será considerado como não percorrido e $a_{ij} = *$ será transformado em $a_{ij} = 1$. 
    -   A parede representa uma casa por onde o ambicioso não consegue passar.
    
### Estruturas de Dados
- Para solucionar o problema a equipe usufruiu da alocação dos valores de entradas em elementos $a_{ij}$ de uma matriz $M$ de ordem $N$. Portanto a estrutura de dados utilizada foi uma matriz $N$ x $N$.

### Algoritmos
-  Os algoritmos para guiar o personagem idealizado, são buscas em largura e em profundidade. Estes algoritmos serão executados nas matrizes bidimensionais utilizadas como entradas no arquivo _`input.data`_.

#### Travessia ou Busca em Grafos
- O entendimento dos algoritmos DFS e BFS tem grande importância no estudo de algoritmos e estruturas de dados. No estudo de grafos por exemplo, consideramos DFS e BFS formas de percorrer grafos em busca da validação de um percurso entre dois vértices, contagem de trilhas, circuitos e outras inferências sobre estes objetos computacionais.

#### DFS em Grafos
- Considerando um passeio realizado em um grafo finito, DFS funciona da seguinte forma. Dado um vértice raiz, ou vértice de início, 1 vértice filho se torna o próximo vértice atual até que não hajam mais vértices filhos vizinhos inexplorados. Após isso o vértice raiz se torna o atual novamente e um novo percurso se inicia. Como pode ser visto um passeio com DFS no grafo abaixo segue a ordem formalmente representada como ${Passeio}: (0, 1, 2, 3, 5, 6)$.


<div align = "center" >
<br>
<strong>Figura 1 -</strong> DFS no Grafo
<br>
<img src="./DFS/img/DFS_Walk.png" height="78%" width="78%">
<br>
Fonte: Construção pelo autor¹.
<br>
____________________________________________
<br>Criada usando o Canva assistir ao vídeo¹, Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>


<br>
Observa-se que os vértices circulados de vermelho na imagem são vértices com adjascencia em vértices já visitados. Agora observe o vídeo abaixo:

<div align = "center" >
<br>
<strong>Vídeo 1 -</strong> DFS no Grafo
<br>
<img src="./DFS/img/DFS.gif" height="78%" width="78%">
<br>
Fonte: Construção pelo autor².
<br>
____________________________________________
<br>Criada usando o graphonline após assistir ao vídeo¹, Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>


<br>


#### DFS em Matrizes Bidimensionais
- Já em matrizes bidimensionais a DFS percorre uma linha ou coluna até que encontre um caracter que a faça reorientar a busca em outra direção(A reorientação acontece quando a busca identifica uma parede ou posição já percorrida anteriormente, portanto não se moverá para lá). As direções escolhidas não podem fazer com que a busca passe em um elemento da matriz que já foi visitado previamente. Observe como a DFS percorre um coluna por completo e tem uma seta vermelha representando que não pode se mover para $a_{10}$ pois essa posição já foi percorrida previamente.

<div align = "center" >
<br>
<strong>Figura 2 -</strong> DFS em Matriz
<br>
<img src = "./DFS/img/DFS_MATRIX.png">
<br>
Fonte: Construção pelo autor³.
<br>
____________________________________________
<br>Criada usando o Canva¹, Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>

#### BFS em Grafos

- Considerando um passeio realizado em um grafo finito, BFS funciona da seguinte forma. Dado um vértice raiz, ou vértice de início, cada um de seus vértices adjascentes serão explorados e usados como próximos vértices atuais.Tendo estes como vértices vizinhos, na nova iteração estes terão seus adjascentes como percorridos e assim sucessivamente. A busca em largura encerra quando todos os vértices de um grafo tiverem sido percorridos.Um fato interessante do BFS é que a pesquisa em largura permite inferir qual o menor caminho entre dois vértices no momento em que ambos estiverem sido percorridos na busca.Observe como isso acontece no vídeo e na imagem abaixo ${Passeio}: (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)$. Considere que na imagem houveram apenas 3 iterações de busca em largura.

<div align = "center" >
<br>
<strong>Figura 3 -</strong> BFS no Grafo
<br>
<img src = "./DFS/img/BFS_walk.png" height = "78%" width = "78%">

<br>
Fonte: Construção pelo autor⁴.
<br>
____________________________________________
<br>Criada usando o Canva assistir ao vídeo², Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>

<br>
 
 - Observa-se que em 3 iterações utilizando o BFS,é possível inferir a menor distância entre alguns $v0$ e $v3$ ou $v0$ e $v4$. Mais especificamente a ditância é de 2 arestas nos respectivos percursos $P_{v0,v4} = (0,1,4)$ ou $P_{v0,v3} = (0,2,3)$. Faça um exercício e tente observar este padrão se repetindo no vídeo abaixo:

<div align = "center" >
<br>
<strong>Vídeo 2 -</strong> BFS no Grafo
<br>
<img src="./DFS/img/BFS.gif" height="78%" width="78%">
<br>
Fonte: Construção pelo autor⁵.
<br>
____________________________________________
<br>Criada usando o graphonline após assistir ao vídeo², Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>

<br>

#### BFS em Matrizes Bidimensionais

- Já em matrizes bidimensionais a BFS percorre todas as casas adjascentes à(s) casa(s) presente(s) por iteração de pesquisa. As direções escolhidas não podem fazer com que a busca passe em um elemento pesquisado. Perceba que a seta vermelha representa que não pode se mover para $a_{02}$ pois essa posição possui uma parede.

<div align = "center" >
<br>
<strong>Figura 4 -</strong> DFS em Matriz
<br>
<img src = "./DFS/img/BFS_MATRIZ.png" height = "78%" width = "78%">
<br>
Fonte: Construção pelo autor⁶.
<br>
____________________________________________
<br>Criada usando o Canva⁶, Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>

- Observe como a BFS percorre casas adjascentes rapidamente em apenas 3 iterações. Enquanto isso a DFS foca ir em somente uma "direção" da matriz, ou seja, matemáticamente este percorreria vários vértices rapidamente, onde a distância entre eles depende de $n_{v}$ vértices vizinhos, portanto de $n_{e}-1$ arestas, afinal o percurso realizado gera um subgrafo onde todos os vértices tem grau $1$. Portanto BFS verifica vértices próximos(com arestas em comum) muito rapidamente, já o DFS pesquisa entre vértices distantes rapidamente. Com isso cada um destes é melhor para uma situação específica.

<br>

## Objetivos:
A problemática proposta pelo trabalho incita os alunos da disciplina a efetuar o caminhamento por BFS, DFS ou Caminhamento Aleatório de uma matriz de entrada com $N>=50$. Isso deve ser realizado seguindo algumas diretrizes de desenvolvimento:

- A matriz estará préviamente organizada para processamento em um arquivo `input.data`.
- O ponto inicial das três formas de caminhamento é o ponto onde se localiza o elemento $a_{00}$, ou seja, onde $i = 0, j=0$.
- A busca se limita ao escopo de matriz alocado na memória, portanto o programa caminha somente em $a_{ij}$ para $N-1>=i>=0$ e $N-1>=j>=0$.
- O programa deve ser escrito de modo à considerar comparações entre a execução dos 3 métodos de busca com diferentes tipos de entrada. Uma forma de facilitar essas comparações é realizando mensurações de tempo diante da execução destas funções.


<br>

## Metodologia:
### Arquivos:
Para resolução do desafio alguns arquivos foram cridos, dentre eles: 
 - `input.data`: Um arquivo que armazena o valor de $N$, ou seja, o tamanho da matriz e os elementos que serão armazenados ali.


 <div align="center">
<strong>Figura 5</strong> - input.data    
<br>

<img src = "./DFS/img/inputData.jpeg">

<br>
Fonte: Captura de tela feita pelo autor⁷.
<br>
____________________________________________
<br>⁷Captura de tela do computador do autor. Disponível em: <a href="https://github.com/jAzz-hub/BFS_and_DFS/blob/main/DFS/img/inputData.jpeg">Imagem 3</a>.
</div>
<br>


- `Makefile` : Controla a geração dos executáveis e compilação dos mesmos(FREE SOFTWARE FOUNDATION, GNU make, 2023).

- `bfs.c` : Contém as funções criadas para implementação do algoritmo BFS.

- `bfs.h` : Contém a assinatura da função de `bfs.c`.

- `dfs.c` : Contém as funções criada para implementação do algoritmo DFS.

- `dfs.h` : Contém a assinatura da função de `dfs.c`.

- `random_walk.c` : Contém as funções criadas para implementação do de uma estrutura de fila.

- `random_walk.h` : Contém a assinatura das funções de `random_walk.c` e a implementação da estrutura de uma fila.

- `Maze.c` : Contém as funções criadas para leitura e processamento do labirinto.

- `Maze.h` : Contém a assinatura das funções criadas em `Maze.c`.

- `Queue.c` : Contém as funções criadas para implementação do de uma estrutura de fila.

- `Queue.h` : Contém a assinatura das funções de `Queue.c` e a implementação da estrutura de uma fila.

- `Stack.c` : Contém as funções criadas para implementação do de uma estrutura de pilha.

- `Stack.h` : Contém a assinatura das funções de `Stack.c` e a implementação da estrutura de uma pilha.

- `main.c` : Contém a execução das 3 funções principais _**RAND**_, _**DFS**_ e _**BFS**_ tendo seus respectivos tempos de execução sendo mensurados.

### Funcionamento

 #### 1. Primeira Leitura do arquivo
  A leitura das entradas do arquivo `input.data` é realizada apenas 1 vez, em primeiro lugar o código reconhece qual a ordem da matriz presente no arquivo, isso será realizado respectivamente pelas funções _**read_size**_ e _**read_matrix**_.

  A função _**read_size**_ é responsável por ler a primeira linha do arquivo de entrada e retornar $N$, já _**read_matrix**_ é responsável por ler os valores do arquivo e salvar em uma matriz. 

 #### 2 Percorrendo a Matriz
  Há três formas de percorrer a matriz, são elas as funções _**RAND**_, _**DFS**_ e _**BFS**_. Todas estas funções param suas iterações quando o caracter $?$ está em um elemento contido na posição presente. Além disso quando o caracter na posição atual for igual a $*$ todas as funções apagam o caminho realizado entre $a_{00}$ e $a_{ij}$ tendo $i$ e $j$ atuais como referência e reiniciam as iterações partindo de novo do elemento ou posição $a_{00}$.

- Iterações na função _**DFS**_
  - A função _**DFS**_ adiciona a posição atual à uma pilha, ou seja, a casa 0,0.
  - À partir disso cada elemento adjascente será verificado como um elemento que pode ser adicionado a fila ou não (Os elementos adicionados à fila são $a_{ij}$ diferentes de $*$, #, $?$ ou que ainda não tenham sido exploradas). 
  - A verificação de casas adjascentes prioriza a posição que se encontra abaixo do elemento atual, diante disso enquanto a pilha não está vazia adiciona-se a primeira posição verificada disponível nesta pilha.
  - Elementos acessados a cada iteração são sempre adicionados no topo da pilha. 
  - Quando 4 posições adjascentes são verificadas de modo que as 4 sejam inacessíveis o algoritmo coloca uma parede na matriz onde estaria sua posição atual. 
  - Além disso ao se encontrar preso a posição do topo da pilha é exluída, portanto a penúltima posição da estrutura se torna a atual.
  
- Iterações na função _**BFS**_
  - A função _**BFS**_ adiciona a posição atual à uma fila, ou seja, a casa 0,0. 
  - À partir disso cada elemento adjascente será verificado como um elemento que pode ser adicionado a fila (Os elementos adicionados à fila são $a_{ij}$ diferentes de $*$, #, $?$ ou que ainda não tenham sido exploradas).Isso é feito enquanto a fila não está vazia.
  - Os elementos acessados a cada iteração serão adicionados no da fila(Caso atendam às premissas descritas previamente) e a cada iteração 1 elemento será removido da mesma.
  
- Iterações na função _**random_walk**_
    - A função _**random_walk**_ verifica posições adjascentes à posição atual através do acesso aleatório destas.
    
    - Toda vez que uma posição é sorteada e apresenta uma posição livre para se percorrer a posição atual se torna esta posição.
    
    - Dito isto o procedimento será realizado até que o caracter $?$ seja encontrado.
 
 #### 2.3 Casos especiais
O programa não trata casos especiais onde a posição inicial se encontre cercada por paredes inicialmente. Portanto o caso da imagem abaixo pode trazer problemas de execução:

<div align="center">
<strong>Figura 6</strong> - input.data    
<br>

<img src = "./DFS/img/workingBadWith.png" height = "78%" width = "78%">

<br>
Fonte: Construção pelo autor⁸.
<br>
____________________________________________
<br>Criada usando o Canva⁸, Disponível no <a href="https://www.canva.com/design/DAFd8EjV-8w/M4fX0cOTTduzNNPJxuF73Q/edit?utm_content=DAFd8EjV-8w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton">link</a>.
</div>
<br>

 
#### Implementação 2.4
O programa armazena o tempo de execução das funções de pesquisa em variáveis do `main.c` chamando a função _**clock()**_ antes e depois de da chamada de cada uma das funções. Isso permite que haja uma mensuração de complexidade considerando o ambiente de execução no momento em que o comando _**make run**_ é executado por um sistema operacional contido em uma máquina específica. Diante disso dada a entrada contida na **Figura 6** temos a saída demonstrada em **Figura 7**, **Figura 8** e **Figura 9**.



 <div align="center">
<strong>Figura 7</strong> - Saída da busca aletória, tempo de execução: 17.686000 ms    
<br>

<img src = "./DFS/img/outputAleatorio.jpeg" height = "78%" width = "78%">

<br>
Fonte: Captura de tela feita pelo autor⁸.
<br>
____________________________________________
<br>Captura de tela do computador do autor. Disponível em⁸, Disponível no <a href="">link</a>.
</div>
<br>

 <div align="center">
<strong>Figura 8</strong> - Saída da busca DFS, tempo de execução: 0.534000 ms    
<br>

<img src = "./DFS/img/outputDFS.jpeg" height = "78%" width = "78%">

<br>
Fonte: Captura de tela feita pelo autor⁹.
<br>
____________________________________________
<br>Captura de tela do computador do autor. Disponível em⁹, Disponível no <a href="">link</a>.
</div>
<br>

 <div align="center">
<strong>Figura 9</strong> - Saída da busca BFS, tempo de execução: 9.183000 ms    
<br>

<img src = "./DFS/img/outputBFS.jpeg" height = "78%" width = "78%">

<br>
Fonte: Captura de tela feita pelo autor¹⁰.
<br>
____________________________________________
<br>Captura de tela do computador do autor. Disponível em¹⁰, Disponível no <a href="">link</a>.
</div>
<br>


## Conclusão
### Por Qual Motivo Utilizar Matrizes Bidimensionais?
Como foi dito anteriormente o problema pode ser resolvido de diversas formas, uma delas é usufruindo de grafos. As relações entre vértices permitem inferências matemáticas mais plurais e complexas que as propostas aqui. Considerando que implementações realizadas aqui se restringem ao percorrimento de um espaço muito grande, a implementação de uma estrutura de dados tão complexa quanto o grafo poderia ser um custo desnecessário. Portanto os grafos não foram uma indicação nem uma escolha para solucionar o problema proposto.

### Comparações Entre as Formas de Caminhamento
 Diante das diferentes entradas propostas, o número e posições dos caracteres #, *, $1$ e ? foram alterados, com isso percebemos que em casos muito raros o BFS se torna mais rápido que o DFS. Além de tudo percebemos que o caminhamento aleatório é mais lento que ambos na maioria dos casos também. Em casos onde a interrogação se aproxima das casas inicias e paredes fazem o DFS andar para a região onde o valor de $i$ dos elementos $a_{ij}$ tende a se aproximar do valor de $N$, temos o BFS mais rápido, depois normalmente o aleatório e por último o DFS por exemplo. Contúdo vale ressaltar que ainda nestes casos o DFS ganhar no percorrimento destas estruturas por muito pouco. Mais especificamente uma diferença próxima de 1 segundo.



## Compilação e Execução
Para compilação e execução do código é necessário que seja criado um arquivo Makefile. Para uso deste arquivo da forma correta, siga as diretrizes de execução abaixo:

<table>

<tr>
<td colspan = '1'><strong>Comandos</strong></td>
<td align = "center" colspan = '1'><strong>Funções</strong></td>
</tr>

<tr>
<td align="center"><strong><i>make clean</i></strong>
</td>
<td align="center">Deleta o arquivo executável e todos os arquivos objetos do diretório. (FREE SOFTWARE FOUNDATION, GNU make, 2023)</td>
</tr>
<tr>
<td align="center"><strong><i>make</i></strong></td>
<td align="center">Compila diferentes partes do programa através do g++ e cria um arquivo executável na pasta build. </td>
</tr>
<tr>
<td align="center"><strong><i>make run</i></strong></td>
<td align="center">Executa o programa da pasta build após a realização da compilação. (PIRES, MICHEL, 2023)</td>
</tr>
</table>

## Ambiente de desenvolvimento:
O código foi desenvolvido e testado no seguinte ambiente de desenvolvimento:

<table>
<tr>
<td colspan = '1' align="center"><strong>Peças</strong></td>
<td align = "center" colspan = '1'><strong>Especificações</strong></td>
</tr>

<tr>
<td align="center"><strong><i>Processador</i></strong>
</td>
<td align="center">Intel(R) Core(TM) i5-3340M CPU @ 2.70GHz</td>
</tr>
<tr>
<td align="center"><strong><i>Memória RAM</i></strong></td>
<td align="center">8 GB </td>
</tr>
<tr>
<td align="center"><strong><i>Sistema Operacional</i></strong></td>
<td>Debian GNU/Linux 11 (bullseye)</td>
</tr>
</table>


<br><br>

## Referências <!--Idea!! CITAR O NÍVIO ZIVIANI-->

[1] Depth First Search (DFS) Explained: Algorithm, Examples, and Code. Disponível em: <https://www.youtube.com/watch?v=PMMc4VsIacU&t=797s>. Acesso em: 23 mai. 2023.

[2] Breadth First Search (BFS): Visualized and Explained. Disponível em: <https://www.youtube.com/watch?v=xlVX7dXLS64>. Acesso em: 24 maio. 2023.

[3] Create Graph online and find shortest path or use other algorithm. Disponível em: <https://graphonline.ru/en/>.


[4] Introdução à Teoria dos Grafos – Aula 5 – Grau de um vértice e o problema das Pontes de Königsberg. Disponível em: <https://www.youtube.com/watch?v=125pPCIRjZ8>. Acesso em: 24 maio. 2023.

[5] PIRES, MICHEL - Repositório GitHub, @mpiress: GenerateDataToMatrix - Disponível em: https://github.com/mpiress/GenerateDataToMatrix/blob/main/src/mat.h. Acessado em 15 de Março de 2023.

[6] GNU make. Disponível em: <https://www.gnu.org/software/make/manual/make.html>. Acessado em XX de Maio de 2023.

[7] GNU Make. Disponível em: <https://www.gnu.org/software/make/>. Acesso em: mai. 23DC.

[8] ALFREDO, A. et al. Grafos. [s.l: s.n.]. Disponível em: <https://homepages.dcc.ufmg.br/~loureiro/md/md_9Grafos.pdf>.




## Contato
<br>
<dig align="center">
<a href="https://github.com/rafaegont1">
<img align="justify" width="20%" height="20%" src="https://img.shields.io/badge/Rafael-000709?style=for-the-badge&logo=github&logoColor=white"/>
</a>
<a href="https://github.com/Getulio-Mendes">
<img align="justify" width="21%" height="20%" src="https://img.shields.io/badge/Getúlio-000709?style=for-the-badge&logo=github&logoColor=white"/>
</a>
<a href="https://github.com/jAzz-hub">
<img align="justify" width="16%" height="10%" src="https://img.shields.io/badge/João-000709?style=for-the-badge&logo=github&logoColor=white"/>
</a>
</div>
