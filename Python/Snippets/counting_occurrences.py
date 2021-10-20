# Source:
# https://betterprogramming.pub/an-alternative-to-python-dictionaries-5d54aa4c5a6

# We have a list of numbers and we want to find the number of occurrences of each number in the list.
number_list = [7, 2, 2, 4, 2, 5, 7, 10, 2, 9, 2, 8, 5, 3, 4,
               2, 4, 2, 4, 8, 2, 1, 2, 5, 6, 7, 9, 4, 1, 8]


def main():
    # Usual approach with dict
    dict_ = {}

    for number in number_list:

        if number not in dict_:
            dict_[number] = 0

        dict_[number] += 1

    print('dict_:', dict_)

    # Approach with defaultdict:
    from collections import defaultdict

    # Inner function to demonstrate default functionality
    def default_value():
        return 0  # Could be anything

    def_dict = defaultdict(default_value)

    # Since I'm not using default_value() more than once,
    # I could also achieve the same effect using an anonymous function
    def_dict_2 = defaultdict(int)

    # Same code as before, but using defaultdict
    for number in number_list:
        def_dict[number] += 1
        def_dict_2[number] += 1

    # I'm converting them to dict for merely aesthetic reasons (better print)
    print('def_dict:', dict(def_dict))
    print('def_dict_2:', dict(def_dict_2))

    # We could achieve the same result using the class Counter
    from collections import Counter

    cont = Counter(number_list)
    print('cont:', dict(cont))


if __name__ == '__main__':
    main()
