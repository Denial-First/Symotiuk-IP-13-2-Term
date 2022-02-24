
def write_file(path):
    fout = open(path, 'w')
    line = input("Введіть текст. Після завершення введіть '+' у новому рядку.\n")
    while line != chr(43):
        fout.write(line)
        line = input()
        if line != chr(43):
            fout.write('\n')
    fout.close()


def read_file(path):
    fin = open(path, 'rt')
    for string in fin:
        print(string, end='')
    print('\n')
    fin.close()


def sort(list):
    for i in range(len(list) - 1):
        for j in range(len(list) - i - 1):
            if len(list[j]) < len(list[j + 1]):
                tmp = list[j]
                list[j] = list[j + 1]
                list[j + 1] = tmp


def format_file(first_path, second_path):
    fin = open(first_path, 'r')
    fout = open(second_path, 'w')
    list = []
    for string in fin:
        list.append(string.rstrip('\n'))
    sort(list)
    for i in list:
        fout.write(str(len(i)) + ' ' + i + '\n')
    fout.close()
    fin.close()
