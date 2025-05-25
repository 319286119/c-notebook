#include <chrono>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string.h>
#include <system_error>
#include <utility>
/*int main()
{
    float a=3.14f;
    float b=3e2;//3*10*10
    char c='d';
    //cin>>a;
    cout<<c<<endl;
    cout<<"a="<<a<<endl;
    cout<<"hello world"<<endl;
    cout<<sizeof(int)<<endl;
    return 0;
}*///cout

/*int main()
{
    char a='a';
    string b="hello";
    cout<<b<<endl;
    cout<<"hello\n";
    cout<<(int)a<<endl;

    return 0;
}*///string类型

/*int main()
{
    bool flag1=true;
    bool flag2=false;
    cout<<flag1<<endl;
    cout<<flag2;
    return 0;
}*/
/*int main()
{
    cout<<sizeof(int *);
    return 0;
}*///bool类型

/*int main()
{
    int*ps=new int(10);//new申请动态内存
    int*arr=new int[3];
    *arr=1;
    *(arr+1)=2;
    *(arr+2)=3;
    cout<<*ps<<endl<<*(arr+1);
    delete ps;//释放堆区内存
    delete[] arr;//数组内存释放
    return 0;
}*///c++中的动态内存new and delete

/*void swap(int&a,int&b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=1;
    int b=2;
    swap(a,b);
    cout<<a<<b;
    return 0;
}*/
/*int&test()
{
    static int a=10;//延长其寿命
    return a;
}

int main()
{
    int&b=test();//其内核是指针
    cout<<b<<endl;
    cout<<b<<endl;//若无static则其不为10
    test()=1000;//通过引用的方式修改了b
    cout<<b<<endl;//输出为1000
    return 0;
}*///引用

/*int main()
{
    const int&b=10;//加入const之后创建了一个temp，b为temp的别名
    return 0;
}*///引用的实质

/*int add(int a,int b,int c);//函数声明和实现不能同时有参数，若有则重定义。
int add(int a,int b,int c=10)//若该位置有了默认值，则该数后必须也有默认值
{
     return a+b+c;
}

int main()
{
    add(20,30);
    return 0;
}*///函数的默认参数

/*void func(int a,int=10)//占位参数
{
    cout<<a;
}
int main()
{
    func(10,10);
    return 0;
}*///函数的占位参数

/*函数重载的要求
1.在同一作用域下
2.函数名同名
3.函数的参数类型不同或者顺序不同或者个数不同*/
/*void func()
{
    cout<<"123"<<endl;
}
void func(int a)
{
    cout<<"123hh"<<endl;
}
void func(int a,int b=10)//不会与func(inta)发生重载
{
    cout<<"123h"
}
void func(const int&a)//不能与fun(int a)发生重载
{
    cout<<"111";
}
void func(int&a)
{
    cout<<"112";
}
int main()
{
    const int a=10;
    func(10);
    return 0;//函数返回值类型不同不能作为重载的条件
}*///函数重载

/*class Ccircle
{
    //访问权限
public://公共

    //属性:半径
    int m_r;
    double pi=3.14;
    //行为：获取圆的周长
    double caculate()
    {
        return 2*pi*m_r;
    }

};
int main()
{
    Ccircle c1;
    c1.m_r=10;
    cout<<c1.caculate();
    return 0;
}*///类和对象，封装

/*class Cpeople
{
    //访问权限
    //public:成员 类内可以访问，类外也可以访问
    //protected成员 类内可以访问，类外不可以访问
    //private成员 类内可以访问，类外不可以访问（其和protected的区别在继承）
public://公共
    string m_name;
protected://保护权限
    string m_car;
private://隐私权限
    int m_password;
public:
    void func()
    {
        m_name="lisi";
        m_car="bmw";
        m_password=12345;
        //类内皆可访问
    }
};
int main()
{
    Cpeople p;
    p.m_name="lisi";
    p.m_car="bmw";//访问失败
    p.m_password=1234;//访问失败
    return 0;
}*///封装：访问权限

//class默认权限为私有private；struct默认权限为公有public

/*class People
{
private:
    string m_name;//可写可读
    int m_age;//可读不可写
    string m_idol;//可写不可读
public:
    void set_name(string a)//写名字
    {
        m_name=a;
    }
    string wirte_name()//读名字
    {
        return m_name;
    }

    
};

int main()
{
    People p;
    p.set_name("lisi");//通过public完成对private的设置

    return 0;
}*///封装：成员属性设置成为私有后通过public中的函数完成属性设置

/*class Cperson
{
private:
   string m_name;
   int m_age;
   int m_tel;

public:
   //1.构造函数
   //没有返回值，不用写void
   //函数名与类名相同
   //构造函数可以发生重载
   //创建对象时自动调用，只调一次*
   Cperson()
   {
     m_age=18;
     m_tel=123;
     m_name="kyx";
     cout<<111<<endl;
   }
   //2.析构函数,进行清理操作
   //没有返回值，不写void
   //没有对象，不能发生重载
   //函数名和类名相同，在名称面前加~
   //对象在销毁前会自动调用析构函数，只调用一次
   ~Cperson()
   {
    cout<<"析构函数调用"<<endl;
   }
   void show()
   {
    cout<<m_age<<m_name<<m_tel;
   }
};
//构造和析构都是必须有的实现，如果不提供，编译器会提供一个空的构造和析构
int main()
{
    Cperson p;//栈上的数据，函数执行完毕后，释放这个对象
    
    return 0;
}*///构造函数和析构函数

//构造函数的分类
//无参构造，有参构造
//普通构造，拷贝构造
/*class Cperson
{
private:
  int age;
  string name;

public:
   //有无参
  Cperson()//无参
  {
    cout<<"wucan"<<endl;
  }
  Cperson(int a)//有参
  {
    cout<<"youcan"<<endl;
  }
  //拷贝构造
  Cperson(const Cperson &p)//将一个数据复制到另一个中
  {
    int age=p.age;
  }
};

void test()
{
    //括号法
    Cperson p;//调用无参
    Cperson p1(10);//调用有参构造
    Cperson p2(p);//拷贝构造函数
    
    //显式法
    Cperson p3;
    Cperson p4=Cperson(10);
    Cperson p5=Cperson(p4);
    //不要用拷贝函数初始化匿名对象

    //隐式构造
    Cperson p6=10;//有参
    Cperson p7=p6;//拷贝
}*/

/*class person
{
//编辑器默认提供默认构造，拷贝构造，析构
//定义有参，默认拷贝；
//定义拷贝，不再提供其他函数
public:
   int age;
   person()
   {
    cout<<"默认构造"<<endl;
   }
   person(int a)
   {
    cout<<"含参构造"<<endl;
    age=a;
   }
   person(const person&a)//若无该定义，有默认的拷贝构造函数
   {
    cout<<"拷贝构造"<<endl;
    age=a.age;
   }
   ~person()
   {
    cout<<"默认析构"<<endl;
   }
};
void test01()
{
    person p;//若写了有参构造，则不提供默认构造函数
    p.age=18;

    person p2(p);//编译器默认进行值拷贝
    cout<<"p2 age="<<p2.age<<endl;
}
int main()
{
    test01();
    return 0;
}*///编辑器默认的构造，析构函数

/*class person
{
public:
   int m_age;
   int*m_height;
   person(int age,int height)
   {
     m_age=age;
     m_height=new int(height);//堆区开辟
     cout<<"youcan"<<endl;
   }
   
   //编译器默认为浅拷贝，浅拷贝内存位于同一区域
   
   //自己设计拷贝构造函数来解决浅拷贝问题
   person(const person&a)
   {
    m_age=a.m_age;
    cout<<"kaobei"<<endl;
    m_height=new int(*a.m_height);//实现深拷贝的代码
   }

   ~person()
   {
     if(m_height!=NULL)
     { 
       delete(m_height);
       m_height=NULL;
     }
     cout<<"xigou"<<endl;
   }
};
void test1()
{
    person p1(18,166);
    cout<<p1.m_age<<*(p1.m_height)<<endl;
    person p2(p1);
    cout<<p2.m_age<<*(p2.m_height)<<endl;//若使用浅拷贝，则会导致程序崩溃;因为两者处于同一内存，delete了两次，直接崩溃
}
int main()
{
    test1();
    return 0;
}*///堆区深浅拷贝的问题

/*class person
{
public:
  int m_a;
  int m_b;
  int m_c;
  //传统初始化
  //person(int a,int b,int c)
  //{
    //m_a=a;
    //m_b=b;
    //m_c=c;
  //}
  //初始化列表
  person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
  {
    
  }
};

int main()
{
    person p(10,20,30);
    cout<<p.m_a<<p.m_b<<p.m_c<<endl;
    return 0;
}*///初始化列表

/*class phone
{
public:
   phone(string name)
   {
    m_pname=name;
    cout<<"phone"<<endl;
   }
   string m_pname;
};
class person
{
public:
   person(string name,string pname):m_name(name),m_phone(pname)
   {
      cout<<"person"<<endl;
   };
   string m_name;
   phone m_phone;

};
int main()
{
    person p("zhangsan","mi");
    cout<<p.m_name<<endl<<p.m_phone.m_pname;
    return 0;
}*///一个类中调用另一个类

/*class person
{
public:
   static int m_a;//类内定义
   
   static void func()//静态成员函数
   {
       m_a=30;//静态成员只能访问静态变量
       //m_b=100;//禁止访问非静态变量
       cout<<"jingtaihanshu";
   }
   int m_b;
//也有访问权限限制
};
int person::m_a=100;//类外初始化

int main()
{
    person p;
    cout<<p.m_a<<endl;
    person p1;
    p1.m_a=200;
    cout<<p.m_a<<endl;//静态成员不属于某一个成员，所有对象共用一份数据
    
    //1.通过对象访问
    cout<<p.m_a<<endl;
    p.func();
    
    //2.通过类名访问
    cout<<person::m_a<<endl;//无法访问私有权限
    person::func();
    
    return 0;
}*///静态成员

/*class person
{
   int m_a;//非静态成员变量，属于类对象
   static int m_b;//不属于类对象，不属于类对象
   void func()//不属于类对象
   {

   }
   static void func1()//不属于类对象
   {

   }
};
int m_b=10;

int main()
{
    person p;
    cout<<sizeof(p);//每个空对象都有一个独一无二的空地址
    //所以编译器会分配一个字节的内存
}*///静态成员和成员函数分开储存

