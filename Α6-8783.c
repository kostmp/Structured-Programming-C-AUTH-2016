//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Constants
#define MIL 10000
//Pre_Processor
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef short int dice;

//Fuction Definition
//������������� ���� �������� ��������
dice dice_roll(){
	return (rand() % 6) + 1;
}

//"������" �� �����, ��� ������� ��� ��������� ���������
void routine(){
	dice t;
	int freq[6] = { 0 }; // ������������ ������ 6 ������ �� ��� ���� 0
	for (int i = 0; i < MIL; ++i){
		t = dice_roll();
		freq[t - 1]++;
		printf("%d ", t);
	}
	printf("\n");
	for (int j = 0; j < 6; ++j){
		printf("Case %d showed up %d times. Frequency: %lf. Percentage: %.2f%% \n", j + 1, freq[j], (double)freq[j] / MIL,
			((double)freq[j] / MIL)*100);
	}
}

//������ ���� �� ���������� input/output
void enviroment(){
	printf("******************************\n");
	printf("\tHello Welcome\nDo you want to roll the Dice?\n");
	printf("*******************************\n");
	printf("Option (y or n):");
	char ans;
	do {
		scanf_s("%c", &ans);
	} while (!(ans == 'n' || ans == 'y'));
	if (ans == 'y'){
		system("cls");
		printf("\t \tGet ready for some MatriX effect!!!\n");
		system("pause");
		routine();
	}
	else{
		printf("Goodbye!!!! \n");
	}
}

//Main
int main(void){
	srand((unsigned int)time(NULL));
	/*� ��������� srand ������� �������� ���� unsigned int ��� ������ ��� � time() ���������� ������ ����� time_t. 
	��'���� ��� � ��������� (Possible DATA LOSS) (��. TYPECASTING)*/
	enviroment();
}