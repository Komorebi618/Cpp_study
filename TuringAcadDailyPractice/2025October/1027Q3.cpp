#include <stdio.h>

int main() {
	int x, theA = 0, Uim = 0, theB = 0, girl = 0;
	bool isEven, btwFourTwelve;
	// 对应性质1：偶数与否；性质2：是否4<x<=12
	printf("请输入一个整数：");
	scanf("%d", &x);
	isEven = (x%2 == 0);
	// 判断x是否为偶数
	btwFourTwelve = (x>4 && x<=12);
	// 判断x是否在4到12之间(不含4，含12)

	if (isEven && btwFourTwelve) {
		// 同时满足两个性质
		theA = 1;
	}
	if (isEven || btwFourTwelve) {
		// 满足至少一个性质
		Uim = 1;
	}
	if (isEven ^ btwFourTwelve) {
		// 仅满足一个性质(异或，只有两个输入不同时结果为真)
		theB = 1;
	}
	if (!(isEven || btwFourTwelve)){
		// 两个性质都不满足(取反)
		girl = 1;
	}

	printf("%d %d %d %d", theA, Uim, theB, girl);
	// 输出结果，"%d %d %d %d" 格式化输出使四个变量间以空格分隔
	return 0;
}
