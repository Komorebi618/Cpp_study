// 此题解为C语言
#include <stdio.h>
#define PI 3.14

int main() {
    int l;
	printf("输入正方形边长（整数）：");
	scanf("%d", &l);

	float area_square = l * l; 
	// 计算正方形面积
	float area_circle = PI * l / 2 * l / 2; 
	// 计算圆面积，注意l为直径，其半径为l/2
	// 在这里发生了隐式类型转换，乘PI时已经转换为float/double类型。
	// 但是为了避免潜在的精度缺失问题，建议显式地将l转换为float类型：
	// float area_circle = PI * (float)l/ 2 * float(l)/2;

	printf("边长为%d的正方形面积比直径为%d的圆面积大：%.2f", l, l, area_square-area_circle);
	// 注意使用 %.2f 表示输出浮点数时保留两位小数
    return 0;
}