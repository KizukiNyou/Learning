class Softwares:
    # The init method is used to create an instance of the class
    # Constructor method
    def __init__(self, names: list):
        if names:
            self.names = list(names)
            self.versions = {}
            for name in names:
                self.versions[name] = 1  # Versions should start at version 1
        else:  # Empty List
            raise Exception("Please enter the names")

    def __str__(self):
        s = "The current softwares and their versions are listed below: \n"
        for key, value in self.versions.items():
            s += f"{key} : {value} \n"
        return s

    def __repr__(self):
        return 'Softwares(%r)' % self.names

    def __setitem__(self, name, version):
        if name in self.versions:
            self.versions[name] = version
        else:
            raise Exception("Software Name doesn't exist")

    def __getitem__(self, name):
        if name in self.versions:
            return self.versions[name]
        else:
            raise Exception("Software Name doesn't exist")

    def __delitem__(self, name):
        if name in self.versions:
            del self.versions[name]
            self.names.remove(name)
        else:
            raise Exception("Software Name doesn't exist")

    def __len__(self):
        return len(self.names)

    def __contains__(self, name):
        if name in self.versions:
            return True
        else:
            return False


def main():
    p = Softwares(['S1', 'S2', 'S3'])
    
    # "If you have enough information so 'eval(repr(c)) == c', that means 
    # you know everything there is to know about c."
    r = eval(repr(p))
    print(r)

    # Constants with same value share the same ID
    # Probably true for any immutable type
    x = 'str'
    y = 'str'
    w = (1, 2)
    v = (1, 2)
    a = 15.2
    b = 15.2
    print(hex(id(x)))
    print(hex(id(y)))
    print('--------------------------')
    print(hex(id(w)))
    print(hex(id(v)))
    print('--------------------------')
    print(hex(id(a)))
    print(hex(id(b)))
    print('--------------------------')


if __name__ == "__main__":
    main()
    
