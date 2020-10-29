#include <stdio.h>

int main(int argc, char** argv)
{
	FILE *entrada;

	char c;

	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"r");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não foi aberto para leitura\n", argv[1]);
		return 1;
	}

	int palavra = 1;
    int linhas = 1;
    char caractere;
	int validadeesp = 0;
	int validadelin = 1;

	c = fgetc(entrada);

	do
	{
		if(c=='\n')
        {
			linhas++;	

			if(validadelin == 0)
			{	
				palavra++;
			}	

			validadelin = 1;
		}
        if(c== ' ' && validadeesp == 0)
        {
			palavra++;
			validadeesp = 1;
		}
		else
		{
			validadelin = 0;
			validadeesp = 0;
		}

		c = fgetc(entrada);

	} while(c != EOF);
	
    printf("O arquivo possui %d palavras\n", palavra);
    printf("e %d linhas.\n", linhas);
    
	fclose(entrada);
	return 0;
}

