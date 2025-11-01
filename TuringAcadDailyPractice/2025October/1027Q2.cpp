// 此题解为C语言
#include <stdio.h>

int main() {
	int n = 0, score = 0;
	printf("请输入做对的题目数量（整数）：");
	scanf("%d", &n);

	if(n < 0 || n > 40) {
		printf("输入错误！0<=n<=40\n");
		return 1;
	}
	// 输入验证，确保n在题目要求范围内
	else {
		if(n <= 10) {
			score = n*6;
		} else if(n <= 20) {
			score = 10*6 + (n-10)*2;
			// 前10题每题6分(共10*6分)，接下来的每题2分
		} else {
			score = 10*6 + 10*2 + (n-20)*1;
			// 前10题每题6分(共10*6分)，接下来的10题每题2分(共10*2分)，剩下的每题1分
		}
		printf("你的得分是：%d分", score);
	}

	return 0;
}