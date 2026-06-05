"""
Generate project deliverables for SCMS.

Outputs:
- docs/class_diagram.png
- docs/project_report.pdf

This script is intentionally simple so it can be explained in viva if needed.
"""

from pathlib import Path
from textwrap import wrap

from fpdf import FPDF
from PIL import Image, ImageDraw, ImageFont


ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / "docs"


def get_font(size=22, bold=False):
    font_name = "arialbd.ttf" if bold else "arial.ttf"
    font_path = Path("C:/Windows/Fonts") / font_name
    if font_path.exists():
        return ImageFont.truetype(str(font_path), size)
    return ImageFont.load_default()


def draw_box(draw, xy, title, lines, fill="#f6f8fa"):
    x1, y1, x2, y2 = xy
    draw.rounded_rectangle(xy, radius=10, outline="#222222", width=2, fill=fill)
    draw.rectangle((x1, y1, x2, y1 + 38), fill="#dce8f7", outline="#222222", width=2)
    draw.text((x1 + 10, y1 + 8), title, fill="#111111", font=get_font(21, True))

    y = y1 + 48
    for line in lines:
        draw.text((x1 + 10, y), line, fill="#111111", font=get_font(17))
        y += 24


def draw_arrow(draw, start, end):
    draw.line((start, end), fill="#333333", width=2)
    sx, sy = start
    ex, ey = end
    if ey > sy:
        points = [(ex, ey), (ex - 7, ey - 14), (ex + 7, ey - 14)]
    elif ey < sy:
        points = [(ex, ey), (ex - 7, ey + 14), (ex + 7, ey + 14)]
    else:
        points = [(ex, ey), (ex - 14, ey - 7), (ex - 14, ey + 7)]
    draw.polygon(points, fill="#333333")


def make_class_diagram():
    img = Image.new("RGB", (1800, 2400), "white")
    draw = ImageDraw.Draw(img)

    draw.text((40, 30), "Smart Campus Management System - Class Diagram",
              fill="#111111", font=get_font(36, True))
    draw.text((40, 78), "HITEC University Taxila | CS-104L OOP",
              fill="#333333", font=get_font(23))

    boxes = {
        "Person": ((80, 150, 420, 310), ["# name, cnic", "# age, contact", "+ displayInfo()"]),
        "Student": ((80, 390, 420, 590), ["- rollNo, semester", "- gpa", "- enrolledCourses[]", "+ calculateGrade()", "+ displayInfo()"]),
        "GradStudent": ((80, 680, 420, 820), ["- thesisTitle", "+ displayInfo()"]),
        "Faculty": ((500, 390, 840, 570), ["- employeeID", "- department", "- designation", "- assignedCourses[]", "+ displayInfo()"]),
        "Staff": ((500, 650, 840, 810), ["- staffID", "- role", "- salary", "+ displayInfo()"]),
        "Course": ((980, 150, 1360, 385), ["- courseCode", "- courseName", "- Faculty* instructor", "- Student* enrolled[]", "- Student* waiting[]", "+ enrollStudent()", "+ display roster", "+ operator overloads"]),
        "Enrollment": ((1420, 150, 1740, 310), ["- Student* student", "- Course* course", "- date, grade"]),
        "LibraryItem": ((80, 950, 440, 1155), ["# itemID, title", "# author, year", "+ checkout()", "+ checkin()", "+ displayItem()"]),
        "Book": ((80, 1220, 440, 1425), ["- isbn", "- genre", "- copiesAvailable", "+ checkout()", "+ checkin()"]),
        "Journal": ((520, 1220, 880, 1425), ["- issn", "- volume", "- issueNumber", "+ checkout()", "+ checkin()"]),
        "Library": ((980, 950, 1360, 1185), ["- LibraryItem* items[]", "- IssuedRecord issued[]", "+ searchByTitle()", "+ displayIssuedRecords()", "+ save/load catalog"]),
        "FeeRecord": ((1420, 950, 1740, 1190), ["- Student* studentRef", "- semesterFee", "- hostelFee", "- balance", "- double* payments", "+ operator-=()", "+ displayPayments()"]),
        "Invoice": ((1420, 1240, 1740, 1445), ["- static counter", "- string* items", "+ getInvoiceCounter()", "+ copy constructor", "+ destructor"]),
        "CampusService": ((80, 1580, 440, 1700), ["+ showServiceName()"]),
        "Accommodation": ((80, 1810, 440, 1960), ["+ allocateRoom()", "+ vacateRoom()"]),
        "Reportable": ((520, 1810, 880, 1960), ["+ generateReport()"]),
        "Room": ((980, 1580, 1360, 1805), ["- roomNumber", "- type, floor", "- Student* occupants[]", "+ add/remove student", "+ hasStudent()"]),
        "HostelBlock": ((980, 1880, 1360, 2065), ["- blockName", "- Room rooms[]", "+ addRoom()", "+ getTotalOccupants()"]),
        "HostelManager": ((1420, 1740, 1740, 2005), ["- HostelBlock block", "+ allocateRoom()", "+ vacateRoom()", "+ generateReport()", "+ showSummary()"]),
    }

    for name, (xy, lines) in boxes.items():
        draw_box(draw, xy, name, lines)

    # Inheritance / relationship arrows.
    draw_arrow(draw, (250, 390), (250, 310))
    draw_arrow(draw, (250, 680), (250, 590))
    draw_arrow(draw, (670, 390), (420, 250))
    draw_arrow(draw, (670, 650), (420, 275))
    draw_arrow(draw, (250, 1220), (250, 1130))
    draw_arrow(draw, (700, 1220), (300, 1130))
    draw_arrow(draw, (250, 1810), (250, 1700))
    draw_arrow(draw, (700, 1810), (300, 1700))
    draw_arrow(draw, (1510, 1740), (440, 1885))
    draw_arrow(draw, (1510, 1740), (880, 1885))
    draw_arrow(draw, (1360, 250), (1420, 230))
    draw_arrow(draw, (980, 250), (840, 470))
    draw_arrow(draw, (1180, 360), (410, 450))
    draw_arrow(draw, (980, 1050), (440, 1040))
    draw_arrow(draw, (1420, 1040), (420, 500))
    draw_arrow(draw, (1190, 1880), (1190, 1780))
    draw_arrow(draw, (1420, 1870), (1360, 1960))
    draw_arrow(draw, (980, 1675), (420, 500))

    draw.text((40, 2290),
              "Legend: arrows show inheritance or main object relationships. See docs/class_diagram.mmd for Mermaid source.",
              fill="#333333", font=get_font(18))

    out = DOCS / "class_diagram.png"
    img.save(out)
    return out


