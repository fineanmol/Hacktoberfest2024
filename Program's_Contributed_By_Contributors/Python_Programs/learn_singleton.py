def singleton(class_):
    instances = {}
    def getinstance(*args, **kwargs):
        if class_ not in instances:
            instances[class_] = class_(*args, **kwargs)
        return instances[class_]
    return getinstance

@singleton
class Test1(object):
    def __init__(self):
        self.var_1 = "bob"

    def change_var(self, new_var):
        print(self.var_1) #should print "bob"
        self.var_1 = new_var #should change "bob" to "john"
        print(self.var_1) #should print "john"

class Test2(object):
    def __init__(self):
        test1 = Test1()
        test1.change_var("john")

class Test3(object):
 def __init__(self):
   test1 = Test1()
   print(test1.var_1)

Test2()
Test3()