/*class person
{
public:
    int age;
    person(int age)
    {
        //this指针指向被调用的成员函数所属的对象
        //在这里this指向p
        this->age=age;//1、解决名称冲突
    }
    person& person_addage(person &p)
    //若采用person为返回类型，则在链式调用时，会返回一个p1',p1''；非p1
    {
        age+=p.age;
        //2.返回值
        return *this;
    }
};
int main()
{
    person p(18);

    person p1(10);
    p1.person_addage(p).person_addage(p).person_addage(p);
    cout<<p1.age<<endl;
    return 0;
}*///this指针

/*class person
{
    public:
    void show_classname()
    {
        cout<<"this is classname"<<endl;
    }
    void show_personage()
    {
        cout<<"age="<<m_age<<endl;
        //相当于cout<<"age="<<this->m_age<<endl;
    }
    int m_age;
};
int main()
{
    person*p=NULL;
    p->show_classname();
    p->show_personage();//p为空导致的报错
    cout<<"123";
    return 0;
}*///空指针访问成员

/*class person
{
public:
   //this指针的本质是指针常量，指针的指向不可修改
   //在函数后加const修饰this指针使this指针指向对象的值无法被修改
   void show_person()const
   {
     age=10;//不加mutable会报错
     cout<<age;
   }
   void func()
   {
      age=10;
   }
   mutable int age;
};

int main()
{
    const person p;//常对象中非mutable不可修改
    
    //常对象只能调用常函数
    p.show_person();
    //p.func();

    return 0;
}*///const常函数和mutable

/*class building
{
    friend void goodgay(building&building);//友元函数
public:
    building()
    {
        m_sittingroom="keting";
        m_bedroom="woshi";
    }
    string m_sittingroom;
private:
    string m_bedroom;
};
void goodgay(building&building)
{
    cout<<"goodgay zhengzai fangwen"<<building.m_sittingroom<<endl;

    cout<<"goodgay zhengzai fangwen"<<building.m_bedroom<<endl;//加上freind之后可以访问私有成员
}
void test01()
{
    building building;
    goodgay(building);

}
int main()
{
    test01();
    return 0;
}*///全局函数做友元

/*class Building//房间类
{
    friend class Goodgay;//类做友元
public:
    Building();
    string m_sittingroom;//客厅
private:
    string m_bedroom;//卧室
    void test()
    {

    }
};

class Goodgay//好基友类
{
    friend void Building::test();//函数做友元
public:
    Goodgay();//构造函数
    void visit();//参观函数，访问building中的属性    
    Building*building;//Building类型的指针
    void visit1();
};

//类外实现构造函数
Building::Building()
{
    m_bedroom="woshi";
    m_sittingroom="keting";
}
Goodgay::Goodgay()
{
   building=new Building;//开辟一块类空间
}
void Goodgay:: visit()
{
    cout<<"visiting  "<<building->m_sittingroom<<endl;
    cout<<"visiting  "<<building->m_bedroom<<endl;
}
void test01()
{
    Goodgay gg;
    gg.visit();
}
int main()
{
    test01();
    return 0;
}*///类和函数做友元

/*class person
{
//运算符重载也可以发生函数重载
//内置数据类型是不可以改变的
//不要滥用运算符重载
public:    
    person operator+(person&p)//加号运算符重载
    {
        person temp;
        temp.m_a=this->m_a+p.m_a;
        temp.m_b=this->m_b+p.m_b;
        return temp;
    }
    int m_a;
    int m_b;
};
//全局函数重载
person operator+(person&p1,person&p2)
{
    person temp;
    temp.m_a=p1.m_a+p2.m_a;
    temp.m_b=p1.m_b+p2.m_b;
    return temp;
}
int main()
{
    person p1;
    p1.m_a=10;
    p1.m_b=20;
    person p2;
    p2.m_a=10;
    p2.m_b=20;
    person p3=p1+p2;
    //等价于(本质调用)
    //person p3=p1.operator+(p2);(类内实现重载的本质)
    cout<<p3.m_a<<p3.m_b<<endl;
    return 0;
}*///运算符重载

/*class person
{
    //在类内无法实现<<的重载无法实现cout在<<左边
    //其简化完为p<<cout
public:
    int m_a;
    int m_b;
};

ostream&operator<<(ostream&out,person &p)
{
    cout<<"m_a="<<p.m_a<<"m_b="<<p.m_b<<endl;
    return cout;
}

void test01()
{
    person p;
    p.m_a=10;
    p.m_b=10;
    cout<<p<<endl;
}
int main()
{
    test01();
    return 0;
}*///<<运算符的重载

/*class Myinteger
{
    friend ostream&operator<<(ostream&cout,Myinteger myint);
public:    

    //重载前置++运算符
    Myinteger& operator++()
    {
        m_num++;
        return *this;
    }

    //重载后置++运算符
    Myinteger operator++(int)
    {
        Myinteger temp=*this;
        m_num+=1;
        return temp;
    }
    Myinteger()
    {
        m_num=0;
    }
private:    
    int m_num;
};

ostream&operator<<(ostream&cout,Myinteger myint)
{
    cout<<myint.m_num;
    return cout;
}

void test01()
{
    Myinteger myint;
    cout<<++(++myint)<<endl;
    cout<<myint<<endl;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}
int main()
{
    test01();
    return 0;
}*///加加重载

/*class person
{
public:    
    person(int age)
    {
        m_age=new int(age);
    }
    int*m_age;
    //person(const person&p)
    //{
        //this->m_age=new int(*p.m_age);
    //}
    ~person()
    {
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
    }
    person& operator=(person&p)//重载赋值运算符的深拷贝
    {
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
        m_age=new int(*p.m_age);
        return *this;
    }
};

void test01()
{
    person p1(18);
    person p2(20);
    person p3(25);
    p2=p1=p3;
    cout<<"p1 age="<<*p1.m_age<<endl;
    cout<<"p2 age="<<*p2.m_age<<endl;
}

int main()
{
    test01();
    return 0;
}*///重载赋值运算符

/*class person
{
public:    
    string m_name;
    int m_age;
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    bool operator==(const person&p)//比较字符的重载
    {
        if(m_age==p.m_age&&m_name==p.m_name)
        {
            return true;
        }
        return false;
    }
};
void test01()
{
   person p1("tom",18);
   person p2("tim",18);
   if(p1==p2)
   {
     cout<<"xiangdeng"<<endl;
   }
   else 
   {
     cout<<"buxiangdeng"<<endl;
   }
}
int main()
{
    test01();
    return 0;
}*///比较运算符的重载

/*class Myprint
{
public:
    void operator()(string str)//重载（），使用起来类似于函数，称为仿函数
    {
        cout<<str<<endl;
    }
};
void test01()
{
    Myprint myprint;
    Myprint()("hello");//匿名对象写法
    myprint("hello world");//创建对象写法
}
int main()
{
    test01();
    return 0;
}*///（）重载，仿函数

/*class java//其他种类如cpp、python有很多重复的栏目
{
public:
    void header()
    {
        cout<<"shouye"<<endl;
    }
    void footer()
    {
        cout<<"bangzhuzhongxin"<<endl;
    }
    void left()
    {
        cout<<"python,java"<<endl;
    }
    void content()
    {
        cout<<"xuekeshiping"<<endl;
    }
};
class python
{
public:
    void header()
    {
        cout<<"shouye"<<endl;
    }
    void footer()
    {
        cout<<"bangzhuzhongxin"<<endl;
    }
    void left()
    {
        cout<<"python,java"<<endl;
    }
    void content()
    {
        cout<<"xuekeshiping"<<endl;
    }
};
void test01()
{
    java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    python py;
    py.header();
    py.footer();
    py.left();
    py.content();
}//不使用继承实现
//上面功能用继承实现形式如下
//继承的好处
//子类继承父类
//子类称为派生类；父类成为基类
class basepage
{
public:
   void header()
    {
        cout<<"shouye"<<endl;
    }
    void footer()
    {
        cout<<"bangzhuzhongxin"<<endl;
    }
    void left()
    {
        cout<<"python,java"<<endl;
    }
};

//java页面
class java:public basepage//继承的语法
{
public:
    void content()
    {
        cout<<"java"<<endl;
    }
};

//python页面
class python:public basepage
{
public:
    void content()
    {
        cout<<"python"<<endl;
    }
};

void test01()
{
    
}

int main()
{
    test01();
    return 0;
}*///继承的基本语法

/*class father
{
    public:
    int m_a=10;
    protected:
    int m_b=20;
    private:
    int m_c=30;
};
//private无法被继承
class son1:public father
{
    //父类权限不变
};

class son2:protected father
{
    //公共和保护权限都变为保护权限
};

class son3:private father
{
    //都变为私密权限
};

int main()
{
    son1 p1;
    son2 p2;
    son3 p3;
    return 0;
}*///继承中的权限改变

/*class base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class son:public base
{
public:
    int m_d;
};

int main()
{
    cout<<sizeof(son);//16,父类中的私有属性被编译器隐藏了
    return 0;
}*///继承中的对象模型

/*class base
{
public:
   base()
   {
    cout<<"base gou zao"<<endl;
   }
   ~base()
   {
    cout<<"base xi gou"<<endl;
   }
};

class son:public base
{
public: 
   son()
   {
     cout<<"son gou zao"<<endl;
   }
   ~son()
   {
    cout<<"son xi gou"<<endl;
   }
};

int main()
{
    son p1;//继承中构造先父后子，析构先子后父
    return 0;
}*///构造和析构顺序

/*class base
{
public:
    int m_a=100;
    void func()
    {
        cout<<"base-func"<<endl;
    }
    void func(int a)
    {

    }
};

class son:public base
{
public:
    int m_a=200;
    void func()
    {
        cout<<"son-func"<<endl;
    }
};

int main()
{
    son p1;
    //因为先构造父类后构造子类所以直接输出是子类
    //加作用域可以使用父类
    cout<<"son下m_a="<<p1.m_a<<endl;
    cout<<"base下m_a="<<p1.base::m_a<<endl;
    p1.func();
    p1.base::func();
    p1.base::func(10);
    cout<<sizeof(son)<<endl;
    return 0;
}*///子类和父类有同名成员

