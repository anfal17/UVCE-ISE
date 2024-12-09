# Web Lab Programs with PHP and MySQL

This repository contains programs using **HTML**, **PHP**, and **MySQL** to perform various web-based tasks. These programs are designed to be run using the **XAMPP** server.

---

## **Setup Instructions**

### **1. Install XAMPP**
- Download and install XAMPP from [https://www.apachefriends.org/](https://www.apachefriends.org/).
- Start the **Apache** and **MySQL** services from the XAMPP Control Panel.

### **2. Set Up the Database**
- Open `http://localhost/phpmyadmin` in your browser.
- Create the required database and tables (refer to program comments for table structures and examples).

---

## **How to Run the Programs**

### **If You Have Only PHP Files**
1. Place all `.php` files in the `htdocs` folder:
   - Navigate to the XAMPP installation directory.
   - Open the `htdocs` folder (e.g., `C:\xampp\htdocs` on Windows or `/opt/lampp/htdocs` on Linux).
   - Create a new folder for your project, e.g., `myWebLab`, and place all `.php` files inside it.

2. Start XAMPP:
   - Open the XAMPP Control Panel.
   - Start the **Apache** service.

3. Open the PHP file in your browser:
   - Visit `http://localhost/myWebLab/<filename>.php` in your browser.
   - Replace `<filename>` with the name of the PHP file you want to execute.

---

### **If You Have Both PHP and HTML Files**
1. Place all `.html` and `.php` files in the `htdocs` folder:
   - Create a project folder (e.g., `myWebLab`) inside the `htdocs` directory.
   - Place all `.html` and `.php` files in this folder.

2. Start XAMPP:
   - Start the **Apache** and **MySQL** services.

3. Open the HTML file in your browser:
   - Navigate to `http://localhost/myWebLab/<html_filename>.html`.
   - Replace `<html_filename>` with the name of your HTML file.
   - Submit forms or interact with the webpage to process data using the linked PHP files.

---

## **Troubleshooting**

- **404 Not Found**:
  - Ensure the files are in the correct folder (`htdocs/myWebLab`).
  - Check the file names and extensions.
  
- **PHP Code Showing in Browser Instead of Executing**:
  - Ensure Apache is running in XAMPP.
  - Access the file via `http://localhost` instead of opening it directly from the file system.

- **Database Errors**:
  - Confirm that the MySQL service is running.
  - Verify the database credentials in the PHP file (`hostname`, `username`, `password`, and `database name`).

---

## **Folder Structure Example**
