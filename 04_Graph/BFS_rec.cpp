void BFS_Matrix(GraphMatrix *gm)
{
	int checker=0;
	int pin=0;
	//Stack st;
	//initStack(&st);
	//printf(">><<");
	printf("A"); // <- ¹Ù²Ü°Í
	BFS_Mt(gm, checker,pin);
	check_clear(gm->vertexCnt);
}
void BFS_Mt(GraphMatrix *gm, int checker, int pin) {
	//printf(">><<");
	
	if (!(checker <= gm->vertexCnt&&pin <= gm->vertexCnt))
		;
	else {
			for (int i = gm->vertexCnt - 1; i > 0; i--) {
				if (gm->graph[pin][i] == 1) {
					if (check[i] != 1) {
						check[i] = 1;
						checker++;
						printf(" - %c", i + 'A');
					}
				}
			}
		pin++;
		BFS_Mt(gm, checker, pin);
	}
	//destroyStack(&st);
}