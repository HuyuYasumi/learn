public class InterfaceTest {

	public static void main(String[] args) {
	}

}

abstract class Downcasting {
}

class Downcasting1 extends Downcasting {
	public static Downcasting1 to1(Downcasting d) {
		return (Downcasting1) d;
	}
}