from hexlet_pytest.example import reverse

from pathlib import Path

def get_test_data_path(filename):
    return Path(__file__).parent / 'test_data' / filename

def read_file(filename):
    return get_test_data_path(filename).read_text()

# тестируем функцию process(), которая как-то обрабатывает файл
def test_reverse_with_data():
    before = read_file('before.txt')
    expected = read_file('result.txt')
    actual = reverse(before.rstrip())

    assert actual == expected.rstrip()



def test_reverse():
    assert reverse('Hexlet') == 'telxeH'


def test_reverse_for_empty_string():
    assert reverse('') == ''
