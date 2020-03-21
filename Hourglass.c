#include <stdio.h>
#include <stdlib.h>

/* ����� ���� �Լ� ���� */
void draw_hourglass(int num, int **arr);
int draw_knou();
static int seq = 0; //���� ���� ����

int main() {
	int chk = draw_knou();
	getchar(); //��¹� Ȯ���ϱ� ���� wating
	return chk; //���� ���� 0�� ��ȯ�ϰ� �����.
}

int draw_knou() {
	int inputNum; //����� �Է� �� ����
	int **arr; //������ �迭 ����

	do {
		printf("�迭�� ���̸� �Է��ϼ���. (5���� 10������ Ȧ��): ");
		scanf_s("%d", &inputNum); //2017 visual studio �� ���� �����÷ο�� ���� ������ scanf_s �Լ� ���
		while (getchar() != '\n'); // �Է� ���� ���ڿ��� ��� �ش� �Լ��� ���� buffer���� ����

		if (inputNum == 0) { //�Է� ���� 0
			printf("�����α׷��� �����մϴ�. �̸�: ���ʼ�\n");
			return 0;
		} else if (inputNum >= 5 && inputNum <= 10) { // �Է°��� 5�̻� 10 �����̰�
			if (inputNum % 2 == 1) { // Ȧ���̸� �𷡽ð� ��� ����
				arr = (int**)malloc(sizeof(int) * inputNum); //������ �迭�� ���� ������ �Ҵ�

				for (int i = 0; i < inputNum; i++) { 
					arr[i] = (int *)malloc(sizeof(int) * inputNum); //�� column�� �������� ������ �Ҵ�
				}

				for (int i = 0; i < inputNum; i++) {
					for (int j = 0; j < inputNum; j++) {
						arr[i][j] = 0; //���� for���� ���� �迭 �ʱ�ȭ
					}
				}

				draw_hourglass(inputNum, arr); // �迭�� ����(����� �Է� ��)�� �ʱ�ȭ�� �迭 ����

				for (int i = 0; i < inputNum; i++) { 
					free(arr[i]); //�迭 i�� ������ �ݳ�
				}

				free(arr); //�迭�� ������ �ݳ�

			} else { //5 ~ 10 ������ ¦���̸�
				printf(" �� 5���� 10 ������ Ȧ���� �Է��Ͻÿ�.�а� : ��ǻ�Ͱ��а�\n");
			}
		} else if (inputNum % 2 == 0) { //¦���̸�
			printf("�� Ȧ���� �Է��Ͻÿ�. �й�: 201912 - 962351\n");
		} else { //�� ��
			printf(" �� 5���� 10 ������ Ȧ���� �Է��Ͻÿ�.�а� : ��ǻ�Ͱ��а�\n");
		}

	} while (1);

	return 0; //���α׷� ���� 0 ��ȯ
}

/**
@param int num
@param int **arr
*/
void draw_hourglass(int num, int **arr) {

	int beginIndex = 0; //���� �Ҵ�Ǿ�� �� ���� column ��ġ
	int endIndex = num; //�� �Ҵ��� ������ column ��ġ

	int centerPoint = num / 2 + 1; //row�� ��/�� ��ȯ��

	for (int i = 0; i < num; i++) {
		if (centerPoint > i) { //���� �ݺ��� focus�� �߰� �������� �� ������
			beginIndex++; //���� column�� ����
			endIndex--; //�� ������ ����
		} else { //�߰� ���� ������ ���
			beginIndex--; //���� column�� ����
			endIndex++; //�� ������ ����
		}

		for (int j = beginIndex - 1; j < endIndex + 1; j++) {
			arr[i][j] = (++seq); //�ݺ����� ���鼭 �������� ���� ���� // seq�� 0���� �����Ͽ� prefix ǥ�� ���
		}

	}


	/*
		���� for���� ����Ͽ� ��� �� ���.
		�ʱ�ȭ�� ��� �迭�� 0���� �����߱� ������
		����� ���� �Ҵ��� seq �Ǵ� 0����
		0�϶� ascii code 32�� ' '��
		�ƴ� �� �ش� ���� ���
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

	//������� ���� 0�� ������ ���ѷ����� ���� ������ �������� �ʱ�ȭ
	seq = 0;
}