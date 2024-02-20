#!/usr/bin/python3
"""defining save_to_json_file function"""


import json


def save_to_json_file(my_obj, filename):
    """save_to_json_file """
    with open(filename, 'w') as file:
        file = json.loads(my_obj)
        return file
