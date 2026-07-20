# What Is Abstraction and How Does It Help Keep Complex Systems Organized?

## Abstraction
Abstraction is the process of hiding complex implementation details and showing only the essential features of an object or system. Think of it as focusing on what something does rather than how it does it

Abstraction is not limited to Python, its a programming concept that can be implemented in many langauges that support object-oriented programming. 

### Example
```python
from abc import ABC, abstractmethod

# Define an abstract base class
class AbstractClass(ABC):
    @abstractmethod
    def abstract_method(self):
        pass

# Concrete subclass that implements the abstract method
class ConcreteClassOne(AbstractClass):
    def abstract_method(self):
        print('Implementation in ConcreteClassOne')

# Another concrete subclass
class ConcreteClassTwo(AbstractClass):
    def abstract_method(self):
        print('Implementation in ConcreteClassTwo')
```

- In practice, abstraction would look something like this:

```python
from abc import ABC, abstractmethod

class Animal(ABC): # Inherits from abstract base class
   @abstractmethod # Abstract method decorator
   def make_sound(self):  # The method subclasses must override
       pass

# Concrete class that will override the abstract method
class Dog(Animal):
   def make_sound(self):
       print('Woof!')

# Another concrete class that will override the abstract method
class Cat(Animal):
   def make_sound(self):
       print('Meow!')

# Another concrete class that will override the abstract method
class Monkey(Animal):
   def make_sound(self):
       print('Ooh ooh aah aah!')

# Create instances of each concrete class
animals = [Dog(), Cat(), Monkey()]

# Loop through the instances to call the make_sound method
for animal in animals:
   animal.make_sound()

# Output:
# Woof!
# Meow!
# Ooh ooh aah aah!
```

- In this example, we are importing the ABC class and abstractmethod from the abc module. We then create an Animal class that inherits from ABC, and creat an abstract method, make_sound, in it that each subclass of Animal must override.

- Then we make the concrete classes, in this case Dog, Cat, and Monkey, which must override the make_sound abstract method. 

- We then instantiate the concrete class and call their make_sound method to show how each of them implements the make_sound abstract method in its own way.

