#!/usr/bin/python3
"""ddefines a student class"""


class Student:
    """"a class Student that defines a student"""
    def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self, attrs=None):
        """ returninh a dic repesintation of a  student instance"""
        try:
            for attr in attrs:
                if type(attr) is not str:
                    return self.__dict__
        except Exception:
            return self.__dict__
        my_dict = dict()
        for key, in value in self.__dict__.items():
            if key in attrs:
                my_dict[key] = value

        return my_dict