class ReportPDF(FPDF):
    def header(self):
        self.set_font("Helvetica", "B", 12)
        self.set_x(self.l_margin)
        self.cell(0, 8, "Smart Campus Management System (SCMS)", 0, 1, "C")
        self.ln(2)

    def footer(self):
        self.set_y(-15)
        self.set_font("Helvetica", "I", 8)
        self.set_x(self.l_margin)
        self.cell(0, 10, f"Page {self.page_no()}", 0, 0, "C")


def add_wrapped(pdf, text, size=11, style="", line_height=6):
    pdf.set_font("Helvetica", style, size)
    text = text.replace("`", "")
    pdf.set_x(pdf.l_margin)
    width = pdf.w - pdf.l_margin - pdf.r_margin
    pdf.multi_cell(width, line_height, text)
    pdf.ln(1)


def add_section(pdf, title):
    pdf.ln(3)
    pdf.set_font("Helvetica", "B", 15)
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 8, title, 0, 1)


def add_bullets(pdf, items):
    pdf.set_font("Helvetica", "", 11)
    width = pdf.w - pdf.l_margin - pdf.r_margin
    for item in items:
        pdf.set_x(pdf.l_margin)
        pdf.multi_cell(width, 6, "- " + item)
    pdf.ln(1)


def make_report(diagram_path):
    pdf = ReportPDF()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()

    pdf.set_font("Helvetica", "B", 20)
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 12, "Smart Campus Management System", 0, 1, "C")
    pdf.set_font("Helvetica", "", 12)
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 8, "CS-104L Object-Oriented Programming", 0, 1, "C")
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 8, "HITEC University Taxila", 0, 1, "C")
    pdf.ln(6)

    add_section(pdf, "Group Members")
    add_bullets(pdf, [
        "Ahmad Ali | Reg No: 25-CS-067",
        "Umer Altaf | Reg No: 25-CS-057",
        "Muhammed Ahmad | Reg No: 25-CS-252",
    ])

    add_section(pdf, "Introduction")
    add_wrapped(pdf, "This project is a simple command-line Smart Campus Management System written in C++. "
                     "It manages basic campus records such as students, faculty, courses, library items, fee records, "
                     "hostel rooms, and reports. The code is made with beginner-level OOP concepts and simple arrays "
                     "so it can be understood and explained by second-semester students.")

    add_section(pdf, "System Modules")
    add_bullets(pdf, [
        "Person module: Person, Student, GradStudent, Faculty, and Staff classes.",
        "Course module: Course and Enrollment classes with capacity checking.",
        "Library module: Book and Journal catalog using file handling and arrays.",
        "Finance module: FeeRecord and Invoice classes with copy handling and static invoice counter.",
        "Hostel module: Room, HostelBlock, and HostelManager using composition and multiple inheritance.",
        "Reports module: student sorting and campus text report generation.",
    ])

    add_section(pdf, "Class Diagram")
    add_wrapped(pdf, "The class diagram below shows the main classes and relationships used in the project.")
    pdf.image(str(diagram_path), x=12, w=185)

    pdf.add_page()
    add_section(pdf, "OOP Concepts Implemented")
    concepts = [
        "Classes and Objects: All modules use C++ classes and objects.",
        "Encapsulation: Private data members are accessed through public methods.",
        "Constructors: Default and parameterized constructors are used in many classes.",
        "Destructors: Library and Invoice clean dynamic memory.",
        "Single Inheritance: Student inherits from Person.",
        "Multi-level Inheritance: GradStudent inherits from Student.",
        "Multiple Inheritance: HostelManager inherits from Accommodation and Reportable.",
        "Virtual Inheritance: Accommodation and Reportable virtually inherit CampusService.",
        "Abstract Classes: Person, LibraryItem, Accommodation, and Reportable.",
        "Runtime Polymorphism: Person pointers call different displayInfo functions.",
        "Operator Overloading: Course ==, Course <<, Course +, FeeRecord -=.",
        "Friend Functions: operator<< is used for Course and Invoice.",
        "Static Members: Invoice uses invoiceCounter.",
        "Copy Constructor and Assignment: FeeRecord and Invoice examples.",
        "Search Functions: Library has searchByTitle and searchByID.",
        "Array Collections: Arrays are used for courses, library items, rooms, and students.",
        "Exception Handling: CapacityExceededException and OverdueException.",
        "File I/O: Library catalog and campus report files.",
        "Sorting: Reports sort students by GPA.",
        "Composition: HostelManager contains HostelBlock.",
        "Aggregation: Course stores Faculty pointer and Room stores Student pointers.",
    ]
    add_bullets(pdf, concepts)

    add_section(pdf, "Library and Finance Details")
    add_wrapped(pdf, "The Library module loads records from data/library_catalog.txt, displays books and "
                     "journals, searches by title or ID, issues a book, shows issued records, and checks overdue returns. The Finance module "
                     "tracks fee balance, accepts payment with operator-=, deep-copies payment history, and creates invoices with "
                     "a static invoice counter.")

    add_section(pdf, "Testing Summary")
    add_bullets(pdf, [
        "Build command .\\build.bat completed successfully.",
        "Menu options 1 to 7 were tested.",
        "Library demo loaded catalog data, issued B001, and showed overdue fine.",
        "Finance demo showed payment, copy constructor, copy assignment, invoice, and invoice copy.",
        "Hostel demo showed service name, allocation, duplicate check, summary, report, and vacate room.",
        "Reports demo sorted students by GPA and created data/campus_report.txt.",
        "Wrong input test with abc did not freeze the program.",
    ])

    add_section(pdf, "Challenges and Solutions")
    add_bullets(pdf, [
        "Understanding polymorphism: solved by using Person* array in main.cpp.",
        "Managing dynamic memory: solved by deleting Library items and Invoice item arrays.",
        "Handling full course capacity: solved by using a custom exception class.",
        "File handling format: solved by using simple pipe-separated text data.",
    ])

    add_section(pdf, "Conclusion")
    add_wrapped(pdf, "This project helped practice core C++ OOP concepts in a practical campus system. "
                     "The project is intentionally console-based and simple so each module can be explained in viva. "
                     "Before final submission, real output screenshots should be added by the group.")

    add_section(pdf, "References")
    add_bullets(pdf, [
        "Course project brief provided by HITEC University Taxila.",
        "C++ class notes and lab practice.",
        "cppreference.com for basic C++ syntax reference.",
    ])

    out = DOCS / "project_report.pdf"
    pdf.output(str(out))
    return out


def main():
    DOCS.mkdir(exist_ok=True)
    diagram = make_class_diagram()
    report = make_report(diagram)
    print(f"Generated: {diagram}")
    print(f"Generated: {report}")


if __name__ == "__main__":
    main()
