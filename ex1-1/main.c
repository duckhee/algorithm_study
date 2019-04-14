/**
 * 어떤 수열을 만들어 내는 다음과 같은 알고리즘을 생각해보자. 어떤 정수 n에서 시작해 n이 짝수 이면
 * 2로 나누고, 홀수면 3을 곱한 다음 1을 더한다. 이렇게 해서 새로 만들어진 숫자를 n으로 놓고 n=1이 
 * 될 때까지 같은 작업을 계속 반복한다. 예를 들어, n = 22이면 다음과 같은 수열이 만들어진다.
 * 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
 * 아직 증명되지 않았지만, 모든 정수 n에 대해 이알고리즘을 적용 시키면 결국에는 n = 1에 이르게 되는 것으로 
 * 추측된다. 그리고 이 가설은 적어도 1,000,000까지의 정수에 대해서 참이다.
 * n이라는 값이 입력 되었을 때 1이 나올 때까지 만들어진 수의 개수(1포함)를 n의 사이클 길이라고 한다.
 * 위에 있는 수열을 예로 들면 22의 사이클 길이는 16이다. i와j라는 두 개의 수가 주어졌을 때 i와 j사이의
 * 모든 수(i,j 포함)에 대해 최대 사이클 길이를 구하라
 * 
 * 입력 
 * 입력은 일련의 정수 쌍 i와 j로 구성되며  한 줄에 한쌍의 수가 입력된다. 모든 정수는 1,000,000보다 작고
 * 0보다 크다.
 * 출력
 * 각 정수쌍 i와j에 대해 i와j를 입력된 순서대로 출력하고 i와j사이(i,j 포함)의 최대 사이클 길이를 출력한다. 
 * 이 세 수는 각각 하나씩의 스페이스로 구분 되어햐 하며 세수가 모두 한 줄에 출력되어야 하고 
 * 입력된 각 줄마다 한 줄 씩 출력 해야한다.
 * 
 * 입력 예
 * 1 10          1 10 20
 * 100 200       100 200 125
 * 201 210       201 210 89
 * 900 1000      900 1000 174
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    long lbound, ubound, lbOrg, ubOrg, temp;
    long i, j, length, max_length;

    while(scanf("%ld %ld", &lbound, &ubound) == 2){
        lbOrg = lbound;
        ubOrg = ubound;
        if(lbound > ubound)
        {
            temp = lbound;
            lbound = ubound;
            ubound = temp;
        }
        max_length = 0;
        for(i = lbound; i <= ubound; i++)
        {
            j = i;
            length = 1;
            while(j != 1){
                if(j&1)
                {
                    j = j *3+1;
                    length++;
                }
                while(!(j&1))
                {
                    j >>= 1;
                    length++;
                }
            }
            if(length > max_length)
            {
                max_length = length;
            }
        }
        printf("%ld %ld %ld\r\n", lbOrg, ubOrg, max_length);
    }
    return 1;
}