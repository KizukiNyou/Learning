# \_\_init\_\_
* Used to create an instance of the class
* The instance variables are defined inside init()

# \_\_repr\_\_ and \_\_str\_\_
* "\_\_repr\_\_ is for developers, \_\_str\_\_ is for customers."
* If \_\_repr\_\_ is defined, and \_\_str\_\_ is not, the object will behave as though \_\_str\_\_ = \_\_repr\_\_

## \_\_repr\_\_:
* Implementation is required
* The goal is to be unambiguous
* Every object you implement should have a functional repr() implementation that is
* Usable for better understanding the object
* Template: "MyClass(this=%r,that=%r)" % (self.this,self.that)
* You need to use %r here. Using %s defeats the goal of repr.
* You want to be able to differentiate MyClass(3) and MyClass("3")
* "This is everything you need to know about this instance"

## \_\_str\_\_:
* Implementation is optional
* The goal is to be readable
* It's better to represent it in a way that a user, not a programmer, would want to read it.
* Chop off useless digits, pretend to be some other class — as long is it supports readability, it is an improvement.
* Implement \_\_str\_\_ if you think it would be useful to have a string version which errs on the side of readability.
* Container's \_\_str\_\_ method uses contained object's \_\_repr\_\_
* The print() function calls __str__ method (if defined) else calls __repr__

# \_\_iter\_\_

# \_\_next\_\_

# \_\_setitem\_\_
`my_obj[key] = value`
* When assigning values in a dictionary, the setitem method is invoked.

# \_\_getitem\_\_
`foo = my_obj[key]`
* The getitem method is called when we use the [] operator of a dictionary

# \_\_len\_\_
`len(my_obj)`
* Returns the lenght of the object

# \_\_contains\_\_
`if foobar in my_obj`
* Implements the "in" operator
* The return value has to be a boolean

# \_\_eq\_\_
`my_obj1 == my_obj2`
* Implements the "==" operator
