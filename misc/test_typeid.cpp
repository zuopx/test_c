/*输出变量的类型*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <boost/type_index.hpp>

int main() {
  std::vector<int> vec = {1, 2, 3, 4};

  const auto itr = std::find(vec.begin(), vec.end(), 2);

  std::cout << "Variable itr is of type: " << typeid(itr).name() << std::endl;
  std::cout << "Variable itr is of type: " << boost::typeindex::type_id_with_cvr<decltype(itr)>().pretty_name() << std::endl;

  return 0;
}
