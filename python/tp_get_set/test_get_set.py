import sys
sys.path.append("/home/percy/project/c/test_c/python/tp_get_set/build")

import myobject

obj = myobject.MyObject()
obj.value = 42
print(obj.value)  # 应该输出 42

print(obj.non_existing_attribute)  # 应该引发 AttributeError
