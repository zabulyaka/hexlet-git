from hexlet_testing.package_name.capitalize import capitalize


def test_capitalize():
    print('Начинаем тестирование capitalize')

    assert capitalize('hello') == 'Hello'

    assert capitalize('') == ''

    print('Тесты capitalize пройдены успешно!')
