#include <stdio.h>
#include <sys/time.h>

#define TAM 500

struct pix
{
	unsigned int r, g, b;
};


struct pix color[TAM][TAM];

int main()
{
	double ti, tf, 	tempo;
	ti = tf = tempo = 0;
	struct timeval tempo_inicio, tempo_fim;
	gettimeofday(&tempo_inicio, NULL);
	
	int i, j;
	for(i = 0; i < TAM; i++)
		for(j = 0; j < TAM; j++)
		{
			color[j][i].r = 
				(color[j][i].r + 
				 color[j][i].g +
				 color[j][i].b)/3;
		}

	gettimeofday(&tempo_fim, NULL);
	tf = (double) tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
	ti = (double) tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
	tempo = (tf-ti) / 1000;
	FILE *f = fopen("testes.csv","a");
	if(f== NULL)
		return 0;
	fprintf(f, "%.3f,", tempo);
	fclose(f);
}