/*class base
{
public:
    static int m_a;
};
int base::m_a=100;

class son:public base
{
public:
    static int m_a;
};
int son::m_a=200;

int main()
{
    son p1;
    //通过对象访问
    cout<<"son-m_a="<<p1.m_a<<endl;
    cout<<"base-m_a="<<p1.base::m_a<<endl;
    //通过类名访问
    cout<<"son-m_a="<<son::m_a<<endl;
    cout<<"base-m_a="<<son::base::m_a<<endl;
    //静态函数同理
    return 0;
}*///同名静态成员处理

/*class base1 
{
public:
    int m_a;
    base1()
    {
        m_a=100;//
    }
};

class base2 
{
public:
    int m_a;//
    int m_b;
    base2()
    {
        m_a=200;
        m_b=200;
    }
};

class son:public base1,public base2//多继承(不推荐)中存在同名变量
{
public:
    int m_c;
    int m_d;
    son()
    {
        m_c=300;
        m_d=400;
    }
};

int main()
{
    son p1;
    cout<<sizeof(p1);
    cout<<p1.base1::m_a<<endl;//有同名变量要加作用域
    return 0;
}*///多继承语法


/*class animal//动物类
{
public:
   int m_age;
};
//使用虚继承解决菱形继承
//animal为虚基类
//羊类
class sheep:virtual public animal
{

};
//驼类
class tuo:virtual public animal
{

};
//羊驼类
class sheeptuo:public sheep,public tuo
{
   
};
int main()
{
    sheeptuo p1;
    //羊一份，驼一份
    p1.sheep::m_age=18;
    p1.tuo::m_age=28;
    //菱形继承时，两个父类拥有相同的数据，需要加以作用域区分
    cout<<"sheep-age="<<p1.sheep::m_age<<endl;
    cout<<"tuo-age="<<p1.tuo::m_age<<endl;
    cout<<p1.m_age;//虚继承将两个同名变为了一个
    return 0;
}*///菱形继承

/*class animal
{
    public:
    virtual void speak()////
    {
       cout<<"animal"<<endl;
    }
};
//动态多态满足条件
//1.有继承关系
//2.子类“重写”父类虚函数
//3.
class cat:public animal
{
public:
    void speak()
    {
        cout<<"cat"<<endl;
    }
};
class dog:public animal
{
    public:
    void speak()
    {
        cout<<"dog"<<endl;
    }
};

void dospeak(animal&animal)//父类的引用来指向子类对象
{
    animal.speak();
}

int main()
{
    cat p1;
    dospeak(p1);//输出动物，因为地址在编译阶段早绑定
    //如果想执行让猫说话，那函数地址不能提前绑定
    dog p2;
    dospeak(p2);
}*///多态的基本语法

/*class animal
{
    public:
    virtual void speak()//是虚函数指针
    {
        cout<<"animal"<<endl;
    }
};
//当子类重写父类的虚函数
//子类中的虚函数表内部会替换子类的虚函数地址
int main()
{
    cout<<sizeof(animal)<<endl;
    return 0;
}*///多态的内核

//分别利用普通写法和多态实现计算器

/*class calculator
{
    public:
    int get_result(string oper)
    {
        if(oper=="+")
        {
            return m_num1+m_num2;
        }
        if(oper=="-")
        {
            return m_num1-m_num2;
        }
        //如果要拓展新的功能（如除法、乘法、开方），需求修改源代码
        //在开发中，提倡开闭原则
        //对扩展进行开放，对修改进行关闭
    }
    int m_num1;
    int m_num2;
};
int main()
{
    calculator p1;
    p1.m_num1=10;
    p1.m_num2=20;
    cout<<p1.m_num1<<"+"<<p1.m_num2<<"="<<p1.get_result("+")<<endl;
    cout<<p1.m_num1<<"-"<<p1.m_num2<<"="<<p1.get_result("-")<<endl;
    return 0;
}*///普通方法

/*class AbstractCalculator
{
public:
    int m_num1;
    int m_num2;
    virtual int getresult()
    {
        return 0;
    }
};
//加法类
class AddCalculator:public AbstractCalculator
{
public:    
    int getresult()
    {
        return m_num1+m_num2;
    }
};
//减法类
class SubCalculator:public AbstractCalculator
{
public:    
    int getresult()
    {
        return m_num1-m_num2;
    }
};
void test01()
{
    AbstractCalculator*p=new AddCalculator;//父类指针接受子类
    p->m_num1=100;
    p->m_num2=100;
    cout<<p->m_num1<<"+"<<p->m_num2<<"="<<p->getresult()<<endl;
    delete p;
    p=NULL;
    AbstractCalculator*p1=new SubCalculator;
    p1->m_num1=100;
    p1->m_num2=100;
    cout<<p1->m_num1<<"+"<<p1->m_num2<<"="<<p1->getresult()<<endl;
    delete p1;
    p1=NULL;
    //多态好处：
    //组织结构清楚
    //可读性强
    //便于维护
}

int main()
{
    test01();
    return 0;
}*///多态方式

/*class base
{
public:
    virtual void func()=0;//纯虚函数
    //类中有纯虚函数就变为抽象类(无法实例化对象)
    //子类必须重写纯虚函数，否则变为抽象类
};
class son:public base
{
     virtual void func()
     {
        cout<<"son"<<endl;
     }
     int m_age;
};

int main()
{
    //base p1;
    base*p=new son;
    p->func();
    son p1;
    return 0;
}*///纯虚函数

/*class Animal
{
public:
    virtual void speak()=0;
    Animal()
    {
        cout<<"animal gouzao"<<endl;
    }
    //virtual~Animal()
    //{
    //    cout<<"animal xigou"<<endl;
    //}
    virtual ~Animal()=0;//纯虚析构也使类成为抽象类
};
Animal::~Animal()//解决通过父类析构代替子类析构
{
    cout<<"virtual xigou"<<endl;
}//纯虚析构在父类也需要实现
//在父类也有开辟在堆区的内存

class Cat:public Animal
{
public:  
    Cat(string name)
    {
        cout<<"cat gouzao"<<endl;
        m_name=new string(name);
    }
    void speak()
    {
        cout<<"cat:"<<*m_name<<endl;
    }
    string *m_name;
    ~Cat()
    {
        if(m_name!=NULL)
        {
            cout<<"cat xigou"<<endl;
            delete m_name;
            m_name=NULL;
        }
    }
};

int main()
{
    Animal*p1=new Cat("tom");
    p1->speak();
    delete p1;//父类析构代替了子类析构，使得内存泄漏
    return 0;
}*///纯虚析构

/*class cpu 
{
    public:
    virtual void calculate()=0;
};

class videocard
{
    public:
    virtual void display()=0;
};

class memory
{
    public:
    virtual void storage()=0;
};

class Computer
{
    public:
    Computer(cpu*cpu,videocard*vc,memory*mem)
    {
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    void work()
    {
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }
        if(m_vc!=NULL)
        {
            delete m_vc;
            m_vc=NULL;
        }
        if(m_mem!=NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }

private:
    cpu*m_cpu;
    videocard*m_vc;
    memory*m_mem;
};

//具体的厂商
//intel
class intelcpu:public cpu
{
public:
    void calculate()
    {
        cout<<"intel calculate"<<endl;
    }
};

class intelvideocard:public videocard
{
public:
    void display()
    {
        cout<<"intel display"<<endl;
    }
};

class intelmemory:public memory
{
public:
    void storage()
    {
        cout<<"intel memory"<<endl;
    }
};

//lenovo
class lencpu:public cpu
{
public:
    void calculate()
    {
        cout<<"lenovo calculate"<<endl;
    }
};

class lenvideocard:public videocard
{
public:
    void display()
    {
        cout<<"lenovo display"<<endl;
    }
};

class lenmemory:public memory
{
public:
    void storage()
    {
        cout<<"lenovo memory"<<endl;
    }
};
void test01()
{
    //第一台零件
    cpu*cpu1=new intelcpu;
    videocard*videocard1=new intelvideocard;
    memory*memory1=new intelmemory;

    //创建第一台电脑
    Computer*computer1=new Computer(cpu1,videocard1,memory1);
    computer1->work();
    delete computer1;
    //创建第二台电脑

}
int main()
{
    test01();
    return 0;
}*///用多态组装电脑

/*void swapint(int&a,int&b)
{
    int temp=a;
    a=b;
    b=temp;
}

void swapdouble(double&a,double&b)
{
    double temp=a;
    a=b;
    b=temp;
}
//无数种类型过于麻烦
template<typename T>
void myswap(T&a,T&b)
{
    T temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=10;
    int b=20;
    swapint(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    double x=1.1;
    double y=2.2;
    swapdouble(x,y);
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;

    //自动类型推导数据类型推导一致，且必须能确定类型
    myswap(a,b);

    //指定类型推导
    myswap<int>(a,b);
    return 0;
}*///模板

/*template<class T>
void myswap(T&a,T&b)
{
     T temp=a;
     a=b;
     b=temp;
}
template<class T>
void mysort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            myswap(arr[max],arr[i]);
        }
    }
}
template<class T>
void print(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void test01()
{
    char arr[]="badcef";
    int num=sizeof(arr)/sizeof(char);
    mysort(arr,num);
    print(arr,num);
}
int main()
{
    test01();
    return 0;
}*///模板案例

/*template <class T>
T myadd(T a,T b)
{
    return a+b;
}
template <class T>
T myadd1(T a,T b)
{
    return a+b;
}
//
int main()
{
    int a=10;
    int b=20;
    char c='c';
    //自动型推导模板函数无法发生隐式类型转换
    cout<<myadd(a, b)<<endl;
    //cout<<myadd(a,c)<<endl;

    //显示指定类型可以发生隐式类型转换
    cout<<myadd1<int>(a, c)<<endl;
    return 0;
}*///普通函数与模板函数在隐式类型转换上的区别

/*void myprint(int a,int b)
{
    cout<<"putong"<<endl;
}
//1.如果函数模板和普通函数都可以调用，优先普通函数
//2.可以通过空模板参数列表强制调用函数模板
//3.函数模板也可以发生函数重载
//4.如果函数模板可以发生更好的匹配，优先调用函数模板
template<class T>
void myprint(T a,T b)
{
    cout<<"moban"<<endl;
}

int main()
{
    int a=10;
    int b=20;
    myprint(a,b);//优先普通函数,若普通函数只用声明报错
    
    //通过空模板参数列表，强制调用函数模板
    myprint<>(a,b);
    return 0;
}*///普通函数和模板函数的调用规则

