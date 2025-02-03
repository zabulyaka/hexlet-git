from hexlet_testing.package_name.capitalize import capitalize


def test_capitalize():
    print('Начинаем тестирование')
    if capitalize('hello') != 'Hello':
        raise Exception('Функция работает неверно!')

    if capitalize('') != '':
        raise Exception('Функция работает неверно!')

    print('Все тесты пройдены!')
