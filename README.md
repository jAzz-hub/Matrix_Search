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
    - [Desenvolvimento](#Desenvolvimento)
    - [Compilação e Execução](#Compilação-e-Execução)
    - [Ambiente de Desenvolvimento](#Ambiente-de-Desenvolvimento)
- [Conclusão](#Conclusão)
    - [Como melhorar a Metodologia?](#Conclusão)
    - [Reavaliando a Implementação do Algoritmo em Matrizes bidimensionais](#Conclusão)
    - [Referências](#Referências)
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
- Para contextualizar o funcionamento do algoritmo, considere que um personagem caminha por um labirinto até encontrar uma saída definida por um ponto de interrogação:
    - O personagem representa uma abstração para uma busca realizada em uma matriz, essa busca se encerra quando o elemento $!$ é encontrado.
    -   O caracter $*$ representa uma casa que reiniciar a pesquisa. Isso significa que, se o personagem passa pelo elemento $a_{ij} = *$, este haverá de reiniciar sua busca da posição $a_{00}$. Além disso o caminho entre $a_{ij}$ e $a_{00}$ será considerado como não percorrido.
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
<br>
referências:
<br>
<br>

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


https://www.youtube.com/watch?v=s-CYnVz-uh4&t=122s

https://www.youtube.com/watch?v=xlVX7dXLS64

https://www.youtube.com/watch?v=125pPCIRjZ8

links úteis:
"https://graphonline.ru/pt/"


A equipe <a href = "https://github.com/Getulio-Mendes/LabirintoRecorrente">Getúlio</a>, <a href = "https://github.com/rafaegont1/O-labirinto-recorrente">Rafel</a> e <a href = "https://github.com/jAzz-hub/Recurrent_Labyrinth">João</a>


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