/*class person
{
public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    string m_name;
    int m_age;

};
template <class T>
bool mycompare(T&a,T&b)
{
    if(a==b)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
//具体化实现person类型(特殊实现某个)
template <>bool mycompare(person&p1,person&p2)
{
    if(p1.m_name==p2.m_name&&p1.m_age==p2.m_age)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void test1()
{
    int a=10;
    int b=20;
    bool ret=mycompare(a,b);
    if(ret==true)
    {
        cout<<"="<<endl;
    }
    else
    { 
        cout<<"!="<<endl;
    }
}
void test2()
{
    person p1("tom",10);
    person p2("tom",10);
    bool re=mycompare(p1,p2);
    cout<<re<<endl;
}
int main()
{
    test2();
    return 0;
}*///具体化模板(模板的局限性)学这个为了在stl中运用系统提供的模板

/*template <class NameType,class AgeType=int>//类模板可以有默认参数类型
class person
{
    public:
    person(NameType name,AgeType age)
    {
       this->m_name=name;
       this->m_age=age;
    }
    NameType m_name;//模板成员类型
    AgeType m_age;
    void show()
    {
        cout<<"name="<<m_name<<endl;
        cout<<"age="<<m_age<<endl;
    }
};
void test1()
{
    //指定成员类型,类模板没有自动推导类型
    person<string,int>p1("sun",999);//模板成员初始化
    p1.show();
}
int main()
{
    test1();
    return 0;
}*///类模板基本语法

/*class person1
{
    public:
    void showperson1()
    {
        cout<<"person1 show"<<endl;
    }
};

class person2
{
    public:
    void showperson2()
    {
        cout<<"person2 show"<<endl;
    }
};
template<class T>
class myclass
{
    public:
    T obj;
    void func1()
    {
       obj.showperson1();
    }
    void func2()
    {
        obj.showperson2();
    }
    //此时无法确定成员类型
    //创建项目可以成功
    //在使用时才会创建
};
void test01()
{
    myclass<person1>p1;//此时才确定类型
    p1.func1();
    //p1.func2();//无法运行

}
int main()
{
    test01();
    return 0;
}*///成员函数创建时机

/*template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age)
    {
        m_name=name;
        m_age=age;
    }
    void showperson()
    {
        cout<<"name="<<m_name<<endl<<"age="<<m_age<<endl;
    }
    T1 m_name;
    T2 m_age;
};
//类模板对象做函数参数

//1.指定传入类型
void printperson1(person<string,int>&p)
{
    p.showperson();
}
void test1()
{
    person<string,int>p("sun",100);
    printperson1(p);
}

//2.参数模板化
template<class T1,class T2>
void printperson2(person<T1,T2>&p)
{
    p.showperson();
    cout<<"T1="<<typeid(T1).name()<<endl;//这样可以查看T的数据类型
    cout<<"T2="<<typeid(T2).name()<<endl;
}
void test2()
{
    person<string,int>p("bajie",100);
    printperson2(p);
}

//3.整个类模板化
template<class T>
void printperson3(T&p)
{
    p.showperson();
    cout<<"T="<<typeid(T).name()<<endl;
}
void test3()
{
    person<string,int>p("tangseng",30);
    printperson3(p);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}*///类模板做函数参数

/*template <class T>
class base 
{
    public:
    T m;
};

class son:public base<int>//子类必须知道父类中的T类型
{
    
};

template<class T1,class T2>
class son2:public base<T2>
{
    public:
    son2()
    {
       cout<<typeid(T1).name()<<endl<<typeid(T2).name()<<endl;

    }
    T1 obj;
};
void test2()
{
    son2<int,char>p1;
}//若父类是类模板，子类需要指出父类中T的类型或者子类也为类模板
*///类模板与继承

/*template<class T1,class T2>
class person
{
    public:
    T1 m_name;
    T2 m_age;
    person(T1 name,T2 age);
    //{
        //m_name=name;
        //m_age=age;
    //}
    void showperson();
    //{
        //cout<<"name="<<m_name<<endl<<"age="<<m_age<<endl;   
    //}
};

//类外实现
template<class T1,class T2>
person<T1,T2>::person(T1 name,T2 age)
{
    m_name=name;
    m_age=age;
}

template<class T1,class T2>
void person<T1,T2>::showperson()//不能单写person::
{
    cout<<"name="<<m_name<<endl<<"age="<<m_age<<endl;
}*///成员函数的类外实现

/*template<class T1,class T2>
class person;
//上述东西编译器许提前知道
template<class T1,class T2>
void printperson1(person<T1,T2>p)
{
    cout<<"name="<<p.m_name<<endl<<"age="<<p.m_age<<endl;
}
template <class T1,class T2>
class person
{
    //全局函数类内实现
    friend void printperson1<>(person<T1,T2>p);
    friend void printperson(person<T1,T2>p)
    {
        cout<<"name="<<p.m_name<<endl<<"age="<<p.m_age<<endl;
    }
    public:
    person(T1 name,T2 age)
    {
        m_name=name;
        m_age=age;
    }
    private:
    T1 m_name;
    T2 m_age;
};
//全局函数类外实现放在此处会报错
//template<class T1,class T2>
//void printperson1(person<T1,T2>p)
//{
//    cout<<"name="<<p.m_name<<endl<<"age="<<p.m_age<<endl;
//}

//类内实现调用
void test01()
{
    person<string, int>p1("zhangsan",99);
    printperson(p1);
}
//类外实现调用
void test02()
{
    person<string,int>p2("jerry",12);
    printperson1(p2);
}

int main()
{
    test01();
    test02();
    return 0;
}*///全局函数在类外实现的注意事项(作为友元)

/*#include"class.hpp"
void test1()
{
    Myarry<int>arr1(5);
    Myarry<int>arr2(arr1);
    Myarry<int>arr3(100);
    arr3=arr1;
}
int main()
{
    test1();
    return 0;
}*///calss_arr.hpp

/*void print(int val)
{
    cout<<val<<endl;
}
void test01()
{
    //创建了一个vecotr容器、数组
    vector<int>v;

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin=v.begin();//起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd=v.end();//结束迭代器，指向容器中的最后一个元素的下一个元素
    //第一种遍历
    while(itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    //第二种遍历
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    //第三种遍历方式,利用stl中提供的遍历算法，本质还是for循环
    for_each(v.begin(),v.end(),print);//最后一个只输函数名
}
int main()
{
    test01();
    return 0;
}*///vector存放内置数据类型

/*class person
{
    public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    string m_name;
    int m_age;
};
void test01()//放class类型
{
    vector<person>v;
    person p1("z",10);
    person p2("s",15);
    person p3("d",11);
    person p4("a",12);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for(vector<person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"name="<<(*it).m_name<<endl<<"age="<<(*it).m_age<<endl;
        
    }//it当成指针使用
}
void test02()
{
     vector<person*>v;
    person p1("z",10);
    person p2("s",15);
    person p3("d",11);
    person p4("a",12);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    for(vector<person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"name="<<(*it)->m_name<<endl<<"age="<<(*it)->m_age<<endl;
        
    }
}
int main()
{
    test01();
    test02();
    return 0;
}*///vector存放自定义数据类型

/*void test01()//string类内部封装的构造函数
{
    string s1;//默认构造
    
    const char*str="hello world";
    string s2(str);//c语言风格的指针构造
    cout<<"s2="<<s2<<endl;

    string s3(s2);//拷贝构造
    cout<<"s3="<<s3<<endl;

    string s4(10,'a');//使用n个字符c初始化
    cout<<"s4="<<s4<<endl;
}
int main()
{
    test01();
    return 0;
}*///string容器构造函数

/*void test01()//string容器中的赋值
{
    string str1;
    str1="hello";
    cout<<"str1="<<str1<<endl;

    string str2;
    str2=str1;
    cout<<"str2="<<str2<<endl;

    string str3;
    str3='a';
    cout<<"str3="<<str3<<endl;

    //通过assign赋值
    string str4;
    str4.assign("hello cpp");
    cout<<"str4="<<str4<<endl;

    string str5;
    str5.assign("hello cpp",5);//"hello cpp"的前五个
    cout<<"str5="<<str5<<endl;

    string str6;
    str6.assign(str5);
    cout<<"str6="<<str6<<endl;

    string str7;
    str7.assign(10,'w');//10个连续的字符'w'
    cout<<"str7="<<str7<<endl;
}
int main()
{
    test01();
    return 0;
}*///string容器赋值

/*void test01()
{
    //字符串拼接
    //利用加等于
    string str1="wo";
    str1+="ai wan";
    string str2="you xi";
    str1+=str2;
    //利用append
    str1.append("ai");
    str1.append("gameabc",4);//"gameabc"中的前四个
    str1.append(str2);
    str1.append(str2,0,3);//从0开始，截取三个
    cout<<"str1="<<str1<<endl;
}
int main()
{
    test01();
    return 0;
}*///字符串拼接

/*void test01()
{
    //查找
    string str1="abcdfgdf";
    int pos=str1.find("df");//找到返回下标，没找到返回-1
    int pos1=str1.rfind("df");//从右往左查
    cout<<"pos="<<pos<<endl;
    cout<<"pos1="<<pos1<<endl;
    
    //2.替换
    string str2="abcdefgh";
    str2.replace(1,3,"11111");//从第一个开始后面三个
    cout<<"str2="<<str2<<endl;
}
int main()
{
    test01();
    return 0;
}*///字符串查找替换

/*void test01()
{
    string str1="hellox";
    string str2="hello";
    if(str1.compare(str2)==0)
    {
        cout<<"="<<endl;
    }
    int re=str1.compare(str2);
    cout<<re<<endl;
}
int main()
{
    test01();
    return 0;
}*///字符比较

/*void test01()
{
    string str="abcdef";
    //1.通过[]访问单个字符
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //2.通过at方式访问单个字符
    for(int i=0;i<str.size();i++)
    {
        cout<<str.at(i)<<" ";
    }
    cout<<endl;
    //修改单个字符
    str[0]='h';
    str.at(1)='r';
    cout<<str<<endl;
}
int main()
{
    test01();
    return 0;
}*///字符存取

