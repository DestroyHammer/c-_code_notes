#include <memory>

class example
{
public:
  int i = 0;
};

int main()
{
  // 创建智能指针
  std::shared_ptr<example> spt0(new example);
  std::shared_ptr<example> spt1 = std::make_shared<example>();
  
  // 已有对象，转为智能指针
  // 产生的智能指针不指向aa本身，而是另一块拷贝aa内容的空间
  example aa;
  std::shared_ptr<example> spt2 = std::make_shared<example>(aa);  
  std::shared_ptr<example> spt3(new example(aa));
  
  // 已有指针，转为智能指针
  // 注意，这里bb和spt4指向同一块空间。若使用bb初始化多个shared_ptr是，会产生double free错误。
  // 实际上应避免将裸指针转为智能指针
  example *bb = new example;
  std::shared_ptr<example> spt4(bb);
  
  // 智能指针赋值
  // spt0原指向的对象引用计数减1；spt0指向spt2指向的对象，且引用计数加1
  spt0 = spt2;
  
  // reset方法
  // 原指向的对象引用计数减1，并指向新的对象
  // 其参数类型为裸指针，参数为空时变成nullptr
  spt0.reset();
  spt0.reset(new example);
  
  
