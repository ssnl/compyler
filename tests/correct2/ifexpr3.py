# basic nested ifexpr: tests if nested if-expressions resolve types properly
z = 2
y = 4
x = 3 if True else y if False else z if "hi" else 3
