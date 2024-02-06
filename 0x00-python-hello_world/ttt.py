import matplotlib.pyplot as plt
import json
import csv

students = {}
courses = {}

def add_student(student_id, name):
    if student_id not in students:
        students[student_id] = {'name': name, 'courses': {}}
        print(f"Student '{name}' added successfully.")
    else:
        print(f"Student with ID '{student_id}' already exists.")

def view_student(student_id):
    if student_id in students:
        student = students[student_id]
        print(f"Student ID: {student_id}\nName: {student['name']}\nCourses: {', '.join(student['courses'].keys())}")
    else:
        print(f"Student with ID '{student_id}' not found.")

def update_student(student_id, new_name):
    if student_id in students:
        students[student_id]['name'] = new_name
        print(f"Student ID '{student_id}' updated successfully. New Name: {new_name}")
    else:
        print(f"Student with ID '{student_id}' not found.")

def delete_student(student_id):
    if student_id in students:
        del students[student_id]
        print(f"Student with ID '{student_id}' deleted successfully.")
    else:
        print(f"Student with ID '{student_id}' not found.")

def add_course(course_code, course_name, credit_hours):
    if course_code not in courses:
        courses[course_code] = {'name': course_name, 'credit_hours': credit_hours}
        print(f"Course '{course_name}' added successfully.")
    else:
        print(f"Course with Code '{course_code}' already exists.")

def view_course(course_code):
    if course_code in courses:
        course = courses[course_code]
        print(f"Course Code: {course_code}\nName: {course['name']}\nCredit Hours: {course['credit_hours']}")
    else:
        print(f"Course with Code '{course_code}' not found.")

def update_course(course_code, new_name, new_credit_hours):
    if course_code in courses:
        courses[course_code]['name'] = new_name
        courses[course_code]['credit_hours'] = new_credit_hours
        print(f"Course Code '{course_code}' updated successfully. New Name: {new_name}, New Credit Hours: {new_credit_hours}")
    else:
        print(f"Course with Code '{course_code}' not found.")

def delete_course(course_code):
    if course_code in courses:
        del courses[course_code]
        print(f"Course with Code '{course_code}' deleted successfully.")
    else:
        print(f"Course with Code '{course_code}' not found.")

# def save_to_json(filename):
#     data = {
#         'students': {s_id: {'name': s['name'], 'courses': {c_id: {'name': c['name'], 'credit_hours': c['credit_hours']} for c_id, c in s['courses'].items()}} for s_id, s in students.items()},
#         'courses': {c_id: {'name': c['name'], 'credit_hours': c['credit_hours']} for c_id, c in courses.items()}
#     }

#     try:
#         with open(filename, 'w') as file:
#             json.dump(data, file, indent=2)
#         print(f"Data saved to {filename} successfully.")
#     except Exception as e:
#         print(f"Error saving data to {filename}: {e}")

def enroll_student_in_course(student_id, course_code):
    if student_id in students and course_code in courses:
        students[student_id]['courses'][course_code] = courses[course_code]
        print(f"Student '{students[student_id]['name']}' enrolled in '{courses[course_code]['name']}' successfully.")
    else:
        print("Enrollment failed. Student or course not found.")

def add_grade(student_id, course_code, grade):
    if student_id in students and course_code in courses:
        if course_code in students[student_id]['courses']:
            students[student_id]['courses'][course_code]['grade'] = grade
            print(f"Grade '{grade}' added for student '{students[student_id]['name']}' in course '{course_code}' successfully.")
        else:
            print(f"Student '{students[student_id]['name']}' is not enrolled in course '{course_code}'.")
    else:
        print("Grade addition failed. Student or course not found.")

# def save_to_csv(filename):
#     try:
#         with open(filename, 'w', newline='') as file:
#             writer = csv.writer(file)
#             writer.writerow(['Student ID', 'Course Code', 'Grade'])

#             for student_id, student in students.items():
#                 for course_code, course in student['courses'].items():
#                     writer.writerow([student_id, course_code, course.get('grade', '')])

#         print(f"Data saved to {filename} successfully.")
#     except Exception as e:
#         print(f"Error saving data to {filename}: {e}")

