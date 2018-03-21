public class AbstractTest {
	public static void main(String[] args) {
		Sts[] st = {
				new St1(),
				new St2(),
		};
		st[0].print();
		st[1].print();
	}
}

abstract class Sts {
	public Sts() {
		print();
	}
	
	public abstract void print();
}

class St1 extends Sts {
	private int stInt = 1;
	
	public St1() {
		print();
	}
	
	public void print() {
		System.out.println(stInt);
	}
}

class St2 extends Sts {
	private int stInt = 2;
	
	public St2() {
		print();
	}
	
	public void print() {
		System.out.println(stInt);
	}
}