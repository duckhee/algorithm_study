/**
 * 한 친구가 방금 새 컴퓨터를 샀다. 그 친구가 지금까지 샀던 가장 강력한 컴퓨터는 공학용 전자 계산기였다. 그런데 그 친구는 새 컴퓨터의 모니터보다
 * 공학용 계산기에 있는 LCD 디스플레이가 더 좋다며 크게 실망하고 말았다. 그 친구를 만족시킬 수 있도록 숫자를 LCD 디스플레이 방식으로 출력하는 
 * 프로그램을 만들어보자.
 * 
 * 입력
 *  입력 파일은 여러 줄로 구성되며 표시될 각각의 숫자마다 한 줄씩 입력된다. 각 줄에는 s 와 n이라는 두 개의 정수가 들어있으며 n은 출력될 숫자(0<=n<=99,9999,999),
 * s는 숫자를 표시하는 크기(1<=s<=10)를 의미한다. 0이 두 개 입력된 줄이 있으면 입력이 종료되며 그 줄은 처리되지 않는다.
 * 
 * 출력
 * 입력 파일에서 지정된 숫자를 수평 방향은 '-' 기호를, 수직 방향은 '|'를 이용해서 LCD 디스플레이 형태로 출력한다. 각 숫자는 정확하게 s+2개의 열, 2s+3개의 행으로 
 * 구성된다. 마지막 숫자를 포함한 모든 숫자를 이루는 공백을 스페이스로 채워야 한다. 두 개의 숫자 사이에는 정확하게 한 열의 공백이 있어야 한다.
 * 각 숫자 다음에는 빈 줄을 한 줄 출력한다. 
 * 
 * 입력 예
 * 2 12345
 * 3 67890
 * 0 0
 */

#include <stdio.h>
#include <string.h>


#define MAX_S     10
#define MAX_DIGITS  8

void main(void)
{
	int s, i, j, digit, num_digits;
	char number[MAX_DIGITS+1];
	char hor_bar[2][MAX_S+1] = {"          ", "----------"};
	char ver_bar[2][2] = {" ", "|"};
	char hor[10][3] = {{1, 0, 1}, {0, 0, 0}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0},
		{1, 1, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 1, 1}};
	char ver[10][4] = {{1, 1, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1},
		{1, 1, 0, 1}, 
		{1, 0, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}};
	char result[5][(MAX_S + 3) * MAX_DIGITS];

	scanf("%d", &s);

	while(s != 0)
	{
		for(i = 0; i < 5; i++)
		{
			result[i][0] = '\0';
		}

		hor_bar[0][s] = '\0';
		hor_bar[1][s] = '\0';
		scanf("%s", number);

		num_digits = strlen(number);
		for(i = 0; i < num_digits; i++)
		{
			digit = number[i] - '0';
			if(i > 0)
			{
				for(j = 0; j < 5; j++)
				{
					strcat(result[j], " ");
				}
			}
            //0번 - 맨 윗줄 가로 bar
			strcat(result[0], " ");
			strcat(result[0], hor_bar[hor[digit][0]]);
			strcat(result[0], " ");
            //1번 - 윗쪽 세로 bar
			strcat(result[1], ver_bar[ver[digit][0]]);
			strcat(result[1], hor_bar[0]);
			strcat(result[1], ver_bar[ver[digit][1]]);
            //2번째 - 맨 윗줄 가로 bar
			strcat(result[2], " ");
			strcat(result[2], hor_bar[hor[digit][1]]);
			strcat(result[2], " ");
            //3번 - 윗쪽 세로 bar
			strcat(result[3], ver_bar[ver[digit][2]]);
			strcat(result[3], hor_bar[0]);
            strcat(result[3], ver_bar[ver[digit][3]]);
            //4번 - 맨 윗쪽 가로 bar
			strcat(result[4], " ");
			strcat(result[4], hor_bar[hor[digit][2]]);
			strcat(result[4], " ");
		}

		puts(result[0]);
		for(i = 0; i < s; i++)
		{
			puts(result[1]);;
		}
		puts(result[2]);
		for(i = 0; i < s; i++)
		{
			puts(result[3]);
		}
		puts(result[4]);
		putchar('\n');

		hor_bar[0][s] = " ";
		hor_bar[1][s] = "-";
		scanf("%d", &s);
	}
}




