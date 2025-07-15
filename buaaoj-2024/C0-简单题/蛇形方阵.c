#include<stdio.h>
int Mat[20][20]={0};
int main(){
	int n;
	scanf("%d",&n);	
	int x=1,y=1,num=1;
	while(num<n*n){
		while(y<n && !Mat[x][y+1]){
			Mat[x][y++]=num++;
		}
		while(x<n && !Mat[x+1][y]){
			Mat[x++][y]=num++;
		}
		while(y>1 && !Mat[x][y-1]){
			Mat[x][y--]=num++;
		}
		while(x>1 && !Mat[x-1][y]){
			Mat[x--][y]=num++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(Mat[i][j]==0){
				printf("%3d",n*n);
				Mat[i][j]=0;
				continue;
			}
			printf("%3d",Mat[i][j]);
			Mat[i][j]=0;
		}
		puts("");
	}
	return 0;
}