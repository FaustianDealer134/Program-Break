#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

extern char end;
extern char etext;
extern  char data_start;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Erro no numero de parametros!" << endl;
		exit(1);
	}
	cout << endl << "O endereco do program break no comeco: " << sbrk(0) << endl;
	int i, N = atoi(argv[1]);
	char *s = static_cast<char*>(sbrk(N+1));

	for(i = 0; i < N; i++)
	{
		s[i] = 'x';
	}
	s[i] = '\0';

	char *t_e = &::etext;
	char *t_b = (char*)0x400000;
	char *d_e = &::end;
	char *d_b = &::data_start;
	int t = (t_e - t_b);
	int d = (d_e - d_b);

	cout << "O tamanho do segmento de texto: 0x0" << hex << t << endl;
	cout << "O tamanho do segmento de dados: 0x0" << hex << d << endl;
	cout << "O endereco do program break no fim: " << sbrk(0) << endl;
	cout << "A string eh: " << s << endl << endl;
	sbrk(-N-1);
	return 0;
}
