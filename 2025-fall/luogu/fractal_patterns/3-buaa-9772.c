#include<stdio.h>
int pow_3[8] = {1};
char canvas[6562][6562];
void draw(int x, int y, int n){
    if(n == 1){
        canvas[x][y] = '\\';
        canvas[x][y + 2] = '/';
        canvas[x + 1][y + 1] = 'x';
        canvas[x + 2][y] = '/';
        canvas[x + 2][y + 2] = '\\';
    }else{
        int sub_size = pow_3[n - 1];
        draw(x, y, n - 1);
        draw(x, y + 2 * sub_size, n - 1);
        draw(x + sub_size, y + sub_size, n - 1);
        draw(x + 2 * sub_size, y, n - 1);
        draw(x + 2 * sub_size, y + 2 * sub_size, n - 1);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <=n; i++){
        pow_3[i] = pow_3[i - 1] * 3;
    }
    int size = pow_3[n];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            canvas[i][j] = ' ';
        }
    }
    draw(0, 0, n);
    for(int i = 0; i < size; i++){
        puts(canvas[i]);
    }
    return 0;
}