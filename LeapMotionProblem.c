#include <stdio.h>
#include <string.h>

/* We have  give a change for a specific sum with least number of coins.
The only coins you have in hand are 1,3,10,15. For.e.g, to give change for $17
, you need 3 coins : one $15 and two $1. Alternately, 
you could have given 4 coins: one $10, two $3 and one $1.
But this will have one more coin than the first option. So first answer is the correct
one
*/

int coins[] = {1,3,10,15};

int CoinCount(int c,int number, int* coinCount,int i){
	int div,rem;
	coinCount[i] = number/c;
	if(coinCount[i]<1)
		return -1;
	rem =  number%c;
	//printf("Level1: coinCount[%d]=%d,rem=%d\n",i,coinCount[i],rem);
	if(rem>=10){
		coinCount[2] += rem/10;
		rem %= 10;
		//printf("Level2: coin10Count=%d,rem=%d\n",coinCount[2],rem);
	}
	if(rem>=3){
		coinCount[1] += rem/3;
		rem %= 3;
		//printf("Level2: coin3Count=%d,Coin1Count=%d\n",coinCount[1],coinCount[0]);
	}
	coinCount[0] += rem;
	printf("With Coin denomination %d, it will taken %d coins to get %d\n",\
		c,coinCount[0]+coinCount[1]+coinCount[2]+coinCount[3],number);
	return coinCount[0]+coinCount[1]+coinCount[2]+coinCount[3];
	
}

int main(int argc, char** argv){
	int input=38;
	int min = input;
	int coinCount[]={0,0,0,0};
	int finalCount[]={0,0,0,0};
	int retVal;
	/*loop through all coin denominations, and if totalCouns < min, make that
	new min*/
	
	for (int i =0;i<sizeof(coins)/sizeof(*coins);i++){
		memset(coinCount,0,sizeof(coinCount));
		retVal = CoinCount(coins[i],input,coinCount,i);
		if(retVal>0 && retVal < min){
			min = retVal;
			memcpy(finalCount,coinCount,sizeof(coinCount));
		}
	}
	printf("To get number %d, we use %d coins:\n Denomination1 coins = %d\n Denomination3 coins = %d\n Denomination10 coins = %d\n Denomination15 coins = %d\n",input,min,finalCount[0],finalCount[1],finalCount[2],finalCount[3]);

	return 0;
}
