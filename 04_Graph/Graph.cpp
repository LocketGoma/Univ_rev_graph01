#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX];  /* 방문된 정점은 1로 미방문 정점은 0으로 저장 */
/*--------------------------------------------------------------------------------------
  함수명 및 기능: initGraph() - 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 '
                                그래프를 인접 행렬법으로 초기화하는 함수
  전달인자:  gm - 그래프 정보 구조체의 주소
             fileName - 그래프의 정점 및 간선 정보가 저장된 데이터 파일명
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, char *fileName)
{
	char vertex[3];  /* 간선정보 입력을 위한 공간 "AB" 형태의 데이터 저장 char 배열 */
	int i,j,k;       /* iterator */
	FILE *fp;        /* 그래프 정보 저장 파일의 파일포인터 */

	fp=fopen(fileName, "rt");
	assert(fp!=NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* 정점과 간선의 개수를 읽기 */
	for (int i = 0; i < gm->vertexCnt; i++) {
		for (int j = 0; j < gm->edgeCnt; j++) {
			gm->graph[i][j] = 0;
		}
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s", vertex);
		for (int i = 0; i < gm->vertexCnt; i++) {
			for (int j = 0; j < gm->edgeCnt; j++){
				if (i==(int)(vertex[0]-'A'))
					if (j == (int)(vertex[1] - 'A')) {
						gm->graph[i][j] = 1;
							gm->graph[j][i] = 1;
							break;
					}
			}
		}
	}

	fclose(fp);
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: outputGraph() - 그래프내의 정점과 간선의 관계를 인접 행렬 형태로 출력
  전달인자:  gm : 그래프 정보 구조체의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i,j;         /* iterator */

	/* 정점명 가로방향 출력 */
	printf("   ");
	for(i=0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;  // 개행 매크로 

	for(i=0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for(j=0; j<gm->vertexCnt; j++)
				printf("%3d", gm->graph[i][j]);
		NEWL;
	}
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: DFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 깊이 우선 탐색
                                   하기 위한 함수(재귀판)
  전달인자:  gm : 그래프 정보 구조체의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for(i=0; i<gm->vertexCnt; ++i)  /* 정점의 방문상태 정보를 저장할 check배열 초기화 */
		check[i] = 0;
	for(i=0; i<gm->vertexCnt; ++i)
		if(check[i] == 0) 
			DFS_recursive(gm, i);
	return;
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: DFS_recursive() - 연결되어있는 하나의 그래프 내의 모든 정점을 
                                    재귀호출기법으로 방문하는 함수
  전달인자:  gm : 그래프 정보 구조체의 주소
             vNum : 방문하고자 하는 정점 번호
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void DFS_recursive(GraphMatrix *gm, int vNum)
{

        // TODO
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: visit() - 방문된 정점을 처리하는 함수(이 함수에서는 방문된 정점을 출력 함)
  전달인자: vNum : 방문하고자 하는 정점 번호
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void visit(int vNum)
{
	printf("%3c", 'A'+vNum);
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: nrDFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 깊이 우선 탐색
                                   하기 위한 함수(비 재귀판)
  전달인자:  gm : 그래프 정보 구조체의 주소
  리턴값: 없음    
--------------------------------------------------------------------------------------*/
void nrDFS_Matrix(GraphMatrix *gm)
{
	GraphMatrix *g = gm;
	Stack st;
	DataType *dt;
	initStack(&st);
	int pin=-1;
		push(&st, 0);
		check[0] = 0;
		int checker = 1;
		while (checker<=g->vertexCnt&&pin<=g->vertexCnt)
		{
			if (pin!=-1)
			for (int i = g->vertexCnt-1; i > 0 ; i--) {
			if (g->graph[pin][i] == 1) {
				if (check[i] != 1) {
					push(&st, i);
					check[i] = 1;
					checker++;
				}
			}
		}
			//printf(">%d<", checker);
		if (isStackEmpty(&st)&&checker<=g->vertexCnt) {
				pin++;
		}
		else {
			pop(&st, &pin);
			printf(" - %c", pin + 'A');
		}
	}

		destroyStack(&st);
		check_clear(g->vertexCnt);
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: BFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 너비 우선 탐색
                                   하기 위한 함수(비 재귀판)
  전달인자:  gm : 그래프 정보 구조체의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void nrBFS_Matrix(GraphMatrix *gm) { // 큐로 구현하기

}
void BFS_Matrix(GraphMatrix *gm) 
{
	int checker=0;
	int pin=0;
	//Stack st;
	//initStack(&st);
	//printf(">><<");
	printf("A"); // <- 바꿀것
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
void check_clear(int n) {
	for (int i = 0; i < n; i++)
		check[i] = 0;
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: countGraphComponents() - 인접 행렬법으로 표기되 그래프 내의 연결 요소별로 
                                           정점들을 출력하고 연결 요소의 개수 리턴
  전달인자:  gm : 그래프 정보 구조체의 주소
  리턴값: 그래프내의 연결 요소의 개수
--------------------------------------------------------------------------------------*/
int countGraphComponents(GraphMatrix *gm)
{
	int componetsCount=0;  /* 그래프 내의 연결 요소 카운트 변수 */

        // TODO
	return componetsCount;
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: initGraph_L() - 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 '
                                 그래프를 인접 리스트법으로 초기화하는 함수
  전달인자:  g : 그래프 정보 구조체의 주소
             fileName : 그래프의 정점 및 간선 정보가 저장된 데이터 파일명
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void initGraph_List(GraphList *g, char *fileName)
{
	char vertex[3];  /* 간선정보 입력을 위한 공간 "AB" 형태의 데이터 저장 char 배열 */
	int i,j,k;       /* iterator */
	FILE *fp;        /* 그래프 정보 저장 파일의 파일포인터 */
	int *vert;

	fp=fopen(fileName, "rt");
	assert(fp!=NULL);
	fscanf(fp, "%d %d\n", &g->vertexCnt, &g->edgeCnt);  /* 정점과 간선의 개수를 읽기 */
	vert = (int *)malloc(sizeof(int)*g->vertexCnt);

        // TODO

	fclose(fp);
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: addNode() - 두 정점의 관계를 리스트에 등록함
  전달인자:  g - 그래프 정보 구조체의 주소
			 vNum1 - 첫번째 정점의 번호
			 vNum2 - 두번째 정점이 번호
  리턴값: 정점 등록이 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int addNode(GraphList *g, int vNum1, int vNum2)
{

        // TODO
	return TRUE;
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: outputGraph_L() - 그래프내의 정점과 간선의 관계를 인접 리스트 형태로 출력
  전달인자:  g : 그래프 정보 구조체의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void outputGraph_List(GraphList *g) //Push->더 없으면 pop->pop된 node와 연결된 node들 push->더 없으면 pop-->
{									//한번 push되면 check관리에서 들어갔음으로 체크.

        // TODO
}
/*--------------------------------------------------------------------------------------
  함수명 및 기능: destroyGraph_L() - 그래프내의 정점 노드 모두 삭제
  전달인자:  g : 그래프 정보 구조체의 주소
  리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroyGraph_List(GraphList *g) //<-리스트란다?
{
	for (int i = 0; i < g->vertexCnt; i++) {
		for (int j = 0; j < -g->edgeCnt; j++) {
			g->graph[i][j].vertex=0;
		}
		free(g->graph[i]);
	}
	free(g);
        // TODO
}