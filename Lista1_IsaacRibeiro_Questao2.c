#include <stdio.h>
#include <string.h>

// REGISTRO - STRUCT DO EXERCÍCIO //

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
/*
void compara_arquivo (Registro reg, FILE a[], FILE saida[], int qt, int c)
{
	Registro pivo;
	while(qt!=0)
	{
		pivo = reg;

		int flag = 1;	
		qt=fread(&reg,sizeof(Registro),1,a);
		
		while(flag !=0)
		{
			if(pivo.cpf == reg.cpf)
			{
				if(pivo.id_inscricao > reg.id_inscricao)
				{
					qt=fread(&reg,sizeof(Registro),1,a);
				}
				else
				{
					pivo = reg;
					qt=fread(&reg,sizeof(Registro),1,a);
				}
			}
			else
			{
				char x = '\n';
				fwrite(&pivo, sizeof(Registro), 1, saida);
				putc(x, saida);
				c++;
				flag = 0;
			}
		}		
	}
}
*/

int main(int argc, char**argv)
{
	FILE *f, *saida;
	Registro r, s;
	int qt;
	int c;

	if(argc != 1)
	{
		fprintf(stderr, "ERRO NA INICIALIZAÇÃO DO PROGRAMA");
		return 1;
	}

	c = 0;
	f = fopen("candidatos.dat","rb");
	saida = fopen("final_candidatos.dat","w");

    qt = fread(&r,sizeof(Registro),1,f);
	while(qt>0)
	{
		qt = fread(&s, sizeof(Registro), 1, f);
		if(r.cpf==s.cpf)
		{
			if(s.id_inscricao > r.id_inscricao)
			{
				r=s;
			}
		}
		else
		{
			fwrite(&r, sizeof(Registro),1,saida);
			c++;
			char x = '\n';
			putc(x, saida);
			r=s;
		}

	}


	printf("Total Lido: %d\n", c);
	printf("Arquivo criado.\n");

	fclose(f);
	fclose(saida);
}
