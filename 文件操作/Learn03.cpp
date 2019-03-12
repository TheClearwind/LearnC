#include<stdio.h>
#include<stdlib.h>
#define N 2
struct stu {
	char name[10]; //姓名
	int num;  //学号
	int age;  //年龄
	float score;  //成绩
}boya[N], boyb[N], *pa, *pb;
int main()
{
	//fread() fwrite()
	//使用fread,fwrite时,推荐使用二进制打开
	/*
	fread() 函数用来从指定文件中读取块数据。所谓块数据，也就是若干个字节的数据，可以是一个字符，可以是一个字符串，可以是多行数据，并没有什么限制。fread() 的原型为：
	size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );
	fwrite() 函数用来向文件中写入块数据，它的原型为：
	size_t fwrite ( void * ptr, size_t size, size_t count, FILE *fp );
	对参数的说明：
	ptr 为内存区块的指针，它可以是数组、变量、结构体等。fread() 中的 ptr 用来存放读取到的数据，fwrite() 中的 ptr 用来存放要写入的数据。
	size：表示每个数据块的字节数。
	count：表示要读写的数据块的块数。
	fp：表示文件指针。
	理论上，每次读写 size*count 个字节的数据
	*/
	FILE *fp;
	int i;
	pa = boya;
	pb = boyb;
	if ((fp = fopen("demo.txt", "wb+")) == NULL) {
		puts("Fail to open file!");
		exit(0);
	}
	//从键盘输入数据
	printf("Input data:\n");
	for (i = 0; i<N; i++, pa++) {
		scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
	}
	//将数组 boya 的数据写入文件
	fwrite(boya, sizeof(struct stu), N, fp);
	//将文件指针重置到文件开头
	rewind(fp);
	//从文件读取数据并保存到数据 boyb
	fread(boyb, sizeof(struct stu), N, fp);
	//输出数组 boyb 中的数据
	for (i = 0; i<N; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
	}
	fclose(fp);
	system("pause");
	return 0;
}