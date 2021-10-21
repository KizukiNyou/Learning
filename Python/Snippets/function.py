# Sources:
# https://realpython.com/inner-functions-what-are-they-good-for/
# https://realpython.com/primer-on-python-decorators/#first-things-first
# https://dbader.org/blog/python-first-class-functions

# Outer Function
def main():
    # Inner Function
    def yell(text: str):
        return text.upper() + '!'

    # Functions are objects (and so, can be used as variables)
    bark = yell
    print(bark('hello, world'))  # Same behavior as yell

    # Bark copies yell's attributes
    print(bark.__name__)  # yell
    print(bark.__qualname__)  # main.<locals>.yell

    # yell can be safely deleted since it's a local/inner function
    del yell
    print(bark('hello, world'))  # Still works

    # Functions can be stored in Data Structures
    funcs = [bark, str.lower, str.capitalize]
    print(funcs)  # Prints their repr methods
    print(funcs[2]('you can also call them like this!'))  # Works

    # Functions can be passed around as arguments to other Functions
    def greet(func):
        print(func("Hi, I'm a function passed as an argument"))

    greet(bark)  # HI, I'M A FUNCTION PASSED AS AN ARGUMENT!
    greet(str.capitalize)  # Hi, i'm a function passed as an argument
    greet(lambda text: text.lower() + '...')  # hi, i'm a function passed as an argument...

    # Using map function to apply bark to a list
    print(list(map(bark, ['hey', 'how', 'are', 'you'])))

    # Functions can be returned from other Functions
    def get_speak_func(volume):
        def whisper(text):
            return text.lower() + '...'

        def yell2(text):
            return text.upper() + '!'

        if volume > 0.5:
            return yell2
        else:
            return whisper

    speak_func = get_speak_func(0.7)
    print(speak_func('hello'))
    print(get_speak_func(0.3)('does this work'))  # Works


if __name__ == '__main__':
    main()