/*void test01()
{
    string str="hello";
    //插入
    str.insert(1,"111");//从第一个位置插入
    cout<<"str="<<str<<endl;

    //删除
    str.erase(1,3);//从第一个位置删除三个
    cout<<"str="<<str<<endl;
}
int main()
{
    test01();
    return 0;
}*///插入删除

/*void test01()
{
    string email="zhangsan@sina.com";
    int pos=email.find("@");
    string userName=email.substr(0,pos);
    cout<<"username="<<userName<<endl;
}
int main()
{
    test01();
    return 0;
}*///子串获取

/*int main()
{
    vector<int>v;//无参构造
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    //区间构造
    vector<int>v2(v.begin(),v.end());

    //拷贝构造
    vector<int>v3(v);

    //n个elem方式构造
    vector<int>v4(10,100);

    return 0;
}*///vector构造函数

/*int main()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    
    //赋值
    vector<int>v2;
    v2=v1;
    
    //assign
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());

    v3.assign(10,100);
    return 0;
}*///vector赋值操作

/*void print_vec(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    print_vec(v1);
    if(v1.empty())
    {
        cout<<"kong"<<endl;
    }
    else 
    {
        cout<<"fei kong wei:"<<v1.capacity()<<endl;
    }
    //重新指定大小
    v1.resize(15,100);
    print_vec(v1);//默认用0填充过长位置,但可以指定，上面指定为100
    //如果指定短了会直接删除
    return 0;
}*///容器和大小

/*int main()
{
    vector<int>v={1,2,3,4};
    v.insert(v.begin(),2,100);
    v.erase(v.begin());//单个清空
    v.erase(v.begin(),v.end());//区间清空
    v.clear();//清空
    return 0;
}*///插入和清空

/*int main()
{
    vector<int>v1={1,2,3,4,5};
    vector<int>v2={5,4,3,2,1};
    v1.swap(v2);//交换两个vector容器
    vector<int>v3;
    for(int i=0;i<100000;i++)
    {
        v3.push_back(i);
    }
    cout<<"v3 capability="<<v3.capacity()<<endl;//138255
    cout<<"v3 size="<<v3.size()<<endl;//100000
    v3.resize(3);
    cout<<"v3 capability="<<v3.capacity()<<endl;//138255
    cout<<"v3 size="<<v3.size()<<endl;//3
    //解决内存浪费
    vector<int>(v3).swap(v3);
     cout<<"v3 capability="<<v3.capacity()<<endl;//3
    cout<<"v3 size="<<v3.size()<<endl;//3
    //创建一个虚拟vector拷贝v3，然后和v3交换，使v3的容量变为3
    return 0;
}*///互换容器

/*int main()
{

    vector<int>v;
    v.reserve(10000);//预留空间
    int num=0;
    //统计开辟的次数
    int*p=NULL;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    cout<<"num="<<num<<endl;//预留前为24，预留后变为1
    return 0;
}*///预留空间

/*#include<deque>
void print_de(deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
void test01()
{
    deque<int>d1={1,2,3,4,5,6};
    print_de(d1);
    deque<int>d2(d1.begin(),d1.end());
    deque<int>d3(d2);
    deque<int>d4(10,100);
}*///deque容器的赋值操作

/*#include<deque>
int main()
{
    deque<int>v1;
    v1.push_back(10);//尾插
    v1.push_front(20);//头插
    v1.push_back(10);//尾删
    v1.push_front(20);//头删
    v1.pop_back();
    v1.pop_front();
    v1.insert(v1.begin(),10);//插入
    v1.erase(v1.begin());
    v1.erase(v1.begin(),v1.end());
    v1.clear();
    return 0;
}*///deque的首插、尾插等

/*#include<deque>
#include<algorithm>
void print_de(deque<int>&v)
{
    for(deque<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    deque<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    print_de(v);
    sort(v.begin(),v.end());
    print_de(v);
    return 0;
}*///sort排序

/*#include<stack>
int main()
{
    //stack先进后出
    stack<int>v;//默认构造
    for(int i=0;i<10;i++)
    {
        v.push(i);
    }
    stack<int>v1(v);//拷贝构造
    int re=v.empty();//为空返回1
    v.swap(v1);
    cout<<re<<endl;
    while(!v.empty())
    {
        cout<<"top="<<v.top()<<endl;//查看栈顶元素
        v.pop();//出栈
    }
    cout<<"size="<<v.size()<<endl;
    return 0;
}*///stack的常用接口

/*#include<queue>
int main()
{
    //queue只能先进先出，只能被访问队尾和队头
    queue<int>v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    while(!v.empty())
    {
        cout<<"front="<<v.front()<<endl;
        cout<<"back="<<v.back()<<endl;
        v.pop();
    }
    cout<<v.size()<<endl;
    return 0;
}*///queue的常见接口

/*#include<list>
int main()
{
    list<int>l1={1,2,3,4};
    list<int>l2(l1);
    list<int>l3(l1.begin(),l2.end());
    return 0;
}*///list的构造

/*#include<list>
int main()
{
    list<int>l1={1,2,3,4,5,6};
    l1.push_back(7);
    l1.push_front(0);
    l1.remove(7);//移除l1中所有的7
    return 0;
};*///list插入和删除

/*#include<list>
int main()
{
    list<int>l1={1,2,3,4,5};
    cout<<"front="<<l1.front()<<endl;//访问第一个元素
    cout<<"end="<<l1.back()<<endl;//访问最后一个元素
    //list不能以[]或者at的方式访问
    //list不支持随机访问，但支持双向
    return 0;
}*///数据储存与访问

/*#include<list>
void print_list(list<int>&l)
{
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool my_com(int v1,int v2)
{
    return v1>v2;
}

int main()
{
    list<int>l1={1,2,3,4,5};
    int m;
    print_list(l1);
    l1.reverse();//反转
    print_list(l1);
    //sort(l1.begin(),l1.end());不支持随机访问的迭代器不可使用普通算法
    l1.sort();//从小到大排序
    l1.sort(my_com);
    print_list(l1);//加入了排序规则
    return 0;
}*///反转和排序

/*#include<list>
class person
{
    public:
    person(string name,int age,int height)
    {
        m_name=name;
        m_age=age;
        m_height=height;
    }
    string m_name;
    int m_age;
    int m_height;
};
bool comperson(person&p1,person&p2)
{
    if(p1.m_age==p2.m_age)
    {
       return p1.m_height<p2.m_height;
    }
    return p1.m_age<p2.m_age;
}
void print_list(list<person>l)
{
    for(list<person>::iterator it=l.begin();it!=l.end();it++)
    {
        cout<<"name="<<it->m_name<<" "<<"age="<<it->m_age<<" "<<"height="<<it->m_height<<endl;
    }
}
int main()
{
    list<person>l;
    person p1("liu",35,175);
    person p2("cao",45,180);
    person p3("sun",35,170);
    person p4("zhao",25,190);
    person p5("zhang",35,160);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.sort(comperson);
    print_list(l);
    return 0;
}*///年龄升序（年龄相同身高升序）

/*#include<set>
void print_set(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    set<int>s1={1,3,4,5,6};
    s1.insert(10);
    print_set(s1);
    //set会自动排序
    //set不允许插入重复的值
    set<int>s2(s1);//拷贝构造
    set<int>s3=s2;//赋值操作
    return 0;
}*///set的构造和赋值

/*#include<vector>
int main()
{
    int n;
    while(cin>>n)
    {
        vector<double>score;
        for(int i=0;i<n;i++)
        {
            double single_score;
            cin>>single_score;
            score.insert(score.begin(),single_score);
        }
        int max=-9999,min=9999,sum=0;
        for(vector<double>::iterator it=score.begin();it!=score.end();it++)
        {
            if(*it>max)
            {
                max=*it;
            }
            if(*it<min)
            {
                min=*it;
            }
            sum+=*it;
        }
        double ave=(sum-min-max)/(n-2);
        cout<<ave;
    }
    return 0;
}*///算平均分

/*#include<list>
#include<vector>
bool my_compare(int v1,int v2)
{
    return v1>v2;
}
int main()
{
    vector<int>v={1,2,3,6,5,4};
    sort(v.begin(),v.end(),my_compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;
    list<int>l={1,2,5,4,6,7};
    l.sort(my_compare);
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it;
    }
    return 0;
}*///排序

/*#include<set>
#include<iostream>
int main()
{
    set<int>s1;
    multiset<int>s2;
    pair<set<int>::iterator,bool>ret=s1.insert(10);
    if(ret.second)
    {
      cout<<"cg"<<endl;
    }
    else
    {
      cout<<"sb"<<endl;
    }
    pair<set<int>::iterator,bool>ret1=s1.insert(10);
    if(ret1.second)
    {
      cout<<"cg"<<endl;
    }
    else
    {
      cout<<"sb"<<endl;
    }
    set<int>::iterator it=s2.insert(10);
    cout<<*it<<endl;
    set<int>::iterator it1=s2.insert(10);
    cout<<*it1<<endl;
    return 0;
}*///set和multiset的区别

/*#include<string>
#include<iostream>
int main()
{
    pair<string,int>p("tom",20);
    cout<<"name="<<p.first<<endl<<"age="<<p.second<<endl;
    return 0;
}*///对组

/*#include<iostream>
#include<map>
int main()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(10,20));
    m.insert(make_pair(2,10));
    return 0;
}*///map

/*#include<stack>
int main()
{
    stack<int>s;
    //常用接口
    s.empty();
    s.push(1);
    s.pop();
    s.top();
    return 0;
}*///栈

/*#include<iostream>
int main()
{
    int a[]={3,5,2,4,6,8,5,7,1};
    int len=9,k,temp;
    for(int i=0;i<len;i++)
    {
     k=i;
     for(int j=i+1;j<len;j++)
     {
       if(a[k]>a[j])
       {
        k=j;
       }
     }
     temp=a[k];
     a[k]=a[i];
     a[i]=temp;
    }
    for(int i=0;i<len;i++)
    {
        cout<<a[i];
    }
    return 0;
}*///选择排序

/*#include<iostream>
int main()
{
    int n=10,t,arr[15]={0};
    for(int i=0;i<n;i++)
    {
        cin>>t;
        arr[t]++;
    }
    for(int i=0;i<15;i++)
    {
      while(arr[i]!=0)
      {
        cout<<i<<" ";
        arr[i]--;
      }
    }
    return 0;
}*///桶排序/计数排序

