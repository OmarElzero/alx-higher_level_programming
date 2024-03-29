#!/usr/bin/python3
"""defining  load_from_json_file function"""


import json


def load_from_json_file(filename):
    """ load_from_json_file."""
    with open(filename, 'r') as file:
        return json.load(file)
