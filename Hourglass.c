#include <stdio.h>
#include <stdlib.h>

/* 사용자 정의 함수 선언 */
void draw_hourglass(int num, int **arr);
int draw_knou();
static int seq = 0; //전역 변수 선언

int main() {
	int chk = draw_knou();
	getchar(); //출력물 확인하기 위해 wating
	return chk; //종료 값인 0을 반환하고 종료됨.
}

int draw_knou() {
	int inputNum; //사용자 입력 값 변수
	int **arr; //다차원 배열 선언

	do {
		printf("배열의 길이를 입력하세요. (5부터 10사이의 홀수): ");
		scanf_s("%d", &inputNum); //2017 visual studio 의 버퍼 오버플로우로 인한 오류로 scanf_s 함수 사용
		while (getchar() != '\n'); // 입력 값이 문자열일 경우 해당 함수를 통해 buffer에서 제거

		if (inputNum == 0) { //입력 값이 0
			printf("♥프로그램을 종료합니다. 이름: 고필성\n");
			return 0;
		} else if (inputNum >= 5 && inputNum <= 10) { // 입력값이 5이상 10 이하이고
			if (inputNum % 2 == 1) { // 홀수이면 모래시계 출력 로직
				arr = (int**)malloc(sizeof(int) * inputNum); //다차원 배열에 동적 기억공간 할당

				for (int i = 0; i < inputNum; i++) { 
					arr[i] = (int *)malloc(sizeof(int) * inputNum); //각 column에 동적으로 기억공간 할당
				}

				for (int i = 0; i < inputNum; i++) {
					for (int j = 0; j < inputNum; j++) {
						arr[i][j] = 0; //이중 for문을 돌며 배열 초기화
					}
				}

				draw_hourglass(inputNum, arr); // 배열의 길이(사용자 입력 값)와 초기화된 배열 전달

				for (int i = 0; i < inputNum; i++) { 
					free(arr[i]); //배열 i의 기억공간 반납
				}

				free(arr); //배열의 기억공간 반납

			} else { //5 ~ 10 사이의 짝수이면
				printf(" ☆ 5부터 10 사이의 홀수를 입력하시오.학과 : 컴퓨터과학과\n");
			}
		} else if (inputNum % 2 == 0) { //짝수이면
			printf("★ 홀수를 입력하시오. 학번: 201912 - 962351\n");
		} else { //그 외
			printf(" ☆ 5부터 10 사이의 홀수를 입력하시오.학과 : 컴퓨터과학과\n");
		}

	} while (1);

	return 0; //프로그램 종료 0 반환
}

/**
@param int num
@param int **arr
*/
void draw_hourglass(int num, int **arr) {

	int beginIndex = 0; //값이 할당되어야 할 시작 column 위치
	int endIndex = num; //값 할당의 마지막 column 위치

	int centerPoint = num / 2 + 1; //row의 증/감 반환점

	for (int i = 0; i < num; i++) {
		if (centerPoint > i) { //현재 반복문 focus가 중간 지점보다 못 갔으면
			beginIndex++; //시작 column을 증가
			endIndex--; //끝 지점을 감소
		} else { //중간 지점 이후일 경우
			beginIndex--; //시작 column을 감소
			endIndex++; //끝 지점을 증가
		}

		for (int j = beginIndex - 1; j < endIndex + 1; j++) {
			arr[i][j] = (++seq); //반복문을 돌면서 전역변수 값을 저장 // seq를 0으로 선언하여 prefix 표현 사용
		}

	}


	/*
		이중 for문을 사용하여 모든 값 출력.
		초기화로 모든 배열을 0으로 선언했기 때문에
		저장된 값은 할당한 seq 또는 0으로
		0일땐 ascii code 32인 ' '을
		아닐 땐 해당 값을 출력
	*/
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[j][i] == 0) {
				printf("%c\t", 32);
			} else {
				printf("%d\t", arr[j][i]);
			}
		}
		printf("\n");
	}

	//사용자의 값이 0일 때까지 무한루프를 돌기 때문에 전역변수 초기화
	seq = 0;
}