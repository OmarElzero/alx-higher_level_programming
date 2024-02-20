#!/usr/bin/python3
"""add=item-task"""


import sys
holder1 = save_to_json_file
holder2 = load_from_json_file
save_to_json_file = __import__('5-save_to_json_file.py').holder1
load_from_json_file = __import__('6-load_from_json_file.py').holder2

arglist = list(sys.argv[1])
try:
    old_data = load_from_json_file('add_item.json')
except Exception:
    old_data = []

old_data.extend(arglist)
save_to_json_file(old_data, 'add_item.json')
