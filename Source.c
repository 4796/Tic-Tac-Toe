#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int odigraj_potez(int mat[10][10], int n, char igrac, int i, int j) {
	if (mat[i][j] != -1) {
		return 0;
	}
	if (igrac == 'X') {
		mat[i][j] = 1;
	}
	else {
		mat[i][j] = 0;
	}

	return 1;
}


int pobednicki_niz(int mat[10][10], int n, char igrac) {
	int p = 0;
	//red
	for (int i = 0; i < n; i++) {
		p = 0;
		for (int j = 0; j < n-1; j++) {
			if (mat[i][j] == mat[i][j + 1] && mat[i][j]!=-1) {
				p++;
			}

		}
		if (p == n - 1) {
			return 1;
		}
	}
	//kolona
	
	for (int j = 0; j < n; j++) {
		p = 0;
		for (int i = 0; i < n - 1; i++) {
			if (mat[i][j] == mat[i+1][j] && mat[i][j] != -1) {
				p++;
			}

		}
		if (p == n - 1) {
			return 1;
		}
	}

	//glavna dij
	p = 0;
	for (int i = 0; i < n-1; i++) {
		
		
			if (mat[i][i] == mat[i+1][i + 1] && mat[i][i] != -1) {
				p++;
			}
			if (p == n - 1) {
				return 1;
			}
		
	}
	//sporedna
	p = 0;
	for (int i = 0; i < n; i++) {           
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {
				
				if (mat[i][j] == 1 && mat[i][j] != -1) {
					p++;
				}
			}

		}

	}
	if (p == n) {
		return 1;
	}
	p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {

				if (mat[i][j] == 0 && mat[i][j] != -1) {
					p++;
				}
			}

		}

	}
	if (p == n) {
		return 1;
	}
	return 0;
}


void prikazi_igru(int mat[10][10], int m) {
	printf("\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				printf("X  ");
			}
			if (mat[i][j] == 0) {
				printf("O  ");
			}
			if (mat[i][j] == -1) {
				printf("_  ");
			}
		}
		printf("\n");
	}
}

void pokreni_igru(int mat[10][10], int* m) {
	int p;
	int i, j;
	
	printf("Unesite dimenziju:\n");
	p=scanf("%d", m);
	getchar();
	if (p != 1 || (*m)>10) {
		printf("greska");
		return;
	}
	do {
		printf("X-unesite potez(indeksi krecu od 0 i u formatu broj broj):\n");
		p=scanf("%d %d", &i, &j);
		getchar();
		if (p != 2 || i > (*m)-1 || j > (*m) - 1) {
			printf("greska");
			return;
		}
		p=odigraj_potez(mat, (*m), 'X', i, j);
		if (p == 0) {
			printf("\ngreska\n");
			return;
		}
		else {
			printf("\ndobar unos!\n");
			prikazi_igru(mat, (*m));
		}
		/////////////
		//prikazi_igru(mat, (*m));
		p = pobednicki_niz(mat, (*m), 'X');
		if (p == 1) {
			printf("Pobednik je X!\n");
			prikazi_igru(mat, (*m));
			return;
		}

		printf("O-unesite potez(indeksi krecu od 0 i u formatu broj broj):\n");
		p=scanf("%d %d", &i, &j);
		getchar();
		if (p != 2 || i > (*m) - 1 || j > (*m) - 1) {
			printf("greska");
			return;
		}
		p = odigraj_potez(mat, (*m), 'O', i, j);
		if (p == 0) {
			printf("\ngreska\n");
			return;
		}
		else {
			printf("\ndobar unos!\n");
			prikazi_igru(mat, (*m));
		}
		////////////
		//prikazi_igru(mat, (*m));
		p = pobednicki_niz(mat, (*m), 'O');
		if (p == 1) {
			printf("Pobednik je O!\n");
			prikazi_igru(mat, (*m));
			return;
		}
	} while (1);


}

int main(void) {
	int matrica[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrica[i][j] = -1;
		}

	}
	int m = 0;
	pokreni_igru(matrica, &m);
	getchar();
}