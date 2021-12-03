package net.project.studentmanagement.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.project.studentmanagement.dao.StudentDao;
import net.project.studentmanagement.model.Student;

/**
 * @email Ramesh Fadatare
 */

@WebServlet("/register")
public class StudentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private StudentDao studentDao;
	
	public void init() {
		studentDao = new StudentDao();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		String firstName = request.getParameter("firstName");
		String lastName = request.getParameter("lastName");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String address = request.getParameter("address");
		String contact = request.getParameter("contact");
		
		Student student = new Student();
		student.setFirstName(firstName);
		student.setLastName(lastName);
		student.setUsername(username);
		student.setPassword(password);
		student.setContact(contact);
		student.setAddress(address);
		
		try {
			studentDao.registerStudent(student);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		response.sendRedirect("studentdetails.jsp");
	}
}
