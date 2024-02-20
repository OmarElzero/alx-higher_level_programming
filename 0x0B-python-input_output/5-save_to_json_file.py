#!/usr/bin/python3
"""defining save_to_json_file function"""


import json


def save_to_json_file(my_obj, filename):
    """Save Python object as JSON to a file."""
    with open(filename, 'w') as file:
        json.dump(my_obj, file)
