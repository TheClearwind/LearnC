﻿#include <wchar.h>
#include <locale.h>
#include<stdlib.h>
int main() {
	wchar_t a = L'A';  //英文字符（基本拉丁字符） 宽字符类型 采用Unicoda编码
	wchar_t b = L'9';  //英文数字（阿拉伯数字）
	wchar_t c = L'中';  //中文汉字
	wchar_t d = L'国';  //中文汉字
	wchar_t e = L'。';  //中文标点
	wchar_t f = L'ヅ';  //日文片假名
	wchar_t g = L'♥';  //特殊符号
	wchar_t h = L'༄';  //藏文

	//将本地环境设置为简体中文
	setlocale(LC_ALL, "zh_CN");

	//使用专门的 putwchar 输出宽字符
	putwchar(a);  putwchar(b);  putwchar(c);  putwchar(d);
	putwchar(e);  putwchar(f);  putwchar(g);  putwchar(h);
	putwchar(L'\n');  //只能使用宽字符

    //使用通用的 wprintf 输出宽字符
	wprintf(
		L"Wide chars: %lc %lc %lc %lc %lc %lc %lc %lc\n",  //必须使用宽字符串
		a, b, c, d, e, f, g, h
	);

	system("pause");
	return 0;
}