def generate_html_certificate(student_id, filename):
    if student_id in students:
        student = students[student_id]

        # Calculate GPA
        total_credit_hours = 0
        total_grade_points = 0

        for course_code, course in student['courses'].items():
            if 'grade' in course:  # Check if a grade is available for the course
                total_credit_hours += course['credit_hours']
                total_grade_points += grade_to_points(course['grade'])

        gpa = total_grade_points / total_credit_hours if total_credit_hours > 0 else 0

        # Generate HTML certificate
    #     html_content = f"""
    #     <!DOCTYPE html>
    #     <html lang="en">
    #     <head>
    #         <meta charset="UTF-8">
    #         <meta name="viewport" content="width=device-width, initial-scale=1.0">
    #         <title>Certificate for {student['name']}</title>
    #     </head>
    #     <body>
    #         <h1>Certificate of Achievement</h1>
    #         <p>This is to certify that</p>
    #         <h2>{student['name']}</h2>
    #         <p>has successfully completed the following courses with the following grades:</p>
    #         <ul>
    #     """

    #     for course_code, course in student['courses'].items():
    #         if 'grade' in course:
    #             html_content += f"<li>{course['name']} ({course_code}): {course['grade']}</li>"

    #     html_content += f"""
    #         </ul>
    #         <p>Overall GPA: {gpa:.2f}</p>
    #     </body>
    #     </html>
    #     """

    #     try:
    #         with open(filename, 'w') as file:
    #             file.write(html_content)
    #         print(f"HTML certificate generated for {student['name']} and saved to {filename} successfully.")
    #     except Exception as e:
    #         print(f"Error generating HTML certificate: {e}")
    # else:
    #     print(f"Student with ID '{student_id}' not found.")

def grade_to_points(grade):
    grading_scale = {'A': 4.0, 'B': 3.0, 'C': 2.0, 'D': 1.0, 'F': 0.0}
    return grading_scale.get(grade.upper(), 0.0)

def generate_bar_chart():
    course_names = [course['name'] for course in courses.values()]
    grade_counts = {course_code: {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'F': 0} for course_code in courses}

    for student in students.values():
        for course_code, course in student['courses'].items():
            if 'grade' in course:
                grade_counts[course_code][course['grade']] += 1

    for course_code, grades in grade_counts.items():
        grades_list = [grades['A'], grades['B'], grades['C'], grades['D'], grades['F']]
        
        plt.figure(figsize=(10, 6))
        plt.bar(['A', 'B', 'C', 'D', 'F'], grades_list, color=['green', 'blue', 'yellow', 'orange', 'red'])
        plt.title(f"Results for {courses[course_code]['name']}")
        plt.xlabel("Grades")
        plt.ylabel("Number of Students")
        plt.savefig(f"bar_chart_{course_code}.png")
        plt.show()

def generate_pie_chart():
    course_counts = {course_code: 0 for course_code in courses}

    for student in students.values():
        for course_code in student['courses']:
            course_counts[course_code] += 1

    labels = [courses[course_code]['name'] for course_code in course_counts]
    sizes = [course_counts[course_code] for course_code in course_counts]

    plt.figure(figsize=(10, 6))
    plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=90)
    plt.title("Percentage of Students Registered in Each Course")
    plt.savefig("pie_chart.png")
    plt.show()

def display_menu():
    print("\nGrade Book System Menu:")
    print("1. Manage Students")
    print("2. Manage Courses")
    print("3. Enroll Student in Course")
    print("4. Add Grade for Student in Course")
    print("5. Generate HTML Certificate")
    print("6. Generate Bar Chart")
    print("7. Generate Pie Chart")
    print("8. Exit")

def run():
    while True:
        display_menu()
        choice = input("Enter your choice (1-8): ")

        if choice == '1':
            student_id = input("Enter Student ID: ")
            name = input("Enter Student Name: ")
            print("1.Add student")
            print("2.delete student")
            print("3.ubdate student information")
            print("4.veiw student information")
            choice_z = int(input(" : "))
            if choice_z == 1 :
             add_student(student_id, name)
            elif choice_z == 2 :
             delete_student(student_id)
            elif choice_z == 3 :
             update_student(student_id, name)
            elif choice_z == 4 :
             view_student(student_id)

        elif choice == '2':
            course_code = input("Enter Course Code: ")
            course_name = input("Enter Course Name: ")
            credit_hours = int(input("Enter Credit Hours: "))
            print("1.Add course")
            print("2.delete course")
            print("3.ubdate course information")
            print("4.veiw course information")
            choice_h = int(input(" : "))
            if choice_h == 1 :
             add_course(course_code, new_name, new_credit_hours)
            elif choice_h == 2 :
             delete_course(course_code)
            elif choice_h == 3 :
             update_course(course_code, new_name, new_credit_hours)
            elif choice_h == 4 :
             view_course(course_code)

        elif choice == '3':
            student_id = input("Enter Student ID: ")
            course_code = input("Enter Course Code: ")
            enroll_student_in_course(student_id, course_code)

        elif choice == '4':
            student_id = input("Enter Student ID: ")
            course_code = input("Enter Course Code: ")
            grade = input("Enter Grade: ")
            add_grade(student_id, course_code, grade)

        elif choice == '5':
            student_id = input("Enter Student ID: ")
            filename = input("Enter Filename for HTML Certificate: ")
            generate_html_certificate(student_id, filename)

        elif choice == '6':
            generate_bar_chart()

        elif choice == '7':
            generate_pie_chart()

        elif choice == '8':
            print("Exiting Grade Book System. Goodbye!")
            break

        else:
            print("Invalid choice. Please enter a number from 1 to 8.")

if __name__ == "__main__":
    run()
