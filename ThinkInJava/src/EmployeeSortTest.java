import java.util.*;

public class EmployeeSortTest {
    public static void main(String[] args) {
        EmployeeSort[] staff = new EmployeeSort[3];

        staff[0] = new EmployeeSort("Harry", 35000);
        staff[1] = new EmployeeSort("Carl", 75000);
        staff[2] = new EmployeeSort("Tony", 45000);

        Arrays.sort(staff);

        for(EmployeeSort e : staff)
            System.out.println("name = " + e.getName() + ", Salary = " + e.getSalary());
    }
}

class EmployeeSort implements Comparable<EmployeeSort> {
    private static int nextId = 1;

    private String name;
    private double salary;
    private int id;

    public EmployeeSort(String name, double salary)
    {
        this.name = name;
        this.salary = salary;
        this.id = this.setId();
    }

    public String getName()
    {
        return this.name;
    }
    public double getSalary()
    {
        return this.salary;
    }
    public int getId()
    {
        return this.id;
    }

    private int setId()
    {
        int tmp = nextId;
        nextId ++;
        return tmp;
    }

    public static int getNextId()
    {
        return nextId;
    }

    public void rasieSalary(double byPercent) {
        double raise = salary * byPercent / 100;
        salary += raise;
    }

    public int compareTo(EmployeeSort other) {
        return Double.compare(salary, other.salary);
    }
}
