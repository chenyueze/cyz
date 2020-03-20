/*************************************************************************
    > File Name: Emma2048.cpp
    > Author: chenyueze
    > Mail: 1536667332@qq.com 
    > Created Time: 一  3/16 19:20:58 2020
    > F5编译运行 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2048 is (4 * 4) 
char body[] = "-------------------------------------------------------------\n";
int nums[6][6] = {0};
int StartGameFlag  = 1;
int Scoll = 0;

void initNums(){
	for(int i = 0; i <= 5; i++){
		nums[0][i] = 1;
		nums[i][0] = 1;
		nums[i][5] = 1;
		nums[5][i] = 1;
	}
}

void outputNums(){
	Scoll = 0;
	printf("%s", body);
	printf("type 'w, a, s, d' to move.\n");
	printf("%s", body);
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			Scoll += nums[i][j];
			if(nums[i][j] == 0){
				printf("		");
			}else{
				printf("%d		", nums[i][j]);
			}
		}
		printf("\n\n\n");
	}
	printf("%s", body);
	printf("Curent Scoll :_%d_    ", Scoll);
	printf("Press 'G' to quit.\n");
	printf("%s", body);
}

void  randNums(){
	int randbase = 0;
	int randall = 0;
	int randsun = 2;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			if(nums[i][j] == 0){
				randbase += 1;
			}
		}
	}

	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			if(nums[i][j] == 0 && randall < 2){
				srand(time(0));
				if(rand() % randbase < randsun){
					nums[i][j] = 2;
					randall += 1;
					randsun -= 2;
				}else{
					randsun += 1;
				}
			}
		}
	}
}

void moveup();
void movedown();
void moveleft();
void moveright();

void StartGame(){ 	
	system("stty raw");
	char dir = getchar();
	system("stty -raw");
	switch (dir) {
		case 'w' :
		case 'W' : {
					   moveup();
					   moveup();
					   moveup();
					   StartGameFlag = 1;
				   };
				   break;
		case 's' :
		case 'S' : {
					   movedown();
					   movedown();
					   movedown();
					   StartGameFlag = 1;
				   };
				   break;
		case 'a' :
		case 'A' : {
					   moveleft();
					   moveleft();
					   moveleft();
					   StartGameFlag = 1;
				   };
				   break;
		case 'd' :
		case 'D' : {
					   moveright();
					   moveright();
					   moveright();
					   StartGameFlag = 1;
				   };
				   break;
		case 'g' :
		case 'G' : StartGameFlag = 0;
				   break;
		default :{
					 printf("please input 'w' for up , 's' for down , 'a' for left , 'd' for right.\n");
					 StartGameFlag = 2;
				 };
	}
}

void moveup(){
	for(int i = 1; i < 4 ; i++){
		for(int j = 1; j <= 4; j++){
			if(nums[i + 1][j] == 0) continue;
			if(nums[i][j] == 0) {
				nums[i][j] = nums[i + 1][j];
				nums[i + 1][j] = 0;
			}
			if(nums[i][j] != nums[i + 1][j]) continue;
			else {
				nums[i][j] += nums[i + 1][j];
				nums[i + 1][j] = 0;
			}
		}
	}	
}

void movedown(){
	for(int i = 4; i > 1; i--){
		for(int j = 1; j <= 4; j++){
			if(nums[i - 1][j] == 0) continue;
			if(nums[i][j] == 0){
				nums[i][j] = nums[i - 1][j];
				nums[i - 1][j] = 0;
			}
			if(nums[i][j] != nums[i - 1][j]) continue;
			else{
				nums[i][j] += nums[i - 1][j];
				nums[i - 1][j] = 0;
			}
		}
	}
}

void moveleft(){
	for(int j = 1; j < 4; j++){
		for(int i = 1; i <= 4; i++){
			if(nums[i][j + 1] == 0) continue;
			if(nums[i][j] == 0){
				nums[i][j] = nums[i][j + 1];
				nums[i][j + 1] = 0;
			}
			if(nums[i][j] != nums[i][j + 1]) continue;
			else {
				nums[i][j] += nums[i][j + 1];
				nums[i][j + 1] = 0;
			}
		}
	}
}

void moveright(){
	for(int j = 4; j > 1; j--){
		for(int i = 1; i <= 4; i++){
			if(nums[i][j - 1] == 0) continue;
			if(nums[i][j] == 0){
				nums[i][j] = nums[i][j - 1];
				nums[i][j - 1] = 0;
			}
			if(nums[i][j] != nums[i][j - 1]) continue;
			else{
				nums[i][j] += nums[i][j - 1];
				nums[i][j - 1] = 0;
			}
		}
	}
}


int main(){
	printf("running 2048.\n");
	initNums();
	while(StartGameFlag != 0){
		if(StartGameFlag == 1){
			randNums();
			outputNums();
		}
		StartGame();
	}
	printf("%s", body);
	printf("Are you have a good time, Master?\n");
	printf("%s", body);
	return 0;
}
