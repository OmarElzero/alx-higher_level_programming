#!/usr/bin/python3
def safe_function(fct, *args):
    import sys
    try :
        res = fct(*args)
        return res
    except Exception as a :
        print("Exception: {}".format(a),file = sys.stderr)
        return None
    