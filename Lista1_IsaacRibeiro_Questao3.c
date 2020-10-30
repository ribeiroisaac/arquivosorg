#include <stdio.h>
#include <string.h>

typedef struct _Registro Registro;

struct _Registro
{
    int id_inscricao[12];
   	char curso[20];
	char cpf[15];
	char dataNascimento[11];
	char sexo;
	char email[40];
	char opcaoQuadro;
};

int main(int argc, char**argv)
{
	FILE *arq1, *arq2;
	Registro r1, r2;
	int qt1, qt2;
	int c;

	if(argc != 1)
	{
		fprintf(stderr, "ERRO NA INICIALIZAÇÃO DO PROGRAMA");
		return 1;
	}

	c = 0;
	arq1 = fopen("candidatosA.dat","rb");
	arq2 = fopen("candidatosB.dat","rb");

	qt1 = fread(&r1, sizeof(Registro), 1, arq1);
	qt2 = fread(&r2, sizeof(Registro), 1, arq2);

    while(qt1 != 0 || qt2 != 0)
    {
		if(strncmp(r1.cpf,r2.cpf,15)==0)
        {
            printf("ID: %d.\n", r1.id_inscricao);
            printf("CURSO: %s.\n", r1.curso);
            printf("CPF: %s.\n", r1.cpf);
            printf("DATA DE NASCIMENTO: %s.\n", r1.dataNascimento);
            printf("SEXO: %c.\n", r1.sexo);
            printf("EMAIL: %s.\n", r1.email);
            printf("OPCAO: %c.\n", r1.opcaoQuadro);
            c++;
            qt1=0;
            qt2=0;
        }
        else
        if (r1.cpf>r2.cpf)
        {
            qt2 = fread(&r2, sizeof(Registro), 1, arq2);
        }
        else
        if (r2.cpf>r1.cpf)
        {
            qt1 = fread(&r1, sizeof(Registro), 1, arq1);
        }
    }

	printf("Total Impresso: %d\n", c);
	fclose(arq1);
	fclose(arq2);
}