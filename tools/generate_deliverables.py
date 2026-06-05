"""
Generate project deliverables for SCMS.

Outputs:
- docs/class_diagram.png
- docs/project_report.pdf

This script is intentionally simple so it can be explained in viva if needed.
"""

from pathlib import Path

from fpdf import FPDF
from PIL import Image, ImageDraw, ImageFont


ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / "docs"
OUTPUTS = DOCS / "test_outputs"
SCREENSHOTS = DOCS / "screenshots"


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


def render_console_image(input_path, output_path, title, max_lines=42):
    """Turn captured console text into a screenshot-style PNG."""
    if not input_path.exists():
        return None

    raw_lines = input_path.read_text(encoding="utf-8", errors="replace").splitlines()
    lines = []
    for line in raw_lines:
        line = line.lstrip("\ufeff")
        if line.strip() == "":
            lines.append("")
        else:
            lines.append(line[:115])

    if len(lines) > max_lines:
        lines = lines[:max_lines - 2] + ["", f"... see {input_path.name} for full captured output ..."]

    width = 1500
    line_height = 26
    height = 90 + max(1, len(lines)) * line_height + 35
    img = Image.new("RGB", (width, height), "#101418")
    draw = ImageDraw.Draw(img)
    title_font = get_font(26, True)
    text_font = get_font(20)

    draw.rectangle((0, 0, width, 58), fill="#20262c")
    draw.text((25, 16), title, fill="#f2f2f2", font=title_font)
    draw.ellipse((width - 95, 20, width - 77, 38), fill="#ff6057")
    draw.ellipse((width - 67, 20, width - 49, 38), fill="#ffbd2e")
    draw.ellipse((width - 39, 20, width - 21, 38), fill="#27c93f")

    y = 78
    for line in lines:
        draw.text((28, y), line, fill="#e7edf3", font=text_font)
        y += line_height

    output_path.parent.mkdir(exist_ok=True)
    img.save(output_path)
    return output_path


def make_output_screenshots():
    screenshot_jobs = [
        ("module1_person.txt", "Module 1 - Person Hierarchy", "module1_person.png"),
        ("module2_course.txt", "Module 2 - Course and Enrollment", "module2_course.png"),
        ("module3_library.txt", "Module 3 - Library System", "module3_library.png"),
        ("module4_finance.txt", "Module 4 - Fee and Finance", "module4_finance.png"),
        ("module5_hostel.txt", "Module 5 - Hostel Management", "module5_hostel.png"),
        ("module6_reports.txt", "Module 6 - Reports and Utilities", "module6_reports.png"),
        ("wrong_input.txt", "Wrong Input Test", "wrong_input.png"),
    ]

    made = []
    for text_file, title, image_file in screenshot_jobs:
        made_image = render_console_image(OUTPUTS / text_file, SCREENSHOTS / image_file, title)
        if made_image is not None:
            made.append(made_image)
    return made


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
        "Reports": ((80, 2120, 520, 2320), ["+ sortStudentsByGPA()", "+ findStudentByRollNo()", "+ showTopStudent()", "+ generateCampusTextReport()"]),
        "Utils": ((620, 2120, 1000, 2320), ["+ getTodayDate()", "+ printLine()", "+ printSmallLine()", "+ checkPositiveInt()"]),
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
    text = text.replace("`", "").encode("latin-1", "replace").decode("latin-1")
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


def add_code_line(pdf, text):
    pdf.set_font("Courier", "", 9)
    pdf.set_x(pdf.l_margin + 4)
    width = pdf.w - pdf.l_margin - pdf.r_margin - 4
    text = text.encode("latin-1", "replace").decode("latin-1")
    pdf.multi_cell(width, 5, text)
    pdf.ln(1)


def add_image_with_caption(pdf, image_path, caption):
    if not image_path.exists():
        return
    pdf.add_page()
    add_section(pdf, caption)
    pdf.image(str(image_path), x=10, w=190)


