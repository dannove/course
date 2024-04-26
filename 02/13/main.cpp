#include <cstdio>
#include <memory>

struct C {
    C() {
        printf("分配内存!\n");
    }

    ~C() {
        printf("释放内存!\n");
    }
};

int main() {
    // make_unique<C>(...)可以理解为等价于new C(...)
    // 括号里也可以有其他构造函数的参数
    std::unique_ptr<C> p = std::make_unique<C>();

    if (1 + 1 == 2) {
        printf("出了点小状况……\n");
        return 1;  // 自动释放 p
    }

    return 0;  // 自动释放 p
}
