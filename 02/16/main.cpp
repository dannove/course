#include <cstdio>
#include <memory>

struct C {
    C() {
        printf("分配内存!\n");
    }

    ~C() {
        printf("释放内存!\n");
    }

    void do_something() {
        printf("成员函数!\n");
    }
};

// 解决方案1：获取原始指针（C*这种类型的指针）
// func()实际上并不需要“夺走”资源的占有权，只是调用了p的某个成员函数而已，
// 并没有接管对象生命周期
void func(C *p) {
    p->do_something();
    p = nullptr; // c++指针是按值传递的
    //当你将一个指针作为参数传递给一个函数时，你实际上是传递了指针变量自身的值，也就是它所存储的内存地址。函数内部接收到的是一个指向相同内存位置的指针副本。这个副本和原始指针指向的是同一块内存区域，但它们是不同的指针变量，有自己的存储位置
    //函数内部，我们尝试将ptr设置为nullptr。然而，这个修改只会影响函数内部的ptr副本，而不会影响main函数中的originalPtr
}

int main() {
    std::unique_ptr<C> p = std::make_unique<C>();
    func(p.get()); //调用get获取原始指针
    func(p.get());
    const char* name = "name";
    //name[1]= 'p';
    const char* color = "red";
    name = color; 
    return 0;
}
