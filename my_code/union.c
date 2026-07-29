#include <stdio.h>

// 共同体：所有成员共享同一块内存
union Peek {
    int num;
    unsigned char bytes[4];
};

int main() {
    union Peek p;
    p.num = 0x12345678;

    printf("数字 0x12345678 在内存里长这样：\n");
    printf("字节0: 0x%02X\n", p.bytes[0]);
    printf("字节1: 0x%02X\n", p.bytes[1]);
    printf("字节2: 0x%02X\n", p.bytes[2]);
    printf("字节3: 0x%02X\n", p.bytes[3]);

    // 判断大小端
    if (p.bytes[0] == 0x78) {
        printf("\n你的电脑是小端模式 (Little Endian)！\n");
        printf("意思就是：低位字节存在低地址，反过来存的\n");
    } else {
        printf("\n你的电脑是大端模式 (Big Endian)！\n");
    }

    printf("\n按回车键退出...");
    getchar();
    return 0;
}