/*#include <iostream>
#include <vector>

// 获取数组中的最大值
int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 对数组按照某一位进行计数排序
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    // 存储每个数字出现的次数
    for (size_t i = 0; i < arr.size(); ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算累计次数
    for (size_t i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // 构建输出数组
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 复制回原数组
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(std::vector<int>& arr) {
    int m = getMax(arr);

    // 对每一位进行计数排序
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

// 打印数组
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}*///基数排序(AI)

/*#include<iostream>
#include<vector>
#include<algorithm>
void sin_countsort(vector<int>&arr,int exp);
int Getmax(vector<int>&arr);
void countsort(vector<int>&arr);
void printArray(vector<int>& arr);
int main()
{
    vector<int>arr={1,3,100};
    countsort(arr);
    printArray(arr);
    return 0;
}
int Getmax(vector<int>&arr)
{
    return *max_element(arr.begin(),arr.end());
}
void countsort(vector<int>&arr)
{
    int max=Getmax(arr);
    for(int i=1;max/i>0;i*=10)
    {
        sin_countsort(arr,i);
    }
}
void sin_countsort(vector<int>&arr,int exp)
{
    vector<int>bucket(10,0);
    vector<int>output(arr.size());
    for(int i=0;i<arr.size();i++)
    {
        bucket[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        bucket[i]+=bucket[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--)
    {
        output[bucket[(arr[i]/exp)%10]-1]=arr[i];
        bucket[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=output[i];
    }
}
void printArray(vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << std::endl;
}*///基数排序

/*#include<iostream>
int main()
{
    int a[15]={46,35,1,24,29,28};
    int n=6;
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            else 
            {
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}*///插入排序

/*#include <iostream>
#include <vector>

using namespace std;

// 希尔排序函数
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // 初始增量 gap 设为数组长度的一半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个 gap 执行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            
            // 插入排序
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {34, 8, 64, 51, 32, 16, 23, 8, 43};
    
    cout << "原始数组: ";
    printArray(arr);
    
    shellSort(arr);
    
    cout << "排序后的数组: ";
    printArray(arr);
    
    return 0;
}*///希尔排序（AI）

/*#include<vector>
#include<iostream>
void shellsort(vector<int>&arr);
int main()
{
    vector<int>arr={1,4,6,7,0,10};
    shellsort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
void shellsort(vector<int>&arr)
{
    int len=arr.size();
    for(int gap=len/2;gap>0;gap/=2)
    {
        for(int i=gap;i<len;i++)
        {
            int temp=arr[i];
            int j=i;
            while(j>=gap&&arr[j-gap]>temp)
            {
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
}*///希尔排序

/*#include <iostream>
#include <vector>

// 合并两个已排序的子数组为一个排序数组
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// 归并排序函数
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// 打印数组函数
void printArray(const std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};

    std::cout << "Given array is \n";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is \n";
    printArray(arr);
    return 0;
}*///归并排序（AI）

/*#include<vector>
#include<iostream>
void merge(vector<int>&arr,int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int>left(n1),right(n2);
    for(int i=0;i<n1;i++)
    {
      left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])
        {
            arr[k++]=left[i++];
        }
        else 
        {
            arr[k++]=right[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=left[i++];
    }
    while(j<n2)
    {
        arr[k++]=right[j++];
    }
}
void mergesort(vector<int>&arr,int l,int r)
{
    if(r>l)
    {
      int mid=(l+r)/2;
      mergesort(arr,l,mid);
      mergesort(arr,mid+1,r);
      merge(arr,l,mid,r);
    }
}
int main()
{
    vector<int>arr={1,3,5,5,2,9};
    mergesort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}*///归并排序

/*#include <iostream>
#include <vector>
using namespace std;

// 快速排序的分区函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为基准值
    int i = low - 1;  // i 用于追踪小于基准值的元素位置

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);  // 将小于基准值的元素交换到左侧
        }
    }
    swap(arr[i + 1], arr[high]);  // 将基准值放置到正确位置
    return i + 1;  // 返回基准值的位置
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 分区位置
        quickSort(arr, low, pi - 1);  // 递归排序左侧子数组
        quickSort(arr, pi + 1, high);  // 递归排序右侧子数组
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "排序后: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}*///快速排序（AI）

/*#include<iostream>
#include<vector>
void quicksort(vector<int>&arr,int low,int high);
int partition(vector<int>&arr,int low,int high);
void swap(int&a,int&b);
void printarr(vector<int>&arr);
int main()
{
    vector<int>arr={1,5,7,2,7,9,3};
    quicksort(arr, 0, arr.size()-1);
    printarr(arr);
    return 0;
}
void quicksort(vector<int>&arr,int low,int high)
{
    if(high>low)
    {
        int pi=partition(arr,low,high);
        quicksort(arr, low, pi-1);
        quicksort(arr,pi+1,high);

    }
}
int partition(vector<int>&arr,int low,int high)
{
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}
void swap(int&a,int&b)
{
    int temp=a;
    a=b;
    b=temp;
}
void printarr(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}*///快速排序


/*#include <iostream>
using namespace std;

template<typename T>
struct ListNode {
    T data;
    ListNode *next;
    ListNode(T d): data(d), next(NULL) {}
};

template<typename T>
struct TreeNode {
    T data;
    ListNode< TreeNode<T>* > *childrenHead;

    void AddChild(TreeNode<T>* node) {
        ListNode< TreeNode<T>* > *childNode = new ListNode< TreeNode<T>* > (node);//赋值T data
        if(childrenHead == NULL) {
            childrenHead = childNode;
        }else {
            childNode->next = childrenHead;//赋值ListNode *next
            childrenHead = childNode;
        }
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T> *nodes;
    TreeNode<T> *root;
public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void SetRoot(int rootId);
    void AddChild(int parentId, int sonId);
    void AssignData(int nodeId, T data);
    void Print(TreeNode<T> *node = NULL);
};

template<typename T>
Tree<T>::Tree() {
    nodes = new TreeNode<T>[100001];
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
    nodes = new TreeNode<T>[maxNodes];
}

template<typename T>
Tree<T>::~Tree() {
    delete[] nodes;
}

template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id) {
    return &nodes[id];//为每一个元素调用默认构造从而使数组初始化，所以可以索引
}

template<typename T>
void Tree<T>::SetRoot(int id) {
    root = GetTreeNode(id);
}

template<typename T>
void Tree<T>::AddChild(int parentId, int sonId) {
    TreeNode<T> *parentNode = GetTreeNode(parentId);
    TreeNode<T> *sonNode = GetTreeNode(sonId);
    parentNode->AddChild( sonNode );
}

template<typename T>
void Tree<T>::AssignData(int id, T data) {
    GetTreeNode(id)->data = data;
}

template<typename T>
void Tree<T>::Print(TreeNode<T> *node) {
    if(node == NULL) {
        node = root;
    } 
    cout << node->data;
    ListNode<TreeNode<T>*> *tmp = node->childrenHead;
    while(tmp) {
        Print(tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Tree<char> T(9);
    T.SetRoot(0);
    T.AssignData(0, 'a');
    T.AssignData(1, 'b');
    T.AssignData(2, 'c');
    T.AssignData(3, 'd');
    T.AssignData(4, 'e');
    T.AssignData(5, 'f');
    T.AssignData(6, 'g');
    T.AssignData(7, 'h');
    T.AssignData(8, 'i');
    T.AddChild(0, 2);
    T.AddChild(0, 1);
    T.AddChild(1, 3);
    T.AddChild(2, 5);
    T.AddChild(2, 4);
    T.AddChild(3, 6);
    T.AddChild(3, 7);
    T.AddChild(3, 8);
    T.Print();
    return 0;
}*///树

/*#include <iostream>
using namespace std;

// 定义树节点
class TreeNode {
public:
    int value;      // 节点值
    TreeNode* left;  // 左子树
    TreeNode* right; // 右子树

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 定义二叉树类
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            insertHelper(root, value);
        }
    }

    // 插入节点的辅助函数
    void insertHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else {
                insertHelper(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                insertHelper(node->right, value);
            }
        }
    }

    // 中序遍历
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }
};

// 示例使用
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    // 中序遍历
    tree.inOrderTraversal(tree.root);
    cout << endl;

    return 0;
}*///树

/*#include <iostream>
#include <vector>
using namespace std;

// 堆调整函数，调整堆，使其符合堆的性质
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 当前节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点比根节点大
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大的不是根节点，则交换并继续调整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 从堆中提取元素
    for (int i = n - 1; i >= 1; i--) {
        // 交换当前根节点和最后一个节点
        swap(arr[0], arr[i]);
        
        // 调整堆，使其符合堆的性质
        heapify(arr, i, 0);
    }
}

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "原始数组: ";
    printArray(arr);

    heapSort(arr);

    cout << "排序后的数组: ";
    printArray(arr);

    return 0;
}*///AI

/*#include<vector>
void heapify(vector<int>& arr, int n, int i)
{
    int root=i,left=2*i+1,right=2*i+2;
    if(arr[left]>arr[root])
    {
        root=left;
    }
    if(arr[right]>arr[root])
    {
        root=right;
    }
    if(root!=i)
    {
        swap(arr[root],arr[i]);
        heapify(arr, n, root);
    }
}
void heapsort(vector<int>& arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>0;i--)
    {
        heapify(arr, n, i);
    }
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr, i, 0);
    }
}*///堆排序

/*#include<vector>
#include<iostream>
int binary_search(vector<int>&arr,int num,int left,int right)
{
    int mid=left+(right-left)/2;
    if(left==right&&arr[left]!=num)return -1;
    if(arr[mid]==num)return mid;
    else if(arr[mid]>num)return binary_search(arr,num, left, mid);
    else if(arr[mid]<num)return binary_search(arr,num, mid, right);

}
int main()
{
    vector<int>arr={1,2,3,4,5,6};
    int num=binary_search(arr, 3, 0, arr.size()-1);
    cout<<num;
    return 0;
}*///二分查找

/*#include<memory>
#include<iostream>
class cat{
public:
    cat();
    ~cat();
    int info();
private:
    int debug=20;
};
cat::cat()
{
    cout<<"construct cat"<<endl;
}

cat::~cat()
{
    cout<<"destruct cat"<<endl;
}

int cat::info()
{
    return this->debug;
}
int main()
{
    auto_ptr<cat>a_ptr(new cat);
    cout<<a_ptr->info()<<endl;
    cout<<a_ptr.get()<<endl;//get获取地址
    return 0;
}*///auto智能指针

