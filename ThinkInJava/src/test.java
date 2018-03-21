public class test
{
    public static void main(String[] args)
    {
        Employee[] staff = new Employee[3];
        staff[0] = new Employee("Tom", 40000);
        staff[1] = new Employee("Dick", 60000);
        staff[2] = new Employee("Harry", 65000);

        for(Employee e : staff) {
            System.out.println("name = " + e.getName() + ", id = " + e.getId() + ", salary = " + e.getSalary());
        }

        int n = Employee.getNextId();
        System.out.println("Next avaliable id = " + n);
    }
}

class Employee
{
    private static int nextId = 1;

    private String name;
    private double salary;
    private int id;

    public Employee(String name, double salary)
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

    public int setId()
    {
        int tmp = nextId;
        nextId ++;
        return tmp;
    }

    public static int getNextId()
    {
        return nextId;
    }

    public static void main(String[] args)
    {
        Employee e = new Employee("Harry", 50000);
        System.out.println(e.getName() + " " + e.getSalary());
    }
}

abstract class Person
{
    private String name;
    public Person(String name)
    {
        this.name = name;
    }
    public abstract String getDescription();
    public String getName()
    {
        return name;
    }
}

class Student extends Person
{
    private String major;

    public Student(String name, String major)
    {
        super(name);
        this.major = major;
    }

    public String getDescription()
    {
        return "a Student majoring in " + major;
    }
}
