- Singleton design pattern

单例模式简介

Singleton provides you with a mechanism(机制) to have one, and only one, object of a
given type and provides a global point of access. Hence, Singletons are typically
used in cases such as logging or database operations, printer spoolers,(用于日志，数据库，打印池) and many
others, where there is a need to have only one instance that is available across the
application to avoid conflicting requests on the same resource. For example, we may
want to use one database object to perform operations on the DB to maintain data
consistency or one object of the logging class across multiple services to dump log
messages in a particular log file sequentially.

使用单例的意图：

• Ensuring that one and only one object of the class gets created
• Providing an access point for an object that is global to the program
• Controlling concurrent access to resources that are shared

单例模式代码:

```
class Singleton(object):
    def __new__(cls):
        print(hasattr(cls, 'instance'))
        if not hasattr(cls, 'instance'):
            cls.instance = super(Singleton, cls).__new__(cls)
        return cls.instance

s = Singleton()
print("Object created", s)

s = Singleton()
print("Object created", s)

```

懒初始化

```
#coding=utf8

class Singleton(object):

    __instance = None

    def __init__(self):
        if not Singleton.__instance:
            print(" __init__ method called..")
        else:
            print("Instance already created:", self.getInstance())

    @classmethod
    def getInstance(cls):
        if not cls.__instance:
            cls.__instance = Singleton()
        return cls.__instance


if __name__ == '__main__':
    s = Singleton()  ## class initialized, but object not created
    print '*' * 80
    print("Object created", Singleton.getInstance()) # Object gets created here
    print '*' * 80
    s1 = Singleton()  ## instance already created

```

Python的模块天然就是单例的

All modules are Singletons by default because of Python's importing behavior.
Python works in the following way:

1. Checks whether a Python module has been imported.
2. If imported, returns the object for the module. If not imported, imports and
instantiates it.
3. So when a module gets imported, it is initialized. However, when the same
module is imported again, it's not initialized again, which relates to the
Singleton behavior of having only one object and returning the same object.

Singletons 和 metaclasses

```
#coding=utf8

# 必须继承自type类
class MyInt(type):

    def __call__(cls, *args, **kw):
        print("***** Here's My int *****", args)
        print("Now do whatever you want with these objects...")
        return type.__call__(cls, *args, **kw)

# 实例化int时候 其实是调用了MyInt的 call方法
class int(object):

    __metaclass__ = MyInt

    def __init__(self, x, y):
        self.x = x
        self.y = y

if __name__ == '__main__':
    i = int(4, 5)
    print i
    j = int(40, 50)
    print j

```

使用metaclass构建单例的metaclass

```
#coding=utf8

class MetaSingleton(type):
    _instances = {}

    def __call__(cls, *args, **kw):
        if cls not in cls._instances:
            cls._instances[cls] = super(MetaSingleton, cls).__call__(*args, **kw)
        return cls._instances[cls]

class Logger():
    __metaclass__ = MetaSingleton
    pass


if __name__ == '__main__':
    logger1 = Logger()
    logger2 = Logger()
    print(logger1, logger2)

```

实例1 使用单例打开sqlite3

```
#coding=utf8

import sqlite3

class MetaSingleton(type):
    _instances = {}

    def __call__(cls, *args, **kw):
        if cls not in cls._instances:
            cls._instances[cls] = super(MetaSingleton, cls).__call__(*args, **kw)
        return cls._instances[cls]


class Database():
    __metaclass__ = MetaSingleton

    connection = None
    def connect(self):
        if self.connection is None:
            self.connection = sqlite3.connect("db.sqlite3")
            self.cursorobj = self.connection.cursor()
        return self.cursorobj

if __name__ == '__main__':
    db1 = Database().connect()
    db2 = Database().connect()
    print ("Database Objects DB1", db1)
    print ("Database Objects DB2", db2)

```

实例2 服务器健康检查实例

```
#coding=utf8

class HealthCheck(object):

    _instance = None

    def __new__(cls, *args, **kwargs):
        if not HealthCheck._instance:
            HealthCheck._instance = super(HealthCheck, cls).__new__(cls,
                                         *args, **kwargs)
        return HealthCheck._instance

    def __init__(self):
        self._servers = []

    def addServer(self):
        self._servers.append("Server 1")
        self._servers.append("Server 2")
        self._servers.append("Server 3")
        self._servers.append("Server 4")

    def changeServer(self):
        self._servers.pop()
        self._servers.append("Server 5")

if __name__ == '__main__':

    hc1 = HealthCheck()
    hc2 = HealthCheck()

    hc1.addServer()
    print("Schedule health check for servers (1)..")
    for i in range(4):
        print("Checking ", hc1._servers[i])

    hc2.changeServer()
    print("Schedule health check for servers (2)..")
    for i in range(4):
        print("Checking ", hc2._servers[i])

```


装饰器的单例模式

```
#coding=utf8

def singleton(cls, *args, **kw):
    instances = {}

    def _singleton(*args, **kw):
        if cls not in instances:
            instances[cls] = cls(*args, **kw)
        return instances[cls]

    return _singleton

@singleton
class A():
    pass

if __name__ == '__main__':
    a = A()
    b = A()
    print(a, b)

```
