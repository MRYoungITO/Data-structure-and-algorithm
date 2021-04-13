#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//结构, 就是程序员自定义的一种"数据类型"
struct student {
	char name[16];
	int age;
	char tel[12];
};

//结构体包含结构体的情况
struct _class {
	struct student martin;
	struct student rock;
	struct student zsf;
};

int main3(void) {

	//结构体的初始化
	//方式一	定义的时候初始化所有的属性
	struct student rock = { "Rock",38,"******" };

	printf("rock的姓名: %s, 年龄: %d, 电话: %s\n", rock.name, rock.age, rock.tel);

	//方式二	定义的时候我们可以指定初始化的属性	VS/VC编译器不支持, 但gcc编译器是支持的
	//struct student s1 = { .name = "张三丰",.age = 100 };

	//方式三	单独初始化每一个属性
	struct student s2;
	strcpy_s(s2.name, sizeof(s2.name), "杨过");
	s2.age = 40;
	s2.tel[0] = '\0';

	printf("杨过的姓名: %s, 年龄: %d, 电话: %s\n", s2.name, s2.age, s2.tel);

	//结构体中含有结构体
	struct _class c1 = { {"Martin",38,"18684518289"} ,{"Rock",38,"******"},{"张三丰",100,""} };
	printf("c1班Martin同学的姓名: %s, 年龄: %d, 电话: %s\n", c1.martin.name, c1.martin.age, c1.martin.tel);

	system("pause");
	return 0;
}