def make_report(diagram_path, screenshot_paths):
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
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 8, "Date: 05-06-2026", 0, 1, "C")
    pdf.set_x(pdf.l_margin)
    pdf.cell(0, 8, "GitHub URL: add public repository link after pushing", 0, 1, "C")
    pdf.ln(6)

    add_section(pdf, "Group Members")
    add_bullets(pdf, [
        "Ahmad Ali | Reg No: 25-CS-067",
        "Umer Altaf | Reg No: 25-CS-057",
        "Muhammed Ahmad | Reg No: 25-CS-252",
    ])

    add_section(pdf, "Introduction")
    add_wrapped(pdf, "This project is a simple command-line Smart Campus Management System written in C++. "
                     "It manages basic campus records for students, faculty, courses, library items, fee records, "
                     "hostel rooms, and reports. The purpose is to show all major OOP concepts from the CS-104L "
                     "course in one connected program. The program uses simple arrays, pointers, classes, file "
                     "handling, and exception handling. The design is intentionally easy to read so each group "
                     "member can explain the code during viva.")

    add_section(pdf, "System Modules")
    add_bullets(pdf, [
        "Person module: Person, Student, GradStudent, Faculty, and Staff classes.",
        "Course module: Course and Enrollment classes with capacity checking.",
        "Library module: Book and Journal catalog using file handling and arrays.",
        "Finance module: FeeRecord and Invoice classes with copy handling and static invoice counter.",
        "Hostel module: Room, HostelBlock, and HostelManager using composition and multiple inheritance.",
        "Reports module: student sorting, searching, campus text report, and PDF-style text report generation.",
    ])

    add_section(pdf, "Class Diagram")
    add_wrapped(pdf, "The class diagram below shows the main classes and relationships used in the project. "
                     "Inheritance is used in Person, LibraryItem, and hostel interfaces. Composition is used "
                     "where HostelManager contains HostelBlock, and aggregation is used where Course stores a "
                     "Faculty pointer without owning the faculty object.")
    pdf.image(str(diagram_path), x=12, w=185)

    pdf.add_page()
    add_section(pdf, "OOP Concepts Implementation")
    concepts = [
        ("Classes and Objects", "All modules define classes and make objects in main.cpp.", "Student s1(...); Course oop(...);"),
        ("Encapsulation", "Private data is changed through public getters, setters, and member functions.", "string getRollNo() const; void setGPA(double newGPA);"),
        ("Default Constructor", "Several classes provide simple empty/default object creation.", "Student::Student() : Person(), semester(1), gpa(0.0) {}"),
        ("Parameterized Constructor", "Objects can be created with real starting data.", "Course::Course(string code, string name, int credits, Faculty* teacher, int capacity)"),
        ("Copy Constructor", "Person, Course, FeeRecord, and Invoice copy object data.", "FeeRecord::FeeRecord(const FeeRecord& other)"),
        ("Destructors", "Library, Invoice, and HostelManager have destructors for cleanup.", "Invoice::~Invoice() { delete[] items; }"),
        ("Single Inheritance", "Student reuses common Person data and behavior.", "class Student : public Person"),
        ("Multi-level Inheritance", "GradStudent extends Student, which already extends Person.", "class GradStudent : public Student"),
        ("Multiple Inheritance", "HostelManager implements accommodation and report behavior.", "class HostelManager : public Accommodation, public Reportable"),
        ("Virtual Inheritance", "Accommodation and Reportable virtually inherit CampusService to avoid duplicate base parts.", "class Accommodation : virtual public CampusService"),
        ("Abstract Classes", "Person, LibraryItem, Accommodation, and Reportable cannot be directly instantiated.", "virtual void displayInfo() const = 0;"),
        ("Runtime Polymorphism", "Base pointers call the correct derived displayInfo function.", "Person* people[] = { &student, &faculty, &staff };"),
        ("Operator Overloading ==", "Course objects are compared by course code.", "bool Course::operator==(const Course& other) const"),
        ("Operator Overloading <<", "Course and Invoice can be printed using stream insertion.", "ostream& operator<<(ostream& out, const Course& course)"),
        ("Operator Overloading +", "Two course waiting lists are merged.", "Student** Course::operator+(Course& other)"),
        ("Operator Overloading -=", "FeeRecord records a payment and reduces balance.", "fee -= 25000;"),
        ("Friend Functions", "operator<< is declared as a friend for Course and Invoice.", "friend ostream& operator<<(ostream& out, const Invoice& invoice);"),
        ("Static Members", "Invoice has one shared invoiceCounter for all invoice objects.", "int Invoice::invoiceCounter = 0;"),
        ("Deep Copy", "FeeRecord and Invoice copy dynamic arrays instead of sharing them.", "payments = new double[paymentCount];"),
        ("Search Functions", "Library searches with a loop, and Reports uses std::find_if for roll number search.", "Student* Reports::findStudentByRollNo(Student* students[], int count, string rollNo)"),
        ("Array-based Collections", "The project uses arrays for courses, library items, rooms, and students.", "LibraryItem* items[MAX_LIBRARY_ITEMS];"),
        ("Arrays of Objects", "HostelBlock keeps Room objects in an array.", "Room rooms[MAX_BLOCK_ROOMS];"),
        ("Exception Handling", "Custom exceptions are thrown and caught for capacity and overdue cases.", "throw CapacityExceededException(\"Course is full\");"),
        ("File I/O", "Library data and campus reports are loaded/saved using fstream.", "ofstream file(fileName);"),
        ("Reporting and Utilities", "Reports and Utils keep report, date, formatting, and validation helpers separate.", "Reports::generateCampusTextReport(...);"),
        ("Memory Management", "Objects and arrays created with new are deleted using delete or delete[].", "delete[] sortedStudents;"),
        ("Sorting and Searching", "Reports sorts students by GPA and searches by roll number.", "sortStudentsByGPA(students, count);"),
        ("Composition", "HostelManager owns a HostelBlock object.", "HostelBlock block;"),
        ("Aggregation", "Course stores Faculty* and Room stores Student* without owning those people.", "Faculty* instructor; Student* occupants[];"),
    ]
    for number, (name, explanation, snippet) in enumerate(concepts, 1):
        add_wrapped(pdf, f"{number}. {name}: {explanation}", size=10)
        add_code_line(pdf, snippet)

    pdf.add_page()
    add_section(pdf, "Module Descriptions")
    add_bullets(pdf, [
        "Module 1 - Person Hierarchy: Stores common personal information in Person and uses Student, GradStudent, Faculty, and Staff subclasses.",
        "Module 2 - Course and Enrollment: Stores course data, enrolls students, blocks over-capacity enrollment, and demonstrates overloaded operators.",
        "Module 3 - Library System: Stores books and journals, searches the catalog, saves/loads text files, tracks issued items, and handles overdue fines.",
        "Module 4 - Fee and Finance: Stores fee balance, records payments with operator-=, deep-copies fee data, and generates invoices with a static counter.",
        "Module 5 - Hostel Management: Uses rooms, hostel blocks, multiple inheritance, virtual inheritance, and composition to allocate/vacate rooms.",
        "Module 6 - Reporting and Utilities: Sorts and searches student data, prints reports, writes a campus text report, writes a PDF-style text report, and keeps helper functions separate.",
    ])

    add_section(pdf, "GitHub Workflow")
    add_wrapped(pdf, "The project is already a local git repository with separate commits for setup, documentation, and each major module. "
                     "Before final submission, create a public GitHub repository named HITEC-OOP-SCMS-25-CS-067, push this folder, "
                     "and paste the repository URL here and in README.md.")
    add_bullets(pdf, [
        "Local branch: master",
        "Current local commits: see git log --oneline in the repository.",
        "A GitHub Actions build workflow is included at .github/workflows/build.yml for the bonus compile check.",
        "Do not submit until the public GitHub link is shared through the course portal.",
    ])

    add_section(pdf, "Testing Summary")
    add_bullets(pdf, [
        "Build command .\\build.bat completed successfully.",
        "All six home menu modules were tested.",
        "Library demo loaded catalog data, issued B001, and showed overdue fine.",
        "Finance demo showed payment, copy constructor, copy assignment, invoice, and invoice copy.",
        "Hostel demo showed service name, allocation, duplicate check, summary, report, and vacate room.",
        "Reports demo sorted students by GPA and created data/campus_report.txt.",
        "Reports demo created data/campus_pdf_report.txt.",
        "Wrong input test with abc did not freeze the program.",
        "Full captured output files are saved in docs/test_outputs.",
    ])

    for image_path in screenshot_paths:
        caption = image_path.stem.replace("_", " ").title() + " Output Screenshot"
        add_image_with_caption(pdf, image_path, caption)

    pdf.add_page()
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
                     "Before final submission, the group should push the repository to GitHub and replace the placeholder "
                     "GitHub URL in this report.")

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
    SCREENSHOTS.mkdir(exist_ok=True)
    diagram = make_class_diagram()
    screenshots = make_output_screenshots()
    report = make_report(diagram, screenshots)
    print(f"Generated: {diagram}")
    for screenshot in screenshots:
        print(f"Generated: {screenshot}")
    print(f"Generated: {report}")


if __name__ == "__main__":
    main()
