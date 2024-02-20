#!/usr/bin/python3
"""ddefines a student class"""


class Student:
    """"a class Student that defines a student"""
    def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self):
        """ returninh a dic repesintation of a  student instance"""
        return self.__dict__
