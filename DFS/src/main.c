
#include "Functions.h"

#include "Structures.h"

void GenerateMatrix(Matrix *mat){
	int data = 0;

	for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++){
        	data = rand()%20;
        	if(data <= 10)
            	mat->m[i][j].val = '1'; 
            else if ((data > 10) && (data < 16))
            	mat->m[i][j].val = '*';
            else
            	mat->m[i][j].val = '#';
        }
}


void SetMatrixSignature(){
	FILE *f;

	if ((f = fopen("dataset/input.data", "w")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    fprintf(f,"%d %d %d", MAXROWS, MAXCOLS, NUMAT); 
    fprintf(f,"\n");
    fclose(f);

}

void SaveMatrix(Matrix *mat){
	
	FILE *f;

	if ((f = fopen("dataset/input.data", "a")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    GenerateMatrix(mat);

	for (int i=0;i<MAXROWS;i++){
        for (int j=0;j<MAXCOLS;j++)
             fprintf(f,"%c ", mat->m[i][j].val); 
        fprintf(f,"\n");
	}
	fprintf(f,"\n");
	fclose(f);
}



int main()
{
	Matrix myMatrix;
	GenerateMatrix(&myMatrix);
	SetMatrixSignature();
	SaveMatrix(&myMatrix);

	int SizeOfMatrixes = SizeRecon();
	int HowMuchMatrixes = HowMuchMatrixes();
	

    return 0;
}