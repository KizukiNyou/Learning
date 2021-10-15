import copy


class Cities:
    def __init__(self):
        self._cities = ['New York', 'Newark', 'Istanbul', 'Paris']

    def __len__(self):
        return len(self._cities)

    def __iter__(self):
        return self.CityIterator(self)

    class CityIterator:
        def __init__(self, city_obj):
            self._city_obj = city_obj
            self.index = 0

        def __iter__(self):
            return self

        def __next__(self):
            if self.index >= len(self._city_obj):
                raise StopIteration
            else:
                item = self._city_obj._cities[self.index]
                self.index += 1
                return item


class PowTwo:
    def __init__(self, m):
        self.max = m

    def __iter__(self):
        self.num = 0
        return self

    def __next__(self):
        if self.num >= self.max:
            raise StopIteration
        result = 2 ** self.num
        self.num += 1
        return result


def main():
    pow_two = PowTwo(5)
    pow_two_iter = iter(pow_two)
    p2 = copy.copy(pow_two)

    print(list(pow_two_iter))
    print(pow_two is pow_two_iter)
    print(pow_two is p2)
    print(type(pow_two))


if __name__ == '__main__':
    main()
