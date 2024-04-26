// unique_ptr 将delete p; p=nullptr;封装成一个操作：
// 只需要 p = nullptr; // 等价于：p.reset()
// 即可。 也不会保留着一个空悬指针，体现了面向对象“封装：不变性”的思想。
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
    std::unique_ptr<C> p = std::make_unique<C>();
    //C * pc = new C;
    printf("提前释放……\n");
    p = nullptr;
   // pc = nullptr; // 普通指针不delete直接令等于nullptr会内存泄漏，造成野指针
    printf("……释放成功\n");

    return 0;  // p 不会再释放一遍
}