/*#include<memory>
#include<iostream>
class cat{
public:
    cat();
    ~cat();
    int info();
private:
    int debug=20;
};
cat::cat()
{
    cout<<"construct cat"<<endl;
}

cat::~cat()
{
    cout<<"destruct cat"<<endl;
}

void func()
{
    cout<<"func begin"<<endl;
    unique_ptr<cat>u_ptr1{make_unique<cat>()};
    u_ptr1->info();//就算info（）抛出异常空间仍会被释放
    cout<<"before func end"<<endl;
}
int cat::info()
{
    return this->debug;
}
int main()
{
    func();
    cout<<"func end"<<endl;
    return 0;
}*///unique_ptr的销毁和构建流程

/*#include<memory>
#include<iostream>
class destruct
{
    public:
    void operator()(int*res)const{
        std::cout<<"自定义删除"<<std::endl;
        delete res;
    }
};
int main()
{
    //声明一个指针
    std::unique_ptr<int>u_ptr;
    
    //构造一个空指针
    std::unique_ptr<int>u_ptr1(nullptr);
    
    //构造一个int值为1的指针
    std::unique_ptr<int>u_ptr2(new int(1));
    
    //独占指针所有权转移构造
    std::unique_ptr<int>u_ptr3(std::move(u_ptr2));//move智能指针之间权限的改变

    //独占指针指向数组
    std::unique_ptr<int[]>u_ptr4(new int[5]);

    //自定义删除方式
    std::unique_ptr<int,destruct>u_ptr5(new int(5));

    //创建destruct的实例对象，并将裸指针的权限交给独占指针
    int*ptr=new int(1);
    std::unique_ptr<int,destruct>u_ptr6(ptr,destruct());

    //使用make_unique
    std::unique_ptr<int>u_ptr7=std::make_unique<int>(123);
    
    int *p=u_ptr.release();//release()获取裸指针,将智能指针变为裸指针，原智能指针被置为空
    std::cout<<u_ptr6.get()<<std::endl;//get()单纯获取地址
    int *p1=u_ptr6.release();
    delete p1;
    p1=nullptr;

    return 0;
}*///独占指针

/*#include<memory>
#include<iostream>
int main()
{
    std::shared_ptr<int>s_ptr(std::make_shared<int>(1));
    std::cout<<s_ptr.use_count()<<std::endl;
    std::shared_ptr<int>s_ptr1=s_ptr;
    std::cout<<s_ptr.use_count()<<std::endl;
    s_ptr.reset();
    std::cout<<s_ptr1.use_count()<<std::endl;
    return 0;
}*///shared_ptr

/*#include <iostream>
#include <memory>

class B;

class A {
public:
    std::weak_ptr<B> bPtr;  // A 类包含一个指向 B 的 std::shared_ptr
    ~A() {
        std::cout << "A destroyed" << std::endl;
    }
};

class B {
public:
    std::shared_ptr<A> aPtr;  // B 类包含一个指向 A 的 std::shared_ptr
    ~B() {
        std::cout << "B destroyed" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();  // 创建 A 对象，a 的引用计数为 1
    std::shared_ptr<B> b = std::make_shared<B>();  // 创建 B 对象，b 的引用计数为 1

    a->bPtr = b;  // A 的 bPtr 指向 B，此时 B 的引用计数增加到 2
    b->aPtr = a;  // B 的 aPtr 指向 A，此时 A 的引用计数增加到 2

    // 当 a 和 b 超出作用域时，它们各自的引用计数减 1
    // 但由于 A 中还持有 B 的 std::shared_ptr，B 中还持有 A 的 std::shared_ptr
    // 所以 A 和 B 的引用计数都不会变为 0，导致它们不会被销毁
    return 0;
}*///weak_ptr解决环形依赖

/*#include <iostream>
#include <memory>

void checkObject(const std::weak_ptr<int>& weak) {
    if (auto shared = weak.lock()) {//lock是尝试将weak提升为shared
        std::cout << "Object is still alive. Value: " << *shared << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }
}

int main() {
    std::shared_ptr<int> shared = std::make_shared<int>(42);
    std::weak_ptr<int> weak = shared;

    checkObject(weak);

    shared.reset();
    checkObject(weak);

    return 0;
}*///安全的访问可能被销毁的对象

/*#include<iostream>
#include<memory>
using namespace std;
void find_num(unique_ptr<int[]>&arr,int&max,int&min){
    for(int i=0;i<10;i++){
        if(arr[i]>max)max=arr[i];
        if(arr[i]<min)min=arr[i];
    }
}
int main()
{
    unique_ptr<int[]>arr=make_unique<int[]>(10);
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    find_num(arr,max, min);
    cout<<"max="<<max<<endl<<"min="<<min<<endl;
    return 0;
}*/

/*#include<iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream outf;
    outf.open("file",ios::out);
    outf<<"hello";
    outf.close();
    ifstream inf("file",ios::in);
    char re[30];
    inf>>re;
    cout<<re;
    inf.close();
    return 0;
}*///文件打开与输入操作

/*#include<iostream>

auto func(int m,int n)->decltype(m*n){
    return m*n;
}
int main(){
    decltype(3.0)n;
    int b=1;
    int& a=b;
    decltype(a)m=b;
    return 0;
}*///decltype类型推导和指定函数返回类型

/*#include <iostream>
using namespace std;
int main(){
    auto func=[](int a,int b){
        return a>b;
    };

    cout<<func(1,2);
    int m=1;
    auto func1=[&]()->double{
        return m;
    };
    //引用捕获
    int n=1;
    auto func2=[=m]()mutable->double{
        return m;
    };
    //按值捕获

    return 0;
}*///lambda表达式配合decltype类型推导和指定函数返回类型

/*#include <regex>
#include <iostream> 
#include <string>
using namespace std;
int main(){
    string str="130.120.2.1";
    regex rule("([0-9]{1,3}[.]){3}[0-9]{1,3}");
    if(regex_match(str,rule))cout<<"match"<<endl;
    if(regex_match("hello,",regex("^he(l|o).*(,)$")))cout<<"match1"<<endl;
    return 0;
}*///正则表达式

/*#include <iostream>
#include <regex>
#include <string>
#include <vector>

// 该函数用于查找输入文本中所有的 IPv4 地址
std::vector<std::string> findIPv4Addresses(const std::string& text) {
    // 定义用于匹配 IPv4 地址的正则表达式
    std::regex pattern(R"(\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b)");
    std::vector<std::string> ipv4Addresses;

    // 创建一个正则表达式迭代器，用于遍历文本中所有匹配的结果
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = std::sregex_iterator();

    // 遍历所有匹配结果
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        // 将匹配到的 IPv4 地址添加到结果数组中
        ipv4Addresses.push_back(match.str());
    }

    return ipv4Addresses;
}

int main() {
    // 示例输入文本
    std::string text = "Some IPs are 192.168.1.1, 256.256.256.256, 10.0.0.1";
    // 调用函数查找 IPv4 地址
    std::vector<std::string> result = findIPv4Addresses(text);

    // 输出找到的所有 IPv4 地址
    for (const auto& ip : result) {
        std::cout << ip << std::endl;
    }

    return 0;
}*///正则表达式匹配所有符合ipv4的组合

/*#include <functional>//stl中提供的内建仿函数
#include <vector>
#include <algorithm>
using namespace std;

class myadd{
    public:
    myadd():count(0){};
    int operator()(int a,int b){
        count++;
        return a+b;
    };
    int count;//仿函数可以有自带属性
};//仿函数

int main(){
    myadd add;
    int re=add(1,2);//通过类对象实现函数的功能
    //仿函数还可以用lambda表达式代替
    
    //创建类对象实现仿函数
    negate<int>n;
    plus<int>p;
    int num=n(10);
    num=p(10,20);
    
    vector<int>arr={1,2,5,3,5,4};
    sort(arr.begin(),arr.end(),greater_equal<int>());//内建函数greater_equal,less,less_equal
    
    //逻辑非logical_not，或logical_or，和logical_and
    return 0;
}*///stl中提供的内建仿函数

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>arr={1,4,2,3,6,4};
    vector<int>arr1;
    for_each(arr.begin(),arr.end(),[](int num){
        cout<<num;
    });//也可以使用仿函数或者函数
    cout<<endl;
    transform(arr.begin(),arr.end(),arr1.begin(),[](int num){
        return num;
    });
    return 0;
}*///algorithm

/*#include <thread>
#include <iostream>
using namespace std;

void func(){
    cout<<"11"<<endl;
}
class myadd{
    friend void thread_add();//外部线程调用私有
private:
    void add(int&a){
        a++;
    }
};
void thread_add(){
    int a=10;
    myadd obj;
    thread thread2(&myadd::add,obj,ref(a));//传递引用值
    thread2.join();
    cout<<"11";
}
int main(){
    thread threadl(func);
    bool re=threadl.joinable();//是否可以使用join
    if(re){
        threadl.join();//主程序等待线程执行完毕
    }
    thread_add();
    return 0;
}*///创建线程

/*#include <thread>
#include <iostream>
#include <mutex>
using namespace std;
int a=0;
mutex mtx;
void func(){
    for(int i=0;i<10000;i++){
        //不设置会导致两个线程同时访问这个数据，导致数据竞争
        mtx.lock();//线程尝试获取互斥量（所有权）
        a++;
        mtx.unlock();
    }
    
}
int main(){
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout<<a<<endl;
    return 0;
}*///互斥量解决多线程数据共享问题

/*#include <thread>
#include <mutex>
using namespace std;
mutex mtx1,mtx2;

void func1(){
    for(int i=0;i<1000;i++){
        mtx1.lock();
        mtx2.lock();
        mtx2.unlock();
        mtx1.unlock();
    }
}
void func2(){
    for(int i=0;i<1000;i++){
        mtx2.lock();
        mtx1.lock();
        mtx1.lock();
        mtx2.lock();
    }
}
int main(){
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    //产生了死锁
    return 0;
}*///死锁

