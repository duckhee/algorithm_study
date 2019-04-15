/**
 * 일년에 한 반씩 다른 여행지로 여행을 가는 학생 모임이 있다. 그 학생들은 지금까지 인디애나폴리스, 피닉스, 내시빌, 필라델피아, 산호세, 아틀란타를 여행했다.
 * 이번 봄에는 아인트호벤으로 여행을 갈 계획이다.
 * 
 * 이 학생들은 여행 경비를 모두 똑같이 부담하기로 합의 했지만, 돈을 쓸 때마다 나눠서 내는 것은 별로 실용적이지 못하다. 그래서 한 명씩 식비, 호텔비, 택시비, 비행기표를
 * 부담하기로 한다. 여행이 끝난 후에 각 학생이 지출한 내역을 계산한 다음 1센트 단위 내에서 모든 학생들이 쓴 돈이 같도록 돈을 주고 받는다. 하지만, 이전 여행의 경험에 비
 * 추어 보면 돈을 주고 받는 과정은 정말 지루하고 오랜 시간을 요하는 작업이 었다. 지출 내역이 주어 졌을 때 모든 학생이 쓴 돈이 (1센트 단위 내에서) 똑같아 지기 위해 전달 되어야
 * 하는 최소 금액을 구해보자.
 * 
 * 입력 표준 입력을 통해 여려 번의 여행에 대한 정보가 입력된다. 각 여행은 여행에 참가한 학생 수를 나타 내는 정수 n으로 구성된다. 이 정수 밑으로는 
 * n개의 줄이 입력된는데, 각 줄에는 달러와 센트 단위로 각 학생이 지출한 경비가 입력된다. 학생 수는 1000명을 넘지 않으며 어떤 항생도 %10,000.00 이상
 * 지출하지 않는다. 마지막 여행에 대한 정보 다음 줄에는 0만 들어 있는 줄이 입력된다.
 * 
 * 
 * 1 입력 3 10.00 20.00 30.00
 * 1 출력 $10.00
 * 2 입력 4 15.00 15.001 3.00 3.01
 * 2 출력 $11.59
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int compare(const void *arg1, const void *arg2)
{
	int p1, p2;

	p1 = *(int *)arg1;
	p2 = *(int *)arg2;

	return (p2-p1);

}

int money_spent[1000];
int money_must_spent[1000];

void main()
{
	while(1)
	{
		int i , n;
		int all_money_spent = 0;
		int each_money_spent;
		int money_exchange = 0;

		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			double temp;
			scanf("%lf", &temp);
			money_spent[i] = (int)(temp*100+0.5);
			all_money_spent += money_spent[i];
		}
		/**
		 * 퀵 정렬
		 */ 
		qsort((void *)money_spent, (size_t)(i), sizeof(int), compare);
		//평균 구하rl
		each_money_spent = all_money_spent / n;

		for(i = 0; i < n; i++)
		{
			money_must_spent[i] = each_money_spent;
		}

		all_money_spent %= n;

		for(i = 0; i < all_money_spent; i++)
		{
			money_must_spent[i]++;
		}

		for(i = 0; i < n; i++)
		{
			// 절대값
			money_exchange += abs(money_spent[i] - money_must_spent[i]);
		}
		money_exchange /= 2;

		printf("$%.2f\n", money_exchange / 100.0);
	}
}



