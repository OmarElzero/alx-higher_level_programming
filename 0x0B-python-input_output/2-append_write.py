#!/usr/bin/python3
"""defining append_write_file function"""


def append_write(filename="", text=""):
    """append_write filename with the utf-8"""
    with open(filename, 'a', encoding='utf-8') as file:
        return file.write(text)
