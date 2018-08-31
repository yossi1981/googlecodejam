#include <stdio.h>
#include <string.h>

#define L_LIMIT 50000
#define C_LIMIT 12
#define R_LIMIT 12

int fillcake(int R, int C, char cake[1000][1000]) 
{	
	//fill horizontally
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if (cake[r][c] != '?') {
				//fill right and left
				for (int i = c + 1 ; i < C && cake[r][i] == '?'; i++) {
					cake[r][i] = cake[r][c];
				}

				//fill left
				for (int i = c - 1; i >= 0 && cake[r][i] == '?'; i--) {
					cake[r][i] = cake[r][c];						
				}
			}
		}
	}

	
	//fill vertically
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if (cake[r][c] != '?') {
				//fill down
				for (int i = r + 1; i < R && cake[i][c] == '?'; i++) {
					cake[i][c] = cake[r][c];	
				}

				//fill up
				for (int i = r -1; i >= 0 && cake[i][c] == '?'; i--) {
					cake[i][c] = cake[r][c];
				}

			}
		}
	}	
}


int main()
{

	//freopen("A-small-practice.in","rt", stdin);
	//freopen("A-small-practice.out", "w", stdout);
	
	freopen("A-large-practice.in","rt", stdin);
	freopen("A-large-practice.out", "w", stdout);

	char inputline[L_LIMIT];
	char cake[1000][1000];
	int tc, tccounter, R, C;
	tccounter = 1;

	scanf("%d", &tc);	
	while (scanf("%d%d", &R, &C) != EOF) {

		//read cake
		for(int r = 0; r < R; r++) {
			scanf("%s",inputline);
			strcpy (cake[r], inputline); 
		}//
		
		fillcake(R, C, cake);
		
		//print test case result
		printf("Case #%d:\n",tccounter);	
		for (int r = 0; r < R; r++) {
			printf("%s\n", cake[r]);
		}//

		tccounter+=1;
	}

	return 0;
}







