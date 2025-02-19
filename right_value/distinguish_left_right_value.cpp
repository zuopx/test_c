/*分辨右值和左值

左值比较好理解，就是赋值符号左边的值，准确的说，左值是表达式后依然存在的持久对象（对应一块堆内存，或当前栈帧内存）
右值，右边的值，指表达式结束后就不再存在的临时对象

右值引用：一种特殊指针，指向右值，延长临时对象的声明周期。
将亡值：能被右值引用所引用的特殊右值（右值分为将亡值和纯右值）
*/
#include <iostream>
#include <string>
#include <boost/type_index.hpp>

using namespace std;

void reference(string& str)
{
    cout << str << "\tleft value\t";
    cout << "Variable str is of type: " << boost::typeindex::type_id_with_cvr<decltype(str)>().pretty_name() << endl;
}


void reference(string&& str)
{
    cout << str << "\tright value\t";
    cout << "Variable str is of type: " << boost::typeindex::type_id_with_cvr<decltype(str)>().pretty_name() << endl;
}


int main()
{
    string s = "string";
    string&& s1 = move(s);

    reference(s);  // left
    reference(s1);  // left
    reference(move(s));  // right

    cout << "Variable s is of type: " << boost::typeindex::type_id_with_cvr<decltype(s)>().pretty_name() << endl;
    cout << "Variable s1 is of type: " << boost::typeindex::type_id_with_cvr<decltype(s1)>().pretty_name() << endl;
    cout << "Variable move(s) is of type: " << boost::typeindex::type_id_with_cvr<decltype(move(s))>().pretty_name() << endl;
}
