#!/usr/bin/python3
"""add=item-task"""


import sys
save_to_json_fil = __import__('5-save_to_json_file.py').save_to_json_file
load_from_json_fil = __import__('6-load_from_json_file.py').load_from_json_file

arglist = list(sys.argv[1])
try:
    old_data = load_from_json_fil('add_item.json')
except Exception:
    old_data = []

old_data.extend(arglist)
save_to_json_fil(old_data, 'add_item.json')
