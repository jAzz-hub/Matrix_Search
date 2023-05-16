

// #próximo_passo = verifica se a casa futura é válida;

unsigned short int SizeRecon()
{
    unsigned short int ArrayArea = 0;
    FILE *LocalPointer;
    LocalPointer = fopen("./dataset/input.data", "r");
    fscanf(LocalPointer, "%hu", &ArrayArea);
    fclose(LocalPointer);
    return ArrayArea;
}

/// @brief Lê a primeira linha do arquivo input.data
/// @return  O número de matrizes a serem lidas nesse arquivo
unsigned int HowMuchMatrixes()
{
    int size;
    string strNumberOfMatrixes;
    string FirstLine;
    FILE *LocalPointer;
    LocalPointer = fopen("./dataset/input.data", "r");
    char l2[100];
    FirstLine = fgets(l2,100,LocalPointer);
    fclose(LocalPointer);

    
    if(FirstLine.at(FirstLine.length()-3)==' ')// Número de matrizes < 10:
    {
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-2);
    }
    else if(FirstLine.at(FirstLine.length()-4)==' ')//Número de matrizes <100:
    {
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-3);
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-2);
    }
    else if(FirstLine.at(FirstLine.length()-5)==' ')//Número de matrizes <1000:
    {
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-4);
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-3);
        strNumberOfMatrixes+=FirstLine.at(FirstLine.length()-2);
    }

    // char AuxChar = (char)strNumberOfMatrixes;

    std::string::size_type sz;
    unsigned int NumberOfMatrixes = std::stoi(strNumberOfMatrixes,&sz);
    
    return NumberOfMatrixes;
}

// FileScanning()
// {
    
// }

// percurso()
// {
//     #Direções Possíveis x+1(direita),x-1(esquerda) ou y-1(subir),y+1(descer):
    
//     verifica as direções:
//         só anda para direções na memória.
//             prioriza na seguinte ordem: baixo, direita, cima, esquerda.
    
//    while(próximo_passo() == true) 
//         Passo_Busca_Profundidade();
    
//     if Verifica_Redondezas(atual);
//         Troca avanço;
//     else
//         while(Verifica_Redondezas == false)
//             pop na pilha
//             matrix[Direção.y + atual.y][Direção.x + atual.x] = '#';
        
    
//     Matrix[Direção.y + atual.y][Direção.x + atual.x] = '#';
//     if perigo{
//         volta no começo
//     }
        
//     dá 1 passo
// }



// ///
// Passo_Busca_Profundidade(Coordenada *Posição_atual,Coordenada Direção)
// {
    
//         posição atual.x+= Direção.x
//         posição atual.y+= Direção.y
//         pega a posição atual armazena na pilha
    
//   }  

// Passo_Busca_Largura()
// {
//     pega a posição atual
// }


// main()
// {
//     lê arquivo e obtem matriz gigante em variável
    
//     iniciar percurso
    
//     percurso();
    
// }