import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class JavaPriorityQueue {

	static class Student {
		private int token;
		private String fname;
		private double cgpa;

		public Student(int id, String fname, double cgpa) {
			super();
			this.token = id;
			this.fname = fname;
			this.cgpa = cgpa;
		}

		public int getToken() {
			return token;
		}

		public String getFname() {
			return fname;
		}

		public double getCgpa() {
			return cgpa;
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PriorityQueue<Student> data = new PriorityQueue<Student>(new Comparator<Student>() {

			@Override
			public int compare(Student o1, Student o2) {
				if (o1.getCgpa() < o2.getCgpa()) {
					return 1;
				} else if (o1.getCgpa() > o2.getCgpa()) {
					return -1;
				} else {
					if (o1.getFname().compareTo(o2.getFname()) == 0) {
						if (o1.getToken() > o2.getToken()) {
							return 1;
						} else if (o1.getToken() < o2.getToken()) {
							return -1;
						} else {
							return 0;
						}

					} else {
						return o1.getFname().compareTo(o2.getFname());
					}
				}
			}
		});
        
		for (int i = 0; i < t; i++) {
			String op = sc.next();
			switch (op) {
			case "ENTER":
				String name = sc.next();
				double cgpa = sc.nextDouble();
				int id = sc.nextInt();
				Student s = new Student(id, name, cgpa);
				data.add(s);
				break;
			case "SERVED":
				if (data.isEmpty()) {
					break;
				}
				data.remove();

			}
		}
		if (data.isEmpty())
			System.out.println("EMPTY");
		else {
			while (!data.isEmpty()) {
				Student st = data.poll();
				System.out.println(st.getFname());
			}
		}
		sc.close();
	}
}