/*#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
int num=0;
mutex mtx;
void func(){
    for(int i=0;i<100;i++){
       lock_guard<mutex>guard(mtx);//相当于互斥量中的智能指针
       //还有一种写法lock_guard<mutex>guard(mtx,adopt_lock)这个默认创建前以及上锁
       //在lock_guard构造函数里lock上
       //unique_lock相当于高级的lock_guard，可以实现等待时间等功能
       num++;
       //在析构函数里unlock
    }
}
int main(){
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout<<num<<endl;
    return 0;
}*///lock_guard，unique_lock

/*#include <iostream>
#include <string>
#include <thread>
using namespace std;
class Log{
public:
    Log(){};
    Log(Log&log)=delete;
    void operator=(Log&log)=delete;

    //创建静态方法，无需实例化对象可以直接调用，如：Log::set();
    static Log& set(){
        //懒汉模式
        static Log* log=nullptr;
        //static Log log;
        //饿汉模式
        if(!log)log=new Log();
        return *log;
    }


    void print(string msg){
        cout<<__TIME__<<msg<<endl;
    }
};

int main(){
    thread t1(Log::set);
    thread t2(Log::set);//多线程访问时可能会造成被new了两次
    //once_flag once
    //可以使用定义call_once(once,fun_name)
    return 0;
}*///call_once

/*#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int>g_queue;
condition_variable g_cv;
mutex mtx;
void producer(){
    for(int i=0;i<10;i++){
        unique_lock<mutex>lock(mtx);
        g_queue.push(i);
        //通知消费者
        g_cv.notify_one();
        cout<<"task:"<<i<<endl;
    }
    this_thread::sleep_for(chrono::microseconds(100));
}

void consumer(){
    while(1){
        unique_lock<mutex>lock(mtx);//互斥量是被持有的
        bool isempty=g_queue.empty();
        //如果队列为空要等待
        g_cv.wait(lock,[](){
            return !g_queue.empty();
        });
        int value=g_queue.front();
        g_queue.pop();

        cout<<"consumer:"<<value<<endl;
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}*///condition_variable的使用以及模型

/*#include <string>
#include <iostream>

class Student{
    private:
    int age;
    std::string name;
    public:
    static int count;
    Student(int m,std::string n):age(m),name(n){
        count++;
    };
    Student():age(0),name("NoName"){
        count++;
    };
    ~Student(){
        count--;
    };
    void Print()const{
        std::cout<<"Name="<<name<<" , age="<<age<<std::endl;
        std::cout<<count<<std::endl;
    };
    
};

int Student::count=0;
int main( )

{

    std::cout << "count=" << Student::count << std::endl;

    Student s1,*p = new Student( 23, "ZhangHong" ) ;    

    s1.Print( ) ;

    p -> Print( ) ;

    delete p;

    s1.Print( ) ;

    Student Stu[4];

    std::cout << "count=" << Student::count << std::endl ;

    return 0;

}*/

/*#include <iostream>
#include <string>
using namespace std;
class CDate
{   
    int Date_Year, Date_Month, Date_Day ;    //���ݳ�ԱĬ��Ϊ��˽������
public :                     			
     CDate(int y=2000, int m=1, int d=1) ;  //string w="s"
     CDate(const CDate &date); 			//���ƹ��캯������
     void  Display ( );                  //��ͨ��Ա������������ݳ�Ա��ֵ
     ~CDate(  );      //��������
};
CDate::CDate(int y, int m, int d):Date_Year(y),Date_Month (m),Date_Day(d)  //��ͨ���캯���Ķ���
{   
    cout << "Constructor : " <<  Date_Year << "-" << Date_Month << "-" << Date_Day <<endl;
}

CDate::CDate( const CDate &date)		    //���ƹ��캯���Ķ���
{   
    Date_Year = date.Date_Year;
    Date_Month = date.Date_Month;
    Date_Day = date.Date_Day + 1;
    cout<<"Copy Constructor called.\n";
}

void CDate::Display()
{   
    cout<< Date_Year << "-" << Date_Month << "-" << Date_Day << endl;
}

CDate::~CDate(  )
{
    cout << "Destructor : " << Date_Year << "-" << Date_Month << "-" << Date_Day <<endl;
}
int main()
{   
	CDate array[3]={CDate(2019,3,8), CDate(2019,3,11), CDate(2025,3,26)};
    for(int i=0; i<3; i++)
       array[i].Display();
	return 0;
}*/

/*#include <string>
#include <iostream>
using namespace std;
class data{
protected:
   string name;
public:
   data(string n):name(n){}
   virtual void print(){
      cout<<"name="<<name<<endl;
   }
};

class teacher:virtual public data{
protected:
   float sal;
public:
   teacher(string n,float s):data(n),sal(s){};
   void print()override{
    cout<<"sal="<<sal<<endl;
   }
};

class student:virtual public data{
protected:
   string id;
   public:
   student(string d,string i):data(d),id(i){}
   void print()override{
    cout<<"id="<<id<<endl;
   }
};

class postgrad:public student{
protected:
   string dn;
public:
   postgrad(string d,string i,string n):data(d),student(d,i),dn(n){}
   void print()override{
    cout<<"dn="<<dn<<endl;
   }
};

class tpost3:virtual public teacher,virtual public postgrad{
public:
    tpost3(string n, string i, string d, float s) : data(n), teacher(n, s),postgrad(n, i, d) {}
    void print() override {
        cout << "The teacher and postgraduate:" << endl;
        data::print();
        student::print();
        cout << "dn=" << postgrad::dn << endl;
        cout << "sal=" << teacher::sal << endl;
    }
};

int main(){
    string name,id,dn;
    double sal;
    cin>>name>>id>>dn>>sal;
    tpost3 t(name,id,dn,sal);
    t.print();
    return 0;
}*///mooc多继承

/*#include <iostream>
using namespace std;

const double PI = 3.1415;
class shape{
    public:
    virtual double volume()=0;
};

class cylinder:virtual public shape{
    private:
    int r,h;
    public:
    cylinder(int numr,int numh):r(numr),h(numh){};
    double volume()override{
        return PI*r*r*h;
    }
};

class sphere:virtual public shape{
    private:
    int r;
    public:
    sphere(int numr):r(numr){};
    double volume()override{
        return 4*PI*r*r*r/3;
    }
};

int main() {

    shape *p;
 
    double  r,h;
 
    cin>>r>>h;
 
    cylinder cy(r,h);
 
    sphere sp(r);
 
    p = &cy;
 
    cout << p->volume() << endl;    		
 
    p=&sp;
 
    cout << p->volume() << endl; 
 
    return 0;
 
}*///指针或引用赋值来避免拷贝切片

/*#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix{
public:
    Matrix(){
        m=nullptr;
    }

    Matrix(int r,int c):row(r),col(c){
        m = new int [r*c];
    
        for(int i=0;i<r*c;i++){    
           cin>>m[i];
        }
    };

    Matrix(const Matrix&other):row(other.row),col(other.col){
       m=new int [row*col];
       for(int i=0;i<row*col;i++){
            m[i]=other.m[i];
       }
    }

    void disp();

    ~Matrix(){
        delete [] m;
    };

    Matrix operator+(Matrix other){
       if(this->row!=other.row||this->col!=other.col){
        cout<<" program terminated! "<<endl;
        exit(0);
       }
       Matrix ret;
       ret.row=other.row;
       ret.col=other.col;
       ret.m=new int[row*col];
       for(int i=0;i<row*col;i++){
            ret.m[i]=this->m[i]+other.m[i];
       }
       return ret;
    }

    Matrix& operator=(Matrix other){
        if (this == &other) return *this;
        this->row=other.row;
       this->col=other.col;
       if(this->m==nullptr){
        m=new int [row*col];
       }
       for(int i=0;i<row*col;i++){
            this->m[i]=other.m[i];
       }
       return *this;
    }
private:
    int row,col;
    int *m;
};

void Matrix::disp()
{
	for(int i=0;i<row;i++)
	{
		cout<<'\t';
		for(int j=0;j<col;j++)
			cout<<*(m+i*col+j)<<'\t';
		cout<<endl;
	}
}

int main()
{
	int row_a,col_a,row_b,col_b;
	cin>>row_a>>col_a;
	Matrix A(row_a,col_a);
	cin>>row_b>>col_b;
	Matrix B(row_b,col_b),C;	
	C = A + B;

	C.disp();
	A = B;
	A.disp();
	return 0;
}*/

  
/*#include <iostream>
int main(){
    try {
       int num1=1,num2=0;
       if(num2==0){
        throw std::logic_error("zero is wrong");
       }
       if(num1==0){
        throw std::runtime_error("zero is true");
       }
    } catch (const std::logic_error&e) {
       std::cout<<"fuck you";
    }catch(const std::runtime_error&e){
       std::cout<<"o shit";
    }
    return 0;
}*///异常捕捉

/*#include <iostream>
class Time{
    friend int operator-(Time&t1,Time&t2);
private:
    int hour,minute,second;
public:
    Time():hour(0),minute(0),second(0){}
    Time(int h,int m,int s):hour(h),minute(m),second(s){}
    Time operator++(){
        Time time(*this);
        second++;
        if(second==60){
            second=0;
            minute++;
        }
        if(minute==60){
            minute=0;
            hour++;
        }
        if(hour==24){
            hour=0;
        }
        return time;
    }
    void show(){
        std::cout<<"hour:"<<hour<<" minute:"<<minute<<" second:"<<second<<std::endl;
    }
    int To_seconds(){
        return hour*3600+minute*60+second;
    }
};

int operator-(Time&t1,Time&t2){
    return t1.To_seconds()-t2.To_seconds()>0?(t1.To_seconds()-t2.To_seconds()):(-t1.To_seconds()+t2.To_seconds());
}

int main(){
    Time t1(1,1,1),t2(2,2,2);
    t1.show();
    ++t1;
    t1.show();
    std::cout<<t2-t1<<std::endl;
    return 0;
}*/

/*#include<iostream>
class human{
protected:
    virtual void speak(){} 
};

class chinese:public human{
public:
    void speak()override{
        std::cout<<"ni hao"<<std::endl;
    }
};

class british:public human{
public:
    void speak()override{
        std::cout<<"hi"<<std::endl;
    }
};

class french:public human{
public:
    void speak()override{
        std::cout<<"bonjour"<<std::endl;
    }
};

int main(){
    chinese c;
    british b;
    french f;
    c.speak();
    b.speak();
    f.speak();
    return 0;
}*/


